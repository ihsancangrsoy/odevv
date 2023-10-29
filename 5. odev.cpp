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

void deleteNextNodeByName(Student* head, char name[]) {
    Student* current = head;
    int found = 0;

    while (current != NULL && current->next != NULL) {
        if (strcmp(current->name, name) == 0) {
            Student* temp = current->next;
            current->next = temp->next;
            free(temp);
            found = 1;
            printf("hangi isimden sonraki silinsin %s.\n", name);
            break;
        }
        current = current->next;
    }

    if (!found) {
        printf("boyle bi ogrenci yok %s\n", name);
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

    addStudent(&head, 1, "Messi", 20);
    addStudent(&head, 2, "Ronaldo", 22);
    addStudent(&head, 3, "Ahmetcan Kaplan", 21);

    deleteNextNodeByName(head, "Ronaldo");
    deleteNextNodeByName(head, "Zidane");
    deleteNextNodeByName(head, "Ahmetcan Kaplan");

    printf("Updated Student Information:\n");
    Student* current = head;
    while (current != NULL) {
        printf("og. no: %d, Ýsim: %s, Yas: %d\n", current->number, current->name, current->age);
        current = current->next;
    }
    freeList(head);

    return 0;
}
