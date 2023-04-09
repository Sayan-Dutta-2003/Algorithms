/*
Write a C/C++ program to perform insertion sort on an integer
array to sort it in ascending order and compute the time
complexity for an input of size N.
*/

#include <stdio.h>
#include <stdlib.h>

static int complexity = 0;

int *insertionSort(int *arr, int size)
{
    int key, j;
    for(int i = 1; i < size; i++)
    {
        key = arr[i];
        for(j = i - 1; j >= 0; j--)
        {
            if(arr[j] > key)
            {
                complexity+=2;
                arr[j + 1] = arr[j];
            }
            else{
                complexity++;
                break;
            }
            complexity++;
        }
        arr[j + 1] = key;
        complexity++;
    }
    complexity++;
    return arr;
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

    for(int i = 0; i < size; i++)
    {
        complexity++;
        printf("%d\t", arr[i]);
    }


    arr = insertionSort(arr, size);


    printf("\nAfter Sorting: ");
    for(int i = 0; i < size; i++)
    {
        complexity++;
        printf("%d\t", *(arr + i));
    }    

    printf("\nTime Complexity: %d", complexity);

    return 0;
}