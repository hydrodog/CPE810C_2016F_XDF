
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += main.cpp\
        mainwindow.cpp \
    inputdialog.cpp

HEADERS  += mainwindow.h \
    inputdialog.h

FORMS    += mainwindow.ui \
    inputdialog.ui
