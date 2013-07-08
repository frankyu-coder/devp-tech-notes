
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QImage>
#include <QString>

class Transaction
{
    public:
        virtual ~Transaction() {};
        virtual QImage apply(const QImage &image) = 0;
        virtual QString message() = 0;
};

#endif
