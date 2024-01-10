#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <QObject>
#include "Game.h"
#include "Ghost.h"
#include "Entity.h"
#include "settings.h"

extern Game *game;

Ghost::Ghost()
    : Entity()
{
    getFrightenedFrames();
    modeTimer = new QTimer();
    scatterTimer = new QTimer();
    directionChangeTimer = new QTimer();
    QObject::connect(modeTimer, SIGNAL(timeout()), this, SLOT(leaveFrightenMode()));
    QObject::connect(scatterTimer, SIGNAL(timeout()), this, SLOT(enterScatterMode()));
    QObject::connect(modeTimer, SIGNAL(timeout()), this, SLOT(leaveScatterMode()));
    QObject::connect(directionChangeTimer, SIGNAL(timeout()), directionChangeTimer, SLOT(stop()));
    scatterTimer->start(TIME_BETWEEN_SCATTERS);
    mode = CHASE;
    speed = GHOST_INIT_SPEED;
    moveableTiles.append(CAGE_ENTRY_TILE);
    srand((unsigned)time(0));
}

void Ghost::getFrightenedFrames()
{
    frightenedFrames.append(QPixmap("resources/sprites/FRIGHTENED_1.png"));
    frightenedFrames.append(QPixmap("resources/sprites/FRIGHTENED_2.png"));
    frightenedFrames.append(QPixmap("resources/sprites/FRIGHTENED_3.png"));
    frightenedFrames.append(QPixmap("resources/sprites/FRIGHTENED_4.png"));
}

void Ghost::getDirection(int targetX, int targetY)
{
    if (!directionChangeTimer->isActive())
    {
        if (abs(targetX - getTileX(x())) >= abs(targetY - getTileY(y())))
            getDirectionForX(targetX, targetY);
        else
            getDirectionForY(targetX, targetY);
    }
}

void Ghost::getDirectionForX(int targetX, int targetY)
{
    if (targetX > getTileX(x()) && canTurnRight() && direction != LEFT)
    {
        if (direction != RIGHT)
        {
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(DIRECTION_CHANGE_COOLDOWN);
        }
        direction = RIGHT;
    }
    else if (targetX < getTileX(x()) && canTurnLeft() && direction != RIGHT)
    {
        if (direction != LEFT)
        {
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(DIRECTION_CHANGE_COOLDOWN);
        }
        direction = LEFT;
    }
    else if (targetY > getTileY(y()) && canTurnDown() && direction != UP)
    {
        if (direction != DOWN)
        {
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(DIRECTION_CHANGE_COOLDOWN);
        }
        direction = DOWN;
    }
    else if (targetY < getTileY(y()) && canTurnUp() && direction != DOWN)
    {
        if (direction != UP)
        {
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(DIRECTION_CHANGE_COOLDOWN);
        }
        direction = UP;
    }
    else
        getDirectionForBlockedWay();
}

void Ghost::getDirectionForY(int targetX, int targetY)
{
    if (targetY > getTileY(y()) && canTurnDown() && direction != UP)
    {
        if (direction != DOWN)
        {
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(DIRECTION_CHANGE_COOLDOWN);
        }
        direction = DOWN;
    }
    else if (targetY < getTileY(y()) && canTurnUp() && direction != DOWN)
    {
        if (direction != UP)
        {
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(DIRECTION_CHANGE_COOLDOWN);
        }
        direction = UP;
    }
    else if (targetX > getTileX(x()) && canTurnRight() && direction != LEFT)
    {
        if (direction != RIGHT)
        {
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(DIRECTION_CHANGE_COOLDOWN);
        }
        direction = RIGHT;
    }
    else if (targetX < getTileX(x()) && canTurnLeft() && direction != RIGHT)
    {
        if (direction != LEFT)
        {
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(DIRECTION_CHANGE_COOLDOWN);
        }
        direction = LEFT;
    }
    else
        getDirectionForBlockedWay();
}

