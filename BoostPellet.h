#pragma once
#include <QObject>
#include "Pellet.h"

class BoostPellet: public Pellet
{
    Q_OBJECT
    int flickerTimer;
    
public:
    BoostPellet(int x, int y, int size);
public slots:
    void flicker();
};