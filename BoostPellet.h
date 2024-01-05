#pragma once
#include <QObject>
#include "Pellet.h"

class BoostPellet: public Pellet
{
    Q_OBJECT
    int flickerTimer;
    
public:
    BoostPellet(int x, int y);
public slots:
    void flicker();
};