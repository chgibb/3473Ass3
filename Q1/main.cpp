#include <iostream>
#include <fstream>
#include "roundrobin.hpp"
int main(int argc,char*argv[])
{
    std::ifstream file("sample.txt",std::ios::in);

    ::RoundRobin rr;

    rr.loadFromStream<std::ifstream>(file);
    file.close();

    rr.runQueueWithProcesses();
    return 0;
}