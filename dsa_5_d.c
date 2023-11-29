#include <stdio.h>
#include <stdlib.h>

// Define a structure for a student node
struct StudentNode {
    float height;               // Height of the student
    struct StudentNode* next;   // Pointer to the next node in the list
};

typedef struct StudentNode StudentNode; // Typedef for convenience

// Function to create a new student node
StudentNode* createNode(float heightValue) {
    StudentNode* newNode = (StudentNode*)malloc(sizeof(StudentNode)); // Allocate memory for the new node
    newNode->height = heightValue;                                    // Assign the height value to the node
    newNode->next = NULL;                                            // Initialize next pointer to NULL
    return newNode;                                                  // Return the newly created node
}

// Function to insert a student node at the end of the linked list
StudentNode* insertAtEnd(StudentNode* head, float heightValue) {
    StudentNode* newNode = createNode(heightValue);

    if (head == NULL) {
        return newNode;  // If the list is empty, the new node becomes the head
    } else {
        StudentNode* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;  // Insert at the end
        return head;
    }
}

// Function to delete a student node from the middle of the list
StudentNode* deleteFromMiddle(StudentNode* head, int position) {
    if (position <= 0) {
        printf("Invalid position.\n");
        return head;
    }

    if (position == 1) {
        StudentNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    StudentNode* current = head;
    StudentNode* prev = NULL;

    for (int i = 1; i < position && current != NULL; i++) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of range.\n");
        return head;
    }

    prev->next = current->next;
    free(current);
    return head;
}

// Function to delete a student node from the beginning of the list
StudentNode* deleteFromBeginning(StudentNode* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    StudentNode* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a student node from the end of the list
StudentNode* deleteFromEnd(StudentNode* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    StudentNode* current = head;
    StudentNode* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    free(current);
    return head;
}

// Function to display the heights in the linked list
void displayList(StudentNode* head) {
    StudentNode* current = head;
    while (current != NULL) {
        printf("%.2f -> ", current->height);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    StudentNode* head = NULL;
    int choice;
    float height;

    while (1) {
        printf("\nStudent Height Menu:\n");
        printf("1. Insert student height\n");
        printf("2. Delete a student height\n");
        printf("3. Display student heights\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student height: ");
                scanf("%f", &height);
                head = insertAtEnd(head, height);
                break;

            case 2:
                if (head == NULL) {
                    printf("List is empty.\n");
                    break;
                }
                int position;
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteFromMiddle(head, position);
                break;

            case 3:
                if (head == NULL) {
                    printf("List is empty.\n");
                } else {
                    printf("Student Heights:\n");
                    displayList(head);
                }
                break;

            case 4:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
