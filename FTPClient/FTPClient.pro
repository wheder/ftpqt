# -------------------------------------------------
# Project created by QtCreator 2010-04-09T14:49:39
# -------------------------------------------------
QT += network
TARGET = FTPClient
TEMPLATE = app
SOURCES += main.cpp \
    connection.cpp \
    panel.cpp \
    transferqueueitem.cpp \
    qxftp.cpp
HEADERS += qxftp.h\
    connection.h \
    panel.h \
    transferqueueitem.h
FORMS += connection.ui \
    panel.ui
RESOURCES += ftpClient.qrc
