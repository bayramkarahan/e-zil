#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once
#include <QMainWindow>
#include<QLineEdit>
#include<QMediaPlayer>
#include<QSystemTrayIcon>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
virtual void closeEvent ( QCloseEvent * event );

public slots:
   // QWidget ayar();
    void  WidgetClosed();
    void listToFile(QStringList list, QString filename);
    QStringList fileToList(QString filename);
    QString listGetLine(QStringList list,QString data);
    QStringList listRemove(QStringList list,QString data);
    void zilKontrol();
    void zilBaslatma();
    void init();
    void iconActivated(QSystemTrayIcon::ActivationReason);
    void gizle();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWidget *ayar();
    QWidget *saatpzrts();
    QWidget *saatsl();
    QWidget *saatcrsmb();
    QWidget *saatprsmb();
    QWidget *saatcm();
    QWidget *saatcmrts();
    QWidget *saatpzr();

    QMediaPlayer* player;
    QTimer *timerZil;
    QTimer *timerZilBaslama;
    QStringList ayarlst;
    QMediaPlaylist *playlist;
    QTimer *timergizle;
    QSystemTrayIcon* trayIcon;
    QMenu* trayIconMenu;

    QMenu* createMenu();

};

#endif // MAINWINDOW_H
