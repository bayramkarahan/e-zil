// MiniAudioPlayer.cpp
// Implementation: define MINIAUDIO_IMPLEMENTATION only here.

#define MINIAUDIO_IMPLEMENTATION
#define MA_ENABLE_MP3
#define MA_ENABLE_MINIMP3
#include "miniaudio.h"

#include "miniaudioplayer.h"

MiniAudioPlayer::MiniAudioPlayer(QObject *parent)
    : QObject(parent)
{
    if (ma_engine_init(NULL, &engine) != MA_SUCCESS) {
        qWarning() << "MiniAudioPlayer: ma_engine_init failed";
        engineInitialized = false;
    } else {
        engineInitialized = true;
    }

    watchTimer = new QTimer(this);
    connect(watchTimer, &QTimer::timeout, this, &MiniAudioPlayer::checkPlayback);
    watchTimer->start(200);

    fadeTimer = new QTimer(this);
    connect(fadeTimer, &QTimer::timeout, this, &MiniAudioPlayer::onFadeTimerTimeout);
    fadeTimer->setInterval(30); // will be adjusted dynamically
}

MiniAudioPlayer::~MiniAudioPlayer()
{
    if (fadeTimer && fadeTimer->isActive()) fadeTimer->stop();

    if (soundInitialized) {
        ma_sound_stop(&currentSound);
        ma_sound_uninit(&currentSound);
        soundInitialized = false;
    }
    if (engineInitialized) {
        ma_engine_uninit(&engine);
        engineInitialized = false;
    }
}

void MiniAudioPlayer::setPlaylist(const QStringList &list)
{
    playlist = list;
    currentIndex = (playlist.isEmpty() ? -1 : 0);
}

QString MiniAudioPlayer::currentFile() const
{
    if (currentIndex >= 0 && currentIndex < playlist.size())
        return playlist.at(currentIndex);
    return QString();
}

void MiniAudioPlayer::play()
{
    if (playlist.isEmpty()) return;
    if (currentIndex < 0) currentIndex = 0;
    playFile(playlist.at(currentIndex));
}

void MiniAudioPlayer::playIndex(int index)
{
    if (index < 0 || index >= playlist.size()) return;
    currentIndex = index;
    play();
}

void MiniAudioPlayer::playFile(const QString &path)
{
    if (!engineInitialized) {
        qWarning() << "Engine not initialized";
        return;
    }

    // stop/uninit previous sound (mirrors senin çalışan yöntemin mantığı)
    if (soundInitialized) {
        ma_sound_stop(&currentSound);
        ma_sound_uninit(&currentSound);
        soundInitialized = false;
    }

    if (ma_sound_init_from_file(&engine,
                                path.toUtf8().constData(),
                                MA_SOUND_FLAG_DECODE, // decode into memory for reliable control
                                NULL,
                                NULL,
                                &currentSound) != MA_SUCCESS) {
        qWarning() << "MiniAudioPlayer: ma_sound_init_from_file failed for" << path;
        return;
    }

    soundInitialized = true;
    // start at 0 volume for fade-in
    ma_sound_set_volume(&currentSound, 0.0f);
    ma_sound_start(&currentSound);

    // set target volume
    ma_sound_set_volume(&currentSound, 0.0f);
    targetVolume = qBound(0.0f, targetVolume, 1.0f);

    emit currentSongChanged(path);

    startFadeIn();
}

void MiniAudioPlayer::stop()
{
    if (!soundInitialized) return;
    // Fade out then stop
    startFadeOut([this](){
        if (soundInitialized) {
            ma_sound_stop(&currentSound);
            ma_sound_uninit(&currentSound);
            soundInitialized = false;
        }
    });
}

void MiniAudioPlayer::next()
{
    if (playlist.isEmpty()) return;

    if (shuffleEnabled) {
        int nextIndex;
        if (playlist.size() <= 1) nextIndex = currentIndex;
        else {
            do {
                nextIndex = QRandomGenerator::global()->bounded(playlist.size());
            } while (nextIndex == currentIndex);
        }
        currentIndex = nextIndex;
    } else {
        currentIndex++;
        if (currentIndex >= playlist.size()) currentIndex = 0;
    }

    play();
}

