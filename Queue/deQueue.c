#include <stdio.h>
#include <stdlib.h>

int front = -1;
int rear = -1;
int arr[5];

int opt;

void main()
{
    while (1)
    {

        printf("enter the option\n1.enqueueFront\n2.enqueueRear\n3.dequeueFront\n4.dequeueRear\n5.display\n");
        scanf("%d", &opt);
        int size = sizeof(arr) / sizeof(int);
        switch (opt)
        {
        case 1:
        {
        }
            enqueueFront(size);
            break;
        case 2:
            enqueueRear(size);
            break;
        case 3:
            dequeueFront(size);
            break;
        case 4:
            dequeueRear(size);
            break;
        case 5:
            display();
            break;

        default:
            break;
        }
    }
}

void enqueueFront(int size)
{
    if (isFull(size))
    {
        printf("queue is full\n");
    }
    else
    {
        int num;
        printf("enter the number\n");
        scanf("%d", &num);
        if (front & rear == -1)
        {
            front = rear = 0;
            arr[front] = num;
        }
        else
        {
            for (int i = rear; i >= front; i--)
            {
                arr[i + 1] = arr[i];
            }
            arr[0] = num;
            rear = rear + 1;
        }
        for (int i = front; i <= rear; i++)
        {
            printf("%d--", arr[i]);
        }
        printf("\n");
    }
}
void enqueueRear(int size)
{
    if (isFull(size))
    {
        printf("queue is full\n");
    }
    else
    {
        int num;
        printf("enter the number");
        scanf("%d", &num);
        if (front & rear == -1)
        {
            front = rear = 0;
            arr[front] = num;
        }
        else
        {
            arr[rear + 1] = num;
            rear++;

            for (int i = front; i <= rear; i++)
            {
                printf("%d--", arr[i]);
            }
            printf("\n");
        }
    }
}
void dequeueFront(int size)
{
    if (isEmpty())
    {
        printf("queue is empty\n");
    }
    else
    {
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {

            front++;
            for (int i = front; i <= rear; i++)
            {
                printf("%d--", arr[i]);
            }
            printf("\n");
        }
    }
}
void dequeueRear(int size)
{
    if (isEmpty())
    {
        printf("queue is empty\n");
    }
    else
    {
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {

            rear = rear - 1;
            for (int i = front; i <= rear; i++)
            {
                printf("%d--", arr[i]);
            }
            printf("\n");
        }
    }
}
void display()
{
}

int isEmpty()
{
    if (front && rear == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(int size)
{
    if (front == 0 && rear + 1 == size)
    {
        return 1;
    }
    return 0;
}