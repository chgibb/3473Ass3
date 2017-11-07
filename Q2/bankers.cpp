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

::Bankers::~Bankers() = default;