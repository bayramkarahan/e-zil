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
    DatabaseHelper *db=new DatabaseHelper(localDir+"e-zil.json");
    QJsonArray liste1 = db->Ara("recordtype", "settings");
    QJsonObject ayarlar;

    if (!liste1.isEmpty()) {
        ayarlar = liste1.first().toObject();
    }
    ///qDebug()<<"ayar"<<ayarlar;
    int derssayisi=0;
    if (ayarlar.contains("derssayisi"))
        derssayisi=ayarlar["derssayisi"].toString().toInt();


    //qDebug()<<"gün:"<<guns<<"desr sayısı:"<<derssayisi;
    QString gn=QString::number(guns)+"s";
    QString tn=QString::number(guns)+"storen";
    QWidget *ayarPage=new QWidget();
    ayarPage->setFixedWidth(en*30);
    ayarPage->setFixedHeight(200+derssayisi*25);
    /*******************************************************/
     // 16 ders için 3 time edit: giriş - ders başlangıç - ders bitiş

    QVector<DersSaatleri> ders(16);

    // Oluştur
    for (int i = 0; i < 16; ++i)
    {
        ders[i].toren     = new QTimeEdit(ayarPage);
        ders[i].giris     = new QTimeEdit(ayarPage);
        ders[i].baslangic = new QTimeEdit(ayarPage);
        ders[i].cikis     = new QTimeEdit(ayarPage);
        ders[i].teneffus  = new QTimeEdit(ayarPage);

        ders[i].toren->setDisplayFormat("hh:mm");
        ders[i].giris->setDisplayFormat("hh:mm");
        ders[i].baslangic->setDisplayFormat("hh:mm");
        ders[i].cikis->setDisplayFormat("hh:mm");
        ders[i].teneffus->setDisplayFormat("hh:mm");
        // Ders sayısına göre gizle
        if (i>0)
        {
            ders[i].toren->hide();
            ders[i].teneffus->hide();

        }
        if ((i+1)>derssayisi)
        {
            ders[i].toren->hide();
            ders[i].giris->hide();
            ders[i].baslangic->hide();
            ders[i].cikis->hide();
            ders[i].teneffus->hide();
        }
    }


    /*********************Sabah Tören Giriş***********************************/
    // Önce tüm ders timeedit'lerini temizle
    for (int i = 0; i < 16; i++) {
        ders[i].toren->setTime(QTime(0,0));
        ders[i].giris->setTime(QTime(0,0));
        ders[i].baslangic->setTime(QTime(0,0));
        ders[i].cikis->setTime(QTime(0,0));
        ders[i].teneffus->setTime(QTime(0,0));
    }
    QJsonArray liste=db->Ara("gun",gn);
    for (const QJsonValue &val : liste)
    {
        if (!val.isObject()) continue;
        QJsonObject obj = val.toObject();

        QString tip = obj["recordtype"].toString();
        int derssaat=obj["ders"].toInt();
        //QString toren=obj["toren"].toString();

        derssaat--;
        //qDebug()<<obj<<derssaat;
        if (obj.contains("toren")){
            QString toren=obj["toren"].toString();
            ders[derssaat].toren->setTime(saniyeToSaat(toren));
        }
        if (obj.contains("giris")){
            QString giris=obj["giris"].toString();
            ders[derssaat].giris->setTime(saniyeToSaat(giris));
        }
        if (obj.contains("baslangic")){
            QString baslangic=obj["baslangic"].toString();
            ders[derssaat].baslangic->setTime(saniyeToSaat(baslangic));
        }
        if (obj.contains("cikis")){
            QString cikis=obj["cikis"].toString();
            ders[derssaat].cikis->setTime(saniyeToSaat(cikis));
        }
        if (obj.contains("teneffus")){
            QString teneffus=obj["teneffus"].toString();
            ders[derssaat].teneffus->setTime(saniyeToSaat(teneffus));
        }
    }



