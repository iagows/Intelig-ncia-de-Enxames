#include "abc.h"
#include <iostream>
#include <fstream>

void write(AlgorithmFactory::ALGORITHM alg, std::string fileName)
{
    int colonySize = 30;
    int dim = 30;
    int epoch = 10000;
    int loops = 30;
    int campeira = colonySize/2;
    int escudeira = colonySize*2;


    std::vector<double> *end = new std::vector<double>(epoch, 0.0);
    for(int i=0; i<loops; ++i)
    {
        std::cout << "Loop: " << i << std::endl;
        ABC abc(colonySize, campeira, escudeira, dim, epoch, alg);
        abc.initialize();
        std::vector<double> *out = abc.search();

        for(int j=0; j<epoch; j++)
        {
            end->at(j) += out->at(j);
        }

        delete out;
    }

    std::ofstream file;
    file.open(fileName.c_str());

    for(double d: *end)
    {
        file << (d/loops) << "\n";
    }

    file.close();

    delete end;
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    //write(AlgorithmFactory::SPHERE, "esfera_abc.csv");
    //write(AlgorithmFactory::ROSENBROCK, "rosenbrock_abc.csv");
    write(AlgorithmFactory::ROTATED_RASTRIGIN, "rastrigin_abc.csv");

    return 0;
}
