#include <QKeyEvent>
#include <QList>
#include <QTimer>
#include <iostream>

#include "Ghost.h"
#include "Inky.h"
#include "Blinky.h"
#include "Pinky.h"
#include "Clyde.h"
#include "Pellet.h"
#include "BoostPellet.h"
#include "Game.h"
#include "PacMan.h"
#include "Entity.h"
#include "settings.h"

extern Game *game;

PacMan::PacMan()
    : Entity()
{
    getFrames();
    getDeathFrames();
    direction = RIGHT;
    setPixmap(right[0]);
    speed = PLAYER_SPEED;
}

void PacMan::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W && canTurnUp())
    {
        if (direction != UP)
            setTilePos(getTileX(x()), getTileY(y()));
        direction = UP;
    }
    else if (event->key() == Qt::Key_A && canTurnLeft())
    {
        if (direction != LEFT)
            setTilePos(getTileX(x()), getTileY(y()));
        direction = LEFT;
    }
    else if (event->key() == Qt::Key_D && canTurnRight())
    {
        if (direction != RIGHT)
            setTilePos(getTileX(x()), getTileY(y()));
        direction = RIGHT;
    }
    else if (event->key() == Qt::Key_S && canTurnDown())
    {
        if (direction != DOWN)
            setTilePos(getTileX(x()), getTileY(y()));
        direction = DOWN;
    }
}

void PacMan::checkCollisions()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0; i < colliding_items.size(); i++)
    {
        if (typeid(*(colliding_items[i])) == typeid(Pellet))
        {
            game->level->score->increase(PELLET_POINTS);
            game->level->pelletLeft--;
            if (game->level->pelletLeft == 0)
                game->level->gameWon();
            delete colliding_items[i];
        }
        else if (typeid(*(colliding_items[i])) == typeid(BoostPellet))
        {
            game->level->score->increase(BOOST_PELLET_POINTS);
            game->level->pelletLeft--;
            if (game->level->pelletLeft == 0)
                game->level->gameWon();
            game->level->startFrightenedMode();
            delete colliding_items[i];
        }
        else if (typeid(*(colliding_items[i])) == typeid(Inky) || typeid(*(colliding_items[i])) == typeid(Blinky) ||
                 typeid(*(colliding_items[i])) == typeid(Pinky) || typeid(*(colliding_items[i])) == typeid(Clyde))
        {
            int ghost_index = 0;
            if (typeid(Blinky) == typeid(*(colliding_items[i])))
            {
                ghost_index = BLINKY_INDEX;
            }
            else if (typeid(Inky) == typeid(*(colliding_items[i])))
            {
                ghost_index = INKY_INDEX;
            }
            else if (typeid(Pinky) == typeid(*(colliding_items[i])))
            {
                ghost_index = PINKY_INDEX;
            }
            else if (typeid(Clyde) == typeid(*(colliding_items[i])))
            {
                ghost_index = CLYDE_INDEX;
            }
            if (game->level->ghosts[ghost_index]->mode == FRIGHTENED)
            {
                game->level->score->increase(GHOST_EATEN_POINTS);
                game->level->ghosts[ghost_index]->enterEatenMode();
            }
            else if (game->level->ghosts[ghost_index]->mode != EATEN)
                handleGhostHit();
        }
    }
}

void PacMan::handleGhostHit()
{
    game->level->bottomBar->decreaseLifes();
    if (game->level->bottomBar->getLifes() < 0)
        game->level->gameOver();
    else
        game->level->resetPositions();
}

void PacMan::getDeathFrames()
{
    deathFrames.append(QPixmap("resources/sprites/PacMan/death/1.png"));
    deathFrames.append(QPixmap("resources/sprites/PacMan/death/2.png"));
    deathFrames.append(QPixmap("resources/sprites/PacMan/death/3.png"));
    deathFrames.append(QPixmap("resources/sprites/PacMan/death/4.png"));
    deathFrames.append(QPixmap("resources/sprites/PacMan/death/5.png"));
    deathFrames.append(QPixmap("resources/sprites/PacMan/death/6.png"));
    deathFrames.append(QPixmap("resources/sprites/PacMan/death/7.png"));
    deathFrames.append(QPixmap("resources/sprites/PacMan/death/8.png"));
    deathFrames.append(QPixmap("resources/sprites/PacMan/death/9.png"));
    deathFrames.append(QPixmap("resources/sprites/PacMan/death/10.png"));
    deathFrames.append(QPixmap("resources/sprites/PacMan/death/11.png"));
}

void PacMan::getFrames()
{
    up.append(QPixmap("resources/sprites/PacMan/1.png"));
    up.append(QPixmap("resources/sprites/PacMan/UP_2.png"));
    up.append(QPixmap("resources/sprites/PacMan/UP_3.png"));
    down.append(QPixmap("resources/sprites/PacMan/1.png"));
    down.append(QPixmap("resources/sprites/PacMan/DOWN_2.png"));
    down.append(QPixmap("resources/sprites/PacMan/DOWN_3.png"));
    left.append(QPixmap("resources/sprites/PacMan/1.png"));
    left.append(QPixmap("resources/sprites/PacMan/LEFT_2.png"));
    left.append(QPixmap("resources/sprites/PacMan/LEFT_3.png"));
    right.append(QPixmap("resources/sprites/PacMan/1.png"));
    right.append(QPixmap("resources/sprites/PacMan/RIGHT_2.png"));
    right.append(QPixmap("resources/sprites/PacMan/RIGHT_3.png"));
}

void animateDeath()
{
    QTimer *animTimer = new QTimer;
    animTimer->start(100);
}

void PacMan::update()
{
    checkCollisions();
    animate();
    move();
}