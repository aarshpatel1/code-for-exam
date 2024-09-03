#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define NUM_STACKS 3

typedef struct {
    int top[NUM_STACKS];
    int data[MAX_SIZE];
} MultipleStacks;

void initialize(MultipleStacks *ms) {
    for (int i = 0; i < NUM_STACKS; i++) {
        ms->top[i] = -1;
    }
}

int isEmpty(MultipleStacks *ms, int stackIndex) {
    return ms->top[stackIndex] == -1;
}

int isFull(MultipleStacks *ms, int stackIndex) {
    return ms->top[stackIndex] == MAX_SIZE / NUM_STACKS - 1;
}

void push(MultipleStacks *ms, int stackIndex, int element) {
    if (isFull(ms, stackIndex)) {
        printf("Stack %d Overflow!\n", stackIndex + 1);
        return;
    }
    ms->top[stackIndex]++;
    ms->data[stackIndex * (MAX_SIZE / NUM_STACKS) + ms->top[stackIndex]] = element;
}

int pop(MultipleStacks *ms, int stackIndex) {
    if (isEmpty(ms, stackIndex)) {
        printf("Stack %d Underflow!\n", stackIndex + 1);
        return -1;
    }
    int poppedElement = ms->data[stackIndex * (MAX_SIZE / NUM_STACKS) + ms->top[stackIndex]];
    ms->top[stackIndex]--;
    return poppedElement;
}

void display(MultipleStacks *ms, int stackIndex) {
    if (isEmpty(ms, stackIndex)) {
        printf("Stack %d is Empty!\n", stackIndex + 1);
        return;
    }
    printf("Stack %d Elements: ", stackIndex + 1);
    for (int i = ms->top[stackIndex]; i >= 0; i--) {
        printf("%d ", ms->data[stackIndex * (MAX_SIZE / NUM_STACKS) + i]);
    }
    printf("\n");
}

int main() {
    MultipleStacks myStacks;
    initialize(&myStacks);

    // Push elements onto different stacks
    push(&myStacks, 0, 10);
    push(&myStacks, 0, 20);
    push(&myStacks, 1, 30);
    push(&myStacks, 1, 40);

    // Display elements of each stack
    display(&myStacks, 0);
    display(&myStacks, 1);

    // Pop elements from different stacks
    int poppedElement = pop(&myStacks, 0);
    printf("Popped Element from Stack 1: %d\n", poppedElement);

    // Display the updated stacks
    display(&myStacks, 0);
    display(&myStacks, 1);

    return 0;
}