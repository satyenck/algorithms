/*****************************************************
Find if one string is permutation of other
*****************************************************/
#include <string>
#include <iostream>

using namespace std;

bool isPerm(string& s1, string& s2)
{
    if(s1.length() != s2.length())
        return false;

    int arr[30] = {0};
    for(int i=0; i<s1.length(); i++)
        arr[s1[i] - 'a']++;     

    for(int i=0; i<s2.length(); i++)
        arr[s2[i] - 'a']--; 

    for(int i=0; i < 30; i++)
        if(arr[i] < 0)
            return false;

    return true;    
}

int main(void)
{
    string s1("thisis");
    string s2("isthis");
    string s3("sthisa");

    cout << "S1, S2: " << isPerm(s1, s2) << endl;
    cout << "S1, S3: " << isPerm(s1, s3) << endl;
    return 0;
}
