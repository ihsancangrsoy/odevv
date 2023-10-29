#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
void addToBeginning(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
void addToEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
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
void addNumbersToList() {
    Node* head = NULL;
    int num;

    do {
        printf("sayi gir (cikmak icin -1): ");
        scanf("%d", &num);

        if (num != -1) {
            if (num % 2 != 0) {
                addToBeginning(&head, num);
            } else {
                addToEnd(&head, num);
            }
        }

    } while (num != -1);

    printf("\nson hal:\n");
    printList(head);

    freeList(head);
}

int main() {
    addNumbersToList();
    return 0;
}

