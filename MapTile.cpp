#include <stdlib.h>
#include <string.h>
#include "MapTile.h"
#include "settings.h"

MapTile::MapTile(int type, int x_pos, int y_pos, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
{
    std::string path = "resources/sprites/BG/";
    path.append(std::to_string(type).c_str());
    path.append(".png");
    setPixmap(QPixmap(path.c_str()));
    setPos(x_pos * TILE_W, y_pos * TILE_H);
}
