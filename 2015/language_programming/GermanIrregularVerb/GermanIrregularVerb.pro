QT       += core gui
QT += phonon
TARGET = GermanIrregularVerb
TEMPLATE = app

SOURCES += \
    main.cpp \
    wordinput.cpp

RESOURCES += \
    word.qrc \
    word.qrc

OTHER_FILES += \
    verbInfinitive2.txt \
    verbParticiple.txt \
    verbPresentTense.txt \
    verbPastTense.txt \
    Deutsch.ico \
    Deutsch.rc

HEADERS += \
    wordinput.h

FORMS += \
    wordinput.ui
RC_FILE=Deutsch.rc
