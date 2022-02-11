#include <stdio.h>

void main()
{
    int arr[5], opt;
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
            dequeue(arr, &front, &rear, size);
            break;
        case 3:
            display(arr, &front, &rear, size);
            break;

        default:
            break;
        }
    }
}

void enqueue(int arr[], int *front, int *rear, int size)
{
    int num;
    if ((*front == 0 && *rear == size - 1) || (*front == *rear + 1))
    {
        printf("queue is full\n");
    }
    else
    {
        printf("enter the number\n");
        scanf("%d", &num);
        if (*front && *rear == -1)
        {

            *front = *rear = 0;
            arr[*front] = num;
        }
        else
        {
            *rear = (*rear + 1) % size;
            arr[*rear] = num;
        }
        printf("f->%d,  r->%d", *front, *rear);

        printf("value added ");
        for (int i = *front; i < *rear + 1; i++)
        {
            printf("%d--", arr[i]);
        }
        printf("\n");
    }
}

void dequeue(int arr[], int *front, int *rear, int size)
{

    if (*front && *rear == -1)
    {
        printf("queue is empty");
    }
    else
    {
        if (*rear == *front)
        {
            *front = *rear = -1;
        }
        else
        {
            *front = (*front + 1) % size;
        }
        printf("value removed\n");
    }
}

void display(int arr[], int *front, int *rear, int size)
{
    if (*front == -1)
    {
        printf("queue is empty\n");
    }
    else
    {
        int i = *front;
        if (*front <= *rear)
        {
            while (i <= *rear)
            {
                printf("%d--", arr[i++]);
            }
        }
        else
        {
            while (i <= size - 1)
            {
                printf("%d--", arr[i++]);
            }
            i = 0;
            while (i <= *rear)
            {
                printf("%d--", arr[i++]);
            }
        }
    }
}
