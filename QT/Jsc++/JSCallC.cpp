#include "JSCallC.h"
#include <QWebEngineView>
#include <QPushButton>
#include <QWebEngineProfile>
#include <QFile>
#include <QWebEngineScriptCollection>

void connet::receiveText(const QString &rettext)
{
    qDebug() << "[connet::receiveText]" << rettext;
}


JSCallC::JSCallC(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QWebEngineProfile *profile = QWebEngineProfile::defaultProfile();
    
    QWebEngineView* view = new QWebEngineView(this);
    QWebEnginePage * page = new QWebEnginePage(profile, this);
    view->move(0, 50);
    view->resize(800, 500);
    view->setPage(page);
    
//     connect(page, &QWebEnginePage::loadProgress, [this, page](int progress)
//     {
//         QString d("haha");
//         page->runJavaScript(R"(function sssss(){
// 	            var ret;
// 	            if(typeof(js_call_c)== "object" && typeof(c_call_js)=="function")
// 	            {
// 		            ret = "ok";
// 	            }else
// 	            {
// 		            ret = "false";
// 	            }
// 	            return ret;
//             };
//             sssss();
//         )", [this,page, progress](const QVariant &v)
//         {
//             QString sss = v.toString();
//             if (sss == "ok")
//             {
//                 insertjs(page);
//             }
//         });
// 
//     });
    insertjs(page);
    connet *channeldata = new connet(this);
    QWebChannel *channel = new QWebChannel(this);
    channel->registerObject(QStringLiteral("content"), channeldata);
    view->page()->setWebChannel(channel);
    //QUrl url = QUrl("D:/Code/qttest/Qttest/Qttest/aa.html");
    QUrl url = QUrl("qrc:/aa.html");
    bool bret = url.isValid();
    view->load(url);
    //view->load(QUrl("D:/Code/qttest/Qttest/Qttest/aa.html"));
    QPushButton * btn = new QPushButton(this);
    btn->move(0, 0);
    connect(btn, &QPushButton::clicked, [&, channeldata]()
    {
        emit channeldata->sendText("c++ call js");
    });
}

void JSCallC::insertjs(QWebEnginePage * page)
{
    QWebEngineScript script;
    QFile webChannelJsFile(":/qwebchannel.js");
    if (!webChannelJsFile.open(QIODevice::ReadOnly)) {
        qDebug() << QString("Couldn't open qwebchannel.js file: %1").arg(webChannelJsFile.errorString());
    }
    else {
        qDebug() << "OK webEngineProfile";
        QByteArray webChannelJs = webChannelJsFile.readAll();
        webChannelJs.append(R"(window.onload = function ()
                            {
                                new QWebChannel(qt.webChannelTransport, function (channel) {
                                var content = channel.objects.content;
                                js_call_c = content.receiveText;
                                content.sendText.connect(c_call_js);
                            });
                        };
                    )"
                    );
        script.setSourceCode(webChannelJs);
        script.setName("QWebChannel.js");
        script.setWorldId(QWebEngineScript::MainWorld);
        script.setInjectionPoint(QWebEngineScript::DocumentCreation);
        script.setRunsOnSubFrames(false);
    }

    page->scripts().insert(script);
}