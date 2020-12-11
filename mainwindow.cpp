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
#include "mainwindow.h"
#include<QTabWidget>
#include<QLabel>
#include<QGridLayout>
#include<QPushButton>
#include<QMediaPlaylist>
#include<QMediaPlayer>
#include<QFile>
#include<QFileDialog>
#include<QRegularExpression>
#include<filecrud.h>
#include<QTimeEdit>
#include<QDate>
#include<QTimer>
#include<QTime>
#include<QMessageBox>
#include<ayar.h>
#include<saatpzrts.h>
#include<saatsl.h>
#include<saatcrsmb.h>
#include<saatprsmb.h>
#include<saatcm.h>
#include<saatcmrts.h>
#include<saatpzr.h>
#include<QApplication>
#include<QDesktopWidget>
#include<QMenu>
#include<QCloseEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
 {

    trayIcon=new QSystemTrayIcon(this);
    init();

    //*******************tray***********************************/
      // Tray icon menu
      auto menu = this->createMenu();
      this->trayIcon->setContextMenu(menu);

      // App icon
      auto appIcon = QIcon(":/icons/bell.png");
      this->trayIcon->setIcon(appIcon);
      this->setWindowIcon(appIcon);

      // Displaying the tray icon
      this->trayIcon->show();     // Note: without explicitly calling show(), QSystemTrayIcon::activated signal will never be emitted!

      // Interaction
      connect(trayIcon, &QSystemTrayIcon::activated, this, &MainWindow::iconActivated);
     // gizle();

      timergizle = new QTimer(this);
      connect(timergizle, SIGNAL(timeout()), this, SLOT(gizle()));
      timergizle->start(1);
     //Qt::WindowMaximizeButtonHint();

}
void MainWindow::init()
{
    this->resize(500,650);
    setFixedWidth(500);
    setFixedHeight(650);
    setWindowTitle("E-Zil 1.0");
    player = new QMediaPlayer(nullptr, QMediaPlayer::StreamPlayback);
    player->setVolume(70);
    ayarlst=fileToList("e-zil.conf");
   /***************************************************/
    QDir klasorpath;
    if (listGetLine(ayarlst,"muzikklasor")!="")
        klasorpath=listGetLine(ayarlst,"muzikklasor").split("|")[1];
    playlist = new QMediaPlaylist;
    klasorpath.setNameFilters({"*.wav" , "*.mp3"});
    for(const QFileInfo & finfo: klasorpath.entryInfoList()){
        playlist->addMedia(QUrl::fromLocalFile(finfo.absoluteFilePath()));
        //  qDebug()<<QUrl::fromLocalFile(finfo.absoluteFilePath());
        //);
    }
    player->setMedia(playlist);
    /****************************************************************/
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()/2 - this->width()/2);
    int y = (screenGeometry.height() - this->height()) / 2;
    this->move(x, y);
    this->setStyleSheet("background-color: #dfdfdf;");

    QTabWidget *tw=new QTabWidget(this);
    tw->resize(this->width(),this->height());
  /************************************************************/
    tw->addTab(ayar(),"Ayarlar");
    tw->addTab(saatpzrts(),"Pzrts");
    tw->addTab(saatsl(),"Salı");
    tw->addTab(saatcrsmb(),"Çrşmb");
    tw->addTab(saatprsmb(),"Prşmb");
    tw->addTab(saatcm(),"Cuma");
    tw->addTab(saatcmrts(),"Cmrts");
    tw->addTab(saatpzr(),"Pazar");

    timerZil = new QTimer(this);
    timerZil->start(1000);
    connect(timerZil, SIGNAL(timeout()), this, SLOT(zilKontrol()));
    timerZilBaslama = new QTimer(this);
    connect(timerZilBaslama, SIGNAL(timeout()), this, SLOT(zilBaslatma()));
}
void MainWindow::zilBaslatma()
{
    qDebug()<<"Kontol Devreye Girdi..";
    timerZil->start(1000);
    timerZilBaslama->stop();
}
void MainWindow::zilKontrol()
{

   const QDate dt = QDate::currentDate();
   // qDebug()<<dt.dayOfWeek();
   QStringList saatlist;
    if(dt.dayOfWeek()==7)
        saatlist=fileToList("e-zil-saatpzr.conf");
    else if(dt.dayOfWeek()==6)
        saatlist=fileToList("e-zil-saatcmrts.conf");
    else if(dt.dayOfWeek()==5)
        saatlist=fileToList("e-zil-saatcm.conf");
    else if(dt.dayOfWeek()==4)
        saatlist=fileToList("e-zil-saatprsmb.conf");
    else if(dt.dayOfWeek()==3)
        saatlist=fileToList("e-zil-saatcrsmb.conf");
    else if(dt.dayOfWeek()==2)
        saatlist=fileToList("e-zil-saatsl.conf");
    else
        saatlist=fileToList("e-zil-saatpzrts.conf");

    //QString girissaat=listGetLine(saatlist,"");
   // qDebug()<< QTime::currentTime().hour();
   // qDebug()<< QTime::currentTime().minute();
    QString saat=QTime::currentTime().toString("hh:mm:ss").split(":")[0];
    QString dakika=QTime::currentTime().toString("hh:mm:ss").split(":")[1];
    QString currentsaat=saat+":"+(dakika);
    /**********************Bilgisayar Kontrol kontrol******************************/
        if(listGetLine(ayarlst,currentsaat)!="")
       {
            QString line=listGetLine(ayarlst,currentsaat);

            if(line.split("|")[0]=="hipckapat")
            {
               system("init 0");
                qDebug()<<"denemehi";
            }
            if(line.split("|")[0]=="hspckapat")
            {
                qDebug()<<"denemehs";
                system("init 0");
            }
        }
        /************************************************/

/**********************Müzik Yayın kontrol******************************/
    if(listGetLine(ayarlst,currentsaat)!="")
   {
        QString line=listGetLine(ayarlst,currentsaat);

        if(line.split("|")[0]=="muzikbaslama")
        {
            system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false");
            system("sleep 1");

            system("pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo 80000");

            player->play();
        }
        if(line.split("|")[0]=="muzikson")
        {
//            system("pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo 80000");

            player->stop();
        }
    }
    /************************************************/
    if(listGetLine(saatlist,currentsaat)!="")
   {
        system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false");
        system("sleep 1");

        system("pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo 80000");

       qDebug()<<"Çalıyor....."<<listGetLine(saatlist,currentsaat);
       qDebug()<<currentsaat;
       timerZil->stop();
       timerZilBaslama->start(70000);

     if(listGetLine(saatlist,currentsaat).split("|")[1]==currentsaat)
       {

            if(listGetLine(ayarlst,"ogrencizil")!="")
            {
                QString filepath=listGetLine(ayarlst,"ogrencizil").split("|")[1];
                QFile* file = new QFile(filepath);
                if (file->open(QFile::ReadOnly)) {
                    qDebug()<<"Öğrenci Zili Çalıyor....."<<listGetLine(saatlist,currentsaat);
                    player->setMedia(QMediaContent(), file);
                    file->seek(0);
                    player->play();
                }
            }
       }
         if(listGetLine(saatlist,currentsaat).split("|")[2]==currentsaat)
       {
           if(listGetLine(ayarlst,"ogretmenzil")!="")
           {
               QString filepath=listGetLine(ayarlst,"ogretmenzil").split("|")[1];
               QFile* file = new QFile(filepath);
               if (file->open(QFile::ReadOnly)) {
                   qDebug()<<"Öğretmen Zili Çalıyor....."<<listGetLine(saatlist,currentsaat);
                   player->setMedia(QMediaContent(), file);
                   file->seek(0);
                   player->play();
               }
           }
       }
       if(listGetLine(saatlist,currentsaat).split("|")[3]==currentsaat)
       {

           if(listGetLine(ayarlst,"cikiszil")!="")
           {
               QString filepath=listGetLine(ayarlst,"cikiszil").split("|")[1];
               QFile* file = new QFile(filepath);
               if (file->open(QFile::ReadOnly)) {
                   qDebug()<<"Çıkış Zili Çalıyor....."<<listGetLine(saatlist,currentsaat);
                   player->setMedia(QMediaContent(), file);
                   file->seek(0);
                   player->play();
               }
           }
       }

   }

}
MainWindow::~MainWindow()
{
  //  delete ui;
}

