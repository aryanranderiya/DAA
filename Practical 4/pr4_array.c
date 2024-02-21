#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max_size 1000 // Maximum number of records

struct Record
{
    char name[500];
    int x;
    int y;
};

struct Record database[max_size]; // Create an array of structures
int size_count = -1;

void display()
{
    printf("Size of Database: %d \n", size_count + 1);
    if (size_count == -1)
    {
        printf("There are no Records!\n");
        return;
    }

    for (int i = 0; i <= size_count; i++)
    {
        printf("\n%d: [City - %s,", i + 1, database[i].name);
        printf("X - %d,", database[i].x);
        printf("Y - %d]\n", database[i].y);
    }
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

    if (size_count >= max_size)
    {
        printf("Database at Full Capacity!\n");
        return;
    }

    size_count++;
    strncpy(database[size_count].name, name, sizeof(database[size_count].name));
    database[size_count].x = x;
    database[size_count].y = y;
    printf("\nCity %s Succesfully Inserted!\n\n", name);
}

void delete(int index)
{
    size_count--;
    for (int i = index; i <= size_count; i++)
    {
        database[i] = database[i + 1];
    }
    printf("Successfully Deleted!\n");
    display();
}

void deleteByName()
{
    char name[500];
    int indextodelete;
    printf("Enter City Name of record to delete: ");
    scanf("%s", name);

    for (int i = 0; i <= size_count; i++)
    {
        if (strcmp(name, database[i].name) == 0)
        {
            indextodelete = i;
            delete (indextodelete);
            return;
        }
    }
    printf("No Such Record Exists!\n");
}

void deleteByCoordinates()
{
    char name[500];
    int indextodelete;
    int x, y;
    printf("Enter X coordinate to delete record: ");
    scanf("%d", &x);
    printf("Enter Y coordinate to delete record: ");
    scanf("%d", &y);

    for (int i = 0; i <= size_count; i++)
    {
        if (database[i].x == x && database[i].y == y)
        {
            indextodelete = i;
            delete (indextodelete);
            return;
        }
    }
    printf("No Such Record Exists!\n");
}

void searchByCoordinates()

{
    int x, y;
    printf("Enter X coordinate to display record details: ");
    scanf("%d", &x);
    printf("Enter Y coordinate to display record details: ");
    scanf("%d", &y);

    for (int i = 0; i <= size_count; i++)
    {
        if (database[i].x == x && database[i].y == y)
        {
            printf("Record found!");
            printf("\n%d: [City - %s,", i + 1, database[i].name);
            printf("X - %d,", database[i].x);
            printf("Y - %d]\n", database[i].y);
            return;
        }
    }

    printf("No Such Record Exists!\n");
}
void searchByName()
{
    char name[500];
    printf("Enter a name to search");
    scanf("%s", name);

    for (int i = 0; i <= size_count; i++)
    {
        if (strcmp(name, database[i].name) == 0)
        {
            printf("Record found!");
            printf("\n%d: [City - %s,", i + 1, database[i].name);
            printf("X - %d,", database[i].x);
            printf("Y - %d]\n", database[i].y);
            return;
        }
    }

    printf("No Such Record Exists!\n");
}

void displayRecordsWithinDistance()
{
    int x0, y0, dist;
    printf("Enter X coordinates of city: ");
    scanf("%d", &x0);
    printf("Enter Y coordinates of city: ");
    scanf("%d", &y0);
    printf("Enter distance from point: ");
    scanf("%d", &dist);

    printf("Records at given distance\n");
    // Traverse the list and calculate the distance of each record from the specified point
    for (int i = 0; i <= size_count; i++)
    {
        double distance = sqrt(pow(database[i].x - x0, 2) + pow(database[i].y - y0, 2));
        // If the distance is less than or equal to the given distance, print the record details
        if (distance <= dist)
        {
            printf("[City = %s , X = %d , Y = %d , Distance = %lf]\n", database[i].name, database[i].x, database[i].y, dist);
        }
    }
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