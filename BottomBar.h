#pragma once

#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QList>

class BottomBar
{
    int lifes;

public:
    QList<QGraphicsPixmapItem *> pixLifes;

    BottomBar();
    void decreaseLifes();
    int getLifes();
};