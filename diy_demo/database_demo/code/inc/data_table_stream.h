
#ifndef DATA_TABLE_STREAM
#define DATA_TABLE_STREAM

#include <QString>

namespace DataService
{
    class IDataTable;
}

class DataTableStream
{
    public:
        virtual int read(DataService::IDataTable *, const QString &filePath,
                int type) = 0;
        virtual int write(DataService::IDataTable *, const QString &file,
                int type) = 0;
};

#endif
