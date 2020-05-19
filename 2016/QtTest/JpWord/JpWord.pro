#-------------------------------------------------
#
# Project created by QtCreator 2016-02-25T16:54:16
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += phonon
TARGET = JpWord
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wordinput.cpp

HEADERS  += mainwindow.h \
    wordinput.h

FORMS    += \
    wordinput.ui

OTHER_FILES += \
    save.png \
    paste.png \
    open.png \
    new.png \
    cut.png \
    copy.png

RESOURCES += \
    resource.qrc
