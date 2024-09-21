#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>

#include "Player.h"
#include "Score.h"

class Game: public QGraphicsView
{
public:
    Game(QWidget *parent=0);

    QGraphicsScene *scene;
    Player *player;
    Score *score;
};

#endif // GAME_H
