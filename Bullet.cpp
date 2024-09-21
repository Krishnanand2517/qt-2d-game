#include "Bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>

Bullet::Bullet()
{
    // draw the rect
    setRect(0, 0, 10, 50);

    // connect to timer
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // start the timer
    timer->start(50);
}

void Bullet::move()
{
    // move bullet up
    setPos(x(), y() - 10);

    // delete bullet after going off-screen
    if (pos().y() + rect().height() < 0) {
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted";
    }
}
