
#include "Inky.h"


Inky::Inky()
    : Ghost()
{
    setPixmap(QPixmap("resources/sprites/Inky/RIGHT_2.png"));
    speed = 6;
}