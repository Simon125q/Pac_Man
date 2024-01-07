#include <QGraphicsScene>
#include <QApplication>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QBrush>
#include <QImage>

#include "Level.h"
#include "Blinky.h"
#include "Inky.h"
#include "Pinky.h"
#include "Clyde.h"
#include "Entity.h"
#include "Pellet.h"
#include "BoostPellet.h"
#include "Game.h"
#include "settings.h"
#include "Score.h"
#include "BottomBar.h"

Game::Game(QWidget *parent)
    : QGraphicsView(parent)
{

    setBackgroundBrush(QBrush(Qt::black));

    level = new Level();

    setScene(level);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WIDTH + 2, HEIGHT + 2);

    show();
}


void Game::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        QApplication::instance()->quit();
    }

    QGraphicsView::keyPressEvent(event);
}