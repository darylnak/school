/*
 * cell_tester.c
 * Name / StudentID
 * A tester for cell.h
 * Tests the various Cell functions prototyped in cell.h and implemented in cell.c
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "cell.h"

#define MAX_BUFFER_SIZE 64

int main() {
    char buffer[MAX_BUFFER_SIZE];
    bool error = false;
    Cell C, D;
    /* Test Cell_Create */
    printf("Testing Cell_Create. Enter a Cell: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    C = Cell_ReadCell(buffer);
    printf("The distance from the origin to your Cell is %lf\n", sqrt(C.x*C.x + C.y*C.y));
    printf("Done testing Cell_Create.\n");

    /* Test Cell_AreNeighbors */
    printf("Testing Cell_AreNeighbors.\n");
    if (Cell_AreNeighbors(C, C)) {
        /* A Cell is not its own neighbor */
        printf("Error in Cell_AreNeighbors: a Cell is not its own neighbor.\n");
        error = true;
    }
    if (Cell_AreNeighbors(Cell_Create(0, 0, OFF), Cell_Create(2, 2, OFF))) {
        /* These Cells are too far */
        printf("Error in Cell_AreNeighbors: (0,0) and (2,2) are not neighbors.\n");
        error = true;
    }
    if (!Cell_AreNeighbors(Cell_Create(0, 0, OFF), Cell_Create(0, 1, OFF))) {
        /* Test neighbors */
        printf("Error in Cell_AreNeighbors: (0,0) and (0,1) are neighbors.\n");
        error = true;
    }
    if (!Cell_AreNeighbors(Cell_Create(0, 0, OFF), Cell_Create(1, 1, OFF))) {
        /* Test diagonal neighbors */
        printf("Error in Cell_AreNeighbors: (0,0) and (1,1) are neighbors.\n");
        error = true;
    }
    printf("Done testing Cell_AreNeighbors.\n");

    printf("Testing Cell_NextState.\n");
    D = Cell_Create(C.x, C.y, OFF);
    Cell_NextState(&D);
    if (Cell_IsOff(D)) {
        printf("Error in Cell_NextState, check your results.\n");
        error = true;
    }
    printf("Done testing Cell_NextState.\n");

    if (!error) {
        printf("No errors found. This does not gaurantee a full score, but you have passed all the tests in cell_tester. Congratulations!\n");
    }
    return 0;
}
