
#include "flip_transaction.h"
#include <QString>
#include <QImage>

FlipTransaction::FlipTransaction(Qt::Orientation orientation)
{
    orientation = orientation;
}

QImage FlipTransaction::apply(const QImage &image)
{
    return image.mirrored(orientation == Qt::Horizontal,
            orientation == Qt::Vertical);
}

QString FlipTransaction::message()
{
    if (orientation == Qt::Horizontal) {
        return QObject::tr("Flipping image horizontally...");
    } else {
        return QObject::tr("Flipping image vertically...");
    }

}
