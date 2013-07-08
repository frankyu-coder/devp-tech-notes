
#include "window.h"
#include "thread_dialog.h"
#include <QPushButton>
#include <QVBoxLayout>

class Window::PrivateData
{
    public:
        QPushButton *button;
        QVBoxLayout *layout;
};

Window::Window(QWidget *parent) :
    QWidget(parent)
{
    m_data = new PrivateData;
    init();
}

Window::~Window()
{
    delete m_data;
}

void Window::init()
{
    m_data->button = new QPushButton(tr("test"));
    connect(m_data->button, SIGNAL(clicked()),
            this, SLOT(test()));
    m_data->layout = new QVBoxLayout;
    m_data->layout->addWidget(m_data->button);
    setLayout(m_data->layout);
}

void Window::test()
{
    ThreadDialog dlg;
    if (!dlg.exec())
        return;
}
