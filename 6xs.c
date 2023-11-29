#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}



// Function to insert a node at a given position
void insertAtPosition(int data, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *newNode = createNode(data);
    if (position == 1) {
        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            struct Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    } else {
        struct Node *temp = head;
        for (int i = 1; i < position - 1; i++) {
            if (temp->next == head) {
                printf("Invalid position.\n");
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Node inserted at position %d.\n", position);
}

// Function to delete a node from a given position
void deleteFromPosition(int position) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *temp = head, *prev;
    int i;
    for (i = 1; i < position; i++) {
        if (temp->next == head) {
            printf("Invalid position.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp == head && temp->next == head) {
        head = NULL;
        free(temp);
    } else if (temp == head) {
        prev = head;
        while (prev->next != head)
            prev = prev->next;
        head = head->next;
        prev->next = head;
        free(temp);
    } else {
        prev->next = temp->next;
        free(temp);
    }

    printf("Node deleted from position %d.\n", position);
}

void searchAndDelete(int data) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    // Traverse the circular linked list
    do {
        if (temp->data == data) {
            if (temp == head) {
                // If the element to be deleted is the head
                if (temp->next == head) {
                    head = NULL;
                } else {
                    head = head->next;
                    prev->next = head;
                }
                free(temp);
                printf("Node with data %d deleted.\n", data);
                return;
            } else {
                // Element to be deleted found in the middle
                prev->next = temp->next;
                free(temp);
                printf("Node with data %d deleted.\n", data);
                return;
            }
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    // Element not found in the list
    printf("Node with data %d not found. Nothing deleted.\n", data);
}


// Function to display the circular linked list
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("Head\n");
}

int main() {
    int choice, data, position;

    do {
        printf("\nMenu:\n");
        printf("1. Display the list\n");
        printf("2. Insert at a position\n");
        printf("3. Delete from a position\n");
        printf("4. Search and delete\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayList();
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                displayList();
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
            case 4:
                printf("Enter data to search and delete: ");
                scanf("%d", &data);
                searchAndDelete(data);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
