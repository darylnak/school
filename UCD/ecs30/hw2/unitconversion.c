#include <stdio.h>
#include <string.h>

int ToGallons(int totVolume, char initUnits);
int ToQuarts(int totVolume, char initUnits);
int ToPints(int totVolume, char initUnits);
int ToCups(int totVolume, char initUnits);
int ToOunces(int totVolume, char initUnits);

int main(void) {

  int inputVolume = 0;
  char inputUnits = '\0';
  char outputUnits = '\0';
  char outputUnitsSring[8] = "";

  printf("Enter your current measurement and unit of volume: ");
  scanf("%d", &inputVolume);
  scanf(" %c", &inputUnits);

  if (inputVolume >= 0 && (inputUnits == 'g' || inputUnits == 'q' || inputUnits == 'p' || inputUnits == 'c' || inputUnits == 'o')) {

    printf("Enter your desired unit of volume: ");
    scanf(" %c", &outputUnits);

    switch (outputUnits) {
      case 'g':
        strcpy(outputUnitsSring, "gallons");
        printf("You have %d %s of liquid.\n", ToGallons(inputVolume, inputUnits), outputUnitsSring);
        break;

      case 'q':
        strcpy(outputUnitsSring, "quarts");
        printf("You have %d %s of liquid.\n", ToQuarts(inputVolume, inputUnits), outputUnitsSring);
        break;

      case 'p':
        strcpy(outputUnitsSring, "pints");
        printf("You have %d %s of liquid.\n", ToPints(inputVolume, inputUnits), outputUnitsSring);
        break;

      case 'c':
        strcpy(outputUnitsSring, "cups");
        printf("You have %d %s of liquid.\n", ToCups(inputVolume, inputUnits), outputUnitsSring);
        break;

      case 'o':
        strcpy(outputUnitsSring, "ounces");
        printf("You have %d %s of liquid.\n", ToOunces(inputVolume, inputUnits), outputUnitsSring);
        break;

      default:
        printf("Error! Enter one of \'g\' for gallons, \'q\' for quarts, \'p\' for pints, \'c\' for cups, or \'o\' for ounces.\n");
        break;
    }
  }
  else {
    if (inputVolume < 0) {
      printf("Error! You entered a negative number.\n");
    }
    if (!(inputUnits == 'g' || inputUnits == 'q' || inputUnits == 'p' || inputUnits == 'c' || inputUnits == 'o')) {
      printf("Error! Enter one of \'g\' for gallons, \'q\' for quarts, \'p\' for pints, \'c\' for cups, or \'o\' for ounces.\n");
    }
  }

  return 0;
}

int ToGallons(int totVolume, char initUnits) {

  switch (initUnits) {

    case 'q':
      return (totVolume / 4);

    case 'p':
      return (totVolume / 8);

    case 'c':
      return (totVolume / 16);

    case 'o':
      return (totVolume / 128);

    default:
      return totVolume;
  }
}
int ToQuarts(int totVolume, char initUnits) {
   switch (initUnits) {
      case 'g':
         return (totVolume / 4);

      case 'p':
         return (totVolume / 2);

      case 'c':
         return (totVolume * 4);

      case 'o':
         return (totVolume * 32);

      default:
         return totVolume;
   }
}
int ToPints(int totVolume, char initUnits) {
   switch (initUnits) {

     case 'q':
       return (totVolume * 2);

     case 'g':
       return (totVolume / 8);

     case 'c':
       return (totVolume / 2);

     case 'o':
       return (totVolume / 16);

     default:
       return totVolume;
   }
}
int ToCups(int totVolume, char initUnits) {
   switch (initUnits) {

     case 'q':
       return (totVolume * 4);

     case 'g':
       return (totVolume * 16);

     case 'p':
       return (totVolume * 2);

     case 'o':
       return (totVolume / 8);

     default:
       return totVolume;
   }
}
int ToOunces(int totVolume, char initUnits) {
   switch (initUnits) {

     case 'q':
       return (totVolume * 32);

     case 'g':
       return (totVolume * 128);

     case 'c':
       return (totVolume * 8);

     case 'p':
       return (totVolume * 16);

     default:
       return totVolume;
   }
}
