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

class Game : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene *scene;
    PacMan *player;
    QList<Ghost *> ghosts;

    QTimer *gameLoopTimer;
    Score *score;
    BottomBar *bottomBar;

    void createGhosts();
    void resetPositions();
    void newGame();

public:
    Game(QWidget *parent = 0);

public slots:
    void updateGame();

friend class Ghost;
friend class PacMan;
};