
#include "window.h"
#include "queue.h"
#include <iostream>
#include <QPushButton>
#include <QVBoxLayout>

using namespace std;
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
	m_data->button = new QPushButton(tr("create nodes"));
	connect(m_data->button, SIGNAL(clicked()),
			this, SLOT(createNode()));
	m_data->layout = new QVBoxLayout;
	m_data->layout->addWidget(m_data->button);
	setLayout(m_data->layout);
	resize(300, 200);
	setWindowTitle(tr("queue test"));
}

bool Window::createNode()
{
	bool t = true;
    _Queue::Queue<int> q;
	for (int i = 0; i < 10 && true == t; i++) {
		t = q.insert(i);
        cout << "#########" << endl;
	}

    int temp = q.size();
    cout << "size =" << temp << endl;
    cout << q << endl;
    return t;
}

