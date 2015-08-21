#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
        ui->setupUi(this);
}


MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::updateGraph(int startTime){

    //Remove os gráficos atuais
    this->ui->qcPlotGraph->clearGraphs();

    this->updateGraph_virusSpread(startTime);

    if(this->ui->cbResistance->isChecked() && (this->ui->sbAlphaConst->value() != 0))
        this->updateGraph_virusResistance(startTime);

    //Dá nome aos eixos
    this->ui->qcPlotGraph->xAxis->setLabel("Tempo");
    this->ui->qcPlotGraph->yAxis->setLabel("Infectados");

    this->ui->qcPlotGraph->replot();
}

void MainWindow::updateGraph_virusSpread(int startTime){

    graphData *graph = this->control->processVirusSpread(this->ui->leQtdPeoples->text(),
                                                         this->ui->leProporcionalityConstant->text(),
                                                         this->ui->hsResolution->value(), startTime,
                                                         this->ui->sbMaxTime->value());

    //Adiciona um novo gráfico com os pontos gerados
    this->ui->qcPlotGraph->addGraph();
    this->ui->qcPlotGraph->graph(0)->setData(graph->getX(), graph->getY());

    //Seta os limites de exibição do gráfico
    this->ui->qcPlotGraph->xAxis->setRange(0, graph->getMaxX());
    this->ui->qcPlotGraph->yAxis->setRange(0, graph->getMaxY());

    this->actualMaxTime = graph->getMaxX();

}

void MainWindow::updateGraph_virusResistance(int startTime){

    if(this->ui->qcPlotGraph->graphCount() > 1){
        graphData *graph = this->control->processVirusResistance(this->ui->leQtdPeoples->text(),
                                                                 this->ui->leProporcionalityConstant->text(),
                                                                 this->ui->hsResolution->value(), startTime,
                                                                 this->ui->sbMaxTime->value(),
                                                                 this->ui->sbAlphaConst->value());

        //Adiciona um novo gráfico com os pontos gerados
        this->ui->qcPlotGraph->addGraph();
        this->ui->qcPlotGraph->graph(1)->setData(graph->getX(), graph->getY());
        this->ui->qcPlotGraph->graph(1)->setPen(QPen(Qt::red));
    }
}

void MainWindow::requestSavePng(){

    QString fileName = QFileDialog::getSaveFileName(
                this,
                "Salvar Gráfico",
                qApp->applicationDirPath(), "*.png");

    if (!fileName.isEmpty()){
        this->ui->qcPlotGraph->savePng(fileName + ".png", 0, 0, 1.0, -1);
    }
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    //Se deseja processar, chama o controle.
    if(this->ui->checkBox->isChecked()){
        this->updateGraph(0);
    }
    else{
        this->ui->cbRealTime->setChecked(false);
        this->ui->cbResistance->setChecked(false);

        this->ui->qcPlotGraph->clearGraphs();
        this->ui->qcPlotGraph->replot();
    }
}

void MainWindow::on_pushButton_clicked()
{
    this->requestSavePng();
}

void MainWindow::on_pbClean_clicked()
{
    this->ui->leProporcionalityConstant->clear();
    this->ui->leQtdPeoples->clear();
    this->ui->sbMaxTime->setValue(1);
    this->ui->hsResolution->setValue(1);

    this->ui->checkBox->setChecked(false);
    this->ui->cbRealTime->setChecked(false);
    this->ui->cbResistance->setChecked(false);

    this->ui->qcPlotGraph->clearGraphs();
    this->ui->qcPlotGraph->replot();
}

void MainWindow::on_hsResolution_valueChanged(int value)
{
    if(this->ui->cbRealTime->isChecked()){
        this->updateGraph(0);
    }
}

void MainWindow::on_sbMaxTime_valueChanged(int arg1)
{
    if(this->ui->cbRealTime->isChecked()){
        this->updateGraph(0);
    }
}

void MainWindow::on_actionSalvar_triggered()
{
    this->requestSavePng();
}

void MainWindow::on_leProporcionalityConstant_textEdited(const QString &arg1)
{
    if(this->ui->cbRealTime->isChecked()){
        this->updateGraph(0);
    }
}

void MainWindow::on_leQtdPeoples_textEdited(const QString &arg1)
{
    if(this->ui->cbRealTime->isChecked()){
        this->updateGraph(0);
    }
}

void MainWindow::on_cbResistance_toggled(bool checked)
{
    if(checked){

        this->ui->sbAlphaConst->setDisabled(false);

        //Ativa o grafico
        this->updateGraph_virusResistance(0);
    }
    else{
        this->ui->sbAlphaConst->setDisabled(true);
        this->ui->qcPlotGraph->removeGraph(1);
    }

    this->ui->qcPlotGraph->replot();
}

void MainWindow::on_sbAlphaConst_valueChanged(int arg1)
{
    if(this->ui->cbRealTime->isChecked()){
        this->ui->qcPlotGraph->removeGraph(1);
        this->ui->qcPlotGraph->addGraph();
        this->updateGraph_virusResistance(0);
        this->ui->qcPlotGraph->replot();
        //this->updateGraph(0);
    }
}

void MainWindow::on_cbRealTime_toggled(bool checked)
{
    if(checked){
        this->updateGraph(0);
    }
}
