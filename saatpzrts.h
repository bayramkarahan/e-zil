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
#ifndef SAATPZRTS_H
#define SAATPZRTS_H
QWidget *MainWindow::saatpzrts(int guns)
{

    //qDebug()<<guns;
    //gn=QString::number(dt.dayOfWeek())+"s";
    //tn=QString::number(dt.dayOfWeek())+"st";
    QString gn=QString::number(guns)+"s";
    QString tn=QString::number(guns)+"st";
    QWidget *ayarPage=new QWidget();
    /*******************************************************/
    QStringList ayarlst=fileToList("e-zil.conf",QDir::homePath());

    /*********************Sabah Tören Giriş***********************************/
    QTimeEdit *s0gle=new QTimeEdit(ayarPage);

    QTimeEdit *s01gle=new QTimeEdit(ayarPage);QTimeEdit *s01ble=new QTimeEdit(ayarPage);QTimeEdit *s01cle=new QTimeEdit(ayarPage);
    QTimeEdit *s2gle=new QTimeEdit(ayarPage); QTimeEdit *s2ble=new QTimeEdit(ayarPage); QTimeEdit *s2cle=new QTimeEdit(ayarPage);
    QTimeEdit *s3gle=new QTimeEdit(ayarPage); QTimeEdit *s3ble=new QTimeEdit(ayarPage); QTimeEdit *s3cle=new QTimeEdit(ayarPage);
    QTimeEdit *s4gle=new QTimeEdit(ayarPage); QTimeEdit *s4ble=new QTimeEdit(ayarPage); QTimeEdit *s4cle=new QTimeEdit(ayarPage);
    QTimeEdit *s5gle=new QTimeEdit(ayarPage); QTimeEdit *s5ble=new QTimeEdit(ayarPage); QTimeEdit *s5cle=new QTimeEdit(ayarPage);
    QTimeEdit *s6gle=new QTimeEdit(ayarPage); QTimeEdit *s6ble=new QTimeEdit(ayarPage); QTimeEdit *s6cle=new QTimeEdit(ayarPage);
    QTimeEdit *s7gle=new QTimeEdit(ayarPage); QTimeEdit *s7ble=new QTimeEdit(ayarPage); QTimeEdit *s7cle=new QTimeEdit(ayarPage);
    QTimeEdit *s8gle=new QTimeEdit(ayarPage); QTimeEdit *s8ble=new QTimeEdit(ayarPage); QTimeEdit *s8cle=new QTimeEdit(ayarPage);
    QTimeEdit *s9gle=new QTimeEdit(ayarPage); QTimeEdit *s9ble=new QTimeEdit(ayarPage); QTimeEdit *s9cle=new QTimeEdit(ayarPage);
    QTimeEdit *s10gle=new QTimeEdit(ayarPage); QTimeEdit *s10ble=new QTimeEdit(ayarPage); QTimeEdit *s10cle=new QTimeEdit(ayarPage);
    QTimeEdit *s11gle=new QTimeEdit(ayarPage); QTimeEdit *s11ble=new QTimeEdit(ayarPage); QTimeEdit *s11cle=new QTimeEdit(ayarPage);
    QTimeEdit *s12gle=new QTimeEdit(ayarPage); QTimeEdit *s12ble=new QTimeEdit(ayarPage); QTimeEdit *s12cle=new QTimeEdit(ayarPage);
    QTimeEdit *s13gle=new QTimeEdit(ayarPage); QTimeEdit *s13ble=new QTimeEdit(ayarPage); QTimeEdit *s13cle=new QTimeEdit(ayarPage);
    QTimeEdit *s14gle=new QTimeEdit(ayarPage); QTimeEdit *s14ble=new QTimeEdit(ayarPage); QTimeEdit *s14cle=new QTimeEdit(ayarPage);

  ///  s0gle->resize(100,25);
  ///  s0gle->setDisplayFormat("hh:mm:ss");
    if(listGetLine(ayarlst,tn)!="")s0gle->setTime(QTime::fromString(listGetLine(ayarlst,tn).split("|")[1]));
    if(listGetLine(ayarlst,gn+"01")!="")s01gle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"01").split("|")[1]));
    if(listGetLine(ayarlst,gn+"01")!="")s01ble->setTime(QTime::fromString(listGetLine(ayarlst,gn+"01").split("|")[2]));
    if(listGetLine(ayarlst,gn+"01")!="")s01cle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"01").split("|")[3]));
    if(listGetLine(ayarlst,gn+"2")!="")s2gle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"2").split("|")[1]));
    if(listGetLine(ayarlst,gn+"2")!="")s2ble->setTime(QTime::fromString(listGetLine(ayarlst,gn+"2").split("|")[2]));
    if(listGetLine(ayarlst,gn+"2")!="")s2cle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"2").split("|")[3]));
    if(listGetLine(ayarlst,gn+"3")!="")s3gle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"3").split("|")[1]));
    if(listGetLine(ayarlst,gn+"3")!="")s3ble->setTime(QTime::fromString(listGetLine(ayarlst,gn+"3").split("|")[2]));
    if(listGetLine(ayarlst,gn+"3")!="")s3cle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"3").split("|")[3]));
    if(listGetLine(ayarlst,gn+"4")!="")s4gle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"4").split("|")[1]));
    if(listGetLine(ayarlst,gn+"4")!="")s4ble->setTime(QTime::fromString(listGetLine(ayarlst,gn+"4").split("|")[2]));
    if(listGetLine(ayarlst,gn+"4")!="")s4cle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"4").split("|")[3]));
    if(listGetLine(ayarlst,gn+"5")!="")s5gle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"5").split("|")[1]));
    if(listGetLine(ayarlst,gn+"5")!="")s5ble->setTime(QTime::fromString(listGetLine(ayarlst,gn+"5").split("|")[2]));
    if(listGetLine(ayarlst,gn+"5")!="")s5cle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"5").split("|")[3]));
    if(listGetLine(ayarlst,gn+"6")!="")s6gle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"6").split("|")[1]));
    if(listGetLine(ayarlst,gn+"6")!="")s6ble->setTime(QTime::fromString(listGetLine(ayarlst,gn+"6").split("|")[2]));
    if(listGetLine(ayarlst,gn+"6")!="")s6cle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"6").split("|")[3]));
    if(listGetLine(ayarlst,gn+"7")!="")s7gle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"7").split("|")[1]));
    if(listGetLine(ayarlst,gn+"7")!="")s7ble->setTime(QTime::fromString(listGetLine(ayarlst,gn+"7").split("|")[2]));
    if(listGetLine(ayarlst,gn+"7")!="")s7cle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"7").split("|")[3]));
    if(listGetLine(ayarlst,gn+"8")!="")s8gle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"8").split("|")[1]));
    if(listGetLine(ayarlst,gn+"8")!="")s8ble->setTime(QTime::fromString(listGetLine(ayarlst,gn+"8").split("|")[2]));
    if(listGetLine(ayarlst,gn+"8")!="")s8cle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"8").split("|")[3]));
    if(listGetLine(ayarlst,gn+"9")!="")s9gle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"9").split("|")[1]));
    if(listGetLine(ayarlst,gn+"9")!="")s9ble->setTime(QTime::fromString(listGetLine(ayarlst,gn+"9").split("|")[2]));
    if(listGetLine(ayarlst,gn+"9")!="")s9cle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"9").split("|")[3]));
    if(listGetLine(ayarlst,gn+"10")!="")s10gle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"10").split("|")[1]));
    if(listGetLine(ayarlst,gn+"10")!="")s10ble->setTime(QTime::fromString(listGetLine(ayarlst,gn+"10").split("|")[2]));
    if(listGetLine(ayarlst,gn+"10")!="")s10cle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"10").split("|")[3]));
    if(listGetLine(ayarlst,gn+"11")!="")s11gle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"11").split("|")[1]));
    if(listGetLine(ayarlst,gn+"11")!="")s11ble->setTime(QTime::fromString(listGetLine(ayarlst,gn+"11").split("|")[2]));
    if(listGetLine(ayarlst,gn+"11")!="")s11cle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"11").split("|")[3]));
    if(listGetLine(ayarlst,gn+"12")!="")s12gle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"12").split("|")[1]));
    if(listGetLine(ayarlst,gn+"12")!="")s12ble->setTime(QTime::fromString(listGetLine(ayarlst,gn+"12").split("|")[2]));
    if(listGetLine(ayarlst,gn+"12")!="")s12cle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"12").split("|")[3]));
    if(listGetLine(ayarlst,gn+"13")!="")s13gle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"13").split("|")[1]));
    if(listGetLine(ayarlst,gn+"13")!="")s13ble->setTime(QTime::fromString(listGetLine(ayarlst,gn+"13").split("|")[2]));
    if(listGetLine(ayarlst,gn+"13")!="")s13cle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"13").split("|")[3]));
    if(listGetLine(ayarlst,gn+"14")!="")s14gle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"14").split("|")[1]));
    if(listGetLine(ayarlst,gn+"14")!="")s14ble->setTime(QTime::fromString(listGetLine(ayarlst,gn+"14").split("|")[2]));
    if(listGetLine(ayarlst,gn+"14")!="")s14cle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"14").split("|")[3]));
  /************************ornek ders********************************/
    QTimeEdit *sgle=new QTimeEdit(ayarPage);
    sgle->resize(60,25);
    if(listGetLine(ayarlst,gn+"01")!="")sgle->setTime(QTime::fromString(listGetLine(ayarlst,"1s01").split("|")[1]));
    QTimeEdit *sble=new QTimeEdit(ayarPage);
    sble->resize(60,25);
    if(listGetLine(ayarlst,gn+"01")!="")sble->setTime(QTime::fromString(listGetLine(ayarlst,"1s01").split("|")[2]));
    QTimeEdit *scle=new QTimeEdit(ayarPage);
    scle->resize(60,25);
    if(listGetLine(ayarlst,gn+"01")!="")scle->setTime(QTime::fromString(listGetLine(ayarlst,"1s01").split("|")[3]));
    QTimeEdit *stle=new QTimeEdit(ayarPage);
    stle->resize(60,25);
    if(listGetLine(ayarlst,gn+"2")!="")stle->setTime(QTime::fromString(listGetLine(ayarlst,gn+"2").split("|")[2]));



