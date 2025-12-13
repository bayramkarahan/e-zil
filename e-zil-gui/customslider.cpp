#include "customslider.h"

CustomSlider::CustomSlider(Qt::Orientation orientation, QWidget *parent)
    : QSlider(orientation, parent),
    m_start(0),
    m_end(100)
{
    setRange(m_start, m_end);

    connect(this, &QSlider::valueChanged,
            this, &CustomSlider::onValueChanged);
}

void CustomSlider::setRangeValues(int start, int end)
{
    m_start = start;
    m_end = end;
    setRange(m_start, m_end);

    emit rangeChanged(m_start, m_end);
    emit currentInfoChanged(m_start, value(), m_end);
}

void CustomSlider::setStartValue(int start)
{
    m_start = start;
    setRange(m_start, m_end);

    emit rangeChanged(m_start, m_end);
    emit currentInfoChanged(m_start, value(), m_end);
}

void CustomSlider::setEndValue(int end)
{
    m_end = end;
    setRange(m_start, m_end);

    emit rangeChanged(m_start, m_end);
    emit currentInfoChanged(m_start, value(), m_end);
}

int CustomSlider::currentValue() const
{
    return value();
}

void CustomSlider::setCurrentValue(int v)
{
    setValue(v);
    emit currentInfoChanged(m_start, value(), m_end);
}

void CustomSlider::onValueChanged(int value)
{
    emit currentInfoChanged(m_start, value, m_end);
}
