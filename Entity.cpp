
#include <QKeyEvent>
#include <iostream>
#include <math.h>

#include "Game.h"
#include "Entity.h"
#include "settings.h"

extern Game *game;

Entity::Entity(QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent)
{
    timeBetFrame = 0;
    animationFrame = 0;
    moveableTiles.append(PELLET_TILE);
    moveableTiles.append(BOOST_PELLET_TILE);
    moveableTiles.append(EMPTY_TILE);
}

void Entity::setTilePos(int x, int y)
{
    setPos(x * TILE_W + TILE_W / 2 - (boundingRect().width() / 2), y * TILE_H + TILE_H / 2 - (boundingRect().height() / 2));
}

int Entity::getTileX(int x)
{
    return floor(x / TILE_W);
}

int Entity::getTileY(int y)
{
    return floor(y / TILE_H);
}

bool Entity::canTurnUp()
{
    int tileX = getTileX(this->x());
    int tileY = getTileY(this->y() - TILE_H / 2 + boundingRect().height() / 2);
    int checkTileType = game->level->board[tileX][tileY - 1];
    if (moveableTiles.contains(checkTileType))
        return true;
    else
        return false;
}

bool Entity::canTurnDown()
{
    int tileX = getTileX(this->x());
    int tileY = getTileY(this->y() + TILE_H / 2 - boundingRect().height() / 2);
    int checkTileType = game->level->board[tileX][tileY + 1];
    if (moveableTiles.contains(checkTileType))
        return true;
    else
        return false;
}

bool Entity::canTurnRight()
{
    int tileX = getTileX(this->x() - TILE_W / 2 + boundingRect().width() / 2);
    int tileY = getTileY(this->y());
    int checkTileType = game->level->board[tileX + 1][tileY];
    if (moveableTiles.contains(checkTileType))
        return true;
    else
        return false;
}

bool Entity::canTurnLeft()
{
    int tileX = getTileX(this->x() + TILE_W / 2 - boundingRect().width() / 2);
    int tileY = getTileY(this->y());
    int checkTileType = game->level->board[tileX - 1][tileY];
    if (moveableTiles.contains(checkTileType))
        return true;
    else
        return false;
}

bool Entity::canMoveUp()
{
    int tileX = getTileX(this->x());
    int tileY = getTileY(this->y() - speed);
    int checkTileType = game->level->board[tileX][tileY];
    if (moveableTiles.contains(checkTileType))
        return true;
    else
        return false;
}

bool Entity::canMoveDown()
{
    int tileX = getTileX(this->x());
    int tileY = getTileY(this->y() + boundingRect().height() / 2 + speed);
    int checkTileType = game->level->board[tileX][tileY];
    if (moveableTiles.contains(checkTileType))
        return true;
    else
        return false;
}

bool Entity::canMoveRight()
{
    int tileX = getTileX(this->x() + boundingRect().width() / 2 + speed);
    int tileY = getTileY(this->y());
    int checkTileType = game->level->board[tileX][tileY];
    if (moveableTiles.contains(checkTileType))
        return true;
    else
        return false;
}

bool Entity::canMoveLeft()
{
    int tileX = getTileX(this->x() - speed);
    int tileY = getTileY(this->y());
    int checkTileType = game->level->board[tileX][tileY];
    if (moveableTiles.contains(checkTileType))
        return true;
    else
        return false;
}

void Entity::move()
{
    if (direction == UP && y() > 0 && canMoveUp())
        setPos(x(), y() - speed);
    if (direction == DOWN && y() + boundingRect().height() < HEIGHT && canMoveDown())
        setPos(x(), y() + speed);
    if (direction == LEFT && x() > 0 && canMoveLeft())
        setPos(x() - speed, y());
    if (direction == RIGHT && x() + boundingRect().width() < WIDTH && canMoveRight())
        setPos(x() + speed, y());
    if (direction == LEFT && x() <= 0)
        setPos(WIDTH - speed, y());
    if (direction == RIGHT && x() + boundingRect().width() >= WIDTH)
        setPos(0 + speed, y());
}

void Entity::animate()
{
    if (timeBetFrame == TIME_BETWEEN_ANIMATION_FRAMES)
    {
        timeBetFrame = 0;
        animationFrame++;
        if (direction == UP)
        {
            if (animationFrame >= up.size())
                animationFrame = 0;
            setPixmap(up[animationFrame]);
        }
        else if (direction == DOWN)
        {
            if (animationFrame >= down.size())
                animationFrame = 0;
            setPixmap(down[animationFrame]);
        }
        else if (direction == RIGHT)
        {
            if (animationFrame >= right.size())
                animationFrame = 0;
            setPixmap(right[animationFrame]);
        }
        else if (direction == LEFT)
        {
            if (animationFrame >= left.size())
                animationFrame = 0;
            setPixmap(left[animationFrame]);
        }
    }

    timeBetFrame++;
}
