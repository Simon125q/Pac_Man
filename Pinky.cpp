#include "Game.h"
#include "Pinky.h"

extern Game *game;

Pinky::Pinky()
    : Ghost()
{
    getFrames();
    setPixmap(up[0]);
}

void Pinky::getFrames()
{
    up.append(QPixmap("resources/sprites/Pinky/UP_1.png"));
    up.append(QPixmap("resources/sprites/Pinky/UP_2.png"));
    down.append(QPixmap("resources/sprites/Pinky/DOWN_1.png"));
    down.append(QPixmap("resources/sprites/Pinky/DOWN_2.png"));
    left.append(QPixmap("resources/sprites/Pinky/LEFT_1.png"));
    left.append(QPixmap("resources/sprites/Pinky/LEFT_2.png"));
    right.append(QPixmap("resources/sprites/Pinky/RIGHT_1.png"));
    right.append(QPixmap("resources/sprites/Pinky/RIGHT_2.png"));
}

void Pinky::getChaseDirection()
{
    if (game->getPlayerDirection() == UP)
        getDirection(getTileX(game->getPlayerX()), getTileY(game->getPlayerY()) - 4);
    else if (game->getPlayerDirection() == DOWN)
        getDirection(getTileX(game->getPlayerX()), getTileY(game->getPlayerY()) + 4);
    else if (game->getPlayerDirection() == RIGHT)
        getDirection(getTileX(game->getPlayerX()) + 4, getTileY(game->getPlayerY()));
    else if (game->getPlayerDirection() == LEFT)
        getDirection(getTileX(game->getPlayerX()) - 4, getTileY(game->getPlayerY()) - 4);
}

void Pinky::getScatterDirection()
{
    getDirection(0, 0);
}