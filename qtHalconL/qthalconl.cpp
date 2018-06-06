#include "qthalconl.h"

DisplayImg::DisplayImg(long winId, int fatherWindowWidth, int fatherWindowHeight):
    m_bInited(false),
    m_nImageWidth(0),
    m_nImageHeight(0),
    m_dImgAspectRation(0),
    m_dCoeff(0),
    m_dCurrCoeff(0),
    m_bMove(false),
    m_lMoveX(0),
    m_lMoveY(0),
    m_moveControl(false),
    m_drawed(false),
    m_mouseDrawControl(false),
    m_mousePressedMode(0),
    m_isPiech(false),
    m_pitchControl(false),
    m_hWindow(new HWindow(0,0,fatherWindowWidth,fatherWindowHeight,(HTuple) winId,"visible",""))
{

}

DisplayImg::~DisplayImg()
{
    delete m_hWindow;
}
//插入图片，第一个参数为父窗口的位置坐标，第二个参数为待插入的图片
bool DisplayImg::InsertImageViewed(InitDisp initParam, HImage &imageInserted)
{
    m_hImg = imageInserted;

    m_RectPicCtrl = initParam.rect;


    m_nImageWidth = m_hImg.Width()[0].I();
    m_nImageHeight = m_hImg.Height()[0].I();
    m_dImgAspectRation = static_cast<double>(m_nImageWidth) / m_nImageHeight;

    //确定缩放系数

    double coeffA = m_nImageWidth * 1.0 / (m_RectPicCtrl.nRight - m_RectPicCtrl.nLeft);
    double coeffB = m_nImageHeight * 1.0 / (m_RectPicCtrl.nBottom - m_RectPicCtrl.nTop);
    if (coeffA <= coeffB)
    {
        m_dCoeff = coeffA;
        m_InitRectDisp.nLeft = (coeffA - coeffB) / 2 * (m_RectPicCtrl.nRight - m_RectPicCtrl.nLeft);
        m_InitRectDisp.nRight = (coeffA + coeffB) / 2 * (m_RectPicCtrl.nRight - m_RectPicCtrl.nLeft);
        m_InitRectDisp.nTop = 0;
        m_InitRectDisp.nBottom = m_nImageHeight - 1;
    }
    else
    {
        m_dCoeff = coeffB;
        m_InitRectDisp.nLeft = 0;
        m_InitRectDisp.nRight = m_nImageWidth - 1;
        m_InitRectDisp.nTop = (-coeffA + coeffB) / 2 * (m_RectPicCtrl.nBottom - m_RectPicCtrl.nTop);
        m_InitRectDisp.nBottom = (coeffA + coeffB) / 2 * (m_RectPicCtrl.nBottom - m_RectPicCtrl.nTop);
    }

    m_dCurrCoeff = m_dCoeff;
    m_CurrRectDisp = m_InitRectDisp;
    m_bInited = TRUE;
    m_XLDs.clear();         //插入图片前，先清空所有的矩形框
    m_mouseDrawControl = false;
    m_moveControl = false;
    //显示图像

    UpdateHalconGraphicWindow();
    return true;
}
bool DisplayImg::InsertImageOringinal(HImage &imageOriginal)
{
    if(!m_bInited)
    {
        return false;
    }
    else
    {
        m_hImgOriginal = imageOriginal;
        return true;
    }
}
//每一次对图像或者窗口的改变，都需要调用此函数
bool DisplayImg::UpdateHalconGraphicWindow()
{
    if (!m_bInited)
        return false;
    SetSystem("flush_graphic", "false");
    m_hWindow->ClearWindow();
    m_hWindow->SetPart(m_CurrRectDisp.nTop, m_CurrRectDisp.nLeft,\
            m_CurrRectDisp.nBottom, m_CurrRectDisp.nRight);
    m_hWindow->DispObj(m_hImg);

    SetSystem("flush_graphic", "true");
    if(!m_drawed)
        return true;

    for(auto rectObj : m_XLDs)
    {
        m_hWindow->SetColor(rectObj.rectColor);
        m_hWindow->DispObj(rectObj.rectObj);
    }

    return true;
}
//复原图像至初始状态
bool DisplayImg::Reset()
{
    if (!m_bInited)
        return false;

    m_CurrRectDisp = m_InitRectDisp;
    m_dCurrCoeff = m_dCoeff;

    UpdateHalconGraphicWindow();
    return true;
}

