#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int front;
    int rear;
    int data[MAX_SIZE];
} Dequeue;

void initialize(Dequeue *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isEmpty(Dequeue *dq) {
    return dq->front == -1;
}

int isFull(Dequeue *dq) {
    return (dq->rear + 1) % MAX_SIZE == dq->front;
}

void enqueueFront(Dequeue *dq, int element) {
    if (isFull(dq)) {
        printf("Dequeue Overflow!\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    dq->data[dq->front] = element;
}

void enqueueRear(Dequeue *dq, int element) {
    if (isFull(dq)) {
        printf("Dequeue Overflow!\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX_SIZE;
    }
    dq->data[dq->rear] = element;
}

int dequeueFront(Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Dequeue Underflow!\n");
        return -1;
    }
    int dequeuedElement = dq->data[dq->front];
    if (dq->front == dq->rear) {
        initialize(dq);
    } else {
        dq->front = (dq->front + 1) % MAX_SIZE;
    }
    return dequeuedElement;
}

int dequeueRear(Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Dequeue Underflow!\n");
        return -1;
    }
    int dequeuedElement = dq->data[dq->rear];
    if (dq->front == dq->rear) {
        initialize(dq);
    } else {
        dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    return dequeuedElement;
}

void display(Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is Empty!\n");
        return;
    }
    printf("Dequeue Elements: ");
    for (int i = dq->front; i != (dq->rear + 1) % MAX_SIZE; i = (i + 1) % MAX_SIZE) {
        printf("%d ", dq->data[i]);
    }
    printf("\n");
}

int main() {
    Dequeue myDequeue;
    initialize(&myDequeue);

    // Enqueue elements at the front
    enqueueFront(&myDequeue, 10);
    enqueueFront(&myDequeue, 20);

    // Enqueue elements at the rear
    enqueueRear(&myDequeue, 30);
    enqueueRear(&myDequeue, 40);

    // Display the dequeue elements
    display(&myDequeue);

    // Dequeue an element from the front
    int dequeuedElement = dequeueFront(&myDequeue);
    printf("Dequeued Element from Front: %d\n", dequeuedElement);

    // Dequeue an element from the rear
    dequeuedElement = dequeueRear(&myDequeue);
    printf("Dequeued Element from Rear: %d\n", dequeuedElement);

    // Display the updated dequeue
    display(&myDequeue);

    return 0;
}