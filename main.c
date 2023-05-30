#include "liste.h"

int main() {
    Node* head = NULL;
    int i, execution_time;

    printf("Introduceti timpii de executie pentru fiecare functie:\n");

    for (i = 0; i < 5; i++) {
        scanf("%d", &execution_time);
        insertNode(&head, execution_time);
    }

    printf("Timpii totali pentru fiecare functie (inclusiv apelurile din interior):\n");

    Node* current = head;
    i = 1;

    while (current != NULL) {
        int total_execution_time = getTotalExecutionTime(current);
        printf("Functia %d: %d\n", i, total_execution_time);
        current = current->next;
        i++;
    }

    printf("\n");

    int position, value;
    printf("Introduceti pozitia si valoarea pentru noul element:\n");
    scanf("%d %d", &position, &value);

    modifyExecutionTimeAtPosition(head, position, value);

    printf("Timpii totali actualizati pentru fiecare functie (inclusiv apelurile din interior):\n");

    current = head;
    i = 1;

    while (current != NULL) {
        int total_execution_time = getTotalExecutionTime(current);
        printf("Functia %d: %d\n", i, total_execution_time);
        current = current->next;
        i++;
    }

    // Eliberam memoria alocata pentru nodurile listei
    current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
