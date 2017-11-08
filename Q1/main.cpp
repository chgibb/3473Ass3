/*
    The program will take in the path to a file with the processes to run and the path to a file
    to output results to.
*/
#include <fstream>
#include <cstring>
#include "roundrobin.hpp"

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
    //take exactly 2 arguments
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

    //disallow taking input from and outputting to the same file
    if(std::strcmp(argv[1],argv[2]) == 0)
    {
        std::cerr<<"Input and output cannot be the same file"<<std::endl;
        return 1;
    }

    std::ifstream inFile(argv[1],std::ios::in);

    Comp3473Ass3::RoundRobin rr;

    //populate processes for round robin from input file
    rr.loadFromStream<std::ifstream>(inFile);
    inFile.close();

    //run round robin
    rr.runQueueWithProcesses();

    std::ofstream outFile(argv[2],std::ios::out);

    //output results
    rr.printProcessStats<std::ofstream>(outFile);
    return 0;
}