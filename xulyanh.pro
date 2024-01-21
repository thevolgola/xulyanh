QT       += core gui serialport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connectiondialog.cpp \
    main.cpp \
    mainwindow.cpp
    INCLUDEPATH += G:\opencv\build\include

    LIBS += G:\opencv_build\bin\libopencv_core480.dll
    LIBS += G:\opencv_build\bin\libopencv_highgui480.dll
    LIBS += G:\opencv_build\bin\libopencv_imgcodecs480.dll
    LIBS += G:\opencv_build\bin\libopencv_imgproc480.dll
    LIBS += G:\opencv_build\bin\libopencv_features2d480.dll
    LIBS += G:\opencv_build\bin\libopencv_calib3d480.dll
    LIBS += G:\opencv_build\bin\opencv_videoio_ffmpeg480_64.dll
    LIBS += G:\opencv_build\bin\libopencv_video480.dll
    LIBS += G:\opencv_build\bin\libopencv_videoio480.dll
    LIBS += G:\opencv_build\bin\libopencv_objdetect480.dll


HEADERS += \
    connectiondialog.h \
    mainwindow.h

FORMS += \
    connectiondialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
