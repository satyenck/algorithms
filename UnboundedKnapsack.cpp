/************************************************
Unbounded knapsack algorithm in the form of
cake thief.
Input: Vector of cakes (weight, value). 
       Bag capacity in terms of weight
Output: Find the max value that can be 
        filled up with cakes in the bag
************************************************/
#include <iostream>
#include <vector>

using namespace std;

struct CakeType
{
    int weight;
    int value;
};

long long maxValue(int bagCapacity, vector<CakeType>& cakeTypes)
{
    vector<long long> maxValAtCap(bagCapacity+1);

    for(int currentCap = 0; currentCap <= bagCapacity; currentCap++)
    {   
        long long curMaxVal = 0;
        vector<CakeType>::iterator it;
        for(it=cakeTypes.begin(); it!=cakeTypes.end(); it++)
        {       
            CakeType cake = *it; 

            if(cake.weight <= currentCap) 
            {           
                long long maxValWithCake = cake.value + maxValAtCap[currentCap - cake.weight]; 
                curMaxVal = max(maxValWithCake,curMaxVal);
            }           
        }       

        maxValAtCap[currentCap] = curMaxVal;
    }   

    return maxValAtCap[bagCapacity];

}

int main()
{
    CakeType cake1 = {1,5};
    CakeType cake2 = {2,7};
    CakeType cake3 = {3,10};
    CakeType cake4 = {4,25};
    CakeType cake5 = {5,20};
    CakeType cake6 = {6,13};
    CakeType cake7 = {7,21};

    CakeType cakes[] = {cake1, cake2, cake3, cake4, cake5, cake6, cake7};

    vector<CakeType> cakeTypes(cakes, cakes+sizeof(cakes)/sizeof(CakeType));

    long long ret;

    ret = maxValue(7, cakeTypes);
    cout << "Max Bag Value: " << ret << endl;
    return 0;
}
