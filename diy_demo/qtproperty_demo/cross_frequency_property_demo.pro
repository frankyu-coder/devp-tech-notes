TEMPLATE = app

DEPENDPATH += . \
            $$PWD/cpp \
            $$PWD/inc \

INCLUDEPATH += . \
            $$PWD/inc \

INCLUDEPATH += \
      $$PWD/../../../../../3rdparty/qtpropertybrowser/src \


include($$PWD/../../../3rdparty/qtpropertybrowser/src/qtpropertybrowser.pri)


#../../../qtreserve/src/cross/

#include(../../../3rdparty/qtpropertybrowser/qtpropertybrowser-2.5_1-opensource/src/qtpropertybrowser.pri)
#include(../cross_frequency_property_demo.pri)
#include($$PWD/cross_common_property_group.h)

# Input
HEADERS += window.h \


SOURCES += main.cpp \
        window.cpp \

