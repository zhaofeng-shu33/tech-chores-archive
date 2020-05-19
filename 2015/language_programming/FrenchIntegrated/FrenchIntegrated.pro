#-------------------------------------------------
#
# Project created by QtCreator 2015-10-24T22:35:32
#
#-------------------------------------------------

QT       += core gui
QT += phonon
CONFIG   += console
TARGET = FrenchIntegrated
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    frenchtry.cpp \
    wordinput.cpp \
    wordsource.cpp

HEADERS  += mainwindow.h \
    frenchtry.h \
    wordinput.h \
    wordsource.h

FORMS    += mainwindow.ui \
    frenchtry.ui \
    wordinput.ui

OTHER_FILES += \
    words1.txt \
    words.txt \
    u.wma \
    o.wma \
    i.wma \
    e.wma \
    a.wma \
    appearance.png

RESOURCES += \
    textfinder.qrc
