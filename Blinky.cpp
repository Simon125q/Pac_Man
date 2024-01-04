
#include "Blinky.h"


Blinky::Blinky()
    : Ghost()
{
    setPixmap(QPixmap("resources/sprites/Blinky/RIGHT_2.png"));
    speed = 9;
}