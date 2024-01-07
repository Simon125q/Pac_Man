
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QBrush>
#include <QImage>
#include <iostream>

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
#include "MapTile.h"

extern Game *game;

Level::Level(QWidget *parent) :QGraphicsScene(parent), board{
                                    {6, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5},
                                    {3, 6, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 6, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 3},
                                    {3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3},
                                    {3, 3, 1, 6, 4, 4, 5, 1, 6, 4, 4, 4, 5, 1, 3, 3, 1, 6, 4, 4, 4, 5, 1, 6, 4, 4, 5, 1, 3, 3},
                                    {3, 3, 2, 3, 0, 0, 3, 1, 3, 0, 0, 0, 3, 1, 3, 3, 1, 3, 0, 0, 0, 3, 1, 3, 0, 0, 3, 2, 3, 3},
                                    {3, 3, 1, 7, 4, 4, 8, 1, 7, 4, 4, 4, 8, 1, 7, 8, 1, 7, 4, 4, 4, 8, 1, 7, 4, 4, 8, 1, 3, 3},
                                    {3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3},
                                    {3, 3, 1, 6, 4, 4, 5, 1, 6, 5, 1, 6, 4, 4, 4, 4, 4, 4, 5, 1, 6, 5, 1, 6, 4, 4, 5, 1, 3, 3},
                                    {3, 3, 1, 7, 4, 4, 8, 1, 3, 3, 1, 7, 4, 4, 5, 6, 4, 4, 8, 1, 3, 3, 1, 7, 4, 4, 8, 1, 3, 3},
                                    {3, 3, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 3, 3},
                                    {3, 7, 4, 4, 4, 4, 5, 1, 3, 7, 4, 4, 5, 0, 3, 3, 0, 6, 4, 4, 8, 3, 1, 6, 4, 4, 4, 4, 8, 3},
                                    {3, 0, 0, 0, 0, 0, 3, 1, 3, 6, 4, 4, 8, 0, 7, 8, 0, 7, 4, 4, 5, 3, 1, 3, 0, 0, 0, 0, 0, 3},
                                    {3, 0, 0, 0, 0, 0, 3, 1, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 1, 3, 0, 0, 0, 0, 0, 3},
                                    {8, 0, 0, 0, 0, 0, 3, 1, 3, 3, 0, 6, 4, 4, 9, 9, 4, 4, 5, 0, 3, 3, 1, 3, 0, 0, 0, 0, 0, 7},
                                    {4, 4, 4, 4, 4, 4, 8, 1, 7, 8, 0, 3, 0, 0, 0, 0, 0, 0, 3, 0, 7, 8, 1, 7, 4, 4, 4, 4, 4, 4},
                                    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                                    {4, 4, 4, 4, 4, 4, 5, 1, 6, 5, 0, 3, 0, 0, 0, 0, 0, 0, 3, 0, 6, 5, 1, 6, 4, 4, 4, 4, 4, 4},
                                    {5, 0, 0, 0, 0, 0, 3, 1, 3, 3, 0, 7, 4, 4, 4, 4, 4, 4, 8, 0, 3, 3, 1, 3, 0, 0, 0, 0, 0, 6},
                                    {3, 0, 0, 0, 0, 0, 3, 1, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 1, 3, 0, 0, 0, 0, 0, 3},
                                    {3, 0, 0, 0, 0, 0, 3, 1, 3, 3, 0, 6, 4, 4, 4, 4, 4, 4, 5, 0, 3, 3, 1, 3, 0, 0, 0, 0, 0, 3},
                                    {3, 6, 4, 4, 4, 4, 8, 1, 7, 8, 0, 7, 4, 4, 5, 6, 4, 4, 8, 0, 7, 8, 1, 7, 4, 4, 4, 4, 5, 3},
                                    {3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3},
                                    {3, 3, 1, 6, 4, 4, 5, 1, 6, 4, 4, 4, 5, 1, 3, 3, 1, 6, 4, 4, 4, 5, 1, 6, 4, 4, 5, 1, 3, 3},
                                    {3, 3, 1, 7, 4, 5, 3, 1, 7, 4, 4, 4, 8, 1, 7, 8, 1, 7, 4, 4, 4, 8, 1, 3, 6, 4, 8, 1, 3, 3},
                                    {3, 3, 2, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 2, 3, 3},
                                    {3, 7, 4, 5, 1, 3, 3, 1, 6, 5, 1, 6, 4, 4, 4, 4, 4, 4, 5, 1, 6, 5, 1, 3, 3, 1, 6, 4, 8, 3},
                                    {3, 6, 4, 8, 1, 7, 8, 1, 3, 3, 1, 7, 4, 4, 5, 6, 4, 4, 8, 1, 3, 3, 1, 7, 8, 1, 7, 4, 5, 3},
                                    {3, 3, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 3, 3},
                                    {3, 3, 1, 6, 4, 4, 4, 4, 8, 7, 4, 4, 5, 1, 3, 3, 1, 6, 4, 4, 8, 7, 4, 4, 4, 4, 5, 1, 3, 3},
                                    {3, 3, 1, 7, 4, 4, 4, 4, 4, 4, 4, 4, 8, 1, 7, 8, 1, 7, 4, 4, 4, 4, 4, 4, 4, 4, 8, 1, 3, 3},
                                    {3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3},
                                    {3, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 8, 3},
                                    {7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 8}}
{
    setSceneRect(0, 0, WIDTH + 2, HEIGHT + 2);
    gameLoopTimer = new QTimer();

    player = new PacMan();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    addItem(player);

    createBoard();
    //createPellet();
    createGhosts();
    resetPositions();
    

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

void Level::createBoard()
{
    for (int x_pos = 0; x_pos < TILE_COLS; x_pos++)
    {
        std::cout<<std::endl;
        for (int y_pos = 0; y_pos < (TILE_ROWS); y_pos++)
        {
            if (board[y_pos][x_pos] == 1)
            {
                std::cout<<"1, ";
                Pellet *p = new Pellet(x_pos * TILE_W, y_pos * TILE_H);
                addItem(p);
            }
            else if (board[y_pos][x_pos] == 2)
            {
                std::cout<<"2, ";
                BoostPellet *p = new BoostPellet(x_pos * TILE_W, y_pos * TILE_H);
                QObject::connect(gameLoopTimer, SIGNAL(timeout()), p, SLOT(flicker()));
                addItem(p);
            }
            else
            {
                std::cout<<" , ";
                MapTile *tile = new MapTile(board[y_pos][x_pos], x_pos, y_pos);
                addItem(tile);
            }
            // if (x_pos % 5 == 0 && y_pos % 5 == 0)
            // {
            
            // }
            // else
            // {
            //     Pellet *p = new Pellet(x_pos * 40, y_pos * 40);
            //     addItem(p);
            // }
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