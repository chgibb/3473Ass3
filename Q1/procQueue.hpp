#pragma once
#include <list>
#include "process.hpp"
class ProcQueue
{
    public:
        std::list<Process*> processes;

        ProcQueue();
};