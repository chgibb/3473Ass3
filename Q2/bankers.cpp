#include "bankers.hpp"

::Bankers::Bankers(int processes,int resources) : processes(processes),resources(resources)
{
    this->requiredResources = new int[processes][resources];
}

::Bankers::~Bankers()
{
    delete[] this->maxResources;
    delete[] this->allocatedResources;
    delete[] this->availResources;
}