void DisplayImg::Zoom(ZoomParam ControlZoom)
{
    if (!m_bInited)
        return;
    double coeffEnlarge = 1.2;
    if (ControlZoom == ZoomIn)
    {
        //缩小
        double zoomLimit = m_nImageHeight*1.0 /ZOOM_IN_LIMIT ;
        if (m_CurrRectDisp.nBottom - m_CurrRectDisp.nTop > zoomLimit || m_CurrRectDisp.nRight - m_CurrRectDisp.nLeft > zoomLimit)
            return;
    }
    else if(ControlZoom == ZoomOut)
    {
        //放大
        double zoomLimit = m_nImageHeight*1.0 /ZOOM_OUT_LIMIT ;
        coeffEnlarge = 1.0 / coeffEnlarge;      //取coeffEnlaige 的倒数
        if (m_CurrRectDisp.nBottom - m_CurrRectDisp.nTop < zoomLimit || m_CurrRectDisp.nRight - m_CurrRectDisp.nLeft < zoomLimit)
            return;
    }
    Hlong x = 0;
    Hlong y = 0;
    Hlong tButton = 0;
    try
    {
        //获取当前鼠标在halcon图形窗口中的位置
        m_hWindow->GetMposition(&y, &x, &tButton);
    }
    catch (HException)
    {
        return;
    }
    double dXLengthFront = (m_CurrRectDisp.nLeft - x) * coeffEnlarge;
    double dXLengthBack = (m_CurrRectDisp.nRight - x) * coeffEnlarge;
    double dYLengthFront = (m_CurrRectDisp.nTop - y) * coeffEnlarge;
    double dYLengthBack = (m_CurrRectDisp.nBottom - y) * coeffEnlarge;
    m_CurrRectDisp.nLeft = (x + dXLengthFront);
    m_CurrRectDisp.nRight =( x + dXLengthBack );
    m_CurrRectDisp.nTop = (y + dYLengthFront);
    m_CurrRectDisp.nBottom = (y + dYLengthBack);
    m_dCurrCoeff *= coeffEnlarge;
    //显示
    UpdateHalconGraphicWindow();
}
//平移函数，在用户设置平移函数使能之后才会被调用
bool DisplayImg::Move()
{
    if (!m_bInited)
        return false;
    if (!m_bMove)
        return false;
    Hlong currX = 0;
    Hlong currY = 0;
    Hlong button = 0;
    if (!TestMposition(currY, currX, button))
    {
        m_bMove = FALSE;
        return false;
    }
    Hlong X = currX - m_lMoveX;
    Hlong Y = currY - m_lMoveY;
    m_CurrRectDisp.nLeft -= X;
    m_CurrRectDisp.nRight -= X;
    m_CurrRectDisp.nTop -= Y;
    m_CurrRectDisp.nBottom -= Y;
    //显示
    UpdateHalconGraphicWindow();
    return true;
}

//平移函数的预处理，平移之前需调用一次
bool DisplayImg::SetMoveStart()
{
    if (!m_bInited)
    {
        m_bMove = false;
        return false;
    }
    if (!TestMposition(m_lMoveY, m_lMoveX, m_mousePressedMode) || m_moveControl == false)
    {
        m_bMove = false;
        return false;
    }
    m_bMove = true;
    return true;
}

bool DisplayImg::TestMposition(Hlong & tRow, Hlong & tColumn, Hlong & button)
{
    try
    {
        m_hWindow->GetMposition(&tRow, &tColumn, &button);
    }
    catch (HException)
    {
        tRow = 0;
        tColumn = 0;
        button = 0;
        return false;
    }
    return true;
}
//随着父窗口大小的改变而改变halcon图形窗口的大小，用户不要调用
void DisplayImg::ChangeWIndowSize(int windowWidth, int windowHeight)
{
    m_hWindow->SetWindowExtents(0,0,windowWidth,windowHeight);
    UpdateHalconGraphicWindow();
}
//清除当前图形窗口的所有图形
bool DisplayImg::ClearHalconWindow()
{
    if(!m_bInited)
        return false;
    m_hWindow->ClearWindow();
    m_XLDs.clear();

    m_bInited = false;
    return true;
}
//设置平移函数使能，传入参数为true 时，使能平移函数；传入参数为false时，禁用平移函数
void DisplayImg::SetMoveControl(bool move)
{
    m_moveControl = move;
}

