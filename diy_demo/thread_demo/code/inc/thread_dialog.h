
#ifndef THREAD_DIALOG_H
#define THREAD_DIALOG_H
#include <QDialog>

class ThreadDialog : public QDialog
{
    Q_OBJECT

    public:
        ThreadDialog(QWidget *parent = 0);

    protected:
        void closeEvent(QCloseEvent *event);

    private slots:
        void startOrStopThreadA();
        void startOrStopThreadB();

    private:
        void init();

    private:
        class PrivateData;
        PrivateData *m_data;
};

#endif
