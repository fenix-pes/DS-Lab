#include <stdio.h>
#include <stdlib.h>

int a[50], s = 0;

/* Function declarations */
void menu();
void insert();
void delete_element();
void sort();
void search();
void display();

int main()
{
    int i;

    printf("Enter the size of array: ");
    scanf("%d", &s);

    if (s < 0 || s > 50)
    {
        printf("Invalid array size!\n");
        return 0;
    }

    printf("Enter the elements of array:\n");

    for (i = 0; i < s; i++)
    {
        scanf("%d", &a[i]);
    }

    menu();

    return 0;
}

/* Menu function */
void menu()
{
    int choice;

    while (1)
    {
        printf("\n\n----- ARRAY OPERATIONS -----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Sort\n");
        printf("4. Search\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete_element();
                break;

            case 3:
                sort();
                break;

            case 4:
                search();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program...\n");
                return;

            default:
                printf("Invalid choice!\n");
        }
    }
}

/* Insert an element */
void insert()
{
    int loc, ele, i;

    if (s == 50)
    {
        printf("Array is full!\n");
        return;
    }

    printf("Enter the location: ");
    scanf("%d", &loc);

    if (loc < 1 || loc > s + 1)
    {
        printf("Invalid location!\n");
        return;
    }

    printf("Enter the element to be inserted: ");
    scanf("%d", &ele);

    for (i = s; i >= loc; i--)
    {
        a[i] = a[i - 1];
    }

    a[loc - 1] = ele;
    s++;

    printf("Element inserted successfully.\n");
    printf("New array after insertion: ");

    for (i = 0; i < s; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\n");
}

/* Delete an element */
void delete_element()
{
    int loc, i;

    if (s == 0)
    {
        printf("Array is empty!\n");
        return;
    }

    printf("Enter location: ");
    scanf("%d", &loc);

    if (loc < 1 || loc > s)
    {
        printf("Invalid location!\n");
        return;
    }

    for (i = loc - 1; i < s - 1; i++)
    {
        a[i] = a[i + 1];
    }

    s--;

    printf("Element deleted successfully.\n");
    printf("New array after deletion: ");

    for (i = 0; i < s; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\n");
}

/* Sort the array */
void sort()
{
    int i, j, temp;

    if (s == 0)
    {
        printf("Array is empty!\n");
        return;
    }

    for (i = 0; i < s - 1; i++)
    {
        for (j = i + 1; j < s; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("Sorted array: ");

    for (i = 0; i < s; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\n");
}

/* Search an element */
void search()
{
    int ele, i, found = 0;

    if (s == 0)
    {
        printf("Array is empty!\n");
        return;
    }

    printf("Enter element to be searched: ");
    scanf("%d", &ele);

    for (i = 0; i < s; i++)
    {
        if (a[i] == ele)
        {
            printf("Element found at position %d\n", i + 1);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Element not found!\n");
    }
}

/* Display the array */
void display()
{
    int i;

    if (s == 0)
    {
        printf("No elements to display!\n");
        return;
    }

    printf("Array elements are: ");

    for (i = 0; i < s; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\n");
}
