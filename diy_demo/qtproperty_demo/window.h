#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <QWidget>
//#include <QtGri/QApplication>
//#include <QtCore/QDate>
//#include <QtCore/QLocale>
#include "qtpropertymanager.h"
#include "qtvariantproperty.h"
#include "qttreepropertybrowser.h"

class Window : public QWidget
{
    Q_OBJECT

     public:
        Window(QWidget *parent = 0);
        virtual ~Window();

    private:
        QtProperty *extrackFrequencyProperty(QtVariantPropertyManager *manager,
                                             QHash<QString, QtVariantProperty *> &propertyTable);

        QtProperty *extrackXAxisProperty(QtVariantPropertyManager *manager,
                                             QHash<QString, QtVariantProperty *> &propertyTable);

        QtProperty *extrackYAxisProperty(QtVariantPropertyManager *manager,
                                             QHash<QString, QtVariantProperty *> &propertyTable);

        QtProperty *extrackHistogramProperty(QtVariantPropertyManager *manager,
                                             QHash<QString, QtVariantProperty *> &propertyTable);

        QtProperty *extrackShowAreaProperty(QtVariantPropertyManager *manager,
                                        QHash<QString, QtVariantProperty *> &propertyTable);

        QtProperty *extrackLegendProperty(QtVariantPropertyManager *manager,
                                        QHash<QString, QtVariantProperty *> &propertyTable);

     private:
        void init();

     private:
        class PrivateData;
        PrivateData *m_data;

};

#endif

