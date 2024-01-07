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
#include "settings.h"

class Level : public QGraphicsScene
{
    Q_OBJECT
    int board[TILE_ROWS][TILE_COLS];

public:
    PacMan *player;
    QList<Ghost *> ghosts;
    QTimer *gameLoopTimer;

    Score *score;
    BottomBar *bottomBar;
    Level(QWidget *parent = 0);

    void createGhosts();
    void resetPositions();
    void createBoard();
    void startFrightenedMode();
public slots:
    void updateLevel();
};