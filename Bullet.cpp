#include "Bullet.h"
#include <QTimer>

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
    setPos(x(), y() - 10);
}
