#ifndef MODERNVALUESLIDERWIDGET_H
#define MODERNVALUESLIDERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QToolTip>
#include "customslider.h"
#include<QStyleOption>
#include<QPainter>

class ModernValueSliderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModernValueSliderWidget(QWidget *parent = nullptr);

    void setRange(int start, int end);
    void setValue(int value);
    int value() const;

private slots:
    void updateInfo(int min, int val, int max);

protected:
    void resizeEvent(QResizeEvent *event) override;


private:
    CustomSlider *slider;
    QLabel *lblMin;
    QLabel *lblVal;
    void applyModernStyle();
};

#endif // MODERNVALUESLIDERWIDGET_H
