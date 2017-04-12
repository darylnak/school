#include <stdio.h>
#include <stdlib.h>

int main(void) {
   FILE* inFile = NULL; // File pointer
   int fileNum1;    // Data value from file
   int fileNum2;    // Data value from file

   // Try to open file
   printf("Opening file myfile.txt.\n");

   inFile = fopen("myfile.txt", "r");
   if (inFile == NULL) {
      printf("Could not open file myfile.txt.\n");
      return -1; // -1 indicates error
   }

   // Can now use fscanf(inFile, ...) like scanf()
   // myfile.txt should contain two integers, else problems
   printf("Reading two integers.\n");
   fscanf(inFile, "%d %d", &fileNum1, &fileNum2);

   // Done with file, so close it
   printf("Closing file myfile.txt.\n");
   fclose(inFile);

   // Output values read from file
   printf("num1 = %d\n", fileNum1);
   printf("num2 = %d\n", fileNum2);
   printf("num1+num2 = %d\n", (fileNum1 + fileNum2));

   return 0;
}
