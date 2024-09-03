#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int front;
    int rear;
    int data[MAX_SIZE];
} Queue;

void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

void enqueue(Queue *q, int element) {
    if (isFull(q)) {
        printf("Queue Overflow!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = element;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int dequeuedElement = q->data[q->front];
    if (q->front == q->rear) {
        initialize(q);
    } else {
        q->front++;
    }
    return dequeuedElement;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue Elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    Queue myQueue;
    initialize(&myQueue);

    // Enqueue elements into the queue
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    // Display the queue elements
    display(&myQueue);

    // Dequeue elements from the queue
    int dequeuedElement = dequeue(&myQueue);
    printf("Dequeued Element: %d\n", dequeuedElement);

    // Display the updated queue
    display(&myQueue);

    return 0;
}