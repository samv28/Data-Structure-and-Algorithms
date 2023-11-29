#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of the doubly linked list
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to print the doubly linked list in reverse
void printReverse(struct Node* head) {
    if (head == NULL) {
        return;
    }
    
    // Traverse to the end of the list
    while (head->next != NULL) {
        head = head->next;
    }

    // Print in reverse
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->prev;
    }
}
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Appending elements to the doubly linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    printf("list: ");
    printList(head);
    printf("Doubly Linked List in Reverse: ");
    printReverse(head);

    return 0;
}
