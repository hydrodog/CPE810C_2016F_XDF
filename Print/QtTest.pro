#-------------------------------------------------
#
# Project created by QtCreator 2016-11-10T21:36:04
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtTest
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    pprint.cpp \
    pframe.cpp \
    ppage.cpp

HEADERS  += dialog.h \
    pprint.hh \
    includes.hh \
    pframe.h \
    ppage.h

FORMS    += dialog.ui

RESOURCES +=
