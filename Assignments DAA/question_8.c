/*
Write a C/C++ program to perform merge sort on an integer
array to sort it in ascending order and compute the time
complexity for an input of size N.
*/
#include <stdio.h>
#include <malloc.h>

static int complexity = 0;

void merge(int arr[], int low, int mid, int high)
{
    int size1 = mid - low + 1;
    int size2 = high - mid;

    int *arr1 = (int *)malloc(sizeof(int) * size1);
    int *arr2 = (int *)malloc(sizeof(int) * size2);
    
    // Copying arr[] elements in arr1[] and arr2[]
    for (int i = low; i <= mid; i++)
    {
        complexity++;
        arr1[i - low] = arr[i];
    }

    for (int j = mid + 1; j <= high; j++)
    {
        complexity++;
        arr2[j - (mid + 1)] = arr[j];
    }

    // Merging Elements from arr1[] and arr2[] to arr[]
    int i = 0, j = 0, k = low;
    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
        {
            complexity+=2;
            arr[k++] = arr1[i++];
        }
        else
        {
            complexity++;
            arr[k++] = arr2[j++];
        }
        complexity++;
    }

    // Merging Remaining Elements from arr1[] and arr2[] to arr[]
    for (   ; i < size1; i++)
    {
        complexity++;
        arr[k++] = arr1[i];
    }
    for (   ; j < size2 ; j++)
    {
        complexity++;
        arr[k++] = arr2[j];
    }
}

void mergeSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
        complexity+=4;
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

    mergeSort(arr, 0, size - 1);

    printf("\nAfter Sorting: ");
    for (int i = 0; i < size; i++)
    {
        complexity++;
        printf("%d\t", *(arr + i));
    }

    printf("\nTime Complexity: %d", complexity);

    return 0;
}