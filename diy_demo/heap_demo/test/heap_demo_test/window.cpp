
#include "window.h"
#include "heap.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <vector>

class Window::PrivateData
{
    public:
        QPushButton *button;
        QVBoxLayout *layout;
        vector<int> array;
        //Heap<int> heap(array);
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
    m_data->button = new QPushButton(tr("heapSort"));
    connect(m_data->button, SIGNAL(clicked()),
            this, SLOT(sort()));

    m_data->layout = new QVBoxLayout;
    m_data->layout->addWidget(m_data->button);
    setLayout(m_data->layout);
    resize(300, 200);
    setWindowTitle(tr("heap sort"));
}

void Window::sort()
{
    for (int i = 10; i < 20; i++) {
        m_data->array.push_back(i);
    }
    random_shuffle(m_data->array.begin(), m_data->array.end());
    Heap<int> heap(m_data->array);
    heap.sort(less<int>()); // 最小堆
    heap.sort(greater<int>()); // 最大堆
}
