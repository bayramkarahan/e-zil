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

bool MainWindow::dosyaVarmi(QString dosya)
{
    FileCrud *filecdr=new FileCrud();
    filecdr->dosya=localDir+dosya;

    if (!filecdr->fileExists())
    {
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
 //   qDebug()<<"ayar";
 //   init();
//burada ayarlar bölümü düzenleniyor yeni3
    QWidget *ayarPage=new QWidget();
    ayarPage->setFixedWidth(500);
    ayarPage->setFixedHeight(600);
    /*******************************************************/
    //QStringList ayarlst=listGetList(fileToList("e-zil.conf"), "ayar",0);//0 sütun bilgisi olan güne göre listconf listesinden filitreleniyor
   // player = new QMediaPlayer(nullptr, QMediaPlayer::StreamPlayback);
    /**********************Tören Giriş**********************************/

    QToolButton *torenZilButton= new QToolButton;
   // torenZilButton->setFixedSize(170, 30);
    //torenZilButton->setIconSize(QSize(150,30));
    torenZilButton->setText("Sabah Töreni Zili Çal");
    torenZilButton->setStyleSheet("Text-align:center");


    QLineEdit *torenZilLineEdit=new QLineEdit(ayarPage);
    //torenZilLineEdit->resize(500,25);
    if(listGetLine(ayarlist,"torenzil")!="")
        torenZilLineEdit->setText(listGetLine(ayarlist,"torenzil").split("|")[2]);

    QLineEdit *torenZilSeviyeLineEdit=new QLineEdit(ayarPage);
    torenZilSeviyeLineEdit->setFixedWidth(30);
    torenZilSeviyeLineEdit->setText("80");
    if(listGetLine(ayarlist,"torenzilseviye")!="")
        torenZilSeviyeLineEdit->setText(listGetLine(ayarlist,"torenzilseviye").split("|")[2]);


    connect(torenZilButton, &QPushButton::clicked, [=]() {
        if(!dosyaVarmi("e-zil.conf")) return;

        QString deger=listGetLine(ayarlist,"torenzilseviye").split("|")[2];
       player->setVolume(deger.toInt());
        QFile* file = new QFile(torenZilLineEdit->text());
        qDebug()<<"Tören zili çalınıyor.."<<torenZilLineEdit->text();
        if (file->open(QFile::ReadOnly)) {
            player->setMedia(QMediaContent(), file);

                file->seek(0);
            player->play();
        }

    });
/************************************************************************/
    QPushButton *torenZilFileSelectButton= new QPushButton;
    torenZilFileSelectButton->setFixedWidth(20);;
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
  //  ogrenciZilButton->setFixedSize(170, 30);
   // ogrenciZilButton->setIconSize(QSize(150,30));
    ogrenciZilButton->setText("Öğrenci Zil Çal");
    ogrenciZilButton->setStyleSheet("Text-align:center");
    //ogrenciZilButton->setFlat(true);
    QLineEdit *ogrenciZilLineEdit=new QLineEdit(ayarPage);
   // ogrenciZilLineEdit->resize(500,25);
    if(listGetLine(ayarlist,"ogrencizil")!="")
        ogrenciZilLineEdit->setText(listGetLine(ayarlist,"ogrencizil").split("|")[2]);

    QLineEdit *ogrenciZilSeviyeLineEdit=new QLineEdit(ayarPage);
     ogrenciZilSeviyeLineEdit->setFixedWidth(30);
    ogrenciZilSeviyeLineEdit->setText("80");
    if(listGetLine(ayarlist,"ogrencizilseviye")!="")
        ogrenciZilSeviyeLineEdit->setText(listGetLine(ayarlist,"ogrencizilseviye").split("|")[2]);

    connect(ogrenciZilButton, &QPushButton::clicked, [=]() {

        if(!dosyaVarmi("e-zil.conf")) return;

         QString deger=listGetLine(ayarlist,"ogrencizilseviye").split("|")[2];
        player->setVolume(deger.toInt());
        QFile* file = new QFile(ogrenciZilLineEdit->text());
        if (file->open(QFile::ReadOnly)) {
             qDebug()<<"Öğrenci zili çalınıyor..";
             player->setMedia(QMediaContent(), file);
            file->seek(0);
            player->play();


        }
    });
/************************************************************************/
    QPushButton *ogrenciZilFileSelectButton= new QPushButton;
    ogrenciZilFileSelectButton->setFixedWidth(20);
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
   // ogretmenZilButton->setFixedSize(170, 30);
   // ogretmenZilButton->setIconSize(QSize(150,30));
    ogretmenZilButton->setText("Öğretmen Zil Çal");
    ogretmenZilButton->setStyleSheet("Text-align:center");
  //  ogretmenZilButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));
    QLineEdit *ogretmenZilLineEdit=new QLineEdit;
     if(listGetLine(ayarlist,"ogretmenzil")!="")
        ogretmenZilLineEdit->setText(listGetLine(ayarlist,"ogretmenzil").split("|")[2]);

     QLineEdit *ogretmenZilSeviyeLineEdit=new QLineEdit;
     ogretmenZilSeviyeLineEdit->setFixedWidth(30);
     ogretmenZilSeviyeLineEdit->setText("80");
      if(listGetLine(ayarlist,"ogretmenzilseviye")!="")
         ogretmenZilSeviyeLineEdit->setText(listGetLine(ayarlist,"ogretmenzilseviye").split("|")[2]);

      connect(ogretmenZilButton, &QPushButton::clicked, [=]() {
          if(!dosyaVarmi("e-zil.conf")) return;
          QString deger=listGetLine(ayarlist,"ogretmenzilseviye").split("|")[2];
          player->setVolume(deger.toInt());
          QFile* file = new QFile(ogretmenZilLineEdit->text());
          if (file->open(QFile::ReadOnly)) {
              player->setMedia(QMediaContent(), file);
              file->seek(0);
              player->play();
          }

      });
    /************************************************************************/
        QPushButton *ogretmenZilFileSelectButton= new QPushButton;
        ogretmenZilFileSelectButton->setFixedWidth(20);
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
    if(listGetLine(ayarlist,"cikiszil")!="")
       cikisZilLineEdit->setText(listGetLine(ayarlist,"cikiszil").split("|")[2]);

    QLineEdit *cikisZilSeviyeLineEdit=new QLineEdit;
    cikisZilSeviyeLineEdit->setFixedWidth(30);
    cikisZilSeviyeLineEdit->setText("80");
    if(listGetLine(ayarlist,"cikiszilseviye")!="")
       cikisZilSeviyeLineEdit->setText(listGetLine(ayarlist,"cikiszilseviye").split("|")[2]);

    connect(cikisZilButton, &QPushButton::clicked, [=]() {
        if(!dosyaVarmi("e-zil.conf")) return;
        QString deger=listGetLine(ayarlist,"cikiszilseviye").split("|")[2];
        player->setVolume(deger.toInt());
        QFile* file = new QFile(cikisZilLineEdit->text());
        if (file->open(QFile::ReadOnly)) {
            player->setMedia(QMediaContent(), file);
            file->seek(0);
            player->play();

        }
    });
    /************************************************************************/
        QPushButton *cikisZilFileSelectButton= new QPushButton;
        cikisZilFileSelectButton->setFixedWidth(20);
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
    //istiklalZilButton->setFixedSize(170, 30);
   // istiklalZilButton->setIconSize(QSize(150,30));
    istiklalZilButton->setText("İstiklal Marşı Çal");
    istiklalZilButton->setStyleSheet("Text-align:center");
   // istiklalZilButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));
    QLineEdit *istiklalZilLineEdit=new QLineEdit;
    if(listGetLine(ayarlist,"istiklalzil")!="")
        istiklalZilLineEdit->setText(listGetLine(ayarlist,"istiklalzil").split("|")[2]);

    QLineEdit *istiklalZilSeviyeLineEdit=new QLineEdit;
    istiklalZilSeviyeLineEdit->setFixedWidth(30);
    istiklalZilSeviyeLineEdit->setText("80");
    if(listGetLine(ayarlist,"istiklalzilseviye")!="")
        istiklalZilSeviyeLineEdit->setText(listGetLine(ayarlist,"istiklalzilseviye").split("|")[2]);

    connect(istiklalZilButton, &QPushButton::clicked, [=]() {
        if(!dosyaVarmi("e-zil.conf")) return;
        QString deger=listGetLine(ayarlist,"istiklalzilseviye").split("|")[2];
        player->setVolume(deger.toInt());

        QFile* file = new QFile(istiklalZilLineEdit->text());
        if (file->open(QFile::ReadOnly)) {
            player->setMedia(QMediaContent(), file);
            file->seek(0);
            player->play();
        }
    });
    /************************************************************************/
        QPushButton *istiklalZilFileSelectButton= new QPushButton;
        istiklalZilFileSelectButton->setFixedWidth(20);
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
   // saygiIstiklalZilButton->setFixedSize(170, 30);
   // saygiIstiklalZilButton->setIconSize(QSize(150,30));
    saygiIstiklalZilButton->setText("Saygı+İstiklal Marşı Çal");
    saygiIstiklalZilButton->setStyleSheet("Text-align:center");
    //saygiIstiklalZilButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));
    QLineEdit *saygiIstiklalZilLineEdit=new QLineEdit;
    if(listGetLine(ayarlist,"istiklalsaygizil")!="")
        saygiIstiklalZilLineEdit->setText(listGetLine(ayarlist,"istiklalsaygizil").split("|")[2]);

    QLineEdit *saygiIstiklalZilSeviyeLineEdit=new QLineEdit;
    saygiIstiklalZilSeviyeLineEdit->setFixedWidth(30);
    saygiIstiklalZilSeviyeLineEdit->setText("80");
    if(listGetLine(ayarlist,"istiklalsaygizilseviye")!="")
        saygiIstiklalZilSeviyeLineEdit->setText(listGetLine(ayarlist,"istiklalsaygizilseviye").split("|")[2]);

    connect(saygiIstiklalZilButton, &QPushButton::clicked, [=]() {
        if(!dosyaVarmi("e-zil.conf")) return;
        QString deger=listGetLine(ayarlist,"istiklalsaygizilseviye").split("|")[2];
        player->setVolume(deger.toInt());
        QFile* file = new QFile(saygiIstiklalZilLineEdit->text());
        if (file->open(QFile::ReadOnly)) {
            player->setMedia(QMediaContent(), file);
            file->seek(0);
            player->play();
        }

    });
    /************************************************************************/
        QPushButton *saygiIstiklalZilFileSelectButton= new QPushButton;
        saygiIstiklalZilFileSelectButton->setFixedWidth(20);
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
   // sirenZilButton->setFixedSize(170, 30);
   // sirenZilButton->setIconSize(QSize(150,30));
    sirenZilButton->setText("Siren Çal");
    sirenZilButton->setStyleSheet("Text-align:center");
   // sirenZilButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));
    QLineEdit *sirenZilLineEdit=new QLineEdit;
    if(listGetLine(ayarlist,"sirenzil")!="")
        sirenZilLineEdit->setText(listGetLine(ayarlist,"sirenzil").split("|")[2]);

    QLineEdit *sirenZilSeviyeLineEdit=new QLineEdit;
    sirenZilSeviyeLineEdit->setFixedWidth(30);
    sirenZilSeviyeLineEdit->setText("80");
    if(listGetLine(ayarlist,"sirenzilseviye")!="")
        sirenZilSeviyeLineEdit->setText(listGetLine(ayarlist,"sirenzilseviye").split("|")[2]);

    connect(sirenZilButton, &QPushButton::clicked, [=]() {
        if(!dosyaVarmi("e-zil.conf")) return;
    QString deger=listGetLine(ayarlist,"sirenzilseviye").split("|")[2];
    player->setVolume(deger.toInt());

        QFile* file = new QFile(sirenZilLineEdit->text());
        if (file->open(QFile::ReadOnly)) {
            player->setMedia(QMediaContent(), file);
            file->seek(0);
            player->play();
        }


    });
    /************************************************************************/
        QPushButton *sirenZilFileSelectButton= new QPushButton;
        sirenZilFileSelectButton->setFixedWidth(20);
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
       // dersSonuPcKapatButton->setFixedSize(200, 30);
      //  dersSonuPcKapatButton->setIconSize(QSize(150,30));
        dersSonuPcKapatButton->setText("Hafta İçi Bilgisayar Kapat");
        dersSonuPcKapatButton->setStyleSheet("Text-align:center");
       // dersSonuPcKapatButton->setFlat(true);
       // dersSonuPcKapatButton->setIcon(QIcon(":icons/saveprofile.png"));
        QTimeEdit *dersSonuPcKapatTimeEdit=new QTimeEdit;
        if(listGetLine(ayarlist,"derssonupckapat")!="")
           dersSonuPcKapatTimeEdit->setTime(saniyeToSaat(listGetLine(ayarlist,"derssonupckapat").split("|")[2]));

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
/************************************************************************/
QPushButton *molaPcKapatButton= new QPushButton;
//molaPcKapatButton->setIconSize(QSize(150,30));
molaPcKapatButton->setText("Hafta Sonu Bilgisayar Kapat");
molaPcKapatButton->setStyleSheet("Text-align:center");
// molaPcKapatButton->setFlat(true);
// molaPcKapatButton->setIcon(QIcon(":icons/saveprofile.png"));
QTimeEdit *molaPcKapatTimeEdit=new QTimeEdit;
 if(listGetLine(ayarlist,"molapckapat")!="")
    molaPcKapatTimeEdit->setTime(saniyeToSaat(listGetLine(ayarlist,"molapckapat").split("|")[2]));

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

if(listGetLine(ayarlist,"kapatKomut")!="")
    if(listGetLine(ayarlist,"kapatKomut").split("|")[2]!="")kapatKomutEdit->setText(listGetLine(ayarlist,"kapatKomut").split("|")[2]);

/************************************************************************/


QLineEdit *muzikLineEdit=new QLineEdit;
if(listGetLine(ayarlist,"muzikklasor")!="")
muzikLineEdit->setText(listGetLine(ayarlist,"muzikklasor").split("|")[2]);
/************************************************************************/
QPushButton *muzikFileSelectButton= new QPushButton;
//muzikFileSelectButton->setFixedSize(20, 30);
muzikFileSelectButton->setFixedWidth(20);
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
 if(listGetLine(ayarlist,"muzikbaslama")!="")
    muzikBaslamaTimeEdit->setTime(saniyeToSaat(listGetLine(ayarlist,"muzikbaslama").split("|")[2]));

 QTimeEdit *muzikSonTimeEdit=new QTimeEdit;
 ///muzikSonTimeEdit->setFixedSize(65, 30);
  if(listGetLine(ayarlist,"muzikson")!="")
    muzikSonTimeEdit->setTime(saniyeToSaat(listGetLine(ayarlist,"muzikson").split("|")[2]));

  QLineEdit *muzikYayinZilSeviyeLineEdit=new QLineEdit;
  muzikYayinZilSeviyeLineEdit->setFixedWidth(30);
  muzikYayinZilSeviyeLineEdit->setText("80");
   if(listGetLine(ayarlist,"muzikyayinseviye")!="")
      muzikYayinZilSeviyeLineEdit->setText(listGetLine(ayarlist,"muzikyayinseviye").split("|")[2]);
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
       if(!dosyaVarmi("e-zil.conf")) return;
       QString deger=listGetLine(ayarlist,"muzikyayinseviye").split("|")[2];
       player->setVolume(deger.toInt());

          if (listGetLine(ayarlist,"muzikklasor")!="")
           {
           qDebug()<<"Müzik Yayını Başladı...";

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


              player->setMedia(playlist);
              player->play();
       }

   });
        /************************************************************************/
   QTimeEdit *molaSuresiTimeEdit=new QTimeEdit;
    molaSuresiTimeEdit->setTime(QTime::fromString("01:00"));
    if(listGetLine(ayarlist,"molasuresi")!="")
       molaSuresiTimeEdit->setTime(saniyeToSaat(listGetLine(ayarlist,"molasuresi").split("|")[2]));

    QLineEdit *molaDersSaatiLineEdit=new QLineEdit;
    molaDersSaatiLineEdit->setText("4");
     if(listGetLine(ayarlist,"moladerssaati")!="")
        molaDersSaatiLineEdit->setText(listGetLine(ayarlist,"moladerssaati").split("|")[2]);

     QLineEdit *dersSayisiLineEdit=new QLineEdit;
     dersSayisiLineEdit->setText("7");
      if(listGetLine(ayarlist,"derssayisi")!="")
         dersSayisiLineEdit->setText(listGetLine(ayarlist,"derssayisi").split("|")[2]);
  /*************************************************************************************/

    QPushButton *durZilButton= new QPushButton;
   // durZilButton->setFixedSize(150, 30);
   // durZilButton->setIconSize(QSize(150,30));
    durZilButton->setText("Zil Durdur");
    durZilButton->setStyleSheet("Text-align:Center");
  //  durZilButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(durZilButton, &QPushButton::clicked, [=]() {

            player->stop();
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
        _ayarlist.append("ayar|derssonupckapat|"+saatToSaniye(dersSonuPcKapatTimeEdit->time()));
        _ayarlist.append("ayar|molapckapat|"+saatToSaniye(molaPcKapatTimeEdit->time()));
        _ayarlist.append("ayar|kapatKomut|"+kapatKomutEdit->text());

        _ayarlist.append("ayar|muzikbaslama|"+saatToSaniye(muzikBaslamaTimeEdit->time()));
        _ayarlist.append("ayar|muzikson|"+saatToSaniye(muzikSonTimeEdit->time()));
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
        _ayarlist.append("ayar|SZSState|"+QString::number(SZSState));
        _ayarlist.append("ayar|ekilitState|"+QString::number(ekilitState));
        _ayarlist.append("ayar|gunState|"+QString::number(gunState));

        _ayarlist.append("ayar|muzikklasor|"+muzikLineEdit->text());
        _ayarlist.append("ayar|molasuresi|"+saatToSaniye(molaSuresiTimeEdit->time()));
        _ayarlist.append("ayar|moladerssaati|"+molaDersSaatiLineEdit->text());
         _ayarlist.append("ayar|derssayisi|"+dersSayisiLineEdit->text());
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

