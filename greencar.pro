#-------------------------------------------------
#
# Project created by QtCreator 2015-12-28T20:52:49
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = greencar
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    listcar.cpp \
    showcar.cpp

HEADERS  += mainwindow.h \
    listcar.h \
    showcar.h

FORMS    += mainwindow.ui \
    listcar.ui \
    showcar.ui

RESOURCES += \
    greencar.qrc
