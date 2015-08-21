#ifndef VIRUSRESISTANCE_H
#define VIRUSRESISTANCE_H

#include "graphdata.h"
#include "virusspread.h"
#include <math.h>

class virusResistance
{

    private:
        double alfaConst;
        virusSpread *spread;

    public:
        virusResistance(int alfaConst, virusSpread *spread);

        //Realiza o cálculo referente ao tempo recebido.
        orderedPair *processOnTime(double time);

        //Gets e sets (Auxiliam no Encapsulamento)
        double getAlfaConst();
        void setAlfaConst(double alfaConst);

};

#endif // VIRUSRESISTANCE_H
