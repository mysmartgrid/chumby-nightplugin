TARGET = nightplugin
TEMPLATE = lib
CONFIG += dll

HEADERS += \
	nightplugin.h \
    nightwidget.h \
    alarmform.h \
    alarmwizard.h \
    timepage.h \
    daypage.h \
    summarypage.h \
    sourcepage.h \
    namepage.h

SOURCES += \
	nightplugin.cpp \
    nightwidget.cpp \
    alarmform.cpp \
    alarmwizard.cpp \
    timepage.cpp \
    daypage.cpp \
    summarypage.cpp \
    sourcepage.cpp \
    namepage.cpp

DESTDIR = ../

FORMS += \
    nightwidget.ui \
    alarmform.ui \
    timepage.ui \
    daypage.ui \
    summarypage.ui \
    sourcepage.ui \
    namepage.ui
