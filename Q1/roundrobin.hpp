#pragma once
#include <list>
#include <string>
#include <cstring>
#include <iostream>
#include "process.hpp"
class RoundRobin
{
    public:
        std::list<::Process> processes;
        std::list<::Process*> procQueue;
        int timeQuantum;
        int ticks;
        
        template<class T>
        bool loadFromStream(T&stream)
        {
            int processes = 0;
            std::string lineStr;
            std::getline(stream,lineStr);
            char*line = (char*)lineStr.c_str();
            {
                char*split;
                split = std::strtok(line," ");
                processes = std::atoi(split);

                split = std::strtok(NULL," ");
                this->timeQuantum = std::atoi(split);
            }
            for(int i = 0; i != processes; ++i)
            {
                std::getline(stream,lineStr);
                line = (char*)lineStr.c_str();
                {
                    char*split;
                    ::Process proc;
                    split = std::strtok(line," ");
                    proc.id = std::atoi(split);
                    split = std::strtok(NULL," ");
                    proc.priority = std::atoi(split);
                    split = std::strtok(NULL," ");
                    proc.burstTime = std::atoi(split);
                    split = std::strtok(NULL," ");
                    proc.arrivalTime = std::atoi(split);
                    this->processes.push_back(proc);
                }
            }
            return true;
        }
        void runQueueWithProcesses();
        RoundRobin();
    private:
        std::list<::Process*> notArrived;
        void initForRun();
};