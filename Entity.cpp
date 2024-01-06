
#include <QKeyEvent>
#include <iostream>

#include "Entity.h"
#include "settings.h"

Entity::Entity(QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent)
{
    timeBetFrame = 0;
    animationFrame = 0;
}

void Entity::move()
{
    if (direction == UP && y() > 0)
        setPos(x(), y() - speed);
    if (direction == DOWN && y() + boundingRect().height() < HEIGHT)
        setPos(x(), y() + speed);
    if (direction == LEFT && x() > 0)
        setPos(x() - speed, y());
    if (direction == RIGHT && x() + boundingRect().width() < WIDTH)
        setPos(x() + speed, y());
}

void Entity::animate()
{
    if (timeBetFrame == 4)
    {
        timeBetFrame = 0;
        animationFrame++;
        if(direction == UP)
        {
            if (animationFrame >= up.size())
                animationFrame = 0;
            setPixmap(up[animationFrame]);
        }
        else if(direction == DOWN)
        {
            if (animationFrame >= down.size())
                animationFrame = 0;
            setPixmap(down[animationFrame]);
        }
        else if(direction == RIGHT)
        {
            if (animationFrame >= right.size())
                animationFrame = 0;
            setPixmap(right[animationFrame]);
        }
        else if(direction == LEFT)
        {
            if (animationFrame >= left.size())
                animationFrame = 0;
            setPixmap(left[animationFrame]);
        }
    }
    
    timeBetFrame++;
}
