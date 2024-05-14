#ifndef CSIMULATORINSPECT_H
#define CSIMULATORINSPECT_H

#include "global.h"
#include <QThread>
#include <QPixmap>
#include <QImage>
#include <QMutex>
#include <QMessageBox>
#include <QDebug>
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

class CSimulatorInspect : public QThread
{
    Q_OBJECT
public:
    CSimulatorInspect(QObject* parent = nullptr);
    ~CSimulatorInspect();

public:
    void loadImage(const char* pathImage);
    QPixmap pixmap() const{
           return mPixmap;
       }

signals:
    void loadImageSuccess();

protected:
    void run() override;


private:

    cv::Mat mMat;
    cv::VideoCapture mVideoCap;

    QPixmap mPixmap;

    QImage cvMatToQImage(const cv::Mat &inMat);
    QPixmap cvMatToQPixmap(const cv::Mat &inMat);
};

#endif // CSIMULATORINSPECT_H
