#include "simulatorinspect.h"


CSimulatorInspect::CSimulatorInspect(QObject *parent) : QThread{parent}
{

}

CSimulatorInspect::~CSimulatorInspect()
{

}

void CSimulatorInspect::loadImage(const char* pathImage)
{
    mMat = cv::imread(pathImage, cv::IMREAD_COLOR);

    if(mMat.empty())
        return;

    mPixmap = cvMatToQPixmap(mMat);
    emit loadImageSuccess();

}

void CSimulatorInspect::run()
{

}

QImage CSimulatorInspect::cvMatToQImage(const cv::Mat &inMat)
{
    switch(inMat.type())
        {
        // 8-bit, 4 channel
        case CV_8UC4:
        {
            QImage image(inMat.data,
                         inMat.cols,
                         inMat.rows,
                         static_cast<int>(inMat.step),
                         QImage::Format_ARGB32);
            return image;
        }
            // 8-bit, 3 channel
        case CV_8UC3:
        {
    //        cv::Mat rgbMat;
    //        cv::cvtColor(inMat, rgbMat, cv::COLOR_BGR2RGB);
            QImage image(inMat.data,
                         inMat.cols, inMat.rows,
                         static_cast<int>(inMat.step),
                         QImage::Format_RGB888);

            return image.rgbSwapped();
        }
            // 8-bit, 1 channel
        case CV_8UC1:
        {
    #if QT_VERSION >= QT_VERSION_CHECK(5, 5, 0)
            QImage image(inMat.data,
                         inMat.cols, inMat.rows,
                         static_cast<int>(inMat.step),
                         QImage::Format_Grayscale8);
    #else
           static QVector<QRgb> sColorTable;
           // only create our color table the first time
           if(sColorTable.isEmpty())
           {
               sColorTable.resize(256);

               for(int i = 0; i < 256; ++i){
                   sColorTable[i] = qRbg(i, i, i);
               }
           }

           QImage image(inMat.data,
                        inMat.cols, inMat.rows,
                        static_cast<int>(inMat.step),
                        QImage::Format_Indexed8);

           image.setColorTable(sColorTable);
    #endif
           return image;
        }
        default:
            qWarning() << "ASM::cvMatToQImage() - cv::Mat image type not handle in switch:" << inMat.type();
            break;
        }

        return QImage();
}

QPixmap CSimulatorInspect::cvMatToQPixmap(const cv::Mat &inMat)
{
    return QPixmap::fromImage(cvMatToQImage(inMat));
}
