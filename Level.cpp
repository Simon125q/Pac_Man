
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QBrush>
#include <QImage>

#include "Level.h"
#include "Game.h"
#include "Blinky.h"
#include "Inky.h"
#include "Pinky.h"
#include "Clyde.h"
#include "Entity.h"
#include "Pellet.h"
#include "BoostPellet.h"
#include "settings.h"
#include "Score.h"
#include "BottomBar.h"

extern Game *game;

Level::Level(QWidget *parent)
    : QGraphicsScene(parent)
{
    setSceneRect(0, 0, WIDTH, HEIGHT);
    gameLoopTimer = new QTimer();

    player = new PacMan();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    addItem(player);

    createGhosts();
    resetPositions();
    createPellet();

    score = new Score();
    score->setPos(WIDTH / 2, score->y());
    addItem(score);

    bottomBar = new BottomBar();
    bottomBar->setPos(WIDTH / 2, HEIGHT - 40);
    addItem(bottomBar);

    QObject::connect(gameLoopTimer, SIGNAL(timeout()), this, SLOT(updateLevel()));
    gameLoopTimer->start(25);
}

void Level::createGhosts()
{
    Blinky *blinky = new Blinky();
    ghosts.append(blinky);
    addItem(blinky);

    Inky *inky = new Inky();
    ghosts.append(inky);
    addItem(inky);

    Pinky *pinky = new Pinky();
    ghosts.append(pinky);
    addItem(pinky);

    Clyde *clyde = new Clyde();
    ghosts.append(clyde);
    addItem(clyde);
}

void Level::resetPositions()
{
    player->setPos(WIDTH / 4, HEIGHT / 4);

    for (int ghost_index = 0; ghost_index < ghosts.size(); ghost_index++)
    {
        ghosts[ghost_index]->setPos(WIDTH / 2 + 50 * ghost_index, HEIGHT / 2);
    }
}

void Level::createPellet()
{
    for (int posX = 0; posX < 20; posX++)
    {
        for (int posY = 0; posY < 20; posY++)
        {
            if (posX % 5 == 0 && posY % 5 == 0)
            {
                BoostPellet *p = new BoostPellet(posX * 40, posY * 40);
                QObject::connect(gameLoopTimer, SIGNAL(timeout()), p, SLOT(flicker()));
                addItem(p);
            }
            else
            {
                Pellet *p = new Pellet(posX * 40, posY * 40);
                addItem(p);
            }
        }
    }
}

void Level::startFrightenedMode()
{
    for (int ghost_index = 0; ghost_index < ghosts.size(); ghost_index++)
    {
        ghosts[ghost_index]->enterFrightenMode();
    }
}

void Level::updateLevel()
{
    player->update();

    for (int ghost_index = 0; ghost_index < ghosts.size(); ghost_index++)
    {
        ghosts[ghost_index]->update();
    }
}