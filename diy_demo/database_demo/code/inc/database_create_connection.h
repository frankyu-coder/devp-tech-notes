
#ifndef DATABASE_CREATE_CONNECTION_H
#define DATABASE_CREATE_CONNECTION_H

class QSqlDatabase;
namespace database
{
class DataBaseCreateConnection : public QWidget
{
    //Q_OBJECT

    public:
        DataBaseCreateConnection();
        ~DataBaseCreateConnection();

    public:
        bool connection(QSqlDatabase&);
        bool ret();
    private:
        void init();

    private:
        class PrivateData;
        PrivateData *m_data;
};

}
#endif
