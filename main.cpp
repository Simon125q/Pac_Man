#include <iostream>
#include <QApplication>

#include "Game.h"

using namespace std;

Game *game;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    game = new Game();
    game->show();

    return app.exec();
}