
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;
node *head = NULL;

void display();
void insert_begin();
void insert_end();
void insert_between();
void delete_begin();
void delete_end();
void delete_between();

int main() {
    int choice;

    do {
        printf("\n\n1. Display");
        printf("\n2. Insert at beginning");
        printf("\n3. Insert at end");
        printf("\n4. Insert at any position");
        printf("\n5. Delete at beginning");
        printf("\n6. Delete at end");
        printf("\n7. Delete at any position");
        printf("\n8. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            display();
        else if (choice == 2)
            insert_begin();
        else if (choice == 3)
            insert_end();
        else if (choice == 4)
            insert_between();
        else if (choice == 5)
            delete_begin();
        else if (choice == 6)
            delete_end();
        else if (choice == 7)
            delete_between();
        else if (choice == 8)
            printf("Exiting...");
        else
            printf("Invalid choice!");

    } while (choice != 8);

    return 0;
}

void display() {
    node *temp = head;

    if (head == NULL) {
        printf("List is empty!");
    } else {
        printf("List: ");

        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL");
    }
}

void insert_begin() {
    node *newnode = malloc(sizeof(node));

    if (newnode == NULL) {
        printf("Memory allocation failed!");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;

    printf("Node inserted!");
}

void insert_end() {
    node *newnode = malloc(sizeof(node));
    node *temp = head;

    if (newnode == NULL) {
        printf("Memory allocation failed!");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("Node inserted!");
}

void insert_between() {
    node *temp = head, *current, *newnode;
    int pos, i, val;

    newnode = malloc(sizeof(node));

    if (newnode == NULL) {
        printf("Memory allocation failed!");
        return;
    }

    printf("Enter data and position: ");
    scanf("%d %d", &val, &pos);

    if (pos < 1) {
        free(newnode);
        printf("Invalid position!");
        return;
    }

    newnode->data = val;

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
    } else {
        i = 1;

        while (i < pos) {
            current = temp->next;
            temp = current;
            i++;
        }

        current = temp->next;
        temp->next = newnode;
        newnode->next = current;
    }

    printf("Node inserted!");
}
void delete_begin() {
    node *temp = head;

    if (head == NULL) {
        printf("List is empty!");
        return;
    }

    head = head->next;
    free(temp);

    printf("Node deleted!");
}

void delete_end() {
    node *current = head, *temp = NULL;

    if (head == NULL) {
        printf("List is empty!");
        return;
    }

    while (current->next != NULL) {
        temp = current;
        current = current->next;
    }

    if (temp == NULL) {
        head = NULL;
    } else {
        temp->next = NULL;
    }

    free(current);

    printf("Node deleted!");
}

void delete_between() {
    node *current = head, *temp = NULL;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (head == NULL || pos < 1) {
        printf("List is empty or position is invalid!");
        return;
    }

    if (pos == 1) {
        head = head->next;
        free(current);
        printf("Node deleted!");
        return;
    }

    for (i = 1; i < pos && current != NULL; i++) {
        temp = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position!");
        return;
    }

    temp->next = current->next;
    free(current);

    printf("Node deleted!");
}
