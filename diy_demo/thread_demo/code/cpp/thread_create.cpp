
#include "thread_create.h"
#include <QString>
#include <iostream>
#include <QMutex>
using namespace std;

class ThreadCreate::PrivateData
{
    public:
        QString messageStr;
        QMutex mutex;
        volatile bool stopped;
};

ThreadCreate::ThreadCreate()
{
    m_data = new PrivateData;
    init();
}

ThreadCreate::~ThreadCreate()
{
    delete m_data;
}

void ThreadCreate::init()
{
   m_data->stopped = false; 
}
/*
void ThreadCreate::run()
{
    while (!m_data->stopped)
        std::cerr << qPrintable(m_data->messageStr);
    m_data->stopped = false;
    std::cerr << std::endl;
}*/

void ThreadCreate::run()
{
    forever {
        m_data->mutex.lock();
        if (m_data->stopped) {
            m_data->stopped = false;
            m_data->mutex.unlock();
            break;
        }
        m_data->mutex.unlock();
        std::cerr << qPrintable(m_data->messageStr);
    }
    std::cerr << std::endl;
}

void ThreadCreate::stop()
{
    m_data->mutex.lock();
    m_data->stopped = true;
    m_data->mutex.unlock();
}

void ThreadCreate::setMessage(const QString &message)
{
    m_data->messageStr = message;
}
