HEADERS       = mainwindow.h \
                xbeltree.h
SOURCES       = main.cpp \
                mainwindow.cpp \
                xbeltree.cpp
QT           += xml


wince*: {
     addFiles.sources = frank.xbel jennifer.xbel
     addFiles.path = "\\My Documents"
     DEPLOYMENT += addFiles
}

RESOURCES += \
    xbel.qrc
