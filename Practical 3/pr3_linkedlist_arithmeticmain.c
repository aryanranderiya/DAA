#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node
{
    int digit;
    struct Node *link;
};

// Function to print the linked list
void printLinkedList(struct Node *head)
{
    int zerocounter = 0;
    struct Node *current = head;
    while (current != NULL)
    {
        if (current->digit != 0) // To Remove Trailing Zeroes
            zerocounter = 1;

        if (!zerocounter == 0) // Only Print the digits if the starting is not a zero
            printf("%d", current->digit);

        current = current->link;
    }
    printf("\n");
}

// Function to insert a node at the end of the linked list
struct Node *insertEnd(struct Node *head, int digit)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->digit = digit;
    newnode->link = NULL;
    if (head == NULL)
    {
        return newnode;
    }
    struct Node *current = head;
    while (current->link != NULL)
    {
        current = current->link;
    }
    current->link = newnode;
    return head;
}

// LinkedList Reverse Function
struct Node *reverse(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;
    // Reverse the links of each node in the linked list
    while (current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    // New head of the reversed list
    return prev;
}

// Function to insert a node at the begining of the linked list
struct Node *insertBeg(struct Node *head, int digit)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->digit = digit;
    newnode->link = head;
    return newnode;
}

// Addition Function
struct Node *addition(struct Node *number1, struct Node *number2)
{
    int addition = 0;
    int carry = 0;
    struct Node *start1 = number1;
    struct Node *start2 = number2;
    struct Node *result = NULL;

    // Traverse both linked lists until both are not null
    while ((start1 != NULL) && (start2 != NULL))
    {

        // Calculate the sum (0 to 9 values only) and update 'addition'
        addition = (start1->digit + start2->digit + carry) % 10;

        // Insert the sum into the result linked list
        result = insertBeg(result, (addition));

        // Update the carry for the next iteration
        carry = (start1->digit + start2->digit + carry) / 10;
        start1 = start1->link;
        start2 = start2->link;
    }

    // If there are nodes still left in start2
    if (start1 == NULL)
    {
        while (start2 != NULL)
        {
            addition = (start2->digit + carry) % 10;
            result = insertBeg(result, addition);
            carry = (start2->digit + carry) / 10;
            start2 = start2->link;
        }
    }
    // If there are nodes still left in start1
    if (start2 == NULL)
    {
        while (start1 != NULL)
        {
            addition = (start1->digit + carry) % 10;
            result = insertBeg(result, addition);
            carry = (start1->digit + carry) / 10;
            start1 = start1->link;
        }
    }
    // If there exists a carry after additioning the last digit, resolve it here
    if ((start1 == NULL) && (start2 == NULL) && (carry != 0))
        result = insertBeg(result, carry);

    return result;
}

// Multiplication Function
void multiplication(struct Node *number1, struct Node *number2)
{
    int carry = 0;
    int count = 0;
    struct Node *start1 = number1;
    struct Node *start2 = number2;
    struct Node *result = NULL;

    while (start2 != NULL)
    {
        struct Node *temp = start1;
        struct Node *answer = NULL;
        // Append zeros to the result for the current count
        int x = count;
        while (x > 0)
        {
            answer = insertEnd(answer, 0);
            x--;
        }
        while (temp != NULL)
        {
            int multiply = (temp->digit * start2->digit + carry) % 10;
            carry = (temp->digit * start2->digit + carry) / 10;
            answer = insertBeg(answer, multiply);
            temp = temp->link;
        }
        // Carry handling if generated
        if (carry > 0)
        {
            answer = insertBeg(answer, carry);
            carry = 0;
        }
        // Reverse the answer and add it to the result
        result = addition(result, answer);
        start2 = start2->link;
        count++;
    }
    result = reverse(result);
    printf("\nResult of multiplication :\n");
    printLinkedList(result);
}

// Subtraction Function
void subtraction(struct Node *number1, struct Node *number2)
{
    int difference = 0, appendMinus = 0, borrow = 0;
    struct Node *start1 = number1;
    struct Node *start2 = number2;
    struct Node *temp;
    struct Node *result = NULL;

    if (number1 < number2)
    {
        // Swap both numbers when first number is smaller
        temp = start1;
        start1 = start2;
        start2 = temp;
        appendMinus = 1;
    }

    while (start1 != NULL || start2 != NULL)
    {
        difference = (start1->digit - borrow);
        if (start2 != NULL)
        {
            difference -= start2->digit;
            start2 = start2->link;
        }
        if (difference < 0)
        {
            difference += 10;
            borrow = 1;
        }
        else
            borrow = 0;

        // Insert the difference into the result linked list
        result = insertBeg(result, difference);
        start1 = start1->link;
    }

    // If the first number is smaller than multiple by -1
    if (appendMinus == 1)
        printf("\nResult of subtraction :\n -");
    else
        printf("\nResult of subtraction :\n");

    printLinkedList(result);
}

int main()
{

    struct Node *start1 = NULL;
    struct Node *start2 = NULL;
    struct Node *result;

    int digit, operation, number1, number2;

    printf("Enter number 1: ");
    scanf("%d", &number1);

    printf("Enter number 2: ");
    scanf("%d", &number2);

    while (number1 != 0)
    {
        // Reverse the digits
        digit = number1 % 10;
        number1 = number1 / 10;
        start1 = insertEnd(start1, digit); // Insert the digit at the ending of the list
    }

    while (number2 != 0)
    {
        // Reverse the digits
        digit = number2 % 10;
        number2 = number2 / 10;
        start2 = insertEnd(start2, digit); // Insert the digit at the ending of the list
    }

    while (1)
    {

        printf("\n1. Addition\n2. Multiplication\n3. Subtraction\n4. Exit\n\n");
        scanf("%d", &operation);

        switch (operation)
        {

        case 1:
            result = addition(start1, start2);
            printf("\nResult of addition :\n");
            printLinkedList(result);
            break;

        case 2:
            multiplication(start1, start2);
            break;

        case 3:
            subtraction(start1, start2);
            break;

        case 4:
            printf("Exiting...");
            exit(0);

        default:
            printf("Please choose a valid option.\n");
            break;
        }
    }
}