s0gle->setDisplayFormat("hh:mm:ss");sgle->setDisplayFormat("hh:mm:ss");
sble->setDisplayFormat("hh:mm:ss");scle->setDisplayFormat("hh:mm:ss");stle->setDisplayFormat("hh:mm:ss");

s01gle->setDisplayFormat("hh:mm:ss");s01ble->setDisplayFormat("hh:mm:ss");s01cle->setDisplayFormat("hh:mm:ss");
s2gle->setDisplayFormat("hh:mm:ss");s2ble->setDisplayFormat("hh:mm:ss");s2cle->setDisplayFormat("hh:mm:ss");
s3gle->setDisplayFormat("hh:mm:ss");s3ble->setDisplayFormat("hh:mm:ss");s3cle->setDisplayFormat("hh:mm:ss");
s4gle->setDisplayFormat("hh:mm:ss");s4ble->setDisplayFormat("hh:mm:ss");s4cle->setDisplayFormat("hh:mm:ss");
s5gle->setDisplayFormat("hh:mm:ss");s5ble->setDisplayFormat("hh:mm:ss");s5cle->setDisplayFormat("hh:mm:ss");
s6gle->setDisplayFormat("hh:mm:ss");s6ble->setDisplayFormat("hh:mm:ss");s6cle->setDisplayFormat("hh:mm:ss");
s7gle->setDisplayFormat("hh:mm:ss");s7ble->setDisplayFormat("hh:mm:ss");s7cle->setDisplayFormat("hh:mm:ss");
s8gle->setDisplayFormat("hh:mm:ss");s8ble->setDisplayFormat("hh:mm:ss");s8cle->setDisplayFormat("hh:mm:ss");
s9gle->setDisplayFormat("hh:mm:ss");s9ble->setDisplayFormat("hh:mm:ss");s9cle->setDisplayFormat("hh:mm:ss");
s10gle->setDisplayFormat("hh:mm:ss");s10ble->setDisplayFormat("hh:mm:ss");s10cle->setDisplayFormat("hh:mm:ss");
s11gle->setDisplayFormat("hh:mm:ss");s11ble->setDisplayFormat("hh:mm:ss");s11cle->setDisplayFormat("hh:mm:ss");
s12gle->setDisplayFormat("hh:mm:ss");s12ble->setDisplayFormat("hh:mm:ss");s12cle->setDisplayFormat("hh:mm:ss");
s13gle->setDisplayFormat("hh:mm:ss");s13ble->setDisplayFormat("hh:mm:ss");s13cle->setDisplayFormat("hh:mm:ss");
s14gle->setDisplayFormat("hh:mm:ss");s14ble->setDisplayFormat("hh:mm:ss");s14cle->setDisplayFormat("hh:mm:ss");