QStringList MainWindow::listRemove(QStringList list,QString data)
 {
    // qDebug()<<"deneme-ddd"<<data;
    // QStringList list;
     //  qDebug()<<list;
     //list << "bayram|sun" << "cloud" << "sun|elif" << "firi|rain";
     QRegularExpression re(data);
     for(int i=0;i<list.count();i++)if(list[i].contains(re)) list.removeAt(i);
    // qDebug()<<list;
     return list;
 }
QString MainWindow::listGetLine(QStringList list,QString data)
 {
     //QStringList list;
     //list << "bayram|sun" << "cloud" << "sun|elif" << "firi|rain";
     QRegularExpression re(data);
     for(int i=0;i<list.count();i++) if(list[i].contains(re)) return list[i];
     //qDebug()<<list;
     return "";
 }
QStringList MainWindow::fileToList(QString filename)
 {
    FileCrud *fcc=new FileCrud();
    fcc->dosya=filename;
    QStringList list;
    for(int i=1;i<=fcc->fileCount();i++)
    {
         QString line=fcc->fileGetLine(i);
         if(line!="")
         {
             line.chop(1);
             QStringList lst=line.split("|");
             QString ln="";
             if(lst.count()>0)ln.append(lst[0]);
             if(lst.count()>1)ln.append("|").append(lst[1]);
             if(lst.count()>2)ln.append("|").append(lst[2]);
             if(lst.count()>3)ln.append("|").append(lst[3]);
             if(lst.count()>4)ln.append("|").append(lst[4]);
             if(lst.count()>5)ln.append("|").append(lst[5]);
             if(lst.count()>6)ln.append("|").append(lst[4]);
             if(lst.count()>7)ln.append("|").append(lst[7]);
             if(lst.count()>8)ln.append("|").append(lst[8]);
             if(lst.count()>9)ln.append("|").append(lst[9]);

             list <<ln;
            // qDebug()<<ln;
             // list <<lst[0]+"|"+lst[1]+"|"+lst[2]+"|"+lst[3]+"|"+lst[4]+"|"+lst[5];

         }
    }
     //QStringList list;
     //list << "bayram|sun" << "cloud" << "sun|elf" << "firi|rain";
    // QRegularExpression re(data);
     //for(int i=0;i<list.count();i++)if(list[i].contains(re)) list.removeAt(i);
     //qDebug()<<list;
     return list;
 }
