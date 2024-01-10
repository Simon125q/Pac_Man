#pragma once
#include <QObject>
#include <QGraphicsEllipseItem>

class Pellet : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT

public:
    int pelletSize;
    Pellet(int x, int y, int size);
};