#ifndef QTREDMINEPLUGIN_H
#define QTREDMINEPLUGIN_H

#include <QObject>
#include <QtQml/QQmlExtensionPlugin>
#include <QtQml/qqml.h>
#include <QGuiApplication>

class QtRedminePlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)
public:
    explicit QtRedminePlugin();
    void registerTypes(const char *uri) override;

signals:

public slots:
};

static void registerQtRedmine(){
    QtRedminePlugin *_qRedmine = new QtRedminePlugin();
    _qRedmine->registerTypes("ro.wesell.qtredmine");
}
Q_COREAPP_STARTUP_FUNCTION(registerQtRedmine)

#endif // QTREDMINEPLUGIN_H
