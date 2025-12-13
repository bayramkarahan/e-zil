#ifndef VALUESLIDERWIDGET_H
#define VALUESLIDERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include "customslider.h"

class ValueSliderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ValueSliderWidget(QWidget *parent = nullptr);

    // Dışarıdan erişim
    void setRange(int start, int end);
    void setValue(int value);
    int value() const;

private slots:
    void updateInfo(int min, int val, int max);

private:
    CustomSlider *slider;
    QLabel *lblMin;
    QLabel *lblVal;
    QLabel *lblMax;
};

#endif // VALUESLIDERWIDGET_H
