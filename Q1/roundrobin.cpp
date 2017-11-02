#include <stdexcept>
#include <list>
#include "roundrobin.hpp"
void ::RoundRobin::runQueueWithProcesses()
{
    int ticks = 0;
    this->procQueue.clear();
    std::list<::Process*> notArrived;
    {
        auto procEnd = this->processes.end();
        for(auto it = this->processes.begin(); it != procEnd; ++it)
        {
            if(it->arrivalTime == 0)
            {
                this->procQueue.push_back(&(*it));
            }
            else
            {
                notArrived.push_back(&(*it));
            }
        }
        notArrived.sort([this](::Process*&a,::Process*&b) -> bool{
            return a->arrivalTime < b->arrivalTime;
        });
    }
    if(this->procQueue.size() == 0)
        throw std::runtime_error("At least one process must have an arrival time of 0");
}

::RoundRobin::RoundRobin() = default;