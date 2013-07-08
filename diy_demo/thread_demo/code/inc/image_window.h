
#ifndef IMAGE_WINDOW_H
#define IMAGE_WINDOW_H

#include "transaction.h"
#include <QMainWindow>
#include <QString>

class ImageWindow : public QMainWindow
{
    Q_OBJECT

    public:
        ImageWindow();
        ~ImageWindow();

    public:
        void createActions();
        void createMenus();

    private slots:
        void allTransactionsDone();
        void flipHorizontally();

    private slots:
        void openImage();
        void saveImage();
        void saveAsImage();
        void exit();

    public:
        void addTransaction(Transaction *);
        void setCurrentFile(const QString&);

    private:
        void init();

    private:
        class PrivateData;
        PrivateData *m_data;
};

#endif
