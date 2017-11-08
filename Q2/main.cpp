#include <iostream>
#include <fstream>

#include "bankers.hpp"

int main(int argc,char*argv[])
{
  /*  Comp3473Ass3::Bankers bankers(5,4);
    std::vector<int> allocMatrix{
        2,0,0,1,
        3,1,2,1,
        2,1,0,3,
        1,3,1,2,
        1,4,3,2
    };

    std::vector<int> maxMatrix{
        4,2,1,2,
        5,2,5,2,
        2,3,1,6,
        1,4,2,4,
        3,6,6,5
    };

    std::vector<int> availMatrix{
        3,3,2,1
    };

    bankers.setMatrix(bankers.allocatedResources,allocMatrix);
    bankers.setMatrix(bankers.maxResources,maxMatrix);
    bankers.setAvailableMatrix(availMatrix);

    bool isSafe = bankers.isSafe();
    if(isSafe)
        std::cout<<"Safe state"<<std::endl;
    else
        std::cout<<"Unsafe state"<<std::endl;*/

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