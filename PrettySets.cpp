/******************************************************
Find number of pretty sets for a given set of numbers.

Example: Input set [10, 7, 3, 2, 1]
Pretty sets: For each number find number of ways this 
number can be formed by adding rest of the numbers in
the set.
For 10: [7, 3], [7, 2, 1]
For 7: Not possible
For 3: [2, 1]
For 2, 1: Not possible
So, number of pretty sets = 3 (2 for 10 and 1 or 3)
******************************************************/
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int findTargetSum(unsigned int target, int pos, vector<unsigned int> arr, set<unsigned int>& inSet, int& foundSets)
{
    // Condition to end recursion
    if(pos == arr.size() || target == 0)
        return 0;

    // This will end up in double count
    if(inSet.find(target-arr.at(pos+1)) != inSet.end())
        foundSets++;

    for(int i=pos+1; i<arr.size()-1; i++)
    {   
        findTargetSum(target-arr.at(i), i, arr, inSet, foundSets);
    }   

    return 0;
}

int findPrettySets(vector<unsigned int> arr, set<unsigned int>& inSet)
{
    int setsFound = 0;

    for(int i=0; i < arr.size()-1; i++)
        findTargetSum(arr.at(i), i, arr, inSet, setsFound);

    cout << "Pretty Sets: " << (setsFound/2) << endl;
    return (setsFound / 2); 
}

int main()
{
    //Assumpiton: array is sorted in descending order
    int myints[] = {10, 7, 4, 3, 2, 1}; 
    vector<unsigned int> inVec(myints, myints+sizeof(myints)/sizeof(unsigned int));
    // Copy in set for quick lookup
    set<unsigned int> inSet(myints, myints+sizeof(myints)/sizeof(unsigned int));

    findPrettySets(inVec, inSet);

    return 0;
}
