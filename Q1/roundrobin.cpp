#include <stdexcept>
#include <list>
#include "roundrobin.hpp"
void ::RoundRobin::initForRun()
{
    this->ticks = 0;
    this->procQueue.clear();
    this->notArrived.clear();
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
                this->notArrived.push_back(&(*it));
            }
        }
        this->notArrived.sort([this](::Process*&a,::Process*&b) -> bool{
            return a->arrivalTime < b->arrivalTime;
        });
    }
    if(this->procQueue.size() == 0)
        throw std::runtime_error("At least one process must have an arrival time of 0");
}

void ::RoundRobin::preemptRunningProcess()
{
    ::Process*runningProc;
    runningProc = &(*this->procQueue.front());
    this->procQueue.pop_front();
    this->procQueue.push_back(runningProc);
}

void ::RoundRobin::runQueueWithProcesses()
{
    this->initForRun();
    ::Process*running;
    running = &(*this->procQueue.front());
    int ticksSinceLastPreempt = 0;
    while(this->procQueue.size() != 0 && this->notArrived.size() != 0)
    {
        if(this->notArrived.front()->arrivalTime == this->ticks)
        {
            this->procQueue.push_back(&(*this->notArrived.front()));
            this->notArrived.pop_front();
        }
        if(ticksSinceLastPreempt == this->timeQuantum)
        {
            this->preemptRunningProcess();
        }
        this->ticks++;
        ticksSinceLastPreempt++;
    }
}

::RoundRobin::RoundRobin() = default;