TARGET = serverShell

TEMPLATE = app

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = serverShell
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
        main.cpp \
        application.cpp \
        consoleshell.cpp \
        mainwindow.cpp \    
        server.cpp


HEADERS += \
        application.h \
        consoleshell.h \
        mainwindow.h \
        server.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
