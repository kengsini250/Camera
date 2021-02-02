QT       += core gui multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += \
           SettingDialog/settingdialog.h \
           date.h \
           mainwindow.h \
           CameraDialog/cameradialog.h \
           save.h \
           subwindow.h \
           camera.h

SOURCES += \
        SettingDialog/settingdialog.cpp \
        date.cpp \
        main.cpp \
        mainwindow.cpp \
        CameraDialog/cameradialog.cpp \
        save.cpp \
        subwindow.cpp \
        camera.cpp

FORMS += mainwindow.ui \
        CameraDialog/cameradialog.ui \
        SettingDialog/settingdialog.ui

INCLUDEPATH += "C:\opencv\build\include"
INCLUDEPATH += "C:\opencv\build\include\opencv2"


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
else: win32:LIBS+= "C:/opencv/build/x64/vc15/lib/opencv_world451d.lib"
#else: win32:LIBS+= \
#\"C:/opencv/build_g++/lib/libopencv_core451.dll.a" \
#\"C:/opencv/build_g++/lib/libopencv_imgproc451.dll.a" \
#\"C:/opencv/build_g++/lib/libopencv_highgui451.dll.a" \
#\"C:/opencv/build_g++/lib/libopencv_videoio451.dll.a"
!isEmpty(target.path): INSTALLS += target
