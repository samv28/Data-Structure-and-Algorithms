#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char pan[11]; // Assuming PAN numbers are 10 characters long (e.g., ABCDE1234F)
    struct Node *next;
    struct Node *prev;
} Node;

Node* createNode(char* pan) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->pan, pan);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(Node **header, char* pan) {
    Node* newNode = createNode(pan);

    if (*header == NULL) {
        *header = newNode;
    } else {
        newNode->next = *header;
        (*header)->prev = newNode;
        *header = newNode;
    }
}

void displayList(Node *header) {
    Node *current = header;
    while (current != NULL) {
        printf("PAN: %s\n", current->pan);
        current = current->next;
    }
}

int main() {
    Node *header = NULL;
    char panNumbers[5][11] = {"ABCDE1234F", "FGHIJ5678K", "LMNOP9012Q", "RSTUV3456W", "XYZAB6789C"};

    // Creating the initial list with 4 employees
    for (int i = 0; i < 4; i++) {
        insertAtBeginning(&header, panNumbers[i]);
    }

    printf("List before inserting the 5th employee's PAN number:\n");
    displayList(header);

    // Inserting the 5th employee's PAN number at the beginning
    insertAtBeginning(&header, panNumbers[4]);

    printf("\nList after inserting the 5th employee's PAN number:\n");
    displayList(header);

    // Free allocated memory for nodes
    Node *current = header;
    Node *temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
