#pragma once

#include <QKeyEvent>

#include "Entity.h"

class PacMan : public Entity
{
    Q_OBJECT
    
public:
    PacMan();
    void keyPressEvent(QKeyEvent *event);
    void checkCollisions();
    void getFrames();
public slots:
    void update();
};