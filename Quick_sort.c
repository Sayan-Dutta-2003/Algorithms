#include <stdio.h>
#include <malloc.h>

void swap(int *arr1, int *arr2)
{
    int temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
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
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    i++;
    swap(&arr[high], &arr[i]);

    return i;
}

void quick_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int i = partition(arr, low, high);
        quick_sort(arr, low, i - 1);
        quick_sort(arr, i + 1, high);
    }
}

int main()
{
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

    quick_sort(arr, 0, size - 1);

    printf("\nAfter Sorting:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", *(arr + i));
    }

    return 0;
}
