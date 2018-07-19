#ifndef DOWNFILE_H
#define DOWNFILE_H


#include "Downfile_include.h"

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QList>

#include "Downfile_include.h"

class DownloadManager;
class Downfile : public QObject
{
    Q_OBJECT
    static Downfile *m_DownfileManager;
    class CGarbo // 它的唯一工作就是在析构函数中删除CSingleton的实例 
    {
    public:
        ~CGarbo()
        {
            if (Downfile::m_DownfileManager)
                delete Downfile::m_DownfileManager;
        }
    };
    static CGarbo Garbo;
public:
    Downfile(QObject *parent = nullptr);
    ~Downfile();
    static Downfile *GetInstance();

    void setBDownexisted(bool bDown);

    //不需要header的 下载
    void getDownLoadFile(QString url, QString loadpath, CallBackFunction callback = nullptr);
    //不需要header的 下载
    
private slots:
    void SLOT_downloadend();
private:
    bool m_bDown;
    QList<DownloadManager*> downloadManager;
    QList<structWaitdata*> m_waitdata;
};

//////////////////////////////////////////////////////////////////////////////////////////////
class DownloadManager : public QObject
{
    Q_OBJECT
private:
    QNetworkAccessManager manager;
    QList<QNetworkReply *> currentDownloads;
    virtual void requestFinished(const int HttpStatusCode, QString data, QNetworkReply *reply);
public:
    DownloadManager();
    ~DownloadManager();
    void SetUrl(const QUrl &url, const QString & strpath, CallBackFunction callback = nullptr);
    QString getPath() {return m_strpath;};
    QString getUrl() {return m_url;};
    QString getMsg()
    {
        return m_strmsg;
    };
    QJsonObject getJsonData()
    {
        return m_JsonData;
    }

    bool getbsuccess() {
        return m_bsuccess;
    };
    
private:
    bool saveToDisk(const QString &filename, QIODevice *data);
    QString saveFileName(const QUrl &url);
    QString m_url;
    QString m_strpath;
    bool m_bsuccess;
    QString m_strmsg;
    QJsonObject m_JsonData;
    public slots:
    void execute();
    void downloadFinished(QNetworkReply *reply);
    void sslErrors(const QList<QSslError> &errors);

private:
    CallBackFunction m_callback;
signals:
    void signal_downloadend();
};

#endif // DOWNFILE_H
