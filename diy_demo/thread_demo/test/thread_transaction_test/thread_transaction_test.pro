
TARGET = a.out
TEMPLATE = app
CONFIG += qt warn_off
CONFIG += qt debug

INCLUDEPATH += $$PWD/../../code/inc \
DEPENDPATH += $$PWD/../../code/cpp \

include ($$PWD/../../code/thread_transaction.pri)

HEADERS += window.h \
        

SOURCES += window.cpp \
        main.cpp \


RESOURCES += $$PWD/../../res/transaction.qrc \ 
