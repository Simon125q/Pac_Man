#pragma once

#include "Ghost.h"

class Clyde : public Ghost
{
    Q_OBJECT
public:
    Clyde();
    void getFrames();
    void getChaseDirection();
    void getScatterDirection();
};