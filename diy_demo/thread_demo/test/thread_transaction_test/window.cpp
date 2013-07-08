
#include "window.h""
#include "image_window.h"
#include <QPushButton>
#include <QVBoxLayout>

class Window::PrivateData
{
    public:
        ImageWindow *imageWindow;
};

Window::Window(/*QWidget *parent*/) //:
    //QWidget(parent)
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
    m_data->imageWindow = new ImageWindow;
    m_data->imageWindow->resize(600, 600);
    m_data->imageWindow->show();
}

