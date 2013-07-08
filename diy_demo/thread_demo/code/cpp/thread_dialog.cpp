
#include "thread_dialog.h"
#include "thread_create.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QCloseEvent>

class ThreadDialog::PrivateData
{
    public:
        ThreadCreate threadA;
        ThreadCreate threadB;
        QPushButton *threadAButton;
        QPushButton *threadBButton;
        QPushButton *quitButton;
        QVBoxLayout *layout;
};

ThreadDialog::ThreadDialog(QWidget *parent)
    : QDialog(parent)
{
    m_data = new PrivateData;
    init();
}

void ThreadDialog::init()
{
    m_data->threadA.setMessage("A");
    m_data->threadB.setMessage("B");

    m_data->threadAButton = new QPushButton(tr("Start A"));
    m_data->threadBButton = new QPushButton(tr("Start B"));
    m_data->quitButton = new QPushButton(tr("Quit"));
    m_data->quitButton->setDefault(true);

    connect(m_data->threadAButton, SIGNAL(clicked()),
            this, SLOT(startOrStopThreadA()));
    connect(m_data->threadBButton, SIGNAL(clicked()),
            this, SLOT(startOrStopThreadB()));
    connect(m_data->quitButton, SIGNAL(clicked()),
            this, SLOT(close()));

    m_data->layout = new QVBoxLayout;
    m_data->layout->addWidget(m_data->threadAButton);
    m_data->layout->addWidget(m_data->threadBButton);
    m_data->layout->addWidget(m_data->quitButton);
    setLayout(m_data->layout);
}

void ThreadDialog::startOrStopThreadA()
{
    if (m_data->threadA.isRunning()) {
        m_data->threadA.stop();
        m_data->threadAButton->setText(tr("Start A"));

    } else {
        m_data->threadA.start();
        m_data->threadAButton->setText(tr("Stop A"));
    }
}

void ThreadDialog::startOrStopThreadB()
{
    if (m_data->threadB.isRunning()) {
        m_data->threadB.stop();
        m_data->threadBButton->setText(tr("Start B"));

    } else {
        m_data->threadB.start();
        m_data->threadBButton->setText(tr("Stop B"));
    }
}

void ThreadDialog::closeEvent(QCloseEvent *event)
{
    m_data->threadA.stop();
    m_data->threadB.stop();
    m_data->threadA.wait();
    m_data->threadB.wait();
    event->accept();

}
