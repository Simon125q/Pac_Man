#pragma once

#include <QGraphicsTextItem>

class BottomBar : public QGraphicsTextItem
{
    int lifes;
    int cheeries;

public:
    BottomBar(QGraphicsItem *parent = 0);
    void increaseCheeries();
    void decreaseLifes();
    int getLifes();
};