
#include "cross_common_property_group.h"

#include <QObject>

#include <QDebug>

CrossCommonPropertyGroup::CrossCommonPropertyGroup()
{
}

CrossCommonPropertyGroup::~CrossCommonPropertyGroup()
{
}

QtProperty *CrossCommonPropertyGroup::extrackBaseProperty(QtVariantPropertyManager *manager,
                                                          QHash<QString, QtVariantProperty *> &propertyTable)
{
    QtProperty          *parameters;
    QtVariantProperty   *item;

    parameters = manager->addProperty(QtVariantPropertyManager::groupTypeId(),
                                      QString(QObject::tr("基本属性")));


    #ifdef QT_DEBUG
        item = manager->addProperty(QVariant::Int, QString(QObject::tr("id(发布版本无此项)")));
        item->setValue("0");
        item->setEnabled(false);
        parameters->addSubProperty(item);
        propertyTable.insert("/map_key/base/id", item);
    #endif

    item = manager->addProperty(QVariant::String, QString(QObject::tr("图名")));
    item->setValue(QObject::tr("交会图"));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/base/title", item);

    item = manager->addProperty(QVariant::Double, QString(QObject::tr("宽度")));
    item->setValue(400);
    item->setAttribute(QLatin1String("minimum"), 0);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/base/width", item);

    item = manager->addProperty(QVariant::Double, QString(QObject::tr("高度")));
    item->setValue(300);
    item->setAttribute(QLatin1String("minimum"), 0);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/base/height", item);

    item = manager->addProperty(QVariant::Double, QString(QObject::tr("x")));
    item->setValue(0);
    item->setAttribute(QLatin1String("minimum"), 0);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/base/x", item);

    item = manager->addProperty(QVariant::Double, QString(QObject::tr("y")));
    item->setValue(0);
    item->setAttribute(QLatin1String("minimum"), 0);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/base/y", item);

    return parameters;
}

QtProperty *CrossCommonPropertyGroup::extrackViewProperty(QtVariantPropertyManager *manager,
                                                          QHash<QString, QtVariantProperty *> &propertyTable)
{
    QtProperty          *parameters;
    QtVariantProperty   *item;

    parameters = manager->addProperty(QtVariantPropertyManager::groupTypeId(),
                                      QString(QObject::tr("外观属性")));

    item = manager->addProperty(QVariant::Color, QString(QObject::tr("背景颜色")));
    item->setValue(QColor(0, 0, 0, 255));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/view/backgroud_color", item);

    item = manager->addProperty(QVariant::Color, QString(QObject::tr("边框颜色")));
    item->setValue(QColor(0, 0, 0, 255));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/view/border_color", item);

    item = manager->addProperty(QVariant::Double, QString(QObject::tr("边框宽度")));
    item->setValue(1);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/view/border_line_width", item);

    return parameters;
}

QtProperty *CrossCommonPropertyGroup::extrackValueAxisProperty(QtVariantPropertyManager *manager,
                             QHash<QString, QtVariantProperty *> &propertyTable)
{
    QtProperty          *parameters;
    QtVariantProperty   *item;

    parameters = manager->addProperty(QtVariantPropertyManager::groupTypeId(),
                                      QString(QObject::tr("数值轴属性")));

    item = manager->addProperty(QVariant::String, QString(QObject::tr("名称(单位)")));
    item->setValue(QObject::tr("数值轴"));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/value_axis/name", item);

    item = manager->addProperty(QVariant::Color, QString(QObject::tr("颜色")));
    item->setValue(QColor(0, 0, 0, 255));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/value_axis/color", item);

    item = manager->addProperty(QVariant::Double, QString(QObject::tr("起始值")));
    item->setValue(0);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/value_axis/lower", item);

    item = manager->addProperty(QVariant::Double, QString(QObject::tr("结束值")));
    item->setValue(100);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/value_axis/upper", item);

    item = manager->addProperty(QVariant::Double, QString(QObject::tr("主刻度间隔")));
    item->setValue(10);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/value_axis/major_tick_size", item);

    item = manager->addProperty(QVariant::Int, QString(QObject::tr("副刻度数量")));
    item->setValue(5);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/value_axis/minor_tick_count", item);

    item = manager->addProperty(QVariant::Bool, QString(QObject::tr("主刻度可见")));
    item->setValue(true);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/value_axis/major_tick_is_visible", item);

    item = manager->addProperty(QVariant::Bool, QString(QObject::tr("副刻度可见")));
    item->setValue(true);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/value_axis/minor_tick_is_visible", item);

    item = manager->addProperty(QVariant::Bool, QString(QObject::tr("标签可见")));
    item->setValue(true);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/value_axis/label_is_visible", item);

    return parameters;
}

QtProperty *CrossCommonPropertyGroup::extrackCategoryAxisProperty(QtVariantPropertyManager *manager,
                             QHash<QString, QtVariantProperty *> &propertyTable)
{
    QtProperty          *parameters;
    QtVariantProperty   *item;

    parameters = manager->addProperty(QtVariantPropertyManager::groupTypeId(),
                                      QString(QObject::tr("类型轴属性")));

    item = manager->addProperty(QVariant::String, QString(QObject::tr("名称")));
    item->setValue(QObject::tr("类型轴"));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/category_axis/name", item);

    item = manager->addProperty(QVariant::Color, QString(QObject::tr("颜色")));
    item->setValue(QColor(0, 0, 0, 255));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/category_axis/color", item);

    item = manager->addProperty(QVariant::Bool, QString(QObject::tr("标签可见")));
    item->setValue(true);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/category_axis/label_is_visible", item);

    return parameters;
}

QtProperty *CrossCommonPropertyGroup::extrackGridProperty(QtVariantPropertyManager *manager,
                                QHash<QString, QtVariantProperty *> &propertyTable)
{
    QtProperty          *parameters;
    QtVariantProperty   *item;

    parameters = manager->addProperty(QtVariantPropertyManager::groupTypeId(),
                                      QString(QObject::tr("网格属性")));

    item = manager->addProperty(QVariant::Color, QString(QObject::tr("颜色")));
    item->setValue(QColor(0, 0, 0, 255));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/grid/color", item);

    item = manager->addProperty(QVariant::Double, QString(QObject::tr("粗细")));
    item->setValue(1);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/grid/line_width", item);

    return parameters;
}
