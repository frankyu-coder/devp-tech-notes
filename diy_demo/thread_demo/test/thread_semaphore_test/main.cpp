
#include <QApplication>
#include <QSemaphore>
#include <QThread>
#include <QtGlobal>
#include <QDebug>
#include <QTime>
#include <cstdio>
//#include "window.h"

const int DataSize = 20;
const int BufferSize = 4;
char buffer[BufferSize];
QSemaphore freeBytes(BufferSize);
QSemaphore usedBytes;

class Producer : public QThread
{
    public:
        void run();
};

void Producer::run()
{
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    for (int i = 0; i < DataSize; ++i) {
        freeBytes.acquire();
        buffer[i % BufferSize] = "ACGT"[(int)qrand() % 4];
        usedBytes.release();
    }
}

class Consumer : public QThread
{
    public:
        void run();
};

void Consumer::run()
{
    for (int i = 0; i < DataSize; ++i) {
        usedBytes.acquire();
        fprintf(stderr, "%c", buffer[i % BufferSize]);
        freeBytes.release();
    }

    fprintf(stderr, "\n");
}

int main(int argc, char *argv[])
{
    //QApplication app(argc, argv);
    //Window *w = new Window;
    //w->resize(300, 300);
    //w->show();
    //return app.exec();
    QApplication app(argc, argv);
    Producer produer;
    Consumer consumer;
    produer.start();
    consumer.start();
    produer.wait();
    consumer.wait();
    return app.exec();
}
