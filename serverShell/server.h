#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QMessageBox>

#include "consoleshell.h"

class Server : public QWidget{

    Q_OBJECT

public:
    Server(QWidget *parent = nullptr);
    virtual ~Server(){}

private:
    QHBoxLayout *layout = nullptr;
    QLabel *labAddr = nullptr;
    QLineEdit *lineAddr = nullptr;
    QLabel *labPort = nullptr;
    QLineEdit *linePort = nullptr;
    QPushButton *btnStart = nullptr;
    QString addr;
    uint16_t port;

private slots:
    void startServer();

signals:
    void setupServer(const QString &address, quint16 port);

};
#endif // SERVER_H
