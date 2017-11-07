#pragma once

class Bankers
{

    public:
        int*maxResources;
        int*allocatedResources;
        int*availResources;
        int*requiredResources;
        Bankers(int,int);
        ~Bankers();
    private:
        int processes = 0;
        int resources = 0;
};