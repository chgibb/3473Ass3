#pragma once
class Process
{
    public:
        int id = 0;
        int priority = 0;
        int burstTime = 0;
        int arrivalTime = 0;

        int waitingTime = 0;
        int aroundTime = 0;
        
        Process();
};