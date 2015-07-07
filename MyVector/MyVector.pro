TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    myvector.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    myvector.h