QCheckBox *oglenMuzikYayincb = new QCheckBox("Müzik Yayını Yapılsın!",ayarPage);
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
/*********************Sessiz zil gösteri ayarı************************************/
QCheckBox *SZScb = new QCheckBox("Sessiz Zil Sistemi Gözüksün Mü?",ayarPage);

if(listGetLine(ayarlist,"SZSState")!="")
    SZSState=listGetLine(ayarlist,"SZSState").split("|")[2].toInt();
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
    SZSgoster();

}
if(SZScb->checkState()==Qt::Unchecked)
{
   SZSState=false;
   SZSgizle();
}

});
/********************* zil e-kilit entegrasyon ayarı************************************/
QCheckBox *ekilitcb = new QCheckBox("e-kilit ile e-zil Uygulaması Etkileşime Girsin Mi?",ayarPage);

if(listGetLine(ayarlist,"ekilitState")!="")
    ekilitState=listGetLine(ayarlist,"ekilitState").split("|")[2].toInt();
if(ekilitState)
{
   // qDebug()<<"ekilitState"<<ekilitState;
    ekilitcb->setChecked(Qt::Checked);
}
else
{
    // qDebug()<<"ekilitState"<<ekilitState;
    ekilitcb->setChecked(Qt::Unchecked);
}

