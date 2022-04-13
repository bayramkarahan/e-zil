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
void MainWindow::zamanHesapla(QTime _sg,QTime _sb,QTime _sc,QTime _st,QString baslamaZamani )
{
   sg=_sg;//Giriş
   sb=_sb;//Başlama
   sc=_sc;//Çıkış
   st=_st;//tenefüs bitiş
   girissaniye=sg.hour()*60*60+sg.minute()*60+sg.second();
   baslamasaniye=sb.hour()*60*60+sb.minute()*60+sb.second();
   cikissaniye=sc.hour()*60*60+sc.minute()*60+sc.second();
   tenefussaniye=st.hour()*60*60+st.minute()*60+st.second();

   gbfark=baslamasaniye-girissaniye;
   bcfark=cikissaniye-baslamasaniye;
   ctfark=tenefussaniye-cikissaniye;

}
QWidget *MainWindow::saatpzrts(int guns)
{
    int derssayisi=0;
    if(listGetLine(ayarlist,"derssayisi")!="")
     derssayisi=listGetLine(ayarlist,"derssayisi").split("|")[2].toInt();
    //qDebug()<<guns;
    //gn=QString::number(dt.dayOfWeek())+"s";
    //tn=QString::number(dt.dayOfWeek())+"st";
    QString gn=QString::number(guns)+"s";
    QString tn=QString::number(guns)+"storen";
    QWidget *ayarPage=new QWidget();
    ayarPage->setFixedWidth(500);
    ayarPage->setFixedHeight(200+derssayisi*25);
   // ayarPage->setStyleSheet("background-color: #ff0000;");
    /*******************************************************/
    QStringList ayarlst=fileToList("e-zil.conf");

    /*********************Sabah Tören Giriş***********************************/
    QTimeEdit *torenbaslama=new QTimeEdit(ayarPage);

    QTimeEdit *s1gle=new QTimeEdit(ayarPage);QTimeEdit *s1ble=new QTimeEdit(ayarPage);QTimeEdit *s1cle=new QTimeEdit(ayarPage);
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
    if(derssayisi<1){s1gle->hide();s1ble->hide();s1cle->hide();}
    if(derssayisi<2){s2gle->hide();s2ble->hide();s2cle->hide();}
    if(derssayisi<3){s3gle->hide();s3ble->hide();s3cle->hide();}
    if(derssayisi<4){s4gle->hide();s4ble->hide();s4cle->hide();}
    if(derssayisi<5){s5gle->hide();s5ble->hide();s5cle->hide();}
    if(derssayisi<6){s6gle->hide();s6ble->hide();s6cle->hide();}
    if(derssayisi<7){s7gle->hide();s7ble->hide();s7cle->hide();}
    if(derssayisi<8){s8gle->hide();s8ble->hide();s8cle->hide();}
    if(derssayisi<9){s9gle->hide();s9ble->hide();s9cle->hide();}
    if(derssayisi<10){s10gle->hide();s10ble->hide();s10cle->hide();}
    if(derssayisi<11){s11gle->hide();s11ble->hide();s11cle->hide();}
    if(derssayisi<12){s12gle->hide();s12ble->hide();s12cle->hide();}
    if(derssayisi<13){s13gle->hide();s13ble->hide();s13cle->hide();}
    if(derssayisi<14){s14gle->hide();s14ble->hide();s14cle->hide();}

  ///  torenbaslama->resize(100,25);
  ///  torenbaslama->setDisplayFormat("hh:mm");
    if(listGetLine(ayarlst,tn)!="")torenbaslama->setTime(saniyeToSaat(listGetLine(ayarlst,tn).split("|")[1]));
    if(listGetLine(ayarlst,gn+"1")!="")s1gle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"1").split("|")[1]));
    if(listGetLine(ayarlst,gn+"1")!="")s1ble->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"1").split("|")[2]));
    if(listGetLine(ayarlst,gn+"1")!="")s1cle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"1").split("|")[3]));
    if(listGetLine(ayarlst,gn+"2")!="")s2gle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"2").split("|")[1]));
    if(listGetLine(ayarlst,gn+"2")!="")s2ble->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"2").split("|")[2]));
    if(listGetLine(ayarlst,gn+"2")!="")s2cle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"2").split("|")[3]));
    if(listGetLine(ayarlst,gn+"3")!="")s3gle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"3").split("|")[1]));
    if(listGetLine(ayarlst,gn+"3")!="")s3ble->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"3").split("|")[2]));
    if(listGetLine(ayarlst,gn+"3")!="")s3cle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"3").split("|")[3]));
    if(listGetLine(ayarlst,gn+"4")!="")s4gle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"4").split("|")[1]));
    if(listGetLine(ayarlst,gn+"4")!="")s4ble->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"4").split("|")[2]));
    if(listGetLine(ayarlst,gn+"4")!="")s4cle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"4").split("|")[3]));
    if(listGetLine(ayarlst,gn+"5")!="")s5gle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"5").split("|")[1]));
    if(listGetLine(ayarlst,gn+"5")!="")s5ble->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"5").split("|")[2]));
    if(listGetLine(ayarlst,gn+"5")!="")s5cle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"5").split("|")[3]));
    if(listGetLine(ayarlst,gn+"6")!="")s6gle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"6").split("|")[1]));
    if(listGetLine(ayarlst,gn+"6")!="")s6ble->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"6").split("|")[2]));
    if(listGetLine(ayarlst,gn+"6")!="")s6cle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"6").split("|")[3]));
    if(listGetLine(ayarlst,gn+"7")!="")s7gle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"7").split("|")[1]));
    if(listGetLine(ayarlst,gn+"7")!="")s7ble->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"7").split("|")[2]));
    if(listGetLine(ayarlst,gn+"7")!="")s7cle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"7").split("|")[3]));
    if(listGetLine(ayarlst,gn+"8")!="")s8gle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"8").split("|")[1]));
    if(listGetLine(ayarlst,gn+"8")!="")s8ble->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"8").split("|")[2]));
    if(listGetLine(ayarlst,gn+"8")!="")s8cle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"8").split("|")[3]));
    if(listGetLine(ayarlst,gn+"9")!="")s9gle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"9").split("|")[1]));
    if(listGetLine(ayarlst,gn+"9")!="")s9ble->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"9").split("|")[2]));
    if(listGetLine(ayarlst,gn+"9")!="")s9cle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"9").split("|")[3]));
    if(listGetLine(ayarlst,gn+"10")!="")s10gle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"10").split("|")[1]));
    if(listGetLine(ayarlst,gn+"10")!="")s10ble->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"10").split("|")[2]));
    if(listGetLine(ayarlst,gn+"10")!="")s10cle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"10").split("|")[3]));
    if(listGetLine(ayarlst,gn+"11")!="")s11gle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"11").split("|")[1]));
    if(listGetLine(ayarlst,gn+"11")!="")s11ble->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"11").split("|")[2]));
    if(listGetLine(ayarlst,gn+"11")!="")s11cle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"11").split("|")[3]));
    if(listGetLine(ayarlst,gn+"12")!="")s12gle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"12").split("|")[1]));
    if(listGetLine(ayarlst,gn+"12")!="")s12ble->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"12").split("|")[2]));
    if(listGetLine(ayarlst,gn+"12")!="")s12cle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"12").split("|")[3]));
    if(listGetLine(ayarlst,gn+"13")!="")s13gle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"13").split("|")[1]));
    if(listGetLine(ayarlst,gn+"13")!="")s13ble->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"13").split("|")[2]));
    if(listGetLine(ayarlst,gn+"13")!="")s13cle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"13").split("|")[3]));
    if(listGetLine(ayarlst,gn+"14")!="")s14gle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"14").split("|")[1]));
    if(listGetLine(ayarlst,gn+"14")!="")s14ble->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"14").split("|")[2]));
    if(listGetLine(ayarlst,gn+"14")!="")s14cle->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"14").split("|")[3]));
  /************************ornek ders********************************/
 //   QTimeEdit *sgle=new QTimeEdit(ayarPage);
   // sgle->resize(60,25);
   // if(listGetLine(ayarlst,gn+"01")!="")sgle->setTime(QTime::fromString(listGetLine(ayarlst,"1s01").split("|")[1]));
    //QTimeEdit *sble=new QTimeEdit(ayarPage);
    //sble->resize(60,25);
    //if(listGetLine(ayarlst,gn+"01")!="")sble->setTime(QTime::fromString(listGetLine(ayarlst,"1s01").split("|")[2]));
    //QTimeEdit *scle=new QTimeEdit(ayarPage);
    //scle->resize(60,25);
   // if(listGetLine(ayarlst,gn+"01")!="")scle->setTime(QTime::fromString(listGetLine(ayarlst,"1s01").split("|")[3]));
    QTimeEdit *tenefusson=new QTimeEdit(ayarPage);
    tenefusson->resize(60,25);
    if(listGetLine(ayarlst,gn+"2")!="")tenefusson->setTime(saniyeToSaat(listGetLine(ayarlst,gn+"2").split("|")[2]));



