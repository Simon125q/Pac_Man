#include <QBrush>

#include "Pellet.h"

Pellet::Pellet(int x, int y)
{
    setBrush(QBrush(Qt::yellow));
    setRect(0, 0, 8, 8);
    setPos(x, y);
    
}