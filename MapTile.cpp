#include "MapTile.h"
#include "settings.h"

MapTile::MapTile(int type, int x_pos, int y_pos, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
{
    if (type == 3)
    {
        setPixmap(QPixmap("resources/sprites/BG/3.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);
    }
    else if (type == 10)
    {
        setPixmap(QPixmap("resources/sprites/BG/10.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 4)
    {
        setPixmap(QPixmap("resources/sprites/BG/4.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 11)
    {
        setPixmap(QPixmap("resources/sprites/BG/11.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 5)
    {
        setPixmap(QPixmap("resources/sprites/BG/5.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 6)
    {
        setPixmap(QPixmap("resources/sprites/BG/6.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 7)
    {
        setPixmap(QPixmap("resources/sprites/BG/7.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 8)
    {
        setPixmap(QPixmap("resources/sprites/BG/8.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 9)
    {
        setPixmap(QPixmap("resources/sprites/BG/9.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
}
