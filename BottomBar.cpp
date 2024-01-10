#include <QFont>
#include "BottomBar.h"
#include "settings.h"

BottomBar::BottomBar(QGraphicsItem *parent)
    : QGraphicsTextItem(parent)
{
    lifes = PLAYER_INIT_LIFES;

    setPlainText(QString::number(lifes));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 16));
}

void BottomBar::decreaseLifes()
{
    lifes--;
    setPlainText(QString::number(lifes));
}

int BottomBar::getLifes()
{
    return lifes;
}