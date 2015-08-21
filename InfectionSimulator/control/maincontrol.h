#ifndef MAINCONTROL_H
#define MAINCONTROL_H

#include <QLineEdit>
#include <QSlider>
#include <QVector>
#include <QString>

#include "../model/virusresistance.h"
#include "../model/virusspread.h"
#include "../model/graphdata.h"

class mainControl
{
    public:
        mainControl();
        ~mainControl();

        graphData *processVirusSpread(QString strNumOfPeople, QString strPConstant, int resolution, int startTime, int maxTime);
        graphData *processVirusResistance(QString strNumOfPeople, QString strPConstant, int resolution, int startTime, int maxTime, int alfaConst);
};

#endif // MAINCONTROL_H
