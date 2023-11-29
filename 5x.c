#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to reverse a doubly linked list
void reverse(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* temp = NULL;

    // Swap next and prev pointers for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the next node
    }

    // Update the head pointer to the last node
    if (temp != NULL) {
        *head_ref = temp->prev;
    }
}

// Function to insert a node at the end of the list
void append(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
    } else {
        struct Node* last = *head_ref;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
        new_node->prev = last;
    }
}

// Function to print the doubly linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Appending nodes to the doubly linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    printf("Original List: ");
    printList(head);

    reverse(&head);

    printf("Reversed List: ");
    printList(head);

    return 0;
}
