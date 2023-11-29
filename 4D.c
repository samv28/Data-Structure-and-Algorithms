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

    // Insert heights of 10 students
    head = insertAtEnd(head, 160.5);
    head = insertAtEnd(head, 172.0);
    head = insertAtEnd(head, 155.5);
    head = insertAtEnd(head, 168.0);
    head = insertAtEnd(head, 175.5);
    head = insertAtEnd(head, 162.5);
    head = insertAtEnd(head, 170.0);
    head = insertAtEnd(head, 165.0);
    head = insertAtEnd(head, 178.5);
    head = insertAtEnd(head, 157.0);

    printf("Initial list:\n");
    displayList(head);

    // Delete a student's data from the middle of the list (e.g., position 5)
    head = deleteFromMiddle(head, 5);
    printf("\nList after deleting a student's data from the middle:\n");
    displayList(head);

    // Delete a node from the beginning of the remaining list
    head = deleteFromBeginning(head);
    printf("\nList after deleting a node from the beginning:\n");
    displayList(head);

    // Delete a node from the end of the remaining list
    head = deleteFromEnd(head);
    printf("\nList after deleting a node from the end:\n");
    displayList(head);

    return 0;
}
