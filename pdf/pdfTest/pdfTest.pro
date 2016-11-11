#-------------------------------------------------
#
# Project created by QtCreator 2016-11-07T17:35:34
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = pdfTest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    TextExtractor.cpp \
    main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/podofo/lib/release/ -lpodofo
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/podofo/lib/debug/ -lpodofo
else:unix: LIBS += -L$$PWD/podofo/lib/ -lpodofo

INCLUDEPATH += $$PWD/podofo/include
DEPENDPATH += $$PWD/podofo/include

HEADERS += \
    TextExtractor.h
