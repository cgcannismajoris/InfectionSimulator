#include "orderedPair.h"

orderedPair::orderedPair(double x, double y){
    this->xComponent = x;
    this->yComponent = y;
}

orderedPair::~orderedPair(){

}

double orderedPair::getX(){
    return (this->xComponent);
}

void orderedPair::setX(double xComponent){
    this->xComponent = xComponent;
}

double orderedPair::getY(){
    return (this->yComponent);
}

void orderedPair::setY(double yComponent){
    this->yComponent = yComponent;
}

void orderedPair::swap(){
    double tmp = this->xComponent;
    this->xComponent = this->yComponent;
    this->yComponent = tmp;
}
