
#ifndef FLIP_TRANSACTION_H
#define FLIP_TRANSACTON_H

#include "transaction.h"

class FlipTransaction : public Transaction
{
    public:
        FlipTransaction(Qt::Orientation orientation);

    public:
        QImage apply(const QImage &image);
        QString message();

    private:
        Qt::Orientation orientation;
};

#endif
