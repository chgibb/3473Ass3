#pragma once
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
namespace Comp3473Ass3
{
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
            template <class T>
            bool loadFromStream(T&stream)
            {
                std::vector<int> streamMatrix = this->getMatrixFromStream<decltype(stream)>(stream);
                this->setMatrix(this->allocatedResources,streamMatrix);

                streamMatrix = this->getMatrixFromStream<decltype(stream)>(stream);
                this->setMatrix(this->maxResources,streamMatrix);

                streamMatrix = this->getAvailableMatrixFromStream<decltype(stream)>(stream);
                this->setAvailableMatrix(streamMatrix);
            }
            Bankers(int,int);
            ~Bankers();

        private:
            int processes = 0;
            int resources = 0;

            std::vector<std::vector<int>>&calculateRequired();
            bool check(int);
            template<class T>
            std::vector<int> getMatrixFromStream(T&stream)
            {
                std::vector<int> res;

                std::string lineStr;
                for(int i = 0; i != this->processes+1; ++i)
                {
                    char*split = nullptr;
                    char*line = nullptr;

                    std::getline(stream,lineStr);
                    line = (char*)lineStr.c_str();
                    split = std::strtok(line," ");

                    if(split)
                        res.push_back(std::atoi(split));
                        
                    for(int j = 0; j != this->resources; ++j)
                    {
                        split = std::strtok(NULL," ");
                        if(split)
                            res.push_back(std::atoi(split));
                    }
                }
                return res;
            }

            template<class T>
            std::vector<int> getAvailableMatrixFromStream(T&stream)
            {
                std::vector<int> res;

                std::string lineStr;
                char*split = nullptr;
                char*line = nullptr;

                std::getline(stream,lineStr);

                line = (char*)lineStr.c_str();
                split = std::strtok(line," ");

                if(split)
                    res.push_back(std::atoi(split));
                else
                    return this->getAvailableMatrixFromStream<decltype(stream)>(stream);
                for(int i = 0; i != this->resources; ++i)
                {
                    split = std::strtok(NULL," ");
                    if(split)
                        res.push_back(std::atoi(split));
                }
                return res;
            }
    };
}