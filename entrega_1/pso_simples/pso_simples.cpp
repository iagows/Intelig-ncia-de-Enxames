#include "pso_simples.h"

#include <chrono>

Pso_simples::Pso_simples()
{
}

Pso_simples::~Pso_simples()
{

}

std::vector<double> *Pso_simples::getMean(double &time, int runs, int particles, int dimensions, int epoch,
                                          TopologyFactory::TOPOLOGY top,
                                          AlgorithmFactory::ALGORITHM alg,
                                          VelocityFactory::TYPE vel)
{
    std::vector<std::vector<double>*> *allFits = new std::vector<std::vector<double>*>();
    auto start = std::chrono::steady_clock::now();
    for(int i=0; i<runs; ++i)
    {
        Swarm* swarm = new Swarm(particles, dimensions, epoch, top, alg, vel);
        allFits->push_back(swarm->psoAlg());
        delete swarm;
    }
    auto end = std::chrono::steady_clock::now();
    time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()/1000.0;

    std::vector<double>* means = new std::vector<double>(epoch);
    for(int i=0; i<epoch; ++i)
    {
        double mean = 0;
        for(int j=0; j<runs; ++j)
        {
            mean += allFits->at(j)->at(i);
        }
        mean /= runs;
        means->at(i)=mean;
    }
    for(int i=0, size = allFits->size(); i<size; ++i)
    {
        std::vector<double>* v = allFits->at(i);
        delete v;
    }
    delete allFits;

    return means;
}


/**
 * Links
 * http://www.swarmintelligence.org/tutorials.php
 * http://www.sfu.ca/~ssurjano/rastr.html
 * https://books.google.com.br/books?id=BxSIrqGed9IC&pg=PA8&lpg=PA8&dq=pso+constriction+clerc&source=bl&ots=9vROyHc0cm&sig=K_WTHX9sn-dWtZ_HjAnpD1CteeI&hl=pt-BR&sa=X&ved=0ahUKEwjbzfPctIfMAhWGFZAKHcisCcEQ6AEIdDAI#v=onepage&q=pso%20constriction%20clerc&f=false
 * https://books.google.com.br/books?id=eRpaCwAAQBAJ&pg=PA282&lpg=PA282&dq=pso+focal+topology&source=bl&ots=hyOqombyVS&sig=mfkSNGETZthn-1rPr7eNEglWMiA&hl=pt-BR&sa=X&ved=0ahUKEwjh6-nbyYTMAhVBOSYKHdXSCr8Q6AEIHTAA#v=onepage&q=pso%20focal%20topology&f=false
 * http://goanna.cs.rmit.edu.au/~xiaodong/cec13-lsgo/competition/cec2013-lsgo-benchmark-tech-report.pdf
 * http://tracer.uc3m.es/tws/pso/parameters.html
 * http://mnemstudio.org/particle-swarm-example-1.htm
 **/
