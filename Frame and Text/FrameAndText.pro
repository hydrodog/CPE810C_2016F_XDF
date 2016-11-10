QT += core
QT -= gui

CONFIG += c++11

TARGET = 810C_project
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    frame.cpp \
    page.cpp \
    characterstyle.cpp \
    border.cpp \
    textline.cpp \
    text.cpp

HEADERS += \
    text.h \
    frame.h \
    textline.h \
    border.h \
    characterstyle.h \
    page.h
