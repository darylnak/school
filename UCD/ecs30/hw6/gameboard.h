#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <stdbool.h>

typedef enum {RED_WINS, YELLOW_WINS, TIE, STILL_PLAYING} gamestate;
typedef enum {RED_PLAYER, YELLOW_PLAYER} player;
typedef enum {EMPTY, RED_COIN, YELLOW_COIN} square;

typedef struct {
    int numRows, numCols;
    int coinsInBoard;
    int squaresLeft;
    player currPlayer;
    gamestate state;
    square** squares;
} gameboard;

// allocates space for the gameboard and its squares
gameboard* gameboard_create(int numRows, int numCols);

// deallocates space for the gameboard and its squares
void gameboard_destroy(gameboard* board);

// sets coinsInBoard to 0, state to STILL_PLAYING, and all squares to EMPTY
void gameboard_initialize(gameboard* board);

// returns RED_COIN, YELLOW_COIN, or EMPTY depending on square (row, col)
square gameboard_square(const gameboard board, int row, int col);

// attempts to insert coin into column col for player p
bool gameboard_insert_coin(gameboard* board, int col, player p);

// prints the coins currently in the board
void gameboard_print(const gameboard board);

// returns true if STILL_PLAYING, false otherwise
bool gameboard_still_playing(const gameboard board);

// returns state field
gamestate gameboard_state(const gameboard board);

// check if game is over due to square (row, col) modification
void gameboard_check_square(gameboard* board, int row, int col);

// check horizontal strips containing square (row, col)
void gameboard_check_square_horizontal(gameboard* board, int row, int col);

// check vertical strips containing square (row, col)
void gameboard_check_square_vertical(gameboard* board, int row, int col);

// check diagonal strips containing square (row, col)
void gameboard_check_square_diagonal(gameboard* board, int row, int col);

// changes state to RED_WINS or YELLOW_WINS
void gameboard_declare_winner(gameboard* board, square color);

#endif