torenbaslama->setDisplayFormat("hh:mm");
//sgle->setDisplayFormat("hh:mm");
//sble->setDisplayFormat("hh:mm");scle->setDisplayFormat("hh:mm");
tenefusson->setDisplayFormat("hh:mm");

s1gle->setDisplayFormat("hh:mm");s1ble->setDisplayFormat("hh:mm");s1cle->setDisplayFormat("hh:mm");
s2gle->setDisplayFormat("hh:mm");s2ble->setDisplayFormat("hh:mm");s2cle->setDisplayFormat("hh:mm");
s3gle->setDisplayFormat("hh:mm");s3ble->setDisplayFormat("hh:mm");s3cle->setDisplayFormat("hh:mm");
s4gle->setDisplayFormat("hh:mm");s4ble->setDisplayFormat("hh:mm");s4cle->setDisplayFormat("hh:mm");
s5gle->setDisplayFormat("hh:mm");s5ble->setDisplayFormat("hh:mm");s5cle->setDisplayFormat("hh:mm");
s6gle->setDisplayFormat("hh:mm");s6ble->setDisplayFormat("hh:mm");s6cle->setDisplayFormat("hh:mm");
s7gle->setDisplayFormat("hh:mm");s7ble->setDisplayFormat("hh:mm");s7cle->setDisplayFormat("hh:mm");
s8gle->setDisplayFormat("hh:mm");s8ble->setDisplayFormat("hh:mm");s8cle->setDisplayFormat("hh:mm");
s9gle->setDisplayFormat("hh:mm");s9ble->setDisplayFormat("hh:mm");s9cle->setDisplayFormat("hh:mm");
s10gle->setDisplayFormat("hh:mm");s10ble->setDisplayFormat("hh:mm");s10cle->setDisplayFormat("hh:mm");
s11gle->setDisplayFormat("hh:mm");s11ble->setDisplayFormat("hh:mm");s11cle->setDisplayFormat("hh:mm");
s12gle->setDisplayFormat("hh:mm");s12ble->setDisplayFormat("hh:mm");s12cle->setDisplayFormat("hh:mm");
s13gle->setDisplayFormat("hh:mm");s13ble->setDisplayFormat("hh:mm");s13cle->setDisplayFormat("hh:mm");
s14gle->setDisplayFormat("hh:mm");s14ble->setDisplayFormat("hh:mm");s14cle->setDisplayFormat("hh:mm");


