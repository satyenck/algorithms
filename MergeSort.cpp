/******************************************
Merge sort of integer numbers
******************************************/

#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int>& arr)
{
    cout << "*** Print Array ***" << endl;
    for(int i=0; i<arr.size(); i++)
        cout << i << ": " << arr.at(i) << endl;
}

void merge(vector<int>& arr, int l, int m, int r)
{
    int n1 = l-m+1;
    int n2 = r-m;
    vector<int> al(n1);
    vector<int> ar(n2);
    int i, j, k = 0;

    for(i=0; i<(l-m+1); i++)
        al[i] = arr[l+i];

    for(j=0; j<(r-m); j++)
        al[j] = arr[m+j];

    i = 0; j = 0; k = l;
    while((i<n1) && (j<n2))
    {   
        if(al[i] < ar[j])
        {       
            arr[k] = al[i];
            i++;        
        }       
        else    
        {       
            arr[k] = ar[j];
            j++;        
        }       
        k++;    
    }   
    while(i<n1)
    {   
        arr[k] = al[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = ar[j];
        j++;
        k++;
    }
    return;
}

void mergeSort(vector<int>& arr, int l, int r)
{
    if(l < r)
    {
        int m = l + (r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
    return;
}

int main()
{
    int myarr[10] = {5,2,3,8,6,4,7,1,9,10};
    vector<int> myvec(myarr, myarr+sizeof(myarr)/sizeof(int));
    mergeSort(myvec, 0, 9);

    printArray(myvec);
    return 0;
}
