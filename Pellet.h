#pragma once
#include <QObject>
#include <QGraphicsEllipseItem>

class Pellet:public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Pellet(int x, int y);
};