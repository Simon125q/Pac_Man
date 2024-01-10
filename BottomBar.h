#pragma once

#include <QGraphicsTextItem>

class BottomBar : public QGraphicsTextItem
{
    int lifes;

public:
    BottomBar(QGraphicsItem *parent = 0);
    void decreaseLifes();
    int getLifes();
};