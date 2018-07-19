#ifndef DOWNLOADFILE_H
#define DOWNLOADFILE_H

#include <QtWidgets/QMainWindow>
#include "ui_downloadfile.h"
#include "Downfile.h"
#include "QALLWidget.h"
class DownLoadFile : public QMainWindow
{
    Q_OBJECT

public:
    DownLoadFile(QWidget *parent = 0);
    ~DownLoadFile();

protected:
    virtual void mousePressEvent(QMouseEvent *event);
private:
    Ui::DownLoadFileClass ui;
    QALLWidget *tmp;
};

#endif // DOWNLOADFILE_H
