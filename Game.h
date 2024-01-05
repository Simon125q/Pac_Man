#pragma once

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>

#include "Board.h"
#include "PacMan.h"
#include "Ghost.h"
#include "Score.h"
#include "BottomBar.h"
#include "BoostPellet.h"

class Game : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene *scene;
    Board *board;
    PacMan *player;
    QList<Ghost *> ghosts;

    QTimer *gameLoopTimer;
    Score *score;
    BottomBar *bottomBar;

    void createGhosts();
    void resetPositions();
    void createPellet();
    void newGame();

public:
    Game(QWidget *parent = 0);

public slots:
    void updateGame();

friend class Ghost;
friend class PacMan;
};