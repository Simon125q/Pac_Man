#pragma once

#include <QWidget>
#include <QGraphicsRectItem>

class Entity : public QGraphicsRectItem
{
public:
    int direction;

    void move();

protected:
    //void paintEvent(QPaintEvent *event);
    void keyPressedEvent(QKeyEvent *event);
};