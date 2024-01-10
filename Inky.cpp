#include "Game.h"
#include "Inky.h"

extern Game *game;

Inky::Inky()
    : Ghost()
{
    getFrames();
    setPixmap(up[0]);
    speed = GHOST_INIT_SPEED;
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
    int playerFrontX = 0;
    int playerFrontY = 0;
    int blinkyFrontX = getTileX(game->level->ghosts[CLYDE_INDEX]->x());
    int blinkyFrontY = getTileY(game->level->ghosts[CLYDE_INDEX]->y());
    if (game->getPlayerDirection() == UP)
    {
        playerFrontX = getTileX(game->getPlayerX());
        playerFrontY = getTileY(game->getPlayerY()) - 2;
    }
    else if (game->getPlayerDirection() == DOWN)
    {
        playerFrontX = getTileX(game->getPlayerX());
        playerFrontY = getTileY(game->getPlayerY()) + 2;
    }
    else if (game->getPlayerDirection() == RIGHT)
    {
        playerFrontX = getTileX(game->getPlayerX()) + 2;
        playerFrontY = getTileY(game->getPlayerY());
    }
    else if (game->getPlayerDirection() == LEFT)
    {
        playerFrontX = getTileX(game->getPlayerX()) - 2;
        playerFrontY = getTileY(game->getPlayerY()) - 2;
    }
    getDirection(playerFrontX + (playerFrontX - blinkyFrontX), playerFrontY + (playerFrontY - blinkyFrontY));
}

void Inky::getScatterDirection()
{
    getDirection(TILE_COLS, TILE_ROWS);
}
