/*****************************************
Fibonacci series program with memoization.
This is non recursive.
*****************************************/

#include <stdio.h>

int fib(int n)
{
    if((n==0) || (n==1))
        return n;   

    int fibArray[100];
    fibArray[0] = 0;
    fibArray[1] = 1;
    int a = 0;  
    int b = 1;
    int c = a + b;
    for(int i=2; i<n; i++)
    {   
        fibArray[i] = fibArray[i-1] + fibArray[i-2];

        a = b;  
        b = c;  
        c = a+b;
    }   

    printf("C: %d, b: %d, a: %d \n", c, b, a); 
    for(int i=0; i < n; i++)
        printf("fibArray[%d]: %d ,", i, fibArray[i]);

    return c;
}

int main()
{
    fib(10);
    return 0;
}