QPushButton *haftaUyarlaButton= new QPushButton;
//  haftaUyarlaButton->setFixedSize(150, 30);
//haftaUyarlaButton->setIconSize(QSize(450,30));
haftaUyarlaButton->setText("Tüm Haftaya Uyarla");
haftaUyarlaButton->setStyleSheet("Text-align:center");
//  ayarKaydetButton->setFlat(true);
// kilitButton->setIcon(QIcon(":icons/saveprofile.png"));
if(guns!=1) haftaUyarlaButton->hide();
    connect(haftaUyarlaButton, &QPushButton::clicked, [=]() {
        int derssayisi=0;
        if(listGetLine(ayarlist,"derssayisi")!="")
         derssayisi=listGetLine(ayarlist,"derssayisi").split("|")[2].toInt();

        int girissaniye,baslamasaniye,cikissaniye,tenefussaniye,gbfark,bcfark,ctfark;
        QTime sg=s1gle->time();//Giriş
        QTime sb=s1ble->time();//Başlama
        QTime sc=s1cle->time();//Çıkış
        QTime st=tenefusson->time();//tenefüs bitiş
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
        saathilist.append("1storen|"+saatToSaniye(torenbaslama->time()));
        QTime anons=s1cle->time();anons=anons.addSecs(gecikme);QTime tenefus=s1cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        if(derssayisi>=1)
        saathilist.append("1s1|"+saatToSaniye(s1gle->time())+"|"+saatToSaniye(s1ble->time())+"|"+saatToSaniye(s1cle->time()));
        anons=s2cle->time();anons=anons.addSecs(gecikme);tenefus=s2cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        if(derssayisi>=2)
        saathilist.append("1s2|"+saatToSaniye(s2gle->time())+"|"+saatToSaniye(s2ble->time())+"|"+saatToSaniye(s2cle->time()));
        anons=s3cle->time();anons=anons.addSecs(gecikme);tenefus=s3cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        if(derssayisi>=3)
        saathilist.append("1s3|"+saatToSaniye(s3gle->time())+"|"+saatToSaniye(s3ble->time())+"|"+saatToSaniye(s3cle->time()));

        anons=s4cle->time();anons=anons.addSecs(gecikme);tenefus=s4cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        if(derssayisi>=4)
        saathilist.append("1s4|"+saatToSaniye(s4gle->time())+"|"+saatToSaniye(s4ble->time())+"|"+saatToSaniye(s4cle->time()));
        anons=s5cle->time();anons=anons.addSecs(gecikme);tenefus=s5cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        if(derssayisi>=5)
        saathilist.append("1s5|"+saatToSaniye(s5gle->time())+"|"+saatToSaniye(s5ble->time())+"|"+saatToSaniye(s5cle->time()));
        anons=s6cle->time();anons=anons.addSecs(gecikme);tenefus=s6cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        if(derssayisi>=6)
        saathilist.append("1s6|"+saatToSaniye(s6gle->time())+"|"+saatToSaniye(s6ble->time())+"|"+saatToSaniye(s6cle->time()));
        anons=s7cle->time();anons=anons.addSecs(gecikme);tenefus=s7cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        if(derssayisi>=7)
        saathilist.append("1s7|"+saatToSaniye(s7gle->time())+"|"+saatToSaniye(s7ble->time())+"|"+saatToSaniye(s7cle->time()));
        anons=s8cle->time();anons=anons.addSecs(gecikme);tenefus=s8cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        if(derssayisi>=8)
        saathilist.append("1s8|"+saatToSaniye(s8gle->time())+"|"+saatToSaniye(s8ble->time())+"|"+saatToSaniye(s8cle->time()));
        anons=s9cle->time();anons=anons.addSecs(gecikme);tenefus=s9cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        if(derssayisi>=9)
        saathilist.append("1s9|"+saatToSaniye(s9gle->time())+"|"+saatToSaniye(s9ble->time())+"|"+saatToSaniye(s9cle->time()));
        anons=s10cle->time();anons=anons.addSecs(gecikme);tenefus=s10cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        if(derssayisi>=10)
        saathilist.append("1s10|"+saatToSaniye(s10gle->time())+"|"+saatToSaniye(s10ble->time())+"|"+saatToSaniye(s10cle->time()));
        anons=s11cle->time();anons=anons.addSecs(gecikme);tenefus=s11cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        if(derssayisi>=11)
        saathilist.append("1s11|"+saatToSaniye(s11gle->time())+"|"+saatToSaniye(s11ble->time())+"|"+saatToSaniye(s11cle->time()));
        anons=s12cle->time();anons=anons.addSecs(gecikme);tenefus=s12cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        if(derssayisi>=12)
        saathilist.append("1s12|"+saatToSaniye(s12gle->time())+"|"+saatToSaniye(s12ble->time())+"|"+saatToSaniye(s12cle->time()));
        anons=s13cle->time();anons=anons.addSecs(gecikme);tenefus=s13cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        if(derssayisi>=13)
        saathilist.append("1s13|"+saatToSaniye(s13gle->time())+"|"+saatToSaniye(s13ble->time())+"|"+saatToSaniye(s13cle->time()));
        anons=s14cle->time();anons=anons.addSecs(gecikme);tenefus=s14cle->time();tenefus=tenefus.addSecs(ctfark-gbfark-gecikme);
        if(derssayisi>=14)
        saathilist.append("1s14|"+saatToSaniye(s14gle->time())+"|"+saatToSaniye(s14ble->time())+"|"+saatToSaniye(s14cle->time()));



        QStringList listconf=fileToList("e-zil.conf");

        listconf=listMerge(saathilist,listconf,0);//pazartesi
        listconf=listMerge(listReplace(saathilist, "1s", "2s", 0),listconf,0);//salı
        listconf=listMerge(listReplace(saathilist, "1s", "3s", 0),listconf,0);//çarşamba
        listconf=listMerge(listReplace(saathilist, "1s", "4s", 0),listconf,0);//perşembe
        listconf=listMerge(listReplace(saathilist, "1s", "5s", 0),listconf,0);//cuma
        listconf=listMerge(listReplace(saathilist, "1s", "6s", 0),listconf,0);//cumartesi
        listconf=listMerge(listReplace(saathilist, "1s", "7s", 0),listconf,0);//pazar

        listToFile(listconf,"e-zil.conf");
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


    connect(saatUyarlaButton, &QPushButton::clicked, [=]() {
   ///     qDebug()<<"burasııı";
       /* int girissaniye,baslamasaniye,cikissaniye,tenefussaniye,gbfark,bcfark,ctfark;
        QTime sg=sgle->time();//Giriş
        QTime sb=sble->time();//Başlama
        QTime sc=scle->time();//Çıkış
        QTime st=tenefusson->time();//tenefüs bitiş
        girissaniye=sg.hour()*60*60+sg.minute()*60+sg.second();
        baslamasaniye=sb.hour()*60*60+sb.minute()*60+sb.second();
        cikissaniye=sc.hour()*60*60+sc.minute()*60+sc.second();
        tenefussaniye=st.hour()*60*60+st.minute()*60+st.second();

        gbfark=baslamasaniye-girissaniye;
        bcfark=cikissaniye-baslamasaniye;
        ctfark=tenefussaniye-cikissaniye;
        */
        int derssayisi=0;
        if(listGetLine(ayarlist,"derssayisi")!="")
         derssayisi=listGetLine(ayarlist,"derssayisi").split("|")[2].toInt();

        zamanHesapla(s1gle->time(),s1ble->time(),s1cle->time(),tenefusson->time(),"sabah");///hesaplama için önemli

        int ogleArasi=0;
        if(listGetLine(ayarlist,"moladerssaati")!="")
            ogleArasi=listGetLine(ayarlist,"moladerssaati").split("|")[2].toInt();

        int molasuresi=0;
        int tmpmolasuresi=0;
        if(listGetLine(ayarlist,"molasuresi")!="")
        {
            QTime msure;
            msure=saniyeToSaat(listGetLine(ayarlst,"molasuresi").split("|")[2]);
            /// molasuresi=ayarlist,"molasuresi").split("|")[2].toInt();
            molasuresi=msure.hour()*60*60+msure.minute()*60+msure.second();

        }
        /// qDebug()<<"mola:"<<molasuresi-ctfark;
   /// qDebug()<<"öğle arası:"<<ogleArasi;
        ogleArasi++;
      //  molasuresi=molasuresi-ctfark;
        tmpmolasuresi=molasuresi;
        s1gle->setTime(sg);
        if(ogleArasi==2){sg=sg.addSecs(bcfark+molasuresi);molasuresi=0;s2gle->setTime(sg);}else {if(derssayisi>=2){sg=sg.addSecs(bcfark+ctfark);s2gle->setTime(sg);}}
        if(ogleArasi==3){sg=sg.addSecs(bcfark+molasuresi);molasuresi=0;s3gle->setTime(sg);}else {if(derssayisi>=3){sg=sg.addSecs(bcfark+ctfark);s3gle->setTime(sg);}}
        if(ogleArasi==4){sg=sg.addSecs(bcfark+molasuresi);molasuresi=0;s4gle->setTime(sg);}else {if(derssayisi>=4){sg=sg.addSecs(bcfark+ctfark);s4gle->setTime(sg);}}
        if(ogleArasi==5){sg=sg.addSecs(bcfark+molasuresi);molasuresi=0;s5gle->setTime(sg);}else {if(derssayisi>=5){sg=sg.addSecs(bcfark+ctfark);s5gle->setTime(sg);}}
        if(ogleArasi==6){sg=sg.addSecs(bcfark+molasuresi);molasuresi=0;s6gle->setTime(sg);}else{if(derssayisi>=6){sg=sg.addSecs(bcfark+ctfark);s6gle->setTime(sg);}}
        if(ogleArasi==7){sg=sg.addSecs(bcfark+molasuresi);molasuresi=0;s7gle->setTime(sg);}else {if(derssayisi>=7){sg=sg.addSecs(bcfark+ctfark);s7gle->setTime(sg);}}
        if(ogleArasi==8){sg=sg.addSecs(bcfark+molasuresi);molasuresi=0;s8gle->setTime(sg);}else {if(derssayisi>=8){sg=sg.addSecs(bcfark+ctfark);s8gle->setTime(sg);}}
        if(ogleArasi==9){sg=sg.addSecs(bcfark+molasuresi);molasuresi=0;s9gle->setTime(sg);}else {if(derssayisi>=9){sg=sg.addSecs(bcfark+ctfark);s9gle->setTime(sg);}}
        if(ogleArasi==10){sg=sg.addSecs(bcfark+molasuresi);molasuresi=0;s10gle->setTime(sg);}else {if(derssayisi>=10){sg=sg.addSecs(bcfark+ctfark);s10gle->setTime(sg);}}
        if(ogleArasi==11){sg=sg.addSecs(bcfark+molasuresi);molasuresi=0;s11gle->setTime(sg);}else {if(derssayisi>=11){sg=sg.addSecs(bcfark+ctfark);s11gle->setTime(sg);}}
        if(ogleArasi==12){sg=sg.addSecs(bcfark+molasuresi);molasuresi=0;s12gle->setTime(sg);}else {if(derssayisi>=12){sg=sg.addSecs(bcfark+ctfark);s12gle->setTime(sg);}}
        if(ogleArasi==13){sg=sg.addSecs(bcfark+molasuresi);molasuresi=0;s13gle->setTime(sg);}else {if(derssayisi>=13){sg=sg.addSecs(bcfark+ctfark);s13gle->setTime(sg);}}
        if(ogleArasi==14){sg=sg.addSecs(bcfark+molasuresi);molasuresi=0;s14gle->setTime(sg);}else {if(derssayisi>=14){sg=sg.addSecs(bcfark+ctfark);s14gle->setTime(sg);}}

        s1ble->setTime(sb);molasuresi=tmpmolasuresi;
        if(ogleArasi==2&&derssayisi>=2){sb=sb.addSecs(bcfark+molasuresi);molasuresi=0;s2ble->setTime(sb);}else {if(derssayisi>=2){sb=sb.addSecs(bcfark+ctfark);s2ble->setTime(sb);}}
        if(ogleArasi==3&&derssayisi>=3){sb=sb.addSecs(bcfark+molasuresi);molasuresi=0;s3ble->setTime(sb);}else {if(derssayisi>=3){sb=sb.addSecs(bcfark+ctfark);s3ble->setTime(sb);}}
        if(ogleArasi==4&&derssayisi>=4){sb=sb.addSecs(bcfark+molasuresi);molasuresi=0;s4ble->setTime(sb);}else {if(derssayisi>=4){sb=sb.addSecs(bcfark+ctfark);s4ble->setTime(sb);}}
        if(ogleArasi==5&&derssayisi>=5){sb=sb.addSecs(bcfark+molasuresi);molasuresi=0;s5ble->setTime(sb);}else {if(derssayisi>=5){sb=sb.addSecs(bcfark+ctfark);s5ble->setTime(sb);}}
        if(ogleArasi==6&&derssayisi>=6){sb=sb.addSecs(bcfark+molasuresi);molasuresi=0;s6ble->setTime(sb);}else {if(derssayisi>=6){sb=sb.addSecs(bcfark+ctfark);s6ble->setTime(sb);}}
        if(ogleArasi==7&&derssayisi>=7){sb=sb.addSecs(bcfark+molasuresi);molasuresi=0;s7ble->setTime(sb);}else {if(derssayisi>=7){sb=sb.addSecs(bcfark+ctfark);s7ble->setTime(sb);}}
        if(ogleArasi==8&&derssayisi>=8){sb=sb.addSecs(bcfark+molasuresi);molasuresi=0;s8ble->setTime(sb);}else {if(derssayisi>=8){sb=sb.addSecs(bcfark+ctfark);s8ble->setTime(sb);}}
        if(ogleArasi==9&&derssayisi>=9){sb=sb.addSecs(bcfark+molasuresi);molasuresi=0;s9ble->setTime(sb);}else {if(derssayisi>=9){sb=sb.addSecs(bcfark+ctfark);s9ble->setTime(sb);}}
        if(ogleArasi==10&&derssayisi>=10){sb=sb.addSecs(bcfark+molasuresi);molasuresi=0;s10ble->setTime(sb);}else {if(derssayisi>=10){sb=sb.addSecs(bcfark+ctfark);s10ble->setTime(sb);}}
        if(ogleArasi==11&&derssayisi>=11){sb=sb.addSecs(bcfark+molasuresi);molasuresi=0;s11ble->setTime(sb);}else {if(derssayisi>=11){sb=sb.addSecs(bcfark+ctfark);s11ble->setTime(sb);}}
        if(ogleArasi==12&&derssayisi>=12){sb=sb.addSecs(bcfark+molasuresi);molasuresi=0;s12ble->setTime(sb);}else {if(derssayisi>=12){sb=sb.addSecs(bcfark+ctfark);s12ble->setTime(sb);}}
        if(ogleArasi==13&&derssayisi>=13){sb=sb.addSecs(bcfark+molasuresi);molasuresi=0;s13ble->setTime(sb);}else {if(derssayisi>=13){sb=sb.addSecs(bcfark+ctfark);s13ble->setTime(sb);}}
        if(ogleArasi==14&&derssayisi>=14){sb=sb.addSecs(bcfark+molasuresi);molasuresi=0;s14ble->setTime(sb);}else {if(derssayisi>=14){sb=sb.addSecs(bcfark+ctfark);s14ble->setTime(sb);}}


        s1cle->setTime(sc);molasuresi=tmpmolasuresi;
        if(ogleArasi==2&&derssayisi>=2){sc=sc.addSecs(bcfark+molasuresi);molasuresi=0;s2cle->setTime(sc);}else {if(derssayisi>=2){sc=sc.addSecs(bcfark+ctfark);s2cle->setTime(sc);}}
        if(ogleArasi==3&&derssayisi>=3){sc=sc.addSecs(bcfark+molasuresi);molasuresi=0;s3cle->setTime(sc);}else {if(derssayisi>=3){sc=sc.addSecs(bcfark+ctfark);s3cle->setTime(sc);}}
        if(ogleArasi==4&&derssayisi>=4){sc=sc.addSecs(bcfark+molasuresi);molasuresi=0;s4cle->setTime(sc);}else {if(derssayisi>=4){sc=sc.addSecs(bcfark+ctfark);s4cle->setTime(sc);}}
        if(ogleArasi==5&&derssayisi>=5){sc=sc.addSecs(bcfark+molasuresi);molasuresi=0;s5cle->setTime(sc);}else {if(derssayisi>=5){sc=sc.addSecs(bcfark+ctfark);s5cle->setTime(sc);}}
        if(ogleArasi==6&&derssayisi>=6){sc=sc.addSecs(bcfark+molasuresi);molasuresi=0;s6cle->setTime(sc);}else {if(derssayisi>=6){sc=sc.addSecs(bcfark+ctfark);s6cle->setTime(sc);}}
        if(ogleArasi==7&&derssayisi>=7){sc=sc.addSecs(bcfark+molasuresi);molasuresi=0;s7cle->setTime(sc);}else {if(derssayisi>=7){sc=sc.addSecs(bcfark+ctfark);s7cle->setTime(sc);}}
        if(ogleArasi==8&&derssayisi>=8){sc=sc.addSecs(bcfark+molasuresi);molasuresi=0;s8cle->setTime(sc);}else {if(derssayisi>=8){sc=sc.addSecs(bcfark+ctfark);s8cle->setTime(sc);}}
        if(ogleArasi==9&&derssayisi>=9){sc=sc.addSecs(bcfark+molasuresi);molasuresi=0;s9cle->setTime(sc);}else {if(derssayisi>=9){sc=sc.addSecs(bcfark+ctfark);s9cle->setTime(sc);}}
        if(ogleArasi==10&&derssayisi>=10){sc=sc.addSecs(bcfark+molasuresi);molasuresi=0;s10cle->setTime(sc);}else {if(derssayisi>=10){sc=sc.addSecs(bcfark+ctfark);s10cle->setTime(sc);}}
        if(ogleArasi==11&&derssayisi>=11){sc=sc.addSecs(bcfark+molasuresi);molasuresi=0;s11cle->setTime(sc);}else {if(derssayisi>=11){sc=sc.addSecs(bcfark+ctfark);s11cle->setTime(sc);}}
        if(ogleArasi==12&&derssayisi>=12){sc=sc.addSecs(bcfark+molasuresi);molasuresi=0;s12cle->setTime(sc);}else {if(derssayisi>=12){sc=sc.addSecs(bcfark+ctfark);s12cle->setTime(sc);}}
        if(ogleArasi==13&&derssayisi>=13){sc=sc.addSecs(bcfark+molasuresi);molasuresi=0;s13cle->setTime(sc);}else {if(derssayisi>=13){sc=sc.addSecs(bcfark+ctfark);s13cle->setTime(sc);}}
        if(ogleArasi==14&&derssayisi>=14){sc=sc.addSecs(bcfark+molasuresi);molasuresi=0;s14cle->setTime(sc);}else {if(derssayisi>=14){sc=sc.addSecs(bcfark+ctfark);s14cle->setTime(sc);}}


 });
/************************mola sonrası**************************************/
    QPushButton *MolaSonrasiSaatUyarlaButton= new QPushButton;
   /// MolaSonrasiSaatUyarlaButton->setFixedSize(300, 30);
    ///MolaSonrasiSaatUyarlaButton->setIconSize(QSize(450,30));
    MolaSonrasiSaatUyarlaButton->setText("Mola Sonrası Saatleri Uyarla");
    MolaSonrasiSaatUyarlaButton->setStyleSheet("Text-align:center");


    connect(MolaSonrasiSaatUyarlaButton, &QPushButton::clicked, [=]() {
      ///  qDebug()<<"mola sonrası";

        int ogleArasi=0;
        if(listGetLine(ayarlist,"moladerssaati")!="")
            ogleArasi=listGetLine(ayarlist,"moladerssaati").split("|")[2].toInt();

/*
        int molasuresi=0;
        int tmpmolasuresi=0;
        if(listGetLine(ayarlist,"molasuresi")!="")
        {
            QTime msure;
            msure=QTime::fromString(listGetLine(ayarlst,"molasuresi").split("|")[2]);
            /// molasuresi=ayarlist,"molasuresi").split("|")[2].toInt();
            molasuresi=msure.hour()*60*60+msure.minute()*60+msure.second();

        }*/
        ogleArasi++;
      //  zamanHesapla(sgle->time(),sble->time(),scle->time(),tenefusson->time());///hesaplama için önemli
        int tempcikissaniye=s1cle->time().hour()*60*60+s1cle->time().minute()*60+s1cle->time().second();
        int temptenefussaniye=tenefusson->time().hour()*60*60+tenefusson->time().minute()*60+tenefusson->time().second();
        int tenefusSuresi=temptenefussaniye-tempcikissaniye;

        if(ogleArasi==2)zamanHesapla(s2gle->time(),s2ble->time(),s2cle->time(),s2cle->time().addSecs(tenefusSuresi),"oglen");///hesaplama için önemli
       if(ogleArasi==3)zamanHesapla(s3gle->time(),s3ble->time(),s3cle->time(),s3cle->time().addSecs(tenefusSuresi),"oglen");///hesaplama için önemli
        if(ogleArasi==4)zamanHesapla(s4gle->time(),s4ble->time(),s4cle->time(),s4cle->time().addSecs(tenefusSuresi),"oglen");///hesaplama için önemli
        if(ogleArasi==5)zamanHesapla(s5gle->time(),s5ble->time(),s5cle->time(),s5cle->time().addSecs(tenefusSuresi),"oglen");///hesaplama için önemli
        if(ogleArasi==6)zamanHesapla(s6gle->time(),s6ble->time(),s6cle->time(),s6cle->time().addSecs(tenefusSuresi),"oglen");///hesaplama için önemli
        if(ogleArasi==7)zamanHesapla(s7gle->time(),s7ble->time(),s7cle->time(),s7cle->time().addSecs(tenefusSuresi),"oglen");///hesaplama için önemli
        if(ogleArasi==8)zamanHesapla(s8gle->time(),s8ble->time(),s8cle->time(),s8cle->time().addSecs(tenefusSuresi),"oglen");///hesaplama için önemli
        if(ogleArasi==9)zamanHesapla(s9gle->time(),s9ble->time(),s9cle->time(),s9cle->time().addSecs(tenefusSuresi),"oglen");///hesaplama için önemli
        if(ogleArasi==10)zamanHesapla(s10gle->time(),s10ble->time(),s10cle->time(),s10cle->time().addSecs(tenefusSuresi),"oglen");///hesaplama için önemli
        if(ogleArasi==11)zamanHesapla(s11gle->time(),s11ble->time(),s11cle->time(),s11cle->time().addSecs(tenefusSuresi),"oglen");///hesaplama için önemli
        if(ogleArasi==12)zamanHesapla(s12gle->time(),s12ble->time(),s12cle->time(),s12cle->time().addSecs(tenefusSuresi),"oglen");///hesaplama için önemli
        if(ogleArasi==13)zamanHesapla(s13gle->time(),s13ble->time(),s13cle->time(),s13cle->time().addSecs(tenefusSuresi),"oglen");///hesaplama için önemli
        if(ogleArasi==14)zamanHesapla(s14gle->time(),s14ble->time(),s14cle->time(),s14cle->time().addSecs(tenefusSuresi),"oglen");///hesaplama için önemli

        /// qDebug()<<"mola:"<<molasuresi-ctfark;


      //qDebug()<<"öğle arası:"<<ogleArasi;
       // molasuresi=molasuresi-ctfark;
      //  tmpmolasuresi=molasuresi;
        //giriş ogrenci
        //s1gle->setTime(sg);
        bool hs=false;
        if(ogleArasi==2&&!hs){hs=true;s2gle->setTime(sg);}else {if (hs){sg=sg.addSecs(bcfark+ctfark);s2gle->setTime(sg);}}
        if(ogleArasi==3&&!hs){hs=true;s3gle->setTime(sg);}else {if (hs){sg=sg.addSecs(bcfark+ctfark);s3gle->setTime(sg);}}
        if(ogleArasi==4&&!hs){hs=true;s4gle->setTime(sg);}else {if (hs){sg=sg.addSecs(bcfark+ctfark);s4gle->setTime(sg);}}
        if(ogleArasi==5&&!hs){hs=true;s5gle->setTime(sg);}else {if (hs){sg=sg.addSecs(bcfark+ctfark);s5gle->setTime(sg);}}
        if(ogleArasi==6&&!hs){hs=true;s6gle->setTime(sg);}else {if (hs){sg=sg.addSecs(bcfark+ctfark);s6gle->setTime(sg);}}
        if(ogleArasi==7&&!hs){hs=true;s7gle->setTime(sg);}else {if (hs){sg=sg.addSecs(bcfark+ctfark);s7gle->setTime(sg);}}
        if(ogleArasi==8&&!hs){hs=true;s8gle->setTime(sg);}else {if (hs){sg=sg.addSecs(bcfark+ctfark);s8gle->setTime(sg);}}
        if(ogleArasi==9&&!hs){hs=true;s9gle->setTime(sg);}else {if (hs){sg=sg.addSecs(bcfark+ctfark);s9gle->setTime(sg);}}
        if(ogleArasi==10&&!hs){hs=true;s10gle->setTime(sg);}else {if (hs){sg=sg.addSecs(bcfark+ctfark);s10gle->setTime(sg);}}
        if(ogleArasi==11&&!hs){hs=true;s11gle->setTime(sg);}else {if (hs){sg=sg.addSecs(bcfark+ctfark);s11gle->setTime(sg);}}
        if(ogleArasi==12&&!hs){hs=true;s12gle->setTime(sg);}else {if (hs){sg=sg.addSecs(bcfark+ctfark);s12gle->setTime(sg);}}
        if(ogleArasi==13&&!hs){hs=true;s13gle->setTime(sg);}else {if (hs){sg=sg.addSecs(bcfark+ctfark);s13gle->setTime(sg);}}
        if(ogleArasi==14&&!hs){hs=true;s14gle->setTime(sg);}else {if (hs){sg=sg.addSecs(bcfark+ctfark);s14gle->setTime(sg);}}
        //başlama öğretmen
        hs=false;
        if(ogleArasi==2&&!hs){hs=true;s2ble->setTime(sb);}else {if (hs){sb=sb.addSecs(bcfark+ctfark);s2ble->setTime(sb);}}
        if(ogleArasi==3&&!hs){hs=true;s3ble->setTime(sb);}else {if (hs){sb=sb.addSecs(bcfark+ctfark);s3ble->setTime(sb);}}
        if(ogleArasi==4&&!hs){hs=true;s4ble->setTime(sb);}else {if (hs){sb=sb.addSecs(bcfark+ctfark);s4ble->setTime(sb);}}
        if(ogleArasi==5&&!hs){hs=true;s5ble->setTime(sb);}else {if (hs){sb=sb.addSecs(bcfark+ctfark);s5ble->setTime(sb);}}
        if(ogleArasi==6&&!hs){hs=true;s6ble->setTime(sb);}else {if (hs){sb=sb.addSecs(bcfark+ctfark);s6ble->setTime(sb);}}
        if(ogleArasi==7&&!hs){hs=true;s7ble->setTime(sb);}else {if (hs){sb=sb.addSecs(bcfark+ctfark);s7ble->setTime(sb);}}
        if(ogleArasi==8&&!hs){hs=true;s8ble->setTime(sb);}else {if (hs){sb=sb.addSecs(bcfark+ctfark);s8ble->setTime(sb);}}
        if(ogleArasi==9&&!hs){hs=true;s9ble->setTime(sb);}else {if (hs){sb=sb.addSecs(bcfark+ctfark);s9ble->setTime(sb);}}
        if(ogleArasi==10&&!hs){hs=true;s10ble->setTime(sb);}else {if (hs){sb=sb.addSecs(bcfark+ctfark);s10ble->setTime(sb);}}
        if(ogleArasi==11&&!hs){hs=true;s11ble->setTime(sb);}else {if (hs){sb=sb.addSecs(bcfark+ctfark);s11ble->setTime(sb);}}
        if(ogleArasi==12&&!hs){hs=true;s12ble->setTime(sb);}else {if (hs){sb=sb.addSecs(bcfark+ctfark);s12ble->setTime(sb);}}
        if(ogleArasi==13&&!hs){hs=true;s13ble->setTime(sb);}else {if (hs){sb=sb.addSecs(bcfark+ctfark);s13ble->setTime(sb);}}
        if(ogleArasi==14&&!hs){hs=true;s14ble->setTime(sb);}else {if (hs){sb=sb.addSecs(bcfark+ctfark);s14ble->setTime(sb);}}


    //çıkış tenefüs
        hs=false;
        if(ogleArasi==2&&!hs){hs=true;s2cle->setTime(sc);}else {if (hs){sc=sc.addSecs(bcfark+ctfark);s2cle->setTime(sc);}}
        if(ogleArasi==3&&!hs){hs=true;s3cle->setTime(sc);}else {if (hs){sc=sc.addSecs(bcfark+ctfark);s3cle->setTime(sc);}}
        if(ogleArasi==4&&!hs){hs=true;s4cle->setTime(sc);}else {if (hs){sc=sc.addSecs(bcfark+ctfark);s4cle->setTime(sc);}}
        if(ogleArasi==5&&!hs){hs=true;s5cle->setTime(sc);}else {if (hs){sc=sc.addSecs(bcfark+ctfark);s5cle->setTime(sc);}}
        if(ogleArasi==6&&!hs){hs=true;s6cle->setTime(sc);}else {if (hs){sc=sc.addSecs(bcfark+ctfark);s6cle->setTime(sc);}}
        if(ogleArasi==7&&!hs){hs=true;s7cle->setTime(sc);}else {if (hs){sc=sc.addSecs(bcfark+ctfark);s7cle->setTime(sc);}}
        if(ogleArasi==8&&!hs){hs=true;s8cle->setTime(sc);}else {if (hs){sc=sc.addSecs(bcfark+ctfark);s8cle->setTime(sc);}}
        if(ogleArasi==9&&!hs){hs=true;s9cle->setTime(sc);}else {if (hs){sc=sc.addSecs(bcfark+ctfark);s9cle->setTime(sc);}}
        if(ogleArasi==10&&!hs){hs=true;s10cle->setTime(sc);}else {if (hs){sc=sc.addSecs(bcfark+ctfark);s10cle->setTime(sc);}}
        if(ogleArasi==11&&!hs){hs=true;s11cle->setTime(sc);}else {if (hs){sc=sc.addSecs(bcfark+ctfark);s11cle->setTime(sc);}}
        if(ogleArasi==12&&!hs){hs=true;s12cle->setTime(sc);}else {if (hs){sc=sc.addSecs(bcfark+ctfark);s12cle->setTime(sc);}}
        if(ogleArasi==13&&!hs){hs=true;s13cle->setTime(sc);}else {if (hs){sc=sc.addSecs(bcfark+ctfark);s13cle->setTime(sc);}}
        if(ogleArasi==14&&!hs){hs=true;s14cle->setTime(sc);}else {if (hs){sc=sc.addSecs(bcfark+ctfark);s14cle->setTime(sc);}}


 });
/******************************************************************/


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
        int derssayisi=0;
        if(listGetLine(ayarlist,"derssayisi")!="")
         derssayisi=listGetLine(ayarlist,"derssayisi").split("|")[2].toInt();

        int girissaniye,baslamasaniye,cikissaniye,tenefussaniye,gbfark,bcfark,ctfark;
        QTime sg=s1gle->time();//Giriş
        QTime sb=s1ble->time();//Başlama
        QTime sc=s1cle->time();//Çıkış
        QTime st=tenefusson->time();//tenefüs bitiş
        girissaniye=sg.hour()*60*60+sg.minute()*60+sg.second();
        baslamasaniye=sb.hour()*60*60+sb.minute()*60+sb.second();
        cikissaniye=sc.hour()*60*60+sc.minute()*60+sc.second();
        tenefussaniye=st.hour()*60*60+st.minute()*60+st.second();

        gbfark=baslamasaniye-girissaniye;
        bcfark=cikissaniye-baslamasaniye;
        ctfark=tenefussaniye-cikissaniye;
        //ctfark--;
        QStringList saathilist;
        int gecikme=60;
        saathilist.append(tn+"|"+saatToSaniye(torenbaslama->time()));
        QTime anons=s1cle->time();
        anons=anons.addSecs(gecikme);
        QTime tenefus=s1cle->time();

        tenefus=tenefus.addSecs(ctfark-gecikme);
       if(derssayisi>=1)
               saathilist.append(gn+"1"+"|"+saatToSaniye(s1gle->time())+"|"+saatToSaniye(s1ble->time())+"|"+saatToSaniye(s1cle->time()));

        anons=s2cle->time();anons=anons.addSecs(gecikme);tenefus=s2cle->time();
        tenefus=tenefus.addSecs(ctfark-gecikme);
      if(derssayisi>=2)
               saathilist.append(gn+"2"+"|"+saatToSaniye(s2gle->time())+"|"+saatToSaniye(s2ble->time())+"|"+saatToSaniye(s2cle->time()));
        anons=s3cle->time();anons=anons.addSecs(gecikme);tenefus=s3cle->time();
        tenefus=tenefus.addSecs(ctfark-gecikme);
        if(derssayisi>=3)
        saathilist.append(gn+"3"+"|"+saatToSaniye(s3gle->time())+"|"+saatToSaniye(s3ble->time())+"|"+saatToSaniye(s3cle->time()));

        anons=s4cle->time();anons=anons.addSecs(gecikme);tenefus=s4cle->time();
        tenefus=tenefus.addSecs(ctfark-gecikme);
        if(derssayisi>=4)
        saathilist.append(gn+"4"+"|"+saatToSaniye(s4gle->time())+"|"+saatToSaniye(s4ble->time())+"|"+saatToSaniye(s4cle->time()));
        anons=s5cle->time();anons=anons.addSecs(gecikme);tenefus=s5cle->time();
        tenefus=tenefus.addSecs(ctfark-gecikme);
        if(derssayisi>=5)
        saathilist.append(gn+"5"+"|"+saatToSaniye(s5gle->time())+"|"+saatToSaniye(s5ble->time())+"|"+saatToSaniye(s5cle->time()));
        anons=s6cle->time();anons=anons.addSecs(gecikme);tenefus=s6cle->time();
        tenefus=tenefus.addSecs(ctfark-gecikme);
        if(derssayisi>=6)
        saathilist.append(gn+"6"+"|"+saatToSaniye(s6gle->time())+"|"+saatToSaniye(s6ble->time())+"|"+saatToSaniye(s6cle->time()));
        anons=s7cle->time();anons=anons.addSecs(gecikme);tenefus=s7cle->time();
        tenefus=tenefus.addSecs(ctfark-gecikme);
        if(derssayisi>=7)
        saathilist.append(gn+"7"+"|"+saatToSaniye(s7gle->time())+"|"+saatToSaniye(s7ble->time())+"|"+saatToSaniye(s7cle->time()));
        anons=s8cle->time();anons=anons.addSecs(gecikme);tenefus=s8cle->time();
        tenefus=tenefus.addSecs(ctfark-gecikme);
        if(derssayisi>=8)
        saathilist.append(gn+"8"+"|"+saatToSaniye(s8gle->time())+"|"+saatToSaniye(s8ble->time())+"|"+saatToSaniye(s8cle->time()));
        anons=s9cle->time();anons=anons.addSecs(gecikme);tenefus=s9cle->time();
        tenefus=tenefus.addSecs(ctfark-gecikme);
        if(derssayisi>=9)
        saathilist.append(gn+"9"+"|"+saatToSaniye(s9gle->time())+"|"+saatToSaniye(s9ble->time())+"|"+saatToSaniye(s9cle->time()));
        anons=s10cle->time();anons=anons.addSecs(gecikme);tenefus=s10cle->time();
        tenefus=tenefus.addSecs(ctfark-gecikme);
        if(derssayisi>=10)
        saathilist.append(gn+"10"+"|"+saatToSaniye(s10gle->time())+"|"+saatToSaniye(s10ble->time())+"|"+saatToSaniye(s10cle->time()));
        anons=s11cle->time();anons=anons.addSecs(gecikme);tenefus=s11cle->time();
        tenefus=tenefus.addSecs(ctfark-gecikme);
        if(derssayisi>=11)
        saathilist.append(gn+"11"+"|"+saatToSaniye(s11gle->time())+"|"+saatToSaniye(s11ble->time())+"|"+saatToSaniye(s11cle->time()));
        anons=s12cle->time();anons=anons.addSecs(gecikme);tenefus=s12cle->time();
        tenefus=tenefus.addSecs(ctfark-gecikme);
        if(derssayisi>=12)
        saathilist.append(gn+"12"+"|"+saatToSaniye(s12gle->time())+"|"+saatToSaniye(s12ble->time())+"|"+saatToSaniye(s12cle->time()));
        anons=s13cle->time();anons=anons.addSecs(gecikme);tenefus=s13cle->time();
        tenefus=tenefus.addSecs(ctfark-gecikme);
        if(derssayisi>=13)
        saathilist.append(gn+"13"+"|"+saatToSaniye(s13gle->time())+"|"+saatToSaniye(s13ble->time())+"|"+saatToSaniye(s13cle->time()));
        anons=s14cle->time();anons=anons.addSecs(gecikme);tenefus=s14cle->time();
        tenefus=tenefus.addSecs(ctfark-gecikme);
        if(derssayisi>=14)
        saathilist.append(gn+"14"+"|"+saatToSaniye(s14gle->time())+"|"+saatToSaniye(s14ble->time())+"|"+saatToSaniye(s14cle->time()));

        QStringList listconf=fileToList("e-zil.conf");
        listconf=listMerge(saathilist,listconf,0);
        listToFile(listconf,"e-zil.conf");
        init();
 });
    int ogleArasi=0;
            if(listGetLine(ayarlist,"moladerssaati")!="")
               ogleArasi=listGetLine(ayarlist,"moladerssaati").split("|")[2].toInt();

    // auto widget = new QWidget;
    auto layout = new QGridLayout(ayarPage);
   /// layout->setContentsMargins(0, 0, 0,0);
    // layout->setVerticalSpacing(4);
    //layout->setColumnMinimumWidth(0, 37);
    //layout->addWidget(adLabel, 2,0,1,2);
   // layout->addWidget(new QLabel("<font size=1>Tüm Saatlere Uygulanacak 1 Saatlik Bilgi</font>"),0,0,1,3,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=2>Tören Saati</font>"),4,0,1,1,Qt::AlignHCenter);
   //  layout->addWidget(new QLabel("<font size=2>Öğrenci Saati</font>"),4,1,1,1,Qt::AlignHCenter);
   //  layout->addWidget(new QLabel("<font size=2>Öğretmen Başlama</font>"),4,2,1,1,Qt::AlignHCenter);
  //   layout->addWidget(new QLabel("<font size=2>Ders Çıkış</font>"),4,3,1,1,Qt::AlignHCenter);
    // layout->addWidget(new QLabel("<font size=2>Teneffüs Bitiş</font>"),4,4,1,1,Qt::AlignHCenter);
     layout->addWidget(torenbaslama, 4,1,1,1); torenbaslama->setStyleSheet("background-color: #ffaaaa;");
    // layout->addWidget(sgle, 6,1,1,1);
   //  layout->addWidget(sble, 6,2,1,1);
    // layout->addWidget(scle, 6,3,1,1);
    // layout->addWidget(tenefusson, 6,4,1,1);
     QLabel *uyari=new QLabel();
     uyari->setText("Örnek saatlerde öğrenci giriş saati ile öğretmen giriş saati arasındaki süre tenefüs süresinden kısa olmalıdır..");
     uyari->setStyleSheet("font-size:9px;color: #ff0000;");
     uyari->setFixedWidth(this->width());
     QLabel *uyari1=new QLabel();
     uyari1->setText("Öğrenci veya Öğretmen giriş saati kullanılmıyorsa öğrenci ve öğretmen giriş saatini aynı yapınız..");
     uyari1->setStyleSheet("font-size:9px;color: #0000ff;");
     uyari1->setFixedWidth(this->width());

     layout->addWidget(uyari,5,0,1,4,Qt::AlignHCenter);
     layout->addWidget(uyari1,6,0,1,4,Qt::AlignHCenter);

       // layout->addWidget(saatUyarlaButton, 8,0,1,2);

        //layout->addWidget(ayarKaydetButton, 8,4,1,1);
     layout->addWidget(saatUyarlaButton, 8,0,1,2);
     layout->addWidget(haftaUyarlaButton, 8,2,1,2);
     layout->addWidget(ayarKaydetButton, 8,4,1,1);


    layout->addWidget(new QLabel("<font size=2>Öğrenci Saati</font>"),9,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=2>Öğretmen Saati</font>"),9,2,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=2>Çıkış Saati</font>"),9,3,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=2>Teneffüs Bitiş</font>"),9,4,1,1,Qt::AlignHCenter);

