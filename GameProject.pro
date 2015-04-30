TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    win_console.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    win_console.h

