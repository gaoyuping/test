#include "makeavatar.h"

MakeAvatar::MakeAvatar(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    m_ddd = new MakeAvatarWidget(this, 100, 100);
    m_ddd->show();
    m_ddd->move(0, 0);
    m_btn = new QPushButton(this);
    m_btn->setText(QStringLiteral(""));
    m_btn->resize(100, 100);
    m_btn->setIcon(QIcon(R"(F:/1.png)"));
    m_btn->setIconSize(QSize(100, 100));
    m_btn->move(500, 10);
    connect(m_btn, &QPushButton::clicked, [&](){
        m_ddd->savepic();
    });

}

MakeAvatar::~MakeAvatar()
{

}
