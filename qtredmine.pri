INCLUDEPATH += $$PWD/include/qtredmine
DEPENDPATH += $$PWD

HEADERS += \
    $$PWD/include/qtredmine/qtredmine_global.h \
    $$PWD/include/qtredmine/Authenticator.h \
    $$PWD/include/qtredmine/KeyAuthenticator.h \
    $$PWD/include/qtredmine/Logging.h \
    $$PWD/include/qtredmine/PasswordAuthenticator.h \
    $$PWD/include/qtredmine/RedmineClient.h \
    $$PWD/include/qtredmine/SimpleRedmineClient.h \
    $$PWD/include/qtredmine/SimpleRedmineTypes.h \
    $$PWD/qtredmineplugin.h

SOURCES += \
    $$PWD/KeyAuthenticator.cpp \
    $$PWD/Logging.cpp \
    $$PWD/PasswordAuthenticator.cpp \
    $$PWD/RedmineClient.cpp \
    $$PWD/SimpleRedmineClient.cpp \
    $$PWD/qtredmineplugin.cpp

#!equals(_PRO_FILE_PWD_, $$PWD) {
#  win32:CONFIG(release, debug|release): LIBS += -L$$PWD/release -L$$PWD/Release/release -L$$shadowed($$PWD)/release -lqtredmine
#  else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/debug -L$$PWD/Debug/debug -L$$shadowed($$PWD)/debug -lqtredmine
#  else:unix: LIBS += -L$$shadowed($$PWD) -lqtredmine
#}
