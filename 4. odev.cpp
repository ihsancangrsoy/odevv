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
void searchByName(Student* head, char name[]) {
    Student* current = head;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("ogrenci no: %d, isim: %s, Age: %d\n", current->number, current->name, current->age);
            found = 1;
        }
        current = current->next;
    }
    if (!found) {
        printf("boyle birisi yok %s\n", name);
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
    addStudent(&head, 1, "Lionel Messi", 20);
    addStudent(&head, 2, "Edin Visca", 22);
    addStudent(&head, 3, "Ugurcan Cakir", 21);
    printf("Search Results:\n");
    searchByName(head, "Mehmetcan");
    searchByName(head, "Lionel Messi");
    searchByName(head, "ROnaldo");
    freeList(head);
    return 0;
}
