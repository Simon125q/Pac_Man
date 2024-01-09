
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

Level::Level(QWidget *parent) : QGraphicsScene(parent), board{
                                                            // y=>                 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35
                                                            /*x0 */ {30, 30, 30, 0, 13, 13, 13, 13, 13, 13, 13, 13, 1, 30, 30, 30, 8, 30, 9, 30, 30, 30, 0, 13, 13, 13, 13, 17, 28, 13, 13, 13, 13, 1, 30, 30},
                                                            /*x1 */ {30, 30, 30, 8, 26, 26, 27, 26, 26, 26, 26, 26, 9, 30, 30, 30, 8, 30, 9, 30, 30, 30, 8, 26, 26, 26, 27, 11, 10, 26, 26, 26, 26, 9, 30, 30},
                                                            /*x2 */ {30, 30, 30, 8, 26, 2, 14, 3, 26, 2, 3, 26, 9, 30, 30, 30, 8, 30, 9, 30, 30, 30, 8, 26, 2, 3, 26, 6, 7, 26, 2, 3, 26, 9, 30, 30},
                                                            /*x3 */ {30, 30, 30, 8, 26, 11, 30, 10, 26, 11, 10, 26, 9, 30, 30, 30, 8, 30, 9, 30, 30, 30, 8, 26, 11, 10, 26, 26, 26, 26, 11, 10, 26, 9, 30, 30},
                                                            /*x4 */ {30, 30, 30, 8, 26, 11, 30, 10, 26, 11, 10, 26, 9, 30, 30, 30, 8, 30, 9, 30, 30, 30, 8, 26, 11, 6, 14, 14, 3, 26, 11, 10, 26, 9, 30, 30},
                                                            /*x5 */ {30, 30, 30, 8, 26, 6, 15, 7, 26, 6, 7, 26, 6, 13, 13, 13, 7, 30, 6, 13, 13, 13, 7, 26, 6, 15, 15, 15, 7, 26, 11, 10, 26, 9, 30, 30},
                                                            /*x6 */ {30, 30, 30, 8, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 11, 10, 26, 9, 30, 30},
                                                            /*x7 */ {30, 30, 30, 8, 26, 2, 14, 3, 26, 2, 14, 14, 14, 14, 14, 14, 3, 30, 2, 14, 14, 14, 3, 26, 2, 3, 26, 2, 14, 14, 7, 10, 26, 9, 30, 30},
                                                            /*x8 */ {30, 30, 30, 8, 26, 11, 30, 10, 26, 6, 15, 15, 3, 2, 15, 15, 7, 30, 6, 15, 15, 15, 7, 26, 11, 10, 26, 6, 15, 15, 3, 10, 26, 9, 30, 30},
                                                            /*x9 */ {30, 30, 30, 8, 26, 11, 30, 10, 26, 26, 26, 26, 11, 10, 30, 30, 30, 30, 30, 30, 30, 30, 30, 26, 11, 10, 26, 26, 26, 26, 11, 10, 26, 9, 30, 30},
                                                            /*x10 */ {30, 30, 30, 8, 26, 11, 30, 10, 26, 2, 3, 26, 11, 10, 30, 18, 12, 12, 12, 19, 30, 2, 3, 26, 11, 10, 26, 2, 3, 26, 11, 10, 26, 9, 30, 30},
                                                            /*x11 */ {30, 30, 30, 8, 26, 6, 15, 7, 26, 11, 10, 26, 6, 7, 30, 9, 30, 30, 30, 8, 30, 11, 10, 26, 6, 7, 26, 11, 10, 26, 6, 7, 26, 9, 30, 30},
                                                            /*x12 */ {30, 30, 30, 8, 26, 26, 26, 26, 26, 11, 10, 26, 30, 30, 30, 9, 30, 30, 30, 8, 30, 11, 10, 26, 26, 26, 26, 11, 10, 26, 26, 26, 26, 9, 30, 30},
                                                            /*x13 */ {30, 30, 30, 24, 14, 14, 14, 3, 26, 11, 6, 14, 14, 3, 30, 31, 30, 30, 30, 8, 30, 11, 6, 14, 14, 3, 30, 11, 6, 14, 14, 3, 26, 9, 30, 30},
                                                            /*x14 */ {30, 30, 30, 16, 15, 15, 15, 7, 26, 11, 2, 15, 15, 7, 30, 31, 30, 30, 30, 8, 30, 11, 2, 15, 15, 7, 30, 11, 2, 15, 15, 7, 26, 9, 30, 30},
                                                            /*x15 */ {30, 30, 30, 8, 26, 26, 26, 26, 26, 11, 10, 26, 30, 30, 30, 9, 30, 30, 30, 8, 30, 11, 10, 26, 26, 26, 26, 11, 10, 26, 26, 26, 26, 9, 30, 30},
                                                            /*x16 */ {30, 30, 30, 8, 26, 2, 14, 3, 26, 11, 10, 26, 2, 3, 30, 9, 30, 30, 30, 8, 30, 11, 10, 26, 2, 3, 26, 11, 10, 26, 2, 3, 26, 9, 30, 30},
                                                            /*x17 */ {30, 30, 30, 8, 26, 11, 30, 10, 26, 6, 7, 26, 11, 10, 30, 22, 13, 13, 13, 23, 30, 6, 7, 26, 11, 10, 26, 6, 7, 26, 11, 10, 26, 9, 30, 30},
                                                            /*x18 */ {30, 30, 30, 8, 26, 11, 30, 10, 26, 26, 26, 26, 11, 10, 30, 30, 30, 30, 30, 30, 30, 30, 30, 26, 11, 10, 26, 26, 26, 26, 11, 10, 26, 9, 30, 30},
                                                            /*x19 */ {30, 30, 30, 8, 26, 11, 30, 10, 26, 2, 14, 14, 7, 6, 14, 14, 3, 30, 2, 14, 14, 14, 3, 26, 11, 10, 26, 2, 14, 14, 7, 10, 26, 9, 30, 30},
                                                            /*x20 */ {30, 30, 30, 8, 26, 6, 15, 7, 26, 6, 15, 15, 15, 15, 15, 15, 7, 30, 6, 15, 15, 15, 7, 26, 6, 7, 26, 6, 15, 15, 3, 10, 26, 9, 30, 30},
                                                            /*x21 */ {30, 30, 30, 8, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 11, 10, 26, 9, 30, 30},
                                                            /*x22 */ {30, 30, 30, 8, 26, 2, 14, 3, 26, 2, 3, 26, 2, 12, 12, 12, 3, 30, 2, 12, 12, 12, 3, 26, 2, 14, 14, 14, 3, 26, 11, 10, 26, 9, 30, 30},
                                                            /*x23 */ {30, 30, 30, 8, 26, 11, 30, 10, 26, 11, 10, 26, 9, 30, 30, 30, 8, 30, 9, 30, 30, 30, 8, 26, 11, 2, 15, 15, 7, 26, 11, 10, 26, 9, 30, 30},
                                                            /*x24 */ {30, 30, 30, 8, 26, 11, 30, 10, 26, 11, 10, 26, 9, 30, 30, 30, 8, 30, 9, 30, 30, 30, 8, 26, 11, 10, 26, 26, 26, 26, 11, 10, 26, 9, 30, 30},
                                                            /*x25 */ {30, 30, 30, 8, 26, 6, 15, 7, 26, 6, 7, 26, 9, 30, 30, 30, 8, 30, 9, 30, 30, 30, 8, 26, 6, 7, 26, 2, 3, 26, 6, 7, 26, 9, 30, 30},
                                                            /*x26 */ {30, 30, 30, 8, 26, 26, 27, 26, 26, 26, 26, 26, 9, 30, 30, 30, 8, 30, 9, 30, 30, 30, 8, 26, 26, 26, 27, 11, 10, 26, 26, 26, 26, 9, 30, 30},
                                                            /*x27 */ {30, 30, 30, 4, 12, 12, 12, 12, 12, 12, 12, 12, 5, 30, 30, 30, 8, 30, 9, 30, 30, 30, 4, 12, 12, 12, 12, 25, 20, 12, 12, 12, 12, 5, 30, 30}}
{
    setSceneRect(0, 0, WIDTH, HEIGHT);
    gameLoopTimer = new QTimer();
    pelletLeft = 0;
    createBoard();
    createPlayer();
    createGhosts();
    resetPositions();
    createGUI();
    
    QObject::connect(gameLoopTimer, SIGNAL(timeout()), this, SLOT(updateLevel()));
    gameLoopTimer->start(25);
}

