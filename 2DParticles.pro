#-------------------------------------------------
#
# Project created by QtCreator 2015-10-10T14:27:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2DParticles
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    particle.cpp \
    vector2d.cpp \
    updateparticles.cpp \
    grid.cpp \
    cell.cpp

HEADERS  += mainwindow.h \
    particle.h \
    vector2d.h \
    updateparticles.h \
    grid.h \
    cell.h

FORMS    += mainwindow.ui
