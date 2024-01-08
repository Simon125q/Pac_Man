#include "MapTile.h"
#include "settings.h"

MapTile::MapTile(int type, int x_pos, int y_pos, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
{
    if (type == 0)
    {
        setPixmap(QPixmap("resources/sprites/BG/0.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);
    }
    else if (type == 1)
    {
        setPixmap(QPixmap("resources/sprites/BG/1.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 2)
    {
        setPixmap(QPixmap("resources/sprites/BG/2.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 3)
    {
        setPixmap(QPixmap("resources/sprites/BG/3.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 4)
    {
        setPixmap(QPixmap("resources/sprites/BG/4.png"));
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
    else if (type == 10)
    {
        setPixmap(QPixmap("resources/sprites/BG/10.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 11)
    {
        setPixmap(QPixmap("resources/sprites/BG/11.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 12)
    {
        setPixmap(QPixmap("resources/sprites/BG/12.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 13)
    {
        setPixmap(QPixmap("resources/sprites/BG/13.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 14)
    {
        setPixmap(QPixmap("resources/sprites/BG/14.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 15)
    {
        setPixmap(QPixmap("resources/sprites/BG/15.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 16)
    {
        setPixmap(QPixmap("resources/sprites/BG/16.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 17)
    {
        setPixmap(QPixmap("resources/sprites/BG/17.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 18)
    {
        setPixmap(QPixmap("resources/sprites/BG/18.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 19)
    {
        setPixmap(QPixmap("resources/sprites/BG/19.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 20)
    {
        setPixmap(QPixmap("resources/sprites/BG/20.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 21)
    {
        setPixmap(QPixmap("resources/sprites/BG/21.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 22)
    {
        setPixmap(QPixmap("resources/sprites/BG/22.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 23)
    {
        setPixmap(QPixmap("resources/sprites/BG/23.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 24)
    {
        setPixmap(QPixmap("resources/sprites/BG/24.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 25)
    {
        setPixmap(QPixmap("resources/sprites/BG/25.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 28)
    {
        setPixmap(QPixmap("resources/sprites/BG/28.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 29)
    {
        setPixmap(QPixmap("resources/sprites/BG/29.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 30)
    {
        setPixmap(QPixmap("resources/sprites/BG/30.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
    else if (type == 31)
    {
        setPixmap(QPixmap("resources/sprites/BG/31.png"));
        setPos(x_pos * TILE_W, y_pos * TILE_H);    
    }
}