void Ghost::getDirectionForBlockedWay()
{
    if (canTurnRight() && direction != LEFT)
    {
        if (direction != RIGHT)
        {
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(DIRECTION_CHANGE_COOLDOWN);
        }
        direction = RIGHT;
    }
    else if (canTurnLeft() && direction != RIGHT)
    {
        if (direction != LEFT)
        {
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(DIRECTION_CHANGE_COOLDOWN);
        }
        direction = LEFT;
    }
    else if (canTurnDown() && direction != UP)
    {
        if (direction != DOWN)
        {
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(DIRECTION_CHANGE_COOLDOWN);
        }
        direction = DOWN;
    }
    else if (canTurnUp() && direction != DOWN)
    {
        if (direction != UP)
        {
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(DIRECTION_CHANGE_COOLDOWN);
        }
        direction = UP;
    }
}

void Ghost::getFrightenedDirections()
{
    if (!directionChangeTimer->isActive())
    {
        if (((direction == UP || direction == DOWN) && (canTurnLeft() || canTurnRight())))
        {
            int turn = rand() % 3;
            if (turn == 1)
                direction = LEFT;
            else if (turn == 2)
                direction = RIGHT;
            else
                return;
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(DIRECTION_CHANGE_COOLDOWN);
        }
        else if (((direction == LEFT || direction == RIGHT) && (canTurnUp() || canTurnDown())))
        {
            int turn = rand() % 3;
            if (turn == 1)
                direction = UP;
            else if (turn == 2)
                direction = DOWN;
            else
                return;
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(DIRECTION_CHANGE_COOLDOWN);
        }
    }
}

void Ghost::getEatenDirection()
{
    getDirection(getTileX(WIDTH / 2), getTileY(HEIGHT / 2));
}

void Ghost::getOutOfCageDirection()
{
    getDirection(13, 14);
    mode = CHASE;
    speed = GHOST_INIT_SPEED;
}

void Ghost::enterFrightenMode()
{
    modeTimer->start(FRIGHTENED_MODE_DURATION);
    mode = FRIGHTENED;
    if (direction == UP)
        direction = DOWN;
    else if (direction == DOWN)
        direction = UP;
    else if (direction == RIGHT)
        direction = LEFT;
    else if (direction == LEFT)
        direction = RIGHT;
}

void Ghost::leaveFrightenMode()
{
    if (mode == FRIGHTENED)
    {
        modeTimer->stop();
        mode = CHASE;
        speed = GHOST_INIT_SPEED;
    }
}

void Ghost::enterScatterMode()
{
    modeTimer->start(SCATTER_MODE_DURATION);
    mode = SCATTER;
}

void Ghost::leaveScatterMode()
{
    if (mode == SCATTER)
    {
        modeTimer->stop();
        mode = CHASE;
        speed = GHOST_INIT_SPEED;
    }
}

void Ghost::enterEatenMode()
{
    mode = EATEN;
    speed = GHOST_EATEN_SPEED;
}

void Ghost::animateFrightened()
{
    if (timeBetFrame == TIME_BETWEEN_ANIMATION_FRAMES)
    {
        timeBetFrame = 0;
        animationFrame++;
        if (animationFrame >= frightenedFrames.size())
            animationFrame = 0;
        setPixmap(frightenedFrames[animationFrame]);
    }
    timeBetFrame++;
}

bool Ghost::isInCage()
{
    int tileX = getTileX(x());
    int tileY = getTileY(y());

    if ((tileY == 16 || tileY == 17 || tileY == 18) &&
        (tileX == 11 || tileX == 12 || tileX == 13 || tileX == 14 || tileX == 15 || tileX == 16))
        return true;
    else
        return false;
}

void Ghost::update()
{
    if (isInCage())
    {
        getOutOfCageDirection();
        animate();
    }
    else if (mode == CHASE)
    {
        getChaseDirection();
        animate();
    }
    else if (mode == SCATTER)
    {
        getScatterDirection();
        animate();
    }
    else if (mode == EATEN)
    {
        getEatenDirection();
        animate();
    }
    else if (mode == FRIGHTENED)
    {
        getFrightenedDirections();
        animateFrightened();
    }
    move();
}
