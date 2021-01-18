/*****************************************************************************
 *   Copyright (C) 2020 by Bayram KARAHAN                                    *
 *   <bayramk@gmail.com>                                                     *
 *                                                                           *
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation; either version 3 of the License, or       *
 *   (at your option) any later version.                                     *
 *                                                                           *
 *   This program is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *   GNU General Public License for more details.                            *
 *                                                                           *
 *   You should have received a copy of the GNU General Public License       *
 *   along with this program; if not, write to the                           *
 *   Free Software Foundation, Inc.,                                         *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .          *
 *****************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once
#include <QMainWindow>
#include<QLineEdit>
#include<QMediaPlayer>
#include<QSystemTrayIcon>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
virtual void closeEvent ( QCloseEvent * event );

public slots:
   // QWidget ayar();
    void  WidgetClosed();
    void listToFile(QStringList list, QString filename);
    QStringList fileToList(QString filename);
    QString listGetLine(QStringList list,QString data);
    QStringList listRemove(QStringList list,QString data);
    QStringList listReplace(QStringList list,QString oldData,QString newData,int index);
    QStringList listMerge(QStringList list1, QStringList list2,int dataIndex);
    QStringList listGetList(QStringList list, QString data,int index);
    void zilKontrol();
    void zilBaslatma();
    void init();
    void iconActivated(QSystemTrayIcon::ActivationReason);
    void gizle();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
     bool tenefusMuzikYayinState;
    bool oglenMuzikYayinState;
     QStringList saatlist;
     QStringList ayarlist;
     QString trn;
     QString gun;
     QString currentsaat;
     bool playState;
    Ui::MainWindow *ui;
     QTabWidget *tw;
    QWidget *giris();
    QWidget *hakkinda();
    QWidget *ayar();
    QWidget *saatpzrts(int guns);
    QWidget *saatsl();
    QWidget *saatcrsmb();
    QWidget *saatprsmb();
    QWidget *saatcm();
    QWidget *saatcmrts();
    QWidget *saatpzr();
    QString currentsaatState;
    QMediaPlayer* player;
    QTimer *timerZil;
    QTimer *timerZilBaslama;

    QMediaPlaylist *playlist;
    QTimer *timergizle;
    QSystemTrayIcon* trayIcon;
    QMenu* trayIconMenu;
    bool tenefusYayin;
    QMenu* createMenu();

};

#endif // MAINWINDOW_H
