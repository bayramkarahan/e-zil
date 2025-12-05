#-------------------------------------------------
#
# Project created by QtCreator 2019-07-02T00:29:01
#
#-------------------------------------------------

QT += widgets network core gui multimedia # multimediawidgets
#apt install libqt5multimedia5
#sudo apt-get install qtmultimedia5-dev

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = e-zil-gui
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
        mainwindow.cpp

HEADERS += \
    Database.h \
        mainwindow.h \
    saatpzrts.h \
    hakkinda.h \
    giris.h \
    ayar.h


RESOURCES += \
    resources.qrc


DEFINES += QT_DEPRECATED_WARNINGS

target.path = /usr/bin

desktop_file.files = e-zil.desktop
desktop_file.path = /usr/share/applications/

icon.files = icons/e-zil.svg
icon.path = /usr/share/icons/

conf.files = e-zil.conf
conf.path = /usr/share/e-zil

music_files.files = e-zil-ses/
music_files.path = /usr/share/e-zil/

INSTALLS += target icon music_files conf

DISTFILES += \
    e-zil.conf
