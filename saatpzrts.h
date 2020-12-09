#ifndef SAATPZRTS_H
#define SAATPZRTS_H
QWidget *MainWindow::saatpzrts()
{

    QWidget *ayarPage=new QWidget();
    /*******************************************************/
    QStringList ayarlst=fileToList("e-zil-saatpzrts.conf");

    /*********************1. ders***********************************/
    QTimeEdit *s01gle=new QTimeEdit(ayarPage);
    s01gle->resize(100,25);
    //s01gle->setInputMask("00:00");
    if(listGetLine(ayarlst,"s01")!="")s01gle->setTime(QTime::fromString(listGetLine(ayarlst,"s01").split("|")[1]));

    QTimeEdit *s01cle=new QTimeEdit(ayarPage);
    s01cle->resize(100,25);
    //s01cle->setInputMask("00:00");
    if(listGetLine(ayarlst,"s01")!="")s01cle->setTime(QTime::fromString(listGetLine(ayarlst,"s01").split("|")[2]));

    QTimeEdit *s01tle=new QTimeEdit(ayarPage);
    s01tle->resize(100,25);
   // s01tle->setInputMask("00:00");
    if(listGetLine(ayarlst,"s01")!="")s01tle->setTime(QTime::fromString(listGetLine(ayarlst,"s01").split("|")[3]));

/**************************************************************/
    /**********************2.ders**********************************/
    QTimeEdit *s2gle=new QTimeEdit(ayarPage);
    s2gle->resize(100,25);
    // s2gle->setInputMask("00:00");
    if(listGetLine(ayarlst,"s2")!="")s2gle->setTime(QTime::fromString(listGetLine(ayarlst,"s2").split("|")[1]));

    QTimeEdit *s2cle=new QTimeEdit(ayarPage);
    s2cle->resize(100,25);
    // s2cle->setInputMask("00:00");
    if(listGetLine(ayarlst,"s2")!="")s2cle->setTime(QTime::fromString(listGetLine(ayarlst,"s2").split("|")[2]));

    QTimeEdit *s2tle=new QTimeEdit(ayarPage);
    s2tle->resize(100,25);
    // s2tle->setInputMask("00:00");
    if(listGetLine(ayarlst,"s2")!="")s2tle->setTime(QTime::fromString(listGetLine(ayarlst,"s2").split("|")[3]));

/**************************************************************/

    /************************3. ders********************************/
    QTimeEdit *s3gle=new QTimeEdit(ayarPage);
    s3gle->resize(100,25);
    if(listGetLine(ayarlst,"s3")!="")s3gle->setTime(QTime::fromString(listGetLine(ayarlst,"s3").split("|")[1]));

    QTimeEdit *s3cle=new QTimeEdit(ayarPage);
    s3cle->resize(100,25);
    if(listGetLine(ayarlst,"s3")!="")s3cle->setTime(QTime::fromString(listGetLine(ayarlst,"s3").split("|")[2]));

    QTimeEdit *s3tle=new QTimeEdit(ayarPage);
    s3tle->resize(100,25);
    if(listGetLine(ayarlst,"s3")!="")s3tle->setTime(QTime::fromString(listGetLine(ayarlst,"s3").split("|")[3]));

/**************************************************************/

    /********************4. ders**************************/
    QTimeEdit *s4gle=new QTimeEdit(ayarPage);
    s4gle->resize(100,25);
    if(listGetLine(ayarlst,"s4")!="")s4gle->setTime(QTime::fromString(listGetLine(ayarlst,"s4").split("|")[1]));

    QTimeEdit *s4cle=new QTimeEdit(ayarPage);
    s4cle->resize(100,25);
    if(listGetLine(ayarlst,"s4")!="")s4cle->setTime(QTime::fromString(listGetLine(ayarlst,"s4").split("|")[2]));

    QTimeEdit *s4tle=new QTimeEdit(ayarPage);
    s4tle->resize(100,25);
    if(listGetLine(ayarlst,"s4")!="")s4tle->setTime(QTime::fromString(listGetLine(ayarlst,"s4").split("|")[3]));

/**************************************************************/

    /**********************5. ders***************************/
    QTimeEdit *s5gle=new QTimeEdit(ayarPage);
    s5gle->resize(100,25);
    if(listGetLine(ayarlst,"s5")!="")s5gle->setTime(QTime::fromString(listGetLine(ayarlst,"s5").split("|")[1]));

    QTimeEdit *s5cle=new QTimeEdit(ayarPage);
    s5cle->resize(100,25);
    if(listGetLine(ayarlst,"s5")!="")s5cle->setTime(QTime::fromString(listGetLine(ayarlst,"s5").split("|")[2]));

    QTimeEdit *s5tle=new QTimeEdit(ayarPage);
    s5tle->resize(100,25);
    if(listGetLine(ayarlst,"s5")!="")s5tle->setTime(QTime::fromString(listGetLine(ayarlst,"s5").split("|")[3]));

/**************************************************************/

    /**********************6. ders***************************/
    QTimeEdit *s6gle=new QTimeEdit(ayarPage);
    s6gle->resize(100,25);
    if(listGetLine(ayarlst,"s6")!="")s6gle->setTime(QTime::fromString(listGetLine(ayarlst,"s6").split("|")[1]));

    QTimeEdit *s6cle=new QTimeEdit(ayarPage);
    s6cle->resize(100,25);
    if(listGetLine(ayarlst,"s6")!="")s6cle->setTime(QTime::fromString(listGetLine(ayarlst,"s6").split("|")[2]));
    QTimeEdit *s6tle=new QTimeEdit(ayarPage);
    s6tle->resize(100,25);
    if(listGetLine(ayarlst,"s6")!="")s6tle->setTime(QTime::fromString(listGetLine(ayarlst,"s6").split("|")[3]));

/**************************************************************/

    /***********************7.ders***************************/
    QTimeEdit *s7gle=new QTimeEdit(ayarPage);
    s7gle->resize(100,25);
    if(listGetLine(ayarlst,"s7")!="")s7gle->setTime(QTime::fromString(listGetLine(ayarlst,"s7").split("|")[1]));

    QTimeEdit *s7cle=new QTimeEdit(ayarPage);
    s7cle->resize(100,25);
    if(listGetLine(ayarlst,"s7")!="")s7cle->setTime(QTime::fromString(listGetLine(ayarlst,"s7").split("|")[2]));

    QTimeEdit *s7tle=new QTimeEdit(ayarPage);
    s7tle->resize(100,25);
    if(listGetLine(ayarlst,"s7")!="")s7tle->setTime(QTime::fromString(listGetLine(ayarlst,"s7").split("|")[3]));

/**************************************************************/

    /***********************8. ders**************************/
    QTimeEdit *s8gle=new QTimeEdit(ayarPage);
    s8gle->resize(100,25);
    if(listGetLine(ayarlst,"s8")!="")s8gle->setTime(QTime::fromString(listGetLine(ayarlst,"s8").split("|")[1]));

    QTimeEdit *s8cle=new QTimeEdit(ayarPage);
    s8cle->resize(100,25);
    if(listGetLine(ayarlst,"s8")!="")s8cle->setTime(QTime::fromString(listGetLine(ayarlst,"s8").split("|")[2]));

    QTimeEdit *s8tle=new QTimeEdit(ayarPage);
    s8tle->resize(100,25);
    if(listGetLine(ayarlst,"s8")!="")s8tle->setTime(QTime::fromString(listGetLine(ayarlst,"s8").split("|")[3]));

/**************************************************************/

    /********************9.ders******************************/
    QTimeEdit *s9gle=new QTimeEdit(ayarPage);
    s9gle->resize(100,25);
    if(listGetLine(ayarlst,"s9")!="")s9gle->setTime(QTime::fromString(listGetLine(ayarlst,"s9").split("|")[1]));

    QTimeEdit *s9cle=new QTimeEdit(ayarPage);
    s9cle->resize(100,25);
    if(listGetLine(ayarlst,"s9")!="")s9cle->setTime(QTime::fromString(listGetLine(ayarlst,"s9").split("|")[2]));

    QTimeEdit *s9tle=new QTimeEdit(ayarPage);
    s9tle->resize(100,25);
    if(listGetLine(ayarlst,"s9")!="")s9tle->setTime(QTime::fromString(listGetLine(ayarlst,"s9").split("|")[3]));

/**************************************************************/
    /***********************10. ders*********************************/
    QTimeEdit *s10gle=new QTimeEdit(ayarPage);
    s10gle->resize(100,25);
    if(listGetLine(ayarlst,"s10")!="")s10gle->setTime(QTime::fromString(listGetLine(ayarlst,"s10").split("|")[1]));

    QTimeEdit *s10cle=new QTimeEdit(ayarPage);
    s10cle->resize(100,25);
    if(listGetLine(ayarlst,"s10")!="")s10cle->setTime(QTime::fromString(listGetLine(ayarlst,"s10").split("|")[2]));

    QTimeEdit *s10tle=new QTimeEdit(ayarPage);
    s10tle->resize(100,25);
    if(listGetLine(ayarlst,"s10")!="")s10tle->setTime(QTime::fromString(listGetLine(ayarlst,"s10").split("|")[3]));

/**************************************************************/

    /************************11. ders********************************/
    QTimeEdit *s11gle=new QTimeEdit(ayarPage);
    s11gle->resize(100,25);
    if(listGetLine(ayarlst,"s11")!="")s11gle->setTime(QTime::fromString(listGetLine(ayarlst,"s11").split("|")[1]));

    QTimeEdit *s11cle=new QTimeEdit(ayarPage);
    s11cle->resize(100,25);
    if(listGetLine(ayarlst,"s11")!="")s11cle->setTime(QTime::fromString(listGetLine(ayarlst,"s11").split("|")[2]));

    QTimeEdit *s11tle=new QTimeEdit(ayarPage);
    s11tle->resize(100,25);
    if(listGetLine(ayarlst,"s11")!="")s11tle->setTime(QTime::fromString(listGetLine(ayarlst,"s11").split("|")[3]));

/**************************************************************/

    /**********************12. ders**********************************/
    QTimeEdit *s12gle=new QTimeEdit(ayarPage);
    s12gle->resize(100,25);
    if(listGetLine(ayarlst,"s12")!="")s12gle->setTime(QTime::fromString(listGetLine(ayarlst,"s12").split("|")[1]));

    QTimeEdit *s12cle=new QTimeEdit(ayarPage);
    s12cle->resize(100,25);
    if(listGetLine(ayarlst,"s12")!="")s12cle->setTime(QTime::fromString(listGetLine(ayarlst,"s12").split("|")[2]));

    QTimeEdit *s12tle=new QTimeEdit(ayarPage);
    s12tle->resize(100,25);
    if(listGetLine(ayarlst,"s12")!="")s12tle->setTime(QTime::fromString(listGetLine(ayarlst,"s12").split("|")[3]));

/**************************************************************/


    /************************13. ders********************************/
    QTimeEdit *s13gle=new QTimeEdit(ayarPage);
    s13gle->resize(100,25);
    if(listGetLine(ayarlst,"s13")!="")s13gle->setTime(QTime::fromString(listGetLine(ayarlst,"s13").split("|")[1]));

    QTimeEdit *s13cle=new QTimeEdit(ayarPage);
    s13cle->resize(100,25);
    if(listGetLine(ayarlst,"s13")!="")s13cle->setTime(QTime::fromString(listGetLine(ayarlst,"s13").split("|")[2]));

    QTimeEdit *s13tle=new QTimeEdit(ayarPage);
    s13tle->resize(100,25);
    if(listGetLine(ayarlst,"s13")!="")s13tle->setTime(QTime::fromString(listGetLine(ayarlst,"s13").split("|")[3]));

/**************************************************************/

    /************************14. ders********************************/
    QTimeEdit *s14gle=new QTimeEdit(ayarPage);
    s14gle->resize(100,25);
    if(listGetLine(ayarlst,"s14")!="")s14gle->setTime(QTime::fromString(listGetLine(ayarlst,"s14").split("|")[1]));

    QTimeEdit *s14cle=new QTimeEdit(ayarPage);
    s14cle->resize(100,25);
    if(listGetLine(ayarlst,"s14")!="")s14cle->setTime(QTime::fromString(listGetLine(ayarlst,"s14").split("|")[2]));

    QTimeEdit *s14tle=new QTimeEdit(ayarPage);
    s14tle->resize(100,25);
    if(listGetLine(ayarlst,"s14")!="")s14tle->setTime(QTime::fromString(listGetLine(ayarlst,"s14").split("|")[3]));

/**************************************************************/
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() % 2) == 0)
        text[2] = ' ';


    /************************ornek ders********************************/
    QTimeEdit *sgle=new QTimeEdit(ayarPage);
    sgle->resize(60,25);
    if(listGetLine(ayarlst,"s01")!="")sgle->setTime(QTime::fromString(listGetLine(ayarlst,"s01").split("|")[1]));

    QTimeEdit *sble=new QTimeEdit(ayarPage);
    sble->resize(60,25);
    if(listGetLine(ayarlst,"s01")!="")sble->setTime(QTime::fromString(listGetLine(ayarlst,"s01").split("|")[2]));

    QTimeEdit *scle=new QTimeEdit(ayarPage);
    scle->resize(60,25);
    if(listGetLine(ayarlst,"s01")!="")scle->setTime(QTime::fromString(listGetLine(ayarlst,"s01").split("|")[3]));

    QTimeEdit *stle=new QTimeEdit(ayarPage);
    stle->resize(60,25);
    if(listGetLine(ayarlst,"s2")!="")stle->setTime(QTime::fromString(listGetLine(ayarlst,"s2").split("|")[2]));

    QPushButton *haftaUyarlaButton= new QPushButton;
    haftaUyarlaButton->setFixedSize(150, 30);
    haftaUyarlaButton->setIconSize(QSize(450,30));
    haftaUyarlaButton->setText("Tüm Haftaya Uyarla");
    haftaUyarlaButton->setStyleSheet("Text-align:center");
  //  ayarKaydetButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));



    connect(haftaUyarlaButton, &QPushButton::clicked, [=]() {
        QStringList saathilist=fileToList("e-zil-saatpzrts.conf");

        listToFile(saathilist,"e-zil-saatsl.conf");
        listToFile(saathilist,"e-zil-saatcrsmb.conf");
        listToFile(saathilist,"e-zil-saatprsmb.conf");
        listToFile(saathilist,"e-zil-saatcm.conf");
        listToFile(saathilist,"e-zil-saatcmrts.conf");
        listToFile(saathilist,"e-zil-saatpzr.conf");
});
    QPushButton *saatUyarlaButton= new QPushButton;
    saatUyarlaButton->setFixedSize(300, 30);
    saatUyarlaButton->setIconSize(QSize(450,30));
    saatUyarlaButton->setText("Tüm Ders Saatlerini Ayarla");
    saatUyarlaButton->setStyleSheet("Text-align:center");
  //  ayarKaydetButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));



    connect(saatUyarlaButton, &QPushButton::clicked, [=]() {

        QTime sg=sgle->time();
        QTime sb=sble->time();
        QTime sc=scle->time();
        QTime st=stle->time();

int girisdakika,baslamadakika,cikisdakika,tenefusdakika,gbfark,bcfark,ctfark;

        girisdakika=sg.hour()*60+sg.minute();
        baslamadakika=sb.hour()*60+sb.minute();
        cikisdakika=sc.hour()*60+sc.minute();
        tenefusdakika=st.hour()*60+st.minute();

        gbfark=baslamadakika-girisdakika;
        bcfark=cikisdakika-baslamadakika;
        ctfark=tenefusdakika-cikisdakika;


       // qDebug()<<"süre:"<<fark;

        //sg=sg.addSecs(fark*60);
        s01gle->setTime(sg);
        sg=sg.addSecs(bcfark*60+ctfark*60);s2gle->setTime(sg);
        sg=sg.addSecs(bcfark*60+ctfark*60);s3gle->setTime(sg);
        sg=sg.addSecs(bcfark*60+ctfark*60);s4gle->setTime(sg);
        sg=sg.addSecs(bcfark*60+ctfark*60);s5gle->setTime(sg);
        sg=sg.addSecs(bcfark*60+ctfark*60);s6gle->setTime(sg);
        sg=sg.addSecs(bcfark*60+ctfark*60);s7gle->setTime(sg);
        sg=sg.addSecs(bcfark*60+ctfark*60);s8gle->setTime(sg);
        sg=sg.addSecs(bcfark*60+ctfark*60);s9gle->setTime(sg);
        sg=sg.addSecs(bcfark*60+ctfark*60);s10gle->setTime(sg);
        sg=sg.addSecs(bcfark*60+ctfark*60);s11gle->setTime(sg);
        sg=sg.addSecs(bcfark*60+ctfark*60);s12gle->setTime(sg);
        sg=sg.addSecs(bcfark*60+ctfark*60);s13gle->setTime(sg);
        sg=sg.addSecs(bcfark*60+ctfark*60);s14gle->setTime(sg);

        sb=sble->time();
        //sb=sb.addSecs(fark*60);
        s01cle->setTime(sb);
        sb=sb.addSecs(bcfark*60+ctfark*60);s2cle->setTime(sb);
        sb=sb.addSecs(bcfark*60+ctfark*60);s3cle->setTime(sb);
        sb=sb.addSecs(bcfark*60+ctfark*60);s4cle->setTime(sb);
        sb=sb.addSecs(bcfark*60+ctfark*60);s5cle->setTime(sb);
        sb=sb.addSecs(bcfark*60+ctfark*60);s6cle->setTime(sb);
        sb=sb.addSecs(bcfark*60+ctfark*60);s7cle->setTime(sb);
        sb=sb.addSecs(bcfark*60+ctfark*60);s8cle->setTime(sb);
        sb=sb.addSecs(bcfark*60+ctfark*60);s9cle->setTime(sb);
        sb=sb.addSecs(bcfark*60+ctfark*60);s10cle->setTime(sb);
        sb=sb.addSecs(bcfark*60+ctfark*60);s11cle->setTime(sb);
        sb=sb.addSecs(bcfark*60+ctfark*60);s12cle->setTime(sb);
        sb=sb.addSecs(bcfark*60+ctfark*60);s13cle->setTime(sb);
        sb=sb.addSecs(bcfark*60+ctfark*60);s14cle->setTime(sb);

        sc=scle->time();
        //sc=sc.addSecs(fark*60);
        s01tle->setTime(sc);
        sc=sc.addSecs(bcfark*60+ctfark*60);s2tle->setTime(sc);
        sc=sc.addSecs(bcfark*60+ctfark*60);s3tle->setTime(sc);
        sc=sc.addSecs(bcfark*60+ctfark*60);s4tle->setTime(sc);
        sc=sc.addSecs(bcfark*60+ctfark*60);s5tle->setTime(sc);
        sc=sc.addSecs(bcfark*60+ctfark*60);s6tle->setTime(sc);
        sc=sc.addSecs(bcfark*60+ctfark*60);s7tle->setTime(sc);
        sc=sc.addSecs(bcfark*60+ctfark*60);s8tle->setTime(sc);
        sc=sc.addSecs(bcfark*60+ctfark*60);s9tle->setTime(sc);
        sc=sc.addSecs(bcfark*60+ctfark*60);s10tle->setTime(sc);
        sc=sc.addSecs(bcfark*60+ctfark*60);s11tle->setTime(sc);
        sc=sc.addSecs(bcfark*60+ctfark*60);s12tle->setTime(sc);
        sc=sc.addSecs(bcfark*60+ctfark*60);s13tle->setTime(sc);
        sc=sc.addSecs(bcfark*60+ctfark*60);s14tle->setTime(sc);

       // QTime fark=sb-sc;
       // qDebug()<<"süre:"<<fark;

       /*
        QTime time(17, 30);
        QTimeEdit te;
        te.setTime(time);
        */

//        listToFile(saathilist,"e-zil-saathi.conf");*/

 });
