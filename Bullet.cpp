#include "Bullet.h"
#include "Game.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QList>

#include "Enemy.h"

// there is an external global object called game
extern Game *game;

Bullet::Bullet()
{
    // draw the rect
    setRect(0, 0, 10, 50);

    // connect to timer
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // start the timer
    timer->start(16);
}

void Bullet::move()
{
    // list of colliding items
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // check if any enemy is in the list
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
            // increase score
            game->score->increase();

            // remove enemy and bullet from scene
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // free memory
            delete colliding_items[i];
            delete this;

            // don't execute further
            return;
        }
    }

    // move bullet up
    setPos(x(), y() - 10);

    // delete bullet after going off-screen
    if (pos().y() + rect().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
