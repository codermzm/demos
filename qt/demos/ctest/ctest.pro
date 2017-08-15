QT += core
QT -= gui

DESTDIR += ../bin

CONFIG += c++11

TARGET = ctest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += sources/main.cpp \
    include/avltree.cpp

HEADERS += include/arraypoint.h\
           include/objectpointer.h\
           include/templatetest.h \
    include/avltree.h
