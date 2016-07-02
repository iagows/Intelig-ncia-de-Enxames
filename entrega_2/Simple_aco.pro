QT -= core
QT -= gui

CONFIG += c++14

# garantindo um "debug_and_release" no CONFIG, pra deixar claro...
debug_and_release {
    CONFIG -= debug_and_release
    CONFIG += debug_and_release
}
# garantindo UM "debug" OU "release" no CONFIG pra usar os
# condicionais instead of writing "CONFIG(debug, debug|release)"...
CONFIG(debug, debug|release) {
    CONFIG -= debug release
    CONFIG += debug
    DEFINES += DEBUG
}
CONFIG(release, debug|release) {
    CONFIG -= debug release
    CONFIG += release
    DEFINES += RELEASE
}

TARGET = Simple_aco
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    tspreader.cpp \
    path.cpp \
    ground.cpp \
    aco.cpp \
    ant.cpp \
    util/point.cpp

HEADERS += \
    tspreader.h \
    path.h \
    ground.h \
    aco.h \
    ant.h \
    util/point.h \
    randutils.hpp
