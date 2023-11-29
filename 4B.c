#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PANNode {
    char pan[11];
    struct PANNode* next;
};

typedef struct PANNode PANNode;

PANNode* createNode(const char panNumber[]) {
    PANNode* newNode = (PANNode*)malloc(sizeof(PANNode));
    strcpy(newNode->pan, panNumber);
    newNode->next = NULL;
    return newNode;
}

PANNode* insertAtBeginning(PANNode* head, const char panNumber[]) {
    PANNode* newNode = createNode(panNumber);
    newNode->next = head;
    return newNode;
}

void displayList(const PANNode* head) {
    const PANNode* current = head;
    while (current != NULL) {
        printf("%s -> ", current->pan);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    PANNode* head = NULL;

    // Insert PAN numbers of 4 employees
    head = insertAtBeginning(head, "ABCDE1234F");
    head = insertAtBeginning(head, "FGHIJ5678K");
    head = insertAtBeginning(head, "LMNOP9012Q");
    head = insertAtBeginning(head, "RSTUV3456W");

    printf("Initial list:\n");
    displayList(head);

    // Insert the PAN number of the 5th employee at the beginning
    head = insertAtBeginning(head, "XYZAB6789C");

    printf("\nList after inserting the 5th employee's PAN number:\n");
    displayList(head);

    return 0;
}
