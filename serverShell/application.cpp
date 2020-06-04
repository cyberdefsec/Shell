#include "application.h"

Application::Application(int &argc, char *argv[]) : QApplication(argc, argv){
    //setApplicationDisplayName(tr("serverShell"));
    setApplicationName(tr("serverShell"));
    setWindowIcon(QIcon(":/ico/server.png"));
}
