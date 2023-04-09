/*
Write a C/C++ program to delete the N element from a heap,
also compute time complexity for those N elements.
*/

#include <stdio.h>
#include <stdlib.h>

void delete(int *heap, int *size, int n);

int main() {
    int *heap;
    int size = 0;
    int n, i;

    // Input the heap elements
    printf("Enter the number of elements in the heap: ");
    scanf("%d", &size);
    heap = (int*)malloc(size * sizeof(int));
    printf("Enter the elements of the heap: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &heap[i]);
    }

    // Input the index of the element to be deleted
    printf("Enter the index of the element to be deleted: ");
    scanf("%d", &n);

    // Delete the element at index n
    delete(heap, &size, n);

    // Print the updated heap
    printf("The updated heap is: ");
    for (i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }

    free(heap); // Free the memory allocated to the heap
    return 0;
}

void delete(int *heap, int *size, int n) {
    int i;

    // Copy the last element of the heap to the element at index n
    heap[n] = heap[*size - 1];

    // Decrement the size of the heap
    *size -= 1;

    // Reorder the heap
    for (i = n; i < *size; ) {
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;
        int max_child = left_child;

        // Find the maximum child
        if (right_child < *size && heap[right_child] > heap[left_child]) {
            max_child = right_child;
        }

        // If the maximum child is greater than the parent, swap them
        if (max_child < *size && heap[max_child] > heap[i]) {
            int temp = heap[i];
            heap[i] = heap[max_child];
            heap[max_child] = temp;
            i = max_child;
        }
        else {
            break;
        }
    }
}
