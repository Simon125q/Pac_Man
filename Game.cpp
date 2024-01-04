#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QBrush>
#include <QImage>

#include "Blinky.h"
#include "Inky.h"
#include "Pinky.h"
#include "Clyde.h"
#include "Entity.h"
#include "Game.h"
#include "settings.h"
#include "Score.h"
#include "BottomBar.h"

Game::Game(QWidget *parent)
    :QGraphicsView(parent)
{

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, WIDTH, HEIGHT);
    setBackgroundBrush(QBrush(Qt::black));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WIDTH, HEIGHT);

    player = new PacMan();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    createGhosts();
    resetPositions();

    score = new Score();
    score->setPos(WIDTH / 2, score->y());
    scene->addItem(score);

    bottomBar = new BottomBar();
    bottomBar->setPos(WIDTH / 2, HEIGHT - 40);
    scene->addItem(bottomBar);

    gameLoopTimer = new QTimer();
    QObject::connect(gameLoopTimer, SIGNAL(timeout()), this, SLOT(updateGame()));
    gameLoopTimer->start(25);

    show();
}

void Game::createGhosts()
{
    Blinky *blinky = new Blinky();
    scene->addItem(blinky);
    ghosts.append(blinky);

    Inky *inky = new Inky();
    scene->addItem(inky);
    ghosts.append(inky);

    Pinky *pinky = new Pinky();
    scene->addItem(pinky);
    ghosts.append(pinky);

    Clyde *clyde = new Clyde();
    scene->addItem(clyde);
    ghosts.append(clyde);
}

void Game::resetPositions()
{
    player->setPos(WIDTH / 4, HEIGHT / 4);

    for (int ghost_index = 0; ghost_index < ghosts.size(); ghost_index++)
    {
        ghosts[ghost_index]->setPos(WIDTH / 2 + 50 * ghost_index, HEIGHT / 2);
    }
}

void Game::updateGame()
{
    player->update();

    for (int ghost_index = 0; ghost_index < ghosts.size(); ghost_index++)
    {
        ghosts[ghost_index]->update();
    }
}