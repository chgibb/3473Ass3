#pragma once
#include <vector>

class Bankers
{
    public:
        std::vector<std::vector<int>> maxResources;
        std::vector<std::vector<int>> allocatedResources;
        std::vector<std::vector<int>> availResources;
        std::vector<std::vector<int>> requiredResources;

        void setMatrix(std::vector<std::vector<int>>&,std::vector<int>&);
        void setAvailableMatrix(std::vector<int>&);
        Bankers(int,int);
        ~Bankers();
        
    private:
        int processes = 0;
        int resources = 0;
};