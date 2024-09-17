#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene *scene = new QGraphicsScene();

    // create an item
    QGraphicsRectItem *rect = new QGraphicsRectItem();
    rect->setRect(0, 0, 100, 100);

    // add it into the scene
    scene->addItem(rect);

    // create a view and show it
    QGraphicsView *view = new QGraphicsView(scene);
    view->show();

    return a.exec();
}
