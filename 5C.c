#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    unsigned long long aadhar; // Assuming Aadhar numbers are unsigned long long
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(unsigned long long aadhar) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->aadhar = aadhar;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertInMiddle(Node* head, unsigned long long aadhar) {
    if (head == NULL) {
        printf("List is empty. Cannot insert in the middle.\n");
        return;
    }

    Node* newNode = createNode(aadhar);

    // Traverse to the 3rd position
    int count = 1;
    Node* current = head;
    while (count < 2 && current->next != NULL) {
        current = current->next;
        count++;
    }

    if (count < 2) {
        printf("List does not have enough nodes. Cannot insert in the middle.\n");
        return;
    }

    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }

    current->next = newNode;
    newNode->prev = current;
}

void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("Aadhar: %llu\n", current->aadhar);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    unsigned long long aadharNumbers[5] = {111122223333, 444455556666, 777788889999, 123456789012, 987654321098};

    // Creating the initial list with 4 employees
    for (int i = 0; i < 4; i++) {
        Node* newNode = createNode(aadharNumbers[i]);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    printf("List before inserting the 5th employee's Aadhar number:\n");
    displayList(head);


    // Inserting the 5th employee's Aadhar number in the middle (at the 3rd position)
    insertInMiddle(head, aadharNumbers[3]);
    
    printf("\nList after inserting the 5th employee's Aadhar number in the middle:\n");
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
