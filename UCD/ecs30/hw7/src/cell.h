/*
* cell.h
* Name / StudentID
* A data structure modeling 2D integer Cartesian Cells
*/

#ifndef _COORDINATE_H_
#define _COORDINATE_H_

#include <stdbool.h>
#include <stdio.h>

typedef enum {OFF, ON, DYING} CellState;

typedef struct {
  int x, y;
  CellState s;
} Cell;

/*
* Input:
*      int x, an x-Cell
*      int y, a y-Cell
* Output:
*      A Cell
* Summary:
*      Initializes a Cell to (x,y)
*/
Cell Cell_Create(int x, int y, CellState s);

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
bool Cell_AreNeighbors(Cell C1, Cell C2);

/*
* Input:
*      Cell* C, a pointer to a Cell
* Summary:
*      Changes the Cell state of C to the next state.
*      OFF -> ON -> DYING -> OFF
*/
void Cell_NextState(Cell* C);

/*
* Input:
*      char* str, a string to read the cell from
* Output:
*      Returns a newly allocated list
* Summary:
*      Creates a cell from the file data
*/
Cell Cell_ReadCell(char* str);

/*
* Input;
* 			Cell C
* Ouptut:
* 			true if C has the corresponding CellState
*/
bool Cell_IsOff(Cell C);
bool Cell_IsOn(Cell C);
bool Cell_IsDying(Cell C);

#endif  /* _COORDINATE_H_ */
