#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record
{
    char name[500];
    int x;
    int y;
    struct Record *link;
};

struct Record *start = NULL;

struct Record *createNewNode(char name[], int x, int y)
{
    struct Record *newNode = (struct Record *)malloc(sizeof(struct Record));
    strncpy(newNode->name, name, sizeof(newNode->name));
    newNode->x = x;
    newNode->y = y;
    newNode->link = NULL;
    printf("Created new Node with name of %s\n", name);
    return newNode;
}

void insert()
{
    int x, y;
    char name[500];

    printf("Inserting Data...\n");
    printf("Enter Name of city: ");
    scanf("%s", name);
    printf("Enter X coordinates of city: ");
    scanf("%d", &x);
    printf("Enter Y coordinates of city: ");
    scanf("%d", &y);

    struct Record *newNode = createNewNode(name, x, y);
    if (start == NULL)
    {
        start = newNode;
        return;
    }
    else
    {
        newNode->link = start;
        start = newNode;
    }
}

void display()
{

    if (start == NULL)
    {
        printf("There are no Records!\n");
        return;
    }

    int counter;
    struct Record *temp = start;

    while (temp != NULL)
    {
        counter++;
        printf(" %d : [City - %s : ", counter, &temp->name);
        printf("X - %d : ", temp->x);
        printf("Y - %d] \n", temp->y);
        temp = temp->link;
    }
}

void deleteByName()
{
    struct Record *previous = NULL;
    struct Record *current = start;
    char name[500];
    printf("Enter Name of City to delete record:");
    scanf("%s", &name);

    while (current != NULL && strcmp(current->name, name) != 0)
    {
        previous = current;
        current = current->link;
    }

    if (current == NULL)
    {
        printf("No such Record Exists!\n");
        return;
    }
    if (previous == NULL) // Current element is the first element in the list
    {
        start = current->link;
    }
    else // If the current element is not the first element of the list
    {
        previous->link = current->link;
    }
    free(current);
    printf("Record has been deleted!\n");
    display();
}

void deleteByCoordinates()
{
    struct Record *previous = NULL;
    struct Record *current = start;
    int x, y;
    printf("Enter X coordinate to delete record: ");
    scanf("%d", &x);
    printf("Enter Y coordinate to delete record: ");
    scanf("%d", &y);

    while (current != NULL && (current->x != x) && (current->y != y))
    {
        previous = current;
        current = current->link;
    }

    if (current == NULL)
    {
        printf("No such Record Exists!\n");
        return;
    }
    if (previous == NULL) // Current element is the first element in the list
    {
        start = current->link;
    }
    else // If the current element is not the first element of the list
    {
        previous->link = current->link;
    }
    free(current);
    printf("Record has been deleted!\n");
    display();
}

void searchByCoordinates()
{
    struct Record *previous = NULL;
    struct Record *current = start;
    int x, y;
    printf("Enter X coordinate to display record details: ");
    scanf("%d", &x);
    printf("Enter Y coordinate to display record details: ");
    scanf("%d", &y);

    while (current != NULL && (current->x != x) && (current->y != y))
    {
        previous = current;
        current = current->link;
    }

    if (current == NULL)
    {
        printf("No such Record Exists!\n");
        return;
    }

    printf("Record with Coordinates X: %d Y: %dFound!\n", current->x, current->y);
    printf("City Name: %s\n", current->name);
}
void searchByName()
{
    struct Record *previous = NULL;
    struct Record *current = start;
    char name[500];
    printf("Enter Name of City to display all details:");
    scanf("%s", &name);

    while (current != NULL && strcmp(current->name, name) != 0)
    {
        previous = current;
        current = current->link;
    }

    if (current == NULL)
    {
        printf("No such Record Exists!\n");
        return;
    }

    printf("Record %s Found!\n", current->name);
    printf("X: %d\n", current->x);
    printf("Y: %d\n", current->y);
}

void displayRecordsWithinDistance()
{
    // struct Node *temp = start;
    // printf("Records at given distance\n");
    // // Traverse the list and calculate the distance of each record from the specified point
    // while (temp != NULL)
    // {
    //     double distance = sqrt(pow(temp->x - x0, 2) + pow(temp->y - y0, 2));
    //     // If the distance is less than or equal to the given distance, print the record details
    //     if (distance <= dist)
    //     {
    //         printf("[City = %s , X = %d , Y = %d , Distance = %lf]\n", temp->city, temp->x, temp->y, dist);
    //     }
    //     temp = temp->next;
    // }
}

int main()
{
    int option;

    while (1)
    {

        printf("Enter an option: \n1. Insert a Record.\n2. Delete a record by name\n3. Delete a record by coordinate.\n4. Search a record by name\n5. Search a record by coordinate\n6. Print all records within a given distance of a specified point.\n7. Display All Records\n8. Exit\n\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            deleteByName();
            break;
        case 3:
            deleteByCoordinates();
            break;
        case 4:
            searchByName();
            break;
        case 5:
            searchByCoordinates();
            break;
        case 6:
            displayRecordsWithinDistance();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        default:
            break;
        }
    }

    return 0;
}