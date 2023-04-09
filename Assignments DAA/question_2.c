/*
2.	Write a C/C++ program to print Fibonacci series up to nth term using 
recursion also compute the time complexity in terms of input size.
*/

#include<stdio.h>

static int complexity = 0;

int fibo(int n, int a, int b)
{
    if (n == 0 || n == 1)
    {
        complexity+=2;
        return b;
    }
    else
    {
        complexity+=2;
        printf("%d\t", a + b);
        fibo(n - 1, b, a + b);
    }
}

int main()
{
    printf("%d\t%d\t", 0, 1);
    fibo(5, 0, 1);
    complexity+=2;

    printf("\nTime Complexity: %d", complexity);
    return 0;
}