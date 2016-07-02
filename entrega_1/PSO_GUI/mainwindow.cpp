#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ps = new Pso_simples();

    double count = 1;
    while((count+1)>1)
    {
        count /= 2;
    }
    this->ui->lb_conf->setText(QString::number(count, 'e', 25));

    initPlotter();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ps;
}

#include <sstream>
#include <iomanip>
void MainWindow::on_bt_work_clicked()
{
    double time = 0;

    int run, part, dim, epoch;
    run = this->ui->sb_times->value();
    part = this->ui->sb_part->value();
    dim = this->ui->sb_dim->value();
    epoch = this->ui->sb_loop->value();

    TopologyFactory::TOPOLOGY top = static_cast<TopologyFactory::TOPOLOGY>(this->ui->cb_top->currentIndex());
    AlgorithmFactory::ALGORITHM alg = static_cast<AlgorithmFactory::ALGORITHM>(this->ui->cb_alg->currentIndex());
    VelocityFactory::TYPE vel = static_cast<VelocityFactory::TYPE>(this->ui->cb_vel->currentIndex());

    std::vector<double>* means = ps->getMean(time, run, part, dim, epoch, top, alg, vel);

    std::stringstream ss;
    for(int i=0, size=means->size(); i<size; ++i)
    {
        ss << std::setprecision(20) << means->at(i) << " ";
        std::cout<<means->at(i)<<std::endl;
    }
    plot(means, (int)alg, alg);
    delete means;

    this->ui->plainTextEdit->setPlainText(QString::fromStdString(ss.str()));
    this->ui->le_time->setText(QString::number(time) + " segundos.");
}

void MainWindow::on_bt_triple_clicked()
{
    double time = 0;

    int run, part, dim, epoch;
    run = this->ui->sb_times->value();
    part = this->ui->sb_part->value();
    dim = this->ui->sb_dim->value();
    epoch = this->ui->sb_loop->value();

    TopologyFactory::TOPOLOGY top = static_cast<TopologyFactory::TOPOLOGY>(this->ui->cb_top->currentIndex());
    VelocityFactory::TYPE vel = static_cast<VelocityFactory::TYPE>(this->ui->cb_vel->currentIndex());

    double tripleTime=0;
    for(int j=0; j<3; ++j)
    {
        AlgorithmFactory::ALGORITHM alg = static_cast<AlgorithmFactory::ALGORITHM>(j);
        std::vector<double>* means = ps->getMean(time, run, part, dim, epoch, top, alg, vel);

        std::stringstream ss;
        for(int i=0, size=means->size(); i<size; ++i)
        {
            ss << std::setprecision(20) << means->at(i) << " ";
            //std::cout<<means->at(i)<<std::endl;
        }
        plot(means, j, alg);
        delete means;

        //this->ui->plainTextEdit->setPlainText(QString::fromStdString(ss.str()));
        tripleTime+=time;
    }
    this->ui->le_time->setText(QString::number(tripleTime) + " segundos.");

}

void MainWindow::initPlotter()
{
    QCustomPlot *cp = this->ui->plotter;
    cp->addGraph();
    cp->addGraph();
    cp->addGraph();
    cp->xAxis->setLabel("Epoch");
    cp->yAxis->setLabel("fitness");
    cp->graph(0)->setPen(QPen(Qt::blue));
    cp->graph(1)->setPen(QPen(Qt::red));
    cp->graph(2)->setPen(QPen(Qt::green));
    cp->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    cp->setLocale(QLocale(QLocale::Portuguese, QLocale::Brazil));
    cp->legend->setVisible(true);
}

void MainWindow::plot(std::vector<double>* means, int graphNum, AlgorithmFactory::ALGORITHM alg)
{
    int runs = this->ui->sb_loop->value();

    std::vector<double>* _x = new std::vector<double>();
    for(int i=0; i<runs; ++i)
    {
        _x->push_back(i);
    }

    this->addToPlot(_x, means, graphNum, alg);

    delete _x;
}

void MainWindow::addToPlot(std::vector<double> *x, std::vector<double> *y, int graphNum, AlgorithmFactory::ALGORITHM alg)
{
    QCustomPlot *cp = this->ui->plotter;

    QVector<double> __x = QVector<double>::fromStdVector(*x);
    QVector<double> __y = QVector<double>::fromStdVector(*y);

    cp->graph(graphNum)->setData(__x, __y);
    switch (alg)
    {
    default:
    case AlgorithmFactory::SPHERE:
        cp->graph(graphNum)->setName("Esfera");
        break;
    case AlgorithmFactory::ROTATED_RASTRIGIN:
        cp->graph(graphNum)->setName("Rot Rastrigin");
        break;
    case AlgorithmFactory::ROSENBROCK:
        cp->graph(graphNum)->setName("Rosenbrock");
        break;
    }
    cp->rescaleAxes(true);

    cp->replot();
}
