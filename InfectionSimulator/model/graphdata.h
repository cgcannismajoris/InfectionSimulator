#ifndef GRAPHDATA_H
#define GRAPHDATA_H

#include <QVector>

class graphData
{
    public:
        //static QString X_NAME = "Infectados";
        //static QString Y_NAME = "Tempo";

    private:
        QVector<double> *X, *Y;
        int maxX;
        int maxY;

        int curveLimitY;
        int curveLimitX;

    public:
        graphData(QVector<double> *x, QVector<double> *y, int maxX, int maxY, int curveLimitX, int curveLimitY);
        ~graphData();

        QVector<double> getX();
        QVector<double> getY();

        int getMaxX();
        int getMaxY();
};

#endif // GRAPHDATA_H
