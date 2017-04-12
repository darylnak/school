#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "gameboard.h"

int main() {
    printf("Enter the number of rows and columns of your gameboard: ");
    int rows, cols, currCol;
    scanf("%d %d", &rows, &cols);
    gameboard* board = gameboard_create(rows, cols);
    board->squaresLeft = board->numCols * board->numRows;
    // Homework TODO: complete this function
    while(gameboard_still_playing(*board)) {
      gameboard_print(*board);
      if (board->squaresLeft == 0) {
         board->state = TIE;
         printf("Game over: tie.");
         continue;
      }
      switch (board->currPlayer) {
         case RED_PLAYER:
            printf("Enter column for red coin: ");
            break;

         case YELLOW_PLAYER:
            printf("Enter column for yellow coin: ");
            break;

         default:
            printf("Something went wrong. Quitting...\n");
            return -1;
      }
      scanf(" %d", &currCol);
      gameboard_insert_coin(board, currCol, board->currPlayer);
   }
   gameboard_destroy(board);

   return 0;
}
