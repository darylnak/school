#include <stdlib.h>

// Create a 2D array and initialize all values to 3
int** Construct2DArray(int numRows, int numCols) {
  // Allocate memory for an int array to hold an array of int arrays.
  int** array = malloc(numRows * sizeof(int*));

  // allocate memory for the the columns of each row
  for (int i = 0; i < numRows; i++) {
    array[i] = malloc(numCols * sizeof(int));

    // initialize the j'th column of row i to 3
    for (int j = 0; j < numCols; j++) {
      array[i][j] = 3;
    }
  }

  return array;
}

int** aray2D(int numrows, int numcols) {
  int** result = malloc(numrows * sizeof(int*));

  for (int i = 0; i < numrows; i++) {
    result[i] = malloc(numcols * sizeof(int));
    for (int j = 0; j < numcols; j++) {
      result[i][j] = 3;
    }
  }
  return result;
}

int LEQFive(IntListNode* node) {
  if (node == NULL) {
    return 0
  }
  else {
    if (node->data <= 5) {
      return 1 + LEQFive(node->next);
    }
    else {
      return LEQFive(node->next);
    }
  }
}

// recursive function to return numbers less than of equal to 5 (LEQFive)
int LEQFive (IntListNode* node) {
  // Base case: Return 0 if reached last Node
  if (node == NULL) {
    return 0;
  }
  else {
    if (node->data <= 5) {
      return (1 + LEQFive(node->next));
    }
    else {
      return LEQFive(node->next);
    }
  }
}
