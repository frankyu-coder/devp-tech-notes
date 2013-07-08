
#ifndef PROPERTY_BROWSER_VARIANT_MANAGER_H
#define PROPERTY_BROWSER_VARIANT_MANAGER_H

#include "qtvariantproperty.h"


class CrossPropertyBrowserVariantManager : public QtVariantPropertyManager
{
    Q_OBJECT
public:
    CrossPropertyBrowserVariantManager(QObject *parent = 0)
        : QtVariantPropertyManager(parent)
            { }

    virtual QVariant value(const QtProperty *property) const;
    virtual int valueType(int propertyType) const;
    virtual bool isPropertyTypeSupported(int propertyType) const;

    virtual QStringList attributes(int propertyType) const;
    virtual int attributeType(int propertyType, const QString &attribute) const;
    virtual QVariant attributeValue(const QtProperty *property, const QString &attribute) const;


    static int curveSelectAdd();
    static int curveSelectRemove();
    static int dataSelector();
    static int curveOutput();

public slots:
    virtual void setValue(QtProperty *property, const QVariant &val);
    virtual void setAttribute(QtProperty *property,
                const QString &attribute, const QVariant &value);
protected:
    virtual QString valueText(const QtProperty *property) const;
    virtual void initializeProperty(QtProperty *property);
    virtual void uninitializeProperty(QtProperty *property);
private:
    struct Data {
        QStringList list;
        QString value;
        QString filter;
    };
 
    QMap<const QtProperty *, Data> theValues;
};



#endif
