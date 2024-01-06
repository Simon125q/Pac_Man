
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
    QObject::connect(modeTimer, SIGNAL(timeout()), this, SLOT(enterChaseMode()));
    mode = CHASE;
    speed = 6;
}

void Ghost::getFrightenedFrames()
{
    frightenedFrames.append(QPixmap("resources/sprites/FRIGHTENED_1.png"));
    frightenedFrames.append(QPixmap("resources/sprites/FRIGHTENED_2.png"));
}

void Ghost::getChaseDirection()
{
    int playerX = game->level->player->x();
    int playerY = game->level->player->y();
    if (playerX - speed > x())
        direction = RIGHT;
    else if (playerX + speed < x())
        direction = LEFT;
    else if (playerY - speed > y())
        direction = DOWN;
    else if (playerY + speed < y())
        direction = UP;
}

void Ghost::getFrightenedDirections()
{
    direction = UP;
}

void Ghost::getScatterDirection()
{
    direction = DOWN;
}

void Ghost::enterFrightenMode()
{
    
    modeTimer->start(5000);
    mode = FRIGHTENED;
}

void Ghost::enterChaseMode()
{
    modeTimer->stop();
    //QObject::disconnect(modeTimer, SIGNAL(timeout()), this, SLOT(enterChaseMode()));
    mode = CHASE;
}

void Ghost::enterScatterMode()
{
    
    modeTimer->start(3000);
    mode = SCATTER;
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
    else if (mode == FRIGHTENED)
    {
        getFrightenedDirections();
        animateFrightened();
    }
    move();
}
