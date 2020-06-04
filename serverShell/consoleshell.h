#ifndef CONSOLESHELL_H
#define CONSOLESHELL_H

#include <QTextEdit>
#include <QScrollBar>
#include <QKeyEvent>
#include <QTextBlock>
#include <QString>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

#define QDEBUG(...) (qDebug() __VA_ARGS__)

typedef struct{
    QString ipAddr;
    uint16_t port;
}InfoClient;

class ConsoleShell : public QTextEdit{

    Q_OBJECT

public:
    ConsoleShell(QWidget *parent = nullptr);
    virtual ~ConsoleShell() override;

protected:
    void keyPressEvent(QKeyEvent *) override;
    void contextMenuEvent(QContextMenuEvent *) override;
    void mouseDoubleClickEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void mousePressEvent(QMouseEvent *) override;

private:
    QTcpServer *serverSock = nullptr;
    QTcpSocket *clientSock = nullptr;
    QString prompt;
    qint64 lenPrompt;
    InfoClient infoClient;
    QStringList saveCommand;
    int pos;

    void sendData();
    void downScroll();
    void setFontConsole(int size);
    void clientDisconnect();
    void setInfoClient();
    void setCursorEnd();
    QString parseLine();
    void historyBegin();
    void historyEnd();
    void historyAdd(const QString &cmd);
    void clearLine();

public slots:
    void setAddressServer(const QString &address, quint16 port);

private slots:
    void clientConnect();
    void readData();

signals:
    void clientInfo(const InfoClient &infoClient);
};
#endif // CONSOLESHELL_H
