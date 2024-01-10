#pragma once

#include "Ghost.h"

class Blinky : public Ghost
{
    Q_OBJECT
public:
    Blinky();
    void getFrames();
    void getChaseDirection();
    void getScatterDirection();
};