QPushButton *haftaUyarlaButton= new QPushButton;
// haftaUyarlaButton->setFixedSize(150, 30);
// haftaUyarlaButton->setIconSize(QSize(450,30));
haftaUyarlaButton->setText("Haftaya Uyarla");
haftaUyarlaButton->setStyleSheet("Text-align:center");
// ayarKaydetButton->setFlat(true);
// kilitButton->setIcon(QIcon(":icons/saveprofile.png"));
if(guns!=1) haftaUyarlaButton->hide();
    connect(haftaUyarlaButton, &QPushButton::clicked, [=]() {

    DatabaseHelper *db = new DatabaseHelper(localDir + "e-zil.json");

        // Önce eski kayıtları temizle
        db->Sil("recordtype", "saat");
        // 1–7 arası günler
        for (int gun = 1; gun <= 7; gun++)
        {

            //
            // 🔵 Ders Saatlerini Kaydet
            //
            for (int i = 0; i < derssayisi; i++)
            {
                QJsonObject obj;
                obj["recordtype"] = "saat";
                obj["gun"] = QString::number(gun)+"s";
                obj["ders"] = i + 1;
                obj["toren"]     = saatToSaniye(ders[i].toren->time());
                obj["giris"]     = saatToSaniye(ders[i].giris->time());
                obj["baslangic"] = saatToSaniye(ders[i].baslangic->time());
                obj["cikis"]     = saatToSaniye(ders[i].cikis->time());
                obj["teneffus"]     = saatToSaniye(ders[i].teneffus->time());
                db->Ekle(obj);
            }
        }

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
    saatUyarlaButton->setText("Saatleri Uyarla");
    saatUyarlaButton->setStyleSheet("Text-align:center");


    connect(saatUyarlaButton, &QPushButton::clicked, [=]() {
        int derssayisi=0;
        if (ayarlar.contains("derssayisi"))
            derssayisi=ayarlar["derssayisi"].toString().toInt();
         int ogleArasi=0;
        if (ayarlar.contains("moladerssaati"))
            ogleArasi=ayarlar["moladerssaati"].toString().toInt();
        int molasuresi=0;
        if (ayarlar.contains("molasuresi"))
        {
            QTime msure;
             msure=saniyeToSaat(ayarlar["molasuresi"].toString());
             molasuresi=msure.hour()*60*60+msure.minute()*60+msure.second();
        }

     QTime sg = ders[0].giris->time();   // s1gle karşılığı
     QTime sb = ders[0].baslangic->time();    // s1ble karşılığı
     QTime sc = ders[0].cikis->time();        // s1cle karşılığı
     QTime st = ders[0].teneffus->time();        // s1cle karşılığı
     int teneffussure = saatToSaniye(st).toInt()-saatToSaniye(sc).toInt();
     int derssure = saatToSaniye(sc).toInt()-saatToSaniye(sb).toInt();

     int ekleneceksure=teneffussure+derssure;
     qDebug()<<"saat uyarla"<<ogleArasi<<sg<<sb<<sc<<st<<teneffussure<<ekleneceksure<<molasuresi;

     for (int i = 1; i < derssayisi; ++i)
     {
         if(ogleArasi==i)
         {
             qDebug()<<"öğle arası"<<ogleArasi<<i;
             int girisbaslamafark=saatToSaniye(ders[i-1].baslangic->time()).toInt()-saatToSaniye(ders[i-1].giris->time()).toInt();

             int eksureg=saatToSaniye(ders[i-1].cikis->time()).toInt()+molasuresi-girisbaslamafark;
             ders[i].giris->setTime(saniyeToSaat(QString::number(eksureg)));
             // --- DERS BAŞLANGIÇ SAATİ ---
             int eksureb=saatToSaniye(ders[i-1].cikis->time()).toInt()+molasuresi;
             ders[i].baslangic->setTime(saniyeToSaat(QString::number(eksureb)));
             // --- DERS BİTİŞ SAATİ ---
             int eksurec=saatToSaniye(ders[i-1].cikis->time()).toInt()+molasuresi+derssure;
             ders[i].cikis->setTime(saniyeToSaat(QString::number(eksurec)));
             // --- TENEFFÜS SAATİ ---
             int eksuret=saatToSaniye(ders[i-1].cikis->time()).toInt()+molasuresi+derssure+teneffussure;
             ders[i].teneffus->setTime(saniyeToSaat(QString::number(eksuret)));
         }else{
             int eksureg=saatToSaniye(ders[i-1].giris->time()).toInt()+ekleneceksure;
             ders[i].giris->setTime(saniyeToSaat(QString::number(eksureg)));
             // --- DERS BAŞLANGIÇ SAATİ ---
             int eksureb=saatToSaniye(ders[i-1].baslangic->time()).toInt()+ekleneceksure;
             ders[i].baslangic->setTime(saniyeToSaat(QString::number(eksureb)));
             // --- DERS BİTİŞ SAATİ ---
             int eksurec=saatToSaniye(ders[i-1].cikis->time()).toInt()+ekleneceksure;
             ders[i].cikis->setTime(saniyeToSaat(QString::number(eksurec)));
             // --- TENEFFÜS SAATİ ---
             int eksuret=saatToSaniye(ders[i-1].teneffus->time()).toInt()+ekleneceksure;
             ders[i].teneffus->setTime(saniyeToSaat(QString::number(eksuret)));
         }
     }

 });
/************************mola sonrası**************************************/
    QPushButton *MolaSonrasiSaatUyarlaButton= new QPushButton;
   /// MolaSonrasiSaatUyarlaButton->setFixedSize(300, 30);
    ///MolaSonrasiSaatUyarlaButton->setIconSize(QSize(450,30));
    MolaSonrasiSaatUyarlaButton->setText("Mola Sonrası Saatleri Uyarla");
    MolaSonrasiSaatUyarlaButton->setStyleSheet("Text-align:center");


    connect(MolaSonrasiSaatUyarlaButton, &QPushButton::clicked, [=]() {

 });
/******************************************************************/

    QPushButton *temizleButton= new QPushButton;
    /// temizleButton->setFixedSize(150, 30);
    ///temizleButton->setIconSize(QSize(150,30));
    temizleButton->setText("Temizle");
    temizleButton->setStyleSheet("Text-align:center");
    //  temizleButton->setFlat(true);
    // temizleButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(temizleButton, &QPushButton::clicked, [=]() {
        DatabaseHelper *db = new DatabaseHelper(localDir + "e-zil.json");
        // Önce eski kayıtları temizle
        QString gnn=QString::number(guns)+"s";
        db->Sil("gun", gnn);
        for (int i = 0; i < 16; i++) {
            ders[i].toren->setTime(QTime(0,0));
            ders[i].giris->setTime(QTime(0,0));
            ders[i].baslangic->setTime(QTime(0,0));
            ders[i].cikis->setTime(QTime(0,0));
            ders[i].teneffus->setTime(QTime(0,0));
        }
     });

    QPushButton *ayarKaydetButton= new QPushButton;
   /// ayarKaydetButton->setFixedSize(150, 30);
    ///ayarKaydetButton->setIconSize(QSize(150,30));
    ayarKaydetButton->setText("Kaydet");
    ayarKaydetButton->setStyleSheet("Text-align:center");
  //  ayarKaydetButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

