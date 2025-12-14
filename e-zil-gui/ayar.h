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
#ifndef AYAR_H
#define AYAR_H
#include<QToolButton>
#include<QCheckBox>
#include<QMessageBox>
//#include "miniaudio.h"

bool MainWindow::dosyaVarmi(QString dosya)
{
    QString path = localDir+dosya;
    if (!QFile::exists(path)) {

        QMessageBox msgError;
        msgError.setText("Ayarları Kaydetmeden İşlem Yapamazsınız..!");
        msgError.setIcon(QMessageBox::Critical);
        msgError.setWindowTitle("Uyarı!");
        msgError.exec();
        return false;
    }
    else return true;
}

QWidget *MainWindow::ayar()
{
    DatabaseHelper *db=new DatabaseHelper(localDir+"e-zil.json");
    QJsonArray liste = db->Ara("recordtype", "settings");
    QJsonObject obj;

    if (!liste.isEmpty()) {
        obj = liste.first().toObject();
    }
   // qDebug()<<"ayar"<<obj;
 //   init();
//burada ayarlar bölümü düzenleniyor yeni3
    QWidget *ayarPage=new QWidget();
    ayarPage->setFixedWidth(en*27);
    ayarPage->setFixedHeight(en*25);
   /**********************Tören Giriş**********************************/

    QToolButton *torenZilButton= new QToolButton;
   // torenZilButton->setFixedSize(170, 30);
    //torenZilButton->setIconSize(QSize(150,30));
    torenZilButton->setText("Sabah Töreni Zili Çal");
    torenZilButton->setStyleSheet("Text-align:center");


    QLineEdit *torenZilLineEdit=new QLineEdit(ayarPage);
    if (obj.contains("torenzil"))
        torenZilLineEdit->setText(obj["torenzil"].toString());

    ModernValueSliderWidget *torenZilSeviyeLineEdit = new ModernValueSliderWidget(ayarPage);
    //torenZilSeviyeLineEdit->setFixedWidth(en * 10);
    torenZilSeviyeLineEdit->setRange(0, 100);
    torenZilSeviyeLineEdit->setValue(80);

    if (obj.contains("torenzilseviye"))
        torenZilSeviyeLineEdit->setValue(obj["torenzilseviye"].toInt());

    connect(torenZilButton, &QPushButton::clicked, [=]() {
        if(!dosyaVarmi("e-zil.json")) return;
        int deger=torenZilSeviyeLineEdit->value();
        QFile* file = new QFile(torenZilLineEdit->text());
        qDebug()<<"Tören zili çalınıyor.."<<torenZilLineEdit->text();
        if (file->open(QFile::ReadOnly)) {
            float volume = deger / 100.0f;   // %50 → 0.50
            QStringList list;
            list <<torenZilLineEdit->text();
            miniPlayer->setPlaylist(list);
            miniPlayer->setFadeDuration(400);   // ms
            miniPlayer->setVolume(volume);
            miniPlayer->play();
        }

    });
/************************************************************************/
    QPushButton *torenZilFileSelectButton= new QPushButton;
    torenZilFileSelectButton->setFixedWidth(30);
    torenZilFileSelectButton->setText("...");
    torenZilFileSelectButton->setStyleSheet("Text-align:center");
    //ogrenciZilFileSelectButton->setFlat(true);
    connect(torenZilFileSelectButton, &QPushButton::clicked, [=]() {
        QString fileName = QFileDialog::getOpenFileName(this,tr("Dosya Seç"),"/usr/share/e-zil/e-zil-ses", tr("Files (*.*)"));
    //qDebug()<<fileName;
       // torenZilLineEdit->setText(fileName.remove(QDir::homePath()+"/"));
       torenZilLineEdit->setText(fileName);
 });

    /*************************Öğrenci*******************************/
    QPushButton *ogrenciZilButton= new QPushButton;
    ogrenciZilButton->setText("Öğrenci Zil Çal");
    ogrenciZilButton->setStyleSheet("Text-align:center");
    QLineEdit *ogrenciZilLineEdit=new QLineEdit(ayarPage);
    if (obj.contains("ogrencizil"))
        ogrenciZilLineEdit->setText(obj["ogrencizil"].toString());


    ModernValueSliderWidget *ogrenciZilSeviyeLineEdit = new ModernValueSliderWidget(ayarPage);
    //ogrenciZilSeviyeLineEdit->setFixedWidth(en * 10);
    ogrenciZilSeviyeLineEdit->setRange(0, 100);
    ogrenciZilSeviyeLineEdit->setValue(80);

    if (obj.contains("ogrencizilseviye"))
        ogrenciZilSeviyeLineEdit->setValue(obj["ogrencizilseviye"].toInt());

    connect(ogrenciZilButton, &QPushButton::clicked, [=]() {

        if(!dosyaVarmi("e-zil.json")) return;

         int deger=ogrenciZilSeviyeLineEdit->value();
        //player->setVolume(deger.toInt());
        QFile* file = new QFile(ogrenciZilLineEdit->text());
        if (file->open(QFile::ReadOnly)) {
             qDebug()<<"Öğrenci zili çalınıyor..";
             /*player->setMedia(QMediaContent(), file);
            file->seek(0);
            player->play();*/
             float volume = deger / 100.0f;   // %50 → 0.50
             QStringList list;
             list <<ogrenciZilLineEdit->text();
             miniPlayer->setPlaylist(list);
             miniPlayer->setFadeDuration(400);   // ms
             miniPlayer->setVolume(volume);
             miniPlayer->play();


        }
    });
/************************************************************************/
    QPushButton *ogrenciZilFileSelectButton= new QPushButton;
    ogrenciZilFileSelectButton->setFixedWidth(30);
    ogrenciZilFileSelectButton->setText("...");
    ogrenciZilFileSelectButton->setStyleSheet("Text-align:center");
    //ogrenciZilFileSelectButton->setFlat(true);
    connect(ogrenciZilFileSelectButton, &QPushButton::clicked, [=]() {
        QString fileName = QFileDialog::getOpenFileName(this,tr("Dosya Seç"),"/usr/share/e-zil/e-zil-ses", tr("Files (*.*)"));
    //qDebug()<<fileName;
       // ogrenciZilLineEdit->setText(fileName.remove(QDir::homePath()+"/"));
         ogrenciZilLineEdit->setText(fileName);
 });
    /***************************Öğretmen*********************************************/

    QPushButton *ogretmenZilButton= new QPushButton;
    ogretmenZilButton->setText("Öğretmen Zil Çal");
    ogretmenZilButton->setStyleSheet("Text-align:center");
    QLineEdit *ogretmenZilLineEdit=new QLineEdit;
    if (obj.contains("ogretmenzil"))
        ogretmenZilLineEdit->setText(obj["ogretmenzil"].toString());

    ModernValueSliderWidget *ogretmenZilSeviyeLineEdit = new ModernValueSliderWidget(ayarPage);
    //ogretmenZilSeviyeLineEdit->setFixedWidth(en * 10);
    ogretmenZilSeviyeLineEdit->setRange(0, 100);
    ogretmenZilSeviyeLineEdit->setValue(80);

    if (obj.contains("ogretmenzilseviye"))
        ogretmenZilSeviyeLineEdit->setValue(obj["ogretmenzilseviye"].toInt());


      connect(ogretmenZilButton, &QPushButton::clicked, [=]() {
          if(!dosyaVarmi("e-zil.json")) return;
          int deger=ogretmenZilSeviyeLineEdit->value();
          QFile* file = new QFile(ogretmenZilLineEdit->text());
          if (file->open(QFile::ReadOnly)) {

              float volume = deger / 100.0f;   // %50 → 0.50
              QStringList list;
              list <<ogretmenZilLineEdit->text();
              miniPlayer->setPlaylist(list);
              miniPlayer->setFadeDuration(400);   // ms
              miniPlayer->setVolume(volume);
              miniPlayer->play();

          }

      });
    /************************************************************************/
        QPushButton *ogretmenZilFileSelectButton= new QPushButton;
        ogretmenZilFileSelectButton->setFixedWidth(30);
        ogretmenZilFileSelectButton->setText("...");
        ogretmenZilFileSelectButton->setStyleSheet("Text-align:center");
        //ogrenciZilFileSelectButton->setFlat(true);
        connect(ogretmenZilFileSelectButton, &QPushButton::clicked, [=]() {
            QString fileName = QFileDialog::getOpenFileName(this,tr("Dosya Seç"),"/usr/share/e-zil/e-zil-ses", tr("Files (*.*)"));
        //qDebug()<<fileName;
            ogretmenZilLineEdit->setText(fileName);
     });
        /************************************************************************/

    QPushButton *cikisZilButton= new QPushButton;
    //cikisZilButton->setFixedSize(170, 30);
   // cikisZilButton->setIconSize(QSize(150,30));
    cikisZilButton->setText("Çıkış Zili Çal");
    cikisZilButton->setStyleSheet("Text-align:center");
  //  cikisZilButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));
    QLineEdit *cikisZilLineEdit=new QLineEdit;
    if (obj.contains("cikiszil"))
        cikisZilLineEdit->setText(obj["cikiszil"].toString());

    ModernValueSliderWidget *cikisZilSeviyeLineEdit = new ModernValueSliderWidget(ayarPage);
    //cikisZilSeviyeLineEdit->setFixedWidth(en * 10);
    cikisZilSeviyeLineEdit->setRange(0, 100);
    cikisZilSeviyeLineEdit->setValue(80);

    if (obj.contains("cikiszilseviye"))
        cikisZilSeviyeLineEdit->setValue(obj["cikiszilseviye"].toInt());


    connect(cikisZilButton, &QPushButton::clicked, [=]() {
        if(!dosyaVarmi("e-zil.json")) return;
        int deger=cikisZilSeviyeLineEdit->value();
        QFile* file = new QFile(cikisZilLineEdit->text());
        if (file->open(QFile::ReadOnly)) {
            float volume = deger / 100.0f;   // %50 → 0.50
            QStringList list;
            list <<cikisZilLineEdit->text();
            miniPlayer->setPlaylist(list);
            miniPlayer->setFadeDuration(400);   // ms
            miniPlayer->setVolume(volume);
            miniPlayer->play();

        }
    });
    /************************************************************************/
        QPushButton *cikisZilFileSelectButton= new QPushButton;
        cikisZilFileSelectButton->setFixedWidth(30);
        cikisZilFileSelectButton->setText("...");
        cikisZilFileSelectButton->setStyleSheet("Text-align:center");

        //ogrenciZilFileSelectButton->setFlat(true);
        connect(cikisZilFileSelectButton, &QPushButton::clicked, [=]() {
            QString fileName = QFileDialog::getOpenFileName(this,tr("Dosya Seç"),"/usr/share/e-zil/e-zil-ses", tr("Files (*.*)"));
        //qDebug()<<fileName;
            cikisZilLineEdit->setText(fileName);
     });
        /************************************************************************/


    QPushButton *istiklalZilButton= new QPushButton;
    istiklalZilButton->setText("İstiklal Marşı Çal");
    istiklalZilButton->setStyleSheet("Text-align:center");
    QLineEdit *istiklalZilLineEdit=new QLineEdit;
    if (obj.contains("istiklalzil"))
        istiklalZilLineEdit->setText(obj["istiklalzil"].toString());

    ModernValueSliderWidget *istiklalZilSeviyeLineEdit = new ModernValueSliderWidget(ayarPage);
    //istiklalZilSeviyeLineEdit->setFixedWidth(en * 10);
    istiklalZilSeviyeLineEdit->setRange(0, 100);
    istiklalZilSeviyeLineEdit->setValue(80);

    if (obj.contains("istiklalzilseviye"))
        istiklalZilSeviyeLineEdit->setValue(obj["istiklalzilseviye"].toInt());


    connect(istiklalZilButton, &QPushButton::clicked, [=]() {
        if(!dosyaVarmi("e-zil.json")) return;
        int deger=istiklalZilSeviyeLineEdit->value();
        QFile* file = new QFile(istiklalZilLineEdit->text());
        if (file->open(QFile::ReadOnly)) {

            float volume = deger / 100.0f;   // %50 → 0.50
            QStringList list;
            list <<istiklalZilLineEdit->text();
            miniPlayer->setPlaylist(list);
            miniPlayer->setFadeDuration(400);   // ms
            miniPlayer->setVolume(volume);
            miniPlayer->play();
        }
    });
    /************************************************************************/
        QPushButton *istiklalZilFileSelectButton= new QPushButton;
        istiklalZilFileSelectButton->setFixedWidth(30);
        istiklalZilFileSelectButton->setText("...");
        istiklalZilFileSelectButton->setStyleSheet("Text-align:center");
        //ogrenciZilFileSelectButton->setFlat(true);
        connect(istiklalZilFileSelectButton, &QPushButton::clicked, [=]() {
            QString fileName = QFileDialog::getOpenFileName(this,tr("Dosya Seç"),"/usr/share/e-zil/e-zil-ses", tr("Files (*.*)"));
        //qDebug()<<fileName;
            istiklalZilLineEdit->setText(fileName);
     });
        /************************************************************************/

    QPushButton *saygiIstiklalZilButton= new QPushButton;
    saygiIstiklalZilButton->setText("Saygı+İstiklal Marşı Çal");
    saygiIstiklalZilButton->setStyleSheet("Text-align:center");
    QLineEdit *saygiIstiklalZilLineEdit=new QLineEdit;
     if (obj.contains("istiklalsaygizil"))
        saygiIstiklalZilLineEdit->setText(obj["istiklalsaygizil"].toString());

     ModernValueSliderWidget *saygiIstiklalZilSeviyeLineEdit = new ModernValueSliderWidget(ayarPage);
     //saygiIstiklalZilSeviyeLineEdit->setFixedWidth(en * 10);
     saygiIstiklalZilSeviyeLineEdit->setRange(0, 100);
     saygiIstiklalZilSeviyeLineEdit->setValue(80);

     if (obj.contains("istiklalsaygizilseviye"))
         saygiIstiklalZilSeviyeLineEdit->setValue(obj["istiklalsaygizilseviye"].toInt());

    connect(saygiIstiklalZilButton, &QPushButton::clicked, [=]() {
        if(!dosyaVarmi("e-zil.json")) return;
        int deger=saygiIstiklalZilSeviyeLineEdit->value();
        QFile* file = new QFile(saygiIstiklalZilLineEdit->text());
        if (file->open(QFile::ReadOnly)) {
            float volume = deger / 100.0f;   // %50 → 0.50
            QStringList list;
            list <<saygiIstiklalZilLineEdit->text();
            //qDebug()<<"isc"<<list<<volume;
            miniPlayer->setPlaylist(list);
            miniPlayer->setFadeDuration(400);   // ms
            miniPlayer->setVolume(volume);
            miniPlayer->play();
        }

    });
    /************************************************************************/
        QPushButton *saygiIstiklalZilFileSelectButton= new QPushButton;
        saygiIstiklalZilFileSelectButton->setFixedWidth(30);
        saygiIstiklalZilFileSelectButton->setText("...");
        saygiIstiklalZilFileSelectButton->setStyleSheet("Text-align:center");
        //ogrenciZilFileSelectButton->setFlat(true);
        connect(saygiIstiklalZilFileSelectButton, &QPushButton::clicked, [=]() {
            QString fileName = QFileDialog::getOpenFileName(this,tr("Dosya Seç"),"/usr/share/e-zil/e-zil-ses", tr("Files (*.*)"));
        //qDebug()<<fileName;
            saygiIstiklalZilLineEdit->setText(fileName);
     });
        /************************************************************************/

    QPushButton *sirenZilButton= new QPushButton;
    sirenZilButton->setText("Siren Çal");
    sirenZilButton->setStyleSheet("Text-align:center");
    QLineEdit *sirenZilLineEdit=new QLineEdit;

    if (obj.contains("sirenzil"))
        sirenZilLineEdit->setText(obj["sirenzil"].toString());

    ModernValueSliderWidget *sirenZilSeviyeLineEdit = new ModernValueSliderWidget(ayarPage);
    //sirenZilSeviyeLineEdit->setFixedWidth(en * 10);
    sirenZilSeviyeLineEdit->setRange(0, 100);
    sirenZilSeviyeLineEdit->setValue(80);

    if (obj.contains("sirenzilseviye"))
        sirenZilSeviyeLineEdit->setValue(obj["sirenzilseviye"].toInt());

  connect(sirenZilButton, &QPushButton::clicked, [=]() {
        if(!dosyaVarmi("e-zil.json")) return;
        int deger=sirenZilSeviyeLineEdit->value();
        //player->setVolume(deger.toInt());

        QFile* file = new QFile(sirenZilLineEdit->text());
        if (file->open(QFile::ReadOnly)) {
            float volume = deger / 100.0f;   // %50 → 0.50
            QStringList list;
            list <<sirenZilLineEdit->text();
            miniPlayer->setPlaylist(list);
            miniPlayer->setFadeDuration(400);   // ms
            miniPlayer->setVolume(volume);
            miniPlayer->play();
        }


    });
    /************************************************************************/
        QPushButton *sirenZilFileSelectButton= new QPushButton;
        sirenZilFileSelectButton->setFixedWidth(30);
        sirenZilFileSelectButton->setText("...");
        sirenZilFileSelectButton->setStyleSheet("Text-align:center");
        //ogrenciZilFileSelectButton->setFlat(true);
        connect(sirenZilFileSelectButton, &QPushButton::clicked, [=]() {
            QString fileName = QFileDialog::getOpenFileName(this,tr("Dosya Seç"),"/usr/share/e-zil/e-zil-ses", tr("Files (*.*)"));
        //qDebug()<<fileName;
            sirenZilLineEdit->setText(fileName);
     });
        /************************************************************************/
        QPushButton *dersSonuPcKapatButton= new QPushButton;
        dersSonuPcKapatButton->setText("Hafta İçi Bilgisayar Kapat");
        dersSonuPcKapatButton->setStyleSheet("Text-align:center");
        QTimeEdit *dersSonuPcKapatTimeEdit=new QTimeEdit;
        if (obj.contains("derssonupckapat"))
            dersSonuPcKapatTimeEdit->setTime(saniyeToSaat(obj["derssonupckapat"].toString()));

        connect(dersSonuPcKapatButton, &QPushButton::clicked, [=]() {
           /* player = new QMediaPlayer(nullptr, QMediaPlayer::StreamPlayback);
            QFile* file = new QFile(sirenZilLineEdit->text());
            if (file->open(QFile::ReadOnly)) {
                player->setMedia(QMediaContent(), file);
                file->seek(0);
                player->play();
                */
           // }

     });
 /************************************************************************/
QPushButton *molaPcKapatButton= new QPushButton;
//molaPcKapatButton->setIconSize(QSize(150,30));
molaPcKapatButton->setText("Hafta Sonu Bilgisayar Kapat");
molaPcKapatButton->setStyleSheet("Text-align:center");
// molaPcKapatButton->setFlat(true);
// molaPcKapatButton->setIcon(QIcon(":icons/saveprofile.png"));
QTimeEdit *molaPcKapatTimeEdit=new QTimeEdit;
if (obj.contains("molapckapat"))
     molaPcKapatTimeEdit->setTime(saniyeToSaat(obj["molapckapat"].toString()));

connect(molaPcKapatButton, &QPushButton::clicked, [=]() {
   /* player = new QMediaPlayer(nullptr, QMediaPlayer::StreamPlayback);
    QFile* file = new QFile(sirenZilLineEdit->text());
    if (file->open(QFile::ReadOnly)) {
        player->setMedia(QMediaContent(), file);
        file->seek(0);
        player->play();
        */
    //}

});

QLineEdit *kapatKomutEdit=new QLineEdit;


    kapatKomutEdit->setText("/sbin/poweroff");


if (obj.contains("kapatKomut"))
    kapatKomutEdit->setText(obj["kapatKomut"].toString());


/************************************************************************/


QLineEdit *muzikLineEdit=new QLineEdit;
if (obj.contains("muzikklasor"))
    muzikLineEdit->setText(obj["muzikklasor"].toString());

/************************************************************************/
QPushButton *muzikFileSelectButton= new QPushButton;
//muzikFileSelectButton->setFixedSize(20, 30);
muzikFileSelectButton->setFixedWidth(30);
muzikFileSelectButton->setText("...");
muzikFileSelectButton->setStyleSheet("Text-align:center");
//ogrenciZilFileSelectButton->setFlat(true);
connect(muzikFileSelectButton, &QPushButton::clicked, [=]() {
    QString fileName = QFileDialog::getExistingDirectory(this, tr("Klasör Seç"),"/usr/share/e-zil/e-zil-ses",

                                                         QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
//qDebug()<<fileName;
    muzikLineEdit->setText(fileName.remove(QDir::homePath()+"/"));
});
/************************************************************************/
QTimeEdit *muzikBaslamaTimeEdit=new QTimeEdit;
if (obj.contains("muzikbaslama"))
     muzikBaslamaTimeEdit->setTime(saniyeToSaat(obj["muzikbaslama"].toString()));

 QTimeEdit *muzikSonTimeEdit=new QTimeEdit;
 ///muzikSonTimeEdit->setFixedSize(65, 30);
 if (obj.contains("muzikson"))
      muzikSonTimeEdit->setTime(saniyeToSaat(obj["muzikson"].toString()));

 ModernValueSliderWidget *muzikYayinZilSeviyeLineEdit = new ModernValueSliderWidget(ayarPage);
 //muzikYayinZilSeviyeLineEdit->setFixedWidth(en * 10);
 muzikYayinZilSeviyeLineEdit->setRange(0, 100);
 muzikYayinZilSeviyeLineEdit->setValue(80);

 if (obj.contains("muzikyayinseviye"))
     muzikYayinZilSeviyeLineEdit->setValue(obj["muzikyayinseviye"].toInt());

 /**********************************************************************/
   QPushButton *muzikYayinZilButton= new QPushButton;
//   muzikYayinZilButton->setFixedSize(170, 30);
 //  muzikYayinZilButton->setIconSize(QSize(150,30));
  // durZilButton->setFixedSize(150, 30);
  // durZilButton->setIconSize(QSize(150,30));
   muzikYayinZilButton->setText("Müzik Yayın Klasör Çal");
   muzikYayinZilButton->setStyleSheet("Text-align:Center");
 //  durZilButton->setFlat(true);
  // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));
   connect(muzikYayinZilButton, &QPushButton::clicked, [=]() {
       if(!dosyaVarmi("e-zil.json")) return;
       int deger=muzikYayinZilSeviyeLineEdit->value();
       //player->setVolume(deger.toInt());

       if (obj.contains("muzikklasor"))
           {
           qDebug()<<"Müzik Yayını Başladı...";

              QDir klasorpath;
            if (obj.contains("muzikklasor"))
                  klasorpath=obj["muzikklasor"].toString();
              //playlist = new QMediaPlaylist;
            QStringList miniPlayList;
            klasorpath.setNameFilters({"*.wav" , "*.mp3"});
            for(const QFileInfo & finfo: klasorpath.entryInfoList()){
                //miniPlayList<<QUrl::fromLocalFile(finfo.absoluteFilePath());
                miniPlayList << finfo.absoluteFilePath();
                 // playlist->addMedia(QUrl::fromLocalFile(finfo.absoluteFilePath()));
                 // muziklist.append(QUrl::fromLocalFile(finfo.absoluteFilePath()).toString().remove(0,7)).append(" ");

                  // qDebug()<<QUrl::fromLocalFile(finfo.absoluteFilePath()).toString();
              }
              float volume = muzikYayinZilSeviyeLineEdit->value() / 100.0f;   // %50 → 0.50
              //qDebug()<<"Liste: "<<miniPlayList<<volume;
              miniPlayer->setPlaylist(miniPlayList);
              miniPlayer->setFadeDuration(400);   // ms
              miniPlayer->setVolume(volume);
              miniPlayer->play();

             // player->setMedia(playlist);
             // player->play();
       }

   });
        /************************************************************************/
   QTimeEdit *molaSuresiTimeEdit=new QTimeEdit;
    molaSuresiTimeEdit->setTime(QTime::fromString("01:00"));
    if (obj.contains("molasuresi"))
        molaSuresiTimeEdit->setTime(saniyeToSaat(obj["molasuresi"].toString()));

    QLineEdit *molaDersSaatiLineEdit=new QLineEdit;
    molaDersSaatiLineEdit->setText("4");
     if (obj.contains("moladerssaati"))
         molaDersSaatiLineEdit->setText(obj["moladerssaati"].toString());

     QLineEdit *dersSayisiLineEdit=new QLineEdit;
     dersSayisiLineEdit->setText("7");

      if (obj.contains("derssayisi"))
          dersSayisiLineEdit->setText(obj["derssayisi"].toString());

  /*************************************************************************************/

    QPushButton *durZilButton= new QPushButton;
   // durZilButton->setFixedSize(150, 30);
   // durZilButton->setIconSize(QSize(150,30));
    durZilButton->setText("Zil Durdur");
    durZilButton->setStyleSheet("Text-align:Center");
  //  durZilButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(durZilButton, &QPushButton::clicked, [=]() {

            //player->stop();
          miniPlayer->stop();
       });

    QPushButton *onemligunButton= new QPushButton;
   // onemligunButton->setFixedSize(150, 30);
   // onemligunButton->setIconSize(QSize(150,30));
    onemligunButton->setText("Önemli Gün İşlemleri");
    onemligunButton->setStyleSheet("Text-align:Center");
  //  onemligunButton->setFlat(true);
   // onemligunButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(onemligunButton, &QPushButton::clicked, [=]() {
            onemliGunSlot();
            //player->stop();
            miniPlayer->stop();
       });


    QPushButton *ayarKaydetButton= new QPushButton;
    //ayarKaydetButton->setFixedSize(150, 30);
   // ayarKaydetButton->setIconSize(QSize(150,30));
    ayarKaydetButton->setText("Ayarları Kaydet");
    ayarKaydetButton->setStyleSheet("Text-align:Center");
  //  ayarKaydetButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(ayarKaydetButton, &QPushButton::clicked, [=]() {
     //   if(player->mediaStatus()==QMediaPlayer::PlayingState)

        miniPlayer->stop();
     // Widget listelerini oluştur
      db->Sil("recordtype","settings");
     // Döngü ile tüm dersleri ekle
         QJsonObject obj;
         obj["recordtype"] = "settings";
         obj["torenzil"] = torenZilLineEdit->text();
         obj["ogrencizil"] = ogrenciZilLineEdit->text();
         obj["ogretmenzil"] = ogretmenZilLineEdit->text();
         obj["cikiszil"] = cikisZilLineEdit->text();
         obj["istiklalzil"] = istiklalZilLineEdit->text();
         obj["istiklalsaygizil"] = saygiIstiklalZilLineEdit->text();
         obj["sirenzil"] =    sirenZilLineEdit->text();
         obj["derssonupckapat"] =    saatToSaniye(dersSonuPcKapatTimeEdit->time());
         obj["molapckapat"] =    saatToSaniye(molaPcKapatTimeEdit->time());
         obj["kapatKomut"] =    kapatKomutEdit->text();
         obj["muzikbaslama"] =    saatToSaniye(muzikBaslamaTimeEdit->time());
         obj["muzikson"] =    saatToSaniye(muzikSonTimeEdit->time());

         obj["torenzilseviye"] =    torenZilSeviyeLineEdit->value();
         obj["ogrencizilseviye"] =    ogrenciZilSeviyeLineEdit->value();
         obj["ogretmenzilseviye"] =    ogretmenZilSeviyeLineEdit->value();
         obj["cikiszilseviye"] =    cikisZilSeviyeLineEdit->value();

         obj["istiklalzilseviye"] =    istiklalZilSeviyeLineEdit->value();
         obj["istiklalsaygizilseviye"] =    saygiIstiklalZilSeviyeLineEdit->value();
         obj["sirenzilseviye"] =    sirenZilSeviyeLineEdit->value();
         obj["muzikyayinseviye"] =    muzikYayinZilSeviyeLineEdit->value();
         obj["oglenMuzikYayinState"] =    oglenMuzikYayinState;
         obj["SZSState"] =   SZSState;
         obj["ekilitState"] =    ekilitState;
         obj["gunState"] =    gunState;

         obj["muzikklasor"] =    muzikLineEdit->text();
         obj["molasuresi"] =    saatToSaniye(molaSuresiTimeEdit->time());
         obj["moladerssaati"] =    molaDersSaatiLineEdit->text();
         obj["derssayisi"] =    dersSayisiLineEdit->text();

               db->Ekle(obj);


        ////init();
        tw->widget(1)->deleteLater();
        tw->widget(2)->deleteLater();
        tw->widget(3)->deleteLater();
        tw->widget(4)->deleteLater();
        tw->widget(5)->deleteLater();
        tw->widget(6)->deleteLater();
        tw->widget(7)->deleteLater();
        tw->widget(8)->deleteLater();
        tw->widget(9)->deleteLater();

        tw->addTab(ayar(),"Ayarlar");
        tw->addTab(saatpzrts(1),"Pzrts");
        tw->addTab(saatpzrts(2),"Salı");
        tw->addTab(saatpzrts(3),"Çrşmb");
        tw->addTab(saatpzrts(4),"Prşmb");
        tw->addTab(saatpzrts(5),"Cuma");
        tw->addTab(saatpzrts(6),"Cmrts");
        tw->addTab(saatpzrts(7),"Pazar");
        tw->addTab(hakkinda(),"Hakkında");

 });


