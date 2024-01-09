#include <cstdlib>
#include <ctime>
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
    directionChangeTimer = new QTimer();
    QObject::connect(modeTimer, SIGNAL(timeout()), this, SLOT(leaveFrightenMode()));
    QObject::connect(directionChangeTimer, SIGNAL(timeout()), directionChangeTimer, SLOT(stop()));
    mode = CHASE;
    speed = 2;
    moveableTiles.append(31);
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
            directionChangeTimer->start(250);
        }
        direction = RIGHT;
    }
    else if (targetX < getTileX(x()) && canTurnLeft() && direction != RIGHT)
    {
        if (direction != LEFT)
        {
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(250);
        }
        direction = LEFT;
    }
    else if (targetY > getTileY(y()) && canTurnDown() && direction != UP)
    {
        if (direction != DOWN)
        {
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(250);
        }
        direction = DOWN;
    }
    else if (targetY < getTileY(y()) && canTurnUp() && direction != DOWN)
    {
        if (direction != UP)
        {
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(250);
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
            directionChangeTimer->start(250);
        }
        direction = DOWN;
    }
    else if (targetY < getTileY(y()) && canTurnUp() && direction != DOWN)
    {
        if (direction != UP)
        {
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(250);
        }
        direction = UP;
    }
    else if (targetX > getTileX(x()) && canTurnRight() && direction != LEFT)
    {
        if (direction != RIGHT)
        {
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(250);
        }
        direction = RIGHT;
    }
    else if (targetX < getTileX(x()) && canTurnLeft() && direction != RIGHT)
    {
        if (direction != LEFT)
        {
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(250);
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
            directionChangeTimer->start(250);
        }
        direction = RIGHT;
    }
    else if (canTurnLeft() && direction != RIGHT)
    {
        if (direction != LEFT)
        {
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(250);
        }
        direction = LEFT;
    }
    else if (canTurnDown() && direction != UP)
    {
        if (direction != DOWN)
        {
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(250);
        }
        direction = DOWN;
    }
    else if (canTurnUp() && direction != DOWN)
    {
        if (direction != UP)
        {
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(250);
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
            directionChangeTimer->start(250);
        }
        else if(((direction == LEFT || direction == RIGHT) && (canTurnUp() || canTurnDown())))
        {
            int turn = rand() % 3;
            if (turn == 1)
                direction = UP;
            else if (turn == 2)
                direction = DOWN;
            else
                return;
            setTilePos(getTileX(x()), getTileY(y()));
            directionChangeTimer->start(250);
        }
    }
    
}

void Ghost::getEatenDirection()
{
    if (getTileX(x()) == getTileX(WIDTH / 2) && getTileY(y()) == getTileY(HEIGHT / 2))
    {
        mode = CHASE;
        speed = 2;
    }
    else
        getDirection(getTileX(WIDTH / 2), getTileY(HEIGHT / 2));
}

void Ghost::enterFrightenMode()
{
    modeTimer->start(3500);
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
        speed = 2;
    }
}

void Ghost::enterScatterMode()
{

    modeTimer->start(3000);
    mode = SCATTER;
}

void Ghost::enterEatenMode()
{
    mode = EATEN;
    speed = 5;
}

void Ghost::animateFrightened()
{
    if (timeBetFrame == 4)
    {
        timeBetFrame = 0;
        animationFrame++;
        if (animationFrame >= frightenedFrames.size())
            animationFrame = 0;
        setPixmap(frightenedFrames[animationFrame]);
    }
    timeBetFrame++;
}

void Ghost::update()
{
    if (mode == CHASE)
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
