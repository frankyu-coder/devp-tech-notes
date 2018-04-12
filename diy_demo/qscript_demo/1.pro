QT += script widgets uitools
RESOURCES += 1.qrc
SOURCES += main.cpp
QMAKE_PROJECT_NAME = scripted_1

qtHaveModule(scripttools): QT += scripttools

target.path = ./
INSTALLS += target

maemo5: CONFIG += 
