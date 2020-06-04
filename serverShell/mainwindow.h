#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QApplication>
#include <QToolBar>
#include <QAction>

#include "server.h"
#include "consoleshell.h"

#define DEFAULT_CURSOR_TIME_FLASH 1000

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow() override;

protected:
    virtual void paintEvent(QPaintEvent *event) override;

private:
    QWidget *centerWidget = nullptr;
    QVBoxLayout *vlayout = nullptr;
    Server *server = nullptr;
    ConsoleShell *consoleShell = nullptr;
    QToolBar *toolBar = nullptr;
    QAction *actIp = nullptr;
    QAction *actClientIp = nullptr;
    QAction *actPort = nullptr;
    QAction *actClientPort = nullptr;

private slots:
    void setInfoClient(const InfoClient &infoClient);
};

#endif // MAINWINDOW_H
