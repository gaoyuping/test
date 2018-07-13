#ifndef MAKEAVATAR_H
#define MAKEAVATAR_H

#include <QtWidgets/QMainWindow>
#include "ui_makeavatar.h"
#include "MakeAvatarWidget.h"
#include <QPushButton>
class MakeAvatar : public QMainWindow
{
    Q_OBJECT

public:
    MakeAvatar(QWidget *parent = 0);
    ~MakeAvatar();

private:
    Ui::MakeAvatarClass ui;
    MakeAvatarWidget * m_ddd;
    QPushButton * m_btn;
};

#endif // MAKEAVATAR_H
