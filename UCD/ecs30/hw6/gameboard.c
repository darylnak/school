#include <stdlib.h>
#include <stdio.h>

#include "gameboard.h"

// allocates space for the gameboard and its squares
gameboard* gameboard_create(int numRows, int numCols) {
  if (numRows < 3 || numCols < 3) {
    fprintf(stderr, "Error: board must be at least 4x4\n");
    exit(0);
  }
  // Homework TODO(COMPLETE): complete this function by adding code here
  gameboard* result = malloc(sizeof(gameboard));
  result->squares = malloc(numRows * sizeof(square*));

  for (int i = 0; i < numRows; i++) {
    result->squares[i] = malloc(numCols * sizeof(square));
  }
  // keeping track of total rows and columns
  result->numRows = numRows;
  result->numCols = numCols;
  gameboard_initialize(result);
  return result;
}

// deallocates space for the gameboard and its squares
void gameboard_destroy(gameboard* board) {
  for (int i = 0; i < board->numRows; i++) {
    free(board->squares[i]);
  }
  free(board->squares);
  free(board);
}

// sets coinsInBoard to 0, state to STILL_PLAYING, and all squares to EMPTY
void gameboard_initialize(gameboard* board) {
  // Homework TODO(COMPLETE): define this function
  board->coinsInBoard = 0;
  board->state = STILL_PLAYING;

  for (int i = 0; i < board->numRows; i++) {
    for (int j = 0; j < board->numCols; j++) {
      board->squares[i][j] = EMPTY;
    }
  }
  // default starting player
  board->currPlayer = RED_PLAYER;
}

// returns RED_COIN, YELLOW_COIN, or EMPTY depending on square (row, col)
square gameboard_square(const gameboard board, int row, int col) {
  if (0 <= row && row < board.numRows && 0 <= col && col < board.numCols) {
    return board.squares[row][col];
  } else {
    fprintf(stderr, "Error: board index %d %d out of bounds\n", row, col);
    exit(EXIT_FAILURE);
  }
}

// attempts to insert coin into column col for player p
bool gameboard_insert_coin(gameboard* board, int col, player p) {
  // Homework TODO(COMPLETE): define this function

  if (col >= board->numCols) {
    exit(0);
  }
  else if (board->currPlayer == RED_PLAYER) {
    for (int i = 0; i < board->numRows; i++) {
      if (board->squares[i][col] == EMPTY) {
        if (i + 1 == board->numRows) {
          board->squares[i][col] = RED_COIN;
          gameboard_check_square(board, i, col);
          board->currPlayer = YELLOW_PLAYER;
          board->squaresLeft = board->squaresLeft - 1;
          return true;
        }
        continue;
      }
      else if ((i - 1) >= 0) {
        board->squares[i - 1][col] = RED_COIN;
        gameboard_check_square(board, i - 1, col);
        board->currPlayer = YELLOW_PLAYER;
        board->squaresLeft = board->squaresLeft - 1;
        return true;
      }
      printf("Column %d is full\n", col);
      return false;
    }
  }
  else {
    for (int i = 0; i < board->numRows; i++) {
      if (board->squares[i][col] == EMPTY) {
        if (i + 1 == board->numRows) {
          board->squares[i][col] = YELLOW_COIN;
          gameboard_check_square(board, i, col);
          board->currPlayer = RED_PLAYER;
          board->squaresLeft = board->squaresLeft - 1;
          return true;
        }
        continue;
      }
      else if ((i - 1) >= 0) {
        board->squares[i - 1][col] = YELLOW_COIN;
        gameboard_check_square(board, i - 1, col);
        board->currPlayer = RED_PLAYER;
        board->squaresLeft = board->squaresLeft - 1;
        return true;
      }
      printf("Column %d is full\n", col);
      return false;
    }
  }
  return false;
}

