QT -= gui core

CONFIG += c++14

TARGET = fss_algorithm
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    algorithms/abstracttestalgorithm.cpp \
    algorithms/algorithmfactory.cpp \
    algorithms/algorithmrosenbrock.cpp \
    algorithms/algorithmrotatedrastrigin.cpp \
    algorithms/algorithmsphere.cpp \
    fish.cpp \
    fss.cpp

HEADERS += \
    randutils.hpp \
    algorithms/abstracttestalgorithm.h \
    algorithms/algorithmfactory.h \
    algorithms/algorithmrosenbrock.h \
    algorithms/algorithmrotatedrastrigin.h \
    algorithms/algorithmsphere.h \
    algorithms/ialgorithm.h \
    fish.h \
    fss.h
