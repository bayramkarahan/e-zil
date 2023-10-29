#include <QCloseEvent>
#include<QWidget>
#include<QPushButton>
#include<QLabel>
#include<QDebug>
#include <QApplication>
#include<QPoint>
#ifndef WIDGET_H
#define WIDGET_H
class Widget : public QWidget
{
    Q_OBJECT

public:
    QLabel *zamanGostergesi;
    QLabel *zamanGostergesiDurum;
    QLabel *zamanGostergesiRenk;
    QLabel *baslik;

Widget(int _w,int _h)
{
    w=_w;
    h=_h;
    this->setFixedSize(w*11,h/2*9);
   // this->setStyleSheet("background-color: #acacac;");

    Qt::WindowFlags flags = 0;
    flags |= Qt::Dialog;
    //flags |= Qt::WindowStaysOnTopHint;
    flags |= Qt::X11BypassWindowManagerHint;
    this->setWindowFlags(flags);
    QLabel *zemin=new QLabel(this);
    zemin->setFixedSize(this->width(),this->height());
    zemin->setStyleSheet("border: 0.5px solid rgba(62, 140, 220,20);"
                         "background-color: #dfdfdf;"
                          "border-radius: "+QString::number(h/2)+"px;");//

    zamanGostergesiDurum=new QLabel(this);
    zamanGostergesiDurum->hide();
    zamanGostergesi=new QLabel(this);
    //zamanGostergesi->setText("Durum");
    zamanGostergesi->setFixedSize(this->width()/4*3-h/4,this->height()-h-h);
    zamanGostergesi->setStyleSheet("font-size: "+QString::number(h*3)+"px;font-weight:700;font-family: Arial;color:#000055;");
    zamanGostergesi->move(h/4,h+h/4*3);

    zamanGostergesiRenk=new QLabel(this);
    zamanGostergesiRenk->setFixedSize(this->width()/4,this->height()-h-h);
    zamanGostergesiRenk->move(this->width()-zamanGostergesiRenk->width()-h/4,h+h/4*3);

    zamanGostergesiRenk->setStyleSheet("font-size: "+QString::number(h*3)+"px; background-color: #00ff00;border: 1px solid gray;border-radius: "+QString::number(h)+"px;");
    zamanGostergesiRenk->setAlignment(Qt::AlignTop|Qt::AlignCenter);


baslik=new QLabel(this);
//baslik->setText(" Sessiz Zil Sistemi");
baslik->setObjectName("baslik");
baslik->setFixedSize(this->width(),h*1.5);
int fnt=h*0.9;
baslik->setStyleSheet("font-size:"+QString::number(fnt)+"px; border: 0.5px solid rgba(62, 140, 220,20);"
                      "border-radius: "+QString::number(h/2)+"px;"
                      "background: qradialgradient(cx:0.5, cy:0.5, radius: 2.5,"
                      "fx:0.5, fy:0.5, stop:0 white, stop:1 gray);");

kapatButton= new QPushButton(this);
//kapatButton->setText("X");
kapatButton->setFixedSize(w,h-h/5);
kapatButton->move(this->width()-kapatButton->width()*1.5,2);
kapatButton->setFlat(true);
kapatButton->setAutoFillBackground(true);
kapatButton->setIcon(QIcon(":/icons/goster.png"));

//kapatButton->setAutoRaise(true);
//kapatButton->raise();
//kapatButton->hide();

connect(kapatButton, &QPushButton::clicked, [=]() {
    if(!visibleStatus)
    {
        visibleStatus=true;
        kapatButton->setIcon(QIcon(":/icons/gizle.png"));
        //qDebug()<<"gizle"<<visibleStatus;
         this->setFixedSize(w*11,h*1.5);

    }else
    {
        visibleStatus=false;
        kapatButton->setIcon(QIcon(":/icons/goster.png"));
        //qDebug()<<"goster"<<visibleStatus;
         this->setFixedSize(w*11,h/2*9);
    }

   // close();
   });

}

protected:
void mousePressEvent(QMouseEvent *event)Q_DECL_OVERRIDE
{
    if (QLabel *w =(QLabel*) qApp->widgetAt(QCursor::pos())) {
         if(w->objectName()=="baslik")
        {
    mouseClickState=true;
        oldPos = event->globalPos();
         }
    }
    //qDebug()<<"press"<<mouseClickState;
}
void mouseMoveEvent(QMouseEvent *event)Q_DECL_OVERRIDE
{
    // qDebug()<<"move"<<mouseClickState;
     if(mouseClickState)
    {
              /// qDebug()<<"başlıktan tutup sürükleniyor";
                 const QPoint delta = event->globalPos() - oldPos;
                             move(x()+delta.x(), y()+delta.y());
                             oldPos = event->globalPos();
           }
}
void mouseReleaseEvent(QMouseEvent *event)Q_DECL_OVERRIDE
{

    mouseClickState=false;
  //  qDebug()<<"release"<<mouseClickState;
}
    void closeEvent(QCloseEvent *bar)
   {
      //  qDebug()<<"release";
       // Do something
      // bar->accept();
        // bar->ignore();
         hide();
   }
private:
  QPushButton *kapatButton;
  bool mouseClickState;
   QPoint oldPos;
   int w,h;
   bool visibleStatus;
};
#endif // WIDGET_H
