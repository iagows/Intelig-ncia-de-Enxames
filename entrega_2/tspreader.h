#ifndef TSPREADER_H
#define TSPREADER_H

#include <string>
#include <vector>
class TSPReader
{
public:
    TSPReader(std::string fileName);

    //lê o arquivo e gera um vetor com as posições. Leia dois a dois.
    std::vector<int> *getPositions();

private:
    std::string fileName;

    // trim o lado esquerdo
    std::string &ltrim(std::string &s);

    // trim o lado direito
    std::string &rtrim(std::string &s);

    // trim os dois lados
    std::string &trim(std::string &s);

    // passando -1 como parâmetro submatch index, faz o split
    std::vector<std::string> split(const std::string& input, const std::string& regex);

    bool is_number(const std::string& s);
};

#endif // TSPREADER_H
