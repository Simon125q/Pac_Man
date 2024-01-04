
#include <QKeyEvent>
#include <iostream>

#include "Entity.h"
#include "settings.h"

Entity::Entity(QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent)
{
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
