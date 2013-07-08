
#ifndef DATA_TABLE_TEXT_H
#define DATA_TABLE_TEXT_H

#include "data_table_base.h"

namespace DataService
{
    class DataText
    {
        public:
            enum { Type = 0xff03};

        public:
            DataText(){}
            ~DataText(){}

            int id;
            std::basic_string<char> name;
            std::basic_string<char> work;

            static int count() {return 2;}

            static std::string columnName(int index)
            {
                QString str;
                switch(index) {
                    case 0 :
                        str = "索引";
                        break;

                    case 1 :
                        str = "名字";
                        break;

                    case 2 :
                        str = "工作";
                        break;
                    default :
                        break;
                };

                return str.toStdString();
            }

            std::string value(int index)
            {
                QString str;
                switch(index) {
                    case 0 :
                        str = QString("%1").arg(id);
                        break;

                    case 1 :
                        str = name.c_str();
                        break;
                        
                    case 2 :
                        str = work.c_str();
                        break;
                    default :
                        break;
                };

                return str.toStdString();
            }
    };

    typedef DataTableBase<std::vector<DataText> > DataTableText;
}

#endif
