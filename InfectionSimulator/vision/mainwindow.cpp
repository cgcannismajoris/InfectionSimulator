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

void MainWindow::updateGraph(){
    graphData *graph = this->control->process(this->ui->leQtdPeoples->text(), this->ui->leProporcionalityConstant->text(), this->ui->hsResolution->value(), this->ui->sbMaxTime->value());

    //Remove o gráfico atual
    this->ui->qcPlotGraph->clearGraphs();

    //Adiciona um novo gráfico com os pontos gerados
    this->ui->qcPlotGraph->addGraph();
    this->ui->qcPlotGraph->graph(0)->setData(graph->getX(), graph->getY());


    //Dá nome aos eixos
    this->ui->qcPlotGraph->xAxis->setLabel("Tempo");
    this->ui->qcPlotGraph->yAxis->setLabel("Infectados");

    //Seta os limites de exibição do gráfico
    this->ui->qcPlotGraph->xAxis->setRange(0, graph->getMaxX());
    this->ui->qcPlotGraph->yAxis->setRange(0, graph->getMaxY());

    this->ui->qcPlotGraph->replot();
}

void MainWindow::requestSavePng(){
    QString fileName = QFileDialog::getSaveFileName(
                this,
                "Save document...",
                qApp->applicationDirPath(), "*.png");

    if (!fileName.isEmpty())
    {
        //ui->plot->savePng(fileName, 0, 0, 1.0, -1);
        this->ui->qcPlotGraph->savePng(fileName, 0, 0, 1.0, -1);
    }
}

void MainWindow::on_checkBox_toggled(bool checked)
{

    //Se deseja processar, chama o controle.
    if(checked){
        this->updateGraph();
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

    this->ui->qcPlotGraph->clearGraphs();
    this->ui->qcPlotGraph->replot();
}

void MainWindow::on_hsResolution_valueChanged(int value)
{
    if(this->ui->cbRealTime->isChecked()){
        this->updateGraph();
    }
}

void MainWindow::on_sbMaxTime_valueChanged(int arg1)
{
    if(this->ui->cbRealTime->isChecked()){
        this->updateGraph();
    }
}

void MainWindow::on_actionSalvar_triggered()
{
    this->requestSavePng();
}
