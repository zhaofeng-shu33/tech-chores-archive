#-------------------------------------------------
#
# Project created by QtCreator 2016-01-25T12:48:12
#
#-------------------------------------------------

QT       += core gui
CONFIG += console
QT       += opengl
LIBS += -lglut32
LIBS += -LC:\glut

TARGET = NounCheck
TEMPLATE = app


SOURCES += main.cpp\
    wordsource.cpp

HEADERS  += \
    wordSource.h

FORMS    += widget.ui

RESOURCES += \
    resource.qrc
