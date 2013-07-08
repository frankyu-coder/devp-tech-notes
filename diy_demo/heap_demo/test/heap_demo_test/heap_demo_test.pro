####
TEMPLATE = app
TARGET = a.out
DEPENDPATH += . \
                $$PWD/../../code/cpp \
INCLUDEPATH += . \
                $$PWD/../../code/inc \

include ($$PWD/../../code/heap_demo.pri)

HEADERS += .\
	window.h \

SOURCES += main.cpp \
	window.cpp \
