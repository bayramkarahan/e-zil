#include "soundchannelwidget.h"

SoundChannelWidget::SoundChannelWidget(QWidget *parent)
    : QWidget(parent)
{
    rbLeft   = new QRadioButton("Sol", this);
    rbCenter = new QRadioButton("Orta", this);
    rbRight  = new QRadioButton("Sağ", this);

    group = new QButtonGroup(this);
    group->addButton(rbLeft, Left);
    group->addButton(rbCenter, Center);
    group->addButton(rbRight, Right);

    // Default CENTER
    rbCenter->setChecked(true);

    auto *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0,0,10,0);
    layout->setSpacing(3);

    layout->addWidget(rbLeft);
    layout->addWidget(rbCenter);
    layout->addWidget(rbRight);

    setLayout(layout);

    applyModernStyle();

    connect(group, QOverload<int>::of(&QButtonGroup::buttonClicked),
            this, [=](int id){
                emit valueChanged(static_cast<ChannelMode>(id));
            });
}

void SoundChannelWidget::setValue(ChannelMode mode)
{
    if (group->button(mode))
        group->button(mode)->setChecked(true);
}

ChannelMode SoundChannelWidget::value() const
{
    return static_cast<ChannelMode>(group->checkedId());
}
void SoundChannelWidget::applyModernStyle()
{
    setStyleSheet(
        "QRadioButton {"
        "    spacing: 6px;"
        "    font-size: 12px;"
        "}"
        "QRadioButton::indicator {"
        "    width: 14px;"
        "    height: 14px;"
        "    border-radius: 7px;"
        "    border: 2px solid #888;"
        "    background: transparent;"
        "}"
        "QRadioButton::indicator:checked {"
        "    background: #448aff;"
        "    border: 2px solid #448aff;"
        "}"
        "QRadioButton::indicator:hover {"
        "    border: 2px solid #448aff;"
        "}"
        );
}