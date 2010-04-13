# -------------------------------------------------
# Project created by QtCreator 2010-04-08T07:48:17
# -------------------------------------------------
QT += network

# QT -= gui
TARGET = ftpServer
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    ../tcpserver.cpp \
    ../connectiondata.cpp
HEADERS += ../tcpserver.h \
    ../connectiondata.h