connect(ayarKaydetButton, &QPushButton::clicked, [=]() {
        DatabaseHelper *db = new DatabaseHelper(localDir + "e-zil.json");

        // Önce eski kayıtları temizle
         QString gnn=QString::number(guns)+"s";
        db->Sil("gun", gnn);

            for (int i = 0; i < derssayisi; i++)
            {
                QJsonObject obj;
                obj["recordtype"] = "saat";
                obj["gun"] = gnn;
                obj["ders"] = i + 1;
                obj["toren"]     = saatToSaniye(ders[i].toren->time());
                obj["giris"]     = saatToSaniye(ders[i].giris->time());
                obj["baslangic"] = saatToSaniye(ders[i].baslangic->time());
                obj["cikis"]     = saatToSaniye(ders[i].cikis->time());
                obj["teneffus"]     = saatToSaniye(ders[i].teneffus->time());
                db->Ekle(obj);
            }
 });
    int ogleArasi=0;

    if (ayarlar.contains("moladerssaati"))
        ogleArasi=ayarlar["moladerssaati"].toString().toInt();


    // auto widget = new QWidget;
    auto layout = new QGridLayout(ayarPage);
   /// layout->setContentsMargins(0, 0, 0,0);
    // layout->setVerticalSpacing(4);
    //layout->setColumnMinimumWidth(0, 37);
    //layout->addWidget(adLabel, 2,0,1,2);
   // layout->addWidget(new QLabel("<font size=1>Tüm Saatlere Uygulanacak 1 Saatlik Bilgi</font>"),0,0,1,3,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=2>Tören Saati</font>"),4,0,1,1,Qt::AlignHCenter);
     layout->addWidget(ders[0].toren, 4,1,1,1); ders[0].toren->setStyleSheet("background-color: #ffaaaa;");

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
     layout->addWidget(saatUyarlaButton, 8,0,1,2);
     layout->addWidget(haftaUyarlaButton, 8,2,1,1);
      layout->addWidget(temizleButton, 8,3,1,1);
     layout->addWidget(ayarKaydetButton, 8,4,1,1);


    layout->addWidget(new QLabel("<font size=2>Öğrenci Saati</font>"),9,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=2>Öğretmen Saati</font>"),9,2,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=2>Çıkış Saati</font>"),9,3,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=2>Teneffüs Bitiş</font>"),9,4,1,1,Qt::AlignHCenter);
    int ara=0;
    for(int j=0;j<derssayisi;j++)
    {
        //if(derssayisi>=1){
            layout->addWidget(new QLabel("<font size=1>"+QString::number(j+1)+". Ders</font>"),j+10+ara,0,1,1,Qt::AlignHCenter);
            layout->addWidget(ders[j].giris , j+10+ara,1,1,1); ders[j].giris->setStyleSheet("background-color: #ffaaaa;");
            layout->addWidget(ders[j].baslangic, j+10+ara,2,1,1);ders[j].baslangic->setStyleSheet("background-color: #ffaaaa;");
            layout->addWidget(ders[j].cikis, j+10+ara,3,1,1);ders[j].cikis->setStyleSheet("background-color: #ffaaaa;");
        //}

         if(j==0)
        {
          layout->addWidget(ders[0].teneffus, j+10+ara,4,1,1);ders[0].teneffus->setStyleSheet("background-color: #ffaaaa;");
          layout->addWidget(MolaSonrasiSaatUyarlaButton,j+10,1,1,3,Qt::AlignHCenter);

        }
         if(ogleArasi==j+1)
         {
            ara=2;
             layout->addWidget(new QLabel("<font size=1>*************** Mola ***************</font>"),j+10+ara-1,1,1,3,Qt::AlignHCenter);
             layout->addWidget(MolaSonrasiSaatUyarlaButton,j+10+ara,1,1,3,Qt::AlignHCenter);
             ders[j].giris->setStyleSheet("background-color: #ffaaaa;");
             ders[j].baslangic->setStyleSheet("background-color: #ffaaaa;");
             ders[j].cikis->setStyleSheet("background-color: #ffaaaa;");

         }

    }
    return ayarPage;
}

#endif // SAATHI_H
