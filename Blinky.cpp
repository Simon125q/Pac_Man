
#include "Blinky.h"


Blinky::Blinky()
    : Ghost()
{
    getFrames();
    setPixmap(QPixmap("resources/sprites/Blinky/RIGHT_2.png"));
    speed = 4;
}

void Blinky::getFrames()
{
    up.append(QPixmap("resources/sprites/Blinky/UP_1.png"));
    up.append(QPixmap("resources/sprites/Blinky/UP_2.png"));
    down.append(QPixmap("resources/sprites/Blinky/DOWN_1.png"));
    down.append(QPixmap("resources/sprites/Blinky/DOWN_2.png"));
    left.append(QPixmap("resources/sprites/Blinky/LEFT_1.png"));
    left.append(QPixmap("resources/sprites/Blinky/LEFT_2.png"));
    right.append(QPixmap("resources/sprites/Blinky/RIGHT_1.png"));
    right.append(QPixmap("resources/sprites/Blinky/RIGHT_2.png"));
}