#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QAudioOutput>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem *parent = 0);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void spawn();
private:
    QMediaPlayer *bulletSound;
    QAudioOutput *bulletSoundOutput;
};

#endif // PLAYER_H
