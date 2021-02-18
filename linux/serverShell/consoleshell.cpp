#include "consoleshell.h"


ConsoleShell::ConsoleShell(QWidget *parent) : QTextEdit(parent){    
    setFontConsole(12);
    QPalette p = palette();
    p.setColor(QPalette::Base, Qt::black);
    p.setColor(QPalette::Text, Qt::green);
    setPalette(p);
    setReadOnly(true);
    lenPrompt = 0;
    pos = 0;
    serverSock = new QTcpServer(this);
    connect(serverSock, SIGNAL(newConnection()), this, SLOT(clientConnect()));
}

ConsoleShell::~ConsoleShell(){
    if(clientSock != nullptr && clientSock->state() == QAbstractSocket::ConnectedState)
        clientSock->close();
}

void ConsoleShell::setFontConsole(int size){
    QFont font;
    font.setPointSize(size);
    setCursorWidth(size - 3);
    setFontFamily("Liberation Mono");
    setFont(font);
}

void ConsoleShell::contextMenuEvent(QContextMenuEvent *){}

void ConsoleShell::mouseDoubleClickEvent(QMouseEvent *){}

void ConsoleShell::mouseMoveEvent(QMouseEvent *){}

void ConsoleShell::mousePressEvent(QMouseEvent *){
    setFocus();
    QTextCursor cur = textCursor();
    if(cur.hasSelection())
        cur.clearSelection();
    setTextCursor(cur);
}

void ConsoleShell::keyPressEvent(QKeyEvent *e){
    if(e->key() == Qt::Key_Left && e->modifiers() == Qt::NoModifier)
        if(textCursor().positionInBlock() > lenPrompt)
            QTextEdit::keyPressEvent(e);
    if(e->key() == Qt::Key_Right && e->modifiers() == Qt::NoModifier)
        QTextEdit::keyPressEvent(e);

    if((e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return) && e->modifiers() == Qt::NoModifier){
        sendData();
        QTextEdit::keyPressEvent(e);
    }

    if(e->key() >= Qt::Key_Space && e->key() <= Qt::Key_AsciiTilde && (e->modifiers() == Qt::NoModifier || e->modifiers() == Qt::ShiftModifier))
        QTextEdit::keyPressEvent(e);

    if((e->key() == Qt::Key_Backspace && textCursor().positionInBlock() > lenPrompt) || e->key() == Qt::Key_Delete)
        QTextEdit::keyPressEvent(e);

    if(e->key() == Qt::Key_C && e->modifiers() == Qt::ControlModifier)
        restartClient();

    if(e->key() == Qt::Key_Home && e->modifiers() == Qt::NoModifier && textCursor().positionInBlock() > lenPrompt){
        QTextCursor cur = textCursor();
        cur.movePosition(QTextCursor::Left, QTextCursor::MoveAnchor, textCursor().positionInBlock() - static_cast<int>(lenPrompt));
        setTextCursor(cur);
    }
    if(e->key() == Qt::Key_End && e->modifiers() == Qt::NoModifier)
        QTextEdit::keyPressEvent(e);

    if(e->key() == Qt::Key_Up && e->modifiers() == Qt::NoModifier)
        historyEnd();
    if(e->key() == Qt::Key_Down && e->modifiers() == Qt::NoModifier)
        historyBegin();
}

void ConsoleShell::sendData(){
    QString cmd;
    if(clientSock != nullptr && clientSock->state() == QAbstractSocket::ConnectedState){
        cmd = parseLine();
        historyAdd(cmd);
        if(cmd == "clear"){
            clear();
            clientSock->write("\n");
        }
        else
            clientSock->write(cmd.toLocal8Bit());
    }
    else
        QDEBUG(<< "No connect client");
}

QString ConsoleShell::parseLine(){
    QString prompt = textCursor().block().text();
    QTextCursor cur;
    if(prompt.length() > lenPrompt){
        cur = textCursor();
        cur.movePosition(QTextCursor::End, QTextCursor::MoveAnchor, prompt.length());
        setTextCursor(cur);
        return prompt.mid(static_cast<int>(lenPrompt));
    }
    return QString("\n");
}

void ConsoleShell::historyBegin(){
    if(pos < saveCommand.length()){
        clearLine();
        insertPlainText(saveCommand.at(pos));
        pos++;
    }
    else
        clearLine();
}

void ConsoleShell::historyEnd(){
    if(pos > 0){
        clearLine();
        insertPlainText(saveCommand.at(pos - 1));
        pos--;
    }
    else
        clearLine();
}

void ConsoleShell::historyAdd(const QString &cmd){
    if(cmd != "\n"){
        saveCommand.append(cmd);
        pos = saveCommand.length();
    }
}

void ConsoleShell::clearLine(){
    QTextCursor cursor = textCursor();
    cursor.movePosition(QTextCursor::Left, QTextCursor::MoveAnchor, textCursor().positionInBlock() - static_cast<int>(lenPrompt));
    cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
    cursor.removeSelectedText();
    setTextCursor(cursor);
}

void ConsoleShell::restartClient(){
    if(clientSock != nullptr && clientSock->state() == QAbstractSocket::ConnectedState){
        setCursorEnd();
        insertPlainText("\n");
        clientSock->disconnectFromHost();
    }
}

void ConsoleShell::setCursorEnd(){
    QTextCursor cur = textCursor();
    cur.movePosition(QTextCursor::End, QTextCursor::MoveAnchor, static_cast<int>(lenPrompt));
    setTextCursor(cur);
}

void ConsoleShell::setAddressServer(const QString &address, const quint16 port){    
    if(address.isEmpty())
        serverSock->listen(QHostAddress::Any, port);
    else
        serverSock->listen(QHostAddress(address), port);
}


void ConsoleShell::clientConnect(){
    clientSock = serverSock->nextPendingConnection();
    setReadOnly(false);
    setInfoClient();
    connect(clientSock, SIGNAL(disconnected()), clientSock, SLOT(deleteLater()));
    connect(clientSock, SIGNAL(readyRead()), this, SLOT(readData()));
}

void ConsoleShell::setInfoClient(){
    QString ip;
    infoClient.port = clientSock->peerPort();
    ip = clientSock->peerAddress().toString();
    infoClient.ipAddr = ip.mid(ip.lastIndexOf(':') + 1);
    emit clientInfo(infoClient);
}

void ConsoleShell::readData(){
    qint64 len = 0;
    if(clientSock->state() == QAbstractSocket::ConnectedState){
        while((len = clientSock->bytesAvailable()) > 0){
            if(lenPrompt == 0)
                lenPrompt = len;            
            insertPlainText(QString(clientSock->readAll()));
            downScroll();
        }
    }
}

void ConsoleShell::downScroll(){
    QScrollBar *bar = verticalScrollBar();
    bar->setValue(bar->maximum());
}
