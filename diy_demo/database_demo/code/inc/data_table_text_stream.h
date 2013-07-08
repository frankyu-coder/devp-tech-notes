
#ifndef DATA_TABLE_TEXT_STREAM_H 
#define DATA_TABLE_TEXT_STREAM_H

//#include "idata_table.h"

#include "data_table_stream.h"
#include <QString>

class DataTableTextCsvStream : public DataTableStream
{
    public:
        DataTableTextCsvStream();
        ~DataTableTextCsvStream();

    public:
        int read(DataService::IDataTable *, const QString &, int);
        int write(DataService::IDataTable *, const QString &, int);

    private:
        class PrivateData;
        PrivateData *m_data;
};

class DataTableTextXmlStream : public DataTableStream
{
    public:
        DataTableTextXmlStream();
        ~DataTableTextXmlStream();

    public:
        int read(DataService::IDataTable *, const QString &, int);
        int write(DataService::IDataTable *, const QString &, int);

    private:
        class PrivateData;
        PrivateData *m_data;

};

#endif
