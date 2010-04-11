# -------------------------------------------------
# Project created by QtCreator 2010-04-10T12:45:37
# -------------------------------------------------
QT += network
QT -= gui
TARGET = qt_FTP_server
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    ../server.cpp \
    servethread.cpp \
    reqqueue.cpp \
    queueitem.cpp \
    acceptionthread.cpp \
    listenthread.cpp
HEADERS += ../server.h \
    servethread.h \
    reqqueue.h \
    queueitem.h \
    acceptionthread.h \
    listenthread.h
