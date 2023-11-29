#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for an Aadhar number node
struct AadharNode {
    long long int aadhar;            // Aadhar number (12 characters + '\0')
    struct AadharNode* next;    // Pointer to the next node in the listsds
};

typedef struct AadharNode AadharNode; // Typedef for convenience

// Function to create a new Aadhar node
AadharNode* createNode(long long int aadharNumber) {
    AadharNode* newNode = (AadharNode*)malloc(sizeof(AadharNode)); // Allocate memory for the new node
    newNode->aadhar = aadharNumber ;                          // Copy Aadhar number to the node
    newNode->next = NULL;                                          // Initialize next pointer to NULL
    return newNode;                                                // Return the newly created node
}

int count_int(long long int x){
    int count = 0;
    while(x){
        x /= 10;
        count++;
    }
    return count;
}
// Function to insert an Aadhar node at the specified position in the linked list
AadharNode* insertAtPosition(AadharNode* head, int position, long long int aadhar) {

        if (position <= 0) {
            printf("Invalid position.\n");
            return head;
        }
        AadharNode* newNode = createNode(aadhar);

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
        printf("%lld -> ", current->aadhar);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    AadharNode* head = NULL;
    int choice, position;
    long long int adhar;

    while (1) {
        printf("\nAadhar Number Menu:\n");
        printf("1. Insert Aadhar number\n");
        printf("2. Display Aadhar numbers\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Aadhar number: ");
                scanf("%lld", &adhar);
                do
                {
                    printf("Invalid Aadhar number.\n");
                    printf("Enter Aadhar number: ");
                    scanf("%lld", &adhar);
                } while (adhar > 999999999999 || adhar < 100000000000);
                
                printf("Enter position to insert: ");
                scanf("%d", &position);
                head = insertAtPosition(head, position, adhar);
                break;

            case 2:
                if (head == NULL) {
                    printf("List is empty.\n");
                } else {
                    printf("Aadhar Numbers:\n");
                    displayList(head);
                }
                break;

            case 3:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
