
#include "transaction_thread.h"
#include <QQueue>
#include <QWaitCondition>
#include <QMutex>

class TransactionThread::PrivateData
{
    public:
        QImage currentImage;
        QQueue<Transaction *> transactions;
        QWaitCondition transactionAdded;
        QMutex mutex;
};

TransactionThread::TransactionThread()
{
    m_data = new PrivateData;
    init();
}

TransactionThread::~TransactionThread()
{
    delete m_data;
    {
        QMutexLocker locker(&m_data->mutex);
        while(!m_data->transactions.isEmpty())
            delete m_data->transactions.dequeue();
        m_data->transactions.enqueue(EndTransaction);
        m_data->transactionAdded.wakeOne();
    }

    wait();
}

void TransactionThread::init()
{
    start();
}

void TransactionThread::addTransaction(Transaction *transact)
{
    QMutexLocker locker(&m_data->mutex);
    m_data->transactions.enqueue(transact);
    m_data->transactionAdded.wakeOne();
}

void TransactionThread::setImage(const QImage &image)
{
    QMutexLocker locker(&m_data->mutex);
    m_data->currentImage = image;
}

QImage TransactionThread::image()
{
    QMutexLocker locker(&m_data->mutex);
    return m_data->currentImage;
}

void TransactionThread::run()
{
    Transaction *transact = 0;
    QImage oldImage;

    forever {
        {
            QMutexLocker locker(&m_data->mutex);

            if (m_data->transactions.isEmpty())
                m_data->transactionAdded.wait(&m_data->mutex);
            transact = m_data->transactions.dequeue();
            if (transact == EndTransaction)
                break;

            oldImage = m_data->currentImage;
        }

        emit transactionStarted(transact->message());
        QImage newImage = transact->apply(oldImage);
        delete transact;

        {
            QMutexLocker locker(&m_data->mutex);
            m_data->currentImage = newImage;
            if (m_data->transactions.isEmpty())
                emit allTransactionsDone();
        }

    }
}
