#include "virusspread.h"

virusSpread::virusSpread(unsigned long int numberOfPeople, double constantOfProportionality){
    this->numberOfPeople = numberOfPeople;
    this->constOfProportionality = constantOfProportionality;
}

orderedPair *virusSpread::processOnTime(double time){

    double exponent;
    double result;

    exponent = (double)(-1) * (double)(this->numberOfPeople + 1) * this->constOfProportionality * time;

    result = ((double)(this->numberOfPeople + 1)) / ((double)((this->numberOfPeople * exp(exponent)) + 1));

    orderedPair *pair = new orderedPair(time, result);

    return (pair);
}

unsigned long int virusSpread::getNumberOfPeople(){
    return (this->numberOfPeople);
}

void virusSpread::setNumberOfPeople(unsigned long int numberOfPeople){
    this->numberOfPeople = numberOfPeople;
}

double virusSpread::getConstOfProportionality(){
    return (this->constOfProportionality);
}

void virusSpread::setConstOfProportionality(double constant){
    this->constOfProportionality = constant;
}