/**************************************************************/



    QPushButton *ayarKaydetButton= new QPushButton;
    ayarKaydetButton->setFixedSize(150, 30);
    ayarKaydetButton->setIconSize(QSize(150,30));
    ayarKaydetButton->setText("Ayarları Kaydet");
    ayarKaydetButton->setStyleSheet("Text-align:center");
  //  ayarKaydetButton->setFlat(true);
   // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(ayarKaydetButton, &QPushButton::clicked, [=]() {
     //   if(player->mediaStatus()==QMediaPlayer::PlayingState)
           // player->stop();
        QStringList saathilist;
        saathilist.append("s01|"+s01gle->text()+"|"+s01cle->text()+"|"+s01tle->text());
        saathilist.append("s2|"+s2gle->text()+"|"+s2cle->text()+"|"+s2tle->text());
        saathilist.append("s3|"+s3gle->text()+"|"+s3cle->text()+"|"+s3tle->text());
        saathilist.append("s4|"+s4gle->text()+"|"+s4cle->text()+"|"+s4tle->text());
        saathilist.append("s5|"+s5gle->text()+"|"+s5cle->text()+"|"+s5tle->text());
        saathilist.append("s6|"+s6gle->text()+"|"+s6cle->text()+"|"+s6tle->text());
        saathilist.append("s7|"+s7gle->text()+"|"+s7cle->text()+"|"+s7tle->text());
        saathilist.append("s8|"+s8gle->text()+"|"+s8cle->text()+"|"+s8tle->text());
        saathilist.append("s9|"+s9gle->text()+"|"+s9cle->text()+"|"+s9tle->text());
        saathilist.append("s10|"+s10gle->text()+"|"+s10cle->text()+"|"+s10tle->text());
        saathilist.append("s11|"+s11gle->text()+"|"+s11cle->text()+"|"+s11tle->text());
        saathilist.append("s12|"+s12gle->text()+"|"+s12cle->text()+"|"+s12tle->text());
        saathilist.append("s13|"+s13gle->text()+"|"+s13cle->text()+"|"+s13tle->text());
        saathilist.append("s14|"+s14gle->text()+"|"+s14cle->text()+"|"+s14tle->text());

        listToFile(saathilist,"e-zil-saatpzrts.conf");
 });

   // auto widget = new QWidget;
    auto layout = new QGridLayout(ayarPage);
    layout->setContentsMargins(0, 0, 0,0);
    layout->setVerticalSpacing(4);
    layout->setColumnMinimumWidth(0, 37);
    //layout->addWidget(adLabel, 2,0,1,2);
    layout->addWidget(new QLabel("<font size=2>İlk Ders Saati</font>"),6,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=2>Ders Başlama</font>"),6,2,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=2>Ders Çıkış</font>"),6,3,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=2>Teneffüs Bitiş</font>"),6,4,1,1,Qt::AlignHCenter);

    layout->addWidget(new QLabel("<font size=2>Tüm Saatlere Uygulanacak 1 Saatlik Bilgi</font>"),5,0,1,3,Qt::AlignHCenter);
    layout->addWidget(sgle, 7,1,1,1);
    layout->addWidget(sble, 7,2,1,1);
    layout->addWidget(scle, 7,3,1,1);
    layout->addWidget(stle, 7,4,1,1);

        layout->addWidget(saatUyarlaButton, 8,1,1,2);
        layout->addWidget(haftaUyarlaButton, 8,3,1,2);

    layout->addWidget(new QLabel("<font size=2>Giriş Saati</font>"),9,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=2>Başlama Saati</font>"),9,2,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=2>Çıkış Saati</font>"),9,3,1,1,Qt::AlignHCenter);

    layout->addWidget(new QLabel("<font size=1>1. Ders</font>"),10,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s01gle, 10,1,1,1);
    layout->addWidget(s01cle, 10,2,1,1);
    layout->addWidget(s01tle, 10,3,1,2);

    layout->addWidget(new QLabel("<font size=1>2. Ders</font>"),12,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s2gle, 12,1,1,1);
    layout->addWidget(s2cle, 12,2,1,1);
    layout->addWidget(s2tle, 12,3,1,2);

    layout->addWidget(new QLabel("<font size=1>3. Ders</font>"),14,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s3gle, 14,1,1,1);
    layout->addWidget(s3cle, 14,2,1,1);
    layout->addWidget(s3tle, 14,3,1,2);

    layout->addWidget(new QLabel("<font size=1>4. Ders</font>"),16,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s4gle, 16,1,1,1);
    layout->addWidget(s4cle, 16,2,1,1);
    layout->addWidget(s4tle, 16,3,1,2);

    layout->addWidget(new QLabel("<font size=1>5. Ders</font>"),18,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s5gle, 18,1,1,1);
    layout->addWidget(s5cle, 18,2,1,1);
    layout->addWidget(s5tle, 18,3,1,2);

    layout->addWidget(new QLabel("<font size=1>6. Ders</font>"),20,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s6gle, 20,1,1,1);
    layout->addWidget(s6cle, 20,2,1,1);
    layout->addWidget(s6tle, 20,3,1,2);

    layout->addWidget(new QLabel("<font size=1>7. Ders</font>"),22,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s7gle, 22,1,1,1);
    layout->addWidget(s7cle, 22,2,1,1);
    layout->addWidget(s7tle, 22,3,1,2);

    layout->addWidget(new QLabel("<font size=1>8. Ders</font>"),24,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s8gle, 24,1,1,1);
    layout->addWidget(s8cle, 24,2,1,1);
    layout->addWidget(s8tle, 24,3,1,2);

    layout->addWidget(new QLabel("<font size=1>9. Ders</font>"),26,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s9gle, 26,1,1,1);
    layout->addWidget(s9cle, 26,2,1,1);
    layout->addWidget(s9tle, 26,3,1,2);

    layout->addWidget(new QLabel("<font size=1>10. Ders</font>"),28,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s10gle, 28,1,1,1);
    layout->addWidget(s10cle, 28,2,1,1);
    layout->addWidget(s10tle, 28,3,1,2);

    layout->addWidget(new QLabel("<font size=1>11. Ders</font>"),30,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s11gle, 30,1,1,1);
    layout->addWidget(s11cle, 30,2,1,1);
    layout->addWidget(s11tle, 30,3,1,2);

    layout->addWidget(new QLabel("<font size=1>12. Ders</font>"),32,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s12gle, 32,1,1,1);
    layout->addWidget(s12cle, 32,2,1,1);
    layout->addWidget(s12tle, 32,3,1,2);

    layout->addWidget(new QLabel("<font size=1>13. Ders</font>"),34,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s13gle, 34,1,1,1);
    layout->addWidget(s13cle, 34,2,1,1);
    layout->addWidget(s13tle, 34,3,1,2);

    layout->addWidget(new QLabel("<font size=1>14. Ders</font>"),36,0,1,1,Qt::AlignHCenter);
    layout->addWidget(s14gle, 36,1,1,1);
    layout->addWidget(s14cle, 36,2,1,1);
    layout->addWidget(s14tle, 36,3,1,2);

    layout->addWidget(ayarKaydetButton, 38,2,1,1);


  //   layout->addWidget(new QLabel("<font size=1>Ayarları Kaydet</font>"),30,1,1,1,Qt::AlignHCenter);
      layout->setColumnStretch(6, 255);

    return ayarPage;
}


#endif // SAATHI_H
