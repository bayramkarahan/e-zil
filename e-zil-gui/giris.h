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
#include<QCheckBox>
#include<QProcess>
#include<QSvgWidget>
#include<QSvgRenderer>
QWidget *MainWindow::giris()
{
    QWidget *girisPage=new QWidget();
    girisPage->setFixedWidth(en*27);
   girisPage->setFixedHeight(en*25);
   auto  screenbtn = new QLabel(girisPage);
    screenbtn->setFixedSize(QSize(en*12,en*12));
    //screenbtn->setIconSize(QSize(250,250));
    screenbtn->setAutoFillBackground(true);
   // screenbtn->setIcon(QIcon(":/icons/e-zil.svg"));
    QSvgRenderer svgRenderer(QString(":/icons/e-zil.svg"));

    QPixmap pixmap(en*12, en*12);   // istediğin boyut
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    svgRenderer.render(&painter);

    screenbtn->setPixmap(pixmap);

    auto *sat0=new QLabel(girisPage);
    sat0->setText("Kullanım Hakkında Bilinmesi Gerekenler:");
    QFont f1( "Arial", 10, QFont::Normal);
    sat0->setFont(f1);

      auto *sat1=new QLabel(girisPage);
    sat1->setText(" 1- Her gün için ayrı ayrı saatler girip kaydedebilirsiniz.");
    auto *sat2=new QLabel(girisPage);
    sat2->setText(" 2- Pazartesi günü ayarlarını tüm haftaya uyarlayabilirsiniz.");
    auto *sat3=new QLabel(girisPage);
    sat3->setText(" 3- Öğrenci ya da öğretmen zili kullanılmayacaksa ayarlar bölümünden boş bırakılacaktır.");
    auto *sat4=new QLabel(girisPage);
    sat4->setText(" 4- Ayarlar bölümünden seçilen tören, öğrenci, öğretmen, çıkış zili tüm günlerde geçerlidir.");
    auto *sat5=new QLabel(girisPage);
    sat5->setText(" 5- Tören, öğrenci, öğretmen, çıkış zili dışındaki(İstiklal Marşı, Siren vb.) elle çalınabilir.");
    auto *sat6=new QLabel(girisPage);
    sat6->setText(" 6- Öğrenci Zili ile Öğretmen Zili arasındaki fark Tenefüs süresinden kısa olmalıdır!");

    QFont ff( "Arial", 8, QFont::Normal);
    sat1->setFont(ff);
    sat2->setFont(ff);
    sat3->setFont(ff);
    sat4->setFont(ff);
    sat5->setFont(ff);
    sat6->setFont(ff);

    auto layout = new QGridLayout(girisPage);
    layout->setContentsMargins(0, 0, 0,0);
   // layout->setVerticalSpacing(5);
    //layout->setColumnMinimumWidth(0, 37);
    layout->addWidget(new QLabel("<font size=6></font>"),0,0,1,2,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=6>e-zil</font>"),1,0,1,2,Qt::AlignHCenter);

    layout->addWidget(screenbtn, 2,0,1,2,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=6></font>"),3,0,1,2,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=6></font>"),4,0,1,2,Qt::AlignHCenter);

    layout->addWidget(sat0,7,0,1,2);
    layout->addWidget(sat1,10,0,1,2);
    layout->addWidget(sat2,15,0,1,2);
    layout->addWidget(sat3,20,0,1,2);
    layout->addWidget(sat4,25,0,1,2);
    layout->addWidget(sat5,30,0,1,2);
    layout->addWidget(sat6,35,0,1,2);

    // girisPage->setStyleSheet("background-color: #acacac");

   // layout->setColumnStretch(6, 255);


    return girisPage;
}
#ifndef GIRIS_H
#define GIRIS_H

#endif // GIRIS_H
