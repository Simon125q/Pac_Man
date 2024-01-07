
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "Game.h"
#include "Board.h"
#include "settings.h"

extern Game *game;

Board::Board() : board_int{
                     {6, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 5},
                     {3, 6, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 5, 6, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 5, 3},
                     {3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3},
                     {3, 3, 1, 6, 11, 11, 5, 1, 6, 11, 11, 11, 5, 1, 3, 3, 1, 6, 11, 11, 11, 5, 1, 6, 11, 11, 5, 1, 3, 3},
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
    board_pix = new QGraphicsPixmapItem *[TILE_COLS];
    for (int row = 0; row < TILE_COLS; row++)
    {
        board_pix[row] = new QGraphicsPixmapItem[TILE_ROWS];
    }

    for (int x_pos = 0; x_pos < TILE_COLS; x_pos++)
    {
        for (int y_pos = 0; y_pos < TILE_ROWS; y_pos++)
        {
            int elem = board_int[x_pos][y_pos];
            if (elem == 3 && x_pos <= TILE_COLS / 2)
            {
                QGraphicsPixmapItem *tile = new QGraphicsPixmapItem();
                // tile->setPixmap(QPixmap("resources/sprites/BG/3.png"));
                // tile->setPos(x_pos * TILE_W, y_pos * TILE_H);
                // game->level->addItem(tile);
                //board_pix[x_pos][y_pos].setPos(x_pos * TILE_W, y_pos * TILE_H);
                //game->level->addItem(&(board_pix[x_pos][y_pos]));
            }
            // else if (elem == 3 && x_pos < TILE_COLS / 2)
            // {
            //     board_pix[x_pos][y_pos].setPixmap(QPixmap("resources/sprites/BG/10.png"));
            //     //board_pix[x_pos][y_pos].setPos(x_pos * TILE_W, y_pos * TILE_H);
            //     //game->level->addItem(&(board_pix[x_pos][y_pos]));
            // }
            // else if (elem == 4 && y_pos >= TILE_ROWS / 2)
            // {
            //     board_pix[x_pos][y_pos].setPixmap(QPixmap("resources/sprites/BG/4.png"));
            //     //board_pix[x_pos][y_pos].setPos(x_pos * TILE_W, y_pos * TILE_H);
            //     //game->level->addItem(&(board_pix[x_pos][y_pos]));
            // }
            // else if (elem == 4 && y_pos < TILE_ROWS / 2)
            // {
            //     board_pix[x_pos][y_pos].setPixmap(QPixmap("resources/sprites/BG/11.png"));
            //     //board_pix[x_pos][y_pos].setPos(x_pos * TILE_W, y_pos * TILE_H);
            //     //game->level->addItem(&(board_pix[x_pos][y_pos]));
            // }
            // else if (elem == 5)
            // {
            //     board_pix[x_pos][y_pos].setPixmap(QPixmap("resources/sprites/BG/5.png"));
            //     //board_pix[x_pos][y_pos].setPos(x_pos * TILE_W, y_pos * TILE_H);
            //     //game->level->addItem(&(board_pix[x_pos][y_pos]));
            // }
            // else if (elem == 6)
            // {
            //     board_pix[x_pos][y_pos].setPixmap(QPixmap("resources/sprites/BG/6.png"));
            //     //board_pix[x_pos][y_pos].setPos(x_pos * TILE_W, y_pos * TILE_H);
            //     //game->level->addItem(&(board_pix[x_pos][y_pos]));
            // }
            // else if (elem == 7)
            // {
            //     board_pix[x_pos][y_pos].setPixmap(QPixmap("resources/sprites/BG/7.png"));
            //     //board_pix[x_pos][y_pos].setPos(x_pos * TILE_W, y_pos * TILE_H);
            //     //game->level->addItem(&(board_pix[x_pos][y_pos]));
            // }
            // else if (elem == 8)
            // {
            //     board_pix[x_pos][y_pos].setPixmap(QPixmap("resources/sprites/BG/8.png"));
            //     //board_pix[x_pos][y_pos].setPos(x_pos * TILE_W, y_pos * TILE_H);
            //     //game->level->addItem(&(board_pix[x_pos][y_pos]));
            // }
            // else if (elem == 9)
            // {
            //     board_pix[x_pos][y_pos].setPixmap(QPixmap("resources/sprites/BG/9.png"));
            //     //board_pix[x_pos][y_pos].setPos(x_pos * TILE_W, y_pos * TILE_H);
            //     //game->level->addItem(&(board_pix[x_pos][y_pos]));
            // }
            // else if (elem == 1)
            // {
                
            // }
        }
    }
}