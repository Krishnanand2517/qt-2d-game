#include "Enemy.h"
#include <QGraphicsScene>
#include <QTimer>
#include <stdlib.h>

Enemy::Enemy()
{
    // set random position
    int random_number = rand() % 700;
    setPos(random_number, 0);

    // draw the rect
    setRect(0, 0, 100, 100);

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
    if ((pos().y() + rect().height() < 0) || (pos().y() > 700)) {
        scene()->removeItem(this);
        delete this;
    }
}
