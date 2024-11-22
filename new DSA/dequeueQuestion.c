#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int x)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque is Full\n");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }
    deque[front] = x;
}

void insertRear(int x)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque is Full\n");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    deque[rear] = x;
}

int deleteFront()
{
    if (front == -1)
    {
        printf("Deque is Empty\n");
        return -1;
    }
    int data = deque[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    return data;
}

int deleteRear()
{
    if (front == -1)
    {
        printf("Deque is Empty\n");
        return -1;
    }
    int data = deque[rear];
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }
    return data;
}

void display()
{
    if (front == -1)
    {
        printf("Deque is Empty\n");
        return;
    }
    printf("Deque Elements: ");
    int i = front;
    while (1)
    {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    insertRear(10);
    insertRear(20);
    insertFront(5);
    display();
    printf("Deleted from Front: %d\n", deleteFront());
    display();
    return 0;
}
