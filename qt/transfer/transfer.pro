#-------------------------------------------------
#
# Project created by QtCreator 2017-04-06T21:56:50
#
#-------------------------------------------------

QT       += core gui network sql xml widgets

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = transfer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp\
        control/QRoundProgressBar.cpp\
        common/HttpFun.cpp \
        common/localstorage.cpp \
        common/ReqHistory.cpp

HEADERS  += mainwindow.h\
            control/QRoundProgressBar.h\
            common/HttpFun.h \
            common/localstorage.h \
            common/ReqHistory.h

FORMS    += mainwindow.ui

win32 {
    src_dir = $$PWD\lib\*.*
    CONFIG(debug, debug|release) {
        dst_dir = $$OUT_PWD\\debug\\
    } else {
        dst_dir = $$OUT_PWD\\release\\
    }

    # dst_dir 最后的 \\ 是必须的，用来标示 xcopy 到一个文件夹，若不存在，创建之

    # Replace slashes in paths with backslashes for Windows
    src_dir ~= s,/,\\,g
    dst_dir ~= s,/,\\,g

    !exists($$dst_dir):system(xcopy $$src_dir $$dst_dir /y /e)
}

RESOURCES += \
    imgs.qrc

