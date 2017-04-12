/*
 * brians_brain.h
 * Name / StudentID
 * An implementation of Conway's Game of Life
 */

#ifndef _BRIANS_BRAIN_H_
#define _BRIANS_BRAIN_H_

#include <stdbool.h>

#include "cell_grid.h"
#include "cell.h"
#include "list.h"

/*
 * Input:
 *      int numRows, the number of rows in the game
 *      int numCols, the number of cols in the game
 * Output:
 *      Returns a CellGrid* that corresponds to the
 *		first generation game state
 * Summary:
 *      Returns the game state of the first generation
 */
CellGrid* FirstGeneration(int numRows, int numCols, List* seedCells);

/*
 * Input:
 *      CellGrid* generation, a pointer to a game state
 * Output:
 *      Returns a CellGrid*, a pointer to a game state
 * Summary:
 *      Calculates the game state of the generation directly
 *		after *generation and returns it
 */
CellGrid* NextGeneration(CellGrid* generation);

/*
 * Input:
 *      CellGrid* generation, a pointer to a game state
 *      Cell coord, a Cell of the game state
 * Output:
 *      Returns true if the Cell is CellIsOn
 * Summary:
 *      Checks if coord is a valid index of *generation and
 *		its corresponding Cell is CellIsOn
 */
bool CellIsOn(CellGrid* generation, int row, int col);

/*
 * Input:
 *      Cell coord, a Cell of the game state
 *      CellGrid* generation, a pointer to a game state
 * Output:
 *      Returns a List* to a List of neighboring Cells
 * Summary:
 *      Calculates neighboring Cells of *generation at coord and
 *		returns them as a List
 */
List* GetNeighboringCells(Cell coord, CellGrid* generation);

/*
 * Input:
 *      CellGrid* generation, a pointer to a game state
 *		List* neighbors, a List of neighbors of a Cell
 * Output:
 *      Returns the number of neighboring Cells that are on
 * Summary:
 *      Counts the number of Cells in *neighbors that
 *		correspond to live Cells in *generation
 */
int CountOnNeighborCells(CellGrid* generation, List* neighbors);

#endif  /* _BRIANS_BRAIN_H_ */
