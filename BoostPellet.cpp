#include <QBrush>

#include "BoostPellet.h"
#include "settings.h"

BoostPellet::BoostPellet(int x, int y, int size)
    : Pellet(x, y, size)
{
    flickerTimer = 0;
}

void BoostPellet::flicker()
{
    if (flickerTimer != 0 && flickerTimer % BOOST_PELLET_FLICKER_DURATION == 0)
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