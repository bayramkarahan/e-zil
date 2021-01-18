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
QWidget *MainWindow::ayar()
{
   // qDebug()<<"ayar";
//burada ayarlar bölümü düzenleniyor yeni3
    QWidget *ayarPage=new QWidget();
    /*******************************************************/
    //QStringList ayarlst=listGetList(fileToList("e-zil.conf"), "ayar",0);//0 sütun bilgisi olan güne göre listconf listesinden filitreleniyor
   // player = new QMediaPlayer(nullptr, QMediaPlayer::StreamPlayback);
    /**********************Tören Giriş**********************************/
    QToolButton *torenZilButton= new QToolButton;
    torenZilButton->setFixedSize(170, 30);
    torenZilButton->setIconSize(QSize(150,30));
    torenZilButton->setText("Sabah Töreni Zili Çal");
    torenZilButton->setStyleSheet("Text-align:center");


    QLineEdit *torenZilLineEdit=new QLineEdit(ayarPage);
    torenZilLineEdit->resize(500,25);
    if(listGetLine(ayarlist,"torenzil")!="")
        torenZilLineEdit->setText(listGetLine(ayarlist,"torenzil").split("|")[2]);

    QLineEdit *torenZilSeviyeLineEdit=new QLineEdit(ayarPage);
    torenZilSeviyeLineEdit->resize(500,25);
    torenZilSeviyeLineEdit->setText("80");
    if(listGetLine(ayarlist,"torenzilseviye")!="")
        torenZilSeviyeLineEdit->setText(listGetLine(ayarlist,"torenzilseviye").split("|")[2]);


    connect(torenZilButton, &QPushButton::clicked, [=]() {
        system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false");
        QString deger=listGetLine(ayarlist,"torenzilseviye").split("|")[2];
       // system("sleep 1");
        QString kmt22="pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo "+deger+"000";
       /// qDebug()<<kmt22;
        system(kmt22.toStdString().c_str());
        //  player = new QMediaPlayer(nullptr, QMediaPlayer::StreamPlayback);
        QFile* file = new QFile(torenZilLineEdit->text());
        if (file->open(QFile::ReadOnly)) {
            player->setMedia(QMediaContent(), file);
            file->seek(0);
            player->play();
        }
 });
/************************************************************************/
    QPushButton *torenZilFileSelectButton= new QPushButton;
    torenZilFileSelectButton->setFixedSize(20, 30);
    torenZilFileSelectButton->setText("...");
    torenZilFileSelectButton->setStyleSheet("Text-align:center");
    //ogrenciZilFileSelectButton->setFlat(true);
    connect(torenZilFileSelectButton, &QPushButton::clicked, [=]() {
        QString fileName = QFileDialog::getOpenFileName(this,tr("Dosya Seç"),QDir::homePath()+"/e-zil-ses", tr("Files (*.*)"));
    //qDebug()<<fileName;
        torenZilLineEdit->setText(fileName);
 });

    /*************************Öğrenci*******************************/
    QPushButton *ogrenciZilButton= new QPushButton;
    ogrenciZilButton->setFixedSize(170, 30);
    ogrenciZilButton->setIconSize(QSize(150,30));
    ogrenciZilButton->setText("Öğrenci Zil Çal");
    ogrenciZilButton->setStyleSheet("Text-align:center");
    //ogrenciZilButton->setFlat(true);
    QLineEdit *ogrenciZilLineEdit=new QLineEdit(ayarPage);
    ogrenciZilLineEdit->resize(500,25);
    if(listGetLine(ayarlist,"ogrencizil")!="")
        ogrenciZilLineEdit->setText(listGetLine(ayarlist,"ogrencizil").split("|")[2]);

    QLineEdit *ogrenciZilSeviyeLineEdit=new QLineEdit(ayarPage);
    ogrenciZilSeviyeLineEdit->resize(500,25);
    ogrenciZilSeviyeLineEdit->setText("80");
    if(listGetLine(ayarlist,"ogrencizilseviye")!="")
        ogrenciZilSeviyeLineEdit->setText(listGetLine(ayarlist,"ogrencizilseviye").split("|")[2]);

    connect(ogrenciZilButton, &QPushButton::clicked, [=]() {
        system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false");
        QString deger=listGetLine(ayarlist,"ogrencizilseviye").split("|")[2];
        QString kmt22="pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo "+deger+"000";
        system(kmt22.toStdString().c_str());
      //  player = new QMediaPlayer(nullptr, QMediaPlayer::StreamPlayback);
        QFile* file = new QFile(ogrenciZilLineEdit->text());
        if (file->open(QFile::ReadOnly)) {
            player->setMedia(QMediaContent(), file);
            file->seek(0);
            player->play();
        }
 });
/************************************************************************/
    QPushButton *ogrenciZilFileSelectButton= new QPushButton;
    ogrenciZilFileSelectButton->setFixedSize(20, 30);
    ogrenciZilFileSelectButton->setText("...");
    ogrenciZilFileSelectButton->setStyleSheet("Text-align:center");
    //ogrenciZilFileSelectButton->setFlat(true);
    connect(ogrenciZilFileSelectButton, &QPushButton::clicked, [=]() {
        QString fileName = QFileDialog::getOpenFileName(this,tr("Dosya Seç"),QDir::homePath()+"/e-zil-ses", tr("Files (*.*)"));
    //qDebug()<<fileName;
        ogrenciZilLineEdit->setText(fileName);
 });
    /***************************Öğretmen*********************************************/

    QPushButton *ogretmenZilButton= new QPushButton;
    ogretmenZilButton->setFixedSize(170, 30);
    ogretmenZilButton->setIconSize(QSize(150,30));
    ogretmenZilButton->setText("Öğretmen Zil Çal");
    ogretmenZilButton->setStyleSheet("Text-align:center");
  //  ogretmenZilButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));
    QLineEdit *ogretmenZilLineEdit=new QLineEdit;
     if(listGetLine(ayarlist,"ogretmenzil")!="")
        ogretmenZilLineEdit->setText(listGetLine(ayarlist,"ogretmenzil").split("|")[2]);

     QLineEdit *ogretmenZilSeviyeLineEdit=new QLineEdit;
     ogretmenZilSeviyeLineEdit->setText("80");
      if(listGetLine(ayarlist,"ogretmenzilseviye")!="")
         ogretmenZilSeviyeLineEdit->setText(listGetLine(ayarlist,"ogretmenzilseviye").split("|")[2]);

    connect(ogretmenZilButton, &QPushButton::clicked, [=]() {
        system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false");
        QString deger=listGetLine(ayarlist,"ogretmenzilseviye").split("|")[2];
        QString kmt22="pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo "+deger+"000";
        system(kmt22.toStdString().c_str());
          //  player = new QMediaPlayer(nullptr, QMediaPlayer::StreamPlayback);
        QFile* file = new QFile(ogretmenZilLineEdit->text());
        if (file->open(QFile::ReadOnly)) {
            player->setMedia(QMediaContent(), file);
            file->seek(0);
            player->play();
        }

 });
    /************************************************************************/
        QPushButton *ogretmenZilFileSelectButton= new QPushButton;
        ogretmenZilFileSelectButton->setFixedSize(20, 30);
        ogretmenZilFileSelectButton->setText("...");
        ogretmenZilFileSelectButton->setStyleSheet("Text-align:center");
        //ogrenciZilFileSelectButton->setFlat(true);
        connect(ogretmenZilFileSelectButton, &QPushButton::clicked, [=]() {
            QString fileName = QFileDialog::getOpenFileName(this,tr("Dosya Seç"),QDir::homePath()+"/e-zil-ses", tr("Files (*.*)"));
        //qDebug()<<fileName;
            ogretmenZilLineEdit->setText(fileName);
     });
        /************************************************************************/

    QPushButton *cikisZilButton= new QPushButton;
    cikisZilButton->setFixedSize(170, 30);
    cikisZilButton->setIconSize(QSize(150,30));
    cikisZilButton->setText("Çıkış Zili Çal");
    cikisZilButton->setStyleSheet("Text-align:center");
  //  cikisZilButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));
    QLineEdit *cikisZilLineEdit=new QLineEdit;
    if(listGetLine(ayarlist,"cikiszil")!="")
       cikisZilLineEdit->setText(listGetLine(ayarlist,"cikiszil").split("|")[2]);

    QLineEdit *cikisZilSeviyeLineEdit=new QLineEdit;
    cikisZilSeviyeLineEdit->setText("80");
    if(listGetLine(ayarlist,"cikiszilseviye")!="")
       cikisZilSeviyeLineEdit->setText(listGetLine(ayarlist,"cikiszilseviye").split("|")[2]);

    connect(cikisZilButton, &QPushButton::clicked, [=]() {
        system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false");
        QString deger=listGetLine(ayarlist,"cikiszilseviye").split("|")[2];
        QString kmt22="pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo "+deger+"000";
        system(kmt22.toStdString().c_str());
           // player = new QMediaPlayer(nullptr, QMediaPlayer::StreamPlayback);
        QFile* file = new QFile(cikisZilLineEdit->text());
        if (file->open(QFile::ReadOnly)) {
            player->setMedia(QMediaContent(), file);
            file->seek(0);
            player->play();
        }

 });
    /************************************************************************/
        QPushButton *cikisZilFileSelectButton= new QPushButton;
        cikisZilFileSelectButton->setFixedSize(20, 30);
        cikisZilFileSelectButton->setText("...");
        cikisZilFileSelectButton->setStyleSheet("Text-align:center");

        //ogrenciZilFileSelectButton->setFlat(true);
        connect(cikisZilFileSelectButton, &QPushButton::clicked, [=]() {
            QString fileName = QFileDialog::getOpenFileName(this,tr("Dosya Seç"),QDir::homePath()+"/e-zil-ses", tr("Files (*.*)"));
        //qDebug()<<fileName;
            cikisZilLineEdit->setText(fileName);
     });
        /************************************************************************/


    QPushButton *istiklalZilButton= new QPushButton;
    istiklalZilButton->setFixedSize(170, 30);
    istiklalZilButton->setIconSize(QSize(150,30));
    istiklalZilButton->setText("İstiklal Marşı Çal");
    istiklalZilButton->setStyleSheet("Text-align:center");
   // istiklalZilButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));
    QLineEdit *istiklalZilLineEdit=new QLineEdit;
    if(listGetLine(ayarlist,"istiklalzil")!="")
        istiklalZilLineEdit->setText(listGetLine(ayarlist,"istiklalzil").split("|")[2]);

    QLineEdit *istiklalZilSeviyeLineEdit=new QLineEdit;
    istiklalZilSeviyeLineEdit->setText("80");
    if(listGetLine(ayarlist,"istiklalzilseviye")!="")
        istiklalZilSeviyeLineEdit->setText(listGetLine(ayarlist,"istiklalzilseviye").split("|")[2]);

    connect(istiklalZilButton, &QPushButton::clicked, [=]() {
        system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false");
        QString deger=listGetLine(ayarlist,"istiklalzilseviye").split("|")[2];
        QString kmt22="pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo "+deger+"000";
        system(kmt22.toStdString().c_str());
         //  player = new QMediaPlayer(nullptr, QMediaPlayer::StreamPlayback);
        QFile* file = new QFile(istiklalZilLineEdit->text());
        if (file->open(QFile::ReadOnly)) {
            player->setMedia(QMediaContent(), file);
            file->seek(0);
            player->play();
        }

 });
    /************************************************************************/
        QPushButton *istiklalZilFileSelectButton= new QPushButton;
        istiklalZilFileSelectButton->setFixedSize(20, 30);
        istiklalZilFileSelectButton->setText("...");
        istiklalZilFileSelectButton->setStyleSheet("Text-align:center");
        //ogrenciZilFileSelectButton->setFlat(true);
        connect(istiklalZilFileSelectButton, &QPushButton::clicked, [=]() {
            QString fileName = QFileDialog::getOpenFileName(this,tr("Dosya Seç"),QDir::homePath()+"/e-zil-ses", tr("Files (*.*)"));
        //qDebug()<<fileName;
            istiklalZilLineEdit->setText(fileName);
     });
        /************************************************************************/

    QPushButton *saygiIstiklalZilButton= new QPushButton;
    saygiIstiklalZilButton->setFixedSize(170, 30);
    saygiIstiklalZilButton->setIconSize(QSize(150,30));
    saygiIstiklalZilButton->setText("Saygı+İstiklal Marşı Çal");
    saygiIstiklalZilButton->setStyleSheet("Text-align:center");
    //saygiIstiklalZilButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));
    QLineEdit *saygiIstiklalZilLineEdit=new QLineEdit;
    if(listGetLine(ayarlist,"istiklalsaygizil")!="")
        saygiIstiklalZilLineEdit->setText(listGetLine(ayarlist,"istiklalsaygizil").split("|")[2]);

    QLineEdit *saygiIstiklalZilSeviyeLineEdit=new QLineEdit;
    saygiIstiklalZilSeviyeLineEdit->setText("80");
    if(listGetLine(ayarlist,"istiklalsaygizilseviye")!="")
        saygiIstiklalZilSeviyeLineEdit->setText(listGetLine(ayarlist,"istiklalsaygizilseviye").split("|")[2]);

    connect(saygiIstiklalZilButton, &QPushButton::clicked, [=]() {
        system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false");
        QString deger=listGetLine(ayarlist,"istiklalsaygizilseviye").split("|")[2];
        QString kmt22="pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo "+deger+"000";
        system(kmt22.toStdString().c_str());
         // player = new QMediaPlayer(nullptr, QMediaPlayer::StreamPlayback);
        QFile* file = new QFile(saygiIstiklalZilLineEdit->text());
        if (file->open(QFile::ReadOnly)) {
            player->setMedia(QMediaContent(), file);
            file->seek(0);
            player->play();
        }

 });
    /************************************************************************/
        QPushButton *saygiIstiklalZilFileSelectButton= new QPushButton;
        saygiIstiklalZilFileSelectButton->setFixedSize(20, 30);
        saygiIstiklalZilFileSelectButton->setText("...");
        saygiIstiklalZilFileSelectButton->setStyleSheet("Text-align:center");
        //ogrenciZilFileSelectButton->setFlat(true);
        connect(saygiIstiklalZilFileSelectButton, &QPushButton::clicked, [=]() {
            QString fileName = QFileDialog::getOpenFileName(this,tr("Dosya Seç"),QDir::homePath()+"/e-zil-ses", tr("Files (*.*)"));
        //qDebug()<<fileName;
            saygiIstiklalZilLineEdit->setText(fileName);
     });
        /************************************************************************/

    QPushButton *sirenZilButton= new QPushButton;
    sirenZilButton->setFixedSize(170, 30);
    sirenZilButton->setIconSize(QSize(150,30));
    sirenZilButton->setText("Siren Çal");
    sirenZilButton->setStyleSheet("Text-align:center");
   // sirenZilButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));
    QLineEdit *sirenZilLineEdit=new QLineEdit;
    if(listGetLine(ayarlist,"sirenzil")!="")
        sirenZilLineEdit->setText(listGetLine(ayarlist,"sirenzil").split("|")[2]);

    QLineEdit *sirenZilSeviyeLineEdit=new QLineEdit;
    sirenZilSeviyeLineEdit->setText("80");
    if(listGetLine(ayarlist,"sirenzilseviye")!="")
        sirenZilSeviyeLineEdit->setText(listGetLine(ayarlist,"sirenzilseviye").split("|")[2]);

    connect(sirenZilButton, &QPushButton::clicked, [=]() {
        system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false");
        QString deger=listGetLine(ayarlist,"sirenzilseviye").split("|")[2];
        QString kmt22="pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo "+deger+"000";
        system(kmt22.toStdString().c_str());
        QFile* file = new QFile(sirenZilLineEdit->text());
        if (file->open(QFile::ReadOnly)) {
            player->setMedia(QMediaContent(), file);
            file->seek(0);
            player->play();
        }

 });
    /************************************************************************/
        QPushButton *sirenZilFileSelectButton= new QPushButton;
        sirenZilFileSelectButton->setFixedSize(20, 30);
        sirenZilFileSelectButton->setText("...");
        sirenZilFileSelectButton->setStyleSheet("Text-align:center");
        //ogrenciZilFileSelectButton->setFlat(true);
        connect(sirenZilFileSelectButton, &QPushButton::clicked, [=]() {
            QString fileName = QFileDialog::getOpenFileName(this,tr("Dosya Seç"),QDir::homePath()+"/e-zil-ses", tr("Files (*.*)"));
        //qDebug()<<fileName;
            sirenZilLineEdit->setText(fileName);
     });
        /************************************************************************/
        QPushButton *hiPcKapatButton= new QPushButton;
        hiPcKapatButton->setFixedSize(200, 30);
        hiPcKapatButton->setIconSize(QSize(150,30));
        hiPcKapatButton->setText("Hafta İçi Bilgisayar Kapat");
        hiPcKapatButton->setStyleSheet("Text-align:center");
       // sirenZilButton->setFlat(true);
       // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));
        QTimeEdit *hiPcKapatTimeEdit=new QTimeEdit;
        if(listGetLine(ayarlist,"hipckapat")!="")
           hiPcKapatTimeEdit->setTime(QTime::fromString(listGetLine(ayarlist,"hipckapat").split("|")[2]));

        connect(hiPcKapatButton, &QPushButton::clicked, [=]() {
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
/************************************************************************/
QPushButton *hsPcKapatButton= new QPushButton;
hsPcKapatButton->setFixedSize(200, 30);
hsPcKapatButton->setIconSize(QSize(150,30));
hsPcKapatButton->setText("Hafta Sonu Bilgisayar Kapat");
hsPcKapatButton->setStyleSheet("Text-align:center");
// sirenZilButton->setFlat(true);
// kilitButton->setIcon(QIcon(":icons/saveprofile.png"));
QTimeEdit *hsPcKapatTimeEdit=new QTimeEdit;
 if(listGetLine(ayarlist,"hspckapat")!="")
    hsPcKapatTimeEdit->setTime(QTime::fromString(listGetLine(ayarlist,"hspckapat").split("|")[2]));

connect(hsPcKapatButton, &QPushButton::clicked, [=]() {
   /* player = new QMediaPlayer(nullptr, QMediaPlayer::StreamPlayback);
    QFile* file = new QFile(sirenZilLineEdit->text());
    if (file->open(QFile::ReadOnly)) {
        player->setMedia(QMediaContent(), file);
        file->seek(0);
        player->play();
        */
    //}

});
/************************************************************************/


QLineEdit *muzikLineEdit=new QLineEdit;
if(listGetLine(ayarlist,"muzikklasor")!="")
muzikLineEdit->setText(listGetLine(ayarlist,"muzikklasor").split("|")[2]);
/************************************************************************/
QPushButton *muzikFileSelectButton= new QPushButton;
muzikFileSelectButton->setFixedSize(20, 30);
muzikFileSelectButton->setText("...");
muzikFileSelectButton->setStyleSheet("Text-align:center");
//ogrenciZilFileSelectButton->setFlat(true);
connect(muzikFileSelectButton, &QPushButton::clicked, [=]() {
    QString fileName = QFileDialog::getExistingDirectory(this, tr("Klasör Seç"),QDir::homePath()+"/e-zil-ses",

                                                         QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
//qDebug()<<fileName;
    muzikLineEdit->setText(fileName);
});
/************************************************************************/
QTimeEdit *muzikBaslamaTimeEdit=new QTimeEdit;
 if(listGetLine(ayarlist,"muzikbaslama")!="")
    muzikBaslamaTimeEdit->setTime(QTime::fromString(listGetLine(ayarlist,"muzikbaslama").split("|")[2]));

 QTimeEdit *muzikSonTimeEdit=new QTimeEdit;
 ///muzikSonTimeEdit->setFixedSize(65, 30);
  if(listGetLine(ayarlist,"muzikson")!="")
     muzikSonTimeEdit->setTime(QTime::fromString(listGetLine(ayarlist,"muzikson").split("|")[2]));

  QLineEdit *muzikYayinZilSeviyeLineEdit=new QLineEdit;
  muzikYayinZilSeviyeLineEdit->setText("80");
   if(listGetLine(ayarlist,"muzikyayinseviye")!="")
      muzikYayinZilSeviyeLineEdit->setText(listGetLine(ayarlist,"muzikyayinseviye").split("|")[2]);
/**********************************************************************/
   QPushButton *muzikYayinZilButton= new QPushButton;
   muzikYayinZilButton->setFixedSize(170, 30);
   muzikYayinZilButton->setIconSize(QSize(150,30));
  // durZilButton->setFixedSize(150, 30);
  // durZilButton->setIconSize(QSize(150,30));
   muzikYayinZilButton->setText("Müzik Yayın Klasör Çal");
   muzikYayinZilButton->setStyleSheet("Text-align:Center");
 //  durZilButton->setFlat(true);
  // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));
   connect(muzikYayinZilButton, &QPushButton::clicked, [=]() {
    //   if(player->mediaStatus()==QMediaPlayer::PlayingState)
      // qDebug()<<"çalıyorrrrrr";

       if (listGetLine(ayarlist,"muzikklasor")!="")
       {
           system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false"); ///system("sleep 1");
           QString deger=listGetLine(ayarlist,"muzikyayinseviye").split("|")[2];
           QString kmt22="pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo "+deger+"000";
           system(kmt22.toStdString().c_str());
           ///system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false");system("sleep 1");
           ///system("pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo 80000");
           player->setMedia(playlist);
           player->play();
       }

});
        /************************************************************************/
   QTimeEdit *molaSuresiTimeEdit=new QTimeEdit;
    molaSuresiTimeEdit->setTime(QTime::fromString("01:00"));
    if(listGetLine(ayarlist,"molasuresi")!="")
       molaSuresiTimeEdit->setTime(QTime::fromString(listGetLine(ayarlist,"molasuresi").split("|")[2]));

    QLineEdit *molaDersSaatiLineEdit=new QLineEdit;
    molaDersSaatiLineEdit->setText("4");
     if(listGetLine(ayarlist,"moladerssaati")!="")
        molaDersSaatiLineEdit->setText(listGetLine(ayarlist,"moladerssaati").split("|")[2]);
  /*************************************************************************************/

    QPushButton *durZilButton= new QPushButton;
   // durZilButton->setFixedSize(150, 30);
   // durZilButton->setIconSize(QSize(150,30));
    durZilButton->setText("Zil Durdur");
    durZilButton->setStyleSheet("Text-align:Center");
  //  durZilButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(durZilButton, &QPushButton::clicked, [=]() {
     //   if(player->mediaStatus()==QMediaPlayer::PlayingState)
            player->stop();

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
           player->stop();
        QStringList _ayarlist;
        _ayarlist.append("ayar|torenzil|"+torenZilLineEdit->text());
        _ayarlist.append("ayar|ogrencizil|"+ogrenciZilLineEdit->text());
        _ayarlist.append("ayar|ogretmenzil|"+ogretmenZilLineEdit->text());
        _ayarlist.append("ayar|cikiszil|"+cikisZilLineEdit->text());
        _ayarlist.append("ayar|istiklalzil|"+istiklalZilLineEdit->text());
        _ayarlist.append("ayar|istiklalsaygizil|"+saygiIstiklalZilLineEdit->text());
        _ayarlist.append("ayar|sirenzil|"+sirenZilLineEdit->text());
        _ayarlist.append("ayar|hipckapat|"+hiPcKapatTimeEdit->text());
        _ayarlist.append("ayar|hspckapat|"+hsPcKapatTimeEdit->text());
        _ayarlist.append("ayar|muzikbaslama|"+muzikBaslamaTimeEdit->text());
        _ayarlist.append("ayar|muzikson|"+muzikSonTimeEdit->text());
        _ayarlist.append("ayar|torenzilseviye|"+torenZilSeviyeLineEdit->text());
        _ayarlist.append("ayar|ogrencizilseviye|"+ogrenciZilSeviyeLineEdit->text());
        _ayarlist.append("ayar|ogretmenzilseviye|"+ogretmenZilSeviyeLineEdit->text());
        _ayarlist.append("ayar|cikiszilseviye|"+cikisZilSeviyeLineEdit->text());
        _ayarlist.append("ayar|istiklalzilseviye|"+istiklalZilSeviyeLineEdit->text());
        _ayarlist.append("ayar|istiklalsaygizilseviye|"+saygiIstiklalZilSeviyeLineEdit->text());
        _ayarlist.append("ayar|sirenzilseviye|"+sirenZilSeviyeLineEdit->text());
        _ayarlist.append("ayar|muzikyayinseviye|"+muzikYayinZilSeviyeLineEdit->text());
        _ayarlist.append("ayar|tenefusMuzikYayinState|"+QString::number(tenefusMuzikYayinState));
        _ayarlist.append("ayar|oglenMuzikYayinState|"+QString::number(oglenMuzikYayinState));
        _ayarlist.append("ayar|muzikklasor|"+muzikLineEdit->text());
        _ayarlist.append("ayar|molasuresi|"+molaSuresiTimeEdit->text());
        _ayarlist.append("ayar|moladerssaati|"+molaDersSaatiLineEdit->text());
        /// listToFile(_ayarlist,"e-zil.conf");
        //MainWindow(QWidget *parent);

        QStringList listconf=fileToList("e-zil.conf");
        listconf=listMerge(_ayarlist,listconf,0);
        listToFile(listconf,"e-zil.conf");
        ayarlist=listGetList(fileToList("e-zil.conf"), "ayar",0);//0 sütun bilgisi olan güne göre list
        init();
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

    QCheckBox *tenefusMuzikYayincb = new QCheckBox("Tenefüste Müzik Yayını Yapılsın!",ayarPage);
//QFont ff( "Arial", 8, QFont::Normal);
//tenefusMuzikYayincb->setFont(ff);
if(listGetLine(ayarlist,"tenefusMuzikYayinState")!="")
    tenefusMuzikYayinState=listGetLine(ayarlist,"tenefusMuzikYayinState").split("|")[2].toInt();

tenefusMuzikYayincb->setChecked(tenefusMuzikYayinState);
connect(tenefusMuzikYayincb, &QCheckBox::clicked, [=]() {
    if(tenefusMuzikYayincb->checkState()==Qt::Checked)
    {
        tenefusMuzikYayinState=true;

    }
    if(tenefusMuzikYayincb->checkState()==Qt::Unchecked)
    {
       tenefusMuzikYayinState=false;
    }

});

QCheckBox *oglenMuzikYayincb = new QCheckBox("Mola Arası Müzik Yayını Yapılsın!",ayarPage);
//QFont ff( "Arial", 8, QFont::Normal);
//tenefusMuzikYayincb->setFont(ff);
if(listGetLine(ayarlist,"oglenMuzikYayinState")!="")
    oglenMuzikYayinState=listGetLine(ayarlist,"oglenMuzikYayinState").split("|")[2].toInt();

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

    auto layout = new QGridLayout(ayarPage);
    layout->setContentsMargins(0, 0, 0,0);
   // layout->setVerticalSpacing(5);
   // layout->setColumnMinimumWidth(0, 37);
    //layout->addWidget(adLabel, 2,0,1,2);
    layout->addWidget(torenZilButton, 5,0,1,1);
    layout->addWidget(torenZilLineEdit, 5,1,1,3);
    layout->addWidget(torenZilFileSelectButton, 5,4,1,1);
    layout->addWidget(new QLabel("Ses %") , 5,5,1,1);
    layout->addWidget(torenZilSeviyeLineEdit, 5,6,1,1);

    layout->addWidget(ogrenciZilButton, 10,0,1,1);
    layout->addWidget(ogrenciZilLineEdit, 10,1,1,3);
    layout->addWidget(ogrenciZilFileSelectButton, 10,4,1,1);
    layout->addWidget(new QLabel("Ses %") , 10,5,1,1);
    layout->addWidget(ogrenciZilSeviyeLineEdit, 10,6,1,1);

    layout->addWidget(ogretmenZilButton, 15,0,1,1);
    layout->addWidget(ogretmenZilLineEdit, 15,1,1,3);
    layout->addWidget(ogretmenZilFileSelectButton, 15,4,1,1);
    layout->addWidget(new QLabel("Ses %") , 15,5,1,1);
    layout->addWidget(ogretmenZilSeviyeLineEdit, 15,6,1,1);


    layout->addWidget(cikisZilButton, 20,0,1,1);
    layout->addWidget(cikisZilLineEdit, 20,1,1,3);
    layout->addWidget(cikisZilFileSelectButton, 20,4,1,1);
    layout->addWidget(new QLabel("Ses %") , 20,5,1,1);
    layout->addWidget(cikisZilSeviyeLineEdit, 20,6,1,1);

    layout->addWidget(istiklalZilButton, 25,0,1,1);
    layout->addWidget(istiklalZilLineEdit, 25,1,1,3);
    layout->addWidget(istiklalZilFileSelectButton, 25,4,1,1);
    layout->addWidget(new QLabel("Ses %") , 25,5,1,1);
    layout->addWidget(istiklalZilSeviyeLineEdit, 25,6,1,1);

    layout->addWidget(saygiIstiklalZilButton, 30,0,1,1);
    layout->addWidget(saygiIstiklalZilLineEdit, 30,1,1,3);
    layout->addWidget(saygiIstiklalZilFileSelectButton, 30,4,1,1);
    layout->addWidget(new QLabel("Ses %") , 30,5,1,1);
    layout->addWidget(saygiIstiklalZilSeviyeLineEdit, 30,6,1,1);

    layout->addWidget(sirenZilButton, 35,0,1,1);
    layout->addWidget(sirenZilLineEdit, 35,1,1,3);
    layout->addWidget(sirenZilFileSelectButton, 35,4,1,1);
    layout->addWidget(new QLabel("Ses %") , 35,5,1,1);
    layout->addWidget(sirenZilSeviyeLineEdit, 35,6,1,1);

    layout->addWidget(muzikYayinZilButton,36,0,1,1);
    layout->addWidget(muzikLineEdit, 36,1,1,3);
    layout->addWidget(muzikFileSelectButton, 36,4,1,1);
    layout->addWidget(new QLabel("Ses %") , 36,5,1,1);
    layout->addWidget(muzikYayinZilSeviyeLineEdit, 36,6,1,1);

    layout->addWidget(new QLabel("Öğle Öncesi Ders Sayısı"),38,0,1,1);
    layout->addWidget(molaDersSaatiLineEdit, 38,1,1,3);
    layout->addWidget(new QLabel("Mola Süresi") , 38,4,1,2);
    layout->addWidget(molaSuresiTimeEdit, 38,6,1,1);






    layout->addWidget(new QLabel("H. İçi/sonu Pc Kapatma Saati"),40,0,1,1);
    layout->addWidget(hiPcKapatTimeEdit, 40,1,1,2);
    layout->addWidget(hsPcKapatTimeEdit, 40,3,1,2);
    //layout->addWidget(,37,0,1,1);
  //  layout->addWidget(hsPcKapatTimeEdit, 37,1,1,1);


    layout->addWidget(new QLabel("Müzik Yayın Başla/Dur Saati"),45,0,1,1);
    layout->addWidget(muzikBaslamaTimeEdit, 45,1,1,2);
    layout->addWidget(muzikSonTimeEdit, 45,3,1,2);

    layout->addWidget(oglenMuzikYayincb, 46,1,1,5);
    layout->addWidget(tenefusMuzikYayincb, 47,1,1,5);

    layout->addWidget(durZilButton,50,1,1,2);
    layout->addWidget(ayarKaydetButton,50,3,1,3);
  //  layout->addWidget(bilgiAlButton,45,3,1,4);

  //  layout->addWidget(new QLabel("<font size=1>Okullara Zil Sistemi için Yazılmıştır.</font>"),50,0,1,1,Qt::AlignHCenter);

//layout->setColumnStretch(6, 255);

    return ayarPage;
}
#endif // AYAR_H
