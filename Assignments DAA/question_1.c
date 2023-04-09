/* 1.	Write a C/C++ program to print Fibonacci series up 
to nth term using iteration also compute time complexity.*/

#include <stdio.h>
static int complexity = 0;

int main() {
    int n, i;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int first = 0, second = 1;
    printf("Fibonacci Series: ");
    
    for (i = 0; i < n; i++) {
        complexity++;
        printf("%d ", first);
        int next = first + second;
        first = second;
        second = next;
        complexity+=4;
        
    }
    printf("\nTime Complexity: %d", complexity);
    return 0;
}

