#include "tspreader.h"

#include <fstream>
#include <algorithm>
#include <regex>
TSPReader::TSPReader(std::string fileName)
{
    this->fileName = fileName;
}

std::vector<int> *TSPReader::getPositions()
{
    std::ifstream file(this->fileName);
    std::string line;

    std::vector<int> *output = new std::vector<int>();
    while(std::getline(file, line))
    {
        line = trim(line);

        std::vector<std::string> _line = split(line, " ");
        int lineSize = _line.size();
        if(lineSize==3)
        {
            _line.erase(_line.begin());
            std::string test = _line.at(0);
            if(is_number(test))
            {
                for(int i=0; i<lineSize-1; ++i)
                {
                    test = _line.at(i);
                    int value = std::stoi(test);
                    output->push_back(value);
                }
            }
        }
    }

    return output;
}

std::string &TSPReader::ltrim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

std::string &TSPReader::rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

std::string &TSPReader::trim(std::string &s)
{
    return ltrim(rtrim(s));
}

std::vector<std::string> TSPReader::split(const std::string &input, const std::string &regex)
{
    std::regex re(regex);
    std::sregex_token_iterator first{input.begin(), input.end(), re, -1}, last;
    return {first, last};
}

bool TSPReader::is_number(const std::string &s)
{
    return !s.empty() && std::find_if(s.begin(),
                                      s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}
