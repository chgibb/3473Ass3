#pragma once
class Process
{
    public:
        int id;
        int priority;
        int burstTime;
        int arrivalTime;

        int waitingTime;
        int aroundTime;
        
        Process();
};