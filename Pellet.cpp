#include <QBrush>

#include "Pellet.h"

Pellet::Pellet(int x, int y)
{
    setBrush(QBrush(Qt::yellow));
    setRect(0, 0, 10, 10);
    setPos(x, y);
    
}