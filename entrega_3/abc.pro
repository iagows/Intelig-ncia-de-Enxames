QT -= gui core

CONFIG += c++14

TARGET = abc
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    abc.cpp \
    algorithms/abstracttestalgorithm.cpp \
    algorithms/algorithmfactory.cpp \
    algorithms/algorithmrosenbrock.cpp \
    algorithms/algorithmrotatedrastrigin.cpp \
    algorithms/algorithmsphere.cpp \
    bee.cpp

HEADERS += \
    randutils.hpp \
    abc.h \
    algorithms/abstracttestalgorithm.h \
    algorithms/algorithmfactory.h \
    algorithms/algorithmrosenbrock.h \
    algorithms/algorithmrotatedrastrigin.h \
    algorithms/algorithmsphere.h \
    algorithms/ialgorithm.h \
    bee.h
