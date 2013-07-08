
#include "producer.h"
#include <QString>
#include <QSemaphore>
#include <iostream>
#include <cstdlib>

using namespace std;

namespace semaphore{

    class Producer::PrivateData
    {
        public:
            QString messageStr;
    };

    Producer::Producer()
    {
        m_data = new PrivateData;
        init();
    }

    Producer::~Producer()
    {
        delete m_data;
    }

    void Producer::init()
    {
        m_data->messageStr = "P";
    }

    void Producer::run()
    {
        char buffer[data1.BufferSize];
        QSemaphore freeSpace(data1.BufferSize);
        QSemaphore usedSpace(0);

        for (int i = 0; i < data1.DataSize; ++i) {
            freeSpace.acquire();
            //buffer[i % data1.BufferSize] = "ACGT"[uint(std::rand()) % 4];
            std::cerr << qPrintable(m_data->messageStr);
            usedSpace.release();
        }
    }

    void Producer::setMessage(const QString &message)
    {
        m_data->messageStr = message;
    }

    /****
     * *****
     * ****
     * ******/

    class Consumer::PrivateData
    {
        public:
            QString messageStr;
    };

    Consumer::Consumer()
    {
        m_data = new PrivateData;
        init();
    }

    Consumer::~Consumer()
    {
        delete m_data;
    }

    void Consumer::init()
    {
        m_data->messageStr = "c";
    }

    void Consumer::run()
    {
        char buffer[data1.BufferSize];
        QSemaphore freeSpace(data1.BufferSize);
        QSemaphore usedSpace(0);

        for (int i = 0; i < data1.DataSize; ++i) {
            usedSpace.acquire();
            std::cerr << qPrintable(m_data->messageStr);
            //std::cerr << buffer[i % data1.BufferSize];
            freeSpace.release();
        }
        std::cerr << std::endl;
    }

    void Consumer::setMessage(const QString &message)
    {
        m_data->messageStr = message;
    }

}
