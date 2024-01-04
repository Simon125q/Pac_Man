#pragma once

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem
{
    int score;

public:
    Score(QGraphicsItem *parent = 0);
    void increase(int byNum);
    int getScore();
};