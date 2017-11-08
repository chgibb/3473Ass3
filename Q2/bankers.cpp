#include "bankers.hpp"

::Bankers::Bankers(int processes,int resources) : processes(processes),resources(resources)
{
    this->maxResources = std::vector<std::vector<int>>(
        this->processes,
        std::vector<int>(this->resources)
    );

    this->allocatedResources = std::vector<std::vector<int>>(
        this->processes,
        std::vector<int>(this->resources)
    );

    this->maxResources = std::vector<std::vector<int>>(
        this->processes,
        std::vector<int>(this->resources)
    );

    this->availResources = std::vector<std::vector<int>>(
        1,
        std::vector<int>(this->processes)
    );

    this->requiredResources = std::vector<std::vector<int>>(
        this->processes,
        std::vector<int>(this->resources)
    );

    
}

void ::Bankers::setMatrix(std::vector<std::vector<int>>&matrix,std::vector<int>&con)
{
    int k = 0;
    for(int i = 0; i < this->processes; ++i)
    {
        for(int j = 0; j < this->resources; ++j)
        {
            matrix[i][j] = con[k];
            ++k;
        }
    }
}

void ::Bankers::setAvailableMatrix(std::vector<int>&con)
{
    int k = 0;
    for(int i = 0; i < this->resources; ++i)
    {
        this->availResources[0][i] = con[k];
        ++k;
    }
}

::Bankers::~Bankers() = default;