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



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
 {
      localDir="/usr/share/e-zil/";
   // wl=new QWidgetAction(this);
    timer1.setSingleShot(true);
    connect(&timer1, SIGNAL(timeout()), &loop, SLOT(quit()));
  //  connect(this, SIGNAL(replayReceived()), &loop, SLOT(quit()));

    trayIcon=new QSystemTrayIcon(this);

       //*******************tray**********************************/
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
      QSize screenSize = qApp->screens()[0]->size();
     // qDebug()<<screenSize.width()/65<<screenSize.height()/35;
      boy=screenSize.width()/65;
     en=boy;

      //this->resize(500,650);
      setFixedWidth(500);
      setFixedHeight(640);
      setWindowTitle("e-zil 2.7");
      QRect screenGeometry = QApplication::desktop()->screenGeometry();
      int x = (screenGeometry.width()/2 - this->width()/2);
      int y = (screenGeometry.height() - this->height()) / 2;
      this->move(x, y);
      this->setStyleSheet("background-color: #dfdfdf;");

      tw=new QTabWidget(this);
      tw->resize(this->width(),this->height());
      /*************************SZS ekranı*******************************************/
            widget=new Widget(en*0.6,boy*0.6);
            widget->move(screenSize.width()-widget->width()*1.5,30);
            widget->setObjectName("pageListwg");
            widget->setAttribute(Qt::WA_TranslucentBackground);
           // widget->show();

      init();// Başlangıç ayarları yapıldı

    /***********************Tab Ayarları Yapıldı********************/

      /*********************************************************************************/

      timergizle = new QTimer(this);
      connect(timergizle, SIGNAL(timeout()), this, SLOT(gizle()));
      timergizle->start(1);


     QTimer *timerWidget= new QTimer(this);
     connect(timerWidget, SIGNAL(timeout()), this, SLOT(widgetAktif()));
    timerWidget->start(5000);


      timerZilBaslama = new QTimer(this);
      connect(timerZilBaslama, SIGNAL(timeout()), this, SLOT(zilKontrol()));
      timerZilBaslama->start(6000);

      player = new QMediaPlayer(nullptr, QMediaPlayer::StreamPlayback);
      player->setVolume(70);




}
void MainWindow::init()
{
 ///  qDebug()<<"init...";

    const QDate dt = QDate::currentDate();
    QStringList listconf=fileToList("e-zil.conf");
    // qDebug()<<dt.dayOfWeek();
    gun=QString::number(dt.dayOfWeek())+"s";
    trn=QString::number(dt.dayOfWeek())+"storen";
    saatlist=listGetList(listconf, gun,0);//0 sütun bilgisi olan güne göre listconf listesinden filitreleniyor
    ayarlist=listGetList(listconf, "ayar",0);//0 sütun bilgisi olan güne göre listconf listesinden filitreleniyor
    /******************Player ve Playlist ayarları yapılıyor***********/

    QDir klasorpath;
    if (listGetLine(ayarlist,"muzikklasor")!="")
        klasorpath=QDir::homePath()+"/"+listGetLine(ayarlist,"muzikklasor").split("|")[2];
    playlist = new QMediaPlaylist;
    klasorpath.setNameFilters({"*.wav" , "*.mp3"});
    for(const QFileInfo & finfo: klasorpath.entryInfoList()){

        playlist->addMedia(QUrl::fromLocalFile(finfo.absoluteFilePath()));
        muziklist.append(QUrl::fromLocalFile(finfo.absoluteFilePath()).toString().remove(0,7)).append(" ");

       // qDebug()<<QUrl::fromLocalFile(finfo.absoluteFilePath()).toString();
    }


    /*****************************************************/
    if(listGetLine(ayarlist,"SZSState")!="")
        SZSState=listGetLine(ayarlist,"SZSState").split("|")[2].toInt();

    if(SZSState==true&&SZSShowState==false) {
        SZSShowState=true;
        qDebug()<<"widget showing..";
        widget->show();
    }

    if(SZSState==false){
        widget->close();
        SZSShowState=false;
    }

 //qDebug()<<"-------------"<<SZSState<<SZSShowState;


}

