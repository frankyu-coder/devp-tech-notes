
#include "window.h"
//#include "stack.h"
#include "stack.cpp"
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
	m_data->button = new QPushButton(tr("create nodes"));
	connect(m_data->button, SIGNAL(clicked()),
			this, SLOT(view()));
	m_data->layout = new QVBoxLayout;
	m_data->layout->addWidget(m_data->button);
	setLayout(m_data->layout);
	resize(300, 200);
	setWindowTitle(tr("stack test"));
}

bool Window::view()
{
	bool t = true;
    
    _Stack::Stack<int> s;
    
	for (int i = 0; i < 10; i++) {
		t = s.push(i);
        cout << "#########" << endl;
	}

    int num = s.size();
    cout << "size =" << num << endl;

    for (int j = 0; j < 10; j++) {
        int temp = s.pop();
        cout << temp << endl;
    }
    //cout << s << endl;
     
    return t;
}

