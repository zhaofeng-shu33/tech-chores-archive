#-------------------------------------------------
#
# Project created by QtCreator 2016-03-18T21:39:26
#
#-------------------------------------------------
QT       += phonon
QT       += core gui
QT       += sql
QT += webkit
QT += xmlpatterns
CONFIG += qt
TARGET = NounDicWithDb
TEMPLATE = app

LIBS += -lz

SOURCES += main.cpp\
        mainwindow.cpp \
    wordinput.cpp

HEADERS  += mainwindow.h \
    wordinput.h

FORMS    += \
    wordinput.ui

RESOURCES += \
    resource.qrc
RC_FILE=Deutsch.rc

OTHER_FILES += \
    horn.jpg \
    Deutsch.rc \
    Deutsch.ico
