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
#ifndef FILECRUD_H
#define FILECRUD_H
#include<QFile>
#include<QDir>

class FileCrud
{
  public:
     QString dosya;//FileCrud *fc=new FileCrud();

    void fileRemove()
{
        QFile file(QDir::homePath()+"/"+dosya);
//const QString yol=QDir::homePath()+"/"+dosya;
    //bool snc=QDir::remove(yol);
        file.remove();
       }
    bool fileExists()
    {
        QFile file(QDir::homePath()+"/"+dosya);

//        QFile file(dosya);
        if(file.exists()) return true; else return false;

    }
    void fileWrite(QString veri)
    {
        QFile data(QDir::homePath()+"/"+dosya);
        QFile newData(QDir::homePath()+"/"+dosya);
        data.open(QIODevice::Text | QIODevice::ReadWrite);
        QString dataText = data.readAll();
        dataText.append(veri+"\n");
       if(newData.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&newData);
        out << dataText;
            }
            newData.close();
            data.close();
    }
    void fileRead()
    {
        QFile file(QDir::homePath()+"/"+dosya);
        /*
         * If file not exit it will create
         * */
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text | QIODevice::ReadWrite))
        {
            qDebug() << "FAIL TO CREATE FILE / FILE NOT EXIT***";
        }

        /*for Reading line by line from text file*/
        while (!file.atEnd()) {
            QByteArray line = file.readLine();
            qDebug() << "read output - " << line;
        }

    }
    int fileCount()
    {
        QFile file(QDir::homePath()+"/"+dosya);
        /*
         * If file not exit it will create
         * */
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text | QIODevice::ReadWrite))
        {
            qDebug() << "FAIL TO CREATE FILE / FILE NOT EXIT***";
        }

        /*for Reading line by line from text file*/
        int sayi=0;
        while (!file.atEnd()) {
            QByteArray line = file.readLine();
           // qDebug() << "read output - " << line;
            sayi++;
        }
        file.close();
return sayi;
    }

    void fileDelete(QString data)
    {
      QRegularExpression re(data);
      QFile f(QDir::homePath()+"/"+dosya);
      if(f.open(QIODevice::ReadWrite | QIODevice::Text))
      {
          QString s;
          QTextStream t(&f);
          while(!t.atEnd())
          {
              QString line = t.readLine();
              if(!line.contains(re))
                  s.append(line + "\n");
          }
          f.resize(0);
          t << s;
          f.close();
      }
        /*QString rdata;
        QFile file(QDir::homePath()+"/"+dosya);
        /*
         * If file not exit it will create
         * */
       /* if (!file.open(QIODevice::ReadOnly | QIODevice::Text | QIODevice::ReadWrite))
        {
            qDebug() << "FAIL TO CREATE FILE / FILE NOT EXIT***";
        }
        QRegularExpression re(data);
        /*for Reading line by line from text file*/
       /* QFile dataa(QDir::homePath()+"/"+dosya+"_");
        QFile newData(QDir::homePath()+"/"+dosya+"_");
       // newData.remove();

        while (!file.atEnd()) {
            QString line = file.readLine();
           // qDebug() << "read output - " << line;
            if(line.contains(re))
            {
            }else
            {


                dataa.open(QIODevice::Text | QIODevice::ReadOnly);
                QString dataText = dataa.readAll();
                dataText.append(line);


                if(newData.open(QFile::WriteOnly | QFile::Truncate)) {
                QTextStream out(&newData);
                out << line;
                    }

            }
            newData.close();
            dataa.close();


        }
*/
    //fileRemove();
   // QFile file_(QDir::homePath()+"/"+dosya+"_");
  //  newData.copy("/home/etapadmin/iplistname_");

//qDebug()<<"denememe";
    }
    QString fileSearch(QString data)
    {
        QString rdata;
        QFile file(QDir::homePath()+"/"+dosya);
        /*
         * If file not exit it will create
         * */
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text | QIODevice::ReadWrite))
        {
            qDebug() << "FAIL TO CREATE FILE / FILE NOT EXIT***";
        }
        QRegularExpression re(data);
        /*for Reading line by line from text file*/
        while (!file.atEnd()) {
            QString line = file.readLine();
           // qDebug() << "read output - " << line;
            if(line.contains(re)) rdata=line; //qDebug()<<"bulundu......";
        }
return rdata;
    }

    QString fileGetLine(int recordLineNumber)
    {
        QString rdata;
        QFile file(QDir::homePath()+"/"+dosya);
        /*
         * If file not exit it will create
         * */
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text | QIODevice::ReadWrite))
        {
            qDebug() << "FAIL TO CREATE FILE / FILE NOT EXIT***";
        }
       // QRegularExpression re(data);
        /*for Reading line by line from text file*/
        int sira=0;
        while (!file.atEnd()) {
            QString line = file.readLine();
           // qDebug() << "read output - " << line;
            if(sira==recordLineNumber-1) rdata=line; //qDebug()<<"bulundu......";
        sira++;
        }
        file.close();
return rdata;
    }
    void fileDeletet(QString delveri)
    {
        //   qDebug()<<"selamf";
         QFile data(QDir::homePath()+"/"+dosya);
           QFile newData(QDir::homePath()+"/"+dosya);
           data.open(QIODevice::Text | QIODevice::ReadOnly);
           QString dataText = data.readAll();
           QRegularExpression re(delveri);
          QString replacementText("");
           dataText.replace(re, replacementText);
            //dataText.remove(delveri);
           if(newData.open(QFile::WriteOnly | QFile::Truncate)) {
           QTextStream out(&newData);
           out << dataText;
               }
               newData.close();

    }
    void fileEdit(QString oldveri,QString newveri)
    {

           QFile data(QDir::homePath()+"/"+dosya);
           QFile newData(QDir::homePath()+"/"+dosya);
           data.open(QIODevice::Text | QIODevice::ReadOnly);
           QString dataText = data.readAll();
           QRegularExpression re(oldveri);
           QString replacementText(newveri);
           dataText.replace(re, replacementText);

           if(newData.open(QFile::WriteOnly | QFile::Truncate)) {
           QTextStream out(&newData);
           out << dataText;
               }
               newData.close();
    }
};





#endif // FILECRUD_H
