/*
Write C/C++ program to implement stack with the use of array.
Make a new function Multi Pop which pops k times. Take k as
user input. Uses amortize analysis (accounting) to calculate time
complexity of the program.
*/

#include <stdio.h>
#define MAX_SIZE 100

static int complexity = 0;

int stack[MAX_SIZE];
int top = -1;

void push(int data)
{
    if (top == MAX_SIZE - 1)
    {
        complexity+=2;
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = data;
    complexity++;
}

int pop()
{
    if (top == -1)
    {
        complexity+=2;
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
    complexity++;
}

void multi_pop(int k)
{
    if ((top - k + 1) < 0)
    {
        complexity+=2;
        printf("Invalid Input");
        return;
    }
    top -= k;
    complexity++;
}

int main()
{

    int k, x;
    printf("Enter the elements to push onto the stack (enter any non-integer character to stop):\n");
    while (scanf("%d", &x) == 1)
    {
        push(x);
        complexity++;
    }
    fflush(stdin);
    printf("Enter k to pop k elements from the stack: ");
    scanf("%d", &k);
    multi_pop(k);
    printf("The elements of the stack are:\n");
    while (top != -1)
    {
        printf("%d ", pop());
        complexity++;
    }

    printf("Average Cost of the this Program: %d", complexity);

    return 0;
}
