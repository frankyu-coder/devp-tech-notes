
#include "window.h"
#include "database_create_connection.h"
#include "database_add_table.h"
#include "data_table_text.h"
#include "data_table_text_stream.h"

#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlTableModel>
#include <QTableView>

class Window::PrivateData
{
    public:
        QLineEdit *lineEdit;
        QVBoxLayout *layout;
        QPushButton *button;
        QPushButton *buttonAdd;
        QPushButton *buttonRem;
        QPushButton *buttonAddTable;
        QPushButton *buttonRemLine;
        QPushButton *buttonInit;
        QPushButton *buttonView;
        QSqlDatabase database;
        QString tableName;
        QString fileName;
        int id;
        bool ret;
        database::DataBaseCreateConnection *connection;
        DataBaseAddTable *addTable;
        DataService::DataTableText *textTable;
        DataTableTextCsvStream *stream;
        QSqlTableModel *model;
        QTableView *view;
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
    m_data->tableName = "data_table1";
    m_data->fileName  = "./data.text";
    m_data->id = 10;
    m_data->ret = false;

    m_data->buttonView = new QPushButton(tr("view"), this);
    connect(m_data->buttonView, SIGNAL(clicked()),
            this, SLOT(view()));
    m_data->buttonInit = new QPushButton(tr("init db"), this);
    connect(m_data->buttonInit, SIGNAL(clicked()),
            this, SLOT(res()));
    m_data->buttonAdd = new QPushButton(tr("add table"), this);
    connect(m_data->buttonAdd, SIGNAL(clicked()),
            this, SLOT(addTable()));

    m_data->buttonRem = new QPushButton(tr("remove table"), this);
    connect(m_data->buttonRem, SIGNAL(clicked()),
            this, SLOT(removeTable()));

    m_data->button      = new QPushButton(tr("add line data"), this);
    connect(m_data->button, SIGNAL(clicked()),
            this, SLOT(addLineData()));
    m_data->buttonAddTable = new QPushButton(tr("add table data"), this);
    connect(m_data->buttonAddTable, SIGNAL(clicked()),
            this, SLOT(addTableData()));
    m_data->buttonRemLine = new QPushButton(tr("rem line data"), this);
    connect(m_data->buttonRemLine, SIGNAL(clicked()),
            this, SLOT(removeLineData()));

    m_data->connection  = new database::DataBaseCreateConnection;
    m_data->addTable    = new DataBaseAddTable;
    m_data->stream      = new DataTableTextCsvStream;
    std::vector<DataService::DataText> *v 
        = new std::vector<DataService::DataText>;
    m_data->textTable   = new DataService::DataTableText(0, 0, *v);


    m_data->view = new QTableView;

    m_data->lineEdit    = new QLineEdit;
    m_data->layout      = new QVBoxLayout;
    m_data->layout->addWidget(m_data->buttonView);
    m_data->layout->addWidget(m_data->buttonInit);
    m_data->layout->addWidget(m_data->lineEdit);
    m_data->layout->addWidget(m_data->buttonAdd);
    m_data->layout->addWidget(m_data->button);
    m_data->layout->addWidget(m_data->buttonAddTable);
    m_data->layout->addWidget(m_data->buttonRemLine);
    m_data->layout->addWidget(m_data->buttonRem);
    m_data->layout->addWidget(m_data->view);
    setLayout(m_data->layout);

}

int Window::res()
{
    m_data->lineEdit->clear();
    bool ret = m_data->connection->connection(m_data->database);
    
    if (!ret) {
        m_data->lineEdit->insert("init unsuccessfully!");
    } else {
        m_data->lineEdit->insert("init successfully!");
        m_data->addTable->setDatabase(m_data->database);
        m_data->ret = ret;
        //ret = m_data->addTable->addLineData(m_data->tableName);
    }

    return ret;
}

int Window::addLineData()
{
    m_data->lineEdit->clear();
    if (!m_data->ret) {
        m_data->lineEdit->insert("error! database is not be initializated!");
        return -1;
    }

    bool ret = m_data->addTable->addLineData(m_data->tableName);
    if (!ret) {
        m_data->lineEdit->insert("add line data unsuccessfully!");
    } else {
        m_data->lineEdit->insert("add line data successfully!");
    }

    return ret;
}

int Window::addTableData()
{
    m_data->lineEdit->clear();
    if (!m_data->ret) {
        m_data->lineEdit->insert("error! database is not be initializated!");
        return 1;
    }

    int type = 0xff03;
    m_data->stream->read(m_data->textTable,
            m_data->fileName,
            type);
    std::vector<DataService::DataText> *v = m_data->textTable->data();
    if (NULL == v) {
        qDebug() << "v(window.cpp:106) is null!";
        return 1;
    }

    //DataService::DataTableText *table = new DataService::DataTableText(0, 0, *v);
    bool r = m_data->addTable->addTableData(m_data->tableName, m_data->textTable);
    if (!r) {
        m_data->lineEdit->insert("add table data unsuccessfully!");
    } else {
        m_data->lineEdit->insert("add table data successfully!");
    }

    return r;
}

int Window::removeLineData()
{
    m_data->lineEdit->clear();
    if (!m_data->ret) {
        m_data->lineEdit->insert("error! database is not be initializated!");       
        return -1;
    }

    bool ret = m_data->addTable->removeLineData(m_data->tableName, m_data->id);
    if (!ret) {
        m_data->lineEdit->insert("rem line data unsuccessfully!");
    } else {
        m_data->lineEdit->insert("rem line data successfully!");
    }

    return ret;
}

int Window::addTable()
{
    m_data->lineEdit->clear();
    if (!m_data->ret) {
        m_data->lineEdit->insert("error! database is not be initializated!");
        return -1;
    }

    bool ret = m_data->addTable->addTable(m_data->tableName);
    if (!ret) {
        m_data->lineEdit->insert("add table unsuccessfully!");
    } else {
        m_data->lineEdit->insert("add table successfully!");
    }

    return ret;
}

int Window::removeTable()
{
    m_data->lineEdit->clear();
    if (!m_data->ret) {
        m_data->lineEdit->insert("error! database is not be initializated!");
        return -1;
    }

    bool ret = m_data->addTable->removeTable(m_data->tableName);
    if (!ret) {
        m_data->lineEdit->insert("remove table unsuccessfully!");
    } else {
        m_data->lineEdit->insert("remove table successfully!");
    }

    return ret;
}

int Window::view()
{
    m_data->lineEdit->clear();
    if (!m_data->ret) {
        m_data->lineEdit->insert("error! database is not be initializated!");
        return -1;
    }

    m_data->model = new QSqlTableModel(this, m_data->database);
    m_data->model->setTable(m_data->tableName);
    m_data->model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_data->model->select();
    //m_data->model->removeColumn(0);
    m_data->model->setHeaderData(0, Qt::Horizontal, tr("id"));
    m_data->model->setHeaderData(1, Qt::Horizontal, tr("name"));
    m_data->model->setHeaderData(2, Qt::Horizontal, tr("work"));

    m_data->view->setModel(m_data->model);
    m_data->view->resizeColumnsToContents();
    m_data->view->show();

    return 0;
}
