#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNumber;
    char name[50];
    int age;
    struct Student* next;
};

// Function to perform a bubble sort on the linked list based on age
void bubbleSort(struct Student* head) {
    int swapped;
    struct Student* ptr1;
    struct Student* lptr = NULL;

    /* Checking for empty list */
    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->age > ptr1->next->age) {
                // Swap the data in the nodes
                int tempRollNumber = ptr1->rollNumber;
                ptr1->rollNumber = ptr1->next->rollNumber;
                ptr1->next->rollNumber = tempRollNumber;

                char tempName[50];
                strcpy(tempName, ptr1->name);   
                strcpy(ptr1->name, ptr1->next->name);
                strcpy(ptr1->next->name, tempName);

                int tempAge = ptr1->age;
                ptr1->age = ptr1->next->age;
                ptr1->next->age = tempAge;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    // Creating nodes for three students
    struct Student n1 = {101, "Alice", 20, NULL};
    struct Student n2 = {102, "Bob", 21, NULL};
    struct Student n3 = {103, "Charlie", 19, NULL};

    // Linking the nodes to form a linked list
    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;

    // Printing the unsorted linked list
    printf("Unsorted Linked List:\n");
    struct Student* current = &n1;
    while (current != NULL) {
        printf("Roll Number: %d\n", current->rollNumber);
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("-------------------\n");

        current = current->next; // Move to the next node
    }

    // Sort the linked list using bubble sort based on age
    bubbleSort(&n1);

    // Printing the sorted linked list
    printf("\nSorted Linked List (by Age):\n");
    current = &n1;
    while (current != NULL) {
        printf("Roll Number: %d\n", current->rollNumber);
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("-------------------\n");

        current = current->next; // Move to the next node
    }

    return 0;
}
