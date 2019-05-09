/* 
 * FFplay for MFC
 *
 * ������ Lei Xiaohua
 * leixiaohua1020@126.com
 * �й���ý��ѧ/���ֵ��Ӽ���
 * Communication University of China / Digital TV Technology
 *
 * http://blog.csdn.net/leixiaohua1020
 * 
 * �����̽�ffmpeg��Ŀ�е�ffplay��������ffplay.c����ֲ����VC�Ļ����¡�
 * ����ʹ��MFC����һ�׼򵥵Ľ��档
 * This software transplant ffplay to Microsoft VC++ environment. 
 * And use MFC to build a simple Graphical User Interface. 
 */


#include "ffplaymfc.h"
#include "ffplaymfcDlg.h"
#include "afxdialogex.h"
//--------------
#include "config.h"
#include <inttypes.h>
#include <math.h>
#include <limits.h>
#include <signal.h>

extern "C"
{
#include "libavutil/avstring.h"
#include "libavutil/colorspace.h"
#include "libavutil/mathematics.h"
#include "libavutil/pixdesc.h"
#include "libavutil/imgutils.h"
#include "libavutil/dict.h"
#include "libavutil/parseutils.h"
#include "libavutil/samplefmt.h"
#include "libavutil/avassert.h"
#include "libavutil/time.h"
#include "libavformat/avformat.h"
#include "libavdevice/avdevice.h"
#include "libswscale/swscale.h"
#include "libavutil/opt.h"
#include "libavcodec/avfft.h"
#include "libswresample/swresample.h"
}

#if CONFIG_AVFILTER
# include "libavfilter/avcodec.h"
# include "libavfilter/avfilter.h"
# include "libavfilter/avfiltergraph.h"
# include "libavfilter/buffersink.h"
# include "libavfilter/buffersrc.h"
#endif

#include "SDL/SDL.h"
#include "SDL/SDL_thread.h"

#include "cmdutils.h"

#include <assert.h>



//���洢��֡��Ϣ
#define MAX_FRAME_NUM 10000
//���洢��Packet��Ϣ
#define MAX_PACKET_NUM 10000
//URL����
#define MAX_URL_LENGTH 500


//��̬����ֻ�������������ļ����пɼ������ܱ������ļ������ã�Ҳ����˵�þ�̬����ֻ
//�����䶨���.cpp��.c�е��ã�������.cpp��.c�ļ��ĺ������ǲ��ܱ����õġ���
//��Ҫ��static void toggle_pause(VideoState *is)���з�װ

//���͡���ͣ������
//Send Command "Pause"
void ffmfc_play_pause();

//���͡���֡������
//Send Command "Step"
void ffmfc_seek_step();

//���͡�ȫ��������
//Send Command "FullScreen"
void ffmfc_play_fullcreen();

//���͡�ǰ��/���ˡ�����
//Send Command "Seek"
void ffmfc_seek(int time);

//���͡���߱ȡ�����
//Send Command "AspectRatio"
void ffmfc_aspectratio(int num,int den);

//���͡���С������
//Send Command "WindowSize"
void ffmfc_size(int percentage);

//���͡����ڻ������ݡ�����
//Send Command "Audio Display Mode"
void ffmfc_audio_display(int mode);

//���͡��˳�������
//Send Command "Quit"
void ffmfc_quit();

//����������
//Main function
int ffmfc_play(LPVOID lpParam);

//��λ
//Reset
int ffmfc_reset_index();

//���Ž���
//Seek Bar
void ffmfc_seek_bar(int pos);
//Stretch
void ffmfc_stretch(int stretch);