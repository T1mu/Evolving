# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = lib
TARGET = Motor
DESTDIR = ../Win32/Debug
QT += core widgets
CONFIG += debug
DEFINES += WIN64 MOTOR_LIB
INCLUDEPATH += ./GeneratedFiles/DeBug \
    ./GeneratedFiles \
    . \
    ./GeneratedFiles/$(ConfigurationName)
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(Motor.pri)
