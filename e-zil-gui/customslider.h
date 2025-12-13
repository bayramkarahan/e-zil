#ifndef CUSTOMSLIDER_H
#define CUSTOMSLIDER_H

#include <QSlider>

class CustomSlider : public QSlider
{
    Q_OBJECT

public:
    explicit CustomSlider(Qt::Orientation orientation = Qt::Horizontal,
                          QWidget *parent = nullptr);

    // Range ayarlama
    void setRangeValues(int start, int end);

    // Tek tek minimum – maksimum
    void setStartValue(int start);
    void setEndValue(int end);

    // Anlık değer alma / ayarlama
    int currentValue() const;
    void setCurrentValue(int value);

signals:
    void rangeChanged(int start, int end);          // Minimum – Maksimum değiştiğinde
    void currentInfoChanged(int min, int val, int max); // Her değer değişiminde

private slots:
    void onValueChanged(int value);

private:
    int m_start;
    int m_end;
};

#endif // CUSTOMSLIDER_H
