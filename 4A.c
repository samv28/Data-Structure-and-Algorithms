#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNumber;
    char name[50];
    int age;
    struct Student* next;
};
int main() {
    // Creating nodes for three students
    struct Student n1 = {101, "Alice", 20, NULL};
    struct Student n2 = {102, "Bob", 21, NULL};
    struct Student n3 = {103, "Charlie", 19, NULL};

    // Linking the nodes to form a linked list
    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;

    // Printing the linked list
    struct Student* current = &n1;
    while (current != NULL) {
        printf("Roll Number: %d\n", current->rollNumber);
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("-------------------\n");

        current = current->next; // Move to the next node
    }
    return 0;
}
