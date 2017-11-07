#pragma once

/**
 * @brief 
 * 
 * Represents a process to be run in the round robin algorithm
 * 
 */
class Process
{
    public:
        /**
         * @brief 
         * 
         * PID
         * 
         */
        int id = 0;

        /**
         * @brief 
         * 
         * Priority level
         * 
         */
        int priority = 0;

        /**
         * @brief 
         * 
         * Required time to run
         * 
         */
        int burstTime = 0;

        /**
         * @brief 
         * 
         * Time to arrive in the queue at
         * 
         */
        int arrivalTime = 0;

        /**
         * @brief 
         * 
         * Total time waiting to be run after arrival
         * 
         */
        int waitingTime = 0;

        /**
         * @brief 
         * 
         * Total time being run
         * 
         */
        int aroundTime = 0;
        
        Process();
};