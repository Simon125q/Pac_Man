#include <QKeyEvent>
#include <QList>
#include <iostream>

#include "Ghost.h"
#include "Inky.h"
#include "Blinky.h"
#include "Pinky.h"
#include "Clyde.h"
#include "Game.h"
#include "PacMan.h"
#include "Entity.h"
#include "settings.h"

extern Game *game;

PacMan::PacMan()
    : Entity() {
        setPixmap(QPixmap("resources/sprites/PacMan/RIGHT_2.png"));
        speed = 10;
    }

void PacMan::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W)
    {
        direction = UP;
    }
    else if (event->key() == Qt::Key_A)
    {
        direction = LEFT;
    }
    else if (event->key() == Qt::Key_D)
    {
        direction = RIGHT;
    }
    else if (event->key() == Qt::Key_S)
    {
        direction = DOWN;
    }
}

void PacMan::checkCollisions()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0; i < colliding_items.size(); i++)
    {
        if (typeid(*(colliding_items[i])) == typeid(Inky) || typeid(*(colliding_items[i])) == typeid(Blinky) ||
            typeid(*(colliding_items[i])) == typeid(Pinky) || typeid(*(colliding_items[i])) == typeid(Clyde))
        {
            game->bottomBar->decreaseLifes();
            if(game->bottomBar->getLifes() == 0)
                game->newGame();
            else
                game->resetPositions();
        }
    }
}

void PacMan::update()
{
    checkCollisions();
    move();
}