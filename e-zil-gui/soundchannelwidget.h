#ifndef SOUNDCHANNELWIDGET_H
#define SOUNDCHANNELWIDGET_H

#include <QWidget>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QButtonGroup>
#include<soundchannel.h>
class SoundChannelWidget : public QWidget
{
    Q_OBJECT

public:


    explicit SoundChannelWidget(QWidget *parent = nullptr);

    void setValue(ChannelMode mode);
    ChannelMode value() const;

signals:
    void valueChanged(ChannelMode mode);

private:
    QRadioButton *rbLeft;
    QRadioButton *rbCenter;
    QRadioButton *rbRight;

    QButtonGroup *group;

    void applyModernStyle();
};

#endif // SOUNDCHANNELWIDGET_H