if(derssayisi>=1){
    layout->addWidget(new QLabel("<font size=1>1. Ders</font>"),10,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s1gle, 10,1,1,1); s1gle->setStyleSheet("background-color: #ffaaaa;");
    layout->addWidget(s1ble, 10,2,1,1);s1ble->setStyleSheet("background-color: #ffaaaa;");
    layout->addWidget(s1cle, 10,3,1,1);s1cle->setStyleSheet("background-color: #ffaaaa;");
    layout->addWidget(tenefusson, 10,4,1,1);tenefusson->setStyleSheet("background-color: #ffaaaa;");
}

 if(ogleArasi==1)
{
    layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),11,1,1,3,Qt::AlignHCenter);
    layout->addWidget(MolaSonrasiSaatUyarlaButton,12,1,1,3,Qt::AlignHCenter);

}
 if(derssayisi>=2){
    layout->addWidget(new QLabel("<font size=1>2. Ders</font>"),13,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s2gle, 13,1,1,1);
    layout->addWidget(s2ble, 13,2,1,1);
    layout->addWidget(s2cle, 13,3,1,1);
 }
    if(ogleArasi==2)
    {
        layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),14,1,1,3,Qt::AlignHCenter);
         layout->addWidget(MolaSonrasiSaatUyarlaButton,15,1,1,3,Qt::AlignHCenter);
         s3gle->setStyleSheet("background-color: #ffaaaa;");
         s3ble->setStyleSheet("background-color: #ffaaaa;");
         s3cle->setStyleSheet("background-color: #ffaaaa;");

    }
