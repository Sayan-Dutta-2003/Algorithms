/*
Write a C/C++ program to perform selection sort on an integer
array to sort it in ascending order and compute the time
complexity for an input of size N.
*/

#include <stdio.h>
#include <malloc.h>

static int complexity = 0;

void swap(int *arr1, int *arr2)
{
    int temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
    complexity+=3;
}

void selectionSort(int *arr, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int min_Index = i;
        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[min_Index])
            {
                complexity+=2;
                min_Index = j;
            }
            complexity++;
        }
        if(min_Index != i)
        {
            complexity+=2;
            swap(&arr[i], &arr[min_Index]);
        }
        complexity++;
    }
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        complexity++;
        printf("%d\t", arr[i]);
    }

}

int main()
{
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

    printf("Before sorting: ");
    printArray(arr, size);
    selectionSort(arr, size);
    printf("\nAfter sorting: ");
    printArray(arr, size);

    printf("\nTime Complexity: %d", complexity);

    return 0;

}