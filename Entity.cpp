
#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>
#include <iostream>

#include "Entity.h"

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

void Entity::move()
{
    // if (direction == UP && y > 0)
    //     y--;
    // if (direction == DOWN && y < 1000)
    //     y++;
    // if (direction == LEFT && x > 0)
    //     x--;
    // if (direction == RIGHT && x < 1000)
    //     x++; 
}

void Entity::keyPressedEvent(QKeyEvent *event)
{
    std::cout<<"Key pressed"<<std::endl;
    if(event->key() == Qt::Key_W)
    {
        std::cout<<"its W"<<std::endl;
        setPos(x(), y()-1);
    }
}