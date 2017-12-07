/*******************************************
Quick sort of interger numbers
*******************************************/

#include <iostream>

using namespace std;

void printArray(int arr[], int size)
{
    cout << "*****PrintArray****" << endl;
    for(int i=0; i<size; i++)
        cout << i << " : " << arr[i] << endl;
}

int partition(int arr[], int left, int right)
{
    int pivot = arr[(left+right)/2];

    while(left <= right)
    {   
        while(arr[left] < pivot) left++; 
        while(arr[right] > pivot) right--;

        if(left <= right)
        {       
            int tmp = arr[left];
            arr[left] = arr[right]; 
            arr[right] = tmp;
            left++;     
            right--;    
        }       
    }   

    return left;
}

void quickSort(int arr[], int left, int right)
{
    int index = partition(arr, left, right);

    if(left < index-1)
        quickSort(arr, left, index-1);

    if(right > index)
        quickSort(arr, index, right); 

}

int main()
{
    int arr[] = {1,10,5,6,8,2,7,4,3,9};
    printArray(arr, 10);
    quickSort(arr, 0, 9);
    printArray(arr, 10);
    return 0;
}
