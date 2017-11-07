#pragma once
#include <vector>

class Bankers
{

    public:
        std::vector<std::vector<int>> maxResources;
        std::vector<std::vector<int>> allocatedResources;
        std::vector<std::vector<int>> availResources;
        std::vector<std::vector<int>> requiredResources;

        void setMatrix(std::vector<std::vector<int>>&matrix,std::vector<int>&con)
        {
            int k = 0;
            for(int i = 0; i < this->processes; ++i)
            {
                for(int j = 0; j < this->resources; ++j)
                {
                    matrix[i][j] = con[k];
                    ++k;
                }
            }
        }

        void setAvailableMatrix(std::vector<int>&con)
        {
            int k = 0;
            for(int i = 0; i < this->resources; ++i)
            {
                this->availResources[0][i] = con[k];
                ++k;
            }
        }

        Bankers(int,int);
        ~Bankers();
    private:
        int processes = 0;
        int resources = 0;
};