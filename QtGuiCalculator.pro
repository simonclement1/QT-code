#-------------------------------------------------
#
# Project created by QtCreator 2016-05-08T17:38:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtGuiCalculator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    resultdialog.cpp

HEADERS  += mainwindow.h \
    resultdialog.h

FORMS    += mainwindow.ui \
    resultdialog.ui

RESOURCES += \
    resources.qrc
