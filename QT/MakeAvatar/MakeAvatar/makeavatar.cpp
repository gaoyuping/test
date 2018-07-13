#include "makeavatar.h"

MakeAvatar::MakeAvatar(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    m_ddd = new MakeAvatarWidget(this, 100, 100);
    m_ddd->show();
    m_ddd->move(0, 0);
    m_btn = new QPushButton(this);
    m_btn->setText(QStringLiteral("¡À¡ê¡ä?"));
    m_btn->move(500, 10);
    connect(m_btn, &QPushButton::clicked, [&](){
        m_ddd->savepic();
    });

}

MakeAvatar::~MakeAvatar()
{

}
