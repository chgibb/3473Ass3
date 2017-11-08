//Adapted from http://javaingrab.blogspot.ca/2013/06/implementation-of-bankers-algorithm.html

#include "bankers.hpp"

void Comp3473Ass3::Bankers::setMatrix(std::vector<std::vector<int>>&matrix,std::vector<int>&con)
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

void Comp3473Ass3::Bankers::setAvailableMatrix(std::vector<int>&con)
{
    int k = 0;
    for(int i = 0; i < this->resources; ++i)
    {
        this->availResources[0][i] = con[k];
        ++k;
    }
}

bool Comp3473Ass3::Bankers::isSafe()
{
    this->calculateRequired();
    bool done[this->processes];
    int j = 0;
    while(j < this->processes)
    {
        bool allocated = false;
        for(int i = 0; i < this->processes; ++i)
        {
            if(!done[i] || check(i))
            {
                for(int k = 0; k < this->resources; ++k)
                {
                    this->availResources[0][k] = this->availResources[0][k] - this->requiredResources[i][k] + this->maxResources[i][k];
                }
                allocated = true;
                done[i] = true;
                ++j;
            }
            if(!allocated)
                break;
        }
    }
    if(j == this->processes)
        return true;
    else
        return false;
}

std::vector<std::vector<int>>&Comp3473Ass3::Bankers::calculateRequired()
{
    for(int i = 0; i < this->processes; ++i)
    {
        for(int j = 0; j < this->resources; ++j)
        {
            this->requiredResources[i][j] = this->maxResources[i][j] - this->allocatedResources[i][j];
        }
    }
    return this->requiredResources;
}

bool Comp3473Ass3::Bankers::check(int i)
{
    for(int j = 0; j < this->resources; ++j)
    {
        if(this->availResources[0][j] < this->requiredResources[i][j])
            return false;
    }
    return true;
}

Comp3473Ass3::Bankers::Bankers() = default;

Comp3473Ass3::Bankers::Bankers(int processes,int resources) : processes(processes),resources(resources)
{
    this->constructMatrices(processes,resources);
}

void Comp3473Ass3::Bankers::constructMatrices(int processes,int resources)
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

Comp3473Ass3::Bankers::~Bankers() = default;