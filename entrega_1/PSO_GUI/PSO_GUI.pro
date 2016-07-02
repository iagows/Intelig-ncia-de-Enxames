#-------------------------------------------------
#
# Project created by QtCreator 2016-04-12T16:20:32
#
#-------------------------------------------------

QT      += core gui
CONFIG  += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = pso_gui
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
        qcustomplot.cpp

HEADERS  += mainwindow.h \
        qcustomplot.h

FORMS    += mainwindow.ui

unix{
    DEFINES += LINUX

    LIBS += -L$$OUT_PWD/../pso_simples/ -lpso_simples
}
win32{
    DEFINES += WINDOWS

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../pso_simples/release/ -lpso_simples
    else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../pso_simples/debug/ -lpso_simples
}

INCLUDEPATH += $$PWD/../pso_simples
DEPENDPATH += $$PWD/../pso_simples
