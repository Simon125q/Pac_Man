#pragma once
#include <QTimer>
#include "Entity.h"

class Ghost : public Entity
{
    Q_OBJECT
    QList<QPixmap> frightenedFrames;
    QTimer *modeTimer;
    QTimer *directionChangeTimer;
    
    void getFrightenedFrames();
public:
    int mode;
    
    Ghost();
    void animateFrightened();
    virtual void getFrames() = 0;

public slots:
    void getDirection(int targetX, int targetY);
    void getDirectionForX(int targetX, int targetY);
    void getDirectionForY(int targetX, int targetY);
    void getDirectionForBlockedWay();
    virtual void getChaseDirection() = 0;
    void getFrightenedDirections();
    virtual void getScatterDirection() = 0;
    void getEatenDirection();
    void leaveFrightenMode();
    void enterFrightenMode();
    void enterScatterMode();
    void enterEatenMode();
    void update();
};