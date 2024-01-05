#include <QBrush>

#include "BoostPellet.h"

BoostPellet::BoostPellet(int x, int y)
    :Pellet(x, y)
{
    flickerTimer = 0;
    setRect(0, 0, 20, 20);
}

void BoostPellet::flicker()
{
    if (flickerTimer != 0 && flickerTimer % 10 == 0)
    {
        flickerTimer = 0;
        setBrush(QBrush(Qt::black));
    }
    else
    {
        flickerTimer++;
        setBrush(QBrush(Qt::yellow));
    }
    
}