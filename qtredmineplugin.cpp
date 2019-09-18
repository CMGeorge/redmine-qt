#include "qtredmineplugin.h"
#include <QDebug>
#include "RedmineClient.h"
//QtRedminePlugin::QtRedminePlugin(QObject *parent) : QObject(parent)
//{

//}

QtRedminePlugin::QtRedminePlugin()
{

}

void QtRedminePlugin::registerTypes(const char *uri)
{
    qDebug() << "URI IS: " << uri;

    Q_ASSERT(uri == QLatin1String("ro.wesell.qtredmine"));
    qmlRegisterType<QObject>(uri,1,0,"Rest");
    qmlRegisterType<qtredmine::RedmineClient>(uri, 1,0,"RedmineClient");
}
