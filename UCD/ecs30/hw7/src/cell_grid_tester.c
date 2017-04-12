/*
 * cell_grid_tester.c
 * Name / StudentID
 * A tester for cell_grid.h
 * Reads a CellGrid from stdin and prints it out
 */

#include <stdio.h>
#include <stdlib.h>

#include "cell_grid.h"

void flushStdin();

int main() {
    int numRows, numCols, row, col;
    char action;
    CellGrid* G;

    printf("Testing CellGrid_Create and CellGrid_Print\n");
    printf("Enter the number of rows & columns: ");
    scanf("%d %d", &numRows, &numCols);
    flushStdin();
    G = CellGrid_Create(numRows, numCols);
    do {
        printf("Type 'c' to enter a cell or 'q' to quit: ");
        action = getchar();
        if (action != 'c' && action != 'q') {
            printf("Invalid command.\n");
        } else if (action == 'c') {
            printf("Enter a row and index to update: ");
            int result = scanf("%d %d", &row, &col);
            flushStdin();
            if (result == 2) {
                CellGrid_SetCell(G, Cell_Create(row, col, ON));
            }
        }
    } while(action != 'q');
    printf("Your grid:\n");
    CellGrid_Print(G, stdin);
    printf("Done testing CellGrid_Create and CellGrid_Print\n");

    printf("Testing CellGrid_Update\n");
    CellState currentState = G->grid[0][0].s;
    CellState newValue = (CellState) (((int) currentState) + 1) % 3;
    CellGrid_Update(G, 0, 0);
    if (G->grid[0][0].s != newValue) {
        printf("Error testing CellGrid_Update: value has not changed\n");
    }
    printf("Done testing CellGrid_Update.\n");

    printf("Testing CellGrid_Inbounds\n");
    if (CellGrid_Inbounds(G, numRows, numCols)) {
        /* Testing out of bounds */
        printf("Error testing CellGrid_Inbounds: (%d,%d) should be out of bounds\n", numRows, numCols);
    }
    if (!CellGrid_Inbounds(G, 0, 0)) {
        /* Testing in bounds */
        printf("Error testing CellGrid_Inbounds: (0,0) should be in bounds\n");
    }
    printf("Done testing CellGrid_Inbounds.\n");
    
    printf("Testing CellGrid_Delete\n");
    CellGrid_Delete(G);
    printf("Done testing CellGrid_Delete.\n");   

    printf("Done running cell_grid_tester. This does not gaurantee full points or that your code is bug-free.\n");
    return 0;
}

void flushStdin() {
    char c;
    while ((c = getchar()) != EOF && c != '\n') {};
}