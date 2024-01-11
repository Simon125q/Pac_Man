#pragma once

#include <QKeyEvent>
#include <QList>
#include <QPixmap>

#include "Entity.h"

class PacMan : public Entity
{
    Q_OBJECT
    QList<QPixmap> deathFrames;
    void getDeathFrames();
    int nextKey;

public:
    PacMan();
    void keyPressEvent(QKeyEvent *event);
    void checkCollisions();
    void getFrames();
    void handleGhostHit();
    void animateDeath();
    void checkKeysQueue();
public slots:
    void update();
};