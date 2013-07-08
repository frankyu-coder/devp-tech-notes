
#include "window.h"
//#include "bst.h"
#include "bst.cpp"
#include <iostream>
#include <QPushButton>
#include <QVBoxLayout>

using namespace std;
using namespace _Bst;
class Window::PrivateData
{
	public:
		QPushButton *button;
        QPushButton *buttonOutput;
		QVBoxLayout *layout;
        Bst<int>    bst;
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
	m_data->button = new QPushButton(tr("create"));
	connect(m_data->button, SIGNAL(clicked()),
			this, SLOT(create()));
	m_data->buttonOutput = new QPushButton(tr("output"));
	connect(m_data->buttonOutput, SIGNAL(clicked()),
			this, SLOT(output()));

	m_data->layout = new QVBoxLayout;
	m_data->layout->addWidget(m_data->button);
    m_data->layout->addWidget(m_data->buttonOutput);
	setLayout(m_data->layout);
	resize(300, 200);
	setWindowTitle(tr("BST"));
}

void Window::create()
{
    for (int i = 0; i < 10; i++) {
        m_data->bst.insertNode(i);
    }
    
    int temp = 4;
    m_data->bst.deleteNode(temp);

}

void Window::output()
{
    m_data->bst.inOrder(m_data->bst.root);
}

