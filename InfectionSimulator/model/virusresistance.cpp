#include "virusresistance.h"

virusResistance::virusResistance(int alfaConst, virusSpread *spread){

    this->spread = spread;
    this->alfaConst = alfaConst;

}


orderedPair *virusResistance::processOnTime(double time){

    double quocient;
    double exponent;

    orderedPair *result = this->spread->processOnTime(time);

    exponent = (time / (double)this->alfaConst) * (double)(this->spread->getNumberOfPeople() + 1);
    quocient = exp(exponent);

    result->setY(result->getY() / quocient);

    return (result);
}

double virusResistance::getAlfaConst(){
    return (this->alfaConst);
}

void virusResistance::setAlfaConst(double alfaConst){
    this->alfaConst = alfaConst;
}