void DisplayImg::DrawRect(Rect rectDraw, HTuple rectColor)
{

    if(!VerifyRect(rectDraw))
        return;
    HObject tObj;
    GenRectangle1(&tObj, rectDraw.nTop, rectDraw.nLeft, rectDraw.nBottom, rectDraw.nRight);
    HObject rect;
    GenContourRegionXld(tObj, &rect, "center");
    rectDrawed XLD;
    XLD.rectObj = rect;
    XLD.rectColor = rectColor;
    m_XLDs.push_back(XLD);
    m_drawed = true;
    UpdateHalconGraphicWindow();
}

void DisplayImg::MouseDrawRect(HTuple rectColor)
{
    if(!m_mouseDrawControl)
        return;
    Hlong hLPosEnd_x = 0;
    Hlong hLPosEng_y = 0;
    Hlong button = 0;

    if(m_mousePressedMode != MOUSE_PRESSED_LEFT_BUTTON)
    {
        return;
    }
    if(!TestMposition(hLPosEng_y, hLPosEnd_x, button))
        return;

    DrawRect(JudgeMouseDirection(hLPosEnd_x, hLPosEng_y), rectColor);
    m_lMoveX = 0;
    m_lMoveY = 0;
    m_mousePressedMode = MOUSE_PRESSED_NO_BUTTON;
}

void DisplayImg::DrawRects(std::vector<Rect> rectsDraw, HTuple rectColor)
{

    for(auto rect : rectsDraw)
    {
        //对vector中每一个矩形进行绘制
        DrawRect(rect, rectColor);
    }
}
bool DisplayImg::VerifyRect(Rect &rectVerified)
{
    //验证准备画的矩形，是否符合要求；
    HTuple tWidth = 0;
    HTuple tHeight = 0;
    if(!m_bInited)
        return false;
    m_hImg.GetImageSize(&tWidth, &tHeight);
        if(rectVerified.nBottom == 0 && rectVerified.nLeft == 0\
            && rectVerified.nRight == 0 && rectVerified.nTop == 0)
            return false;
        if(rectVerified.nLeft < 0 || rectVerified.nTop < 0)
            return false;
        if(rectVerified.nRight > tWidth[0].D() || rectVerified.nBottom > tHeight[0].D())
            return false;
    return true;
}

void DisplayImg::SetMouseDrawControl(bool draw)
{
    m_mouseDrawControl = draw;
}

void DisplayImg::PitchRect()
{
    if(!m_pitchControl)
        return;
    Hlong hRow = 0;
    Hlong hColumn = 0;
    Hlong button = 0;
    if(!TestMposition(hRow, hColumn, button))
        return;

    if(button != MOUSE_PRESSED_LEFT_BUTTON)
        return;


    HObject rects;      //新的rect容器
    HObject regionSelected;     //容器中被选中的rect，即待删除的region
    HObject pointSelected ;
    GenEmptyObj(&rects);
    HObject rectSelected;               //用来装待删除的rect

        for(auto rect : m_XLDs)
        {
            HObject region;
            GenRegionContourXld(rect.rectObj, &region, "filled");           //xld转成对应的region
            ConcatObj(rects, region, &rects);                               //把所有的region放到rect容器中
        }
        GenRegionPoints(&pointSelected, hRow,hColumn);
        SelectShapeProto(rects, pointSelected, &regionSelected, "overlaps_rel", 0.0000001,100);       //依据点，选中包含这个点的region
        GenContourRegionXld(regionSelected, &rectSelected, "center");                           //region 转成对应的xld

        HTuple isequal = 0;
        for(int i = 0; i < m_XLDs.size(); i++)
        {
            CompareObj(rectSelected, m_XLDs.at(i).rectObj,0.0,&isequal);
            if(isequal == TRUE)
            {
                for(auto aRect : m_XldPitched)
                {
                    HTuple isEqual= 0;
                    CompareObj(rectSelected,aRect.rectObj,0.0,&isEqual);
                    if(isEqual == TRUE)
                        return;
                }

                m_rectPitched.push_back(i);
                m_XLDs.erase(m_XLDs.begin()+i);
                rectDrawed xldPitch;
                xldPitch.rectObj = rectSelected;
                xldPitch.rectColor = "gray";
                m_XldPitched.push_back(xldPitch);
                m_XLDs.insert(m_XLDs.begin()+i,xldPitch);
                m_isPiech = true;
                break;
            }
        }

    //被选中的矩形的加入序号从小到大进行排序
    std::sort(m_rectPitched.begin(), m_rectPitched.end());

    UpdateHalconGraphicWindow();
}

