#include "Downfile.h"
#include "Downfile_include.h"


#include <QJsonDocument>
#include <QFile>
#include <QFileInfo>

Downfile* Downfile::m_DownfileManager = nullptr;
Downfile::CGarbo Downfile::Garbo;


class FindByurl
{
public:
    FindByurl(const QString &strurl) :m_strurl(strurl){}
    bool operator ()(const QList<DownloadManager*>::value_type &pair)
    {
        return 0 == pair->getUrl().compare(m_strurl);
    }
private:
    QString m_strurl;
};

class FindwaitdataByurl
{
public:
    FindwaitdataByurl(const QString &strurl) :m_strurl(strurl){}
    bool operator ()(const QList<structWaitdata*>::value_type &pair)
    {
        return 0 == pair->url.compare(m_strurl);
    }
private:
    QString m_strurl;
};


Downfile::Downfile(QObject *parent)
    : QObject(parent)
{

}

Downfile::~Downfile()
{

}

Downfile *Downfile::GetInstance()
{
    static QMutex   s_mutex;
    if (m_DownfileManager == NULL)
    {
        QMutexLocker locker(&s_mutex);
        if (m_DownfileManager == NULL)
            m_DownfileManager = new Downfile(nullptr);
    }
    return m_DownfileManager;
}

void Downfile::getDownLoadFile(QString url, QString loadpath, CallBackFunction callback)
{
    static QMutex s_mutexdownloadManager;
    QMutexLocker locker(&s_mutexdownloadManager);
    QList<DownloadManager*>::iterator iter = std::find_if(downloadManager.begin(), downloadManager.end(), FindByurl(url));
    if (iter != downloadManager.end())
    {
        //等待现有线程下载完成
        structWaitdata *tmp = new structWaitdata;;
        tmp->url = url;
        tmp->loadpath = loadpath;
        tmp->callback = callback;
        m_waitdata.push_back(tmp);
        return;
    }

    DownloadManager  *newmanager = new DownloadManager();
    newmanager->SetUrl(url, loadpath, callback);
    connect(newmanager, SIGNAL(signal_downloadend()), this, SLOT(SLOT_downloadend()));
    downloadManager.push_back(newmanager);
}

void Downfile::SLOT_downloadend()
{
    static QMutex s_mutexdownloadManager;
    QMutexLocker locker(&s_mutexdownloadManager);
    DownloadManager * endmanage = dynamic_cast<DownloadManager*>(sender());
    downloadManager.removeOne(endmanage);
    while (true)
    {
        QList<structWaitdata*>::iterator iter = std::find_if(m_waitdata.begin(), m_waitdata.end(), FindwaitdataByurl(endmanage->getUrl()));
        if (iter != m_waitdata.end())
        {
            structWaitdata* tmpCallback = *iter;
            //等待现有线程下载完成
            if (tmpCallback->loadpath == endmanage->getPath())
            {
                if (tmpCallback->callback)
                {
                    tmpCallback->callback(endmanage->getbsuccess(), endmanage->getMsg(), endmanage->getJsonData());
                }
            }
            else
            {
                bool bsuccess = endmanage->getbsuccess();
                if (bsuccess)
                {
                    if (QFile::exists(tmpCallback->loadpath)) {
                        QFile file(tmpCallback->loadpath);
                        file.remove();
                    }
                    QFile::copy(endmanage->getPath(), tmpCallback->loadpath);
                }

                if (tmpCallback->callback)
                {
                    tmpCallback->callback(bsuccess, endmanage->getMsg(), endmanage->getJsonData());
                }
            }

            m_waitdata.removeAll(tmpCallback);
            delete tmpCallback;
        }
        else
        {
            break;
        }
    }

    endmanage->deleteLater();
}


//////////////////////////////////////////////////////////////////////////////////////////////
DownloadManager::DownloadManager()
{
    connect(&manager, SIGNAL(finished(QNetworkReply*)),
            SLOT(downloadFinished(QNetworkReply*)));
}

DownloadManager::~DownloadManager()
{

}

void DownloadManager::requestFinished(const int HttpStatusCode, QString data, QNetworkReply *reply)
{
    bool bRet = false;
    QString strRet;

    QJsonObject jsonObject;
    QJsonParseError jsonError;
    if (200 == HttpStatusCode)
    {
        bRet = true;
        jsonObject = QJsonDocument::fromJson(reply->readAll(), &jsonError).object();
        strRet = "";
    }
    else
    {
        bRet = false;
        strRet = data;
    }

    m_bsuccess = bRet;
    m_strmsg = strRet;
    m_JsonData = jsonObject;

    if (m_callback)
    {
        m_callback(bRet, strRet, jsonObject);
    }
}
#include <algorithm>



void DownloadManager::SetUrl(const QUrl &url, const QString & strpath, CallBackFunction callback)
{
    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);
    m_callback = callback;
#ifndef QT_NO_SSL
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)), SLOT(sslErrors(QList<QSslError>)));
#endif
    m_url = url.toString();
    m_strpath = strpath;
    currentDownloads.append(reply);
}

QString DownloadManager::saveFileName(const QUrl &url)
{
    QString path = url.path();
    
    QString basename;
    if (m_strpath.isEmpty())
    {
        basename = QFileInfo(path).fileName();
    }
    else
    {
        basename = m_strpath;
    }
    
    if (QFile::exists(basename)) {
        QFile file(basename);
        file.remove();
    }

    if (QFile::exists(basename)) {
        // already exists, don't overwrite
        int i = 0;
        basename += '.';
        while (QFile::exists(basename + QString::number(i)))
            ++i;

        basename += QString::number(i);
    }

    return basename;
}

bool DownloadManager::saveToDisk(const QString &filename, QIODevice *data)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        fprintf(stderr, "Could not open %s for writing: %s\n",
                qPrintable(filename),
                qPrintable(file.errorString()));
        return false;
    }

    file.write(data->readAll());
    file.close();

    return true;
}

void DownloadManager::execute()
{
    QUrl url = R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)";
    //SetUrl(url);
}

void DownloadManager::sslErrors(const QList<QSslError> &sslErrors)
{
#ifndef QT_NO_SSL
    QString strerrormsg;
    foreach(const QSslError &error, sslErrors)
        strerrormsg.append(qPrintable(error.errorString()));
    qInfo() << "[DownloadManager::sslErrors]http errror code" << strerrormsg;
    requestFinished(0, strerrormsg, nullptr);
#else
    Q_UNUSED(sslErrors);
#endif
}

void DownloadManager::downloadFinished(QNetworkReply *reply)
{
    int istatuscode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    QUrl url = reply->url();
    if (reply->error()) {
        QString strerror;
        QString strerrormsg = qPrintable(reply->errorString());
        strerror.append("Download of ").append(url.toEncoded().constData()).append(" failed:").append(strerrormsg);
        qInfo() << "[DownloadManager::downloadFinished] "<< strerror;
        qInfo() << "[DownloadManager::downloadFinished]http errror code" << istatuscode;
        requestFinished(istatuscode, strerrormsg, reply);
    }
    else {
        QString filename = saveFileName(url);
        if (saveToDisk(filename, reply))
            printf("Download of %s succeeded (saved to %s)\n",
            url.toEncoded().constData(), qPrintable(filename));
        requestFinished(istatuscode, qPrintable(filename), reply);
    }
    
    currentDownloads.removeAll(reply);
    reply->deleteLater();
    emit signal_downloadend();
}
