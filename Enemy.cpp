#include "Enemy.h"
#include "Game.h"
#include <QGraphicsScene>
#include <QTimer>
#include <stdlib.h>

// there is an external global object called game
extern Game *game;

Enemy::Enemy()
{
    // set random position
    int random_number = rand() % 700;
    setPos(random_number, 0);

    // draw the graphics
    setPixmap(QPixmap(":/images/enemy.png"));
    setRotation(180);
    setScale(0.5);

    // connect to timer
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // start the timer
    timer->start(50);
}

void Enemy::move()
{
    // move enemy down
    setPos(x(), y() + 5);

    // delete enemy after going off-screen
    if (pos().y() > 600) {
        // decrease health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
