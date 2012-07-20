TARGET = nightplugin
TEMPLATE = lib
CONFIG += dll

HEADERS += \
	nightplugin.h \
    nightwidget.h \
    alarmform.h \
    alarmwizard.h \
    timepage.h \
    daypage.h

SOURCES += \
	nightplugin.cpp \
    nightwidget.cpp \
    alarmform.cpp \
    alarmwizard.cpp \
    timepage.cpp \
    daypage.cpp

DESTDIR = ../

FORMS += \
    nightwidget.ui \
    alarmform.ui \
    timepage.ui \
    daypage.ui