void MainWindow::listToFile(QStringList list, QString filename)
 {
  //  qDebug()<<"selam listtofile";
    FileCrud *fcc=new FileCrud();
    fcc->dosya=filename;
    //QStringList list;
    fcc->fileRemove();
    for(int i=0;i<list.count();i++)
    {
         QString line=list[i];
         if(line!="")
         {
             //line.chop(1);
             QStringList lst=line.split("|");
             //qDebug()<<line;
             QString ln="";
             if(lst.count()>0)ln.append(lst[0]);
             if(lst.count()>1)ln.append("|").append(lst[1]);
             if(lst.count()>2)ln.append("|").append(lst[2]);
             if(lst.count()>3)ln.append("|").append(lst[3]);
             if(lst.count()>4)ln.append("|").append(lst[4]);
             if(lst.count()>5)ln.append("|").append(lst[5]);
             if(lst.count()>6)ln.append("|").append(lst[4]);
             if(lst.count()>7)ln.append("|").append(lst[7]);
             if(lst.count()>8)ln.append("|").append(lst[8]);
             if(lst.count()>9)ln.append("|").append(lst[9]);

             //qDebug()<<ln;
             fcc->fileWrite(ln);
            // fcc->fileWrite(lst[0]+"|"+lst[1]+"|"+lst[2]+"|"+lst[3]+"|"+lst[4]+"|"+lst[5]);

         }

    }
 }


void  MainWindow::gizle()
{
    //hide();
   // qDebug()<<"deded";
    QWidget::hide();
    timergizle->stop();
  //  if(socket->waitForConnected())//bağlantı varsa
    //{
   // if (timeoutsecond!="")    timer->start(timeoutsecond.toInt());
    //else timer->start(3000);
  //  qDebug()<<"Paket Gönderme Başladı..";
    //}//else qDebug()<<"Paket Gönderilemiyor..";
}

QMenu* MainWindow::createMenu()
{
  // App can exit via Quit menu
 /* auto quitAction = new QAction("&Kapat", this);
  connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
  auto ayarAction = new QAction("&Ayarlar", this);
  connect(ayarAction, &QAction::triggered, qApp, gizle());
*/
    auto minimizeAction = new QAction(tr("Gi&zle"), this);
    connect(minimizeAction, &QAction::triggered, this, &QWidget::hide);

   /* auto maximizeAction = new QAction(tr("Ma&ximize"), this);
    connect(maximizeAction, &QAction::triggered, this, &QWidget::showMaximized);
*/
    auto restoreAction = new QAction(tr("&Ayarlar"), this);
    connect(restoreAction, &QAction::triggered, this, &QWidget::showNormal);

    auto quitAction = new QAction(tr("&Kapat"), this);
    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
    auto menu = new QMenu(this);
    //menu->addAction(quitAction)


    menu->addAction(minimizeAction);
    //menu->addAction(maximizeAction);
    menu->addAction(restoreAction);
    menu->addSeparator();
    menu->addAction(quitAction);

   // trayIcon = new QSystemTrayIcon(this);
    //trayIcon->setContextMenu(trayIconMenu);

    //;

  return menu;
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason_)
{
  switch (reason_) {
  case QSystemTrayIcon::Trigger:
    this->trayIcon->showMessage("E-Zil", "Okul Zil Sistemi!");
    break;
  default:
    ;
  }
}

void MainWindow::WidgetClosed()
{
    QWidget::hide();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    emit WidgetClosed();
     event->ignore();

}
