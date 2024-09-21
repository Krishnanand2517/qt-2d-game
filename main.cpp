#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "MyRect.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene *scene = new QGraphicsScene();

    // create an item
    MyRect *player = new MyRect();
    player->setRect(0, 0, 100, 100);

    // add it into the scene
    scene->addItem(player);

    // make player focusable and focus on it (to receive input events)
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // create a view
    QGraphicsView *view = new QGraphicsView(scene);

    // disable scrollbars
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // show the view finally
    view->show();

    // set view size
    view->setFixedSize(800, 600);

    // adjust the scene to match the view
    scene->setSceneRect(0, 0, 800, 600);

    // move the player to bottom of the scene
    player->setPos(view->width() / 2, view->height() - player->rect().height() - 10);

    return a.exec();
}