void Level::createPlayer()
{
    player = new PacMan();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    addItem(player);
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
    player->setTilePos(10, 8);

    for (int ghost_index = 0; ghost_index < ghosts.size(); ghost_index++)
    {
        if (ghost_index < 2)
            ghosts[ghost_index]->setTilePos(TILE_COLS / 2 + ghost_index, TILE_ROWS / 2);
        else
            ghosts[ghost_index]->setTilePos(TILE_COLS / 2 + ghost_index - 2, TILE_ROWS / 2);
    }
}

void Level::createBoard()
{
    for (int y_pos = 0; y_pos < TILE_ROWS; y_pos++)
    {
        for (int x_pos = 0; x_pos < TILE_COLS; x_pos++)
        {
            if (board[x_pos][y_pos] == 26)
            {
                pelletLeft++;
                Pellet *p = new Pellet((x_pos * TILE_W) + TILE_W / 2, (y_pos * TILE_H) + TILE_H / 2, 8);
                addItem(p);
            }
            else if (board[x_pos][y_pos] == 27)
            {
                pelletLeft++;
                BoostPellet *p = new BoostPellet((x_pos * TILE_W) + TILE_W / 2, (y_pos * TILE_H) + TILE_H / 2, 16);
                QObject::connect(gameLoopTimer, SIGNAL(timeout()), p, SLOT(flicker()));
                addItem(p);
            }
            else if (board[x_pos][y_pos] == 30)
            {
            }
            else
            {
                MapTile *tile = new MapTile(board[x_pos][y_pos], x_pos, y_pos);
                addItem(tile);
            }
        }
    }
}

void Level::createGUI()
{
    score = new Score();
    score->setPos(WIDTH / 2, score->y());
    addItem(score);

    bottomBar = new BottomBar();
    bottomBar->setPos(WIDTH / 2, HEIGHT - 40);
    addItem(bottomBar);
}

void Level::startFrightenedMode()
{
    for (int ghost_index = 0; ghost_index < ghosts.size(); ghost_index++)
    {
        ghosts[ghost_index]->enterFrightenMode();
    }
}

void Level::gameOver()
{
    gameLoopTimer->stop();
}

void Level::gameWon()
{
    gameLoopTimer->stop();
}

void Level::updateLevel()
{
    player->update();

    for (int ghost_index = 0; ghost_index < ghosts.size(); ghost_index++)
    {
        ghosts[ghost_index]->update();
    }
}