// prints the coins currently in the board
void gameboard_print(const gameboard board) {
  for (int i = 0; i < board.numRows; i++) {
    for (int j = 0; j < board.numCols; j++) {
      switch (gameboard_square(board, i, j)) {
        case EMPTY:
        printf("  ");
        break;
        case RED_COIN:
        printf("R ");
        break;
        case YELLOW_COIN:
        printf("Y ");
        break;
      }
    }
    printf("\n");
  }
  for (int j = 0; j < board.numCols - 1; j++) {
    printf("==");
  }
  printf("=\n");
}

// returns true if STILL_PLAYING, false otherwise
bool gameboard_still_playing(const gameboard board) {
  return board.state == STILL_PLAYING;
}

// returns state field
gamestate gameboard_state(const gameboard board) {
  return board.state;
}

// check if game is over due to square (row, col) modification
void gameboard_check_square(gameboard* board, int row, int col) {
  // Homework TODO: define this function
  gameboard_check_square_horizontal(board, row, col);
  gameboard_check_square_vertical(board, row, col);
  gameboard_check_square_diagonal(board, row, col);
}

// check horizontal strips containing square (row, col)
void gameboard_check_square_horizontal(gameboard* board, int row, int col) {
  // Homework TODO: define this function
  int winCount = 0;

  switch (board->currPlayer) {
    case RED_PLAYER:
    // check right - inclusive current coin
    for (int i = 0; i < 4; i++) {
      if ((col + i) < board->numRows) {
        if (board->squares[row][col + i] == RED_COIN) {
          winCount++;
          continue;
        }
        break;
      }
    }

    // check left - exclusive current coin
    for (int i = 1; i < 5; i++) {
      if ((col - i) >= 0) {
        if (board->squares[row][col - i] == RED_COIN) {
          winCount++;
          continue;
        }
        break;
      }
    }

    // check if current player won
    if (winCount == 4) {
      gameboard_print(*board);
      gameboard_declare_winner(board, board->squares[row][col]);
      return;
    }
    return;

    case YELLOW_PLAYER:
    // check right - inclusive current coin
    for (int i = 0; i < 4; i++) {
      if ((col + i) < board->numRows) {
        if (board->squares[row][col + i] == YELLOW_COIN) {
          winCount++;
          continue;
        }
        break;
      }
    }

    // check left - exclusive current coin
    for (int i = 1; i < 5; i++) {
      if ((col - i) >= 0) {
        if (board->squares[row][col - i] == YELLOW_COIN) {
          winCount++;
          continue;
        }
        break;
      }
    }

    // check if current player won
    if (winCount == 4) {
      gameboard_print(*board);
      gameboard_declare_winner(board, board->squares[row][col]);
      return;
    }
    return;

    default:
    printf("Something went wrong in horizontal check. Quitting...\n");
    exit(0);
  }
}

// check vertical strips containing square (row, col)
void gameboard_check_square_vertical(gameboard* board, int row, int col) {
  // Homework TODO: define this function
  int winCount = 0;

  switch (board->currPlayer) {
    case RED_PLAYER:
    // check up - inclusive current coin
    for (int i = 0; i < 4; i++) {
      if ((row - i) >= 0) {
        if (board->squares[row - i][col] == RED_COIN) {
          winCount++;
          continue;
        }
        break;
      }
    }

    // check down - exclusive current coin
    for (int i = 1; i < 5; i++) {
      if ((row + i) < board->numRows) {
        if (board->squares[row + i][col] == RED_COIN) {
          winCount++;
          continue;
        }
        break;
      }
    }

    // check if current player won
    if (winCount == 4) {
      gameboard_print(*board);
      gameboard_declare_winner(board, board->squares[row][col]);
      return;
    }
    return;

    case YELLOW_PLAYER:
    // check up - inclusive current coin
    for (int i = 0; i < 4; i++) {
      if ((row - i) >= 0) {
        if (board->squares[row - i][col] == YELLOW_COIN) {
          winCount++;
          continue;
        }
        break;
      }
    }

    // check down - exclusive current coin
    for (int i = 1; i < 5; i++) {
      if ((row + i) < board->numRows) {
        if (board->squares[row + i][col] == YELLOW_COIN) {
          winCount++;
          continue;
        }
        break;
      }
    }

    // check if current player won
    if (winCount == 4) {
      gameboard_print(*board);
      gameboard_declare_winner(board, board->squares[row][col]);
      return;
    }
    return;

    default:
    printf("Something went wrong in vertical check. Quitting...\n");
    exit(0);
  }
}

