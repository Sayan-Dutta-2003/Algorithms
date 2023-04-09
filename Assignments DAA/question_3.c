/*
3.	Write a C/C++ program using linear search to search
an element in an array also compute time complexity for an input of size N.*/

#include <stdio.h>
#include <stdlib.h>

static int complexity = 0;

int linear_Search(int *arr, int element, int size)
{
    for (int i = 0; i < size; i++)
    {
        complexity++;
        if (arr[i] == element)
        {
            complexity+=2;
            return i;
        }
    }
    complexity++;
    return -1;
    
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

    int search;
    printf("Enter the element you want to search: ");
    scanf("%d", &search);

    int found = linear_Search(arr, search, size);
    complexity+=1;

    if (found == -1)
    {
        printf("Not Found\n");
        complexity+=2;
    }
    else
    {
        printf("Element %d found at index %d\n", search, found);
        complexity++;
    }
    printf("Time Complexity: %d", complexity);

    return 0;
}