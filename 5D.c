#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float height;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(float height) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->height = height;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtEnd(Node** head, float height) {
    Node* newNode = createNode(height);

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("Height: %.2f\n", current->height);
        current = current->next;
    }
}

void deleteFromMiddle(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from the middle.\n");
        return;
    }

    Node* current = *head;
    int count = 1;

    while (count < position && current->next != NULL) {
        current = current->next;
        count++;
    }

    if (count < position) {
        printf("List does not have enough nodes. Cannot delete from the middle.\n");
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = current;
    }

    free(temp);
}

void deleteFromBeginning(Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from the beginning.\n");
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    free(temp);
}

void deleteFromEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from the end.\n");
        return;
    }

    Node* current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next = NULL;
    }

    free(current);
}

int main() {
    Node* head = NULL;
    float heights[10] = {165.5, 170.2, 175.0, 160.8, 180.1, 172.6, 168.3, 182.7, 176.4, 169.9};

    // Creating the initial list with 10 student heights
    for (int i = 0; i < 10; i++) {
        insertAtEnd(&head, heights[i]);
    }

    printf("List before deletions:\n");
    displayList(head);

    // Delete a student's data from the middle of the list (position 5)
    deleteFromMiddle(&head, 5);

    printf("\nList after deleting from the middle:\n");
    displayList(head);

    // Delete a node from the beginning of the remaining list
    deleteFromBeginning(&head);

    printf("\nList after deleting from the beginning:\n");
    displayList(head);

    // Delete a node from the end of the remaining list
    deleteFromEnd(&head);

    printf("\nList after deleting from the end:\n");
    displayList(head);

    // Free allocated memory for nodes
    Node* current = head;
    Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
