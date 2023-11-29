#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for an Aadhar number node
struct AadharNode {
    char aadhar[13];            // Aadhar number (12 characters + '\0')
    struct AadharNode* next;    // Pointer to the next node in the list
};

typedef struct AadharNode AadharNode; // Typedef for convenience

// Function to create a new Aadhar node
AadharNode* createNode(char aadharNumber[]) {
    AadharNode* newNode = (AadharNode*)malloc(sizeof(AadharNode)); // Allocate memory for the new node
    strcpy(newNode->aadhar, aadharNumber);                          // Copy Aadhar number to the node
    newNode->next = NULL;                                          // Initialize next pointer to NULL
    return newNode;                                                // Return the newly created node
}

// Function to insert an Aadhar node at the specified position in the linked list
AadharNode* insertAtPosition(AadharNode* head, int position, char aadharNumber[]) {
    if (position <= 0) {
        printf("Invalid position.\n");
        return head;
    }

    AadharNode* newNode = createNode(aadharNumber);

    if (position == 1) {  // Inserting at the beginning
        newNode->next = head;
        head = newNode;
    } else {
        AadharNode* current = head;
        for (int i = 1; i < position - 1 && current != NULL; i++) {
            current = current->next;
        }

        if (current == NULL) {
            printf("Position out of range.\n");
            return head;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    return head;
}

// Function to display the Aadhar numbers in the linked list
void displayList(AadharNode* head) {
    AadharNode* current = head;
    while (current != NULL) {
        printf("%s -> ", current->aadhar);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    AadharNode* head = NULL;

    

    // Insert Aadhar numbers of 4 employees
    head = insertAtPosition(head, 1, "123456789012");
    head = insertAtPosition(head, 2, "987654321012");
    head = insertAtPosition(head, 3, "567890123012");
    head = insertAtPosition(head, 4, "345678901012");

    printf("Initial list:\n");
    displayList(head);

    printf("Enter the position of the 5th employee's Aadhar number: ");
    int position;
    scanf("%d", &position);


    // Insert the Aadhar number of the 5th employee in the middle
    head = insertAtPosition(head, position, "654321098012");

    printf("\nList after inserting the 5th employee's Aadhar number:\n", position);
    displayList(head);

    return 0;
}
