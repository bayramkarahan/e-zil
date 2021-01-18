#-------------------------------------------------
#
# Project created by QtCreator 2019-07-02T00:29:01
#
#-------------------------------------------------

QT       += widgets  xml network core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = e-zil
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
contains(QT_VERSION, ^5\\..*) {
  PKGCONFIG += Qt5GStreamer-1.0 Qt5GStreamerUi-1.0 Qt5GLib-2.0
  }
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    singleinstance.cpp

HEADERS += \
        mainwindow.h \
    filecrud.h \
    menu.h \
    ayar.h \
    saatpzrts.h \
    singleinstance.h \
    giris.h \
    hakkinda.h


RESOURCES += \
    resources.qrc


DEFINES += QT_DEPRECATED_WARNINGS

target.path = /usr/bin

desktop_file.files = e-zil.desktop
desktop_file.path = /usr/share/applications/

icon.files = icons/bell.svg
icon.path = /usr/share/e-zil

music_files.files = musics/
music_files.path = /tmp/

conf_files.files = e-zil.conf
conf_files.path = /tmp/

auto_start.files = e-zil.desktop
auto_start.path = /etc/xdg/autostart/

INSTALLS += target desktop_file icon music_files auto_start conf_files

DISTFILES += \
    e-zil.conf
