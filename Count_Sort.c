#include<stdio.h>
#include<stdlib.h>

void count_sort(int *arr, int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }

    int *count = (int*)calloc((max + 1), sizeof(int));

    int *brr = (int*)malloc(size * sizeof(int));
    
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

    for(int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    for(int i = size - 1; i >= 0; i--)
    {
        brr[--count[arr[i]]] = arr[i];
    }

    for(int i = 0; i < size; i++)
    {
        arr[i] = brr[i];
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

    count_sort(arr, size);

    printf("\nAfter Sorting:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", *(arr + i));
    }

    return 0;
}
