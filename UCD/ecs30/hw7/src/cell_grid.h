/*
 * cell_grid.h
 * Name / StudentID
 * An implementation of a 2D Grid of Cells
 */

#ifndef _CELL_GRID_H_
#define _CELL_GRID_H_

#include "cell.h"

typedef struct {
    Cell** grid;       /* The grid */
    int numRows;       /* number of rows in grid */
    int numCols;       /* number of columns in grid */
} CellGrid;

/*
 * Input:
 *      int numRows, number of rows for new CellGrid
 *      int numCols, number of cols for new CellGrid
 * Output:
 *      A CellGrid* pointing to a newly allocated CellGrid
 * Summary:
 *      Allocates a new CellGrid with numRows rows and
 *      numCols cols and returns a pointer to it
 */
CellGrid* CellGrid_Create(int numRows, int numCols);

/*
 * Input:
 *      CellGrid* G, a pointer to a CellGrid to delete
 * Summary:
 *      De-allocates G, including grid, row by row
 */
void CellGrid_Delete(CellGrid* G);

/*
 * Input:
 *      CellGrid* G, a pointer to a CellGrid to delete
 *      int row, an index for a row of *M
 *      int col, an index for a column of *M
 * Output:
 *      The CellState in location row, col
 */
CellState CellGrid_GetState(const CellGrid* G, int row, int col);

/*
 * Input:
 *      CellGrid* G, a pointer to a CellGrid to update
 *      Cell C, the cell to set in G
 * Summary:
 *      Updates the (C.x, C.y) entry of G to be C
 */
void CellGrid_SetCell(CellGrid* G, Cell C);

/*
 * Input:
 *      CellGrid* G, a pointer to a CellGrid to update
 *      int row, an index for a row of *M
 *      int col, an index for a column of *M
 * Summary:
 *      Updates the (row,col) entry of the CellGrid pointed to
 *      by G with the entry element
 */
void CellGrid_Update(CellGrid* G, int row, int col);

/*
 * Input:
 *      CellGrid* G, a pointer to a CellGrid
 *      int row, an index for a row of *G
 *      int col, an index for a column of *G
 * Summary:
 *      Checks if (row,col) is a Cell in G
 */
bool CellGrid_Inbounds(const CellGrid* G, int row, int col);

/*
 * Input:
 *      CellGrid* G, a pointer to a CellGrid to print
 *      FILE* fp, a file opened for writing
 * Summary:
 *      Prints entries of the CellGrid pointed to by G
 *      as O's for ONs and # for DYINGs
 */
void CellGrid_Print(const CellGrid* G, FILE* fp);

#endif /* _CELL_GRID_H_ */