void MainWindow::widgetAktif()
{
    int k=boy*0.6;
    widget->zamanGostergesi->setText(QTime::currentTime().toString("hh:mm"));
   // widget->zamanGostergesiRenk->setStyleSheet("font-size: "+QString::number(10)+"px;background-color: #0000ff; border: 1px solid gray;border-radius: "+QString::number(k)+"px;");

    if( widget->zamanGostergesiDurum->text()=="S") {
         widget->zamanGostergesiRenk->setText("S");
         widget->zamanGostergesiRenk->setStyleSheet("font-size: "+QString::number(k)+"px;background-color: #ffccff; border: 1px solid gray;border-radius: "+QString::number(k)+"px;");}

     if( widget->zamanGostergesiDurum->text()=="TRN") {
          widget->zamanGostergesiRenk->setText("TRN");
          widget->zamanGostergesiRenk->setStyleSheet("font-size: "+QString::number(k)+"px;background-color: #0000ff; border: 1px solid gray;border-radius: "+QString::number(k)+"px;");}

     if( widget->zamanGostergesiDurum->text()=="TND") {
         widget->zamanGostergesiRenk->setText("TND");
         widget->zamanGostergesiRenk->setStyleSheet("font-size: "+QString::number(k)+"px;background-color: #ffff00; border: 1px solid gray;border-radius: "+QString::number(k)+"px;");}

    if( widget->zamanGostergesiDurum->text()=="TNF") {
         widget->zamanGostergesiRenk->setText("TNF");
         widget->zamanGostergesiRenk->setStyleSheet("font-size: "+QString::number(k)+"px;background-color: #ff0000; border: 1px solid gray;border-radius: "+QString::number(k)+"px;");}

    if( widget->zamanGostergesiDurum->text()=="D") {
         widget->zamanGostergesiRenk->setText("D");
         widget->zamanGostergesiRenk->setStyleSheet("font-size: "+QString::number(k)+"px;background-color: #00ff00; border: 1px solid gray;border-radius: "+QString::number(k)+"px;");}

    if( widget->zamanGostergesiDurum->text()=="ML") {
         widget->zamanGostergesiRenk->setText("ML");
         widget->zamanGostergesiRenk->setStyleSheet("font-size: "+QString::number(k)+"px;background-color: #00ffff; border: 1px solid gray;border-radius: "+QString::number(k)+"px;");}

    if( widget->zamanGostergesiDurum->text()=="A") {
         widget->zamanGostergesiRenk->setText("A");
         widget->zamanGostergesiRenk->setStyleSheet("font-size: "+QString::number(k)+"px;background-color: #ff00ff; border: 1px solid gray;border-radius: "+QString::number(k)+"px;");}

    widget->raise();
}

