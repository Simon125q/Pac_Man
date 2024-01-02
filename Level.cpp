
#include <QPainter>
#include <QPaintEvent>

#include "Level.h"
//#include "PacMan.h"

Level::Level(QWidget *parent)
    : QWidget(parent)
{

    setPalette(Qt::black);
    setAutoFillBackground(true);
}


void Level::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::yellow);
    painter.drawPie(QRect(5, 50, 130, 130), 45 * 16, 270 * 16);
    update();
}