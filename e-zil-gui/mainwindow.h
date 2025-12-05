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
#include<QProcess>
#include<QTime>
#include<QThread>
#include<QTimer>
#include<QEventLoop>
#include<QLabel>
#include<QSize>
#include<QScreen>
#include<QTableWidget>
#include<Database.h>
#include<QTimeEdit>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    struct DersSaatleri {
        QTimeEdit *toren;
        QTimeEdit *giris;
        QTimeEdit *baslangic;
        QTimeEdit *cikis;
        QTimeEdit *teneffus;
    };

public slots:

    bool dosyaVarmi(QString dosya);

    void SZSgizle();
     void SZSgoster();
      void about();
      void  widgetShow();
    void onemliGunSlot();
    void webTableCellDoubleClicked(int iRow, int iColumn);
    void resetStatus()
    {
        torenMuzikPlayStatus=false;
        ogrenciMuzikPlayStatus=false;
        ogretmenMuzikPlayStatus=false;
        cikisMuzikPlayStatus=false;
        tenefusMuzikYayinPlayStatus=false;
        molaMuzikYayinPlayStatus=false;
    };

    QTime saniyeToSaat(QString _zaman);
    QString saatToSaniye(QTime _zaman);
    void zamanHesapla(QTime _sg,QTime _sb,QTime _sc,QTime _st ,QString baslamaZamani);
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QTableWidget *twl;
    bool ekilitState=false;
    bool torenMuzikPlayStatus=false;
    bool ogrenciMuzikPlayStatus=false;
    bool ogretmenMuzikPlayStatus=false;
    bool cikisMuzikPlayStatus=false;
    bool tenefusMuzikYayinPlayStatus=false;
    bool molaMuzikYayinPlayStatus=false;

    int girissaniye,baslamasaniye,cikissaniye,tenefussaniye,gbfark,bcfark,ctfark;
    QTime sb,sg,sc,st;
    QString muziklist;
    QProcess process;
    QString localDir;
     bool tenefusMuzikYayinState;
    bool molaMuzikYayinState;
    bool oglenMuzikYayinState;
    bool SZSState=false;
    bool SZSShowState=false;
    bool gunState=false;
      QStringList saatlist;
     QStringList ayarlist;
     QStringList gunlist;

     QString trn;
     QString gun;
     QString currentsaat;
     QString tempCurrentsaat;
     bool playState;
     bool playStateToren;
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

    QEventLoop loop;
    QTimer timer1;

    QMediaPlaylist *playlist;
    QTimer *timergizle;
    bool tenefusYayin;
    int en,boy;
};

#endif // MAINWINDOW_H
