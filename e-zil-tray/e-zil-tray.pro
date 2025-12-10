#-------------------------------------------------
#
# Project created by QtCreator 2019-07-02T00:29:01
#
#-------------------------------------------------

QT += widgets network core gui
#multimedia # multimediawidgets
#apt install libqt5multimedia5
#sudo apt-get install qtmultimedia5-dev

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = e-zil-tray
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    miniaudio.cpp \
    miniaudioplayer.cpp \
    singleinstance.cpp

HEADERS += \
    Database.h \
        mainwindow.h \
    miniaudioplayer.h \
    singleinstance.h \
    widget.h


RESOURCES += \
    resources.qrc


DEFINES += QT_DEPRECATED_WARNINGS

target.path = /usr/bin

icon.files = icons/bell.svg
icon.path = /usr/share/e-zil

auto_start.files = e-zil.desktop
auto_start.path = /etc/xdg/autostart/

INSTALLS += target icon auto_start

DISTFILES += \
    e-zil.conf\
    e-zil.desktop
