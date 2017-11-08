#pragma once
#include <vector>

/**
 * @brief 
 * 
 * Adapted from http://javaingrab.blogspot.ca/2013/06/implementation-of-bankers-algorithm.html
 * 
 */
class Bankers
{
    public:
        std::vector<std::vector<int>> maxResources;
        std::vector<std::vector<int>> allocatedResources;
        std::vector<std::vector<int>> availResources;
        std::vector<std::vector<int>> requiredResources;

        void setMatrix(std::vector<std::vector<int>>&,std::vector<int>&);
        void setAvailableMatrix(std::vector<int>&);
        bool isSafe();
        Bankers(int,int);
        ~Bankers();

    private:
        int processes = 0;
        int resources = 0;

        std::vector<std::vector<int>>&calculateRequired();
        bool check(int);
};