void DisplayImg::CancelPitch()
{
    if(!m_isPiech)
        return;
    for(int i = 0; i < m_rectPitched.size(); i++)
    {
        m_XldPitched.at(i).rectColor = "red";
        m_XLDs.erase(m_XLDs.begin()+m_rectPitched.at(i));
        m_XLDs.insert(m_XLDs.begin()+m_rectPitched.at(i),m_XldPitched.at(i));
    }
    //取消矩形的选中，则需要这俩个容器清空
    m_rectPitched.clear();
    m_XldPitched.clear();
    m_isPiech = false;

    UpdateHalconGraphicWindow();
}

void DisplayImg::DeleteRectDrawed()
{
    if(!m_isPiech)
        return;
    for(int i = 0; i < m_rectPitched.size(); i++)
    {
        m_XLDs.erase(m_XLDs.begin()+m_rectPitched.at(i));
        for(int j = 0; j < m_rectPitched.size(); j++)
        {
            m_rectPitched.at(j) -= 1;
        }
    }

    //完成一次删除操作，则需要将这两个容器清空
    m_rectPitched.clear();
    m_XldPitched.clear();
    m_isPiech = false;
    UpdateHalconGraphicWindow();
}

void DisplayImg::DrawRectMoving(HTuple rectColor)
{
    if(!m_mouseDrawControl || m_mousePressedMode != MOUSE_PRESSED_LEFT_BUTTON)
        return;
    Hlong posx = 0;
    Hlong posy = 0;
    Hlong button = 0;

    TestMposition(posy, posx, button);
    Rect mouseRect;
    mouseRect = JudgeMouseDirection(posx, posy);
    if(!VerifyRect(mouseRect))
        return;
    HObject tObj;
    GenRectangle1(&tObj, mouseRect.nTop, mouseRect.nLeft, mouseRect.nBottom, mouseRect.nRight);
    HObject rect;
    GenContourRegionXld(tObj, &rect, "center");
    UpdateHalconGraphicWindow();
    m_hWindow->SetColor(rectColor);
    m_hWindow->DispObj(rect);

}
Rect DisplayImg::JudgeMouseDirection(Hlong hLPosEnd_x, Hlong hLPosEng_y)
{
    Rect nullRect;
    nullRect.nBottom = 0;nullRect.nLeft = 0;nullRect.nRight = 0;nullRect.nTop = 0;
    if(m_lMoveX == hLPosEnd_x && m_lMoveY == hLPosEng_y)
    {
        return nullRect;
    }
    if(hLPosEnd_x >= m_lMoveX && hLPosEng_y >= m_lMoveY)
        //左上到右下
    {
        Rect mouseRect;
        mouseRect.nTop = m_lMoveY; mouseRect.nBottom = hLPosEng_y; mouseRect.nLeft = m_lMoveX; mouseRect.nRight = hLPosEnd_x;
        return mouseRect;
    }
    if(hLPosEnd_x <= m_lMoveX && hLPosEng_y <= m_lMoveY)
        //右下到左上
    {
        Rect mouseRect;
        mouseRect.nTop = hLPosEng_y; mouseRect.nBottom = m_lMoveY; mouseRect.nLeft = hLPosEnd_x; mouseRect.nRight = m_lMoveX;
        return mouseRect;
    }

    if(hLPosEnd_x >= m_lMoveX && hLPosEng_y <= m_lMoveY)
        //左下到右上
    {
        Rect mouseRect;
        mouseRect.nTop = hLPosEng_y; mouseRect.nBottom = m_lMoveY; mouseRect.nLeft = m_lMoveX; mouseRect.nRight = hLPosEnd_x;
        return mouseRect;
    }
    if(hLPosEnd_x <= m_lMoveX && hLPosEng_y >= m_lMoveY)
        //右上到左下
    {
        Rect mouseRect;
        mouseRect.nTop = m_lMoveY; mouseRect.nBottom = hLPosEng_y; mouseRect.nLeft = hLPosEnd_x; mouseRect.nRight = m_lMoveX;
        return mouseRect;
    }
    return nullRect;
}


void DisplayImg::SetPitchRectControl(bool pitch)
{
    m_pitchControl = pitch;
}


void DisplayImg::SaveImage(std::string & filePath)
{
    if(!m_bInited)
    {
        return;
    }
    if(m_hImgOriginal.CountObj() != 0)                  //如果有原图则存原图
    {
        saveOptoin optionSave(m_hImgOriginal);
        optionSave.Save(filePath);
    }
    else                                //没有原图，则存显示用的图
    {
        saveOptoin optionSave(m_hImg);
        optionSave.Save(filePath);
    }

}
