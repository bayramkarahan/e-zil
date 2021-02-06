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
#include<giris.h>
#include<hakkinda.h>
#include<QApplication>
#include<QDesktopWidget>
#include<QMenu>
#include<QCloseEvent>

#include <iostream>
#include <fstream>
#include <QThread>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
 {
    /**************raspberry pi  ayarları********************/
    //echo "24" > /sys/class/gpio/export
    QStringList lst1;lst1<<"24";listToFile(lst1,"export","/sys/class/gpio");
    //echo "in" > /sys/class/gpio/gpio24/direction
    QStringList lst2;lst2<<"in";listToFile(lst2,"direction","/sys/class/gpio/gpio24");
    ///if (( "$(cat /sys/class/gpio/gpio24/value)" == "1" ))
    /********************************************************/
    sistem=2; //linux aplay
   // sistem=1;//windows multimedya

   // wl=new QWidgetAction(this);

    trayIcon=new QSystemTrayIcon(this);
    init();// Başlangıç ayarları yapıldı

    //*******************tray***********************************/
      // Tray icon menu
      auto menu = this->createMenu();
      this->trayIcon->setContextMenu(menu);

      // App icon
      auto appIcon = QIcon(":/icons/bell.svg");
      this->trayIcon->setIcon(appIcon);
      this->setWindowIcon(appIcon);

      // Displaying the tray icon
      this->trayIcon->show();     // Note: without explicitly calling show(), QSystemTrayIcon::activated signal will never be emitted!

      // Interaction
      connect(trayIcon, &QSystemTrayIcon::activated, this, &MainWindow::iconActivated);
     // gizle();


      /**********************form ayarları yapıldı***********************/
      //this->resize(500,650);
      setFixedWidth(500);
      setFixedHeight(600);
      setWindowTitle("E-Zil 2.0");
      QRect screenGeometry = QApplication::desktop()->screenGeometry();
      int x = (screenGeometry.width()/2 - this->width()/2);
      int y = (screenGeometry.height() - this->height()) / 2;
      this->move(x, y);
      this->setStyleSheet("background-color: #dfdfdf;");

      tw=new QTabWidget(this);
      tw->resize(this->width(),this->height());
    /***********************Tab Ayarları Yapıldı********************/
      QFont ff( "Arial", 7.5, QFont::Normal);
      tw->setFont(ff);

     tw->addTab(giris(),"Giriş");
      tw->addTab(ayar(),"Ayarlar");
      tw->addTab(saatpzrts(1),"Pzrts");
      tw->addTab(saatpzrts(2),"Salı");
      tw->addTab(saatpzrts(3),"Çrşmb");
      tw->addTab(saatpzrts(4),"Prşmb");
      tw->addTab(saatpzrts(5),"Cuma");
      tw->addTab(saatpzrts(6),"Cmrts");
      tw->addTab(saatpzrts(7),"Pazar");
      tw->addTab(hakkinda(),"Hakkında");
      /*********************************************************************************/

      timergizle = new QTimer(this);
      connect(timergizle, SIGNAL(timeout()), this, SLOT(gizle()));
      timergizle->start(1);



      timerZil = new QTimer(this);
     // timerZil->start(3000);
      //connect(timerZil, SIGNAL(timeout()), this, SLOT(zilKontrol()));

      timerZilBaslama = new QTimer(this);
      connect(timerZilBaslama, SIGNAL(timeout()), this, SLOT(zilBaslatma()));
      timerZilBaslama->start(1000);

      player = new QMediaPlayer(nullptr, QMediaPlayer::StreamPlayback);
      player->setVolume(70);
}
void MainWindow::init()
{
    qDebug()<<"Ayarlar Güncellendi...";

    const QDate dt = QDate::currentDate();
    QStringList listconf=fileToList("e-zil.conf",QDir::homePath());
    // qDebug()<<dt.dayOfWeek();
    gun=QString::number(dt.dayOfWeek())+"s";
    trn=QString::number(dt.dayOfWeek())+"st";
    saatlist=listGetList(listconf, gun,0);//0 sütun bilgisi olan güne göre listconf listesinden filitreleniyor
    ayarlist=listGetList(listconf, "ayar",0);//0 sütun bilgisi olan güne göre listconf listesinden filitreleniyor
    /******************Player ve Playlist ayarları yapılıyor***********/

    QDir klasorpath;
    if (listGetLine(ayarlist,"muzikklasor")!="")
        klasorpath=listGetLine(ayarlist,"muzikklasor").split("|")[2];
    playlist = new QMediaPlaylist;
    klasorpath.setNameFilters({"*.wav" , "*.mp3"});
    for(const QFileInfo & finfo: klasorpath.entryInfoList()){

        playlist->addMedia(QUrl::fromLocalFile(finfo.absoluteFilePath()));
        muziklist.append(QUrl::fromLocalFile(finfo.absoluteFilePath()).toString().remove(0,7)).append(" ");

       // qDebug()<<QUrl::fromLocalFile(finfo.absoluteFilePath()).toString();
    }

}
void MainWindow::zilBaslatma()
{
     zilKontrol();
}
void MainWindow::zilKontrol()
{
    /********************raspberry pi 24 pin in=1 in=0 ************/
    //if (( "$(cat /sys/class/gpio/gpio24/value)" == "1" ))
    string myText;
    ifstream myFile("/sys/class/gpio/gpio24/value");
    //ifstream myFile("/home/by/value");
    getline (myFile, myText);
    myFile.close();
          if(myText=="1"&&remoteMuzikState==false)
        {
            remoteMuzikState=true;
            myText="0";
            //ofstream MyReadFile("/sys/class/gpio/gpio24/value");
             //  ofstream MyFile("/home/by/value");  // Create and open a text file
             //MyFile << "0";                      // Write to the file
             //MyFile.close();                     // Close the file

            QString istiklaldosya;
            if (listGetLine(ayarlist,"istiklalzil")!="")
                istiklaldosya=listGetLine(ayarlist,"istiklalzil").split("|")[2];

            QStringList arguments;
            QString kmt=QString("aplay "+istiklaldosya);
            arguments << "-c" << kmt;
            process.start("/bin/bash",arguments);
            // system("sleep 2000");
            QThread::msleep(4000);
            //qDebug()<<"kumanda On Click"<<istiklaldosya;
        }
          if(myText=="1"&&remoteMuzikState==true)
        {
              //ofstream MyReadFile("/sys/class/gpio/gpio24/value");
              //   ofstream MyFile("/home/by/value");  // Create and open a text file
               // MyFile << "0";                      // Write to the file
               // MyFile.close();                     // Close the file
              process.terminate();
              remoteMuzikState=false;

              // qDebug()<<"kumanda Off Click";
          }


    /**************************************************************/
    currentsaat=QTime::currentTime().toString("hh:mm:ss");
    QString line=listGetLine(saatlist,currentsaat);
    if(line!="")
   {
       //qDebug()<<">>"<<QTime::currentTime().toString("hh:mm:ss")<<trn<<gun<<currentsaat<<tenefusYayin<<line.left(3)<<line.left(2);
        if(line.left(3)==trn)
        {
            playState=true;
            if(listGetLine(ayarlist,"torenzil")!="")
            {
                if(sistem==1)
                {
                system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false"); ///system("sleep 1");
                QString deger=listGetLine(ayarlist,"torenzilseviye").split("|")[2];
                QString kmt22="pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo "+deger+"000";
                system(kmt22.toStdString().c_str());

                QString filepath=listGetLine(ayarlist,"torenzil").split("|")[2];
                QFile* file = new QFile(filepath);
                if (file->open(QFile::ReadOnly)) {
                    player->setMedia(QMediaContent(), file);
                    file->seek(0);
                    player->play();
                }
                }else{
                    QStringList arguments;
                    QString kmt=QString("aplay "+listGetLine(ayarlist,"torenzil").split("|")[2]);
                    arguments << "-c" << kmt;
                    process.start("/bin/bash",arguments);

                }
                qDebug()<<"Tören Zili Çalıyor....."<<listGetLine(saatlist,currentsaat)<<currentsaat;

            }

        }
        if(playState){playState=false; return;}
        if(line.left(2)==gun&&line.split("|")[1]==currentsaat)
        {

            if(listGetLine(ayarlist,"ogrencizil")!="")
            {
                if(sistem==1)
                {
                    system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false"); ///system("sleep 1");
                    QString deger=listGetLine(ayarlist,"ogrencizilseviye").split("|")[2];
                    QString kmt22="pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo "+deger+"000";
                    system(kmt22.toStdString().c_str());

                    QString filepath=listGetLine(ayarlist,"ogrencizil").split("|")[2];
                    QFile* file = new QFile(filepath);
                    if (file->open(QFile::ReadOnly)) {
                        player->setMedia(QMediaContent(), file);
                        file->seek(0);
                        player->play();
                    }
                }else{
                    QStringList arguments;
                    QString kmt=QString("aplay "+listGetLine(ayarlist,"ogrencizil").split("|")[2]);
                    arguments << "-c" << kmt;
                    process.start("/bin/bash",arguments);

                }
                qDebug()<<"Öğrenci Zili Çalıyor....."<<listGetLine(saatlist,currentsaat)<<currentsaat;
            }
        }
        if(line.left(2)==gun&&line.split("|")[2]==currentsaat)
        {
            if(listGetLine(ayarlist,"ogretmenzil")!="")
            {
                if(sistem==1)
                {
                    system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false"); ///system("sleep 1");
                    QString deger=listGetLine(ayarlist,"ogretmenzilseviye").split("|")[2];
                    QString kmt22="pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo "+deger+"000";
                    system(kmt22.toStdString().c_str());

                    QString filepath=listGetLine(ayarlist,"ogretmenzil").split("|")[2];
                    QFile* file = new QFile(filepath);
                    if (file->open(QFile::ReadOnly)) {
                        player->setMedia(QMediaContent(), file);
                        file->seek(0);
                        player->play();
                    }
                }else{
                    QStringList arguments;
                    QString kmt=QString("aplay "+listGetLine(ayarlist,"ogretmenzil").split("|")[2]);
                    arguments << "-c" << kmt;
                    process.start("/bin/bash",arguments);
                }
                qDebug()<<"Öğretmen Zili Çalıyor....."<<listGetLine(saatlist,currentsaat)<<currentsaat;
            }
        }
        if(line.left(2)==gun&&line.split("|")[3]==currentsaat)
        {
            if(sistem==1)
            {
                if(listGetLine(ayarlist,"cikiszil")!="")
                {
                    system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false"); ///system("sleep 1");
                    QString deger=listGetLine(ayarlist,"cikiszilseviye").split("|")[2];
                    QString kmt22="pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo "+deger+"000";
                    system(kmt22.toStdString().c_str());

                    QString filepath=listGetLine(ayarlist,"cikiszil").split("|")[2];
                    QFile* file = new QFile(filepath);
                    if (file->open(QFile::ReadOnly)) {
                        qDebug()<<"Çıkış Zili Çalıyor....."<<listGetLine(saatlist,currentsaat)<<currentsaat;
                        player->setMedia(QMediaContent(), file);
                        file->seek(0);
                        player->play();
                    }
                }
                else{
                    QStringList arguments;
                    QString kmt=QString("aplay "+listGetLine(ayarlist,"cikiszil").split("|")[2]);
                    arguments << "-c" << kmt;
                    process.start("/bin/bash",arguments);
                }
                qDebug()<<"Çıkış Zili Çalıyor....."<<listGetLine(saatlist,currentsaat)<<currentsaat;
            }
        }
        if(line.left(2)==gun&&line.split("|")[4]==currentsaat)
        {
            if(sistem==1)
            {
                if (listGetLine(ayarlist,"muzikklasor")!="")
                {
                    player->setMedia(playlist);
                    system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false"); ///system("sleep 1");
                    QString deger=listGetLine(ayarlist,"muzikyayinseviye").split("|")[2];
                    QString kmt22="pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo "+deger+"000";
                    system(kmt22.toStdString().c_str());
                    player->play();
                    tenefusYayin=true;
                }}else{
                QStringList arguments;
                QString kmt=QString("aplay "+muziklist);
                arguments << "-c" << kmt;
                process.start("/bin/bash",arguments);

            }
            qDebug()<<"Tenefüs Müzik Yayını Başladı..";
        }
        if(line.left(2)==gun&&line.split("|")[5]==currentsaat)
        {
            if(sistem==1)
            {
                player->stop();
                qDebug()<<"Tenefüs Müzik Yayını Durdu..";
                tenefusYayin=false;
            }else{
                process.terminate();
                qDebug()<<"Tenefüs Müzik Yayını Durdu..";
                tenefusYayin=false;

            }
        }

    }
    QString lineayar=listGetLine(ayarlist,currentsaat);
    if(lineayar!="")
   {
     //  qDebug()<<">>"<<QTime::currentTime().toString("hh:mm:ss")<<trn<<gun<<currentsaat<<tenefusYayin<<lineayar.left(3)<<lineayar.left(2);

        if(lineayar.split("|")[0]=="muzikbaslama")
        {
            if (listGetLine(ayarlist,"muzikklasor")!="")
            {
                if(tenefusMuzikYayinState)
                {if(sistem==1)
                    {
                        system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false"); ///system("sleep 1");
                        QString deger=listGetLine(ayarlist,"muzikyayinseviye").split("|")[2];
                        QString kmt22="pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo "+deger+"000";
                        system(kmt22.toStdString().c_str());
                        player->setMedia(playlist);
                        player->play();
                    }else{
                        QStringList arguments;
                        QString kmt=QString("aplay "+muziklist);
                        arguments << "-c" << kmt;
                        process.start("/bin/bash",arguments);

                    }
                }


                if(oglenMuzikYayinState)
                {
                    if(sistem==1)
                    {
                        system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false"); ///system("sleep 1");
                        QString deger=listGetLine(ayarlist,"muzikyayinseviye").split("|")[2];
                        QString kmt22="pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo "+deger+"000";
                        system(kmt22.toStdString().c_str());
                        player->setMedia(playlist);
                        player->play();
                    }else{
                        QStringList arguments;
                        QString kmt=QString("aplay "+muziklist);
                        arguments << "-c" << kmt;
                        process.start("/bin/bash",arguments);

                    }

                }

                }
        }
        if(lineayar.split("|")[0]=="muzikson")
        {if(sistem==1)
            {
                player->stop();
            }else{
                process.terminate();

            }
        }
        if(lineayar.split("|")[0]=="hipckapat")
        {
            system("init 0");
        }
        if(lineayar.split("|")[0]=="hspckapat")
        {
            system("init 0");

        }
   }

}
MainWindow::~MainWindow()
{
  //  delete ui;
}

