#pragma once
#include <QWidget>
#include <QPushButton>
#include <QLabel>

class EndScreen: public QWidget
{
public:
    QPushButton *exit;
    QLabel *message;
    EndScreen(bool isGameWon, QWidget *parent = 0);
    void gameLost();
    void gameWon();
};