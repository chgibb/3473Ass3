#include <stdexcept>
#include "roundrobin.hpp"
void ::RoundRobin::runQueueWithProcesses()
{
    int ticks = 0;
    this->procQueue.clear();
    {
        auto procEnd = this->processes.end();
        for(auto it = this->processes.begin(); it != procEnd; ++it)
        {
            if(it->arrivalTime == 0)
            {
                this->procQueue.push_back(&(*it));
            }
        }
    }
    if(this->procQueue.size() == 0)
        throw std::runtime_error("At least one process must have an arrival time of 0");
}

::RoundRobin::RoundRobin() = default;