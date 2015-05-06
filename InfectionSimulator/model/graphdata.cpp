#include "graphdata.h"

graphData::graphData(QVector<double> *x, QVector<double> *y, int maxX, int maxY, int curveLimitX, int curveLimitY){
    this->X = x;
    this->Y = y;

    this->maxX = maxX;
    this->maxY = maxY;

    this->curveLimitX = curveLimitX;
    this->curveLimitY = curveLimitY;
}

graphData::~graphData(){
    this->X->~QVector();
    this->Y->~QVector();
}

QVector<double> graphData::getX(){
    return (*X);
}

QVector<double> graphData::getY(){
    return (*Y);
}

int graphData::getMaxX(){
    return (this->maxX);
}

int graphData::getMaxY(){
    return (this->maxY);
}
