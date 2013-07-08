#ifndef CROSS_COMMON_PROPERTY_GROUP_H
#define CROSS_COMMON_PROPERTY_GROUP_H

#include <QHash>
#include <QString>

#include "qtpropertymanager.h"
#include "qtvariantproperty.h"

class CrossCommonPropertyGroup
{
    public:
        CrossCommonPropertyGroup();
        virtual ~CrossCommonPropertyGroup();

    public:
        QtProperty *extrackBaseProperty(QtVariantPropertyManager *manager,
                                     QHash<QString, QtVariantProperty *> &propertyTable);

        QtProperty *extrackViewProperty(QtVariantPropertyManager *manager,
                                     QHash<QString, QtVariantProperty *> &propertyTable);

        QtProperty *extrackValueAxisProperty(QtVariantPropertyManager *manager,
                                     QHash<QString, QtVariantProperty *> &propertyTable);

        QtProperty *extrackCategoryAxisProperty(QtVariantPropertyManager *manager,
                                     QHash<QString, QtVariantProperty *> &propertyTable);

        QtProperty *extrackGridProperty(QtVariantPropertyManager *manager,
                                        QHash<QString, QtVariantProperty *> &propertyTable);

};

#endif

