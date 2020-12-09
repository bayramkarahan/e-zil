#ifndef MENU_H
#define MENU_H
#include<QWidgetAction>

/*
QMenu *MainWindow::kilitMenu()
{   QMenu *menu = new QMenu(this);

   QPushButton *kilitButton= new QPushButton;
   kilitButton->setFixedSize(150, 30);
   kilitButton->setIconSize(QSize(150,30));
   kilitButton->setText("Seçili Pc Kilitle");
   kilitButton->setStyleSheet("Text-align:left");
   kilitButton->setFlat(true);
  // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

   connect(kilitButton, &QPushButton::clicked, [=]() {
       QString komut="ekrankilit|"+lineEdit_message->text()+"|"+username->text()+"|"+password->text();
       lineEdit_message->setText(komut);
       //socketNumberLabel->setText("Broadcast");
       //socketNumberLabel->hide();
       //destlabel->setText("Hedef(Broadcast)");
       sendMessageInit();
       menu->close();
});

   QPushButton *kilitAllButton= new QPushButton;
   kilitAllButton->setFixedSize(150, 30);
   kilitAllButton->setIconSize(QSize(150,30));
   kilitAllButton->setText("Tüm Pc'leri Kilitle");
   kilitAllButton->setStyleSheet("Text-align:left");
   kilitAllButton->setFlat(true);
  // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

   connect(kilitAllButton, &QPushButton::clicked, [=]() {
       QString komut="ekrankilit|"+lineEdit_message->text()+"|"+username->text()+"|"+password->text();
       lineEdit_message->setText(komut);
       socketNumberLabel->setText("Broadcast");
       socketNumberLabel->hide();
       destlabel->setText("Hedef(Broadcast)");
       sendMessageInit();
        menu->close();
});


   QPushButton *kilitAcButton= new QPushButton;
   kilitAcButton->setFixedSize(150, 30);
   kilitAcButton->setIconSize(QSize(150,30));
   kilitAcButton->setText("Seçili Pc Kilit Aç");
   kilitAcButton->setStyleSheet("Text-align:left");
   kilitAcButton->setFlat(true);
  // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

   connect(kilitAcButton, &QPushButton::clicked, [=]() {
       QString komut="ekrankilitac|"+lineEdit_message->text()+"|"+username->text()+"|"+password->text();
       lineEdit_message->setText(komut);
       //socketNumberLabel->setText("Broadcast");
       //socketNumberLabel->hide();
       //destlabel->setText("Hedef(Broadcast)");
       sendMessageInit();
        menu->close();
});

   QPushButton *kilitAcAllButton= new QPushButton;
   kilitAcAllButton->setFixedSize(150, 30);
   kilitAcAllButton->setIconSize(QSize(150,30));
   kilitAcAllButton->setText("Tüm Pc'leri Kilit Aç");
   kilitAcAllButton->setStyleSheet("Text-align:left");
   kilitAcAllButton->setFlat(true);
  // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

   connect(kilitAcAllButton, &QPushButton::clicked, [=]() {
       QString komut="ekrankilitac|"+lineEdit_message->text()+"|"+username->text()+"|"+password->text();
       lineEdit_message->setText(komut);
       socketNumberLabel->setText("Broadcast");
       socketNumberLabel->hide();
       destlabel->setText("Hedef(Broadcast)");
       sendMessageInit();
        menu->close();
});



    auto widget = new QWidget;
    auto layout = new QGridLayout(widget);
    layout->setContentsMargins(0, 0, 0,0);
    layout->setVerticalSpacing(0);
  //  layout->setColumnMinimumWidth(0, 37);
    layout->addWidget(kilitButton, 2,0,1,2);
    layout->addWidget(kilitAllButton, 3,0,1,2);
    layout->addWidget(kilitAcButton, 4,0,1,2);
    layout->addWidget(kilitAcAllButton, 5,0,1,2);

    // layout->addWidget(new QLabel("<font size=1>Ayarları Kaydet</font>"),6,1,1,1,Qt::AlignHCenter);
     // layout->setColumnStretch(6, 255);

    // add a widget action to the context menu
    auto wa = new QWidgetAction(this);
  //  wa->setIcon(QIcon(":/icon1"));
    wa->setDefaultWidget(widget);
    menu->addAction(wa);

     menu->setStyleSheet("QMenu { width: 150 px; height: 120 px; }");
   return menu;
}

QMenu *MainWindow::kapatMenu()
{   QMenu *menu = new QMenu(this);

   QPushButton *kilitButton= new QPushButton;
   kilitButton->setFixedSize(150, 30);
   kilitButton->setIconSize(QSize(150,30));
   kilitButton->setText("Seçili Pc Kapat");
   kilitButton->setFlat(true);
  // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

   connect(kilitButton, &QPushButton::clicked, [=]() {
       QString komut="pckapat|init 0|"+username->text()+"|"+password->text();
       lineEdit_message->setText(komut);
     //  socketNumberLabel->setText("Broadcast");
      // socketNumberLabel->hide();
      // destlabel->setText("Hedef(Broadcast)");
       sendMessageInit();
});

   QPushButton *kilitAllButton= new QPushButton;
   kilitAllButton->setFixedSize(150, 30);
   kilitAllButton->setIconSize(QSize(150,30));
   kilitAllButton->setText("Tüm Pc'leri Kapat");
   kilitAllButton->setFlat(true);
  // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

   connect(kilitAllButton, &QPushButton::clicked, [=]() {
       QString komut="pckapat|init 0|"+username->text()+"|"+password->text();
       lineEdit_message->setText(komut);
       socketNumberLabel->setText("Broadcast");
       socketNumberLabel->hide();
       destlabel->setText("Hedef(Broadcast)");
       sendMessageInit();
});

    auto widget = new QWidget;
    auto layout = new QGridLayout(widget);
    layout->setContentsMargins(0, 0, 0,0);
    layout->setVerticalSpacing(0);
  //  layout->setColumnMinimumWidth(0, 37);
    layout->addWidget(kilitButton, 2,0,1,2);
   layout->addWidget(kilitAllButton, 3,0,1,2);
    // layout->addWidget(new QLabel("<font size=1>Ayarları Kaydet</font>"),6,1,1,1,Qt::AlignHCenter);
      //layout->setColumnStretch(6, 255);

    // add a widget action to the context menu
    auto wa = new QWidgetAction(this);
  //  wa->setIcon(QIcon(":/icon1"));
    wa->setDefaultWidget(widget);
    menu->addAction(wa);

     menu->setStyleSheet("QMenu { width: 150 px; height: 60 px; }");
   return menu;
}

QMenu *MainWindow::duyuruMesajMenu()
{   QMenu *menu = new QMenu(this);

   QPushButton *kilitButton= new QPushButton;
   kilitButton->setFixedSize(150, 30);
   kilitButton->setIconSize(QSize(150,30));
   kilitButton->setText("Seçili Pc'ye Duyuru");
   kilitButton->setFlat(true);
  // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

   connect(kilitButton, &QPushButton::clicked, [=]() {
       QString komut="ekranmesaj|"+lineEdit_message->text()+"|"+username->text()+"|"+password->text();
       lineEdit_message->setText(komut);
      // socketNumberLabel->setText("Broadcast");
      // socketNumberLabel->hide();
       //destlabel->setText("Hedef(Broadcast)");
       sendMessageInit();
});

   QPushButton *kilitAllButton= new QPushButton;
   kilitAllButton->setFixedSize(150, 30);
   kilitAllButton->setIconSize(QSize(150,30));
   kilitAllButton->setText("Tüm Pc'lere Duyuru");
   kilitAllButton->setFlat(true);
  // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

   connect(kilitAllButton, &QPushButton::clicked, [=]() {
       QString komut="ekranmesaj|"+lineEdit_message->text()+"|"+username->text()+"|"+password->text();
       lineEdit_message->setText(komut);
       socketNumberLabel->setText("Broadcast");
       socketNumberLabel->hide();
       destlabel->setText("Hedef(Broadcast)");
       sendMessageInit();
});

    auto widget = new QWidget;
    auto layout = new QGridLayout(widget);
    layout->setContentsMargins(0, 0, 0,0);
    layout->setVerticalSpacing(0);
  //  layout->setColumnMinimumWidth(0, 37);
    layout->addWidget(kilitButton, 2,0,1,2);
   layout->addWidget(kilitAllButton, 3,0,1,2);
    // layout->addWidget(new QLabel("<font size=1>Ayarları Kaydet</font>"),6,1,1,1,Qt::AlignHCenter);
      //layout->setColumnStretch(6, 255);

    // add a widget action to the context menu
    auto wa = new QWidgetAction(this);
  //  wa->setIcon(QIcon(":/icon1"));
    wa->setDefaultWidget(widget);
    menu->addAction(wa);

     menu->setStyleSheet("QMenu { width: 150 px; height: 60 px; }");
   return menu;
}

QMenu *MainWindow::ekranImageMenu()
{   QMenu *menu = new QMenu(this);

   QPushButton *kilitButton= new QPushButton;
   kilitButton->setFixedSize(150, 30);
   kilitButton->setIconSize(QSize(150,30));
   kilitButton->setText("Seçili Pc Ekranı");
   kilitButton->setFlat(true);
  // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

   connect(kilitButton, &QPushButton::clicked, [=]() {
       QString komut="ekranimage|"+lineEdit_message->text()+"|"+username->text()+"|"+password->text();
       lineEdit_message->setText(komut);
      // socketNumberLabel->setText("Broadcast");
     //  socketNumberLabel->hide();
      // destlabel->setText("Hedef(Broadcast)");
       sendMessageInit();
      // qDebug()<<destlabel->text();
});

   QPushButton *kilitAllButton= new QPushButton;
   kilitAllButton->setFixedSize(150, 30);
   kilitAllButton->setIconSize(QSize(150,30));
   kilitAllButton->setText("Tüm Pc Ekranları");
  kilitAllButton->setFlat(true);
  // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

   connect(kilitAllButton, &QPushButton::clicked, [=]() {
       QString komut="ekranimage|"+lineEdit_message->text()+"|"+username->text()+"|"+password->text();
       lineEdit_message->setText(komut);
       socketNumberLabel->setText("Broadcast");
     //  socketNumberLabel->hide();
      // destlabel->setText("Hedef(Broadcast)");
       sendMessageInit();
      // qDebug()<<destlabel->text();
});

    auto widget = new QWidget;
    auto layout = new QGridLayout(widget);
    layout->setContentsMargins(0, 0, 0,0);
    layout->setVerticalSpacing(0);
  //  layout->setColumnMinimumWidth(0, 37);
    layout->addWidget(kilitButton, 2,0,1,2);
   layout->addWidget(kilitAllButton, 3,0,1,2);
    // layout->addWidget(new QLabel("<font size=1>Ayarları Kaydet</font>"),6,1,1,1,Qt::AlignHCenter);
      //layout->setColumnStretch(6, 255);

    // add a widget action to the context menu
    auto wa = new QWidgetAction(this);
  //  wa->setIcon(QIcon(":/icon1"));
    wa->setDefaultWidget(widget);
    menu->addAction(wa);

     menu->setStyleSheet("QMenu { width: 150 px; height: 60 px; }");
   return menu;
}

QMenu *MainWindow::komutMenu()
{   QMenu *menu = new QMenu(this);

   QPushButton *kilitButton= new QPushButton;
   kilitButton->setFixedSize(150, 30);
   kilitButton->setIconSize(QSize(150,30));
   kilitButton->setText("Seçili Pc'de Çalıştır");
   kilitButton->setFlat(true);
  // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

   connect(kilitButton, &QPushButton::clicked, [=]() {
       QString komut="komut|"+lineEdit_message->text()+"|"+username->text()+"|"+password->text();
       lineEdit_message->setText(komut);
       //socketNumberLabel->setText("Broadcast");
       //socketNumberLabel->hide();
       //destlabel->setText("Hedef(Broadcast)");
       sendMessageInit();
       textBrowser_receivedMessages->clear();
});

   QPushButton *kilitAllButton= new QPushButton;
   kilitAllButton->setFixedSize(150, 30);
   kilitAllButton->setIconSize(QSize(150,30));
   kilitAllButton->setText("Tüm Pc'lerde Çalıştır");
   kilitAllButton->setFlat(true);
  // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

   connect(kilitAllButton, &QPushButton::clicked, [=]() {
       QString komut="komut|"+lineEdit_message->text()+"|"+username->text()+"|"+password->text();
       lineEdit_message->setText(komut);
       socketNumberLabel->setText("Broadcast");
       socketNumberLabel->hide();
       destlabel->setText("Hedef(Broadcast)");
       sendMessageInit();
});

    auto widget = new QWidget;
    auto layout = new QGridLayout(widget);
    layout->setContentsMargins(0, 0, 0,0);
    layout->setVerticalSpacing(0);
  //  layout->setColumnMinimumWidth(0, 37);
    layout->addWidget(kilitButton, 2,0,1,2);
   layout->addWidget(kilitAllButton, 3,0,1,2);
    // layout->addWidget(new QLabel("<font size=1>Ayarları Kaydet</font>"),6,1,1,1,Qt::AlignHCenter);
      //layout->setColumnStretch(6, 255);

    // add a widget action to the context menu
    auto wa = new QWidgetAction(this);
  //  wa->setIcon(QIcon(":/icon1"));
    wa->setDefaultWidget(widget);
    menu->addAction(wa);

     menu->setStyleSheet("QMenu { width: 150 px; height: 60 px; }");
   return menu;
}
*/
#endif // MENU_H
