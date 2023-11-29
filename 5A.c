#include <stdio.h>
#include <stdlib.h>
#include<string.h>

// Structure to represent a student
struct Student {
    int rollNumber;
    char name[50];
    int age;
    struct Student* next;
    struct Student* prev;
};

// Function to create a new student node
struct Student* createStudent(int rollNumber, const char* name, int age) {
    struct Student* student = (struct Student*)malloc(sizeof(struct Student));
    if (student == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    student->rollNumber = rollNumber;
    strcpy(student->name, name);
    student->age = age;
    student->next = NULL;
    student->prev = NULL;
    return student;
}

// Function to print student information
void printStudents(struct Student* head) {
    struct Student* current = head;
    while (current != NULL) {
        printf("Roll Number: %d, Name: %s, Age: %d\n", current->rollNumber, current->name, current->age);
        current = current->next;
    }
}

int main() {
    // Create three student nodes
    struct Student* n1 = createStudent(1, "Alice", 20);
    struct Student* n2 = createStudent(2, "Bob", 21);
    struct Student* n3 = createStudent(3, "Charlie", 19);

    // Connect the nodes to form a double linked list
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;

    // Print student information
    printStudents(n1);

    // Free allocated memory for the nodes
    free(n1);
    free(n2);
    free(n3);

    return 0;
}