if(derssayisi>=3){
    layout->addWidget(new QLabel("<font size=1>3. Ders</font>"),16,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s3gle, 16,1,1,1);
    layout->addWidget(s3ble, 16,2,1,1);
    layout->addWidget(s3cle, 16,3,1,1);
}
    if(ogleArasi==3)
    {
        layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),17,1,1,3,Qt::AlignHCenter);
        layout->addWidget(MolaSonrasiSaatUyarlaButton,18,1,1,3,Qt::AlignHCenter);
        s4gle->setStyleSheet("background-color: #ffaaaa;");
        s4ble->setStyleSheet("background-color: #ffaaaa;");
        s4cle->setStyleSheet("background-color: #ffaaaa;");
    }
    if(derssayisi>=4){
    layout->addWidget(new QLabel("<font size=1>4. Ders</font>"),19,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s4gle, 19,1,1,1);
    layout->addWidget(s4ble, 19,2,1,1);
    layout->addWidget(s4cle, 19,3,1,1);
    }
            if(ogleArasi==4)
            {
                layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),20,1,1,3,Qt::AlignHCenter);
                layout->addWidget(MolaSonrasiSaatUyarlaButton,21,1,1,3,Qt::AlignHCenter);
                s5gle->setStyleSheet("background-color: #ffaaaa;");
                s5ble->setStyleSheet("background-color: #ffaaaa;");
                s5cle->setStyleSheet("background-color: #ffaaaa;");
            }
