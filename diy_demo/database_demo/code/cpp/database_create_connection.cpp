
//#include <QSqlDatabase>
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>
#include "database_create_connection.h"

namespace database
{
class DataBaseCreateConnection::PrivateData
{
    public:
        QString hostName;
        QString databaseName;
        QString userName;
        QString password;
};

DataBaseCreateConnection::DataBaseCreateConnection()
{
    m_data = new PrivateData;
    init();
}

DataBaseCreateConnection::~DataBaseCreateConnection()
{
    delete m_data;
}

void DataBaseCreateConnection::init()
{
    m_data->hostName = "test";
    m_data->databaseName = "test.db";
    m_data->userName = "yjj";
    m_data->password = "123456";
}

bool DataBaseCreateConnection::connection(QSqlDatabase& db)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(m_data->hostName);
    db.setDatabaseName(m_data->databaseName);
    db.setUserName(m_data->userName);
    db.setPassword(m_data->password);
    if (!db.open()) {
        QMessageBox::critical(0, QObject::tr("Database Error"),
                db.lastError().text());
        return false;
    }
    return true;

}

static bool createConnection(QSqlDatabase &db)
{/*
    //QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("test");
    db.setDatabaseName("test.db");
    db.setUserName("yjj");
    db.setPassword("123456");
    if (!db.open()) {
        QMessageBox::critical(0, QObject::tr("Database Error"),
                db.lastError().text());
        return false;
    }
    return true;
    */
}

static bool createTable(QSqlDatabase& db)
{/* 
    QString add 
        = QString("create table worker6 (id integer primary key, firstName varchar, lastName varchar, work varchar)");
    //    .arg(m_data->tableName);
    QSqlQuery query(db);
    bool ret = query.exec(add);
    query.exec("insert into worker6 values(01, 'Jiajia', 'Yu', 'IT')");
    query.exec("insert into worker6 values(02, 'Wei', 'Wang', 'medicine')");

    if (!ret) {
        qDebug() << "create table unsuccessful or the table has been exist!";
        return false;
    } else {
        qDebug() << "create table successful!";
        return true;
    }
    */
}

}
