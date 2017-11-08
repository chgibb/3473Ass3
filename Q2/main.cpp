#include <iostream>
#include <fstream>

#include "bankers.hpp"

int main(int argc,char*argv[])
{
    int processes = 0;
    int resources = 0;
    std::ifstream inFile(argv[1],std::ios::in);
    {
        std::string lineStr;
        std::getline(inFile,lineStr);
        char*line = (char*)lineStr.c_str();
        char*split = std::strtok(line," ");
        processes = std::atoi(split);
        split = std::strtok(NULL," ");
        resources = std::atoi(split);
    }

    Comp3473Ass3::Bankers bankers(processes,resources);
    bankers.loadFromStream<std::ifstream>(inFile);

    bool isSafe = bankers.isSafe();
    if(isSafe)
        std::cout<<"Safe state"<<std::endl;
    else
        std::cout<<"Unsafe state"<<std::endl;
    
    return 0;
}