if(derssayisi>=5){
    layout->addWidget(new QLabel("<font size=1>5. Ders</font>"),22,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s5gle, 22,1,1,1);
    layout->addWidget(s5ble, 22,2,1,1);
    layout->addWidget(s5cle, 22,3,1,1);
}
            if(ogleArasi==5)
            {
                layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),23,1,1,3,Qt::AlignHCenter);
                layout->addWidget(MolaSonrasiSaatUyarlaButton,24,1,1,3,Qt::AlignHCenter);
                s6gle->setStyleSheet("background-color: #ffaaaa;");
                s6ble->setStyleSheet("background-color: #ffaaaa;");
                s6cle->setStyleSheet("background-color: #ffaaaa;");
            }
if(derssayisi>=6){
    layout->addWidget(new QLabel("<font size=1>6. Ders</font>"),25,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s6gle, 25,1,1,1);
    layout->addWidget(s6ble, 25,2,1,1);
    layout->addWidget(s6cle, 25,3,1,1);
}
            if(ogleArasi==6)
            {
                layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),26,1,1,3,Qt::AlignHCenter);
                layout->addWidget(MolaSonrasiSaatUyarlaButton,27,1,1,3,Qt::AlignHCenter);
                s7gle->setStyleSheet("background-color: #ffaaaa;");
                s7ble->setStyleSheet("background-color: #ffaaaa;");
                s7cle->setStyleSheet("background-color: #ffaaaa;");
            }
