#include "liste.h"

void insertNode(Node** head, int execution_time) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->execution_time = execution_time;
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

void modifyExecutionTimeAtPosition(Node* head, int position, int execution_time) {
    if (position < 0) {
        printf("Invalid position.\n");
        return;
    }

    Node* current = head;
    int i = 0;

    while (current != NULL && i < position - 1) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        printf("Invalid position.\n");
        return;
    }

    current->execution_time = execution_time;
}

int getTotalExecutionTime(Node* head) {
    int total_time = 0;
    Node* current = head;

    while (current != NULL) {
        total_time += current->execution_time;
        current = current->next;
    }

    return total_time;
}
