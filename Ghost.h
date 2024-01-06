#pragma once
#include <QTimer>
#include "Entity.h"

class Ghost : public Entity
{
    Q_OBJECT
    QList<QPixmap> frightenedFrames;
    QTimer *modeTimer;
    
    void getFrightenedFrames();
public:
    int mode;
    
    Ghost();
    void animateFrightened();
    virtual void getFrames() = 0;

public slots:
    void getChaseDirection();
    void getFrightenedDirections();
    void getScatterDirection();
    void enterChaseMode();
    void enterFrightenMode();
    void enterScatterMode();
    void update();
};