/*
Write a C/C++ program to perform count sort on an integer
array to sort it in ascending order and compute the time
complexity for an input of size N.
*/

#include<stdio.h>
#include<stdlib.h>

static int complexity = 0;

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        complexity++;
        printf("%d\t", arr[i]);
    }
}

void count_sort(int *arr, int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if(max < arr[i])
        {
            complexity+=2;
            max = arr[i];
        }
        complexity++;
    }

    int *count = (int*)calloc((max + 1), sizeof(int));

    int *brr = (int*)malloc(size * sizeof(int));
    
    for (int i = 0; i < size; i++)
    {
        complexity++;
        count[arr[i]]++;
    }

    for(int i = 1; i <= max; i++)
    {
        complexity++;
        count[i] += count[i - 1];
    }

    for(int i = size - 1; i >= 0; i--)
    {
        complexity++;
        brr[--count[arr[i]]] = arr[i];
    }

    for(int i = 0; i < size; i++)
    {
        complexity++;
        arr[i] = brr[i];
    }
    
}


int main(){
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    printf("Enter %d elements in the array: ", size);

    for (int i = 0; i < size; i++)
    {
        complexity++;
        scanf("%d", &arr[i]);
    }

    printf("Before Sorting: ");
    printArray(arr, size);

    count_sort(arr, size);

    printf("\nAfter Sorting: ");
    printArray(arr, size);

    printf("Time Complexity: %d", complexity);

    return 0;
}