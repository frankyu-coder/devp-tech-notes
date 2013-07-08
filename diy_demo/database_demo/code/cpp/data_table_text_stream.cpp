

#include "data_table_text_stream.h"
#include "data_table_text.h"

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QDebug>
#include <QTextCodec>
#include <QVariant>
#include <vector>
#include <string>

//***data table text***//

// csv
class DataTableTextCsvStream::PrivateData
{
    public:
};

DataTableTextCsvStream::DataTableTextCsvStream()
{
    m_data = new PrivateData;
}

DataTableTextCsvStream::~DataTableTextCsvStream()
{
    delete m_data;
}

// write to file
int DataTableTextCsvStream::write(DataService::IDataTable * iData, const QString &file, int type)
{
    if ( DataService::DataText::Type != type) {
        return -1;
    }
    
    DataService::DataTableText *table = 
        dynamic_cast<DataService::DataTableText *>(iData);

    if (NULL == table) {
        return -1;
    }

    std::vector<DataService::DataText> *v = table->data();
    if (NULL == v) {
        return -1;
    }

    QFile fi(file);
    fi.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream stream(&fi);
    
    QString s = ",";
    std::vector<DataService::DataText>::iterator it;
    for (it = v->begin(); it != v->end(); ++it) {
        DataService::DataText data = *it;

        stream << QString("%1").arg(data.id) << s;
        stream << data.name.c_str() << s;
        stream << data.work.c_str();
        stream << "\n";
    }

    fi.close();
}

