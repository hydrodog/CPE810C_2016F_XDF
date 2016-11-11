QT += core
QT -= gui

CONFIG += c++11

TARGET = finalProj
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ../x_ptext.cpp

HEADERS += \
    ../x_PText.hh
