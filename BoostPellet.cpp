#include <QBrush>

#include "BoostPellet.h"

BoostPellet::BoostPellet(int x, int y, int size)
    :Pellet(x, y, size)
{
    flickerTimer = 0;
    //setRect(0, 0, pelletSize, pelletSize);
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