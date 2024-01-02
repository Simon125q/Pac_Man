#pragma once

#include <QWidget>

class QLCDNumber;
class Level;

class Game : public QWidget
{
    Q_OBJECT
private:
    QLCDNumber *score;
    Level *level;

    QTimer *gameLoopTimer;

public:
    Game(QWidget *parent = 0);

public slots:
    void updateGame();

// protected:
//     void paintEvent(QPaintEvent *event);


};