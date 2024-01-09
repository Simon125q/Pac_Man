#include "Game.h"
#include "Clyde.h"

extern Game *game;

Clyde::Clyde()
    : Ghost()
{
    getFrames();
    setPixmap(QPixmap("resources/sprites/Clyde/RIGHT_2.png"));
    speed = 2;
}

void Clyde::getFrames()
{
    up.append(QPixmap("resources/sprites/Clyde/UP_1.png"));
    up.append(QPixmap("resources/sprites/Clyde/UP_2.png"));
    down.append(QPixmap("resources/sprites/Clyde/DOWN_1.png"));
    down.append(QPixmap("resources/sprites/Clyde/DOWN_2.png"));
    left.append(QPixmap("resources/sprites/Clyde/LEFT_1.png"));
    left.append(QPixmap("resources/sprites/Clyde/LEFT_2.png"));
    right.append(QPixmap("resources/sprites/Clyde/RIGHT_1.png"));
    right.append(QPixmap("resources/sprites/Clyde/RIGHT_2.png"));
}

void Clyde::getChaseDirection()
{
    if ((getTileX(game->getPlayerX()) + 4 < getTileX(x()) || getTileX(game->getPlayerX()) - 4 > getTileX(x())) &&
     (getTileY(game->getPlayerY()) + 4 < getTileY(y()) || getTileY(game->getPlayerY()) - 4 > getTileY(y())))
    {
        getDirection(getTileX(game->getPlayerX()), getTileY(game->getPlayerY()));
    }
    else
        getScatterDirection();
        
}

void Clyde::getScatterDirection()
{
    getDirection(20, 4);
}
