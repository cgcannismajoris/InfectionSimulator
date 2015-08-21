#include "maincontrol.h"

using namespace std;

mainControl::mainControl()
{
}

mainControl::~mainControl(){

}

graphData *mainControl::processVirusSpread(QString strNumOfPeople, QString strPConstant, int resolution, int startTime, int maxTime){

    long int numOfPeople = strNumOfPeople.toLong();
    double porpContant = strPConstant.toDouble();

    unsigned long int counter;
    double xCoordinate;

    long int pointCounter = 0;

    //Instancia o objeto responsável pelo cálculo dos dados.
    virusSpread *spread;

    //Instancia a estrutura de dados responsável pelo armazenamento.
    //x -> Tempo (Domínio)
    //y -> Quantidade de pessaos infectadas (Imagem)
    QVector<double> *x, *y;

    //ponto temporário
    orderedPair *tmpPoint;

    //Dados do gráfico que serão passados para a interface
    graphData *graph;

    //Se inseriu dados inválidos
    if(numOfPeople < 0 || porpContant < 0 || maxTime < 0){
        return (0);
    }

    //Tudo OK...
    x = new QVector<double>(maxTime * resolution);
    y = new QVector<double>(maxTime * resolution);
    spread = new virusSpread(numOfPeople, porpContant);

    //Gera os pontos
    for(counter = startTime; counter < (unsigned int)maxTime; counter++){
        for(xCoordinate = counter, pointCounter = pointCounter; xCoordinate < (counter + 1) && pointCounter < maxTime * resolution; xCoordinate += (1.0/(double)resolution), pointCounter++){

            //Calcula a quantidade de infectados no tempo xCoordinate
            tmpPoint = spread->processOnTime(xCoordinate);

            (*x)[pointCounter] = tmpPoint->getX();
            (*y)[pointCounter] = tmpPoint->getY();

            tmpPoint->~orderedPair();
        }
    }

    //Instancia o objeto a ser passado para a interface
    graph = new graphData(x, y, maxTime, numOfPeople + 2, numOfPeople + 1, -1);

    return (graph);
}

graphData *mainControl::processVirusResistance(QString strNumOfPeople, QString strPConstant, int resolution, int startTime, int maxTime, int alfaConst){

    long int numOfPeople = strNumOfPeople.toLong();
    double porpContant = strPConstant.toDouble();

    unsigned long int counter;
    double xCoordinate;

    long int pointCounter = 0;

    //Instancia o objeto responsável pelo cálculo dos dados.
    virusResistance *resistance;

    //Instancia a estrutura de dados responsável pelo armazenamento.
    //x -> Tempo (Domínio)
    //y -> Quantidade de pessaos infectadas (Imagem)
    QVector<double> *x, *y;

    //ponto temporário
    orderedPair *tmpPoint;

    //Dados do gráfico que serão passados para a interface
    graphData *graph;

    //Se inseriu dados inválidos
    if(numOfPeople < 0 || porpContant < 0 || maxTime < 0){
        return (0);
    }

    //Tudo OK...
    x = new QVector<double>(maxTime * resolution);
    y = new QVector<double>(maxTime * resolution);
    resistance = new virusResistance(alfaConst, new virusSpread(numOfPeople, porpContant));

    //Gera os pontos
    for(counter = startTime; counter < (unsigned int)maxTime; counter++){
        for(xCoordinate = counter, pointCounter = pointCounter; xCoordinate < (counter + 1) && pointCounter < maxTime * resolution; xCoordinate += (1.0/(double)resolution), pointCounter++){

            //Calcula a quantidade de infectados no tempo xCoordinate
            tmpPoint = resistance->processOnTime(xCoordinate);

            (*x)[pointCounter] = tmpPoint->getX();
            (*y)[pointCounter] = tmpPoint->getY();

            tmpPoint->~orderedPair();

            //resistance->setAlfaConst(resistance->getAlfaConst() + resistance->getAlfaConst());
        }
    }

    //Instancia o objeto a ser passado para a interface
    graph = new graphData(x, y, maxTime, numOfPeople + 2, numOfPeople + 1, -1);

    return (graph);
}
