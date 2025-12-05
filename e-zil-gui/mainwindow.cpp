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

#ifdef Q_OS_LINUX
   // qDebug()<< "Linux version";
      localDir="/usr/share/e-zil/";
#endif

#ifdef Q_OS_WIN
   // qDebug()<< "Windows version";
     localDir = QCoreApplication::applicationDirPath() + "/";
#endif





   // wl=new QWidgetAction(this);
    timer1.setSingleShot(true);
    connect(&timer1, SIGNAL(timeout()), &loop, SLOT(quit()));
  //  connect(this, SIGNAL(replayReceived()), &loop, SLOT(quit()));
        // App icon
      auto appIcon = QIcon(":/icons/e-zil.svg");
        this->setWindowIcon(appIcon);



      /**********************form ayarları yapıldı***********************/
      QSize screenSize = qApp->screens()[0]->size();
     // qDebug()<<screenSize.width()/65<<screenSize.height()/35;
      boy=screenSize.width()/65;
     en=boy;

      //this->resize(500,650);
      setFixedWidth(500);
      setFixedHeight(640);
      setWindowTitle("e-zil");
      QRect screenGeometry = QApplication::desktop()->screenGeometry();
      int x = (screenGeometry.width()/2 - this->width()/2);
      int y = (screenGeometry.height() - this->height()) / 2;
      this->move(x, y);
      this->setStyleSheet("background-color: #dfdfdf;");

      tw=new QTabWidget(this);
      tw->resize(this->width(),this->height());
      /*************************SZS ekranı*******************************************/
      player = new QMediaPlayer(nullptr, QMediaPlayer::StreamPlayback);
      player->setVolume(70);

widgetShow();


}

MainWindow::~MainWindow()
{
  //  delete ui;
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

void  MainWindow::SZSgizle()
{
     qDebug()<<"widget gizle..";
    SZSState=false;
     DatabaseHelper *db=new DatabaseHelper(localDir+"e-zil.json");
     QJsonArray ayarlarliste = db->Ara("recordtype", "settings");
     QJsonObject ayarlar;

     if (!ayarlarliste.isEmpty()) {
         ayarlar = ayarlarliste.first().toObject();
     }
     if (ayarlar.contains("SZSState"))
         SZSState=ayarlar["SZSState"].toBool();
     ayarlar["SZSState"]=false;
     db->Ekle(ayarlar);
}
void  MainWindow::SZSgoster()
{
//widget->show();
    qDebug()<<"widget göster..";
    SZSState=true;
    DatabaseHelper *db=new DatabaseHelper(localDir+"e-zil.json");
    QJsonArray ayarlarliste = db->Ara("recordtype", "settings");
    QJsonObject ayarlar;

    if (!ayarlarliste.isEmpty()) {
        ayarlar = ayarlarliste.first().toObject();
    }
    if (ayarlar.contains("SZSState"))
        SZSState=ayarlar["SZSState"].toBool();
    ayarlar["SZSState"]=true;
    db->Ekle(ayarlar);
}
void  MainWindow::about()
{
    QSize screenSize = qApp->screens()[0]->size();
   // qDebug()<<screenSize.width()/65<<screenSize.height()/35;

    QWidget *hk=hakkinda();

    hk->show();
    hk->move(screenSize.width()/2-hk->width()/2,screenSize.height()/2-hk->height()/2);
     hk->setWindowTitle("Hakkında");
     auto appIcon = QIcon(":/icons/e-zil.svg");
     hk->setWindowIcon(appIcon);
}
void  MainWindow::widgetShow()
{

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


void MainWindow::onemliGunSlot()
{
    /*
   // qDebug()<<"ayar click";
    QString font="12";
    QDialog * d = new QDialog();
    d->setStyleSheet("font-size:"+QString::number(font.toInt()-2)+"px;");
    auto appIcon = QIcon(":/icons/e-zil.svg");
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
   /*twl=new QTableWidget;
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
*/
}

void MainWindow::webTableCellDoubleClicked(int iRow, int iColumn)
{/*
     QString webadres= twl->item(iRow, 0)->text();
     QStringList list=fileToList("gunlist");
/******************************************************************/
    //QMessageBox::StandardButton reply;
    // reply = QMessageBox::question(this, "Uyarı", "Bilgisayar Silinecek! Emin misiniz?",
      //                             QMessageBox::Yes|tr(QMessageBox::No);
   /*  QMessageBox messageBox(this);
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

*/
}
