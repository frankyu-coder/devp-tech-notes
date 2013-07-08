####
TEMPLATE = app
TARGET = a.out

DEPENDPATH += . \
                $$PWD/../../code/cpp \
INCLUDEPATH += . \
                $$PWD/../../code/inc \
                $$PWD/../../code/cpp \

include ($$PWD/../../code/stack_demo1.pri)

HEADERS += .\
	window.h \

SOURCES += main.cpp \
	window.cpp \
