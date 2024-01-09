#include <QBrush>

#include "Pellet.h"

Pellet::Pellet(int x, int y, int size)
{
    pelletSize = size;
    setBrush(QBrush(Qt::yellow));
    setRect(0, 0, pelletSize, pelletSize);
    setPos(x - (pelletSize / 2), y - (pelletSize / 2));
}