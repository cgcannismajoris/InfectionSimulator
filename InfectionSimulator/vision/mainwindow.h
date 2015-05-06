#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//#include "graphwindow.h"

#include "../control/maincontrol.h"
#include "../model/graphdata.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private slots:
        void on_checkBox_toggled(bool checked);
        void on_pushButton_clicked();
        void on_pbClean_clicked();
        void on_hsResolution_valueChanged(int value);

        void on_sbMaxTime_valueChanged(int arg1);

        void on_actionSalvar_triggered();

private:
            Ui::MainWindow *ui;
            mainControl *control = NULL;
            void updateGraph();
            void requestSavePng();
};

#endif // MAINWINDOW_H
