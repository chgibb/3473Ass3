#pragma once
#include <list>
#include "process.hpp"
class RoundRobin
{
    public:
        std::list<Process> processes;
        int timeQuantum;

        template<class T>
        bool loadFromStream(T&stream)
        {
            return true;
        }
        
        RoundRobin();
};