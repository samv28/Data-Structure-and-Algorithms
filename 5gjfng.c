#include <stdio.h>
#include <stdlib.h>

struct Employee {
    long long int aadharNumber;
    struct Employee* next;
    struct Employee* prev;
};

void displayAadharList(struct Employee* head) {
    printf("\nList of Aadhar Numbers:\n");
    struct Employee* current = head;
    while (current != NULL) {
        printf("%lld\n", current->aadharNumber);
        current = current->next;
    }
}

void insertAtPosition(struct Employee** head, long long int aadharNumber, int position) {
    if (aadharNumber < 10000000000 || aadharNumber > 999999999999) {
        printf("Invalid Aadhar Card Number\n");
        return;
    }

    struct Employee* newNode = (struct Employee*)malloc(sizeof(struct Employee));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->aadharNumber = aadharNumber;

    if (position <= 1 || *head == NULL) {
        
        newNode->next = *head;
        newNode->prev = NULL;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
    } else {
       
        struct Employee* current = *head;
        int currentPosition = 1;
        while (currentPosition < position - 1 && current->next != NULL) {
            current = current->next;
            currentPosition++;
        }
        
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
}

int main() {
    struct Employee* head = NULL;

      // Create a doubly linked list of Aadhar numbers for 4 employees
    head = (struct Employee*)malloc(sizeof(struct Employee));
    head->aadharNumber = 195234567890;
    head->next = NULL;
    head->prev = NULL;

    struct Employee* second = (struct Employee*)malloc(sizeof(struct Employee));
    second->aadharNumber = 231145678901;
    second->next = NULL;
    second->prev = head;
    head->next = second;

    struct Employee* third = (struct Employee*)malloc(sizeof(struct Employee));
    third->aadharNumber = 345678902112;
    third->next = NULL;
    third->prev = second;
    second->next = third;

    struct Employee* fourth = (struct Employee*)malloc(sizeof(struct Employee));
    fourth->aadharNumber = 456789012312;
    fourth->next = NULL;
    fourth->prev = third;
    third->next = fourth;

    int choice;
    long long int aadharNumber;
    int position;

    do {
        printf("Menu:\n");
        printf("1. Add Aadhar Card\n");
        printf("2. Display Aadhar List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                do {
                    printf("Enter Aadhar Card Number: ");
                    scanf("%lld", &aadharNumber);
                    if (aadharNumber < 10000000000 || aadharNumber > 999999999999) {
                        printf("Invalid Aadhar Card Number. Please enter a 12-digit number.\n");
                    }
                } while (aadharNumber < 10000000000 || aadharNumber > 999999999999);
                printf("Enter position to insert (1-4) : ");
                scanf("%d", &position);
                if (position < 1 || position > 4) {
                    printf("position out of bound. Inserting aadhar number at the end\n");
                }
                insertAtPosition(&head, aadharNumber, position);
                break;
            case 2:
                displayAadharList(head);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);


    return 0;
}