QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += D:/Libraries/opencv480_CUDA/include \
DEPENDPATH += D:/Libraries/opencv480_CUDA/include \

LIBS += -LD:/Libraries/opencv480_CUDA/x64/vc17/lib \
        #-lopencv_core480d \
        #-lopencv_imgproc480d \
        #-lopencv_highgui480d \
        #-lopencv_imgcodecs480d \
        #-lopencv_videoio480d \
        #-lopencv_video480d \
        #-lopencv_calib3d480d \
        #-lopencv_photo480d \
        #-lopencv_features2d480d \
        -lopencv_core480 \
        -lopencv_imgproc480 \
        -lopencv_highgui480 \
        -lopencv_imgcodecs480 \
        -lopencv_videoio480 \
        -lopencv_video480 \
        -lopencv_calib3d480 \
        -lopencv_photo480 \
        -lopencv_features2d480


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    simulatorinspect.cpp

HEADERS += \
    global.h \
    mainwindow.h \
    simulatorinspect.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
