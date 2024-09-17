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
    MyRect *rect = new MyRect();
    rect->setRect(0, 0, 100, 100);

    // add it into the scene
    scene->addItem(rect);

    // make rect focusable and focus on it (to receive input events)
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    // create a view and show it
    QGraphicsView *view = new QGraphicsView(scene);
    view->show();

    return a.exec();
}
