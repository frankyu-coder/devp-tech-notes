
#include <QtDebug>
#include "window.h"
#include "cross_common_property_group.h"
#include "cross_property_browser_variant_manager.h"

class Window::PrivateData
{
    public:
        QHash<QString, QtVariantProperty *> propertyTable;
        CrossCommonPropertyGroup crossCommonPropertyGroup;
        QtVariantPropertyManager *manager;
        QtVariantEditorFactory *variantFactory;
        QtTreePropertyBrowser *variantEditor;

};

Window::Window(QWidget *parent) :
    QWidget(parent)
{
    m_data = new PrivateData;
    init();
}

Window::~Window()
{
    delete m_data;
}

void Window::init()
{
    m_data->manager = new CrossPropertyBrowserVariantManager();

    QHash<QString, QtVariantProperty *> &table = m_data->propertyTable;

    QtProperty *baseProperty = m_data->crossCommonPropertyGroup.extrackBaseProperty(m_data->manager, table);

    QtProperty *xAxisProperty = extrackXAxisProperty(m_data->manager, table);

    QtProperty *yAxisProperty = extrackYAxisProperty(m_data->manager, table);

    QtProperty *frequencyProperty = extrackFrequencyProperty(m_data->manager, table);

    QtProperty *histogramProperty = extrackHistogramProperty(m_data->manager, table);

    QtProperty *showAreaProperty = extrackShowAreaProperty(m_data->manager, table);

    QtProperty *legendProperty = extrackLegendProperty(m_data->manager, table);

   // propertyEditor()->addProperty(frequencyProperty);
   // propertyEditor()->addProperty(baseProperty);
   // propertyEditor()->addProperty(xAxisProperty);
   // propertyEditor()->addProperty(yAxisProperty);
   // propertyEditor()->addProperty(histogramProperty);
   // propertyEditor()->addProperty(showAreaProperty);
   // propertyEditor()->addProperty(legendProperty);


    m_data->variantFactory = new QtVariantEditorFactory();
    m_data->variantEditor = new QtTreePropertyBrowser();

    m_data->variantEditor->setFactoryForManager(m_data->manager, m_data->variantFactory);
    m_data->variantEditor->addProperty(frequencyProperty);    
    m_data->variantEditor->addProperty(baseProperty);
    m_data->variantEditor->addProperty(xAxisProperty);
    m_data->variantEditor->addProperty(yAxisProperty);    
    m_data->variantEditor->addProperty(histogramProperty);
    m_data->variantEditor->addProperty(showAreaProperty);
    m_data->variantEditor->addProperty(legendProperty);

    m_data->variantEditor->setPropertiesWithoutValueMarked(true);
    m_data->variantEditor->setRootIsDecorated(false);
    m_data->variantEditor->show();
}

