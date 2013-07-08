
#ifndef PRODUCER_H
#define PRODUCER_H

#include <QThread>
#include <QSemaphore>

namespace semaphore{

    static struct data{
        int DataSize;
        int BufferSize;

        data() {
            DataSize = 10;
            BufferSize = 4;
        }

    }data1;

    //QSemaphore freeSpace(data1.BufferSize);
    //QSemaphore usedSpace(0);

    class Producer : public QThread
    {
        Q_OBJECT

        public:
            Producer();
            ~Producer();

        public:
            void setMessage(const QString &message);
            void stop();

        protected:
            void run();

        private:
            void init();

        private:
            class PrivateData;
            PrivateData *m_data;
    };

    /**
     * ********
     * ********
     * ******/

    class Consumer: public QThread
    {
        Q_OBJECT

        public:
            Consumer();
            ~Consumer();

        public:
            void setMessage(const QString &message);
            void stop();

        protected:
            void run();

        private:
            void init();

        private:
            class PrivateData;
            PrivateData *m_data;
    };

}

#endif
