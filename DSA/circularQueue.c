#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int front;
    int rear;
    int data[MAX_SIZE];
} CircularQueue;

void initialize(CircularQueue *cq) {
    cq->front = -1;
    cq->rear = -1;
}

int isEmpty(CircularQueue *cq) {
    return cq->front == -1;
}

int isFull(CircularQueue *cq) {
    return (cq->rear + 1) % MAX_SIZE == cq->front;
}

void enqueue(CircularQueue *cq, int element) {
    if (isFull(cq)) {
        printf("Queue Overflow!\n");
        return;
    }
    if (isEmpty(cq)) {
        cq->front = 0;
    }
    cq->rear = (cq->rear + 1) % MAX_SIZE;
    cq->data[cq->rear] = element;
}

int dequeue(CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int dequeuedElement = cq->data[cq->front];
    if (cq->front == cq->rear) {
        initialize(cq);
    } else {
        cq->front = (cq->front + 1) % MAX_SIZE;
    }
    return dequeuedElement;
}

void display(CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue Elements: ");
    for (int i = cq->front; i != (cq->rear + 1) % MAX_SIZE; i = (i + 1) % MAX_SIZE) {
        printf("%d ", cq->data[i]);
    }
    printf("\n");
}

int main() {
    CircularQueue myQueue;
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