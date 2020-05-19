TEMPLATE = app


UI_DIR = Debug
MOC_DIR = Debug
RCC_DIR = Debug

TARGET = SimpleCustomStyle
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
			StyleMainWindow.h
    
SOURCES +=	main.cpp \
			CustomStyle.cpp \
			StyleMainWindow.cpp
			
FORMS +=	StyleMainWindow.ui
		
RESOURCES += 