QtProperty *Window::extrackXAxisProperty(QtVariantPropertyManager *manager,
                             QHash<QString, QtVariantProperty *> &propertyTable)
{
    QtProperty          *parameters;
    QtVariantProperty   *item;
    QStringList         enumValues;

    parameters = manager->addProperty(QtVariantPropertyManager::groupTypeId(),
                                      QString(QObject::tr("X轴属性")));

    item = manager->addProperty(QVariant::String, QString(QObject::tr("轴名")));
    item->setValue(QObject::tr("数值轴"));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/name", item);

    item = manager->addProperty(QVariant::String, QString(QObject::tr("单位")));
    item->setValue("");
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/unit", item);

    item = manager->addProperty(QVariant::Font, QString(QObject::tr("轴名字体")));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/name_font", item);

    item = manager->addProperty(QVariant::Color, QString(QObject::tr("轴名颜色")));
    item->setValue(QColor(0, 0, 0, 255));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/name_color", item);

    item = manager->addProperty(QVariant::Int, QString(QObject::tr("轴名大小")));
    item->setValue(5);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/name_size", item);

    item = manager->addProperty(QtVariantPropertyManager::enumTypeId(),
                                    QString(tr("轴名方向")));
    enumValues.clear();
    enumValues << "水平" << "垂直";
    item->setAttribute(QLatin1String("enumNames"), enumValues);
    item->setValue(0);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/name_direction", item);


    item = manager->addProperty(QVariant::String, QString(QObject::tr("轴线线型")));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/line_linear", item);

    item = manager->addProperty(QVariant::Color, QString(QObject::tr("轴线颜色")));
    item->setValue(QColor(0, 0, 0, 255));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/color", item);

    item = manager->addProperty(QVariant::Int, QString(QObject::tr("轴线粗细")));
    item->setValue(1);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/line_width", item);

    item = manager->addProperty(QVariant::String, QString(QObject::tr("轴线输入数据")));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/line_input_data", item);


    item = manager->addProperty(QtVariantPropertyManager::enumTypeId(),
                                    QString(tr("刻度方式")));
    enumValues.clear();
    enumValues << "线性" << "对数" << "指数";
    item->setAttribute(QLatin1String("enumNames"), enumValues);
    item->setValue(0);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/name_calibration_style", item);

    item = manager->addProperty(QVariant::Double, QString(QObject::tr("起始值")));
    item->setValue(0);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/lower", item);

    item = manager->addProperty(QVariant::Font, QString(QObject::tr("起始值字体")));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/lower_font", item);

    item = manager->addProperty(QVariant::Color, QString(QObject::tr("起始值颜色")));
    item->setValue(QColor(0, 0, 0, 255));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/lower_color", item);

    item = manager->addProperty(QVariant::Int, QString(QObject::tr("起始值大小")));
    item->setValue(5);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/lower_size", item);

    item = manager->addProperty(QVariant::Int, QString(QObject::tr("起始值精度")));
    item->setValue(5);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/lower_precision", item);


    item = manager->addProperty(QVariant::Double, QString(QObject::tr("结束值")));
    item->setValue(100);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/upper", item);

    item = manager->addProperty(QVariant::Font, QString(QObject::tr("结束值字体")));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/upper_font", item);

    item = manager->addProperty(QVariant::Color, QString(QObject::tr("结束值颜色")));
    item->setValue(QColor(0, 0, 0, 255));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/upper_color", item);

    item = manager->addProperty(QVariant::Int, QString(QObject::tr("结束值大小")));
    item->setValue(5);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/upper_size", item);

    item = manager->addProperty(QVariant::Int, QString(QObject::tr("结束值精度")));
    item->setValue(5);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/upper_precision", item);


    item = manager->addProperty(QVariant::Double, QString(QObject::tr("等分数")));
    item->setValue(10);
    item->setEnabled(false);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/score", item);


    item = manager->addProperty(QVariant::Bool, QString(QObject::tr("等分线可见")));
    item->setValue(true);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/score_is_visible", item);

    item = manager->addProperty(QVariant::String, QString(QObject::tr("等分线线型")));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/score_linear", item);

    item = manager->addProperty(QVariant::Color, QString(QObject::tr("等分线颜色")));
    item->setValue(QColor(0, 0, 0, 255));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/score_color", item);

    item = manager->addProperty(QVariant::Int, QString(QObject::tr("等分线粗细")));
    item->setValue(1);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/x_axis/score_width", item);

    return parameters;
}

QtProperty *Window::extrackYAxisProperty(QtVariantPropertyManager *manager,
                             QHash<QString, QtVariantProperty *> &propertyTable)
{
    QtProperty          *parameters;
    QtVariantProperty   *item;
    QStringList         enumValues;

    parameters = manager->addProperty(QtVariantPropertyManager::groupTypeId(),
                                      QString(QObject::tr("Y轴属性")));

    item = manager->addProperty(QVariant::String, QString(QObject::tr("轴名")));
    item->setValue(QObject::tr("数值轴"));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/name", item);

    item = manager->addProperty(QVariant::String, QString(QObject::tr("单位")));
    item->setValue("");
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/unit", item);
    
    item = manager->addProperty(QVariant::Font, QString(QObject::tr("轴名字体")));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/name_font", item);

    item = manager->addProperty(QVariant::Color, QString(QObject::tr("轴名颜色")));
    item->setValue(QColor(0, 0, 0, 255));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/name_color", item);

    item = manager->addProperty(QVariant::Int, QString(QObject::tr("轴名大小")));
    item->setValue(5);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/name_size", item);

    item = manager->addProperty(QtVariantPropertyManager::enumTypeId(),
                                    QString(tr("轴名方向")));
    enumValues.clear();
    enumValues << "水平" << "垂直";
    item->setAttribute(QLatin1String("enumNames"), enumValues);
    item->setValue(0);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/name_direction", item);


    item = manager->addProperty(QVariant::String, QString(QObject::tr("轴线线型")));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/line_linear", item);

    item = manager->addProperty(QVariant::Color, QString(QObject::tr("轴线颜色")));
    item->setValue(QColor(0, 0, 0, 255));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/color", item);

    item = manager->addProperty(QVariant::Int, QString(QObject::tr("轴线粗细")));
    item->setValue(1);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/line_width", item);

    item = manager->addProperty(QVariant::String, QString(QObject::tr("轴线输入数据")));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/line_input_data", item);


    item = manager->addProperty(QtVariantPropertyManager::enumTypeId(),
                                    QString(tr("刻度方式")));
    enumValues.clear();
    enumValues << "线性" << "对数" << "指数";
    item->setAttribute(QLatin1String("enumNames"), enumValues);
    item->setValue(0);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/name_calibration_style", item);



    item = manager->addProperty(QVariant::Double, QString(QObject::tr("起始值")));
    item->setValue(0);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/lower", item);

    item = manager->addProperty(QVariant::Font, QString(QObject::tr("起始值字体")));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/lower_font", item);

    item = manager->addProperty(QVariant::Color, QString(QObject::tr("起始值颜色")));
    item->setValue(QColor(0, 0, 0, 255));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/lower_color", item);

    item = manager->addProperty(QVariant::Int, QString(QObject::tr("起始值大小")));
    item->setValue(5);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/lower_size", item);

    item = manager->addProperty(QVariant::Int, QString(QObject::tr("起始值精度")));
    item->setValue(5);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/lower_precision", item);


    item = manager->addProperty(QVariant::Double, QString(QObject::tr("结束值")));
    item->setValue(100);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/upper", item);

    item = manager->addProperty(QVariant::Font, QString(QObject::tr("结束值字体")));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/upper_font", item);

    item = manager->addProperty(QVariant::Color, QString(QObject::tr("结束值颜色")));
    item->setValue(QColor(0, 0, 0, 255));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/upper_color", item);

    item = manager->addProperty(QVariant::Int, QString(QObject::tr("结束值大小")));
    item->setValue(5);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/upper_size", item);

    item = manager->addProperty(QVariant::Int, QString(QObject::tr("结束值精度")));
    item->setValue(5);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/upper_precision", item);


    item = manager->addProperty(QVariant::Double, QString(QObject::tr("等分数")));
    item->setValue(10);
    item->setEnabled(false);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/score", item);

    item = manager->addProperty(QVariant::Bool, QString(QObject::tr("等分线可见")));
    item->setValue(true);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/score_is_visible", item);

    item = manager->addProperty(QVariant::String, QString(QObject::tr("等分线线型")));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/score_linear", item);

    item = manager->addProperty(QVariant::Color, QString(QObject::tr("等分线颜色")));
    item->setValue(QColor(0, 0, 0, 255));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/score_color", item);

    item = manager->addProperty(QVariant::Int, QString(QObject::tr("等分线粗细")));
    item->setValue(1);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/y_axis/score_width", item);




    return parameters;
}

