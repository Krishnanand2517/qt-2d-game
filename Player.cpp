#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>

#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsRectItem(parent)
{

}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        if (pos().x() > 0) {
            setPos(x() - 10, y());
        }
    }
    else if (event->key() == Qt::Key_Right) {
        if (pos().x() + 100 < 800) {
            setPos(x() + 10, y());
        }
    }
    else if (event->key() == Qt::Key_Space) {
        // create a bullet
        Bullet *bullet = new Bullet();
        bullet->setPos(x(), y());

        // add the bullet to the scene
        scene()->addItem(bullet);
    }
}

void Player::spawn() {
    // create an enemy and put it into the scene
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
