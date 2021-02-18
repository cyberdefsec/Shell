TARGET = serverShell

TEMPLATE = app

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11 exception warning_on

isEmpty(DESTDIR){
    CONFIG(debug, debug|release){
        message(Debug build)
        unix: DESTDIR = $$PWD/debug
    }
    CONFIG(release, debug|release){
        message(Release build)
        unix: DESTDIR = $$PWD/release
    }
}

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


RESOURCES += \
    resource.qrc

unix:!macx!android{
    isEmpty(PREFIX){
        PREFIX = /usr/local
        message($$PREFIX)
    }

    BINDIR = $$PREFIX/bin
    APPDIR = /usr/share/applications
    ICODIR = /usr/share/icons/hicolor/128x128/apps

    target.path = $$BINDIR
    target.files += $$DESTDIR/$$TARGET

    icon_128.path = $$ICODIR
    icon_128.files += ico/$${TARGET}.png

    desktop.path = $$APPDIR
    desktop.files += desktop/$${TARGET}.desktop

    INSTALLS += target \
                icon_128 \
                desktop
}
