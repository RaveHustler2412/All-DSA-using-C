#include <stdio.h>

void main()
{
    int opt;
    int arr[5];
    int top = -1;

    while (1)
    {
        printf("énter the option\n1.push\n2.pop\n3.display\n");
        scanf("%d", &opt);
        int size = sizeof(arr) / sizeof(int);
        switch (opt)
        {
        case 1:

        {
            push(arr, &top, size);
            break;
        }
        case 2:
            pop(arr, &top, size);
            break;
        case 3:
            display(arr, &top);
            break;

        default:
            break;
        }
    }
}

void push(int arr[], int *top, int size)
{
    int num;
    if (*top + 1 > size - 1)
    {
        printf("stack is full\n");
    }
    else
    {
        printf("enter the number");
        scanf("%d", &num);
        arr[++*top] = num;

        printf("value is added %d\t", size);
        for (int i = *top; i > -1; i--)
        {
            printf("%d\t", arr[i]);
        }
        printf("\n");
    }
}
void pop(int arr[], int *top, int size)
{
    if (*top == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        *top = *top - 1;
        printf("Popped\n");
    }
}
void display(int arr[], int *top)

{
    if (*top == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        for (int i = *top; i > -1; i--)
        {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}