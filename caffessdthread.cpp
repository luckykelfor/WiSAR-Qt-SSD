#include<caffessdthread.h>

extern char MODEL_FILE[];// = "../caffe-ssd/models/VGGNet/VOC0712/SSD_300x300/deploy.prototxt";
extern char WEIGHT_FILE[];// = "../caffe-ssd/models/VGGNet/VOC0712/SSD_300x300/VGG_VOC0712_SSD_300x300_iter_120000.caffemodel";
extern char MEAN_FILE[];//="";
extern char MEAN_VALUE[];//="104,117,123";
extern float CONF_THRESH;// = 0.4;

extern Mat currentFrameCopy;
CaffeSSDThread::CaffeSSDThread()
{
    isPaused = 0x01;
    isStopped = false;

}
void CaffeSSDThread::run()
{


    ::google::InitGoogleLogging("Caffe-SSD-in-Qt5");
    // Print output to stderr (while still logging)
    FLAGS_alsologtostderr = 1;

#ifndef GFLAGS_GFLAGS_H_
    namespace gflags = google;
#endif

    //    gflags::SetUsageMessage("Do detection using SSD mode.\n"
    //                            "Usage:\n"
    //                            "    ssd_detect [FLAGS] model_file weights_file list_file\n");
    //    gflags::ParseCommandLineFlags(&argc, &argv, true);

    //    if (argc < 4) {
    //        gflags::ShowUsageWithFlagsRestrict(argv[0], "examples/ssd/ssd_detect");
    //        return 1;
    //    }

    // const string& model_file = argv[1];
    // const string& weights_file = argv[2];
    //  const string& mean_file = FLAGS_mean_file;
    //  const string& mean_value = FLAGS_mean_value;
    //  const string& file_type = FLAGS_file_type;
   // const string& out_file = "output.txt";
    const float confidence_threshold = CONF_THRESH;
    // Initialize the network.
    // std::cout<<"mean file:\n"<<mean_file<<"\nmean_value:\n"<<mean_value<<"\nconfidence_threshold:\n"<<confidence_threshold<<std::endl;
    Detector detector(MODEL_FILE, WEIGHT_FILE, MEAN_FILE, MEAN_VALUE);

    while (!isStopped)
    {


        while(0x00 == this->isPaused)
        {

            std::vector<vector<float> > detections = detector.Detect(currentFrameCopy);

            /* Print the detection results. */
            for (int i = 0; i < detections.size(); ++i) {
                const vector<float>& d = detections[i];
                // Detection format: [image_id, label, score, xmin, ymin, xmax, ymax].
                CHECK_EQ(d.size(), 7);
                const float score = d[2];
                if (score >= confidence_threshold) {

                    cv::Point tl(static_cast<int>(d[3]*currentFrameCopy.cols),static_cast<int>(d[4]*currentFrameCopy.rows));
                    cv::Point br(static_cast<int>(d[5]*currentFrameCopy.cols),static_cast<int>(d[6]*currentFrameCopy.rows));
                    cv::rectangle(currentFrameCopy,cv::Rect(tl,br),cv::Scalar(0,255,0),4);
                    cv::putText(currentFrameCopy,label[(int)d[1]],tl,0,1,cv::Scalar(0,255,255),2);
                }
            }
            //std::cout<<"IN";
            cvtColor(currentFrameCopy, currentFrameCopy, CV_BGR2RGB);

            QImage imageQ((unsigned char*)currentFrameCopy.data,currentFrameCopy.cols,currentFrameCopy.rows,currentFrameCopy.cols*3,QImage::Format_RGB888);
            emit frameProcessed(imageQ);
            msleep(25);

        }
        msleep(100);

    }
    return;
}
