#-------------------------------------------------
#
# Project created by QtCreator 2016-01-25T12:48:12
#
#-------------------------------------------------

QT       += core gui
CONFIG += console
QT       += opengl
LIBS += -lGL -lGLU -lglut

TARGET = NounCheck
TEMPLATE = app


SOURCES += main.cpp\
    wordsource.cpp

HEADERS  += \
    wordSource.h

FORMS    += widget.ui

RESOURCES += \
    resource.qrc
