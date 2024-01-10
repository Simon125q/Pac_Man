#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPalette>
#include <QColor>
#include <QLabel>
#include <QApplication>
#include <stdlib.h>
#include <string.h>
#include <QString>

#include "EndScreen.h"
#include "Game.h"

extern Game *game;

EndScreen::EndScreen(bool isGameWon, QWidget *parent)
    :QWidget(parent)
{
    setPalette(QPalette(QColor(0, 20, 20)));
    setAutoFillBackground(true);
    if (isGameWon)
        gameWon();
    else
        gameLost();

    message->setFont(QFont("Times", 25, QFont::Bold));
    message->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    QLabel *score1 = new QLabel("Your Score:");
    QLabel *score2 = new QLabel(std::to_string(game->getScore()).c_str());

    score1->setFont(QFont("Times", 18, QFont::Bold));
    score2->setFont(QFont("Times", 18, QFont::Bold));
    score1->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    score2->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    exit = new QPushButton("Exit");
    exit->setFont(QFont("Times", 25, QFont::Bold));

    connect(exit, SIGNAL(clicked()), qApp, SLOT(quit()));
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(message);
    layout->addWidget(score1);
    layout->addWidget(score2);
    layout->addWidget(exit);
    setLayout(layout);
}

void EndScreen::gameLost()
{
    message = new QLabel("Game Over");
}

void EndScreen::gameWon()
{
    message = new QLabel("Congratulations!");
}