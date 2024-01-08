
#include "Clyde.h"


Clyde::Clyde()
    : Ghost()
{
    getFrames();
    setPixmap(QPixmap("resources/sprites/Clyde/RIGHT_2.png"));
    speed = 3;
}

void Clyde::getFrames()
{
    up.append(QPixmap("resources/sprites/Clyde/UP_1.png"));
    up.append(QPixmap("resources/sprites/Clyde/UP_2.png"));
    down.append(QPixmap("resources/sprites/Clyde/DOWN_1.png"));
    down.append(QPixmap("resources/sprites/Clyde/DOWN_2.png"));
    left.append(QPixmap("resources/sprites/Clyde/LEFT_1.png"));
    left.append(QPixmap("resources/sprites/Clyde/LEFT_2.png"));
    right.append(QPixmap("resources/sprites/Clyde/RIGHT_1.png"));
    right.append(QPixmap("resources/sprites/Clyde/RIGHT_2.png"));
}