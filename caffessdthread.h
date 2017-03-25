#ifndef CAFFESSDTHREAD_H
#define CAFFESSDTHREAD_H
#include <caffe/caffe.hpp>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <algorithm>
#include <iomanip>
#include <iosfwd>
#include <memory>
//#include <std::string>
#include <utility>
#include <vector>
#include<QImage>
#include<detector.h>
using namespace cv;
//
using namespace caffe;  // NOLINT(build/namespaces)
#include<QThread>
class CaffeSSDThread :public QThread
{
    Q_OBJECT
public:
    CaffeSSDThread();

// std::vector<vector<float> > Detect(const cv::Mat& img);
    char isPaused;
    bool isStopped;
signals:
    void frameProcessed(const QImage &);

//private:
   // void SetMean(const std::string& mean_file, const std::string& mean_value);

   // void WrapInputLayer(std::vector<cv::Mat>* input_channels);

   // void Preprocess(const cv::Mat& img,
   //                 std::vector<cv::Mat>* input_channels);

private:

    void run();
};


#endif // CAFFESSDTHREAD_H
