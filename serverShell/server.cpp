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

    connect(btnStart, SIGNAL(clicked()), this, SLOT(startServer()));
}

void Server::startServer(){
    if(! linePort->text().isEmpty()){
        lineAddr->setEnabled(false);
        linePort->setEnabled(false);
        btnStart->setEnabled(false);
        emit setupServer(lineAddr->text(), linePort->text().toUShort());
    }
    else{
        QMessageBox::warning(this, nullptr, tr("Enter ip address and port"), QMessageBox::Ok);
        lineAddr->setFocus();
    }
}
