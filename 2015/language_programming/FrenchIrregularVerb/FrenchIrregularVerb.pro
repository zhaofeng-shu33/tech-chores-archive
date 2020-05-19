
OTHER_FILES += \
    ConjugaisonPresent.txt \
    ConjugaisonPasse.txt \
    ConjugaisonInfinitive.txt \
    ConjugaisonFuturSimple.txt \
    French.rc \
    French.ico \
    ConjugaisonImparfait.txt

HEADERS += \
    wordinput.h \
    widget.h

SOURCES += \
    wordinput.cpp \
    widget.cpp \
    main.cpp

FORMS += \
    wordinput.ui \
    widget.ui

RESOURCES += \
    word.qrc
RC_FILE=French.rc
