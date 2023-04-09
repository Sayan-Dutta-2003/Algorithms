/*
Write a C/C++ program to perform quick sort on an integer
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

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j = low;
    for (   ; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            complexity+=3;
            i++;
            swap(&arr[j], &arr[i]);
        }
        complexity++;
    }
    i++;
    swap(&arr[high], &arr[i]);

    complexity+=2;
    return i;
}

void quick_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int i = partition(arr, low, high);
        quick_sort(arr, low, i - 1);
        quick_sort(arr, i + 1, high);
        complexity+=3;
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

    printf("Before Sorting: ");

    for (int i = 0; i < size; i++)
    {
        complexity++;
        printf("%d\t", i[arr]);
    }

    quick_sort(arr, 0, size - 1);

    printf("\nAfter Sorting: ");
    for (int i = 0; i < size; i++)
    {
        complexity++;
        printf("%d\t", *(arr + i));
    }

    printf("Time Complexity: %d", complexity);

    return 0;
}