void MainWindow::zilKontrol()
{
    init();//ayarların yüklendiği yer
    currentsaat=QTime::currentTime().toString("hh:mm");
    int currentsaniye=QTime::currentTime().hour()*60*60+QTime::currentTime().minute()*60+QTime::currentTime().second();

   // qDebug()<<">>"<<QTime::currentTime().toString("hh:mm")<<trn<<gun<<currentsaat<<tenefusYayin<<saniye;
int tb=0,ogrenciGirisSaati=0,dersBaslamaSaati=0,cikisSaati=0,sorakiCikisSaati=0;
const QDate dt = QDate::currentDate();

int derssayisi=0;
if(listGetLine(ayarlist,"derssayisi")!="")
 derssayisi=listGetLine(ayarlist,"derssayisi").split("|")[2].toInt();

int torenBaslamaSaati=0;
if(listGetLine(saatlist,QString::number(dt.dayOfWeek())+"storen")!="")
 torenBaslamaSaati=listGetLine(saatlist,QString::number(dt.dayOfWeek())+"storen").split("|")[1].toInt();

int ilkOgrenciGirisSaati=0;
if(listGetLine(saatlist,QString::number(dt.dayOfWeek())+"s1")!="")
ilkOgrenciGirisSaati=listGetLine(saatlist,QString::number(dt.dayOfWeek())+"s1").split("|")[1].toInt();

int sonDersCikisSaati=0;
if(listGetLine(saatlist,QString::number(dt.dayOfWeek())+"s"+QString::number(derssayisi))!="")
sonDersCikisSaati=listGetLine(saatlist,QString::number(dt.dayOfWeek())+"s"+QString::number(derssayisi)).split("|")[3].toInt();

int moladerssaatisayisi=0;
if(listGetLine(ayarlist,"moladerssaati")!="")
 moladerssaatisayisi=listGetLine(ayarlist,"moladerssaati").split("|")[2].toInt();

int molaBaslamaSaati=0;
if(listGetLine(saatlist,QString::number(dt.dayOfWeek())+"s"+QString::number(moladerssaatisayisi))!="")
molaBaslamaSaati=listGetLine(saatlist,QString::number(dt.dayOfWeek())+"s"+QString::number(moladerssaatisayisi)).split("|")[3].toInt();

int molaBitisSaati=0;
if(listGetLine(saatlist,QString::number(dt.dayOfWeek())+"s"+QString::number(moladerssaatisayisi+1))!="")
molaBitisSaati=listGetLine(saatlist,QString::number(dt.dayOfWeek())+"s"+QString::number(moladerssaatisayisi+1)).split("|")[1].toInt();

/*
qDebug()<<"derssayisi"<<derssayisi;
qDebug()<<"torenBaslama"<<torenBaslama;
qDebug()<<"ilkOgrenciGiris"<<ilkOgrenciGiris;
qDebug()<<"molabaslamasaati"<<molabaslamasaati<<"molabaslamasaati"<<molabitissaati;
qDebug()<<"sonDersCikis"<<sonDersCikis;
*/
//qDebug()<<"saatlist sayısı:"<<saatlist.count();
    for(int i=0;i<saatlist.count();i++)
    {
        //qDebug()<<"zam"<<saatlist[i]<<currentsaniye<<cikisSaati<<molaBaslamaSaati<<molaBitisSaati;

        if(saatlist[i].split("|").count()>2)
        {
           // qDebug()<<i<<saatlist[i].split("|")[1]<<saatlist[i].split("|")[2]<<saatlist[i].split("|")[3];
            ogrenciGirisSaati=saatlist[i].split("|")[1].toInt();
            dersBaslamaSaati=saatlist[i].split("|")[2].toInt();
            cikisSaati=saatlist[i].split("|")[3].toInt();
          //  sorakiCikisSaati=saatlist[i+1].split("|")[3].toInt();
           // qDebug()<<"zam"<<saatlist[i]<<currentsaniye<<cikisSaati<<molaBaslamaSaati<<molaBitisSaati;

            if(currentsaniye<torenBaslamaSaati)
            {
                //qDebug()<<"sabah"<<saatlist[i]<<currentsaniye;
                widget->zamanGostergesiDurum->setText("S");break;
            }
            else if(currentsaniye>torenBaslamaSaati&&currentsaniye<ilkOgrenciGirisSaati)
            {
               // qDebug()<<"tören"<<tb<<saatlist[i]<<currentsaniye;

                if(torenMuzikPlayStatus==false){resetStatus();
                   if(torenBaslamaSaati+60>currentsaniye) torenMuzik();
                    torenMuzikPlayStatus=true;}
                widget->zamanGostergesiDurum->setText("TRN");break;
            }
            else if(currentsaniye>=ogrenciGirisSaati&&currentsaniye<dersBaslamaSaati){
               // qDebug()<<"T>>D"<<saatlist[i]<<currentsaniye;
                 if(ogrenciMuzikPlayStatus==false){resetStatus();
                     if(ogrenciGirisSaati+60>currentsaniye) ogrenciMuzik();
                     ogrenciMuzikPlayStatus=true;}
                 widget->zamanGostergesiDurum->setText("TND");break;
            }
            else if(currentsaniye>=dersBaslamaSaati&&currentsaniye<cikisSaati){
                //qDebug()<<"D"<<saatlist[i]<<currentsaniye;
                if(ogretmenMuzikPlayStatus==false){resetStatus();
                    if(dersBaslamaSaati+60>currentsaniye) ogretmenMuzik();
                    ogretmenMuzikPlayStatus=true;}
                widget->zamanGostergesiDurum->setText("D");break;
            }
            else if(currentsaniye>=cikisSaati&&(currentsaniye>molaBaslamaSaati&&currentsaniye<molaBitisSaati))
            {
                //qDebug()<<"Mola"<<saatlist[i]<<currentsaniye;
               if(cikisMuzikPlayStatus==false){
                    resetStatus();
                     if(cikisSaati+60>currentsaniye) cikisMuzik();
                    cikisMuzikPlayStatus=true;
                    yayinMolaMuzik();
                    molaMuzikYayinPlayStatus=true;
                }
                widget->zamanGostergesiDurum->setText("ML");break;
            }
            else if(currentsaniye>=cikisSaati&&!(currentsaniye>molaBaslamaSaati&&currentsaniye<molaBitisSaati)&&currentsaniye>=sonDersCikisSaati)
            {
               // qDebug()<<"Akşam"<<saatlist[i]<<cikisSaati<<currentsaniye;
                widget->zamanGostergesiDurum->setText("A");
                if(cikisMuzikPlayStatus==false){ resetStatus();cikisMuzikPlayStatus=true;
                  if(cikisSaati+60>currentsaniye)  cikisMuzik();
                }
               break;
            }
            else if(currentsaniye>=cikisSaati&&!(currentsaniye>molaBaslamaSaati&&currentsaniye<molaBitisSaati))
            {
                if(i<saatlist.count()-1&&saatlist[i+1].split("|").count()>2)
                {
                    if(currentsaniye<saatlist[i+1].split("|")[1].toInt())
                    {
                       // qDebug()<<"TNF"<<saatlist[i]<<currentsaniye;

                        if(cikisMuzikPlayStatus==false){
                            resetStatus();
                            cikisMuzikPlayStatus=true;
                            if(cikisSaati+60>currentsaniye) cikisMuzik();
                            yayinTenefusMuzik();
                            tenefusMuzikYayinPlayStatus=true;
                        }
                        widget->zamanGostergesiDurum->setText("TNF");break;
                    }
                }
            }



        }

    }
/**************************************************************************************/

int currentsaatsaniye=QTime::currentTime().hour()*60*60+QTime::currentTime().minute()*60;
    QString lineayar=listGetLine(ayarlist,QString::number(currentsaatsaniye));
    if(lineayar!="")
   {
 qDebug()<<"ayar..:"<<lineayar;
      if(lineayar.split("|")[1]=="muzikbaslama"&&
              listGetLine(ayarlist,"oglenMuzikYayinState")=="ayar|oglenMuzikYayinState|1"&&
               molaMuzikYayinState==false)
        {
          widget->zamanGostergesiDurum->setText("M");
            qDebug()<<"15sn sonra Mola Müzik Yayını Başlayacak..";
            timer1.start(15000);
            loop.exec();

            if (listGetLine(ayarlist,"muzikklasor")!="")
            {
                player->setMedia(playlist);
                player->play();
                molaMuzikYayinState=true;

            }

      }



        if(lineayar.split("|")[1]=="muzikson"&&
                listGetLine(ayarlist,"oglenMuzikYayinState")=="ayar|oglenMuzikYayinState|1"&&
                 molaMuzikYayinState)
        { player->stop();

             molaMuzikYayinState=false;
        }

        if(lineayar.split("|")[1]=="derssonupckapat")
        {
          //  qDebug()<<"derssonupckapat";
             QString kmt=QString(listGetLine(ayarlist,"kapatKomut").split("|")[2]);
                    system(kmt.toStdString().c_str());
        }
        if(lineayar.split("|")[1]=="molapckapat")
        {
           // qDebug()<<"molapckapat";
            QString kmt=QString(listGetLine(ayarlist,"kapatKomut").split("|")[2]);
                   system(kmt.toStdString().c_str());
        }
   }
/***********************************************************/
    // const QDate dt = QDate::QDate::toString();
    // qDebug()<<"tarih:"<<QDate::currentDate().toString("dd.MM.yyyy");
    if(listGetLine(ayarlist,"gunState")=="ayar|gunState|1")
    {
         gunlist=fileToList("gunlist");
       // QString tarih=QDate::currentDate();//.toString("dd/MM/yyyy");
       // QDate date = QDate::fromString(tarih, "dd/MM/yyyy");
         QDate date = QDate::currentDate();
         int haftaSayisi=date.weekNumber();

        if(listGetLine(gunlist,"hafta"+QString::number(haftaSayisi))!="")
        {

            QString gun=QString(listGetLine(gunlist,"hafta"+QString::number(haftaSayisi)).split("|")[1]);
            // qDebug()<<"gun:"<<gun;
            widget->baslik->setText("H: "+gun);
        }else
        {
            widget->baslik->setText(" Sessiz Zil Sistemi");
        }
    }
/***********************************************************/
}
MainWindow::~MainWindow()
{
  //  delete ui;
}
void MainWindow::torenMuzik()
{
//qDebug()<<"Tören müzik...";
    if(listGetLine(ayarlist,"torenzil")!="")
    {
       // widget->zamanGostergesiDurum->setText("TR");
        QString deger=listGetLine(ayarlist,"torenzilseviye").split("|")[2];
        player->setVolume(deger.toInt());
        playStateToren=true;
        QString filepath=listGetLine(ayarlist,"torenzil").split("|")[2];
        QFile* file = new QFile(QDir::homePath()+"/"+filepath);
        if (file->open(QFile::ReadOnly)) {
            player->setMedia(QMediaContent(), file);
            file->seek(0);
            player->play();
            tempCurrentsaat=currentsaat;
            qDebug()<<"Tören Zili Çalıyor....."<<QDateTime::currentDateTime();
        }
    }
}
void MainWindow::ogrenciMuzik()
{
    //qDebug()<<"ogrenci müzik...";
    if(listGetLine(ayarlist,"ogrencizil")!="")
    {
        if(tenefusYayin) {
            //qDebug()<<"ogrenci süresi:"<< player->duration();
            player->stop();
            qDebug()<<"Tenefüs Müzik Yayını Durdu.."<<QDateTime::currentDateTime();
            tenefusYayin=false;
            qDebug()<<"10sn sonra Öğrenci Zili Çalacak.."<<QDateTime::currentDateTime();
            timer1.start(10000);
            loop.exec();
        }
        widget->zamanGostergesiDurum->setText("TND");
        QString deger=listGetLine(ayarlist,"ogrencizilseviye").split("|")[2];
        player->setVolume(deger.toInt());
        QString filepath=listGetLine(ayarlist,"ogrencizil").split("|")[2];
        QFile* file = new QFile(QDir::homePath()+"/"+filepath);
        if (file->open(QFile::ReadOnly)) {
            player->setMedia(QMediaContent(), file);
            file->seek(0);
            player->play();
            tempCurrentsaat=currentsaat;
            qDebug()<<"Öğrenci Zili Çalıyor....."<<QDateTime::currentDateTime();
        }
    }
}
void MainWindow::ogretmenMuzik()
{
    if(listGetLine(ayarlist,"ekilitState")!="")
        ekilitState=listGetLine(ayarlist,"ekilitState").split("|")[2].toInt();
    if(ekilitState)
    {
        system("nohup pkill e-kilit&");
    }

           // qDebug()<<"ogretmen müzik...";
    if(listGetLine(ayarlist,"ogretmenzil")!="")
    {
        widget->zamanGostergesiDurum->setText("D");
        QString deger=listGetLine(ayarlist,"ogretmenzilseviye").split("|")[2];
        player->setVolume(deger.toInt());

        QString filepath=listGetLine(ayarlist,"ogretmenzil").split("|")[2];
        QFile* file = new QFile(QDir::homePath()+"/"+filepath);

        if (file->open(QFile::ReadOnly)) {
            player->setMedia(QMediaContent(), file);
            file->seek(0);
            player->play();
            tempCurrentsaat=currentsaat;
            qDebug()<<"Öğretmen Zili Çalıyor....."<<QDateTime::currentDateTime();
        }
    }
}
void MainWindow::cikisMuzik()
{
    if(listGetLine(ayarlist,"ekilitState")!="")
        ekilitState=listGetLine(ayarlist,"ekilitState").split("|")[2].toInt();
    if(ekilitState)
    {
       system("nohup /usr/bin/e-kilit&");
    }

    // qDebug()<<"çıkış müzik...";
    if(listGetLine(ayarlist,"cikiszil")!="")
    {

        widget->zamanGostergesiDurum->setText("TN");
        QString deger=listGetLine(ayarlist,"cikiszilseviye").split("|")[2];
        player->setVolume(deger.toInt());

        QString filepath=listGetLine(ayarlist,"cikiszil").split("|")[2];
        QFile* file = new QFile(QDir::homePath()+"/"+filepath);
        if (file->open(QFile::ReadOnly)) {
            player->setMedia(QMediaContent(), file);
            file->seek(0);
            player->play();
            tempCurrentsaat=currentsaat;
            qDebug()<<"Çıkış Zili Çalıyor....."<<QDateTime::currentDateTime();
        }

    }
}
void MainWindow::yayinTenefusMuzik()
{
     //qDebug()<<"yayin müzik...";
    if(listGetLine(ayarlist,"tenefusMuzikYayinState")=="ayar|tenefusMuzikYayinState|1")// &&line.split("|")[0].right(1)!=QString::number(ogleArasi))
    {
        qDebug()<<"15sn sonra Tenefüs Müzik Yayını Başlayacak.."<<QDateTime::currentDateTime();
        timer1.start(20000);
        loop.exec();
        QString deger=listGetLine(ayarlist,"muzikyayinseviye").split("|")[2];
        player->setVolume(deger.toInt());

        if (listGetLine(ayarlist,"muzikklasor")!="")
        {
            player->setMedia(playlist);
            player->play();
            tenefusYayin=true;
            qDebug()<<"Tenefüs Müzik Yayını Başladı.."<<QDateTime::currentDateTime();

        }


    }
}
void MainWindow::yayinMolaMuzik()
{
     //qDebug()<<"yayin müzik...";
    if(listGetLine(ayarlist,"oglenMuzikYayinState")=="ayar|oglenMuzikYayinState|1")// &&line.split("|")[0].right(1)!=QString::number(ogleArasi))
    {
        qDebug()<<"15sn sonra Mola Müzik Yayını Başlayacak.."<<QDateTime::currentDateTime();
        timer1.start(20000);
        loop.exec();
        QString deger=listGetLine(ayarlist,"muzikyayinseviye").split("|")[2];
        player->setVolume(deger.toInt());

        if (listGetLine(ayarlist,"muzikklasor")!="")
        {
            player->setMedia(playlist);
            player->play();
            tenefusYayin=true;
            qDebug()<<"Mola Müzik Yayını Başladı.."<<QDateTime::currentDateTime();

        }


    }
}
QTime MainWindow::saniyeToSaat(QString _zaman)
{
     QTime zm(0,0,0);
      zm=zm.addSecs(_zaman.toInt());
      return zm;
}
QString MainWindow::saatToSaniye(QTime _zaman)
{
   int zmm=_zaman.hour()*60*60+_zaman.minute()*60+_zaman.second();
   return QString::number(zmm);
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
     for(int i=0;i<list.count();i++)if(list[i].contains(data)) list.removeAt(i);
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
QStringList MainWindow::fileToList(QString filename)
 {
    FileCrud *fcc=new FileCrud();
    fcc->dosya=localDir+filename;
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
void MainWindow::listToFile(QStringList list, QString filename)
 {
  //  qDebug()<<" listtofile";
    FileCrud *fcc=new FileCrud();
    fcc->dosya=localDir+filename;
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
/********************file permission*************************/
   QFile file(localDir+filename);
    if (file.open(QFile::ReadWrite)){
            if(!file.setPermissions(QFileDevice::WriteUser | QFileDevice::ReadUser|QFileDevice::ExeUser|
                                    QFileDevice::WriteOwner | QFileDevice::ReadOwner|QFileDevice::ExeOwner|
                                    QFileDevice::WriteGroup | QFileDevice::ReadGroup|QFileDevice::ExeGroup|
                                    QFileDevice::WriteOther | QFileDevice::ReadOther|QFileDevice::ExeOther)){
                qDebug()<< "Error in permissions";
             }
            file.close();
    }
/***********************************************/
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
void  MainWindow::SZSgizle()
{
    widget->close();

    qDebug()<<"widget gizle..";

    SZSState=false;
    QStringList listconf=fileToList("e-zil.conf");
    listconf=listRemove(listconf,"ayar|SZSState|");
    listconf.append("ayar|SZSState|"+QString::number(SZSState));
    listToFile(listconf,"e-zil.conf");

}
void  MainWindow::SZSgoster()
{
widget->show();
qDebug()<<"widget göster..";
SZSState=true;
 QStringList listconf=fileToList("e-zil.conf");
 listconf=listRemove(listconf,"ayar|SZSState|");
listconf.append("ayar|SZSState|"+QString::number(SZSState));
listToFile(listconf,"e-zil.conf");

}
void  MainWindow::about()
{
    QSize screenSize = qApp->screens()[0]->size();
   // qDebug()<<screenSize.width()/65<<screenSize.height()/35;

    QWidget *hk=hakkinda();

    hk->show();
    hk->move(screenSize.width()/2-hk->width()/2,screenSize.height()/2-hk->height()/2);
     hk->setWindowTitle("Hakkında");
     auto appIcon = QIcon(":/icons/bell.svg");
     hk->setWindowIcon(appIcon);
}
void  MainWindow::widgetShow()
{
    init();
    qDebug()<<"ekranı göster";
    QFont ff( "Arial", 7.5, QFont::Normal);
    tw->setFont(ff);
  tw->clear();
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
    this->showNormal();

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

    auto minimizeActionSZS = new QAction(tr("Sessiz ZS Gi&zle"), this);
     connect(minimizeActionSZS, SIGNAL(triggered()), this, SLOT(SZSgizle()));
     auto  restoreActionSZS = new QAction(tr("Sessiz ZS Gös&ter"), this);
      connect( restoreActionSZS, SIGNAL(triggered()), this, SLOT(SZSgoster()));

      auto  aboutAction = new QAction(tr("Hakkında"), this);
       connect( aboutAction, SIGNAL(triggered()), this, SLOT(about()));

   /* auto maximizeAction = new QAction(tr("Ma&ximize"), this);
    connect(maximizeAction, &QAction::triggered, this, &QWidget::showMaximized);
*/
    auto restoreAction = new QAction(tr("&Ayarlar"), this);
  //  connect(restoreAction, &QAction::triggered, this, &QWidget::showNormal);
     connect( restoreAction, SIGNAL(triggered()), this, SLOT(widgetShow()));

    auto quitAction = new QAction(tr("&Kapat"), this);
    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
    auto menu = new QMenu(this);
    //menu->addAction(quitAction)


    menu->addAction(minimizeAction);
    //menu->addAction(maximizeAction);
    menu->addAction(restoreAction);
    menu->addSeparator();
    menu->addAction(minimizeActionSZS);
    menu->addAction(restoreActionSZS);

    menu->addSeparator();
    menu->addAction(aboutAction);

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
   // this->trayIcon->showMessage("E-Zil", "Okul Zil Sistemi!");
      widgetShow();
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
void MainWindow::onemliGunSlot()
{
   // qDebug()<<"ayar click";
    QString font="12";
    QDialog * d = new QDialog();
    d->setStyleSheet("font-size:"+QString::number(font.toInt()-2)+"px;");
    auto appIcon = QIcon(":/icons/bell.svg");
    d->setWindowIcon(appIcon);
    d->setWindowTitle("Önemli Gün Listesi");
    d->setFixedSize(en*25,en*30);

    QLineEdit * gun = new QLineEdit();
    gun->setFixedSize(en*20,boy*2);

    QLineEdit * tarih = new QLineEdit();
    tarih->setFixedSize(en*20,boy*2);

    QLabel *gunLabel=new QLabel("Önemli Gün");
    QLabel *tarihLabel=new QLabel("Tarih (Her hafta için bir önemli gün giriniz,Örn: 17/10/2022)");
    QToolButton *gunEkleButton= new QToolButton;
    gunEkleButton->setFixedSize(QSize(en*20,boy*2));
    gunEkleButton->setIconSize(QSize(en*20,boy));
    gunEkleButton->setStyleSheet("Text-align:center");
    //gunEkleButton->setAutoRaise(true);
    gunEkleButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
     gunEkleButton->setText("Gün Ekle");

    connect(gunEkleButton, &QPushButton::clicked, [=]() {
        QStringList gunlist=fileToList("gunlist");
         QDate date = QDate::fromString(tarih->text(), "dd/MM/yyyy");
          int haftaSayisi=date.weekNumber();
       // qDebug()<<"hatfa :"<<haftaSayisi<<date.year()<<date.month()<<date.day();
            gunlist<<tarih->text()+"|"+gun->text()+"|hafta"+QString::number(haftaSayisi);

        listToFile(gunlist,"gunlist");
        for(int i=0;i<gunlist.count();i++)
        {
            QString line=gunlist[i];
            QStringList lst=line.split("|");
            twl->setRowCount(i+1);
            twl->setItem(i, 0, new QTableWidgetItem(lst[0]));//tarih
            twl->setItem(i, 1, new QTableWidgetItem(lst[1]));//gün

        }

});

    /***********************************************************************/
   twl=new QTableWidget;
    twl->setFixedSize(QSize(en*20,en*20));
    twl->setColumnCount(2);
    //twl->setRowCount(0);
    twl->setColumnWidth(0, en*7);
    twl->setColumnWidth(1, en*12);

    twl->setHorizontalHeaderItem(0, new QTableWidgetItem("Tarih"));
    twl->setHorizontalHeaderItem(1, new QTableWidgetItem("Gün"));

    twl->setSelectionBehavior(QAbstractItemView::SelectRows);
    twl->setSelectionMode(QAbstractItemView::SingleSelection);
    //connect(tw, &QTableWidget::cellClicked, this, cellClicked());
    connect(twl, SIGNAL(cellDoubleClicked(int,int)),SLOT(webTableCellDoubleClicked(int,int)));
    twl->setRowCount(0);
    QStringList list=fileToList("gunlist");
    for(int i=0;i<list.count();i++)
    {
        QString line=list[i];
        QStringList lst=line.split("|");
        twl->setRowCount(twl->rowCount()+1);
        twl->setItem(i, 0, new QTableWidgetItem(lst[0]));//tarih
        twl->setItem(i, 1, new QTableWidgetItem(lst[1]));//gun

    }


    QVBoxLayout * vbox = new QVBoxLayout();
    QHBoxLayout * hbox1= new QHBoxLayout();
    QHBoxLayout * hbox2= new QHBoxLayout();
    QHBoxLayout * hbox3= new QHBoxLayout();
    QHBoxLayout * hbox4= new QHBoxLayout();
    QHBoxLayout * hbox5= new QHBoxLayout();
    QHBoxLayout * hbox6= new QHBoxLayout();

    hbox1->addWidget(tarihLabel);

    hbox2->addWidget(tarih);
    hbox3->addWidget(gunLabel);

    hbox4->addWidget(gun);


    hbox5->addWidget(gunEkleButton);

    hbox6->addWidget(twl);

   vbox->addLayout(hbox1);
    vbox->addLayout(hbox2);
    vbox->addLayout(hbox3);
    vbox->addLayout(hbox4);
    vbox->addLayout(hbox5);
    vbox->addLayout(hbox6);

    d->setLayout(vbox);

    int result = d->exec();

}

void MainWindow::webTableCellDoubleClicked(int iRow, int iColumn)
{
     QString webadres= twl->item(iRow, 0)->text();
     QStringList list=fileToList("gunlist");
/******************************************************************/
    //QMessageBox::StandardButton reply;
    // reply = QMessageBox::question(this, "Uyarı", "Bilgisayar Silinecek! Emin misiniz?",
      //                             QMessageBox::Yes|tr(QMessageBox::No);
     QMessageBox messageBox(this);
     messageBox.setText("Uyarı");
     messageBox.setInformativeText("Gun İçin İşlem Seçiniz!");
     QAbstractButton *evetButton =messageBox.addButton(tr("Sil"), QMessageBox::ActionRole);
     QAbstractButton *hayirButton =messageBox.addButton(tr("Düzenle"), QMessageBox::ActionRole);
     messageBox.setIcon(QMessageBox::Question);
             messageBox.exec();
             if (messageBox.clickedButton() == evetButton) {
                 // qDebug()<<"evet basıldı";
                 list=listRemove(list,webadres);
                 listToFile(list,"gunlist");
                 if(list.count()==0) twl->setRowCount(0);
                 for(int i=0;i<list.count();i++)
                 {
                     QString line=list[i];
                     QStringList lst=line.split("|");
                     twl->setRowCount(i+1);
                     twl->setItem(i, 0, new QTableWidgetItem(lst[0]));//ip
                 }
             }
             if (messageBox.clickedButton() == hayirButton) {
                 //qDebug()<<"hayır basıldı";
             }


}
