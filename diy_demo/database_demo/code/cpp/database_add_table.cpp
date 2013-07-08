
#include "database_add_table.h"
#include "data_table_text.h"
#include "idata_table.h"
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

class DataBaseAddTable::PrivateData
{
    public:
        QSqlDatabase db;
        bool ret;
};

DataBaseAddTable::DataBaseAddTable()
{
    m_data = new PrivateData;
    init();
}

DataBaseAddTable::~DataBaseAddTable()
{
    delete m_data;
}

void DataBaseAddTable::init()
{
    // init
}

int DataBaseAddTable::addTable(QString& tableName)
{
    QString add = QString("create table '%1'(id integer primary key, name varchar, work varchar)")
        .arg(tableName);
    QSqlQuery query(m_data->db);
    bool ret = query.exec(add); 
    return ret;
}

int DataBaseAddTable::removeTable(QString& tableName)
{
    QString rem = QString("drop table '%1'")
        .arg(tableName);
    QSqlQuery query(m_data->db);
    bool ret = query.exec(rem);
    return ret;
}

int DataBaseAddTable::addLineData(QString& tableName)
{
        QString insertData = QString("insert into '%1' values(1, 'yujiajia', 'It')")
            .arg(tableName);
        QSqlQuery query(m_data->db);
        bool ret = query.exec(insertData);
        return ret;
}

int DataBaseAddTable::removeLineData(QString &tableName, int id)
{
    QString rem = QString("delete from '%1'"
            "where id = '%2'")
        .arg(tableName)
        .arg(id);
    QSqlQuery query(m_data->db);
    bool ret = query.exec(rem);
    query.finish();
    return ret;
}

int DataBaseAddTable::addTableData(QString& tableName, DataService::IDataTable *dataTable)
{
    DataService::DataTableText *table 
        = dynamic_cast<DataService::DataTableText *>(dataTable);
    if (NULL == table) {
        qDebug() << "table(DataTableText*) is null!";
        return false;
    }

    std::vector<DataService::DataText> *v;
    v = table->data();
    if (NULL == v) {
        qDebug() << "v(std::vector) is null!";
        return false;
    }

    m_data->db.transaction();
    QSqlQuery query(m_data->db);
    std::vector<DataService::DataText>::iterator it;
    it = v->begin();
    bool ret;
    for (; it != v->end(); ++it) {
        DataService::DataText data = *it;
        qDebug() << "data.id =" << data.id;
        qDebug() << "data.name =" << data.name.c_str();
        qDebug() << "data.work =" << data.work.c_str();
        QString add = QString("INSERT INTO '%1'"
                "VALUES('%2', '%3', '%4')")
            .arg(tableName)
            .arg(data.id)
            .arg(data.name.c_str())
            .arg(data.work.c_str());
        query.prepare(add);
        ret = query.exec();
        query.finish();
        if (!ret) {
            return false;
        }
    }
    m_data->db.commit();
    return true;
}

void DataBaseAddTable::setDatabase(QSqlDatabase& db)
{
    m_data->db = db;
}

int dataTable(QString& tableName, int id, DataService::IDataTable *dataTable)
{
    return 0;
}
