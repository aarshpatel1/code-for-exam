#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int x)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

int main()
{
    enqueue(10);
    enqueue(20);
    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());
    return 0;
}
