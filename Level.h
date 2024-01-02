#pragma once

#include <QWidget>

class Level : public QWidget
{
    Q_OBJECT
private:

public:
    Level(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);

    
};