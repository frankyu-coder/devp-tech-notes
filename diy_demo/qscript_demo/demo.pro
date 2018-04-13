QT += script widgets uitools

RESOURCES += demo.qrc
SOURCES   += main.cpp
QMAKE_PROJECT_NAME = scripted_demo

qtHaveModule(scripttools): QT += uitools
qtHaveModule(scripttools): QT += scripttools

target.path = ./output
INSTALLS += target
