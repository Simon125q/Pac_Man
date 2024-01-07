#pragma once
#include <QObject>
#include <QGraphicsPixmapItem>

#include "settings.h"

class Board: public QObject
{
    int board_int[TILE_ROWS][TILE_COLS];
    QGraphicsPixmapItem **board_pix;
public:
    Board();
};