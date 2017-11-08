/*
    The program will take in the path to a file to read matrices for the Banker's algorithm from.
    It will then evaluate if the system is safe.
*/
#include <iostream>
#include <fstream>

#include "bankers.hpp"

/**
 * @brief 
 * 
 * Main entry
 * 
 * @param argc 
 * @param argv[] 
 * @return int 
 */
int main(int argc,char*argv[])
{
    //take exactly 1 argument
    if(argc < 2)
    {
        std::cerr<<"Insufficient arguments"<<std::endl;
        return 1;
    }

    if(argc > 2)
    {
        std::cerr<<"Too many arguments"<<std::endl;
        return 1;
    }

    std::ifstream inFile(argv[1],std::ios::in);

    //load system from file
    Comp3473Ass3::Bankers bankers;
    bankers.loadFromStream<std::ifstream>(inFile);

    //evaluate and print safety
    bool isSafe = bankers.isSafe();
    if(isSafe)
        std::cout<<"Safe state"<<std::endl;
    else
        std::cout<<"Unsafe state"<<std::endl;
    
    return 0;
}