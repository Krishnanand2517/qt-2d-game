#include "Game.h"

#include <QTimer>

Game::Game(QWidget *parent)
{
    // Create a scene
    scene = new QGraphicsScene();

    // adjust the scene to match the view
    scene->setSceneRect(0, 0, 800, 600);

    // visualize the newly created scene
    setScene(scene);

    // disable scrollbars
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // set view size
    setFixedSize(800, 600);

    // set BG color to white
    setBackgroundBrush(Qt::white);


    // Create the player
    player = new Player();
    player->setRect(0, 0, 100, 100);

    // move the player to bottom of the scene
    player->setPos(width() / 2, height() - player->rect().height() - 10);

    // make player focusable and focus on it (to receive input events)
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add it into the scene
    scene->addItem(player);


    // Create the score
    score = new Score();
    scene->addItem(score);


    // Spawn enemies every 2 seconds
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    // show the view finally
    show();
}
