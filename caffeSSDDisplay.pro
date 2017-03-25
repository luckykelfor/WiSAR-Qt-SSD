#-------------------------------------------------
#
# Project created by QtCreator 2017-03-25T04:09:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = caffeSSDDisplay
TEMPLATE = app





FORMS    += \
    mainwindow.ui
SOURCES += main.cpp \
 mainwindow.cpp    \
    ../caffe-ssd/include/caffe/proto/caffe.pb.cc \
    customerview.cpp \
    realtimedisplaythread.cpp \
    caffessdthread.cpp \
    detector.cpp
INCLUDEPATH += /usr/local/include \
/usr/local/hdf5/include \
/usr/local/cuda/include \
/home/amax/fkm/caffe-ssd/include

HEADERS  += mainwindow.h \
    customerview.h \
    realtimedisplaythread.h \
    caffessdthread.h \
    detector.h
LIBS += -L/usr/local/lib \
-L/home/amax/fkm/caffe-ssd/build/lib \
-L/usr/local/hdf5/lib \
-L/usr/local/cuda/lib64 \
-lopencv_core -lopencv_highgui -lopencv_imgproc -lcudart -lcudnn -lcaffe -lglog -lgflags -lprotobuf -lboost_system -lboost_filesystem -lboost_regex -lm -lhdf5_hl -lhdf5
DEFINES += USE_OPENCV
DEFINES += USE_CUDNN