// read from file
int DataTableTextCsvStream::read(DataService::IDataTable *iData, const QString &filePath, int type)
{
    if ( DataService::DataText::Type != type) {
        qDebug() << "type is not right";
        return -1;
    }

    DataService::DataTableText *table = 
        dynamic_cast<DataService::DataTableText *>(iData);

    if (table == NULL) {
        qDebug() << "table is null";
        return -1;
    }

    std::vector<DataService::DataText> *v = table->data();
    if (!v) 
        return -1;

    QFile fi(filePath);
    if (!fi.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "error!";
        return -1;
    }

    QTextStream stream(&fi);
    QString content = stream.readAll();
    QStringList rows = content.split("\n");

    int rowCount = rows.count();
    int columnCount;

    if (rowCount > 0) {
        QString row = rows.first();
        QStringList columns = row.split(",");
        columnCount = columns.count(); 
    }

    for (int i = 0; i < rowCount; ++i) {
        DataService::DataText rowText;

        QString row = rows.at(i);
        QStringList columns = row.split(",");

        if (columns.count() != 3)
            continue;

        rowText.id = columns.at(0).toInt();
        rowText.name = columns.at(1).toStdString();
        rowText.work = columns.at(2).toStdString();

        v->push_back(rowText);
    }

    return 0;
}
/*
// xml
class DataTableTextXmlStream::PrivateData
{
    public:
        int column;
        QString content;
        QString s;
};

DataTableTextXmlStream::DataTableTextXmlStream()
{
    m_data = new PrivateData;
    m_data->column  = 6;
    m_data->content = "";
}

DataTableTextXmlStream::~DataTableTextXmlStream()
{
    delete m_data;
}

int DataTableTextXmlStream::write(DataService::IDataTable *iData, const QString &file, int type)
{

    if (DataService::DataText1::Type != type) {
        return -1;
    }

    DataService::DataTableText1 *table = 
        dynamic_cast<DataService::DataTableText1 *>(iData);

    if (NULL == table) {
        return -1;
    }

    std::vector<DataService::DataText1> *v = table->data();
    if (NULL == v) {
        return -1;
    }

    int row = v->size();
    qDebug() << "write:row =" << row;
    
    QFile fi(file);
    if (!fi.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return -1;
    }

    QDomDocument doc("test");
    QDomElement root = doc.createElement("xml_file");
    doc.appendChild(root);

    std::vector<DataService::DataText1>::iterator it;
    it = v->begin();

    QDomElement rowElement = doc.createElement("column");
    for (int i = 0; i < row; ++i) {
        // name 
        for (int j = 0; j < m_data->column; ++j) {
        QString s = "c";
        QString rowKey = s.append(QString("%1").arg(j));
        QString name;
        switch(j) {
        case 0:
            name = "id";
            break;
        case 1:
            name = "wellId";
            break;
        case 2:
            name = "catalogId";
            break;
        case 3:
            name = "stratDepth";
            break;
        case 4:
            name = "endDepth";
            break;
        case 5:
            name = "content";
            break;
        }
        rowElement.setAttribute(rowKey, name);
        }

        // data
        DataService::DataText1 data = *it;
        QDomElement colElement = doc.createElement("row");
        for (int k = 0; k < m_data->column; ++k) {
            QString s = "c";
            QString section = s.append(QString("%1").arg(k));
            int va;
            double val;
            QString value;

            switch(k) {
            case 0:
                va = data.id;
                value = QString("%1").arg(va);
                break;
            case 1:
                va = data.wellId;
                value = QString("%1").arg(va);
                break;
            case 2:
                va = data.catalogId;
                value = QString("%1").arg(va);
                break;
            case 3:
                val = data.startDepth;
                value = QString("%1").arg(val);
                break;
            case 4:
                val = data.endDepth;
                value = QString("%1").arg(val);
                break;
            case 5:
                value = data.content.c_str();
                break;
            }

            colElement.setAttribute(section, value);
        }

        it++;
        rowElement.appendChild(colElement);
    }
    root.appendChild(rowElement);
    m_data->content = doc.toString();

   //QTextStream out(&fi);
   //out << doc.toString();
    
    QString content;
    QTextStream stream(&fi);
    doc.documentElement().save(stream, 4);

    QTextStream textStream(&fi);
    textStream.setCodec(QTextCodec::codecForName("UTF-8"));
    textStream << content;
    
    fi.close();
}

int DataTableTextXmlStream::read(DataService::IDataTable *iData, const QString &filePath, int type)
{
    if ( DataService::DataText1::Type != type) {
        qDebug() << "type is not right";
        return -1;
    }

    DataService::DataTableText1 *table = 
        dynamic_cast<DataService::DataTableText1 *>(iData);

    if (table == NULL) {
        qDebug() << "table is null";
        return -1;
    }

    std::vector<DataService::DataText1> v;
    table = new DataService::DataTableText1(0, 0, v);
    //std::vector<DataService::DataText1> *v = table->data();

    QFile fi(filePath);

    if (!fi.open(QIODevice::ReadOnly)) {
        return -1;
    }

    QString content = fi.readAll();

    QString errorStr;
    int errorLine;
    int errorColumn;
    QDomDocument doc("test");
    if (!doc.setContent(content, false, &errorStr, &errorLine, &errorColumn)) {
        return -1;
    }

    fi.close();

	QDomElement docElement = doc.documentElement();
	if (docElement.tagName() != "xml_file") {
		return -1;
	}

	QDomNodeList lists = docElement.childNodes();
    QDomElement column;
    QDomElement data1;
    QDomElement data2;
    QVariant rowCount;
    QVariant colCount;

    for (int i = 0; i < lists.count(); ++i) {
        QDomNode node = lists.at(i);
        if ("column" == node.nodeName()) {
            column = node.toElement();
            int id = column.attribute("c0").toInt();
            int wellId = column.attribute("c1").toInt();
            int catalogId = column.attribute("c2").toInt();
            double startDepth = column.attribute("c3").toDouble();
            double endDepth = column.attribute("c4").toDouble();
            QString content = column.attribute("c5");

            QDomNodeList l = column.childNodes();
            
            for (int j = 0; j < l.count(); ++j) {
            data1 = l.at(j).toElement();
            DataService::DataText1 rowText;
            int id = data1.attribute("c0").toInt();
            rowText.id = id;
            int wellId = data1.attribute("c1").toInt();
            rowText.wellId = wellId;
            int catalogId = data1.attribute("c2").toInt();
            rowText.startDepth = data1.attribute("c3").toDouble();
            rowText.endDepth = data1.attribute("c4").toDouble();
            rowText.content = data1.attribute("c5").toStdString();
            v.push_back(rowText);
            qDebug() << "reading...";
            }

        }
    }

    qDebug() << "read over";
    return 0;
}
*/
