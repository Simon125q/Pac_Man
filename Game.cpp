#include <iostream>
#include <QLCDNumber>
#include <QHBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "Entity.h"

#include "Game.h"
//#include "Level.h"

Game::Game(QWidget *parent)
    :QWidget(parent)
{
    setPalette(QPalette(Qt::blue));
    setAutoFillBackground(true);

    QPushButton *exit = new QPushButton("Exit");
    exit->setFont(QFont("Times", 18, QFont::Bold));

    score = new QLCDNumber(5);
    score->setSegmentStyle(QLCDNumber::Filled);

    //level = new Level;
    QGraphicsScene *scene = new QGraphicsScene();
    Entity *player = new Entity;
    player->setRect(0, 0, 100, 100);
    
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    QGraphicsView *view = new QGraphicsView(scene);

    gameLoopTimer = new QTimer(this);

    connect(exit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(gameLoopTimer, SIGNAL(timeout()), this, SLOT(updateGame()));

    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(score);
    topLayout->addStretch(1);
    topLayout->addWidget(exit);

    QVBoxLayout *gameLayout = new QVBoxLayout;
    gameLayout->addLayout(topLayout);
    gameLayout->addWidget(view);

    setLayout(gameLayout);

    

}

void Game::updateGame()
{
    //level->updateLevel()
    update();
}

// void Game::paintEvent(QPaintEvent *event)
// {
//     QPainter painter(this);
//     level->drawLevel(painter);
// }