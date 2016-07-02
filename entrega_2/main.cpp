#include "aco.h"
#include <fstream>
#include <iostream>

std::vector<int> simulation(double alpha, double beta, int q, double rho, bool useQ=false,
                                         std::string loadFrom="att48.tsp", int epoch=500, int times=30);

void write(std::vector<int> input, std::string outputFile);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    //3.1
    //alfa = 1, beta 0.5
    write(simulation(1, 0.5, 100, 0.3), "01 1 0.5");
    //alfa 1, beta 1
    write(simulation(1, 1, 100, 0.3), "02 1 1");
    //alfa 1, beta 3
    write(simulation(1, 3, 100, 0.3), "03 1 3");
    //alfa 3, beta 0.5
    write(simulation(3, 0.5, 100, 0.3), "04 3 0.5");
    //alfa 3, beta 1
    write(simulation(3, 1, 100, 0.3), "05 3 1");
    //alfa 3, beta 3
    write(simulation(3, 3, 100, 0.3), "06 3 3");

    //3.2
    //rho 0.3 q 1
    write(simulation(1, 1, 1, 0.3, true), "07 0.3 1");
    //rho 0.3 q 100
    write(simulation(1, 1, 100, 0.3, true), "08 0.3 100");
    //rho 0.3 q 10000
    write(simulation(1, 1, 10000, 0.3, true), "09 0.3 10000");
    //rho 0.5 q 1
    write(simulation(1, 1, 1, 0.5, true), "10 0.5 1");
    //rho 0.5 q 100
    write(simulation(1, 1, 100, 0.5, true), "11 0.5 100");
    //rho 0.5 q 10000
    write(simulation(1, 1, 10000, 0.5, true), "12 0.5 10000");
    //rho 0.9 q 1
    write(simulation(1, 1, 1, 0.9, true), "13 0.9 1");
    //rho 0.9 q 100
    write(simulation(1, 1, 100, 0.9, true), "14 0.9 100");
    //rho 0.9 q 10000
    write(simulation(1, 1, 10000, 0.9, true), "15 0.9 10000");

    return 1;
}

std::vector<int> simulation(double alpha, double beta, int q, double rho, bool useQ,
                                         std::string loadFrom, int epoch, int times)
{
    std::vector<std::vector<int>> out;
    for(int i=0; i<times; ++i)
    {
        std::cout << "Iteracao: " << i << std::endl;
        ACO *aco = new ACO(alpha, beta, q, rho, loadFrom, useQ, epoch*0.04);
        std::vector<int> r = aco->run(epoch);
        out.push_back(r);
        delete aco;
    }
    std::vector<int> mean(25);

    for(int i=0; i<times; ++i)
    {
        std::vector<int> atI = out.at(i);
        for(int j=0, size=atI.size(); j<size; ++j)
        {
            mean.at(j) += atI.at(j);
        }
    }
    for(int b =0, size = mean.size(); b<size; ++b)
    {
        mean.at(b) /= times;
    }
    return mean;
}

void write(std::vector<int> input, std::string outputFile)
{
    std::ofstream os;
    os.open(outputFile+".csv");
    for(int i=0, size=input.size(); i<size; ++i)
    {
        os << input.at(i) << ",";
    }
    os.close();
}
