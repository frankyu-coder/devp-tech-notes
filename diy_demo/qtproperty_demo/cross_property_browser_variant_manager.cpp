
#include "cross_property_browser_variant_manager.h"
#include <QDebug>

class CurveSelectAdd 
{
};

class CurveSelectRemove
{
};

class DataSelector
{
};

class CurveOutput
{
};

Q_DECLARE_METATYPE(CurveSelectAdd)
Q_DECLARE_METATYPE(CurveSelectRemove)
Q_DECLARE_METATYPE(DataSelector)
Q_DECLARE_METATYPE(CurveOutput)

int CrossPropertyBrowserVariantManager::curveSelectAdd()
{
    return qMetaTypeId<CurveSelectAdd>();
}

int CrossPropertyBrowserVariantManager::curveSelectRemove()
{
    return qMetaTypeId<CurveSelectRemove>();
}

int CrossPropertyBrowserVariantManager::dataSelector()
{
    return qMetaTypeId<DataSelector>();
}

int CrossPropertyBrowserVariantManager::curveOutput()
{
    return qMetaTypeId<CurveOutput>();
}

bool CrossPropertyBrowserVariantManager::isPropertyTypeSupported(int propertyType) const
{
    if (propertyType == curveSelectAdd())
        return true;
    if (propertyType == curveSelectRemove())
        return true;
    if (propertyType == dataSelector())
        return true;
    if (propertyType == curveOutput())
        return true;

    return QtVariantPropertyManager::isPropertyTypeSupported(propertyType);
}

int CrossPropertyBrowserVariantManager::valueType(int propertyType) const
{
    if (propertyType == curveSelectAdd())
        return QVariant::String;

    if (propertyType == curveSelectRemove())
        return QVariant::String;

    if (propertyType == dataSelector())
        return QVariant::String;

    if (propertyType == curveOutput())
        return QVariant::String;

    return QtVariantPropertyManager::valueType(propertyType);
}

QVariant CrossPropertyBrowserVariantManager::value(const QtProperty *property) const
{
    if (theValues.contains(property)) {
        return theValues[property].value;
    }
    return QtVariantPropertyManager::value(property);
}

QStringList CrossPropertyBrowserVariantManager::attributes(int propertyType) const
{
    if (propertyType == curveSelectAdd()) {
        QStringList attr;
        attr << QLatin1String("CurveSelectAdd");
        return attr;
    }
    if (propertyType == curveSelectRemove()) {
        QStringList attr;
        attr << QLatin1String("CurveSelectRemove");
        return attr;
    }
    if (propertyType == dataSelector()) {
        QStringList attr;
        attr << QLatin1String("DataSelector");
        return attr;
    }
    if (propertyType == curveOutput()) {
        QStringList attr;
        attr << QLatin1String("CurveOutput");
        return attr;
    }

    return QtVariantPropertyManager::attributes(propertyType);
}

int CrossPropertyBrowserVariantManager::attributeType(int propertyType, const QString &attribute) const
{
    if (propertyType == curveSelectAdd()) {
        if (attribute == QLatin1String("CurveSelectAdd"))
            return QVariant::String;
        return 0;
    }
    if (propertyType == curveSelectRemove()) {
        if (attribute == QLatin1String("CurveSelectRemove"))
            return QVariant::String;
        return 0;
    }
    if (propertyType == dataSelector()) {
        if (attribute == QLatin1String("DataSelector"))
            return QVariant::String;
        return 0;
    }

    if (propertyType == curveOutput()) {
        if (attribute == QLatin1String("CurveOutput"))
            return QVariant::String;
        return 0;
    }


    return QtVariantPropertyManager::attributeType(propertyType, attribute);

}

QVariant CrossPropertyBrowserVariantManager::attributeValue(const QtProperty *property, const QString &attribute) const
{
    if (theValues.contains(property)) {
        if (attribute == QLatin1String("CurveSelectAdd"))
            return theValues[property].list;
    }
    if (theValues.contains(property)) {
        if (attribute == QLatin1String("CurveSelectRemove"))
            return theValues[property].list;
    }
    if (theValues.contains(property)) {
        if (attribute == QLatin1String("DataSelector"))
            return theValues[property].list;
    }


    if (theValues.contains(property)) {
        if (attribute == QLatin1String("CurveOutput"))
            return theValues[property].list;
    }

    return QtVariantPropertyManager::attributeValue(property, attribute);
}

QString CrossPropertyBrowserVariantManager::valueText(const QtProperty *property) const
{
    if (theValues.contains(property))
        return theValues[property].value;
    return QtVariantPropertyManager::valueText(property);
}

void CrossPropertyBrowserVariantManager::setValue(QtProperty *property, const QVariant &val)
{
    if (theValues.contains(property)) {
        if (val.type() != QVariant::String && !val.canConvert(QVariant::String))
            return;

        QString str = qVariantValue<QString>(val);
        Data d = theValues[property];
        /*
        if (d.value == str)
            return;
            */

        d.value = str;
        theValues[property] = d;

        emit propertyChanged(property);
        emit valueChanged(property, str);

        return;
    }
    QtVariantPropertyManager::setValue(property, val);
}

void CrossPropertyBrowserVariantManager::setAttribute(QtProperty *property,
                const QString &attribute, const QVariant &val)
{
    if (theValues.contains(property)) {
        if (attribute == QLatin1String("DataSelector")) {
            if (val.type() != QVariant::StringList && 
                    !val.canConvert(QVariant::StringList))
                return;
            QStringList strList = qVariantValue<QStringList>(val);
            Data d = theValues[property];
            if (d.list== strList)
                return;
            d.list= strList;
            theValues[property] = d;
            emit attributeChanged(property, attribute, strList);
            return;
        }
    }

    QtVariantPropertyManager::setAttribute(property, attribute, val);
}

void CrossPropertyBrowserVariantManager::initializeProperty(QtProperty *property)
{
    if (propertyType(property) == curveSelectAdd())
        theValues[property] = Data();

    if (propertyType(property) == curveSelectRemove())
        theValues[property] = Data();

    if (propertyType(property) == dataSelector())
        theValues[property] = Data();

    if (propertyType(property) == curveOutput())
        theValues[property] = Data();

    QtVariantPropertyManager::initializeProperty(property);
}

void CrossPropertyBrowserVariantManager::uninitializeProperty(QtProperty *property)
{
    theValues.remove(property);
    QtVariantPropertyManager::uninitializeProperty(property);
}

