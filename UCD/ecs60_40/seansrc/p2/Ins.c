#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

// insertion sort, several errors

int X[10],  // input array
    Y[10],  // workspace array  
    NumInputs,  // length of input array
    NumY = 0;  // current number of 
               // elements in Y

void GetArgs(int AC, char **AV)

{  int I;

   NumInputs = AC - 1;
   for (I = 0; I < NumInputs; I++)
      X[I] = atoi(AV[I+1]);
}

void ScootOver(int JJ)

{  int K;

   for (K = NumY; K > JJ; K--)
      Y[K] = Y[K-1];
}

void Insert(int NewY)

{  int J;

   if (NumY == 0)  { // Y empty so far,
                    // easy case
      Y[0] = NewY;
      return;
   }
   // need to insert just before the first Y
   // element that NewY is less than
   for (J = 0; J < NumY; J++)  {
      if (NewY < Y[J])  {
         // shift Y[J], Y[J+1],... rightward
         // before inserting NewY
         ScootOver(J);
         Y[J] = NewY;
         return;
      }
   }
   Y[NumY] = NewY;
}

void ProcessData()

{  

   for (NumY = 0; NumY < NumInputs; NumY++)
      // insert new Y in the proper place 
      // among Y[0],...,Y[NumY-1]
      Insert(X[NumY]);
}

void PrintResults()

{  int I;

   for (I = 0; I < NumInputs; I++)
      printf("%d\n",Y[I]);
}

int main(int Argc, char ** Argv)

{  

   GetArgs(Argc,Argv);
   ProcessData();
   PrintResults();
}
 
