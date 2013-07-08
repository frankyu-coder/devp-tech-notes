
#include <iostream>
#include "window.h"
#include "insert_sort.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "quick_sort.h"
#include "shell_sort.h"
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

#define NUM 8

class Window::PrivateData
{
    public:
        QLineEdit *edit;
        QPushButton *insertButton;
        QPushButton *bubbleButton;
        QPushButton *selectionButton;
        QPushButton *quickButton;
        QPushButton *shellButton;
        InsertSort insertSort;
        BubbleSort bubbleSort;
        SelectionSort selectionSort;
        QuickSort quickSort;
        ShellSort shellSort;

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
//    m_data->insertSort = new InsertSort;
//    m_data->bubbleSort = new BubbleSort;

    m_data->insertButton = new QPushButton(tr("insert sort"));
    connect(m_data->insertButton, SIGNAL(clicked()),
            this, SLOT(insert_sort()));
    m_data->bubbleButton = new QPushButton(tr("bubble_sort"));
    connect(m_data->bubbleButton, SIGNAL(clicked()),
            this, SLOT(bubble_sort()));
    m_data->selectionButton = new QPushButton(tr("selection_sort"));
    connect(m_data->selectionButton, SIGNAL(clicked()),
            this, SLOT(selection_sort()));
    m_data->quickButton = new QPushButton(tr("quick_sort"));
    connect(m_data->quickButton, SIGNAL(clicked()),
            this, SLOT(quick_sort()));
    m_data->shellButton = new QPushButton(tr("shell_sort"));
    connect(m_data->shellButton, SIGNAL(clicked()),
            this, SLOT(shell_sort()));

    m_data->edit = new QLineEdit;

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_data->insertButton);
    layout->addWidget(m_data->bubbleButton);
    layout->addWidget(m_data->selectionButton);
    layout->addWidget(m_data->quickButton);
    layout->addWidget(m_data->shellButton);
    layout->addWidget(m_data->edit);

    setLayout(layout);
}

static QString view(double *ptr, const int size)
{
    QString context;
    for (int i = 0; i < size; ++i) {
        double tmp = ptr[i];
        QString str = QString("%1").arg(tmp);
        context.append(str).append(",");
        std::cout << tmp << ",";
    }

    return context;
}

void Window::insert_sort()
{
    double ptr[] = {3, 21, 6, 8, 88, 0, 9, 45};
    m_data->insertSort.sort(ptr, NUM);
    QString context = view(ptr, NUM);
    m_data->edit->setText(context);
}

void Window::bubble_sort()
{
    double ptr[] = {3, 21, 6, 8, 88, 0, 9, 45};
    m_data->bubbleSort.sort(ptr, NUM);
    QString context = view(ptr, NUM);
    m_data->edit->setText(context);
}

void Window::selection_sort()
{
    double ptr[] = {3, 21, 6, 8, 88, 0, 9, 45};
    m_data->selectionSort.sort(ptr, NUM);
    QString context = view(ptr, NUM);
    m_data->edit->setText(context);

}

void Window::quick_sort()
{
    double ptr[] = {3, 21, 6, 8, 88, 0, 9, 45};
    m_data->quickSort.sort(ptr, NUM);
    QString context = view(ptr, NUM);
    m_data->edit->setText(context);

}

void Window::shell_sort()
{
    double ptr[] = {3, 21, 6, 8, 88, 0, 9, 45};
    m_data->shellSort.sort(ptr, NUM);
    QString context = view(ptr, NUM);
    m_data->edit->setText(context);

}
