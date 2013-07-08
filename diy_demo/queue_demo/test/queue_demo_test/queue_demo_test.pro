#############
TEMPLATE = app
TARGET = a.out
DEPENDPATH += . \
                $$PWD/../../code/cpp \
INCLUDEPATH += . \
                $$PWD/../../code/inc \

include ($$PWD/../../code/queue_demo.pri)

HEADERS += .\
	window.h \

SOURCES += main.cpp \
	window.cpp \
