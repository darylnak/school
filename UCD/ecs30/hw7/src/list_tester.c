/*
 * list_tester.c
 * Name / StudentID
 * A tester for list.h
 * Reads Cells from stdin into a List and prints them out
 */

#include <stdio.h>
#include <stdlib.h>

#include "cell.h"
#include "list.h"

#define MAX_BUFFER_SIZE 64

void flushStdin();

int main() {
    char buffer[MAX_BUFFER_SIZE];
    char action;
    List* list = List_Create();
    do {
        printf("Type 'c' to enter a cell or 'q' to quit: ");
        action = getchar();
        flushStdin();
        if (action != 'c' && action != 'q') {
            printf("Invalid command.\n");
        } else if (action == 'c') {
            printf("Enter a cell: ");
            fgets(buffer, MAX_BUFFER_SIZE, stdin);
            List_PushFront(list, Cell_ReadCell(buffer));
        }
    } while(action != 'q');
    List_Print(list);
    List_Delete(list);
    return 0;
}

void flushStdin() {
    char c;
    while ((c = getchar()) != EOF && c != '\n') {};
}