if(derssayisi>=7){
    layout->addWidget(new QLabel("<font size=1>7. Ders</font>"),28,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s7gle, 28,1,1,1);
    layout->addWidget(s7ble, 28,2,1,1);
    layout->addWidget(s7cle, 28,3,1,1);
}
            if(ogleArasi==7)
            {
                layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),29,1,1,3,Qt::AlignHCenter);
                layout->addWidget(MolaSonrasiSaatUyarlaButton,30,1,1,3,Qt::AlignHCenter);
                s8gle->setStyleSheet("background-color: #ffaaaa;");
                s8ble->setStyleSheet("background-color: #ffaaaa;");
                s8cle->setStyleSheet("background-color: #ffaaaa;");
            }
if(derssayisi>=8){
    layout->addWidget(new QLabel("<font size=1>8. Ders</font>"),31,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s8gle, 31,1,1,1);
    layout->addWidget(s8ble, 31,2,1,1);
    layout->addWidget(s8cle, 31,3,1,1);
}
            if(ogleArasi==8)
            {
                layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),32,1,1,3,Qt::AlignHCenter);
                layout->addWidget(MolaSonrasiSaatUyarlaButton,33,1,1,3,Qt::AlignHCenter);
                s9gle->setStyleSheet("background-color: #ffaaaa;");
                s9ble->setStyleSheet("background-color: #ffaaaa;");
                s9cle->setStyleSheet("background-color: #ffaaaa;");
            }
