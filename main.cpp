#include "mainwindow.h"
#include <QApplication>

int WEBCAM_ID = 0;
char VIDEO_FILE[] = "../YoloDisplay/DJI_0038.MOV";
char INPUT_DATA_FILE[]    = "../YoloDisplay/cfg/coco.data";
char INPUT_CFG_FILE[]     = "../YoloDisplay/cfg/yolo.cfg";
char INPUT_WEIGHTS_FILE[] = "../YoloDisplay/yolo.weights";
char INPUT_IMAGE_FILE[]   = "../YoloDisplay/test.png";
int WEBCAM_WIDTH = 1280;
int WEBCAM_HEIGHT = 720;
int DISPLAY_WIDTH = 720;
int DISPLAY_HEIGHT=420;

char MODEL_FILE[] = "../caffe-ssd/models/VGGNet/VOC0712/SSD_300x300/deploy.prototxt";
char WEIGHT_FILE[] = "../caffe-ssd/models/VGGNet/VOC0712/SSD_300x300/VGG_VOC0712_SSD_300x300_iter_120000.caffemodel";
char MEAN_FILE[]="";
char MEAN_VALUE[]="104,117,123";
float CONF_THRESH = 0.4;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
