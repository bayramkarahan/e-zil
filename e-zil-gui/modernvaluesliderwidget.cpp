#include "modernvaluesliderwidget.h"

ModernValueSliderWidget::ModernValueSliderWidget(QWidget *parent)
    : QWidget(parent)
{
    slider = new CustomSlider(Qt::Horizontal, this);

    lblMin = new QLabel("0", this);
    lblVal = new QLabel("0", this);

    lblMin->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    lblVal->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    // ❗ Daha küçük ve kompakt
    /*lblMin->setFixedWidth(30);
    lblMax->setFixedWidth(30);
    lblVal->setFixedWidth(90);
*/

    // Alt tarafta min – slider – max
    auto *bottom = new QHBoxLayout();
    bottom->setSpacing(1);                  // ❗ Etiket–slider arası daraltıldı
    bottom->addWidget(lblMin);
    bottom->addWidget(slider);
    bottom->addWidget(lblVal);

    auto *main = new QVBoxLayout(this);
    main->setSpacing(0);                    // ❗ Üst–alt arası daha dar
    main->setContentsMargins(0, 0, 0, 0);   // ❗ Daha kompakt görünüm
    main->addLayout(bottom);
    setLayout(main);

    applyModernStyle();

    connect(slider, &CustomSlider::currentInfoChanged,
            this, &ModernValueSliderWidget::updateInfo);

    connect(slider, &QSlider::valueChanged, this, [=](int v){
        lblVal->setText(QString::number(v));
    });
    setObjectName("modernSlider");
   setAttribute(Qt::WA_StyledBackground, true);
    setStyleSheet(
        "#modernSlider {"
        "    border: 1px solid #acacac;"
        "    border-radius: 2px;"
        "    background-color: rgba(0,0,0,0);"   // transparent ama boyanan tür
        "}"
        );


}
/* -------------------------------
   BURASI EKSİKTİ — IMPLEMENTATION
--------------------------------*/
static QString clamp3(int v)
{
    if (v > 999) return "999+";
    if (v < -99) return "-99";
    return QString::number(v);
}

void ModernValueSliderWidget::setRange(int start, int end)
{
    slider->setRange(start, end);
    lblMin->setText(clamp3(start));
}

void ModernValueSliderWidget::setValue(int value)
{
    slider->setValue(value);
    lblVal->setText(QString::number(value));
}

int ModernValueSliderWidget::value() const
{
    return slider->value();
}

void ModernValueSliderWidget::applyModernStyle()
{
    slider->setStyleSheet(
        "QSlider::groove:horizontal {"
        "    height: 6px;"
        "    background: #cccccc;"
        "    border-radius: 3px;"
        "}"
        "QSlider::handle:horizontal {"
        "    width: 16px;"
        "    height: 16px;"
        "    margin: -5px 0;"
        "    background: #448aff;"   // mavi modern
        "    border-radius: 8px;"
        "}"
        "QSlider::sub-page:horizontal {"
        "    background: #448aff;"
        "    border-radius: 3px;"
        "}"
        "QSlider::add-page:horizontal {"
        "    background: #bbbbbb;"
        "    border-radius: 3px;"
        "}"
        );
}


void ModernValueSliderWidget::updateInfo(int min, int val, int max)
{
    lblMin->setText(clamp3(min));
    lblVal->setText(QString::number(val));

}
void ModernValueSliderWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    int w = width();
    int h = height();

    // Etiket yüksekliği (küçük – büyük)
    int labelH = qMax(14, int(h * 0.25));
    int valueLabelH = qMax(16, int(h * 0.35));

    // Min/Max font
    QFont fMin = lblMin->font();
    fMin.setPointSizeF(labelH * 0.5);
    lblMin->setFont(fMin);

    // Value font
    QFont fVal = lblVal->font();
    fVal.setPointSizeF(valueLabelH * 0.4);
    lblVal->setFont(fVal);

    // Etiket genişlikleri
    lblMin->setFixedWidth(w * 0.10);
    lblVal->setFixedWidth(w*0.10);
    lblVal->setFixedHeight(h * 0.80);
    lblMin->setFixedHeight(h * 0.80);


    // Slider yüksekliği
    slider->setFixedHeight(h*0.8);
    slider->setFixedWidth(w * 0.7);
}

