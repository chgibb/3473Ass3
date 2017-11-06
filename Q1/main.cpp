#include <iostream>
#include <fstream>
#include <cstring>
#include "roundrobin.hpp"
int main(int argc,char*argv[])
{
    if(argc < 3)
    {
        std::cerr<<"Insufficient arguments"<<std::endl;
        return 1;
    }
    if(argc > 3)
    {
        std::cerr<<"Too many arguments"<<std::endl;
        return 1;
    }
    if(std::strcmp(argv[1],argv[2]) == 0)
    {
        std::cerr<<"Input and output cannot be the same file"<<std::endl;
        return 1;
    }
    std::ifstream inFile(argv[1],std::ios::in);

    ::RoundRobin rr;

    rr.loadFromStream<std::ifstream>(inFile);
    inFile.close();

    rr.runQueueWithProcesses();

    std::ofstream outFile(argv[2],std::ios::out);

    rr.printProcessStats<std::ofstream>(outFile);
    return 0;
}