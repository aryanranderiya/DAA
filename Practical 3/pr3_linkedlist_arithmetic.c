#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *start_one = NULL;
struct Node *start_two = NULL;

struct Node *ptr_one = NULL;
struct Node *ptr_two = NULL;

void insert(int item, struct Node **start)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = item;
    if (*start == NULL)
    {
        *start = new_node;
        new_node->link = NULL;
    }
    else
    {
        struct Node *ptr = *start;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = new_node;
        new_node->link = NULL;
    }
}

void display(struct Node *start)
{
    struct Node *temp = start;

    while (temp != NULL)
    {
        printf("%d --> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

void performAddition(struct Node *start_one, struct Node *start_two)
{
    printf("Performing Addition...\n");

    struct Node *temp = start_one;
    struct Node *temp2 = start_two;

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp3 = new_node;

    while (temp != NULL || temp2 != NULL)
    {
        temp = temp->link;
        temp2 = temp2->link;

        new_node->data = (temp->data) + (temp2->data);
        
    }

    display(temp3);
}

int main()
{

    int num1, num2;
    printf("Enter number 1: ");
    scanf("%d", &num1);
    printf("Enter number 2: ");
    scanf("%d", &num2);

    int digit;

    while (num1 != 0)
    {
        digit = num1 % 10;
        num1 = num1 / 10;
        insert(digit, &start_one);
    }

    while (num2 != 0)
    {
        digit = num2 % 10;
        num2 = num2 / 10;
        insert(digit, &start_two);
    }

    printf("\nLinked List 1: \n");
    display(start_one);

    printf("\nLinked List 2: \n");
    display(start_two);

    performAddition(start_one, start_two);

    return 0;
}