#-------------------------------------------------
#
# Project created by QtCreator 2016-04-12T15:48:52
#
#-------------------------------------------------

QT       -= core gui

CONFIG += c++14

TARGET = pso_simples
TEMPLATE = lib

DEFINES += PSO_SIMPLES_LIBRARY

SOURCES += pso_simples.cpp \
    iagorandom.cpp \
    particle.cpp \
    swarm.cpp \
    algorithms/abstracttestalgorithm.cpp \
    algorithms/algorithmfactory.cpp \
    algorithms/algorithmrosenbrock.cpp \
    algorithms/algorithmrotatedrastrigin.cpp \
    algorithms/algorithmsphere.cpp \
    topology/abstracttopology.cpp \
    topology/topologyfactory.cpp \
    topology/topologymasterslave.cpp \
    topology/topologyring.cpp \
    topology/topologystar.cpp \
    velocity/velocityclerc.cpp \
    velocity/velocityfactory.cpp \
    velocity/velocityinertia.cpp \
    velocity/velocityinertiadecrease.cpp \
    velocity/velocitynormal.cpp

HEADERS += pso_simples.h\
        pso_simples_global.h \
    iagorandom.h \
    ialgorithm.h \
    itopology.h \
    particle.h \
    swarm.h \
    algorithms/abstracttestalgorithm.h \
    algorithms/algorithmfactory.h \
    algorithms/algorithmrosenbrock.h \
    algorithms/algorithmrotatedrastrigin.h \
    algorithms/algorithmsphere.h \
    topology/abstracttopology.h \
    topology/topologyfactory.h \
    topology/topologymasterslave.h \
    topology/topologyring.h \
    topology/topologystar.h \
    velocity/ivelocity.h \
    velocity/velocityclerc.h \
    velocity/velocityfactory.h \
    velocity/velocityinertia.h \
    velocity/velocityinertiadecrease.h \
    velocity/velocitynormal.h

unix {
    target.path = /usr/lib
    INSTALLS += target
    DEFINES += LINUX
}

win32{
    DEFINES +=WINDOWS
}