connect(ekilitcb, &QCheckBox::clicked, [=]() {
if(ekilitcb->checkState()==Qt::Checked)
{
    ekilitState=true;
    ///SZSgoster();

}
if(ekilitcb->checkState()==Qt::Unchecked)
{
   ekilitState=false;
  /// SZSgizle();
}

});
/********************* önemli gün ayarı************************************/
QCheckBox *guncb = new QCheckBox("Önemli Günler Gösterilsin Mi?",ayarPage);

if(listGetLine(ayarlist,"gunState")!="")
    gunState=listGetLine(ayarlist,"gunState").split("|")[2].toInt();
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
    ///SZSgoster();

}
if(guncb->checkState()==Qt::Unchecked)
{
   gunState=false;
  /// SZSgizle();
}

});
    auto layout = new QGridLayout(ayarPage);
    layout->setContentsMargins(0, 0, 0,0);
   // layout->setVerticalSpacing(5);
   // layout->setColumnMinimumWidth(0, 37);
    //layout->addWidget(adLabel, 2,0,1,2);
    layout->addWidget(torenZilButton, 5,0,1,1);
    layout->addWidget(torenZilLineEdit, 5,1,1,2);
    layout->addWidget(torenZilFileSelectButton, 5,3,1,1);
    layout->addWidget(new QLabel("Ses %") , 5,4,1,1);
    layout->addWidget(torenZilSeviyeLineEdit, 5,5,1,1);

    layout->addWidget(ogrenciZilButton, 10,0,1,1);
    layout->addWidget(ogrenciZilLineEdit, 10,1,1,2);
    layout->addWidget(ogrenciZilFileSelectButton, 10,3,1,1);
    layout->addWidget(new QLabel("Ses %") , 10,4,1,1);
    layout->addWidget(ogrenciZilSeviyeLineEdit, 10,5,1,1);

    layout->addWidget(ogretmenZilButton, 15,0,1,1);
    layout->addWidget(ogretmenZilLineEdit, 15,1,1,2);
    layout->addWidget(ogretmenZilFileSelectButton, 15,3,1,1);
    layout->addWidget(new QLabel("Ses %") , 15,4,1,1);
    layout->addWidget(ogretmenZilSeviyeLineEdit, 15,5,1,1);


    layout->addWidget(cikisZilButton, 20,0,1,1);
    layout->addWidget(cikisZilLineEdit, 20,1,1,2);
    layout->addWidget(cikisZilFileSelectButton, 20,3,1,1);
    layout->addWidget(new QLabel("Ses %") , 20,4,1,1);
    layout->addWidget(cikisZilSeviyeLineEdit, 20,5,1,1);

    layout->addWidget(istiklalZilButton, 25,0,1,1);
    layout->addWidget(istiklalZilLineEdit, 25,1,1,2);
    layout->addWidget(istiklalZilFileSelectButton, 25,3,1,1);
    layout->addWidget(new QLabel("Ses %") , 25,4,1,1);
    layout->addWidget(istiklalZilSeviyeLineEdit, 25,5,1,1);

    layout->addWidget(saygiIstiklalZilButton, 30,0,1,1);
    layout->addWidget(saygiIstiklalZilLineEdit, 30,1,1,2);
    layout->addWidget(saygiIstiklalZilFileSelectButton, 30,3,1,1);
    layout->addWidget(new QLabel("Ses %") , 30,4,1,1);
    layout->addWidget(saygiIstiklalZilSeviyeLineEdit, 30,5,1,1);

    layout->addWidget(sirenZilButton, 35,0,1,1);
    layout->addWidget(sirenZilLineEdit, 35,1,1,2);
    layout->addWidget(sirenZilFileSelectButton, 35,3,1,1);
    layout->addWidget(new QLabel("Ses %") , 35,4,1,1);
    layout->addWidget(sirenZilSeviyeLineEdit, 35,5,1,1);

    layout->addWidget(muzikYayinZilButton,36,0,1,1);
    layout->addWidget(muzikLineEdit, 36,1,1,2);
    layout->addWidget(muzikFileSelectButton, 36,3,1,1);
    layout->addWidget(new QLabel("Ses %") , 36,4,1,1);
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
    //layout->addWidget(,37,0,1,1);
  //  layout->addWidget(hsPcKapatTimeEdit, 37,1,1,1);


    layout->addWidget(new QLabel("Müzik Y. Başla/Dur Saati"),45,0,1,1);
    layout->addWidget(muzikBaslamaTimeEdit, 45,1,1,2);
    layout->addWidget(muzikSonTimeEdit, 45,3,1,2);

    layout->addWidget(oglenMuzikYayincb, 46,0,1,7);
    layout->addWidget(tenefusMuzikYayincb, 47,0,1,7);
    layout->addWidget(SZScb, 49,0,1,7);
    layout->addWidget(ekilitcb, 50,0,1,7);
    layout->addWidget(guncb, 51,0,1,7);

    layout->addWidget(durZilButton,52,0,1,1);
    layout->addWidget(ayarKaydetButton,52,3,1,3);
   layout->addWidget(onemligunButton,55,0,1,7);
/**/
  //  layout->addWidget(new QLabel("<font size=1>Okullara Zil Sistemi için Yazılmıştır.</font>"),50,0,1,1,Qt::AlignHCenter);

//layout->setColumnStretch(6, 255);

    return ayarPage;
}
#endif // AYAR_H
