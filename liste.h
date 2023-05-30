#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int execution_time;
    struct Node* next;
} Node;

void insertNode(Node** head, int execution_time);

void modifyExecutionTimeAtPosition(Node* head, int position, int execution_time);

int getTotalExecutionTime(Node* head);
