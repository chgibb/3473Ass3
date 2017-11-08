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
            /**
             * @brief 
             * 
             * Maximum number of resources
             * 
             */
            std::vector<std::vector<int>> maxResources;

            /**
             * @brief 
             * 
             * Currently allocated resources
             * 
             */
            std::vector<std::vector<int>> allocatedResources;

            /**
             * @brief 
             * 
             * Currently available resources
             * 
             */
            std::vector<std::vector<int>> availResources;

            /**
             * @brief 
             * 
             * Currently required resources
             * 
             */
            std::vector<std::vector<int>> requiredResources;

            /**
             * @brief 
             * 
             * Initialize the matrix using the provided vector
             * 
             * @param  
             * @param  
             */
            void setMatrix(std::vector<std::vector<int>>&,std::vector<int>&);

            /**
             * @brief 
             * 
             * Initialize the available matrix using the provided vector
             * 
             * @param  
             */
            void setAvailableMatrix(std::vector<int>&);

            /**
             * @brief 
             * 
             * Evaluate the currently loaded system for safety
             * 
             * @return true 
             * @return false 
             */
            bool isSafe();

            /**
             * @brief 
             * 
             * Initialize the system using the provided stream
             * 
             * @tparam T 
             * @param stream 
             * @return true 
             * @return false 
             */
            template <class T>
            bool loadFromStream(T&stream)
            {
                this->setProcessesAndResourcesFromStream<decltype(stream)>(stream);
                this->constructMatrices(this->processes,this->resources);

                std::vector<int> streamMatrix = this->getMatrixFromStream<decltype(stream)>(stream);
                this->setMatrix(this->allocatedResources,streamMatrix);

                streamMatrix = this->getMatrixFromStream<decltype(stream)>(stream);
                this->setMatrix(this->maxResources,streamMatrix);

                streamMatrix = this->getAvailableMatrixFromStream<decltype(stream)>(stream);
                this->setAvailableMatrix(streamMatrix);
            }
            Bankers();
            Bankers(int,int);
            ~Bankers();

        private:
            /**
             * @brief 
             * 
             * The number of processes in the system
             * 
             */
            int processes = 0;

            /**
             * @brief 
             * 
             * The number of resource types in the system
             * 
             */
            int resources = 0;

            /**
             * @brief 
             * 
             * Construct system matrices using the provided dimensions
             * 
             * @param  
             * @param  
             */
            void constructMatrices(int,int);

            /**
             * @brief 
             * 
             * Determine the number of required resources at any given time
             * 
             * @return std::vector<std::vector<int>>& 
             */
            std::vector<std::vector<int>>&calculateRequired();

            /**
             * @brief 
             * 
             * Check the allocatability of a given process by index
             * 
             * @param  
             * @return true 
             * @return false 
             */
            bool check(int);

            /**
             * @brief 
             * 
             * Determine process number and resource types from the provided stream
             * 
             * @tparam T 
             * @param stream 
             */
            template<class T>
            void setProcessesAndResourcesFromStream(T&stream)
            {
                std::string lineStr;
                std::getline(stream,lineStr);
                char*line = (char*)lineStr.c_str();
                char*split = std::strtok(line," ");
                this->processes = std::atoi(split);
                split = std::strtok(NULL," ");
                this->resources = std::atoi(split);
            }

            /**
             * @brief 
             * 
             * Read processxresources matrix from the provided stream
             * 
             * @tparam T 
             * @param stream 
             * @return std::vector<int> 
             */
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

            /**
             * @brief 
             * 
             * Read an availability matrix from the provided stream
             * 
             * @tparam T 
             * @param stream 
             * @return std::vector<int> 
             */
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