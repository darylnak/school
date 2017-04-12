#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// Constants used throughout the program.
// This would allow us to easily change the game to use, say, 4 dice instead of 5
#define NUM_DICE 5
#define NUM_FACES 6
#define UNSCORED_CATEGORY -1

// Sets up the game. Seed rand and mark every category as unscored
void initializeGame(int categoryScores[NUM_FACES]);

// Marks all die as unsaved. Used at the start of a round
void resetsavedDice(bool savedDice[NUM_DICE]);

// Play one round of simple yahtzee
void playRound(bool savedDice[NUM_DICE], int dice[NUM_DICE]);

// Obtains saved dice from player
void getPlayerSaveDice(bool savedDice[]);

// Re-roll all die that are not saved
void rollAllUnsavedDice(bool savedDice[NUM_DICE], int dice[NUM_DICE]);

// Ask user for category and score round for that category if available
void scoreRound(int dice[NUM_DICE], int categoryScores[NUM_FACES]);

// Prints the current dice rolls and re-rolls remaining
void printRoundState(int dice[NUM_DICE], int roll);

// Prints current total score of all saved categories
void printTotalScore(int categoryScores[NUM_FACES]);

// Flush stdin buffer
void flushStdin();

// Plays simple yahtzee
//
// Simple yahtzee consists of 6 rounds. In each round, 5 dice are rolled,
// and they may be re-rolled twice. The player saves dice they wish to keep
// which will not be re-rolled.
int main() {
  int dice[NUM_DICE], categoryScores[NUM_FACES];
  bool savedDice[NUM_DICE];
  initializeGame(categoryScores);
  // Play and score all rounds
  for (int gamesPlayed = 0; gamesPlayed < NUM_FACES; ++gamesPlayed) {
    playRound(savedDice, dice);
    scoreRound(dice, categoryScores);
  }
  printf("Game over.\n");

  return 0;
}

//////////////////////////////////
//// INITIALIZATION FUNCTIONS ////

// Sets up the game. Seed rand and mark every category as unscored
void initializeGame(int categoryScores[NUM_FACES]) {
  for (int i = 0; i < NUM_FACES; ++i) {
    categoryScores[i] = UNSCORED_CATEGORY;
  }
  int seed;
  printf("Enter seed: ");
  scanf("%d", &seed);
  // Flush the input buffer after every scanf call.
  flushStdin();
  srand(seed);
}

// Marks all die as unsaved. Used at the start of a round
void resetsavedDice(bool savedDice[NUM_DICE]) {
  for (int i = 0; i < NUM_DICE; i++) {
    savedDice[i] = false;
  }
}

//////////////////////////////////////
//// END INITIALIZATION FUNCTIONS ////

///////////////////////////////////
//// PLAYING A ROUND FUNCTIONS ////

// Play one round of simple yahtzee
void playRound(bool savedDice[NUM_DICE], int dice[NUM_DICE]) {
  resetsavedDice(savedDice);
  // Initial roll before asking to save dice
  rollAllUnsavedDice(savedDice, dice);
  printRoundState(dice, 2);
  for (int roll = 0; roll < 2; ++roll) {
    getPlayerSaveDice(savedDice);
    rollAllUnsavedDice(savedDice, dice);
    printRoundState(dice, 1 - roll);
  }
}

// Obtains saved dice from player
void getPlayerSaveDice(bool savedDice[]) {
  char option;
  int die;
  bool reroll = false;
  while (!reroll) {
    printf("Enter dice to save or 'r' for reroll: ");
    // Read input and clear input buffer afterwards
    int scanfResult = scanf("%c", &option);
    flushStdin();
    // If some character successfully read
    if (scanfResult == 1) {
      // If user requests a reroll
      if (option == 'r') {
        reroll = true;
        continue;
      }
      // Else if user toggles saving of a die
      else if (isdigit(option) && 1 <= (die = atoi(&option)) && die <= NUM_DICE) {
        savedDice[die - 1] = !savedDice[die - 1];
        printf("Die %d is now %s\n", die, savedDice[die - 1] ? "saved" : "unsaved");
        continue;
      }
    }
    // Otherwise re-prompt for input
    printf("Error: invalid command. Enter 'r' for re-roll unsaved die or 1-5 to toggle saving die\n");
  }
}

