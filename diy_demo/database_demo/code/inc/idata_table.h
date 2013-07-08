
#ifndef _I_DATA_TABLE_H_H
#define _I_DATA_TABLE_H_H

#include <string>
#include <list>
#include <QString>

namespace DataService
{
    /***
     * 对数据的一般抽象
     * 产品中的主要数据类型：曲线，文本，图像
     * 都可以抽象成不同的table类型。
     * 最简的接口包括：行数，列数，单元的内容
     * 已经能够唯一识别该table的key和id。
     *
     * */
    class IDataTable
    {
        public:
            virtual ~IDataTable() {}

            virtual int type() = 0;

            virtual int id() = 0;
            virtual void setId(int id) = 0;

            virtual std::string key() = 0;
            virtual void setKey(std::string *) = 0;

        public:
            virtual int rowCount() = 0;
            virtual int columnCount() = 0;
            virtual std::list<std::string> columnNames() = 0;

            virtual void * getValue(int row, int column) = 0;
            virtual std::string getTableValue(int row, int column) = 0;
    };
}

#endif
