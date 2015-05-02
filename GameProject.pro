TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    win_console.cpp \
    unitdata.cpp \
    settings.cpp \
    unitcontrol.cpp \
    unitDB.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    win_console.h \
    unitdata.h \
    settings.h \
    unitcontrol.h \
    unitDB.h

