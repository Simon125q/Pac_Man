#pragma once

#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPixmap>

class Entity : public QObject, public QGraphicsPixmapItem
{
private:
    Q_OBJECT
    
public:
    int direction;
    int speed;
    int animationFrame;
    int timeBetFrame;

    QList<QPixmap> up;
    QList<QPixmap> down;
    QList<QPixmap> right;
    QList<QPixmap> left;
    QList<int> moveableTiles;

    Entity(QGraphicsItem *parent = 0);
    void setTilePos(int x, int y);
    int getTileX(int x);
    int getTileY(int y);
    bool canTurnUp();
    bool canTurnDown();
    bool canTurnRight();
    bool canTurnLeft();
    bool canMoveUp();
    bool canMoveDown();
    bool canMoveRight();
    bool canMoveLeft();
    virtual void getFrames() = 0;
    void animate();

public slots:
    void move();
    virtual void update() = 0;
};