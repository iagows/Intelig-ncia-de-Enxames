#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "pso_simples.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_bt_work_clicked();

    void on_bt_triple_clicked();

private:
    Ui::MainWindow *ui;

    Pso_simples* ps;

    void initPlotter();

    void plot(std::vector<double> *means, int graphNum, AlgorithmFactory::ALGORITHM alg);

    void addToPlot(std::vector<double> *x, std::vector<double> *y, int graphNum, AlgorithmFactory::ALGORITHM alg);
};

#endif // MAINWINDOW_H
