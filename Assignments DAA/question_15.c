/*
Write a C/C++ program to implement dynamic array. First take
maximum length of array from user input. Then start by creating
array of size 1, and start taking input. Every time the array is full,
double its capacity. Use amortize analysis (aggregate) to calculate
time complexity of the program.
*/

#include <stdio.h>
#include <stdlib.h>

static int complexity = 0;

int main()
{
    int size = 1, capacity = 1;
    int *arr = (int *)malloc(capacity * sizeof(int));
    printf("Enter the elements of the array (enter any non-integer character to stop):\n");
    int i = 0, x;
    while (i < size && scanf("%d", &x) == 1)
    {
        arr[i++] = x;
        if (i == capacity)
        {
            capacity *= 2;
            printf("Memory reallocated to double the capacity: %d\n", capacity);
            arr = (int *)realloc(arr, capacity * sizeof(int));
            complexity += 4;
        }
        complexity++;
    }
    while (scanf("%d", &x) == 1)
    {
        if (i == capacity)
        {
            capacity *= 2;
            printf("Memory reallocated to double the capacity: %d\n", capacity);
            arr = (int *)realloc(arr, capacity * sizeof(int));
            complexity += 4;
        }
        arr[i++] = x;
        complexity++;
    }
    printf("The elements of the array are:\n");
    for (int j = 0; j < i; j++)
    {
        printf("%d ", arr[j]);
        complexity++;
    }
    free(arr);

    printf("\nAverage Cost of the this Program: %d", complexity / i );
    return 0;
}