if(derssayisi>=9){
    layout->addWidget(new QLabel("<font size=1>9. Ders</font>"),34,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s9gle, 34,1,1,1);
    layout->addWidget(s9ble, 34,2,1,1);
    layout->addWidget(s9cle, 34,3,1,1);
}
            if(ogleArasi==9)
            {
                layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),35,1,1,3,Qt::AlignHCenter);
                layout->addWidget(MolaSonrasiSaatUyarlaButton,36,1,1,3,Qt::AlignHCenter);
                s10gle->setStyleSheet("background-color: #ffaaaa;");
                s10ble->setStyleSheet("background-color: #ffaaaa;");
                s10cle->setStyleSheet("background-color: #ffaaaa;");
            }
if(derssayisi>=10){
    layout->addWidget(new QLabel("<font size=1>10. Ders</font>"),37,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s10gle, 37,1,1,1);
    layout->addWidget(s10ble, 37,2,1,1);
    layout->addWidget(s10cle, 37,3,1,1);
}
            if(ogleArasi==10)
            {
                layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),38,1,1,3,Qt::AlignHCenter);
                layout->addWidget(MolaSonrasiSaatUyarlaButton,39,1,1,3,Qt::AlignHCenter);
                s11gle->setStyleSheet("background-color: #ffaaaa;");
                s11ble->setStyleSheet("background-color: #ffaaaa;");
                s11cle->setStyleSheet("background-color: #ffaaaa;");
            }
if(derssayisi>=11){
    layout->addWidget(new QLabel("<font size=1>11. Ders</font>"),40,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s11gle, 40,1,1,1);
    layout->addWidget(s11ble, 40,2,1,1);
    layout->addWidget(s11cle, 40,3,1,1);
}
            if(ogleArasi==11)
            {
                layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),41,1,1,3,Qt::AlignHCenter);
                layout->addWidget(MolaSonrasiSaatUyarlaButton,41,1,1,3,Qt::AlignHCenter);
                s12gle->setStyleSheet("background-color: #ffaaaa;");
                s12ble->setStyleSheet("background-color: #ffaaaa;");
                s12cle->setStyleSheet("background-color: #ffaaaa;");
            }
if(derssayisi>=12){
    layout->addWidget(new QLabel("<font size=1>12. Ders</font>"),42,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s12gle, 42,1,1,1);
    layout->addWidget(s12ble, 42,2,1,1);
    layout->addWidget(s12cle, 42,3,1,1);
}
            if(ogleArasi==12)
            {
                layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),43,1,1,3,Qt::AlignHCenter);
                layout->addWidget(MolaSonrasiSaatUyarlaButton,43,1,1,3,Qt::AlignHCenter);
                s13gle->setStyleSheet("background-color: #ffaaaa;");
                s13ble->setStyleSheet("background-color: #ffaaaa;");
                s13cle->setStyleSheet("background-color: #ffaaaa;");
            }
if(derssayisi>=13){
    layout->addWidget(new QLabel("<font size=1>13. Ders</font>"),44,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s13gle, 44,1,1,1);
    layout->addWidget(s13ble, 44,2,1,1);
    layout->addWidget(s13cle, 44,3,1,1);
}
            if(ogleArasi==13)
            {
                layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),45,1,1,3,Qt::AlignHCenter);
                layout->addWidget(MolaSonrasiSaatUyarlaButton,46,1,1,3,Qt::AlignHCenter);
                s14gle->setStyleSheet("background-color: #ffaaaa;");
                s14ble->setStyleSheet("background-color: #ffaaaa;");
                s14cle->setStyleSheet("background-color: #ffaaaa;");
            }
if(derssayisi>=14){
    layout->addWidget(new QLabel("<font size=1>14. Ders</font>"),47,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s14gle, 47,1,1,1);
    layout->addWidget(s14ble, 47,2,1,1);
    layout->addWidget(s14cle, 47,3,1,1);
}
 //   layout->addWidget(new QLabel("<font size=1>Ayarları Kaydet</font>"),30,1,1,1,Qt::AlignHCenter);
     // layout->setColumnStretch(6, 255);

    return ayarPage;
}


#endif // SAATHI_H
