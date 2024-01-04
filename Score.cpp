#include <QFont>
#include "Score.h"

Score::Score(QGraphicsItem *parent)
    : QGraphicsTextItem(parent)
{
    score = 0;

    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 16));
}

void Score::increase(int byNum)
{
    score += byNum;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore()
{
    return score;
}