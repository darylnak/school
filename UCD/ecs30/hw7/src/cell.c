#include "cell.h"

#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
* Input:
*      int x, an x-Cell
*      int y, a y-Cell
* Output:
*      A Cell
* Summary:
*      Initializes a Cell to (x,y)
*/
Cell Cell_Create(int x, int y, CellState s) {
   Cell result;
   result.x = x;
   result.y = y;
   result.s = s;
   return result;
}

/*
* Input:
*      Cell C1, a Cell
*      Cell C2, another Cell
* Output:
*      true if C2 is a neighbor of C1, false otherwise
* Summary:
*      Checks if C1 and C2 are neighbors, that is, if they
*      are in adjacent squares (including squares that are
*      diagonally adjacent) and not equal
*/
bool Cell_AreNeighbors(Cell C1, Cell C2) {
   // TODO: complete this function
   if ((C1.x + 1 == C2.x && C1.y == C2.y) || (C1.x - 1 == C2.x && C1.y == C2.y) ||
      (C1.x == C2.x && C1.y + 1 == C2.y) || (C1.x == C2.x && C1.y - 1 == C2.y) ||
      (C1.x + 1 == C2.x && C1.y + 1 == C2.y) || (C1.x + 1 == C2.x && C1.y - 1 == C2.y) ||
      (C1.x - 1 == C2.x && C1.y + 1 == C2.y) || (C1.x - 1 == C2.x && C1.y - 1 == C2.y)) {
         return true;
   }
   return false;
}

/*
* Input:
*      Cell* C, a pointer to a Cell
* Summary:
*      Swaps the entries of the Cell pointed to by C
*/
void Cell_NextState(Cell* C) {
   switch (C->s) {
      case OFF:
         C->s = ON;
      break;
      case ON:
         C->s = DYING;
      break;
      case DYING:
         C->s = OFF;
      break;
   }
   return;
}

/*
* Input:
*      FILE* fp, a file pointer pointing to a read-only open file
* Output:
*      Returns a newly allocated list
* Summary:
*      Creates a cell from the file data
*/
Cell Cell_ReadCell(char* str) {
   char s = 'A';
   int row, col;
   if (sscanf(str, "%d %d %c", &row, &col, &s) != 3) {
      fprintf(stderr, "Error reading cell\n");
      exit(0);
   }
   CellState state;
   switch (s) {
      case 'O':
         state = ON;
         break;
      case 'D':
         state = DYING;
         break;
      default:
         fprintf(stderr, "Error: expected O or D for cell state\n");
         exit(0);
   }
   return Cell_Create(row, col, state);
}

/*
* Input;
*          Cell C
* Ouptut:
*          true if C has the corresponding CellState
*/
bool Cell_IsOff(Cell C) {
   return C.s == OFF;
}

bool Cell_IsOn(Cell C) {
   return C.s == ON;
}

bool Cell_IsDying(Cell C) {
   return C.s == DYING;
}
