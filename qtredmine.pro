TEMPLATE = lib
TARGET = qtredmine

QT += network
QT -= gui
QT += qml quick


QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += $$PWD/include/qtredmine

HEADERS += \
    include/qtredmine/qtredmine_global.h \
    include/qtredmine/Authenticator.h \
    include/qtredmine/KeyAuthenticator.h \
    include/qtredmine/Logging.h \
    include/qtredmine/PasswordAuthenticator.h \
    include/qtredmine/RedmineClient.h \
    include/qtredmine/SimpleRedmineClient.h \
    include/qtredmine/SimpleRedmineTypes.h \
    qtredmineplugin.h

SOURCES += \
    KeyAuthenticator.cpp \
    Logging.cpp \
    PasswordAuthenticator.cpp \
    RedmineClient.cpp \
    SimpleRedmineClient.cpp \
    qtredmineplugin.cpp

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
