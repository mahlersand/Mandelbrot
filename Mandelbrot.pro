#-------------------------------------------------
#
# Project created by QtCreator 2014-11-27T19:53:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mandelbrot
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    brotwidget.cpp

HEADERS  += mainwindow.h \
    brotwidget.h \
    menu.h \
    renderrunnable.h

FORMS    += mainwindow.ui
