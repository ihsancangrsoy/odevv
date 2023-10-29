#include <stdio.h>
#include <stdlib.h>
typedef struct Student {
    int number;
    char name[50];
    int age;
    struct Student* next;
} Student;
void addStudent(Node** head, int number, char name[], int age) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->number = number;
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->next = *head;
    *head = newStudent;
}
void printStudents(Node* head) {
    Node* current = head;
    int count = 0;

    while (current != NULL) {
        printf("Student Number: %d, Name: %s, Age: %d\n", current->number, current->name, current->age);
        count++;
        current = current->next;
    }
    printf("\nTotal Students: %d\n", count);
}
void freeList(Node* head) {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
int main() {
    Node* head = NULL;
    addStudent(&head, 1, "Mert Müldür", 20);
    addStudent(&head, 2, "Eren Elmalý", 22);
    addStudent(&head, 3, "Serdar Dursun", 21);
    printf("Student Information:\n");
    printStudents(head);
    freeList(head);
    return 0;
}
