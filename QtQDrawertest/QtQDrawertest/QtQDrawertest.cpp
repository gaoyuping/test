#include "QtQDrawertest.h"

QtQDrawertest::QtQDrawertest(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ssss = new QDrawer(this);
    ssss->addLayerDrawer(QStringLiteral("²âÊÔ1"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ1"), QStringLiteral("1_1"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ1"), QStringLiteral("1_2"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ1"), QStringLiteral("1_3"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ1"), QStringLiteral("1_4"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ1"), QStringLiteral("1_5"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ1"), QStringLiteral("1_6"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ1"), QStringLiteral("1_7"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ1"), QStringLiteral("1_8"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ1"), QStringLiteral("1_9"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ1"), QStringLiteral("1_10"));
    ssss->setLayerDrawerbackgroud(0, "#FFFFF0FF");
    ssss->addLayerDrawer(QStringLiteral("²âÊÔ2"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ2"), QStringLiteral("2_1"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ2"), QStringLiteral("2_2"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ2"), QStringLiteral("2_3"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ2"), QStringLiteral("2_4"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ2"), QStringLiteral("2_5"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ2"), QStringLiteral("2_6"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ2"), QStringLiteral("2_7"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ2"), QStringLiteral("2_8"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ2"), QStringLiteral("2_9"));
    ssss->setLayerDrawerbackgroud(1, "#FFFFF00F");

    ssss->addLayerDrawer(QStringLiteral("²âÊÔ3"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ3"), QStringLiteral("3_1"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ3"), QStringLiteral("3_2"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ3"), QStringLiteral("3_3"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ3"), QStringLiteral("3_4"));
    ssss->addLayerDrawerContent(QStringLiteral("²âÊÔ3"), QStringLiteral("3_5"));
    ssss->setLayerDrawerbackgroud(2, "#FFFF0FF0");
}
