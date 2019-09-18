#ifndef QTREDMINEPLUGIN_H
#define QTREDMINEPLUGIN_H

#include <QObject>
#include <QtQml/QQmlExtensionPlugin>
#include <QtQml/qqml.h>
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

#endif // QTREDMINEPLUGIN_H
