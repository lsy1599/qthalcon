#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QPushButton>
#include <QMenu>
#include <QMouseEvent>
#include <memory>
#include "qthalconl.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void OpenImg();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void resizeEvent(QResizeEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);
private slots:
    void on_pushButton_reset_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_move_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_zoom_clicked();

    void on_pushButton_3_clicked();

    void saveActionTrigger();
private:
    Ui::MainWindow *ui;
    std::shared_ptr<DisplayImg> m_pDispImg;
    QRect m_RectPictCtrl;
    QMenu *m_menu;
    QAction *m_action;
};
#endif // MAINWINDOW_H
