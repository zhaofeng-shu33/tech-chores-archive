TEMPLATE = app


UI_DIR = Debug
MOC_DIR = Debug
RCC_DIR = Debug

TARGET = AdvancedStyle
QT += core \
    gui \
    sql \
    xml
    
DEPENDPATH +=	. \
				Code \
				Include 

INCLUDEPATH +=	. \
				Include	  
    
HEADERS +=	CustomStyle.h \
			StyleMainWindow.h \
			RoundPushBtn.h
    
SOURCES +=	main.cpp \
			CustomStyle.cpp \
			StyleMainWindow.cpp \
			RoundPushBtn.cpp
			
FORMS +=	StyleMainWindow.ui
		
RESOURCES += Texture.qrc