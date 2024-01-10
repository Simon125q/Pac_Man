#include "Game.h"
#include "Clyde.h"

extern Game *game;

Clyde::Clyde()
    : Ghost()
{
    getFrames();
    setPixmap(up[0]);
    speed = GHOST_INIT_SPEED;
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
    if ((getTileX(game->getPlayerX()) + CLYDE_SCATTER_RANGE < getTileX(x()) || getTileX(game->getPlayerX()) - CLYDE_SCATTER_RANGE > getTileX(x())) &&
        (getTileY(game->getPlayerY()) + CLYDE_SCATTER_RANGE < getTileY(y()) || getTileY(game->getPlayerY()) - CLYDE_SCATTER_RANGE > getTileY(y())))
    {
        getDirection(getTileX(game->getPlayerX()), getTileY(game->getPlayerY()));
    }
    else
        getScatterDirection();
}

void Clyde::getScatterDirection()
{
    getDirection(0, TILE_ROWS);
}