// Re-roll all die that are not saved
void rollAllUnsavedDice(bool savedDice[NUM_DICE], int dice[NUM_DICE]) {
  for (int i = 0; i < NUM_DICE; i++) {
    if (!savedDice[i]) {
      dice[i] = 1 + rand() % NUM_FACES;
    }
  }
}

// Ask user for category and score round for that category if available
void scoreRound(int dice [NUM_DICE], int categoryScores[NUM_FACES]) {
  // Homework TODO: write code for this function. (COMPLETE)
  // This function should:
  // 1) Ask the user for a category to save the round score to
  // 2) Check if the input category is scored or not using UNSCORED_CATEGORY
  // 3) Score the result for category i in categoryScores[i - 1]
  // 4) Print the current total score
  char categoryChoice = '\0';
  int categoryNum = 0;

  while(true) {
    printf("Enter category to save score: ");
    int scanfResult = scanf("%c", &categoryChoice);
    flushStdin();

    if (scanfResult == 1 && isdigit(categoryChoice) && (categoryNum = atoi(&categoryChoice)) > 0 && categoryNum <= 6
    && categoryScores[categoryNum - 1] == -1) {
      categoryScores[categoryNum - 1] = 0;
      for (int i = 0; i < NUM_FACES - 1; i++) {
        if (dice[i] == categoryNum) {
          categoryScores[categoryNum - 1] += categoryNum;
        }
      }
      printTotalScore(categoryScores);
      break;
    }
    else {
      printf("Error: invalid command. Enter 1-6 to save to an unused category\n");
      continue;
    }
  }
};

///////////////////////////////////////
//// END PLAYING A ROUND FUNCTIONS ////

////////////////////////////
//// PRINTING FUNCTIONS ////

// Prints the current dice rolls and re-rolls remaining
void printRoundState(int dice[NUM_DICE], int rerollsLeft) {
  // Homework TODO: write code for this function. (COMPLETE)
  // Example output, if all dice are 1 and 2 rerolls are left:
  // Dice: 1 1 1 1 1
  // Rolls left: 2
  printf("Dice: ");
  for (int i = 0; i < NUM_DICE; i++) {
    if (i == NUM_DICE - 1) {
      printf("%d\n", dice[i]);
    }
    else {
      printf("%d ", dice[i]);
    }
  }
  printf("Rolls left: %d\n", rerollsLeft);
}

// Prints current total score of all saved categories
void printTotalScore(int categoryScores[NUM_FACES]) {
  // Homework TODO: write code for this function. (COMPLETE)
  // Example output, if the score for category i is 2i except
  // for category 2, which is unscored:
  // Category 1 score: 1
  // Category 2 score: not scored
  // Category 3 score: 6
  // Category 4 score: 8
  // Category 5 score: 10
  // Category 6 score: 12
  // Total Score: 27
  int totScore = 0;

  for (int i = 0; i < NUM_FACES; i++) {
    if (categoryScores[i] != -1) {
      printf("Category %d score: %d\n", i + 1, categoryScores[i]);
      totScore += categoryScores[i];
    }
    else {
      printf("Category %d score: n/a\n", i + 1);
    }
  }
  printf("Total Score: %d\n", totScore);
}

////////////////////////////////
//// END PRINTING FUNCTIONS ////

// Flush stdin buffer
void flushStdin() {
  char c;
  // Skip all characters until end-of-file marker
  // or new line / carriage return
  while ( (c = getchar()) != EOF &&
  c != '\n' &&
  c != '\r' ) {};
}
