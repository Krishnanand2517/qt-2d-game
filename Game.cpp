#include "Game.h"

#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>

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


    // Create the score and health
    score = new Score();
    health = new Health();
    health->setPos(health->x(), health->y() + 25);

    scene->addItem(score);
    scene->addItem(health);


    // Spawn enemies every 2 seconds
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    // play bg music
    QMediaPlayer *music = new QMediaPlayer();
    QAudioOutput *audioOutput = new QAudioOutput();
    audioOutput->setVolume(60);
    music->setAudioOutput(audioOutput);

    music->setSource(QUrl("qrc:/sounds/bgsound.mp3"));
    music->setLoops(QMediaPlayer::Infinite);
    music->play();

    // show the view finally
    show();
}
