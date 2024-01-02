#include <iostream>
#include <QApplication>
#include <QPushButton>

#include "Game.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Game game;
    game.setGeometry(400, 100, 500, 355);
    game.show();
    return app.exec();
}