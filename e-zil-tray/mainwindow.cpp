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
#include<QTimeEdit>
#include<QDate>
#include<QTimer>
#include<QTime>
#include<QMessageBox>
#include<QApplication>
#include<QDesktopWidget>
#include<QMenu>
#include<QCloseEvent>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
 {
#ifdef Q_OS_LINUX
   // qDebug()<< "Linux version";
    localDir="/usr/share/e-zil/";
#endif

#ifdef Q_OS_WIN
   // qDebug()<< "Windows version";
      localDir = QCoreApplication::applicationDirPath() + "/";
#endif
      clientConfWather.addPath(localDir+"e-zil.json");
      connect(&clientConfWather, &QFileSystemWatcher::fileChanged, this,
              [this](){
                  init();   // burada tekrar addPath() çağırılacak
              });


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
      auto appIcon = QIcon(":/icons/e-zil.svg");
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
          //yayinTenefusMuzik();
}
void MainWindow::init()
{
   qDebug()<<"init...";
    const QDate dt = QDate::currentDate();
    gun=QString::number(dt.dayOfWeek())+"s";

    DatabaseHelper *db=new DatabaseHelper(localDir+"e-zil.json");
    QJsonArray settings = db->Ara("recordtype", "settings");
    if (!settings.isEmpty()) {
        ayarlar = settings.first().toObject();
    }
    //DatabaseHelper *db=new DatabaseHelper(localDir+"e-zil.json");
     liste = db->Ara("gun", gun);
    /******************Player ve Playlist ayarları yapılıyor***********/

    QDir klasorpath;
     if (ayarlar.contains("muzikklasor"))
         klasorpath=ayarlar["muzikklasor"].toString();

    playlist = new QMediaPlaylist;
    klasorpath.setNameFilters({"*.wav" , "*.mp3"});
    //qDebug()<<"klasorpath:"<<klasorpath;
    for(const QFileInfo & finfo: klasorpath.entryInfoList()){

        playlist->addMedia(QUrl::fromLocalFile(finfo.absoluteFilePath()));
        muziklist.append(QUrl::fromLocalFile(finfo.absoluteFilePath()).toString().remove(0,7)).append(" ");

        //qDebug()<<"ilk liste"<<QUrl::fromLocalFile(finfo.absoluteFilePath()).toString();
    }


    if (ayarlar.contains("SZSState"))
        SZSState=ayarlar["SZSState"].toBool();
    /*****************************************************/

    if(SZSState==true&&SZSShowState==false) {
        SZSShowState=true;
        qDebug()<<"widget showing..";
       widget->show();
    }

    if(SZSState==false&&SZSShowState){
        qDebug()<<"widget kapatma";
      widget->hide();
        SZSShowState=false;
    }
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
    currentsaat=QTime::currentTime().toString("hh:mm");
    currentsaniye=QTime::currentTime().hour()*60*60+QTime::currentTime().minute()*60+QTime::currentTime().second();

    //qDebug()<<">>"<<gun<<currentsaat<<currentsaniye;
    ///qDebug()<<"ayar"<<ayarlar;
    int molaBaslamaSaati=0;
    int molaBitisSaati=0;
    int torenBaslamaSaati=0;
    int ilkOgrenciGirisSaati=0;
    int sonDersCikisSaati=0;
    int derssayisi=0;
    int oglearasiderssayisi=0;
    int molasuresi=0;
    int muzikbaslama=0;
    int muzikson=0;
    int derssonupckapat=0;
    int molapckapat=0;
    if (ayarlar.contains("derssayisi"))
        derssayisi=ayarlar["derssayisi"].toString().toInt();
    if (ayarlar.contains("moladerssaati"))
        oglearasiderssayisi=ayarlar["moladerssaati"].toString().toInt();
    if (ayarlar.contains("molasuresi"))
        molasuresi=ayarlar["molasuresi"].toString().toInt();
    if (ayarlar.contains("muzikson"))
        muzikson=ayarlar["muzikson"].toString().toInt();
    if (ayarlar.contains("muzikbaslama"))
        muzikbaslama=ayarlar["muzikbaslama"].toString().toInt();
    if (ayarlar.contains("derssonupckapat"))
        derssonupckapat=ayarlar["derssonupckapat"].toString().toInt();
    if (ayarlar.contains("molapckapat"))
        molapckapat=ayarlar["molapckapat"].toString().toInt();

    /**************************************************************/

    bool bulundu = false;
    int tolerans = 2;   // 10 saniye
    QString zilturu="";
    int zildersno=0;
    int zilzamani=0;
    if(liste.count()>0)
    {

        for (const QJsonValue &item : liste) {
            QJsonObject veri = item.toObject();
            // tören saati
            if(veri["ders"].toInt()==1)
                torenBaslamaSaati=veri["toren"].toString().toInt();
            // mola başlama
            if(veri["ders"].toInt()==oglearasiderssayisi)
                molaBaslamaSaati=veri["cikis"].toString().toInt();
            // ilk öğreci giriş saati
            if(veri["ders"].toInt()==1)
                ilkOgrenciGirisSaati=veri["giris"].toString().toInt();
            // ders bitiş saati
            if(veri["ders"].toInt()==derssayisi)
                sonDersCikisSaati=veri["cikis"].toString().toInt();
            // mola bitiş saati
            if(veri["giris"].toString()==veri["baslangic"].toString())
                molaBitisSaati=molasuresi+molaBaslamaSaati;
            else
            {
                int gbfark=veri["baslangic"].toString().toInt()-veri["giris"].toString().toInt();
                molaBitisSaati=molasuresi+molaBaslamaSaati-gbfark;
            }

            // Kontrol edilecek alanlar
            QStringList alanlar = {"baslangic", "giris", "cikis", "toren"};

            for (const QString &alan : alanlar) {

                if (!veri.contains(alan)) continue;

                int deger = veri.value(alan).toString().toInt();

                // Toleranslı karşılaştırma
                if (qAbs(currentsaniye - deger) <= tolerans) {
                    /*qDebug()
                    << "EŞLEŞME BULUNDU => Ders:"
                    << veri.value("ders").toInt()
                    << " Alan:" << alan
                    << " AlanDeğeri:" << deger
                    << " Current:" << currentsaniye;*/
                    zilturu=alan;
                    zildersno=veri.value("ders").toInt();
                    zilzamani=deger;
                    bulundu = true;
                }
            }
           /// if(bulundu) break;
        }
    }
    if(bulundu){
        qDebug()
            << "zil:"
            <<zildersno
            <<zilturu
            <<zilzamani;
        if(zilturu=="giris"){
            if(ogrenciMuzikPlayStatus==false){
                resetStatus();
                //if(zilzamani+60>currentsaniye)
                ogrenciMuzik();
                ogrenciMuzikPlayStatus=true;
            }
            widget->zamanGostergesiDurum->setText("TND");
        }
        if(zilturu=="baslangic"){
            if(ogretmenMuzikPlayStatus==false){
                resetStatus();
                ///if(zilzamani+60>currentsaniye)
                ogretmenMuzik();
                ogretmenMuzikPlayStatus=true;
            }
                widget->zamanGostergesiDurum->setText("D");
        }
        if(zilturu=="cikis"){
            if(cikisMuzikPlayStatus==false){
                resetStatus();
                cikisMuzikPlayStatus=true;
                //if(zilzamani+60>currentsaniye)
                cikisMuzik();
                if(zildersno!=oglearasiderssayisi&&zildersno!=derssayisi)
                {
                    yayinTenefusMuzik();
                    tenefusMuzikYayinPlayStatus=true;
                }
            }
            widget->zamanGostergesiDurum->setText("TNF");
        }
    }

    if (qAbs(currentsaniye - molaBaslamaSaati) <= tolerans) {
        qDebug()<<"öğle arası başladı"<<molaBaslamaSaati;
        if(cikisMuzikPlayStatus==false){
            resetStatus();
            //if(molaBaslamaSaati+60>currentsaniye)
            cikisMuzik();
            cikisMuzikPlayStatus=true;
            yayinMolaMuzik();
            molaMuzikYayinPlayStatus=true;
        }
        widget->zamanGostergesiDurum->setText("ML");
    }
    if (qAbs(currentsaniye - molaBitisSaati) <= tolerans) {
        qDebug()<<"öğle arası bitti"<<molaBitisSaati;
    }
    if(currentsaniye<torenBaslamaSaati)
    {
        //qDebug()<<"sabah"<<saatlist[i]<<currentsaniye;
        widget->zamanGostergesiDurum->setText("S");
    }

    if (qAbs(currentsaniye - torenBaslamaSaati) <= tolerans) {

        if(torenMuzikPlayStatus==false){
            qDebug()<<"tören başladı";
            resetStatus();
            //if(torenBaslamaSaati+60>currentsaniye)
            torenMuzik();
            torenMuzikPlayStatus=true;
            widget->zamanGostergesiDurum->setText("TRN");
        }

    }
    if (qAbs(currentsaniye - ilkOgrenciGirisSaati) <= tolerans) {
        qDebug()<<"ilk öğrenci girişi";
    }
    if (currentsaniye >(sonDersCikisSaati+tolerans)) {

            ///qDebug()<<"ders bitti";
            widget->zamanGostergesiDurum->setText("A");
             /*if(cikisMuzikPlayStatus==false){
                resetStatus();
            cikisMuzikPlayStatus=true;
            /*if(qAbs(currentsaniye -sonDersCikisSaati+10)<=tolerans)
                cikisMuzik();*/

       // }
    }

    if (qAbs(currentsaniye - muzikbaslama) <= tolerans) {

        if(molaMuzikYayinState==false)
        {
            qDebug()<<"mola muzikbaslama";
            widget->zamanGostergesiDurum->setText("M");
            qDebug()<<"15sn sonra Mola Müzik Yayını Başlayacak..";
            timer1.start(15000);
            loop.exec();
            QString muzikklasor;
            if (ayarlar.contains("muzikklasor"))
                muzikklasor=ayarlar["muzikklasor"].toString().toInt();
            if (muzikklasor!="")
            {
                player->setMedia(playlist);
                player->play();
                molaMuzikYayinState=true;
            }
        }
    }

    if (qAbs(currentsaniye - muzikson) <= tolerans) {
        qDebug()<<"mola muzikson bitti";
           if(molaMuzikYayinState)
            {
                player->stop();
                molaMuzikYayinState=false;
            }
    }

    if (qAbs(currentsaniye - derssonupckapat) <= tolerans) {
        qDebug()<<"kapatKomut";
        QString kmt="";
        if (ayarlar.contains("kapatKomut"))
            kmt=ayarlar["molapckapat"].toString().toInt();
        system(kmt.toStdString().c_str());
    }

    if (qAbs(currentsaniye - molapckapat) <= tolerans) {
        qDebug()<<"molapckapati";
        QString kmt="";
        if (ayarlar.contains("kapatKomut"))
            kmt=ayarlar["molapckapat"].toString().toInt();
        system(kmt.toStdString().c_str());
    }

    bool gunState;
    if (ayarlar.contains("gunState"))
        gunState=ayarlar["gunState"].toBool();
    if(gunState)
    {
        QDate date = QDate::currentDate();
        int haftaSayisi=date.weekNumber();
        //qDebug()<<"günlerr"<<haftaSayisi;

        DatabaseHelper *db=new DatabaseHelper(localDir+"onemligun.json");
        //db->Sil("tarih", tarih);
        QJsonArray liste = db->Oku();
        for (const QJsonValue &val : liste)
        {
            if (!val.isObject()) continue;
            QJsonObject obj = val.toObject();
            QString tarih = obj["tarih"].toString();
            QString gun=obj["gun"].toString();
            QString haftasy=obj["haftasayisi"].toString();
            if(haftaSayisi==haftasy.toInt())
            {
                // qDebug()<<"gun:"<<gun;
                widget->baslik->setText("H: "+gun);
                break;
            }else
            {
                widget->baslik->setText(" Sessiz Zil Sistemi");
            }
        }
    }
}
MainWindow::~MainWindow()
{

}
void MainWindow::torenMuzik()
{
    qDebug()<<"Tören müzik...";
    int deger=0;
    if (ayarlar.contains("torenzilseviye"))
        deger=ayarlar["torenzilseviye"].toString().toInt();
    QString filepath;
    if (ayarlar.contains("torenzil"))
        filepath=ayarlar["torenzil"].toString();

    qDebug()<<filepath;
    player->setVolume(deger);
    QFile* file = new QFile(filepath);
    if (file->open(QFile::ReadOnly)) {
        player->setMedia(QMediaContent(), file);
        file->seek(0);
        player->play();
        tempCurrentsaat=currentsaat;
        qDebug()<<"Tören Zili Çalıyor....."<<QDateTime::currentDateTime();
    }

}
void MainWindow::ogrenciMuzik()
{
    qDebug()<<"ogrenci müzik...";
    int deger=0;
    if (ayarlar.contains("ogrencizilseviye"))
        deger=ayarlar["ogrencizilseviye"].toString().toInt();
    QString filepath;
    if (ayarlar.contains("ogrencizil"))
        filepath=ayarlar["ogrencizil"].toString();


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
    player->setVolume(deger);
    QFile* file = new QFile(filepath);
    if (file->open(QFile::ReadOnly)) {
        player->setMedia(QMediaContent(), file);
        file->seek(0);
        player->play();
        tempCurrentsaat=currentsaat;
        qDebug()<<"Öğrenci Zili Çalıyor....."<<QDateTime::currentDateTime();
    }

}
void MainWindow::ogretmenMuzik()
{
    qDebug()<<"ogretmen müzik...";
    int deger=0;
    if (ayarlar.contains("ogretmenzilseviye"))
        deger=ayarlar["ogretmenzilseviye"].toString().toInt();
    QString filepath;
    if (ayarlar.contains("ogretmenzil"))
        filepath=ayarlar["ogretmenzil"].toString();


    widget->zamanGostergesiDurum->setText("D");

    player->setVolume(deger);

    QFile* file = new QFile(filepath);

    if (file->open(QFile::ReadOnly)) {
        player->setMedia(QMediaContent(), file);
        file->seek(0);
        player->play();
        tempCurrentsaat=currentsaat;
        qDebug()<<"Öğretmen Zili Çalıyor....."<<QDateTime::currentDateTime();
    }
}
void MainWindow::cikisMuzik()
{
    qDebug()<<"çıkış müzik...";
    int deger=0;
    if (ayarlar.contains("cikiszilseviye"))
        deger=ayarlar["cikiszilseviye"].toString().toInt();
    QString filepath;
    if (ayarlar.contains("cikiszil"))
        filepath=ayarlar["cikiszil"].toString();

    widget->zamanGostergesiDurum->setText("TN");
    player->setVolume(deger);
    QFile* file = new QFile(filepath);
    if (file->open(QFile::ReadOnly)) {
        player->setMedia(QMediaContent(), file);
        file->seek(0);
        player->play();
        tempCurrentsaat=currentsaat;
        qDebug()<<"Çıkış Zili Çalıyor....."<<QDateTime::currentDateTime();
    }
}
void MainWindow::yayinTenefusMuzik()
{
    qDebug()<<"yayin müzik...";

    bool tenefusMuzikYayinState=false;
    if (ayarlar.contains("tenefusMuzikYayinState"))
        tenefusMuzikYayinState=ayarlar["tenefusMuzikYayinState"].toBool();

    if(tenefusMuzikYayinState)
    {
        int deger=0;
        if (ayarlar.contains("muzikyayinseviye"))
            deger=ayarlar["muzikyayinseviye"].toString().toInt();
        //qDebug()<<"15sn sonra Tenefüs Müzik Yayını Başlayacak.."<<QDateTime::currentDateTime();
        timer1.start(20000);
        loop.exec();

        player->setVolume(deger);
        QString muzikklasor;
        if (ayarlar.contains("muzikklasor"))
            muzikklasor=ayarlar["muzikklasor"].toString();

        if (muzikklasor!="")
        {
            //qDebug()<<"listeler sayısı" << playlist->mediaCount();
            /*for (int i = 0; i < playlist->mediaCount(); i++) {
                qDebug()<<"listeler" << playlist->media(i).canonicalUrl().fileName();
            }*/

            player->setMedia(playlist);
            player->play();
            tenefusYayin=true;
            qDebug()<<"Tenefüs Müzik Yayını Başladı.."<<QDateTime::currentDateTime();

        }


    }
}
void MainWindow::yayinMolaMuzik()
{
    qDebug()<<"yayin müzik...";

    bool oglenMuzikYayinState;
    if (ayarlar.contains("oglenMuzikYayinState"))
        oglenMuzikYayinState=ayarlar["oglenMuzikYayinState"].toBool();

    if(oglenMuzikYayinState)
    {
        qDebug()<<"15sn sonra Mola Müzik Yayını Başlayacak.."<<QDateTime::currentDateTime();
        timer1.start(20000);
        loop.exec();
        int deger=0;
        if (ayarlar.contains("muzikyayinseviye"))
            deger=ayarlar["muzikyayinseviye"].toString().toInt();
        player->setVolume(deger);
        QString muzikklasor;
        if (ayarlar.contains("muzikklasor"))
            muzikklasor=ayarlar["muzikklasor"].toString().toInt();

        if (muzikklasor!="")
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

void  MainWindow::gizle()
{
    //hide();
   // qDebug()<<"deded";
    QWidget::hide();
    timergizle->stop();
}


void  MainWindow::widgetShow()
{
      qDebug()<<"ekranı göster";
    QFont ff( "Arial", 7.5, QFont::Normal);
        // this->showNormal();

#ifdef Q_OS_LINUX
   // qDebug()<< "Linux version";
   //system("sh -c \"pkexec env DISPLAY=$DISPLAY XAUTHORITY=$XAUTHORITY e-zil-gui\"");
    // pkexec komutunu çalıştır
    int result = system("sh -c \"pkexec ls\"");

    // Dönüş değerini kontrol et
    if (result == 0) {
        //QMessageBox::information(nullptr, "Başarılı", "pkexec doğrulaması başarılı, uygulama root yetkisiyle çalışıyor.");
        system("sh -c \"pkexec /usr/bin/e-zil-gui\"");
    } else if (result == 126 || result == 127) {
        QMessageBox::critical(nullptr, "Hata", "pkexec doğrulaması başarısız: Yetkilendirme reddedildi veya komut bulunamadı.");
    } /*else {
        QMessageBox::critical(nullptr, "Hata", QString("pkexec bilinmeyen bir hata verdi: %1").arg(result));
    }*/
#endif

#ifdef Q_OS_WIN
   // qDebug()<< "Windows version";
      //localDir="";
     // system("e-zil-gui");
      const QString pathToApp = "e-zil-gui";
      QProcess::startDetached(pathToApp);
#endif


 }
QMenu* MainWindow::createMenu()
{
  // App can exit via Quit menu
 /* auto quitAction = new QAction("&Kapat", this);
  connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
  auto ayarAction = new QAction("&Ayarlar", this);
  connect(ayarAction, &QAction::triggered, qApp, gizle());
*/
   /* auto minimizeAction = new QAction(tr("Gi&zle"), this);
    connect(minimizeAction, &QAction::triggered, this, &QWidget::hide);

    auto minimizeActionSZS = new QAction(tr("Sessiz ZS Gi&zle"), this);
     connect(minimizeActionSZS, SIGNAL(triggered()), this, SLOT(SZSgizle()));
     auto  restoreActionSZS = new QAction(tr("Sessiz ZS Gös&ter"), this);
      connect( restoreActionSZS, SIGNAL(triggered()), this, SLOT(SZSgoster()));
*/
    /*  auto  aboutAction = new QAction(tr("Hakkında"), this);
       connect( aboutAction, SIGNAL(triggered()), this, SLOT(about()));
*/
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


   // menu->addAction(minimizeAction);
    //menu->addAction(maximizeAction);
    menu->addAction(restoreAction);
    menu->addSeparator();
   // menu->addAction(minimizeActionSZS);
    //menu->addAction(restoreActionSZS);

    menu->addSeparator();
   // menu->addAction(aboutAction);

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