QtProperty *Window::extrackFrequencyProperty(QtVariantPropertyManager *manager,
                                                                  QHash<QString, QtVariantProperty *> &propertyTable)
{
    QtProperty          *parameters;
    QtVariantProperty   *item;

    parameters = manager->addProperty(QtVariantPropertyManager::groupTypeId(),
                                      QString(QObject::tr("频率交会图属性")));

    item = manager->addProperty(CrossPropertyBrowserVariantManager::dataSelector(),
            QString(tr("输入数据")));

    QStringList type;
    type << "Frequency";
    item->setAttribute(QLatin1String("DataSelector"), type);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/frequency/data_input", item);

    return parameters;
}

QtProperty *Window::extrackHistogramProperty(QtVariantPropertyManager *manager,
                                                                  QHash<QString, QtVariantProperty *> &propertyTable)
{
    QtProperty          *parameters;
    QtVariantProperty   *item;

    parameters = manager->addProperty(QtVariantPropertyManager::groupTypeId(),
                                      QString(QObject::tr("直方图")));


    item = manager->addProperty(QVariant::Bool, QString(QObject::tr("可见")));
    item->setValue(true);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/histogram/visible", item);

    item = manager->addProperty(QVariant::Color, QString(QObject::tr("线颜色")));
    item->setValue(QColor(0, 0, 0, 255));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/histogram/line_color", item);

    item = manager->addProperty(QVariant::Color, QString(QObject::tr("填充颜色")));
    item->setValue(QColor(0, 0, 0, 255));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/histogram/fill_color", item);

    item = manager->addProperty(QVariant::Int, QString(QObject::tr("最大高度")));
    item->setValue(100);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/histogram/max", item);


    return parameters;
}

QtProperty *Window::extrackShowAreaProperty(QtVariantPropertyManager *manager,
                                QHash<QString, QtVariantProperty *> &propertyTable)
{
    QtProperty          *parameters;
    QtVariantProperty   *item;
    QStringList         enumValues;

    parameters = manager->addProperty(QtVariantPropertyManager::groupTypeId(),
                                      QString(QObject::tr("显示域")));


    item = manager->addProperty(QVariant::Color, QString(QObject::tr("背景颜色")));
    item->setValue(QColor(0, 0, 0, 255));
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/showArea/background_color", item);

    item = manager->addProperty(QtVariantPropertyManager::enumTypeId(),
                                    QString(tr("频数显示")));
    enumValues.clear();
    enumValues << "方式1" << "方式2";
    item->setAttribute(QLatin1String("enumNames"), enumValues);
    item->setValue(0);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/showArea/frequency_style", item);


    return parameters;
}

QtProperty *Window::extrackLegendProperty(QtVariantPropertyManager *manager,
                                QHash<QString, QtVariantProperty *> &propertyTable)
{
    QtProperty          *parameters;
    QtVariantProperty   *item;

    parameters = manager->addProperty(QtVariantPropertyManager::groupTypeId(),
                                      QString(QObject::tr("频数统计标示")));


    item = manager->addProperty(QVariant::Bool, QString(QObject::tr("可见")));
    item->setValue(true);
    parameters->addSubProperty(item);
    propertyTable.insert("/map_key/legend/visible", item);

    return parameters;
}
