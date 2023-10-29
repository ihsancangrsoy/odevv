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
void freeList(Node* head) {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void bubbleSort(Node* head) {
    int swapped;
    Node* ptr1;
    Node* lptr = NULL;
    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data < ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    Node* head = NULL;

  
    for (int i = 0; i < 100; i++) {
        int randomNum = rand() % 1000; 
        addToBeginning(&head, randomNum);
    }

   
    printf("siralanmamis:\n");
    printList(head);

    
    bubbleSort(head);

    
    printf("\nsiralanmis hal:\n");
    printList(head);

    freeList(head);

    return 0;
}