// check diagonal strips containing square (row, col)
void gameboard_check_square_diagonal(gameboard* board, int row, int col) {
  // Homework TODO: define this function
  int winCount = 0;

  if (board->currPlayer == RED_PLAYER) {
    // top right
    for (int i = 0; i < board->numCols && i < board->numRows && winCount < 4; i++) {
      if ((row - i)  >= 0 && (col + i) < board->numCols) {
        if (board->squares[row - i][col + i] == RED_COIN) {
          winCount++;
          continue;
        }
        break;
      }
    }
    for (int i = 1; i < board->numCols && i < board->numRows && winCount < 4; i++) {
      if ((row + i) < board->numRows && (col - i) >= 0) {
        if (board->squares[row + i][col - i] == RED_COIN) {
          winCount++;
          continue;
        }
        break;
      }
    }
    if (winCount == 4) {
      gameboard_print(*board);
      gameboard_declare_winner(board, board->squares[row][col]);
      return;
    }
    else {
      winCount = 0;

      for (int i = 0; i < board->numCols && i < board->numRows && winCount < 4; i++) {
        if ((row - i)  >= 0 && (col - i) >= 0) {
          if (board->squares[row - i][col - i] == RED_COIN) {
            winCount++;
            continue;
          }
          break;
        }
      }
      for (int i = 1; i < board->numCols && i < board->numRows && winCount < 4; i++) {
        if ((row + i) < board->numRows && (col + i) <= board->numCols) {
          if (board->squares[row + i][col + i] == RED_COIN) {
            winCount++;
            continue;
          }
          break;
        }
      }
      if (winCount == 4) {
        gameboard_print(*board);
        gameboard_declare_winner(board, board->squares[row][col]);
        return;
      }
    }
  }

  if (board->currPlayer == YELLOW_PLAYER) {
    // top right
    for (int i = 0; i < board->numCols && i < board->numRows && winCount < 4; i++) {
      if ((row - i)  >= 0 && (col + i) < board->numCols) {
        if (board->squares[row - i][col + i] == YELLOW_COIN) {
          winCount++;
          continue;
        }
        break;
      }
    }
    for (int i = 1; i < board->numCols && i < board->numRows && winCount < 4; i++) {
      if ((row + i) < board->numRows && (col - i) >= 0) {
        if (board->squares[row + i][col - i] == YELLOW_COIN) {
          winCount++;
          continue;
        }
        break;
      }
    }
    if (winCount == 4) {
      gameboard_print(*board);
      gameboard_declare_winner(board, board->squares[row][col]);
      return;
    }
    else {
      winCount = 0;

      for (int i = 0; i < board->numCols && i < board->numRows && winCount < 4; i++) {
        if ((row - i)  >= 0 && (col - i) >= 0) {
          if (board->squares[row - i][col - i] == YELLOW_COIN) {
            winCount++;
            continue;
          }
          break;
        }
      }
      for (int i = 1; i < board->numCols && i < board->numRows && winCount < 4; i++) {
        if ((row + i) < board->numRows && (col + i) <= board->numCols) {
          if (board->squares[row + i][col + i] == YELLOW_COIN) {
            winCount++;
            continue;
          }
          break;
        }
      }
      if (winCount == 4) {
        gameboard_print(*board);
        gameboard_declare_winner(board, board->squares[row][col]);
        return;
      }
    }
  }
  return;
}

// changes state to RED_WINS or YELLOW_WINS
void gameboard_declare_winner(gameboard* board, square color) {
  // Homework TODO: define this function
  switch (color) {
    case RED_COIN:
    board->state = RED_WINS;
    printf("Game over: red wins.\n");
    return;

    case YELLOW_COIN:
    board->state = YELLOW_WINS;
    printf("Game over: yellow wins.\n");
    return;

    default:
    printf("Something went wrong. Quitting...\n");
    exit(0);
  }
}