QCheckBox *oglenMuzikYayincb = new QCheckBox("Müzik Yayını Yapılsın!",ayarPage);
//QFont ff( "Arial", 8, QFont::Normal);
//tenefusMuzikYayincb->setFont(ff);

if (obj.contains("oglenMuzikYayinState"))
   oglenMuzikYayinState=obj["oglenMuzikYayinState"].toBool();

oglenMuzikYayincb->setChecked(oglenMuzikYayinState);
connect(oglenMuzikYayincb, &QCheckBox::clicked, [=]() {
if(oglenMuzikYayincb->checkState()==Qt::Checked)
{
    oglenMuzikYayinState=true;

}
if(oglenMuzikYayincb->checkState()==Qt::Unchecked)
{
   oglenMuzikYayinState=false;
}

});
/*********************Sessiz zil gösteri ayarı************************************/
QCheckBox *SZScb = new QCheckBox("Sessiz Zil Sistemi Gözüksün Mü?",ayarPage);

if (obj.contains("SZSState"))
    SZSState=obj["SZSState"].toBool();

if(SZSState)
{
   // qDebug()<<"SZSState"<<SZSState;
    SZScb->setChecked(Qt::Checked);
}
else
{
    // qDebug()<<"SZSState"<<SZSState;
    SZScb->setChecked(Qt::Unchecked);
}

