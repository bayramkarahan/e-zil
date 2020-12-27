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

QWidget *MainWindow::ayar()
{

    QWidget *ayarPage=new QWidget();
    /*******************************************************/
    QStringList ayarlst=fileToList("e-zil.conf");
    player = new QMediaPlayer(nullptr, QMediaPlayer::StreamPlayback);
    /********************************************************/
    QPushButton *ogrenciZilButton= new QPushButton;
    ogrenciZilButton->setFixedSize(170, 30);
    ogrenciZilButton->setIconSize(QSize(150,30));
    ogrenciZilButton->setText("Öğrenci Zil Çal");
    ogrenciZilButton->setStyleSheet("Text-align:center");
    //ogrenciZilButton->setFlat(true);
    QLineEdit *ogrenciZilLineEdit=new QLineEdit(ayarPage);
    ogrenciZilLineEdit->resize(500,25);
    if(listGetLine(ayarlst,"ogrencizil")!="")
        ogrenciZilLineEdit->setText(listGetLine(ayarlst,"ogrencizil").split("|")[1]);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(ogrenciZilButton, &QPushButton::clicked, [=]() {
        system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false");
        system("sleep 1");
        system("pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo 80000");

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
    /************************************************************************/

    QPushButton *ogretmenZilButton= new QPushButton;
    ogretmenZilButton->setFixedSize(170, 30);
    ogretmenZilButton->setIconSize(QSize(150,30));
    ogretmenZilButton->setText("Öğretmen Zil Çal");
    ogretmenZilButton->setStyleSheet("Text-align:center");
  //  ogretmenZilButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));
    QLineEdit *ogretmenZilLineEdit=new QLineEdit;
     if(listGetLine(ayarlst,"ogretmenzil")!="")
        ogretmenZilLineEdit->setText(listGetLine(ayarlst,"ogretmenzil").split("|")[1]);

    connect(ogretmenZilButton, &QPushButton::clicked, [=]() {
        system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false");
        system("sleep 1");

        system("pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo 80000");

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
    if(listGetLine(ayarlst,"cikiszil")!="")
       cikisZilLineEdit->setText(listGetLine(ayarlst,"cikiszil").split("|")[1]);


    connect(cikisZilButton, &QPushButton::clicked, [=]() {
        system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false");
        system("sleep 1");

        system("pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo 80000");

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
    if(listGetLine(ayarlst,"istiklalzil")!="")
        istiklalZilLineEdit->setText(listGetLine(ayarlst,"istiklalzil").split("|")[1]);

    connect(istiklalZilButton, &QPushButton::clicked, [=]() {
        system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false");
        system("sleep 1");

        system("pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo 80000");

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
    if(listGetLine(ayarlst,"istiklalsaygizil")!="")
        saygiIstiklalZilLineEdit->setText(listGetLine(ayarlst,"istiklalsaygizil").split("|")[1]);

    connect(saygiIstiklalZilButton, &QPushButton::clicked, [=]() {
        system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false");
        system("sleep 1");

        system("pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo 80000");

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
    if(listGetLine(ayarlst,"sirenzil")!="")
        sirenZilLineEdit->setText(listGetLine(ayarlst,"sirenzil").split("|")[1]);

    connect(sirenZilButton, &QPushButton::clicked, [=]() {
        system("pacmd set-sink-mute alsa_output.pci-0000_00_05.0.analog-stereo false");
        system("sleep 1");

        system("pacmd set-sink-volume alsa_output.pci-0000_00_05.0.analog-stereo 80000");

       // player = new QMediaPlayer(nullptr, QMediaPlayer::StreamPlayback);
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
        if(listGetLine(ayarlst,"hipckapat")!="")
           hiPcKapatTimeEdit->setTime(QTime::fromString(listGetLine(ayarlst,"hipckapat").split("|")[1]));

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
 if(listGetLine(ayarlst,"hspckapat")!="")
    hsPcKapatTimeEdit->setTime(QTime::fromString(listGetLine(ayarlst,"hspckapat").split("|")[1]));

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
if(listGetLine(ayarlst,"muzikklasor")!="")
muzikLineEdit->setText(listGetLine(ayarlst,"muzikklasor").split("|")[1]);
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
 if(listGetLine(ayarlst,"muzikbaslama")!="")
    muzikBaslamaTimeEdit->setTime(QTime::fromString(listGetLine(ayarlst,"muzikbaslama").split("|")[1]));
 QTimeEdit *muzikSonTimeEdit=new QTimeEdit;
  if(listGetLine(ayarlst,"muzikson")!="")
     muzikSonTimeEdit->setTime(QTime::fromString(listGetLine(ayarlst,"muzikson").split("|")[1]));

        /************************************************************************/


    QPushButton *durZilButton= new QPushButton;
    durZilButton->setFixedSize(150, 30);
    durZilButton->setIconSize(QSize(150,30));
    durZilButton->setText("Zil Durdur");
    durZilButton->setStyleSheet("Text-align:left");
  //  durZilButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(durZilButton, &QPushButton::clicked, [=]() {
     //   if(player->mediaStatus()==QMediaPlayer::PlayingState)
            player->stop();

 });


    QPushButton *ayarKaydetButton= new QPushButton;
    ayarKaydetButton->setFixedSize(150, 30);
    ayarKaydetButton->setIconSize(QSize(150,30));
    ayarKaydetButton->setText("Ayarları Kaydet");
    ayarKaydetButton->setStyleSheet("Text-align:left");
  //  ayarKaydetButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(ayarKaydetButton, &QPushButton::clicked, [=]() {
     //   if(player->mediaStatus()==QMediaPlayer::PlayingState)
           // player->stop();
        QStringList ayarlist;
        ayarlist.append("ogrencizil|"+ogrenciZilLineEdit->text());
        ayarlist.append("ogretmenzil|"+ogretmenZilLineEdit->text());
        ayarlist.append("cikiszil|"+cikisZilLineEdit->text());
        ayarlist.append("istiklalzil|"+istiklalZilLineEdit->text());
        ayarlist.append("istiklalsaygizil|"+saygiIstiklalZilLineEdit->text());
        ayarlist.append("sirenzil|"+sirenZilLineEdit->text());
        ayarlist.append("hipckapat|"+hiPcKapatTimeEdit->text());
        ayarlist.append("hspckapat|"+hsPcKapatTimeEdit->text());
        ayarlist.append("muzikbaslama|"+muzikBaslamaTimeEdit->text());
        ayarlist.append("muzikson|"+muzikSonTimeEdit->text());
        ayarlist.append("muzikklasor|"+muzikLineEdit->text());

        listToFile(ayarlist,"e-zil.conf");
        //MainWindow(QWidget *parent);
        init();
 });

    QPushButton *bilgiAlButton= new QPushButton;
    bilgiAlButton->setFixedSize(150, 30);
    bilgiAlButton->setIconSize(QSize(150,30));
    bilgiAlButton->setText("Hakkında");
    bilgiAlButton->setStyleSheet("Text-align:center");
  //  ayarKaydetButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(bilgiAlButton, &QPushButton::clicked, [=]() {// auto widget = new QWidget;

        QMessageBox::information(this,"E-Zil 1.0",
                                 "Bu Uygulama Okullarda Zil Sisteminde Kullanılmak için Yazılmıştır."
                                 "\n"
                                 "\n*****************************************************************************"
                                 "\n   Copyright (C) 2020 by Bayram KARAHAN                                     "
                                 "\n   <bayramk@gmail.com>  <www.bayramkarahan.blogspot.com>                                                    "
                                 "\n                                                                           "
                                 "\n   This program is free software; you can redistribute it and/or modify    "
                                 "\n   it under the terms of the GNU General Public License as published by    "
                                 "\n   the Free Software Foundation; either version 3 of the License, or       "
                                 "\n   (at your option) any later version.                                     "
                                 "\n                                                                           "
                                 "\n   This program is distributed in the hope that it will be useful,         "
                                 "\n   but WITHOUT ANY WARRANTY; without even the implied warranty of          "
                                 "\n   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           "
                                 "\n   GNU General Public License for more details.                            "
                                 "\n                                                                           "
                                 "\n   You should have received a copy of the GNU General Public License       "
                                 "\n   along with this program; if not, write to the                          "
                                 "\n   Free Software Foundation, Inc.,                                         "
                                 "\n   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .          "
                                 "\n****************************************************************************"
                                 "\n"
                                 "\n");
    });

    auto layout = new QGridLayout(ayarPage);
    layout->setContentsMargins(0, 0, 0,0);
    layout->setVerticalSpacing(5);
    layout->setColumnMinimumWidth(0, 37);
    //layout->addWidget(adLabel, 2,0,1,2);
    layout->addWidget(ogrenciZilButton, 10,0,1,1);
    layout->addWidget(ogrenciZilLineEdit, 10,1,1,5);
    layout->addWidget(ogrenciZilFileSelectButton, 10,6,1,1);

    layout->addWidget(ogretmenZilButton, 15,0,1,1);
    layout->addWidget(ogretmenZilLineEdit, 15,1,1,5);
    layout->addWidget(ogretmenZilFileSelectButton, 15,6,1,1);

    layout->addWidget(cikisZilButton, 20,0,1,1);
    layout->addWidget(cikisZilLineEdit, 20,1,1,5);
    layout->addWidget(cikisZilFileSelectButton, 20,6,1,1);

    layout->addWidget(istiklalZilButton, 25,0,1,1);
    layout->addWidget(istiklalZilLineEdit, 25,1,1,5);
    layout->addWidget(istiklalZilFileSelectButton, 25,6,1,1);

    layout->addWidget(saygiIstiklalZilButton, 30,0,1,1);
    layout->addWidget(saygiIstiklalZilLineEdit, 30,1,1,5);
    layout->addWidget(saygiIstiklalZilFileSelectButton, 30,6,1,1);

    layout->addWidget(sirenZilButton, 35,0,1,1);
    layout->addWidget(sirenZilLineEdit, 35,1,1,5);
    layout->addWidget(sirenZilFileSelectButton, 35,6,1,1);
    layout->addWidget(new QLabel("Haf. İçi Pc Kapatma Saati"),36,0,1,1);
    layout->addWidget(hiPcKapatTimeEdit, 36,1,1,1);

    layout->addWidget(new QLabel("Haf. Sonu Pc Kapatma Saati"),37,0,1,1);
    layout->addWidget(hsPcKapatTimeEdit, 37,1,1,1);

    layout->addWidget(new QLabel("Müzik Yayın Klasörü"),38,0,1,1);
    layout->addWidget(muzikLineEdit, 38,1,1,5);
    layout->addWidget(muzikFileSelectButton, 38,6,1,1);

    layout->addWidget(new QLabel("Müzik Başlama/Bitiş Saati"),39,0,1,1);
    layout->addWidget(muzikBaslamaTimeEdit, 39,1,1,2);
    layout->addWidget(muzikSonTimeEdit, 39,3,1,2);

    layout->addWidget(durZilButton,40,0,1,2);
    layout->addWidget(ayarKaydetButton,45,0,1,3);
    layout->addWidget(bilgiAlButton,45,3,1,4);

  //  layout->addWidget(new QLabel("<font size=1>Okullara Zil Sistemi için Yazılmıştır.</font>"),50,0,1,1,Qt::AlignHCenter);

layout->setColumnStretch(6, 255);

    return ayarPage;
}
#endif // AYAR_H
