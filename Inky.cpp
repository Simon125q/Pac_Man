#include "Game.h"
#include "Inky.h"

extern Game *game;

Inky::Inky()
    : Ghost()
{
    getFrames();
    setPixmap(QPixmap("resources/sprites/Inky/RIGHT_2.png"));
    speed = 2;
}

void Inky::getFrames()
{
    up.append(QPixmap("resources/sprites/Inky/UP_1.png"));
    up.append(QPixmap("resources/sprites/Inky/UP_2.png"));
    down.append(QPixmap("resources/sprites/Inky/DOWN_1.png"));
    down.append(QPixmap("resources/sprites/Inky/DOWN_2.png"));
    left.append(QPixmap("resources/sprites/Inky/LEFT_1.png"));
    left.append(QPixmap("resources/sprites/Inky/LEFT_2.png"));
    right.append(QPixmap("resources/sprites/Inky/RIGHT_1.png"));
    right.append(QPixmap("resources/sprites/Inky/RIGHT_2.png"));
}

void Inky::getChaseDirection()
{
    getDirection(getTileX(game->getPlayerX()), getTileY(game->getPlayerY()));
}

void Inky::getScatterDirection()
{
    getDirection(2, 20);
}
