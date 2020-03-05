#ifndef QMLRedmineClient_H
#define QMLRedmineClient_H

#include "qtredmine_global.h"

#include "RedmineClient.h"
#include "SimpleRedmineTypes.h"

#include <QObject>
#include <QString>
#include <QTime>
#include <QJSValue>

#include "qqmlvarpropertyhelpers.h"
#include "qqmlobjectlistmodel.h"
namespace qtredmine {

/**
 * @brief Simple Redmine connection class
 *
 * This class handles the connections to a Redmine instance and provides access to
 * the Redmine REST API.
 *
 * It provides a simple API for accessing Redmine.
 *
 * @sa http://www.redmine.org/projects/redmine/wiki/Rest_api
 */
class QTREDMINESHARED_EXPORT QMLRedmineClient : public RedmineClient
{
    Q_OBJECT
    Q_PROPERTY(QString url READ url WRITE setUrl /*NOTIFY urlChanged*/)
    Q_PROPERTY(QString apiKey READ apiKey WRITE setApiKey /*NOTIFY apiKeyChanged*/)
    Q_PROPERTY(bool checkSsl READ checkSsl WRITE setCheckSsl /*NOTIFY checkSslChanged*/)
public:
//    enum NetworkAccessibility {
//        UnknownAccessibility = -1,
//        NotAccessible = 0,
//        Accessible = 1
//    };
//    Q_ENUM(NetworkAccessibility)
    QMLRedmineClient( QObject* parent = nullptr );
    QMLRedmineClient( QString url, QObject* parent = nullptr );
    QMLRedmineClient( QString url, QString apiKey,
                         bool checkSsl   = true,
                         QObject* parent = nullptr );
    QMLRedmineClient( QString url, QString login, QString password,
                         bool checkSsl   = true,
                         QObject* parent = nullptr );

    void init();
    static QTime getTime( const QString& stime );

    void sendIssue( Issue item,
                    SuccessCb callback = nullptr,
                    int id = NULL_ID,
                    QString parameters = "" );

    void sendIssuePriority( Enumeration item,
                            SuccessCb callback = nullptr,
                            int id = NULL_ID,
                            QString parameters = "" );

    void sendIssueStatus( IssueStatus item,
                          SuccessCb callback = nullptr,
                          int id = NULL_ID,
                          QString parameters = "" );

    void sendProject( Project item,
                      SuccessCb callback = nullptr,
                      int id = NULL_ID,
                      QString parameters = "" );

    void sendTimeEntry( TimeEntry item,
                        SuccessCb callback = nullptr,
                        int id = NULL_ID,
                        QString parameters = "" );

    void sendTimeEntryActivity( Enumeration item,
                                SuccessCb callback = nullptr,
                                int id = NULL_ID,
                                QString parameters = "" );

    void sendTracker( Tracker item,
                      SuccessCb callback = nullptr,
                      int id = NULL_ID,
                      QString parameters = "" );

    void sendTracker( Version item,
                      SuccessCb callback = nullptr,
                      int id = NULL_ID,
                      QString parameters = "" );

    void retrieveCustomFields( CustomFieldsCb callback,
                               CustomFieldFilter filter );

    void retrieveIssue( IssueCb callback,
                        int issueId,
                        QString parameters = "" );

    void retrieveIssues( IssuesCb callback,
                         RedmineOptions options = RedmineOptions() );

    void retrieveIssueCategories( IssueCategoriesCb callback,
                                  int projectId,
                                  QString parameters = "" );

    void retrieveIssuePriorities( EnumerationsCb callback,
                                  QString parameters = "" );

    void retrieveIssueStatuses( IssueStatusesCb callback,
                                QString parameters = "" );

    void retrieveMemberships( MembershipsCb callback,
                              int projectId,
                              QString parameters = "" );

    void retrieveProject( ProjectCb callback,
                          int projectId,
                          QString parameters = "" );

    Q_INVOKABLE void retrieveProjects( QString parameters = "" );

    void retrieveTimeEntries( TimeEntriesCb callback,
                              QString parameters = "" );

    void retrieveTimeEntryActivities( EnumerationsCb callback,
                                      QString parameters = "" );

    void retrieveTrackers( TrackersCb callback,
                           QString parameters = "" );

    Q_INVOKABLE void retrieveCurrentUser();

    void retrieveUsers( UsersCb callback,
                        QString parameters = "" );

    void retrieveVersions( VersionsCb callback,
                           int projectId,
                           QString parameters = "" );

    QString url() const
    {
        return RedmineClient::getUrl();
    }

    QString apiKey() const
    {
        return "";
    }

    bool checkSsl() const
    {
        return RedmineClient::checkSsl_;
    }

protected:
    void retrieveEnumerations( QString enumeration,
                               EnumerationsCb callback,
                               QString parameters = "" );



public slots:
    void reconnect();
    void checkConnectionStatus ();

    void setUrl(QString url)
    {
        RedmineClient::setUrl(url);
    }

    void setApiKey(QString apiKey)
    {
        RedmineClient::setAuthenticator(apiKey);
    }

    void setCheckSsl(bool checkSsl)
    {
        RedmineClient::setCheckSsl(checkSsl);
    }

signals:
    void connectionChanged (QNetworkAccessManager::NetworkAccessibility connected);
    void userRetrieveComplete(qtredmine::User currentUser, qtredmine::RedmineError redmineError, QStringList returnData);
    void projectsRetrieveComplete(QQmlObjectListModel<qtredmine::Project >projects, qtredmine::RedmineError redmineError,QStringList returnData);
private:
    /// Maximum number of resources to fetch at once
    int limit_ = 100;

    /// Current connection status to Redmine
    QNetworkAccessManager::NetworkAccessibility connected_ = QNetworkAccessManager::UnknownAccessibility;

    /// Currently checking the connection
    bool checkingConnection_;

    void fillItem( Item& item, QJsonObject* obj, QString value);
    template<typename T>void fillDefaultFields( T& item, QJsonObject* obj);
    QStringList getErrorList( QNetworkReply* reply, QJsonDocument* json );
    void parseIssue( Issue& issue, QJsonObject* obj );
    void parseProject( Project& project, QJsonObject* obj );
    void parseUser( User& user, QJsonObject* obj );
//    QString m_url;
//    QString m_apiKey;
//    bool m_checkSsl;
};

Q_DECLARE_METATYPE(QNetworkAccessManager::NetworkAccessibility)
} // qtredmine
#endif // QMLRedmineClient_H
