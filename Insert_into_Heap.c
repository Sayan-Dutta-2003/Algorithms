/*
Write a C/C++ program to insert an element into heap, also
compute time complexity for an input of size N.
*/

#include <stdio.h>
#include <stdlib.h>

static int complexity = 0;

void insert(int heap[], int size, int element) {
    heap[size] = element;
    int i = size, parent = (i - 1) / 2;
    while (i > 0 && heap[parent] < heap[i]) {
        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;
        i = parent;
        parent = (i - 1) / 2;
        complexity+=7;
    }
}

void printHeap(int heap[], int size) {
    printf("Heap: ");
    for (int i = 0; i < size; i++) {
        complexity++;
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int *heap, size = 0, capacity = 1, element;
    heap = (int *)malloc(capacity * sizeof(int));
    

    printf("Enter the elements of the heap (enter 'q' to stop):\n");
    while (scanf("%d", &element) == 1) {
        if (size >= capacity) {
            capacity *= 2;
            heap = (int *)realloc(heap, capacity * sizeof(int));
            complexity+=3;
        }
        
        insert(heap, size, element);
        size++;
        printHeap(heap, size);
        complexity++;
    }
    free(heap);

    printf("\nTime Complexity: %d", complexity);
    return 0;
}

