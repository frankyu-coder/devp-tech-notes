
#ifndef THREAD_CREATE_H
#define THREAD_CREATE_H
#include <QThread>
#include <QString>

class ThreadCreate : public QThread
{
    Q_OBJECT

    public:
        ThreadCreate();
        ~ThreadCreate();

        void setMessage(const QString &message);
        void stop();

    protected:
        void run();

    private:
        void init();

    private:
        //QString messageStr;
        //volatile bool stopped;
        class PrivateData;
        PrivateData *m_data;
};

#endif
