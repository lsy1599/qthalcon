#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("Halcon Test"));
    long winID = (long)ui->widget_halcon->winId();


    m_pDispImg = std::make_shared<DisplayImg>(winID,579,344);

    m_menu = new QMenu(this);
    m_action = new QAction("save image",m_menu);
    connect(m_action, SIGNAL(triggered(bool)), SLOT(saveActionTrigger()));
    m_menu->addAction(m_action);

    OpenImg();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenImg()
{

    m_RectPictCtrl.setTop(ui->widget_halcon->y());
    m_RectPictCtrl.setBottom(ui->widget_halcon->y() + 344);
    m_RectPictCtrl.setLeft(ui->widget_halcon->x());
    m_RectPictCtrl.setRight(ui->widget_halcon->x() + 579);

    HImage imageH;
    //读一张图
    ReadImage(&imageH, "monkey");

    InitDisp tempInitParam;
    //当前的父窗口上下左右边的坐标
    tempInitParam.rect.nTop = m_RectPictCtrl.top();
    tempInitParam.rect.nLeft = m_RectPictCtrl.left();
    tempInitParam.rect.nBottom = m_RectPictCtrl.bottom();
    tempInitParam.rect.nRight = m_RectPictCtrl.right();
    //插入图片到halcon图形窗口
    m_pDispImg->InsertImageViewed(tempInitParam,imageH);

}


 void MainWindow::mousePressEvent(QMouseEvent * event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (ui->widget_halcon->rect().contains(event->pos()))
        {
            //移动图片的预处理操作
            m_pDispImg->SetMoveStart();

        }
    }
    //鼠标在矩形框内点击鼠标左键，则选中对应的矩形
    m_pDispImg->PitchRect();
    event->ignore();
}

void MainWindow::mouseMoveEvent(QMouseEvent * event)
{
    //移动图片
    m_pDispImg->Move();
    //鼠标在移动过程中画出所有的矩形
    m_pDispImg->DrawRectMoving("red");
    event->ignore();
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    //鼠标松开时，画出最后的矩形
    m_pDispImg->MouseDrawRect("red");
    event->ignore();
}


void MainWindow::wheelEvent(QWheelEvent * event)
{
    int zDelta = event->angleDelta().y();
    if(zDelta > 0)
    {
        //放大图片
        m_pDispImg->Zoom(ZoomParam::ZoomOut);
    }
    else
    {
        //缩小图片
        m_pDispImg->Zoom(ZoomParam::ZoomIn);
    }
    event->ignore();
}


void MainWindow::resizeEvent(QResizeEvent *event)
{
    //当父窗口size改变时，同时改变halcon图形窗口的大小，这个函数，其他地方最好不要调用；


    //直接获取widget_halcon 的高，拿不到正确的值，只有这样减一下，值才正确。有待更好的方法来处理
    int fatherWindowHeight = event->size().height() - ui->statusBar->height() - ui->widget_2->height();

    m_pDispImg->ChangeWIndowSize(event->size().width(), fatherWindowHeight);

}

void MainWindow::on_pushButton_reset_clicked()
{
    //复原图片至初始打开的状态
    m_pDispImg->Reset();

}

void MainWindow::on_pushButton_clear_clicked()
{
    //清空当前的halcon图形窗口
    m_pDispImg->ClearHalconWindow();
}

void MainWindow::on_pushButton_move_clicked()
{
    //对平移功能使能
    m_pDispImg->SetMoveControl(true);
    m_pDispImg->SetMouseDrawControl(false);
    m_pDispImg->SetPitchRectControl(false);
}

void MainWindow::on_pushButton_clicked()
{
    //取消对已经被选中的矩形的选中
    m_pDispImg->CancelPitch();


}

void MainWindow::on_pushButton_2_clicked()
{
    m_pDispImg->SetMoveControl(false);
    m_pDispImg->SetMouseDrawControl(true);
    m_pDispImg->SetPitchRectControl(false);
}

void MainWindow::on_pushButton_zoom_clicked()
{
    //删除被选中的所有矩形
    m_pDispImg->DeleteRectDrawed();
}

void MainWindow::on_pushButton_3_clicked()
{
    m_pDispImg->SetPitchRectControl(true);
     m_pDispImg->SetMouseDrawControl(false);
    m_pDispImg->SetMoveControl(false);
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    //m_menu = new QMenu(this);

   // QAction saveAction("save image",m_menu);

    m_menu->move(cursor().pos());
    //m_menu->setFixedSize(QSize(100,100));
    m_menu->show();
    event->ignore();
}

void MainWindow::saveActionTrigger()
{
    QString name = QFileDialog::getSaveFileName(this, tr("Save File"),
                                               "/home/jana/untitled.bmp",
                                               tr("Images (*.png *.xpm *.jpg *.bmp)"));
   std::string filePath =  name.toStdString();
    m_pDispImg->SaveImage(filePath);
}
