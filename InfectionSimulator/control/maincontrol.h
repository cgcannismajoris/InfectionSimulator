#ifndef MAINCONTROL_H
#define MAINCONTROL_H

#include <QLineEdit>
#include <QSlider>
#include <QVector>
#include <QString>

#include "../model/virusspread.h"
#include "../model/graphdata.h"

class mainControl
{
    public:
        mainControl();
        ~mainControl();

        graphData *process(QString strNumOfPeople, QString strPConstant, int resolution, int maxTime);
};

#endif // MAINCONTROL_H
