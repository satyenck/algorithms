/**********************************************
Highest product of any 3 numbers from a
sequence of integer numbers. Number can be 
+ve or -ve
**********************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int highestProduct(vector<int>& v)
{
        int highest, lowest, highest3, highest2, lowest2, current;

        if(v.size()<3)
        {
                cout << "Provide proper input..." << endl;
                return 0;
        }

        highest = max(v[0], v[1]);
        lowest = min(v[0], v[1]);

        highest2 = v[0]*v[1];
        lowest2 = v[0]*v[1];
        highest3 = v[0]*v[1]*v[2];

        for(int i=2; i<v.size(); i++)
        {
                current = v[i];

                highest3 = max(max(highest3, current*highest2), current*lowest2);
                highest2 = max(max(highest2, current*highest), current*lowest);
                lowest2 = min(min(lowest2, current*lowest), current*highest);
                highest = max(current, highest);
                lowest = min(current, lowest);
        }

        cout << "Highest Product: " << highest3 << endl;
        return highest3;
}

int main()
{
        int a[] = {-10, 10, 1, 3, 2, 20, 6};
        vector<int> v(a, a+sizeof(a)/sizeof(int));

        int prod = highestProduct(v);
        return 0;
}
