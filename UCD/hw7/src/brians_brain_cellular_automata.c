/*
 * brians_brain_cellular_automata.c
 * Name / StudentID
 * A tester for brians_brain.h
 * Reads a seed (starting generation) from a file and runs
 * Conways' Game of Life, printing to stdout
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "brians_brain.h"
#include "cell.h"
#include "cell_grid.h"

#define MAX_BUFFER_SIZE 64

int main(int argc, char* argv[]) {
    char buffer[MAX_BUFFER_SIZE];
    FILE* fp;
    List* seed;
    CellGrid* currentGeneration, *nextGeneration;
    int rows, cols, generations, i;
    struct timespec sleepTime;
    sleepTime.tv_sec = 0;
    sleepTime.tv_nsec = 500000000L;
    if (argc != 3) {
        printf("Usage: %s <filename> <generations>\n", argv[0]);
        exit(0);
    }
    /* Get first generation Cells */
    fp = fopen(argv[1], "r");
    /* Get game parameters */
    fgets(buffer, MAX_BUFFER_SIZE, fp);
    sscanf(buffer, "%d %d", &rows, &cols);
    sscanf(argv[2], "%d", &generations);
    /* Get original configuration */
    seed = List_Read(fp);
    fclose(fp);
    /* Run game */
    printf("\033[H\033[J");
    printf("\033[%d;%dH", 0, 0);
    currentGeneration = FirstGeneration(rows, cols, seed);
    CellGrid_Print(currentGeneration, stdout);
    for (i = 1; i < generations; i++) {
      //  nanosleep(&sleepTime, NULL);
        nextGeneration = NextGeneration(currentGeneration);
        CellGrid_Delete(currentGeneration);
        currentGeneration = nextGeneration;
        printf("\033[H\033[J");
        printf("\033[%d;%dH", 0, 0);
        CellGrid_Print(currentGeneration, stdout);
    }
    CellGrid_Delete(currentGeneration);
    List_Delete(seed);
    return 0;
}
