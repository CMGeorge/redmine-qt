TEMPLATE = lib
TARGET = qtredmine

QT += network
QT -= gui
QT += qml quick


QMAKE_CXXFLAGS += -std=c++11

#INCLUDEPATH += $$PWD/include/qtredmine

DISTFILES += \
    .travis.yml \
#    qtredmine.pri \
    Example.h \
    Example.cpp \
    README.md

#QML ONLY ATM

TARGETPATH  = ro/wesell/$${TARGET}

load(qml_plugin)
#OTHER_FILES+
#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#    CONFIG += staticlib
#}

#include($$PWD/qtredmine.pri)
