#pragma once

#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QObject>

class Entity : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    int direction;
    int speed;

    Entity(QGraphicsItem *parent = 0);

public slots:
    void move();
    virtual void update() = 0;
};