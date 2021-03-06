#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Include Headers
#include <QMainWindow>
#include <cstdio>
#include <cstdlib>
#include <ctype.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <vector>
#include <SDL/SDL.h>
#include <multicam.h>
#include <ocam2_sdk.h>
#include <ocam2_pvt.h>
#include <algorithm>
#include <functional>
#include <QApplication>
#include <QImage>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QFileDialog>
#include <QtEndian>
#include <QKeyEvent>
#include <QTime>
#include <QTest>
#include <QTableWidgetItem>
#include <QMouseEvent>
#include <fstream>
#include <QThread>
#include <thread>
#include "terminal.h"
#include "maths.h"
#include "dialog_histogram.h"
#include "dialog_stats.h"
#include "zoomer.h"
#include "g_param.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

#ifndef BYTE
#define BYTE unsigned char
#endif


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool eventFilter(QObject *obj, QEvent *ev);

private slots:
    void on_Snap_shot_PB_clicked();

    void on_SingleSave_PB_clicked();

    void on_SingleLoad_PB_clicked();

    void on_Threshold_Slider_valueChanged(int value);

    void on_Frequency_Slider_valueChanged(int value);

    void on_SequenceSave_PB_clicked();

    void on_Preset_PB_clicked();

    void on_SequenceLoad_PB_clicked();

    void on_Exit_PB_clicked();

    void on_Median_Checkbox_stateChanged(int arg1);

    void on_Dark_PB_clicked();

    void on_BufferSave_PB_clicked();

    void on_BufferAcquire_PB_clicked();

    void on_BufferLoad_PB_clicked();

    void on_BufferDisplay_PB_clicked();

    void on_Max_checkBox_stateChanged(int arg1);

    void on_Run_PB_clicked(bool checked);

    void on_PTC_PB_clicked();

    void on_Darkimage_PB_clicked();

    void on_Dark_Checkbox_stateChanged(int arg1);

    void on_BP_Slider_valueChanged(int value);

    void on_WP_Slider_valueChanged(int value);

    void on_Statistics_PB_clicked();

    void on_PNG_PB_clicked();

    void on_Histo_PB_clicked();

    void on_Temp_PB_clicked();

    void on_Console_Input_LineEdit_returnPressed();

    void on_MaskStatistics_PB_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_ThreshSave_PB_clicked();

    void on_ThreshLoad_PB_clicked();

    void on_AcquireCycle_PB_clicked();

    void on_PlotStatistics_PB_clicked();

    void on_Save_PB_clicked();

    void on_LoadDark_PB_clicked();

    void on_Load_PB_clicked();

    void on_AddNoise_PB_clicked();

    void on_GaussianNoise_CheckBox_stateChanged(int arg1);

    void on_GetMask_PB_clicked();

    void on_AcquireSet_PB_clicked();

    void on_LoadSet_PB_clicked();

    void on_Test_PB_clicked();

    void on_ClearHistory_PB_clicked();

    void on_BufferAllocate_PB_clicked();

    void on_ReadNoise_Checkbox_stateChanged(int arg1);

    void on_Overillumination_Reset_PB_clicked();

    void on_Gain_Histo_PB_clicked();

    void on_Zoom_PB_clicked();

    void on_Flat_PB_clicked();

    void on_LoadFlat_PB_clicked();

    void on_Flat_Checkbox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;

    // Initialize functions
    void test_error();
    void ChangeSection();
    void Init_Driver();
    int InitializeMultiCam();
    static void McCallback(PMCCALLBACKINFO CallBackInfo);
    static void *SignalHandler ( void * Param);
    void AcquireImages();
    void display(const short imagebuffer[]);
    void Ocam_Init();
    void pixel_correction(short img1[], short img2[]);
    void threshold_function(short thresh);
    void InitBigImageBuffer();
    void SerialInit();
    void SerialCommand(QString str, int mode);
    vector<float> short2float(short in[], const int length);
    static void *ReadData(void * SerialRefPtr);
    void UpdateTemp();
    void ZoomImage();
    void mousePressEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
