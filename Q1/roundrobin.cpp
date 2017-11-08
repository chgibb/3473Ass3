#ifdef LOGRUNNINGQUEUE
    #include <iostream>
#endif
#include <stdexcept>
#include <list>
#include "roundrobin.hpp"

void Comp3473Ass3::RoundRobin::initForRun()
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
        this->notArrived.sort([this](Comp3473Ass3::Process*&a,Comp3473Ass3::Process*&b) -> bool{
            return a->arrivalTime < b->arrivalTime;
        });
        #ifdef LOGRUNNINGQUEUE
            for(auto it = this->notArrived.begin(); it != this->notArrived.end(); ++it)
            {
                std::cout<<"id "<<(*it)->id<<" arrival "<<(*it)->arrivalTime<<std::endl;
            }
        #endif
    }
    if(this->procQueue.size() == 0)
        throw std::runtime_error("At least one process must have an arrival time of 0");
}

void Comp3473Ass3::RoundRobin::preemptRunningProcess()
{
    Comp3473Ass3::Process*runningProc;
    runningProc = &(*this->procQueue.front());
    #ifdef LOGRUNNINGQUEUE
        std::cout<<"preempting "<<runningProc->id<<std::endl;
    #endif
    this->procQueue.pop_front();
    this->procQueue.push_back(runningProc);
}

void Comp3473Ass3::RoundRobin::incrementWaitingTimes()
{
    if(this->procQueue.size() == 1)
        return;
    auto procEnd = this->procQueue.end();
    for(auto it = this->procQueue.begin(); it != procEnd; ++it)
    {
        if(&(*it) != &this->procQueue.front())
            (*it)->waitingTime++;
    }
}

void Comp3473Ass3::RoundRobin::runQueueWithProcesses()
{
    this->initForRun();
    Comp3473Ass3::Process*running;
    int ticksSinceLastPreempt = 0;
    while(!this->notArrived.empty() || !this->procQueue.empty())
    {
        this->ticks++;
        this->incrementWaitingTimes();
        if(!this->notArrived.empty() && this->notArrived.front()->arrivalTime == this->ticks)
        {
            this->procQueue.push_back(&(*this->notArrived.front()));
            this->notArrived.pop_front();
        }
        if(!this->procQueue.empty())
        {
            running = &(*this->procQueue.front());
            #ifdef LOGRUNNINGQUEUE
                std::cout<<"running "<<running->id<<" ticks "<<this->ticks<<std::endl;
            #endif
            running->aroundTime++;
        }
        else
        {
            #ifdef LOGRUNNINGQUEUE
                std::cout<<"running nothing ticks"<<this->ticks<<std::endl;
            #endif
            continue;
        }

        if(ticksSinceLastPreempt >= this->timeQuantum)
        {
            if(running->aroundTime >= running->burstTime)
            {
                #ifdef LOGRUNNINGQUEUE
                    std::cout<<"removing "<<running->id<<std::endl;
                #endif
                this->procQueue.pop_front();
            }
            else
            {
                this->preemptRunningProcess();
            }
            ticksSinceLastPreempt = 0;

        }
        else
            ticksSinceLastPreempt++;

    }
    #ifdef LOGRUNNINGQUEUE
        std::cout<<"finished at "<<this->ticks<<std::endl;
    #endif
}

Comp3473Ass3::RoundRobin::RoundRobin() = default;