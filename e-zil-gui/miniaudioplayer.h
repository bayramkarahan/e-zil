#ifndef MINIAUDIOPLAYER_H
#define MINIAUDIOPLAYER_H

#include <QObject>
#include <QStringList>
#include <QTimer>
#include <QRandomGenerator>
#include <QDebug>
#include <functional>

// Include header only (do NOT define MINIAUDIO_IMPLEMENTATION here)
#include "miniaudio.h"
/*****************************************/
/* QStringList list;
            list <<torenZilLineEdit->text();
            //list << "C:/e-zil-ses/e-zil-ses/Ses/muzik2.mp3";
            miniPlayer->setPlaylist(list);
            //miniPlayer->setShuffle(true);       // veya false
            miniPlayer->setFadeDuration(800);   // ms
            miniPlayer->setVolume(volume);
            miniPlayer->play();

            // durdurmak
          ///  miniPlayer->stop();

            // ileri / geri
          ///  miniPlayer->next();
          ///  miniPlayer->previous();
     /********************************************/
class MiniAudioPlayer : public QObject
{
    Q_OBJECT
public:
    explicit MiniAudioPlayer(QObject *parent = nullptr);
    ~MiniAudioPlayer();

    void setPlaylist(const QStringList &list);
    void play();               // play current index (or first)
    void playIndex(int index); // play specific index
    void stop();               // stop and uninit current sound
    void next();
    void previous();

    void setVolume(float v);          // 0.0 - 1.0
    void setShuffle(bool enabled);
    void setFadeDuration(int ms);     // fade-in/out duration in ms

    QString currentFile() const;
    float duration() const;           // seconds, 0 if unknown

signals:
    void currentSongChanged(const QString &filename);
    void finishedAll();               // playlist finished (no repeat)

private slots:
    void checkPlayback();
    void onFadeTimerTimeout();

private:
    void playFile(const QString &path);
    void startFadeIn();
    void startFadeOut(std::function<void()> onEnd);

private:
    QStringList playlist;
    int currentIndex = -1;

    ma_engine engine;
    ma_sound currentSound;

    bool engineInitialized = false;
    bool soundInitialized = false;

    float targetVolume = 1.0f; // desired master volume for each sound
    int fadeDurationMs = 600;  // default fade duration

    QTimer *watchTimer = nullptr;
    QTimer *fadeTimer = nullptr;

    float fadeStep = 0.02f;
    float fadeCurrent = 0.0f;
    bool fadeInProgress = false;
    std::function<void()> fadeOnEnd;

    bool shuffleEnabled = false;
};

#endif // MINIAUDIOPLAYER_H
