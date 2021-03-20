#include "server.h"

Server::Server(QWidget *parent) : QWidget(parent){
    layout = new QHBoxLayout(this);

    layout->addStretch(1);
    labAddr = new QLabel(tr("IP address:"), this);
    layout->addWidget(labAddr);

    lineAddr = new QLineEdit(this);
    lineAddr->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    layout->addWidget(lineAddr);

    labPort = new QLabel(tr("Port:"), this);
    layout->addWidget(labPort);

    linePort = new QLineEdit(this);
    linePort->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    layout->addWidget(linePort);

    btnStart = new QPushButton(tr("Start server"), this);
    btnStart->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    layout->addWidget(btnStart);

    btnStop = new QPushButton(tr("Stop server"), this);
    btnStop->setEnabled(false);
    btnStop->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    layout->addWidget(btnStop);

    connect(btnStart, SIGNAL(clicked()), this, SLOT(startServer()));
    connect(btnStop, SIGNAL(clicked()), this, SLOT(stopServer()));
}

void Server::startServer(){
    if(! linePort->text().isEmpty()){
        lineAddr->setEnabled(false);
        linePort->setEnabled(false);
        btnStart->setEnabled(false);
        btnStop->setEnabled(true);
        emit setupServer(lineAddr->text(), linePort->text().toUShort());
    }
    else{
        QMessageBox::warning(this, nullptr, tr("Enter ip address and port"), QMessageBox::Ok);
        lineAddr->setFocus();
    }
}

void Server::stopServer(){
    lineAddr->setEnabled(true);
    linePort->setEnabled(true);
    btnStart->setEnabled(true);
    btnStop->setEnabled(false);
    emit shutdown();
}
