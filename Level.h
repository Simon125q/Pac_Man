#pragma once


#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>

#include "PacMan.h"
#include "Ghost.h"
#include "Score.h"
#include "BottomBar.h"
#include "BoostPellet.h"

class Level : public QGraphicsScene
{
    Q_OBJECT

public:
    PacMan *player;
    QList<Ghost *> ghosts;
    QTimer *gameLoopTimer;

    Score *score;
    BottomBar *bottomBar;
    Level(QWidget *parent = 0);
    
    void createGhosts();
    void resetPositions();
    void createPellet();
    void startFrightenedMode();
public slots:
    void updateLevel();    
};