#pragma once
#include <QGraphicsPixmapItem>
#include "settings.h"

class MapTile : public QGraphicsPixmapItem
{
public:
    MapTile(int type, int x_pos, int y_pos, QGraphicsItem *parent = 0);
};