#include <stdio.h>
#include <stdlib.h>

int opt, value, pos;
struct Node
{
    int data;
    struct Node *next, *prev;

} *head = NULL;

void display();
int insertionAtBeg(int value);
int insertionAtEnd(int value);
void deletionAtBeg();
void deletionAtEnd();
void update(int pos, int value);
void InsertPos(int pos, int value);
void DeletePos(int pos);
int traverse(struct Node *temp);
int search();

int main()
{

    while (1)
    {
        printf("\nenter the choice\n0.display\n1.insertionAtBeg\n2.insertionAtEnd\n3.deletionAtBeg\n4.deletionAtEnd\n5.InsertPos\n6.DeletePos\n7.Update\n8.Traverse\n9.Search\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 0:
            display();
            break;
        case 1:
        {
            printf("enter the value ");
            scanf("%d", &value);
            insertionAtBeg(value);
            break;
        }

        case 2:
        {
            printf("enter the value");
            scanf("%d", &value);
            insertionAtEnd(value);
            break;
        }
        case 3:
            deletionAtBeg();
            break;
        case 4:
            deletionAtEnd();
            break;

        case 5:
        {
            printf("enter the position to be inserted\nenter the value ");
            scanf("%d %d", &pos, &value);
            InsertPos(pos, value);
            break;
        }

        case 6:
        {
            printf("enter the position to be deleted");
            scanf("%d", &pos);
            DeletePos(pos);
            break;
        }
        case 7:
        {
            printf("enter the position to be updated\nenter the value ");
            scanf("%d %d", &pos, &value);
            update(pos, value);
            break;
        }

        case 8:
        {
            if (isEmpty())
            {
                printf("List is empty\n");
            }
            else
            {
                traverse(head);
            }

            break;
        }
        case 9:
        {
            if (isEmpty())
            {
                printf("List is empty\n");
            }
            else
            {

                if (search())
                    printf("Data is Present\n");
                else
                {
                    printf("Data not found\n");
                }
            }

            break;
        }

        default:
            break;
        }
    }
    return 0;
}

int isEmpty()
{
    if (head == NULL)
        return 1;
    return 0;
}

int search()
{

    printf("enter the value to be searched ");
    scanf("%d", &value);

    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
int insertionAtBeg(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    struct Node *temp;
    newNode->data = value;
    if (isEmpty())
    {
        newNode->prev = NULL;
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->prev = NULL;
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    return 0;
}

int insertionAtEnd(value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    struct Node *temp;
    newNode->data = value;

    if (isEmpty())
    {
        newNode->prev = NULL;
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }
    return 0;
}

void deletionAtBeg()
{
    if (isEmpty())
    {
        printf('list is empty\n');
    }
    else
    {
        if (head->next == NULL)
            head = NULL;
        else
        {

            head = head->next;
            head->prev = NULL;
        }
    }
}

void deletionAtEnd()
{
    struct Node *temp = head;
    if (isEmpty())
    {
        printf("list is empty\n");
    }
    else
    {
        if (temp->next == NULL)
        {
            head = NULL;
        }
        else
        {

            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = NULL;
        }
    }
}

void InsertPos(pos, value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;

    if (isEmpty())
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        if (pos == 1)
        {
            head->prev = newNode;
            newNode->next = head;
            newNode->prev = NULL;
            head = newNode;
        }
        else
        {

            struct Node *temp = head;

            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

void DeletePos(pos)
{
    if (isEmpty())
    {
        printf("list is empty\n");
    }
    else
    {
        struct Node *temp = head;
        if (pos == 1)
        {
            head = NULL;
        }
        else
        {
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            if (temp->next->next == NULL)
            {
                temp->next = NULL;
            }
            else
            {

                temp->next->next->prev = temp;
                temp->next = temp->next->next;
            }
        }
    }
}

void update(pos, value)
{
    if (isEmpty())
    {
        printf("list is empty\n");
    }
    else
    {
        struct Node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->data = value;
    }
}

int traverse(struct Node *temp)
{

    if (temp->next != NULL)
    {
        traverse(temp->next);
    }
    printf("%d--", temp->data);
}

void display()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d--", temp->data);
            temp = temp->next;
        }
    }
}