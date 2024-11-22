#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue is Full\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = x;
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear)
    {
        front = rear = -1; // Queue becomes empty
    }
    else
    {
        front = (front + 1) % MAX;
    }
    return data;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue Elements: ");
    int i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("Dequeued: %d\n", dequeue());
    display();
    return 0;
}
