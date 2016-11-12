#-------------------------------------------------
#
# Project created by QtCreator 2016-02-04T23:32:20
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = buscador
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    resultado.cpp \
    imagen.cpp

HEADERS  += mainwindow.h \
    resultado.h \
    imagen.h

FORMS    += mainwindow.ui \
    resultado.ui \
    imagen.ui
