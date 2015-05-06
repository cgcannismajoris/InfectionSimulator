#ifndef VIRUSSPREAD_H
#define VIRUSSPREAD_H

#include "orderedPair.h"
#include <math.h>

class virusSpread
{

    private:
        unsigned long int numberOfPeople;
        double constOfProportionality;

    public:
        //Construtor
        virusSpread(unsigned long int numberOfPeople, double constantOfProportionality);

        //Realiza o cálculo referente ao tempo recebido.
        orderedPair *processOnTime(double time);

        //Gets e sets (Auxiliam no Encapsulamento)
        unsigned long int getNumberOfPeople();
        void   setNumberOfPeople(unsigned long int numberOfPeople);
        double getConstOfProportionality();
        void   setConstOfProportionality(double constant);
};

#endif // VIRUSSPREAD_H
