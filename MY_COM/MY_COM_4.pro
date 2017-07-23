#-------------------------------------------------
#
# Project created by QtCreator 2017-07-18T19:06:11
#
#-------------------------------------------------

QT       += core gui

TARGET = MY_COM_4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    posix_qextserialport.cpp \
    qextserialbase.cpp

HEADERS  += mainwindow.h \
    posix_qextserialport.h \
    qextserialbase.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    log.txt
