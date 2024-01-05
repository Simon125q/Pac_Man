#pragma once
#include <QObject>

#include "settings.h"

class Board: public QObject
{
    int board_table[TILE_ROWS][TILE_COLS];
public:
    Board();
};