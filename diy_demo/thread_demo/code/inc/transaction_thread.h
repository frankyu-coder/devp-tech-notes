
#ifndef TRANSACTION_THREAD_H
#define TRANSACTION_THREAD_H

#include "transaction.h"
#include <QThread>

class TransactionThread : public QThread
{
    Q_OBJECT

    public:
        TransactionThread();
        ~TransactionThread();

    public:
        void addTransaction(Transaction *);
        void setImage(const QImage &);
        QImage image();

    signals:
        void transactionStarted(const QString &message);
        void allTransactionsDone();

    protected:
        void run();

    private:
        Transaction *EndTransaction;

    private:
        void init();

    private:
        class PrivateData;
        PrivateData *m_data;
};

#endif
