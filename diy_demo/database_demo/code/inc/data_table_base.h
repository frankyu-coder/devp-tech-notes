#ifndef DATA_TABLE_BASE_H
#define DATA_TABLE_BASE_H

#include <string>
#include <list>
#include <QString>

#include "idata_table.h"

#include <string>
#include <vector>

namespace DataService
{
    /*
     * 对T::value_type 的要求是
     * int value_type::count(); //列数
     * std::string value_type::index(int) // 一列的字符串
     * 由T提供基本的存储结构，该模板只提供另一种访问方式
     * 有T::value_type 提供row的结构和列名称信息
     * */

    template<class T> 
        class DataTableBase : public IDataTable
    {
        public:
            typedef typename T::value_type record_type;
            typedef T vector_type;

        public:
            DataTableBase() :
                m_type(0),
                m_id(0),
                m_v(0) {}
            DataTableBase(unsigned type, int id, vector_type &v) :
                m_type(type),
                m_id(id),
                m_v(&v) {}
            virtual ~DataTableBase() {}

        public:
            void init(unsigned type, int id, vector_type &v)
            {
                m_type = type;
                m_id = id;
                m_v = &v;
            }
        public:
            int type() { return m_type; }
            int id() { return m_id; }
            void setId(int n) { m_id = n; }
            std::string key() { return ""; }
            void setKey(std::string *) { }

        public:
            int rowCount() { return m_v->size(); }
            int columnCount() 
            { 
                return record_type::count();
            }
            std::list<std::string> columnNames()
            {
                std::list<std::string> l;
                int count = record_type::count();
                for (int i = 0; i < count; ++i) {
                    l.push_back(record_type::columnName(i));
                }
                return l;
            }

            void * getValue(int row, int column) { return NULL; }
            std::string getTableValue(int row, int column)
            {
                if (row < 0 || row > m_v->size())
                    return "";

                record_type r = m_v->at(row);  
                return r.value(column);
            }

            vector_type *data() { return m_v; }

        private:
            unsigned m_type;
            int m_id;
            vector_type *m_v;
    };
}

#endif
