#-------------------------------------------------
#
# Project created by QtCreator 2016-07-06T23:30:44
#
#-------------------------------------------------

QT       += core gui

TARGET = MyCom
TEMPLATE = app
INCLUDEPATH +=D:\QtTest\src\HeadFile
LIBS += D:\QtTest\src\qextserialport-build-desktop\build\libqextserialportd.a
SOURCES += main.cpp\
        mainwindow.cpp \
    MessageWindow.cpp

HEADERS  += mainwindow.h \
    MessageWindow.h


FORMS    += mainwindow.ui
