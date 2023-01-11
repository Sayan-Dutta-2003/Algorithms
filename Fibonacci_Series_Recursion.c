#include <stdio.h>

// 1st Method

int fibo(int n, int a, int b)
{
    if (n == 0 || n == 1)
    {
        return b;
    }
    else
    {
        // int k1 = fibo(n - 1);
        // int k2 = fibo(n - 2);
        // int s = k1 + k2;
        // printf("%d\t", s);
        // k1 = k2;
        // k2 = s;
        // return s;
        printf("%d\t", a + b);
        fibo(n - 1, b, a + b);
    }
}

int main()
{
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d\t", fibo(i));
    // }
    printf("%d\t%d\t", 0, 1);
    fibo(5, 0, 1);
    return 0;
}

// 2nd Method

#include <stdio.h>

int fibo(int n, int a, int b)
{
    if (n == 0 || n == 1)
    {
        return b;
    }
    else
    {
        // int k1 = fibo(n - 1);
        // int k2 = fibo(n - 2);
        // int s = k1 + k2;
        // printf("%d\t", s);
        // k1 = k2;
        // k2 = s;
        // return s;
        printf("%d\t", a + b);
        fibo(n - 1, b, a + b);
    }
}

void printfFibo(int n)
{
    if(n == 0)
        printf("%d", n);
    else if(n == 1)
        printf("%d\t%d\t", 0, 1);
    else
    {
        int a = 0;
        int b = 1;
        printf("%d", a);
        printf("%d", b);
        fibo(n, a, b);
    }
}

int main()
{
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d\t", fibo(i));
    // }
    // printf("%d\t%d\t", 0, 1);
    fibo(5, 0, 1);
    printfFibo(5);
    return 0;
}
