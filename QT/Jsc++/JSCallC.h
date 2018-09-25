#pragma once

#include <QObject>
#include <QWebChannel>
#include "ui_JSCallC.h"

class QWebEnginePage;

class connet : public QObject
{
    Q_OBJECT
public:
    connet(QWidget*parent = nullptr){};
public slots :
void receiveText(const QString &rettext);
signals:
void sendText(const QString &text);
};

class JSCallC : public QMainWindow
{
    Q_OBJECT

public:
    JSCallC(QWidget *parent = Q_NULLPTR);
    // ReSharper disable once IdentifierTypo
    void insertjs(QWebEnginePage * page);
private:
    Ui::JSCallCClass ui;
};
