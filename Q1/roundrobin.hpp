#pragma once
#include <list>
#include <string>
#include <cstring>
#include <iostream>
#include "process.hpp"

/**
 * @brief 
 * 
 * Singleton to load and run repeated round robins
 * 
 */
class RoundRobin
{
    public:
        /**
         * @brief 
         * 
         * All processes to run
         * 
         */
        std::list<::Process> processes;

        /**
         * @brief 
         * 
         * Processes being run
         * 
         */
        std::list<::Process*> procQueue;

        /**
         * @brief 
         * 
         * Time quantum to preempt at
         * 
         */
        int timeQuantum;

        /**
         * @brief 
         * 
         * Total number of ticks run
         * 
         */
        int ticks;
        
        /**
         * @brief 
         * 
         * Populates the process list reading from stream
         * 
         * @param stream 
         * @return bool
         */
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

        /**
         * @brief 
         * 
         * Writes property names and values for all processes to stream
         * 
         * @param stream 
         */
        template <class T>
        void printProcessStats(T&stream)
        {
            auto procEnd = this->processes.end();
            for(auto it = this->processes.begin(); it != procEnd; ++it)
            {
                stream<<"id: "<<it->id<<std::endl;
                stream<<"   priority: "<<it->priority<<std::endl;
                stream<<"   burst time: "<<it->burstTime<<std::endl;
                stream<<"   arrival time: "<<it->arrivalTime<<std::endl;
                stream<<"   waiting time: "<<it->waitingTime<<std::endl;
                stream<<"   around time: "<<it->aroundTime<<std::endl;
            }
        }

        /**
         * @brief 
         * 
         * Run the round robin algorithm
         * 
         */
        void runQueueWithProcesses();

        RoundRobin();
    private:
        /**
         * @brief 
         * 
         * All processes which have not yet arrived
         * 
         */
        std::list<::Process*> notArrived;

        /**
         * @brief 
         * 
         * Prepare for a fresh run of the algorithm
         * 
         */
        void initForRun();

        /**
         * @brief 
         * 
         * Preempt the currently running process
         * 
         */
        void preemptRunningProcess();

        /**
         * @brief 
         * 
         * Increment the waiting time on all waiting processes
         * 
         */
        void incrementWaitingTimes();
};