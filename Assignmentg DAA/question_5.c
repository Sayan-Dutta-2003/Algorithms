/*
Write a C/C++ program to perform bubble sort on an integer
array to sort it in ascending order and compute the time
complexity for an input of size N.
*/

#include<stdio.h>
#include<stdlib.h>

static int complexity = 0;

void printArray(int *arr, int n)
{
    for (int i = 0; i < n ; i++)
    {
        complexity++;
        printf("%d ", arr[i]);
    }
    
}

void bubbleSort(int *arr, int size)
{
    int temp;
    int isSorted;
    for (int i = 0; i < size - 1; i++) // For number of Pass
    {
        isSorted = 1;
        for (int j = 0; j < size - 1 - i; j++) // For comparison in each Pass
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0;
                complexity+=4;
            }
            complexity++;
        }
        if (isSorted)
        {
            complexity+=2;
            return;
        } 
        complexity++;
    }
    
}


int main()
{
    
    int *arr, size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    arr = (int*)malloc(sizeof(int) * size);
    printf("Enter %d elements in the array: ", size);
    for(int i = 0; i < size; i++)
    {
        complexity++;
        scanf("%d", &arr[i]);
    }

    printf("\nArray before Sorting: ");
    printArray(arr, size);

    bubbleSort(arr, size);

    printf("\nArray after Sorting: ");
    printArray(arr, size);

    printf("\nTime Complexity: %d", complexity);

    return 0;
}