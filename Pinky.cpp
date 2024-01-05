
#include "Pinky.h"


Pinky::Pinky()
    : Ghost()
{
    getFrames();
    setPixmap(up[0]);
}

void Pinky::getFrames()
{
    up.append(QPixmap("resources/sprites/Pinky/UP_1.png"));
    up.append(QPixmap("resources/sprites/Pinky/UP_2.png"));
    down.append(QPixmap("resources/sprites/Pinky/DOWN_1.png"));
    down.append(QPixmap("resources/sprites/Pinky/DOWN_2.png"));
    left.append(QPixmap("resources/sprites/Pinky/LEFT_1.png"));
    left.append(QPixmap("resources/sprites/Pinky/LEFT_2.png"));
    right.append(QPixmap("resources/sprites/Pinky/RIGHT_1.png"));
    right.append(QPixmap("resources/sprites/Pinky/RIGHT_2.png"));
}