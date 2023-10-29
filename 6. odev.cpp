#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int number;
    char name[50];
    int age;
    struct Student* next;
} Student;

void addStudent(Student** head, int number, char name[], int age) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->number = number;
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->next = *head;
    *head = newStudent;
}

void findLongestName(Student* head, char longestName[], int* longestLength) {
    Student* current = head;
    *longestLength = 0;

    while (current != NULL) {
        int currentLength = strlen(current->name);
        if (currentLength > *longestLength) {
            *longestLength = currentLength;
            strcpy(longestName, current->name);
        }
        current = current->next;
    }
}
void freeList(Student* head) {
    Student* current = head;
    Student* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Student* head = NULL;

    addStudent(&head, 1, "Asýk Veysel", 20);
    addStudent(&head, 2, "Cengiz Kurtoglu", 22);
    addStudent(&head, 3, "Husamettin Varyemezoglu", 21);

    char longestName[50];
    int longestLength;

    findLongestName(head, longestName, &longestLength);

    printf("Longest Name: %s\n", longestName);
    printf("Length of Longest Name: %d\n", longestLength);

    freeList(head);

    return 0;
}
