#include <cstdlib>
#include <iostream>

#include <fstream>
#include "fss.h"

void write(AlgorithmFactory::ALGORITHM alg, std::string fileName)
{
    int fishAmount = 30;
    int dim = 30;
    int epoch = 1500;

    int mean = 30;

    std::vector<double> *output = new std::vector<double>(epoch, 0);

    for(int i=0; i<mean; ++i)
    {
        std::cout << "it: " << i << std::endl;
        FSS *f = new FSS(fishAmount, dim, epoch, alg);
        std::vector<double>* vec = f->work();

        for(int j=0; j<epoch; ++j)
        {
            output->at(j) += vec->at(j);
        }
        delete vec;
        delete f;
    }

    std::ofstream file;
    file.open(fileName.c_str());

    for(double d: *output)
    {
        file << (d/mean) << "\n";
    }

    file.close();

    delete output;
}
int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    write(AlgorithmFactory::SPHERE, "esfera.csv");
    write(AlgorithmFactory::ROTATED_RASTRIGIN, "rastrigin.csv");
    write(AlgorithmFactory::ROSENBROCK, "rosenbrock.csv");

    //system("shutdown -s");
    return EXIT_SUCCESS;
}
