#pragma once


#include "Entity.h"

class Ghost : public Entity
{
    Q_OBJECT
public:
    Ghost();
public slots:
    void getDirection();
    void update();
};