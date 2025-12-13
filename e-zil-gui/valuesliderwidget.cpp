#include "valuesliderwidget.h"

ValueSliderWidget::ValueSliderWidget(QWidget *parent)
    : QWidget(parent)
{
    slider = new CustomSlider(Qt::Horizontal, this);
    lblMin = new QLabel("0", this);
    lblVal = new QLabel("0", this);
    lblMax = new QLabel("100", this);

    lblMin->setMinimumWidth(30);
    lblVal->setMinimumWidth(40);
    lblMax->setMinimumWidth(30);

    auto *layout = new QHBoxLayout(this);
    layout->addWidget(lblMin);
    layout->addWidget(slider);
    layout->addWidget(lblVal);
    layout->addWidget(lblMax);
    setLayout(layout);

    connect(slider, &CustomSlider::currentInfoChanged,
            this, &ValueSliderWidget::updateInfo);
}

void ValueSliderWidget::setRange(int start, int end)
{
    slider->setRangeValues(start, end);
}

void ValueSliderWidget::setValue(int value)
{
    slider->setCurrentValue(value);
}

int ValueSliderWidget::value() const
{
    return slider->currentValue();
}

void ValueSliderWidget::updateInfo(int min, int val, int max)
{
    lblMin->setText(QString::number(min));
    lblVal->setText(QString::number(val));
    lblMax->setText(QString::number(max));
}
