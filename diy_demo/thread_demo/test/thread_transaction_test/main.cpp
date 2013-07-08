
#include <QApplication>
#include <QDebug>
#include "window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Window *w = new Window;
    //w->resize(300, 300);
    //w->show();

    return app.exec();
}
