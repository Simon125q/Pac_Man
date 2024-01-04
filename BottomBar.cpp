#include <QFont>
#include "BottomBar.h"

BottomBar::BottomBar(QGraphicsItem *parent)
    : QGraphicsTextItem(parent)
{
    lifes = 3;
    cheeries = 0;

    setPlainText(QString("Lifes: ") + QString::number(lifes) + QString("    Cherries: ") + QString::number(cheeries));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 16));
}

void BottomBar::increaseCheeries()
{
    cheeries ++;
    setPlainText(QString("Lifes: ") + QString::number(lifes) + QString("    Cherries: ") + QString::number(cheeries));
}

void BottomBar::decreaseLifes()
{
    lifes --;
    setPlainText(QString("Lifes: ") + QString::number(lifes) + QString("    Cherries: ") + QString::number(cheeries));
}

int BottomBar::getLifes()
{
    return lifes;
}