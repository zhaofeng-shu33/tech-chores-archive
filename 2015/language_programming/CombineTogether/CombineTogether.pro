#-------------------------------------------------
#
# Project created by QtCreator 2015-12-08T11:23:29
#
#-------------------------------------------------

QT       += core gui

TARGET = CombineTogether

CONFIG   += console

TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wordsource.cpp \
    wordinput.cpp \
    frenchtry.cpp \
    widget.cpp \
    conjugaison.cpp \
    wordsource2.cpp

HEADERS  += mainwindow.h \
    wordsource.h \
    wordinput.h \
    frenchtry.h \
    widget.h \
    conjugaison.h \
    wordsource2.h

FORMS    += mainwindow.ui \
    wordinput.ui \
    frenchtry.ui \
    widget.ui \
    conjugaison.ui

OTHER_FILES += \
    words1.txt \
    words.txt \
    ConjugaisonAnswer.txt \
    Conjugaison.txt \
    ConjugaisonPasse.txt

RESOURCES += \
    textfinder.qrc
