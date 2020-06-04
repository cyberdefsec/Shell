#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QIcon>

class Application : public QApplication{

    Q_OBJECT

public:
    Application(int &argc, char *argv[]);
    virtual ~Application(){}
};

#endif // APPLICATION_H