QStringList MainWindow::listMerge(QStringList list1, QStringList list2, int dataIndex)
{
    for(int i=0;i<list1.count();i++)
    {
        QString line=list1[i];
        if(line!="")
        {

            QStringList lst=line.split("|");
            list2=listRemove(list2,lst[dataIndex]);
        }
    }
    for(int i=0;i<list1.count();i++)
    {
       list2.append(list1[i]);
    }
    return list2;
}
QStringList MainWindow::listReplace(QStringList list, QString oldData, QString newData, int index)
 {
    QStringList liste;
         QRegularExpression re(oldData);
     for(int i=0;i<list.count();i++)
     {
         if(list[i].contains(re))
         {
             QStringList lst=list[i].split("|");
             lst[index].replace(oldData, newData);
            // qDebug()<<lst;

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
            // list.removeAt(i);
             liste.append(ln);
         }
     }
    // qDebug()<<list;
     return liste;
 }

QStringList MainWindow::listGetList(QStringList list, QString data,int index)
 {
    QStringList liste;
    QRegularExpression re(data);
     for(int i=0;i<list.count();i++)
     {
         if(list[i].contains(re))
         {
            liste.append(list[i]);

         }
     }
    // qDebug()<<list;
     return liste;
 }
QStringList MainWindow::listRemove(QStringList list,QString data)
 {
         QRegularExpression re(data);
     for(int i=0;i<list.count();i++)if(list[i].contains(re)) list.removeAt(i);
    // qDebug()<<list;
     return list;
 }
QString MainWindow::listGetLine(QStringList list,QString data)
 {
         QRegularExpression re(data);
     for(int i=0;i<list.count();i++) if(list[i].contains(re)) return list[i];
     //qDebug()<<list;
     return "";
 }
QStringList MainWindow::fileToList(QString filename,QString path)
 {
    FileCrud *fcc=new FileCrud();
    fcc->dosya=path+"/"+filename;
    //qDebug()<<"dosya:"<<fcc->dosya;
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
        return list;
 }
void MainWindow::listToFile(QStringList list, QString filename, QString path)
 {
  //  qDebug()<<"selam listtofile";
    FileCrud *fcc=new FileCrud();
    fcc->dosya=path+"/"+filename;
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
