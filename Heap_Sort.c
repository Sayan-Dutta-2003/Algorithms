#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Max_heapify(int *arr, int size, int i)
{
    int largest = i; // Initializing largest as root

    int left = 2 * i;

    int right = (2 * i) + 1;

    if(left <= size && arr[left] > arr[largest])
    {
        largest = left;
    }

    if(right <= size && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(&arr[largest], &arr[i]);

        Max_heapify(arr, size, largest);
    }
}

void heap_sort(int *arr, int size)
{
    // Building Max Heap
    for(int i = (size / 2); i >= 1; i--)
    {
        Max_heapify(arr, size, i);
    }

    // Heap Sort (Deleting Elements from max heap)
    for(int i = size; i >= 1; i--)
    {
        swap(&arr[1], &arr[i]);

        Max_heapify(arr, i, 1);
    }
}

int main(){
    int size;
    printf("Enter the size of array\n");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    printf("Enter %d elements in the array\n", size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Before Sorting:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d\t", i[arr]);
    }

    heap_sort(arr, size);

    printf("\nAfter Sorting:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", *(arr + i));
    }
    return 0;
}
