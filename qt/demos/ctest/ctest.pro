QT += core
QT -= gui

CONFIG += c++11

TARGET = ctest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    arraypoint.h \
    templatetest.h