void MiniAudioPlayer::previous()
{
    if (playlist.isEmpty()) return;
    currentIndex--;
    if (currentIndex < 0) currentIndex = playlist.size() - 1;
    play();
}

void MiniAudioPlayer::setVolume(float v)
{
    v = qBound(0.0f, v, 1.0f);
    targetVolume = v;
    if (soundInitialized && !fadeInProgress) {
        ma_sound_set_volume(&currentSound, targetVolume);
    }
}

void MiniAudioPlayer::setShuffle(bool enabled)
{
    shuffleEnabled = enabled;
}

void MiniAudioPlayer::setFadeDuration(int ms)
{
    fadeDurationMs = qMax(0, ms);
}

float MiniAudioPlayer::duration() const
{
    if (!soundInitialized) return 0.0f;
    float seconds = 0.0f;
    ma_sound_get_length_in_seconds((ma_sound*)&currentSound, &seconds);
    return seconds;
}

void MiniAudioPlayer::checkPlayback()
{
    if (!engineInitialized) return;

    if (soundInitialized) {
        if (!ma_sound_is_playing(&currentSound) && !fadeInProgress) {
            // current finished normally
            // uninit previous
            ma_sound_uninit(&currentSound);
            soundInitialized = false;

            // move to next if available, otherwise emit finishedAll
            if (!playlist.isEmpty()) {
                int nextIndex = currentIndex + 1;
                if (nextIndex >= playlist.size()) {
                    // reached end
                    currentIndex = -1;
                    emit finishedAll();
                } else {
                    currentIndex = nextIndex;
                    play();
                }
            }
        }
    }
}

// Fade helpers using QTimer on GUI thread (safe)
void MiniAudioPlayer::startFadeIn()
{
    if (!soundInitialized) return;

    fadeTimer->stop();
    fadeOnEnd = nullptr;
    fadeInProgress = true;

    int steps = qMax(1, fadeDurationMs / 30);
    fadeStep = (steps > 0) ? (targetVolume / (float)steps) : targetVolume;
    fadeCurrent = 0.0f;

    fadeTimer->setInterval(qMax(10, fadeDurationMs / steps));
    fadeTimer->start();
}

void MiniAudioPlayer::startFadeOut(std::function<void()> onEnd)
{
    if (!soundInitialized) {
        if (onEnd) onEnd();
        return;
    }

    fadeTimer->stop();
    fadeOnEnd = onEnd;
    fadeInProgress = true;

    int steps = qMax(1, fadeDurationMs / 30);
    fadeStep = (steps > 0) ? (targetVolume / (float)steps) : targetVolume;
    fadeCurrent = targetVolume;

    fadeTimer->setInterval(qMax(10, fadeDurationMs / steps));
    fadeTimer->start();
}

void MiniAudioPlayer::onFadeTimerTimeout()
{
    if (!soundInitialized) {
        fadeTimer->stop();
        fadeInProgress = false;
        if (fadeOnEnd) { fadeOnEnd(); fadeOnEnd = nullptr; }
        return;
    }

    if (fadeCurrent < targetVolume && fadeOnEnd == nullptr) {
        // fade-in progression
        fadeCurrent += fadeStep;
        if (fadeCurrent >= targetVolume) {
            fadeCurrent = targetVolume;
            ma_sound_set_volume(&currentSound, fadeCurrent);
            fadeTimer->stop();
            fadeInProgress = false;
            return;
        }
        ma_sound_set_volume(&currentSound, fadeCurrent);
        return;
    }

    if (fadeOnEnd) {
        // fade-out progression
        fadeCurrent -= fadeStep;
        if (fadeCurrent <= 0.0f) {
            ma_sound_set_volume(&currentSound, 0.0f);
            fadeTimer->stop();
            fadeInProgress = false;

            // call onEnd (stop/uninit)
            std::function<void()> fn = fadeOnEnd;
            fadeOnEnd = nullptr;
            fn();
            return;
        }
        ma_sound_set_volume(&currentSound, fadeCurrent);
        return;
    }

    // otherwise nothing
}
