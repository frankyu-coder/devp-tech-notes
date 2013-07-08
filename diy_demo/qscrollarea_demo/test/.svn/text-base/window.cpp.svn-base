#include "window.h"

#include <QLabel>
#include <QImage>
#include <QScrollArea>
#include <QPushButton>
#include <QDebug>
#include <QVBoxLayout>
#include <QScrollBar>

class Window::PrivateData
{
	public:
		QLabel *label;
		QScrollArea *scroll;
		QVBoxLayout *v;
};

Window::Window(QWidget *parent)
	: QWidget(parent)
{
	init();
}

Window::~Window()
{
	delete m_data;
}

void Window::init()
{
	m_data = new PrivateData;

	QImage image("cute.png");

	m_data->label = new QLabel();
	m_data->label->setPixmap(QPixmap::fromImage(image));

	m_data->scroll = new QScrollArea();
	m_data->scroll->setBackgroundRole(QPalette::Dark);
	m_data->scroll->setWidget(m_data->label);
    //m_data->scroll->verticalScrollBar()->setRange(0,100000);
    //m_data->scroll->horizontalScrollBar()->setRange(0, 100000);
    //qDebug() << "scroll bar pos = " <<
    //            m_data->scroll->horizontalScrollBar()->pos();
    connect(m_data->scroll->verticalScrollBar(),
            SIGNAL(valueChanged(int)),
            this,
            SLOT(test()));

	m_data->v = new QVBoxLayout;
	m_data->v->addWidget(m_data->scroll);

	setLayout(m_data->v);
	resize(600, 400);

	setWindowTitle(tr("test"));
}

void Window::test()
{
    qDebug() << "test = " <<
                m_data->scroll->verticalScrollBar()->pos();
}
