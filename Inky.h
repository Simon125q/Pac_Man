#pragma once


#include "Ghost.h"

class Inky : public Ghost
{
    Q_OBJECT
public:

    Inky();
    void getFrames();
    void getChaseDirection();
    void getScatterDirection();
};