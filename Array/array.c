#include <stdio.h>

void main()
{
    int opt, s;
    int arr[50];
    int count = 0;

    while (1)
    {
        printf("enter the option\n1.insert\n2.delete\n3.update\n4.display\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:

            insert(arr, &count);
            break;
        case 2:
            delete (arr, &count);
            break;
        case 3:
            update(arr, &count);
            break;
        case 4:
            display(arr, &count);
            break;
        case 5:
            break;

        default:
            break;
        }
    }
}

void insert(int arr[], int *count)
{
    int num;
    printf("enter the number\n");
    scanf("%d", &num);
    *count = *count + 1;
    arr[*count] = num;
    for (int i = 1; i < *count + 1; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
void delete (int arr[], int *count)
{
    int pos;
    printf("enter the position to be deleted");
    scanf("%d", &pos);
    for (int i = *count; i > pos; i--)
    {
        arr[i - 1] = arr[i];
    }
    *count = *count - 1;
    for (int i = 1; i < *count + 1; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
void update(int arr[], int *count)
{

    int pos, num;
    printf("enter the position to be inserted\n");
    scanf("%d", &pos);
    printf("enter the number");
    scanf("%d", &num);
    arr[pos] = num;
    *count = *count + 1;

    printf("the array is \n");
    if (*count == 0)
    {
        printf("array is empty");
    }
    else
    {
        for (int i = 1; i < *count + 1; i++)
        {
            printf("%d\t", arr[i]);
        }
        printf("\n");
    }
}
void display(int arr[], int *count)
{
    for (int i = 1; i < *count + 1; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