connect(SZScb, &QCheckBox::clicked, [=]() {
if(SZScb->checkState()==Qt::Checked)
{
    SZSState=true;
    //SZSgoster();
    qDebug()<<SZSState;

}
if(SZScb->checkState()==Qt::Unchecked)
{
   SZSState=false;
    qDebug()<<SZSState;
   //SZSgizle();
}

});

/********************* önemli gün ayarı************************************/
QCheckBox *guncb = new QCheckBox("Önemli Günler Gösterilsin Mi?",ayarPage);


if (obj.contains("gunState"))
    gunState=(obj["gunState"].toBool());


if(gunState)
{
   // qDebug()<<"ekilitState"<<ekilitState;
    guncb->setChecked(Qt::Checked);
}
else
{
    // qDebug()<<"ekilitState"<<ekilitState;
    guncb->setChecked(Qt::Unchecked);
}

connect(guncb, &QCheckBox::clicked, [=]() {
if(guncb->checkState()==Qt::Checked)
{
    gunState=true;
    SZSgoster();

}
if(guncb->checkState()==Qt::Unchecked)
{
   gunState=false;
   SZSgizle();
}

});
    auto layout = new QGridLayout(ayarPage);
    layout->setContentsMargins(0, 10, 0,0);
   // layout->setVerticalSpacing(5);
   // layout->setColumnMinimumWidth(0, 37);
    //layout->addWidget(adLabel, 2,0,1,2);
    layout->addWidget(torenZilButton, 5,0,1,1);
    layout->addWidget(torenZilLineEdit, 5,1,1,3);
    layout->addWidget(torenZilFileSelectButton, 5,4,1,1);
    layout->addWidget(torenZilSeviyeLineEdit, 5,5,1,1);

    layout->addWidget(ogrenciZilButton, 10,0,1,1);
    layout->addWidget(ogrenciZilLineEdit, 10,1,1,3);
    layout->addWidget(ogrenciZilFileSelectButton, 10,4,1,1);
    layout->addWidget(ogrenciZilSeviyeLineEdit, 10,5,1,1);

    layout->addWidget(ogretmenZilButton, 15,0,1,1);
    layout->addWidget(ogretmenZilLineEdit, 15,1,1,3);
    layout->addWidget(ogretmenZilFileSelectButton, 15,4,1,1);
    layout->addWidget(ogretmenZilSeviyeLineEdit, 15,5,1,1);


    layout->addWidget(cikisZilButton, 20,0,1,1);
    layout->addWidget(cikisZilLineEdit, 20,1,1,3);
    layout->addWidget(cikisZilFileSelectButton, 20,4,1,1);
    layout->addWidget(cikisZilSeviyeLineEdit, 20,5,1,1);

    layout->addWidget(istiklalZilButton, 25,0,1,1);
    layout->addWidget(istiklalZilLineEdit, 25,1,1,3);
    layout->addWidget(istiklalZilFileSelectButton, 25,4,1,1);
    layout->addWidget(istiklalZilSeviyeLineEdit, 25,5,1,1);

    layout->addWidget(saygiIstiklalZilButton, 30,0,1,1);
    layout->addWidget(saygiIstiklalZilLineEdit, 30,1,1,3);
    layout->addWidget(saygiIstiklalZilFileSelectButton, 30,4,1,1);
    layout->addWidget(saygiIstiklalZilSeviyeLineEdit, 30,5,1,1);

    layout->addWidget(sirenZilButton, 35,0,1,1);
    layout->addWidget(sirenZilLineEdit, 35,1,1,3);
    layout->addWidget(sirenZilFileSelectButton, 35,4,1,1);
    layout->addWidget(sirenZilSeviyeLineEdit, 35,5,1,1);

    layout->addWidget(muzikYayinZilButton,36,0,1,1);
    layout->addWidget(muzikLineEdit, 36,1,1,3);
    layout->addWidget(muzikFileSelectButton, 36,4,1,1);
    layout->addWidget(muzikYayinZilSeviyeLineEdit, 36,5,1,1);

    layout->addWidget(new QLabel("Ders Sayısı") , 37,0,1,1);
    layout->addWidget(dersSayisiLineEdit, 37,1,1,2);

    layout->addWidget(new QLabel("Öğle Öncesi Ders Sayısı"),38,0,1,1);
    layout->addWidget(molaDersSaatiLineEdit, 38,1,1,2);

    layout->addWidget(new QLabel("Mola Süresi") , 39,0,1,1);
    layout->addWidget(molaSuresiTimeEdit, 39,1,1,2);

    layout->addWidget(new QLabel("Ders Sonu Pc Kapatma"),40,0,1,2);
    layout->addWidget(dersSonuPcKapatTimeEdit, 40,1,1,2);

    layout->addWidget(new QLabel("Mola Başı Pc Kapatma"),41,0,1,2);
    layout->addWidget(molaPcKapatTimeEdit, 41,1,1,2);


    layout->addWidget(new QLabel("Kapatma Komutu"), 43,0,1,1);
    layout->addWidget(kapatKomutEdit, 43,1,1,4);

    layout->addWidget(new QLabel("Müzik Y. Başla/Dur Saati"),45,0,1,1);
    layout->addWidget(muzikBaslamaTimeEdit, 45,1,1,2);
    layout->addWidget(muzikSonTimeEdit, 45,3,1,2);

    layout->addWidget(oglenMuzikYayincb, 46,0,1,7);
    layout->addWidget(SZScb, 49,0,1,7);
    layout->addWidget(guncb, 51,0,1,7);

    layout->addWidget(durZilButton,52,0,1,1);
    layout->addWidget(ayarKaydetButton,52,3,1,3);
   layout->addWidget(onemligunButton,55,0,1,7);

//layout->setColumnStretch(6, 255);

    return ayarPage;
}
#endif // AYAR_H
