#include "qtredmineplugin.h"
#include "SimpleRedmineTypes.h"
#include <QDebug>
#include "QMLRedmineClient.h"
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
    qmlRegisterType<qtredmine::QMLRedmineClient>(uri, 1,0,"RedmineClient");
    qmlRegisterType<QNetworkAccessManager>(uri, 1,0, "QNetworkAccessManager");
//    qmlRegisterType<qtredmine::RedmineError>(uri,1,0,"RedmineError");
//    qmlRegisterType<qtredmine::RedmineResource>(uri,1,0,"RedmineResource");
//    qmlRegisterType<qtredmine::User>(uri,1,0,"User");
}
//Q_DECLARE_METATYPE(qtredmine::User)
