
#ifndef DATABASE_ADD_TABLE_H
#define DATABASE_ADD_TABLE_H

#include "idata_table.h"

class QString;
class QSqlDatabase;
class DataBaseAddTable
{
    public:
        DataBaseAddTable();
        ~DataBaseAddTable();

    public:
        void init();

    public:
        void setDatabase(QSqlDatabase&);

    public:
        int addTable(QString& /*tableName*/);
        int removeTable(QString& /*tableName*/);
        int addLineData(QString& /*tableName*/);
        int addTableData(QString& /*tableName*/, DataService::IDataTable * /*dataTable */);
        int removeTableData(QString& /*tableName*/, DataService::IDataTable * /*dataTable */ );
        int removeLineData(QString& /*tableName*/, int /* id */);
        int dataTable(QString& /*tableName*/, int /*id*/, DataService::IDataTable * /*dataTable */); //取数据 

    private:
        class PrivateData;
        PrivateData *m_data;
};

#endif
