/*
Write a C/C++ program to build a heap using heapify and use
it to perform heap sort, also compute the time complexity for an
input of size N.
*/

#include<stdio.h>
#include<stdlib.h>

static int complexity = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    complexity+=3;
}

void Max_heapify(int *arr, int size, int i)
{
    int largest = i; 

    int left = 2 * i;

    int right = (2 * i) + 1;

    if(left <= size && arr[left] > arr[largest])
    {
        complexity+=3;
        largest = left;
    }

    if(right <= size && arr[right] > arr[largest])
    {
        complexity+=3;
        largest = right;
    }

    if(largest != i)
    {
        swap(&arr[largest], &arr[i]);

        Max_heapify(arr, size, largest);
        complexity+=2;
    }
}

void heap_sort(int *arr, int size)
{

    for(int i = (size / 2); i >= 1; i--)
    {
        complexity++;
        Max_heapify(arr, size, i);
    }

    for(int i = size; i >= 1; i--)
    {
        complexity++;
        swap(&arr[1], &arr[i]);

        Max_heapify(arr, i, 1);
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

    printf("Before Sorting:\n");

    for (int i = 0; i < size; i++)
    {
        complexity++;
        printf("%d\t", i[arr]);
    }

    heap_sort(arr, size);

    printf("\nAfter Sorting:\n");
    for (int i = 0; i < size; i++)
    {
        complexity++;
        printf("%d\t", *(arr + i));
    }

    printf("\nTime Complexity: %d", complexity);

    return 0;
}