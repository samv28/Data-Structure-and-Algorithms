#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL) {
        return newNode; // If the list is empty, the new node becomes the head
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode; // Insert at the end
        return head;
    }
}

// Function to perform a bubble sort on the linked list
Node* bubbleSort(Node* head) {
    if (head == NULL) {
        return NULL; // Empty list
    }

    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap the data in the nodes
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    return head;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // Insert elements into the linked list
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 8);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 6);

    printf("Original Linked List:\n");
    printList(head);

    // Sort the linked list using bubble sort
    head = bubbleSort(head);

    printf("\nSorted Linked List:\n");
    printList(head);

    // Clean up the memory by freeing the nodes
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
