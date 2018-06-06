#ifndef QTHALCONL_H
#define QTHALCONL_H

#if defined(QTHALCONL_LIBRARY)
#  define QTHALCONLSHARED_EXPORT __declspec(dllexport)
#else
#  define QTHALCONLSHARED_EXPORT __declspec(dllimport)
#endif



#include "ImageOperStruct.h"
#include "saveoptoin.h"

#define ZOOM_OUT_LIMIT 32               //最大放大倍数为32倍
#define ZOOM_IN_LIMIT 0.03125           //最小缩小倍数1/32倍
#define MOUSE_PRESSED_NO_BUTTON 0
#define MOUSE_PRESSED_LEFT_BUTTON 1
#define MOUSE_PRESSED_RIGHT_BUTTON 2
#define TRUE 1
enum ZoomParam
{
    ZoomIn = 0,     //缩小
    ZoomOut         //放大
};

class QTHALCONLSHARED_EXPORT DisplayImg
{
public:

    DisplayImg(long winId, int fatherWindowWidth, int fatherWindowHeight);      //第一个参数为父窗口句柄，第二个和第三个参数为父窗口宽和高
    ~DisplayImg();
    bool InsertImageViewed(InitDisp initParam,HImage &imageInserted);     //插入一张降采样的图片用来显示
    bool InsertImageOringinal(HImage &imageOriginal);                            //插入一张原图
    bool Reset();                                                   //复原图像至初始状态（包括位置，大小信息）
    void Zoom(ZoomParam ControlZoom);   //缩放图像
    bool Move();   //拖动图像
    bool SetMoveStart();        //拖动图像的预处理
    void SetMouseDrawControl(bool draw);        //控制当前是否支持鼠标画框
    void ChangeWIndowSize(int windowWidth, int windowHeight);       //使得halcon图形窗口大小随着父窗口大小的改变而改变。
    bool ClearHalconWindow();                           //清除当前图形窗口中的图片
    void SetMoveControl(bool move);                     //控制当前是否支持移动图片
    void DrawRect(Rect rectDraw, HTuple rectColor);     //用代码画一个矩形框
    void MouseDrawRect(HTuple rectColor);               //用鼠标画矩形框，使用鼠标坐标激活
    void DrawRects(std::vector<Rect> rectsDraw, HTuple rectColor);      //用代码画一组矩形框
    void PitchRect();                                   //对已经画的矩形进行选择
    void DeleteRectDrawed();                            //删除被选择的矩形
    void DrawRectMoving(HTuple rectColor);              //鼠标画框的过程中，持续显示过程中的矩形
    void CancelPitch();                                 //取消所有被选择的矩形
    void SetPitchRectControl(bool pitch);               //传入参数为true，则激活选中矩形的功能。false则禁用
    void SaveImage(std::string & filePath);

private:
    bool TestMposition(Hlong &tRow, Hlong &tColumn, Hlong & button);
    bool UpdateHalconGraphicWindow();
    bool VerifyRect(Rect &rectVerified);  //Mode--true,代表使用代码画框；Mode--false,代表用两个点作为输入参数画框
    Rect JudgeMouseDirection(Hlong hLPosEnd_x, Hlong hLPosEng_y);

private:

    HWindow *m_hWindow;             //halcon 窗口对象
    HImage m_hImg;                  //图片对象
    HImage m_hImgOriginal;
    std::vector<rectDrawed> m_XLDs;                 //这个容器控制所有被画的矩形
    std::vector<int>        m_rectPitched;          //这个容器承载所有被选中矩形的加入序号
    std::vector<rectDrawed> m_XldPitched;           //这个容器承载所有被选中的矩形
    Rect m_RectPicCtrl;
    bool m_bInited;
    bool m_drawed;
    int m_nImageWidth;
    int m_nImageHeight;             //图片的宽和高
    double m_dImgAspectRation;      //原始图片的宽高比
    double m_dCoeff;//缩放系数
    double m_dCurrCoeff;            //当前缩放系数
    Rect m_InitRectDisp;            //插入图片后的初始halcon窗口参数值
    Rect m_CurrRectDisp;            //当前显示的halcon窗口参数值
    bool m_bMove;
    Hlong m_lMoveX;
    Hlong m_lMoveY;
    bool m_moveControl;             //由用户控制。对平移功能使能；true--使能平移函数，false--禁用平移功能
    bool m_mouseDrawControl;        //由用户控制。对鼠标画框使能；true--使能鼠标画框函数，false--禁用鼠标画框函数
    HTuple m_rectColor;
    Rect m_Rect1;
    Hlong m_mousePressedMode;       //0--代表没有按钮拿下；1--代表鼠标左键被按下；2--代表鼠标右键被按下
    bool m_isPiech;                 //true--代表有取到rect;false--代表没取到rect
    bool m_pitchControl;            //true--代表可以选中矩形框；false--代表不能选中
};

#endif // QTHALCONL_H
