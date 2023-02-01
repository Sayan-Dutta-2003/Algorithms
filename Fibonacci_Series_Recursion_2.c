#include <stdio.h>

static int complexity = 0;

int fibonacci(int n)
{
    if (n <= 0)
    {
        complexity += 2;
        return 0;
    }
    
    if (n == 1)
    {
        complexity += 2;
        return 1;
    }

    complexity++;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", fibonacci(i));
        complexity++;
    }

    printf("\nTime Complexity: %d\n", complexity);
    
    return 0;
}
