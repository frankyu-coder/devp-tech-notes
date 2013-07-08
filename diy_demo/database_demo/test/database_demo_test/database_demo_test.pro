
QT += sql
TARGET = a.out
TEMPLATE = app

INCLUDEPATH += $$PWD/../../code/inc \
DEPENDPATH += $$PWD/../../code/cpp \

include ($$PWD/../../code/database_demo.pri)


HEADERS += window.h \
        #$$PWD/../../code/inc/database_create_connection.h \
        #$$PWD/../../code/inc/database_add_table.h \

SOURCES += window.cpp \
        main.cpp \
        #$$PWD/../../code/cpp/database_create_connection.cpp \
        #$$PWD/../../code/cpp/database_add_table.cpp \

