#include "QbaseWidget.h"

#include <QStyleOption>
#include <QPainter>
QbaseWidget::QbaseWidget(QWidget *parent)
    : QWidget(parent)
{
}

QbaseWidget::~QbaseWidget()
{
}

void QbaseWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

