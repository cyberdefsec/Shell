#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    resize(800, 600);

    centerWidget = new QWidget(this);
    setCentralWidget(centerWidget);

    vlayout = new QVBoxLayout;
    centerWidget->setLayout(vlayout);

    server = new Server(this);
    vlayout->addWidget(server);

    consoleShell = new ConsoleShell(this);
    vlayout->addWidget(consoleShell);

    toolBar = new QToolBar(this);
    toolBar->setMovable(false);
    toolBar->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    actIp = new QAction(tr("IP address:"), this);
    toolBar->addAction(actIp);

    actClientIp = new QAction(this);
    toolBar->addAction(actClientIp);

    toolBar->addAction(toolBar->addSeparator());

    actPort = new QAction(tr("Port:"), this);
    toolBar->addAction(actPort);

    actClientPort = new QAction(this);
    toolBar->addAction(actClientPort);

    addToolBar(Qt::BottomToolBarArea, toolBar);

    connect(server, SIGNAL(setupServer(const QString&, quint16)), consoleShell, SLOT(setAddressServer(const QString&, quint16)));
    connect(server, SIGNAL(shutdown()), consoleShell, SLOT(clientDisconnect()));
    connect(consoleShell, SIGNAL(clientInfo(const InfoClient &)), this, SLOT(setInfoClient(const InfoClient &)));
}

MainWindow::~MainWindow(){

}

void MainWindow::paintEvent(QPaintEvent *event){
    if(consoleShell->hasFocus())
        QApplication::setCursorFlashTime(0);
    else
        QApplication::setCursorFlashTime(DEFAULT_CURSOR_TIME_FLASH);
    QMainWindow::paintEvent(event);
}

void MainWindow::setInfoClient(const InfoClient &infoClient){
    actClientIp->setText(infoClient.ipAddr);
    actClientPort->setText(QString::number(infoClient.port));
}