QPushButton *haftaUyarlaButton= new QPushButton;
//  haftaUyarlaButton->setFixedSize(150, 30);
//haftaUyarlaButton->setIconSize(QSize(450,30));
haftaUyarlaButton->setText("Tüm Haftaya Uyarla");
haftaUyarlaButton->setStyleSheet("Text-align:center");
//  ayarKaydetButton->setFlat(true);
// kilitButton->setIcon(QIcon(":icons/saveprofile.png"));
if(guns!=1) haftaUyarlaButton->hide();
    connect(haftaUyarlaButton, &QPushButton::clicked, [=]() {

        int girissaniye,baslamasaniye,cikissaniye,tenefussaniye,gbfark,bcfark,ctfark;
        QTime sg=sgle->time();//Giriş
        QTime sb=sble->time();//Başlama
        QTime sc=scle->time();//Çıkış
        QTime st=stle->time();//tenefüs bitiş
        girissaniye=sg.hour()*60*60+sg.minute()*60+sg.second();
        baslamasaniye=sb.hour()*60*60+sb.minute()*60+sb.second();
        cikissaniye=sc.hour()*60*60+sc.minute()*60+sc.second();
        tenefussaniye=st.hour()*60*60+st.minute()*60+st.second();

        gbfark=baslamasaniye-girissaniye;
        bcfark=cikissaniye-baslamasaniye;
        ctfark=tenefussaniye-cikissaniye;
        //ctfark--;
        QStringList saathilist;
        int gecikme=10;
        saathilist.append("1st|"+s0gle->text());
        QTime anons=s01cle->time();anons=anons.addSecs(gecikme);QTime tenefus=s01cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append("1s01|"+s01gle->text()+"|"+s01ble->text()+"|"+s01cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s2cle->time();anons=anons.addSecs(gecikme);tenefus=s2cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append("1s2|"+s2gle->text()+"|"+s2ble->text()+"|"+s2cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s3cle->time();anons=anons.addSecs(gecikme);tenefus=s3cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append("1s3|"+s3gle->text()+"|"+s3ble->text()+"|"+s3cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));

        anons=s4cle->time();anons=anons.addSecs(gecikme);tenefus=s4cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append("1s4|"+s4gle->text()+"|"+s4ble->text()+"|"+s4cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s5cle->time();anons=anons.addSecs(gecikme);tenefus=s5cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append("1s5|"+s5gle->text()+"|"+s5ble->text()+"|"+s5cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s6cle->time();anons=anons.addSecs(gecikme);tenefus=s6cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append("1s6|"+s6gle->text()+"|"+s6ble->text()+"|"+s6cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s7cle->time();anons=anons.addSecs(gecikme);tenefus=s7cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append("1s7|"+s7gle->text()+"|"+s7ble->text()+"|"+s7cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s8cle->time();anons=anons.addSecs(gecikme);tenefus=s8cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append("1s8|"+s8gle->text()+"|"+s8ble->text()+"|"+s8cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s9cle->time();anons=anons.addSecs(gecikme);tenefus=s9cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append("1s9|"+s9gle->text()+"|"+s9ble->text()+"|"+s9cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s10cle->time();anons=anons.addSecs(gecikme);tenefus=s10cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append("1s10|"+s10gle->text()+"|"+s10ble->text()+"|"+s10cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s11cle->time();anons=anons.addSecs(gecikme);tenefus=s11cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append("1s11|"+s11gle->text()+"|"+s11ble->text()+"|"+s11cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s12cle->time();anons=anons.addSecs(gecikme);tenefus=s12cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append("1s12|"+s12gle->text()+"|"+s12ble->text()+"|"+s12cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s13cle->time();anons=anons.addSecs(gecikme);tenefus=s13cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append("1s13|"+s13gle->text()+"|"+s13ble->text()+"|"+s13cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s14cle->time();anons=anons.addSecs(gecikme);tenefus=s14cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append("1s14|"+s14gle->text()+"|"+s14ble->text()+"|"+s14cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));



        QStringList listconf=fileToList("e-zil.conf",QDir::homePath());

        listconf=listMerge(saathilist,listconf,0);//pazartesi
        listconf=listMerge(listReplace(saathilist, "1s", "2s", 0),listconf,0);//salı
        listconf=listMerge(listReplace(saathilist, "1s", "3s", 0),listconf,0);//çarşamba
        listconf=listMerge(listReplace(saathilist, "1s", "4s", 0),listconf,0);//perşembe
        listconf=listMerge(listReplace(saathilist, "1s", "5s", 0),listconf,0);//cuma
        listconf=listMerge(listReplace(saathilist, "1s", "6s", 0),listconf,0);//cumartesi
        listconf=listMerge(listReplace(saathilist, "1s", "7s", 0),listconf,0);//pazar

        listToFile(listconf,"e-zil.conf",QDir::homePath());
init();
          //tw->tabRemoved(3);
        tw->widget(3)->deleteLater();
        tw->widget(4)->deleteLater();
        tw->widget(5)->deleteLater();
        tw->widget(6)->deleteLater();
        tw->widget(7)->deleteLater();
        tw->widget(8)->deleteLater();
        tw->widget(9)->deleteLater();

        tw->addTab(saatpzrts(2),"Salı");
        tw->addTab(saatpzrts(3),"Çrşmb");
        tw->addTab(saatpzrts(4),"Prşmb");
        tw->addTab(saatpzrts(5),"Cuma");
        tw->addTab(saatpzrts(6),"Cmrts");
        tw->addTab(saatpzrts(7),"Pazar");
         tw->addTab(hakkinda(),"Hakkında");

});
    QPushButton *saatUyarlaButton= new QPushButton;
   /// saatUyarlaButton->setFixedSize(300, 30);
    ///saatUyarlaButton->setIconSize(QSize(450,30));
    saatUyarlaButton->setText("Tüm Saatleri Uyarla");
    saatUyarlaButton->setStyleSheet("Text-align:center");
  //  ayarKaydetButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));



    connect(saatUyarlaButton, &QPushButton::clicked, [=]() {
        int girissaniye,baslamasaniye,cikissaniye,tenefussaniye,gbfark,bcfark,ctfark;
        QTime sg=sgle->time();//Giriş
        QTime sb=sble->time();//Başlama
        QTime sc=scle->time();//Çıkış
        QTime st=stle->time();//tenefüs bitiş
        girissaniye=sg.hour()*60*60+sg.minute()*60+sg.second();
        baslamasaniye=sb.hour()*60*60+sb.minute()*60+sb.second();
        cikissaniye=sc.hour()*60*60+sc.minute()*60+sc.second();
        tenefussaniye=st.hour()*60*60+st.minute()*60+st.second();

        gbfark=baslamasaniye-girissaniye;
        bcfark=cikissaniye-baslamasaniye;
        ctfark=tenefussaniye-cikissaniye;
        int ogleArasi=0;
        if(listGetLine(ayarlist,"moladerssaati")!="")
            ogleArasi=listGetLine(ayarlist,"moladerssaati").split("|")[2].toInt();

        int molasuresi=0;
        int tmpmolasuresi=0;
        if(listGetLine(ayarlist,"molasuresi")!="")
        {
            QTime msure;
            msure=QTime::fromString(listGetLine(ayarlst,"molasuresi").split("|")[2]);
            /// molasuresi=ayarlist,"molasuresi").split("|")[2].toInt();
            molasuresi=msure.hour()*60*60+msure.minute()*60+msure.second();

        }
        /// qDebug()<<"mola:"<<molasuresi-ctfark;

        molasuresi=molasuresi-ctfark;
        tmpmolasuresi=molasuresi;
        s01gle->setTime(sg);
        if(ogleArasi==2){sg=sg.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sg=sg.addSecs(bcfark+ctfark);s2gle->setTime(sg);}
        if(ogleArasi==3){sg=sg.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sg=sg.addSecs(bcfark+ctfark);s3gle->setTime(sg);}
        if(ogleArasi==4){sg=sg.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sg=sg.addSecs(bcfark+ctfark);s4gle->setTime(sg);}
        if(ogleArasi==5){sg=sg.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sg=sg.addSecs(bcfark+ctfark);s5gle->setTime(sg);}
        if(ogleArasi==6){sg=sg.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sg=sg.addSecs(bcfark+ctfark);s6gle->setTime(sg);}
        if(ogleArasi==7){sg=sg.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sg=sg.addSecs(bcfark+ctfark);s7gle->setTime(sg);}
        if(ogleArasi==8){sg=sg.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sg=sg.addSecs(bcfark+ctfark);s8gle->setTime(sg);}
        if(ogleArasi==9){sg=sg.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sg=sg.addSecs(bcfark+ctfark);s9gle->setTime(sg);}
        if(ogleArasi==10){sg=sg.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sg=sg.addSecs(bcfark+ctfark);s10gle->setTime(sg);}
        if(ogleArasi==11){sg=sg.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sg=sg.addSecs(bcfark+ctfark);s11gle->setTime(sg);}
        if(ogleArasi==12){sg=sg.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sg=sg.addSecs(bcfark+ctfark);s12gle->setTime(sg);}
        if(ogleArasi==13){sg=sg.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sg=sg.addSecs(bcfark+ctfark);s13gle->setTime(sg);}
        if(ogleArasi==14){sg=sg.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sg=sg.addSecs(bcfark+ctfark);s14gle->setTime(sg);}

        s01ble->setTime(sb);molasuresi=tmpmolasuresi;
        if(ogleArasi==2){sb=sb.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sb=sb.addSecs(bcfark+ctfark);s2ble->setTime(sb);}
        if(ogleArasi==3){sb=sb.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sb=sb.addSecs(bcfark+ctfark);s3ble->setTime(sb);}
        if(ogleArasi==4){sb=sb.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sb=sb.addSecs(bcfark+ctfark);s4ble->setTime(sb);}
        if(ogleArasi==5){sb=sb.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sb=sb.addSecs(bcfark+ctfark);s5ble->setTime(sb);}
        if(ogleArasi==6){sb=sb.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sb=sb.addSecs(bcfark+ctfark);s6ble->setTime(sb);}
        if(ogleArasi==7){sb=sb.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sb=sb.addSecs(bcfark+ctfark);s7ble->setTime(sb);}
        if(ogleArasi==8){sb=sb.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sb=sb.addSecs(bcfark+ctfark);s8ble->setTime(sb);}
        if(ogleArasi==9){sb=sb.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sb=sb.addSecs(bcfark+ctfark);s9ble->setTime(sb);}
        if(ogleArasi==10){sb=sb.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sb=sb.addSecs(bcfark+ctfark);s10ble->setTime(sb);}
        if(ogleArasi==11){sb=sb.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sb=sb.addSecs(bcfark+ctfark);s11ble->setTime(sb);}
        if(ogleArasi==12){sb=sb.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sb=sb.addSecs(bcfark+ctfark);s12ble->setTime(sb);}
        if(ogleArasi==13){sb=sb.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sb=sb.addSecs(bcfark+ctfark);s13ble->setTime(sb);}
        if(ogleArasi==14){sb=sb.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sb=sb.addSecs(bcfark+ctfark);s14ble->setTime(sb);}


        s01cle->setTime(sc);molasuresi=tmpmolasuresi;
        if(ogleArasi==2){sc=sc.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sc=sc.addSecs(bcfark+ctfark);s2cle->setTime(sc);}
        if(ogleArasi==3){sc=sc.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sc=sc.addSecs(bcfark+ctfark);s3cle->setTime(sc);}
        if(ogleArasi==4){sc=sc.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sc=sc.addSecs(bcfark+ctfark);s4cle->setTime(sc);}
        if(ogleArasi==5){sc=sc.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sc=sc.addSecs(bcfark+ctfark);s5cle->setTime(sc);}
        if(ogleArasi==6){sc=sc.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sc=sc.addSecs(bcfark+ctfark);s6cle->setTime(sc);}
        if(ogleArasi==7){sc=sc.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sc=sc.addSecs(bcfark+ctfark);s7cle->setTime(sc);}
        if(ogleArasi==8){sc=sc.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sc=sc.addSecs(bcfark+ctfark);s8cle->setTime(sc);}
        if(ogleArasi==9){sc=sc.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sc=sc.addSecs(bcfark+ctfark);s9cle->setTime(sc);}
        if(ogleArasi==10){sc=sc.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sc=sc.addSecs(bcfark+ctfark);s10cle->setTime(sc);}
        if(ogleArasi==11){sc=sc.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sc=sc.addSecs(bcfark+ctfark);s11cle->setTime(sc);}
        if(ogleArasi==12){sc=sc.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sc=sc.addSecs(bcfark+ctfark);s12cle->setTime(sc);}
        if(ogleArasi==13){sc=sc.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sc=sc.addSecs(bcfark+ctfark);s13cle->setTime(sc);}
        if(ogleArasi==14){sc=sc.addSecs(bcfark+ctfark+molasuresi);molasuresi=0;}else {sc=sc.addSecs(bcfark+ctfark);s14cle->setTime(sc);}


 });
/**************************************************************/



    QPushButton *ayarKaydetButton= new QPushButton;
   /// ayarKaydetButton->setFixedSize(150, 30);
    ///ayarKaydetButton->setIconSize(QSize(150,30));
    ayarKaydetButton->setText("Kaydet");
    ayarKaydetButton->setStyleSheet("Text-align:center");
  //  ayarKaydetButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(ayarKaydetButton, &QPushButton::clicked, [=]() {
     //   if(player->mediaStatus()==QMediaPlayer::PlayingState)
           // player->stop();
        int girissaniye,baslamasaniye,cikissaniye,tenefussaniye,gbfark,bcfark,ctfark;
        QTime sg=sgle->time();//Giriş
        QTime sb=sble->time();//Başlama
        QTime sc=scle->time();//Çıkış
        QTime st=stle->time();//tenefüs bitiş
        girissaniye=sg.hour()*60*60+sg.minute()*60+sg.second();
        baslamasaniye=sb.hour()*60*60+sb.minute()*60+sb.second();
        cikissaniye=sc.hour()*60*60+sc.minute()*60+sc.second();
        tenefussaniye=st.hour()*60*60+st.minute()*60+st.second();

        gbfark=baslamasaniye-girissaniye;
        bcfark=cikissaniye-baslamasaniye;
        ctfark=tenefussaniye-cikissaniye;
        //ctfark--;
        QStringList saathilist;
        int gecikme=10;
        saathilist.append(tn+"|"+s0gle->text());
        QTime anons=s01cle->time();anons=anons.addSecs(gecikme);QTime tenefus=s01cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append(gn+"01"+"|"+s01gle->text()+"|"+s01ble->text()+"|"+s01cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s2cle->time();anons=anons.addSecs(gecikme);tenefus=s2cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append(gn+"2"+"|"+s2gle->text()+"|"+s2ble->text()+"|"+s2cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s3cle->time();anons=anons.addSecs(gecikme);tenefus=s3cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append(gn+"3"+"|"+s3gle->text()+"|"+s3ble->text()+"|"+s3cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));

        anons=s4cle->time();anons=anons.addSecs(gecikme);tenefus=s4cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append(gn+"4"+"|"+s4gle->text()+"|"+s4ble->text()+"|"+s4cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s5cle->time();anons=anons.addSecs(gecikme);tenefus=s5cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append(gn+"5"+""+s5gle->text()+"|"+s5ble->text()+"|"+s5cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s6cle->time();anons=anons.addSecs(gecikme);tenefus=s6cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append(gn+"6"+"|"+s6gle->text()+"|"+s6ble->text()+"|"+s6cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s7cle->time();anons=anons.addSecs(gecikme);tenefus=s7cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append(gn+"7"+"|"+s7gle->text()+"|"+s7ble->text()+"|"+s7cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s8cle->time();anons=anons.addSecs(gecikme);tenefus=s8cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append(gn+"8"+"|"+s8gle->text()+"|"+s8ble->text()+"|"+s8cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s9cle->time();anons=anons.addSecs(gecikme);tenefus=s9cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append(gn+"9"+"|"+s9gle->text()+"|"+s9ble->text()+"|"+s9cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s10cle->time();anons=anons.addSecs(gecikme);tenefus=s10cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append(gn+"10"+"|"+s10gle->text()+"|"+s10ble->text()+"|"+s10cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s11cle->time();anons=anons.addSecs(gecikme);tenefus=s11cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append(gn+"11"+"|"+s11gle->text()+"|"+s11ble->text()+"|"+s11cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s12cle->time();anons=anons.addSecs(gecikme);tenefus=s12cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append(gn+"12"+"|"+s12gle->text()+"|"+s12ble->text()+"|"+s12cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s13cle->time();anons=anons.addSecs(gecikme);tenefus=s13cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append(gn+"13"+"|"+s13gle->text()+"|"+s13ble->text()+"|"+s13cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));
        anons=s14cle->time();anons=anons.addSecs(gecikme);tenefus=s14cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        saathilist.append(gn+"14"+"|"+s14gle->text()+"|"+s14ble->text()+"|"+s14cle->text()+"|"+anons.toString("hh:mm:ss")+"|"+tenefus.toString("hh:mm:ss"));

         QStringList listconf=fileToList("e-zil.conf",QDir::homePath());
        listconf=listMerge(saathilist,listconf,0);
        listToFile(listconf,"e-zil.conf",QDir::homePath());
        init();
 });
    int ogleArasi=0;
            if(listGetLine(ayarlist,"moladerssaati")!="")
               ogleArasi=listGetLine(ayarlist,"moladerssaati").split("|")[2].toInt();

    // auto widget = new QWidget;
    auto layout = new QGridLayout(ayarPage);
    layout->setContentsMargins(0, 0, 0,0);
    // layout->setVerticalSpacing(4);
    //layout->setColumnMinimumWidth(0, 37);
    //layout->addWidget(adLabel, 2,0,1,2);
    layout->addWidget(new QLabel("<font size=2>Tüm Saatlere Uygulanacak 1 Saatlik Bilgi</font>"),0,0,1,3,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Tören Saati</font>"),6,0,1,1,Qt::AlignHCenter);

     layout->addWidget(new QLabel("<font size=2>Öğrenci Saati</font>"),6,1,1,1,Qt::AlignHCenter);
     layout->addWidget(new QLabel("<font size=2>Öğretmen Başlama</font>"),6,2,1,1,Qt::AlignHCenter);
     layout->addWidget(new QLabel("<font size=2>Ders Çıkış</font>"),6,3,1,1,Qt::AlignHCenter);
     layout->addWidget(new QLabel("<font size=2>Teneffüs Bitiş</font>"),6,4,1,1,Qt::AlignHCenter);
     layout->addWidget(s0gle, 7,0,1,1);
     layout->addWidget(sgle, 7,1,1,1);
     layout->addWidget(sble, 7,2,1,1);
     layout->addWidget(scle, 7,3,1,1);
     layout->addWidget(stle, 7,4,1,1);

       // layout->addWidget(saatUyarlaButton, 8,0,1,2);

        //layout->addWidget(ayarKaydetButton, 8,4,1,1);
     layout->addWidget(saatUyarlaButton, 8,0,1,2);
     layout->addWidget(haftaUyarlaButton, 8,2,1,2);
     layout->addWidget(ayarKaydetButton, 8,4,1,1);


    layout->addWidget(new QLabel("<font size=2>Öğrenci Saati</font>"),9,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=2>Öğretmen Saati</font>"),9,2,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=2>Çıkış Saati</font>"),9,3,1,1,Qt::AlignHCenter);


    layout->addWidget(new QLabel("<font size=1>1. Ders</font>"),10,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s01gle, 10,1,1,1);
    layout->addWidget(s01ble, 10,2,1,1);
    layout->addWidget(s01cle, 10,3,1,1);
if(ogleArasi==1)
    layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),11,1,1,3,Qt::AlignHCenter);

    layout->addWidget(new QLabel("<font size=1>2. Ders</font>"),12,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s2gle, 12,1,1,1);
    layout->addWidget(s2ble, 12,2,1,1);
    layout->addWidget(s2cle, 12,3,1,1);
    if(ogleArasi==2)
        layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),13,1,1,3,Qt::AlignHCenter);

    layout->addWidget(new QLabel("<font size=1>3. Ders</font>"),14,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s3gle, 14,1,1,1);
    layout->addWidget(s3ble, 14,2,1,1);
    layout->addWidget(s3cle, 14,3,1,1);
    if(ogleArasi==13)
        layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),15,1,1,3,Qt::AlignHCenter);

    layout->addWidget(new QLabel("<font size=1>4. Ders</font>"),16,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s4gle, 16,1,1,1);
    layout->addWidget(s4ble, 16,2,1,1);
    layout->addWidget(s4cle, 16,3,1,1);
            if(ogleArasi==4)
                layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),17,1,1,3,Qt::AlignHCenter);

    layout->addWidget(new QLabel("<font size=1>5. Ders</font>"),18,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s5gle, 18,1,1,1);
    layout->addWidget(s5ble, 18,2,1,1);
    layout->addWidget(s5cle, 18,3,1,1);
            if(ogleArasi==5)
    layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),19,1,1,3,Qt::AlignHCenter);

    layout->addWidget(new QLabel("<font size=1>6. Ders</font>"),20,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s6gle, 20,1,1,1);
    layout->addWidget(s6ble, 20,2,1,1);
    layout->addWidget(s6cle, 20,3,1,1);
            if(ogleArasi==6)
                layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),21,1,1,3,Qt::AlignHCenter);

    layout->addWidget(new QLabel("<font size=1>7. Ders</font>"),22,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s7gle, 22,1,1,1);
    layout->addWidget(s7ble, 22,2,1,1);
    layout->addWidget(s7cle, 22,3,1,1);
            if(ogleArasi==7)
                layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),23,1,1,3,Qt::AlignHCenter);

    layout->addWidget(new QLabel("<font size=1>8. Ders</font>"),24,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s8gle, 24,1,1,1);
    layout->addWidget(s8ble, 24,2,1,1);
    layout->addWidget(s8cle, 24,3,1,1);
            if(ogleArasi==8)
                layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),25,1,1,3,Qt::AlignHCenter);

    layout->addWidget(new QLabel("<font size=1>9. Ders</font>"),26,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s9gle, 26,1,1,1);
    layout->addWidget(s9ble, 26,2,1,1);
    layout->addWidget(s9cle, 26,3,1,1);
            if(ogleArasi==9)
                layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),27,1,1,3,Qt::AlignHCenter);

    layout->addWidget(new QLabel("<font size=1>10. Ders</font>"),28,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s10gle, 28,1,1,1);
    layout->addWidget(s10ble, 28,2,1,1);
    layout->addWidget(s10cle, 28,3,1,1);
            if(ogleArasi==10)
                layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),29,1,1,3,Qt::AlignHCenter);

    layout->addWidget(new QLabel("<font size=1>11. Ders</font>"),30,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s11gle, 30,1,1,1);
    layout->addWidget(s11ble, 30,2,1,1);
    layout->addWidget(s11cle, 30,3,1,1);
            if(ogleArasi==11)
                layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),31,1,1,3,Qt::AlignHCenter);

    layout->addWidget(new QLabel("<font size=1>12. Ders</font>"),32,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s12gle, 32,1,1,1);
    layout->addWidget(s12ble, 32,2,1,1);
    layout->addWidget(s12cle, 32,3,1,1);
            if(ogleArasi==12)
                layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),33,1,1,3,Qt::AlignHCenter);

    layout->addWidget(new QLabel("<font size=1>13. Ders</font>"),34,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s13gle, 34,1,1,1);
    layout->addWidget(s13ble, 34,2,1,1);
    layout->addWidget(s13cle, 34,3,1,1);
            if(ogleArasi==13)
                layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),35,1,1,3,Qt::AlignHCenter);

    layout->addWidget(new QLabel("<font size=1>14. Ders</font>"),36,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s14gle, 36,1,1,1);
    layout->addWidget(s14ble, 36,2,1,1);
    layout->addWidget(s14cle, 36,3,1,1);

 //   layout->addWidget(new QLabel("<font size=1>Ayarları Kaydet</font>"),30,1,1,1,Qt::AlignHCenter);
     // layout->setColumnStretch(6, 255);

    return ayarPage;
}


#endif // SAATHI_H
