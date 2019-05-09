#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QThread>
#include <QImage>

class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;

class VideoPlayer : public QThread
{
    Q_OBJECT

public:
    explicit VideoPlayer(QString url);
    ~VideoPlayer();

    void startPlay();

signals:
    void sig_GetOneFrame(QImage, double); //每获取到一帧图像 就发送此信号
    void sig_GetOneFramewh(int, int, double);
    void sig_GetRFrame(QImage);   ///2017.8.11---lizhen

protected:
    void run();

private:
    QString mFileName;
    QString strUrl;

    //2017.8.10---lizhen
    VlcInstance *_instance;
    VlcMedia *_media;
    VlcMediaPlayer *_player;
};

#endif // VIDEOPLAYER_H
