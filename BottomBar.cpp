#include <QFont>
#include <QGraphicsPixmapItem>
#include "BottomBar.h"
#include "settings.h"

BottomBar::BottomBar()
{
    lifes = PLAYER_INIT_LIFES;

    for (int life = 0; life < lifes; life++)
    {
        QGraphicsPixmapItem *l = new QGraphicsPixmapItem();
        l->setPixmap(QPixmap("resources/sprites/PacMan/RIGHT_2.png"));
        l->setPos(life * TILE_W, (TILE_ROWS - 1) * TILE_H);
        pixLifes.append(l);
    }
}

void BottomBar::decreaseLifes()
{
    lifes--;
    if (lifes >= 0)
    {
        delete pixLifes.last();
        pixLifes.pop_back();
    }
}

int BottomBar::getLifes()
{
    return lifes;
}