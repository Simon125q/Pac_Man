#pragma once

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>

#include "Level.h"
#include "PacMan.h"
#include "Ghost.h"
#include "Score.h"
#include "BottomBar.h"
#include "BoostPellet.h"

class Game : public QGraphicsView
{
    Q_OBJECT
private:
    Level *level;

public:
    Game(QWidget *parent = 0);

protected:
    void keyPressEvent(QKeyEvent *event);

friend class Ghost;
friend class PacMan;
friend class Level;
friend class Board;
};