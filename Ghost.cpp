
#include "Game.h"
#include "Ghost.h"
#include "Entity.h"
#include "settings.h"

extern Game *game;

Ghost::Ghost()
    : Entity()
{
    setPixmap(QPixmap("resources/sprites/Ghost/RIGHT_2.png"));
    speed = 8;
}

void Ghost::getDirection()
{
    int playerX = game->player->x();
    int playerY = game->player->y();
    if (playerX - speed > x())
        direction = RIGHT;
    else if (playerX + speed < x())
        direction = LEFT;
    else if (playerY - speed > y())
        direction = DOWN;
    else if (playerY + speed < y())
        direction = UP;
}

void Ghost::update()
{
    getDirection();
    move();
}
