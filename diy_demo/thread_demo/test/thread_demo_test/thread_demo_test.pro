
QT += sql
TARGET = a.out
TEMPLATE = app

INCLUDEPATH += $$PWD/../../code/inc \
DEPENDPATH += $$PWD/../../code/cpp \

include ($$PWD/../../code/thread_demo.pri)

HEADERS += window.h \
        

SOURCES += window.cpp \
        main.cpp \
