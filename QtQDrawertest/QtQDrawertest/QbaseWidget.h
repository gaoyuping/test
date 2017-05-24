#pragma once

#include <QWidget>

class QbaseWidget : public QWidget
{
    Q_OBJECT

public:
    QbaseWidget(QWidget *parent = NULL);
    ~QbaseWidget();
    void paintEvent(QPaintEvent *);
};
