#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include<caffessdthread.h>
#include<realtimedisplaythread.h>
#include<customerview.h>
#include<iostream>
#include<QLabel>
#include<QPushButton>
#include<QImage>


using namespace cv;
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

 //widgets:
  //  QPushButton pushButton_beginProc; //in ui.h
    void onButton_dispProcessResults();
    void onButton_dispRealTimeView();
    void dispProcessResults(const QImage&);
    void dispRealTimeView(const QImage&);
    CaffeSSDThread *workThread;
    RealTimeDisplayThread *dispThread;
    CustomerGraphicsView *myProcessedView,*myRealTimeView;


    ~MainWindow();
protected:
    void closeEvent(QCloseEvent*);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
