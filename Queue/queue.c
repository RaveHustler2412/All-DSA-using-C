#include <stdio.h>

void main()
{
    int arr[50], opt;
    int front = -1;
    int rear = -1;

    while (1)
    {
        printf("enter the option\n1.enqueue\n2.dequeue\n3.display\n");
        scanf("%d", &opt);
        int size = sizeof(arr) / sizeof(int);
        switch (opt)
        {
        case 1:
            enqueue(arr, &front, &rear, size);
            break;
        case 2:
            dequeue(arr, &front, &rear);
            break;
        case 3:
            display(arr, &front, &rear);
            break;

        default:
            break;
        }
    }
}

void enqueue(int arr[], int *front, int *rear, int size)
{
    int num;

    if (*rear + 1 == size)
    {
        printf("queue is full");
    }
    else
    {
        printf("enter the number");
        scanf("%d", &num);
        if (*front && *rear == -1)
        {
            *front = *rear = (*front + 1);
            arr[*front] = num;
        }
        else
        {
            arr[++*rear] = num;
        }
        printf("value added to queue\n");
    }
}

void dequeue(int arr[], int *front, int *rear)
{
    if (*front && *rear == -1)
    {
        printf("queue is empty\n");
    }
    else
    {
        if (*front == *rear)
        {
            *front = *rear = -1;
        }
        else
        {
            *front = *front + 1;
        }
        printf("value is removed\n");
    }
}

void display(int arr[], int *front, int *rear)
{
    if (*front && *rear == -1)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("QUEUE IS  ");
        for (int i = *front; i < *rear + 1; i++)
        {
            printf(" %d--", arr[i]);
        }
        printf("\n");
    }
}
