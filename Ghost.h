#pragma once
#include <QString>

#include "Entity.h"

class Ghost : public Entity
{
    Q_OBJECT

public:
    int mode;
    QString ghost_name;

    Ghost();
    virtual void getFrames() = 0;
public slots:
    void getDirection();
    void update();
};