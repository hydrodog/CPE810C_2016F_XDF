QT += core
QT += gui
QT += widgets

CONFIG += c++11

TARGET = 810C_project
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    frame.cpp \
    page.cpp \
    border.cpp \
    textline.cpp \
    text.cpp \
    font.cpp \
    content.cpp \
    read.cpp \
    sample.cpp

HEADERS += \
    text.h \
    frame.h \
    textline.h \
    border.h \
    page.h \
    font.h \
    content.h \
    read.h
