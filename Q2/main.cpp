#include <iostream>

#include "bankers.hpp"

int main(int argc,char*argv[])
{
    ::Bankers bankers(5,4);
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
    return 0;
}