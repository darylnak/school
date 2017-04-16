#include <stdlib.h>
#include <stdio.h>

// insertion sort, several errors

int X[10],  // input array
    NumInputs,  // length of input array
    NumY = 0;  // current number of 
               // elements in list

struct ListElt  {
   int Elt;
   struct ListElt *NextElt;
}; 

struct ListElt *Y;  // ptr to workspace list

void GetArgs(int AC, char **AV)

{  int I;

   NumInputs = AC - 1;
   for (I = 0; I < NumInputs; I++)
      X[I] = atoi(AV[I+1]);
}

void Insert(int NewY)

{  struct ListElt *NewElt,*P;

   NewElt = (struct ListElt *) 
            malloc(sizeof(struct ListElt));
   NewElt->Elt = NewY;
   NewElt->NextElt = 0;
   if (Y == 0)  { // Y empty so far, 
                  // easy case
      Y = NewElt;
      return;
   }
   // need to insert just before the first Y 
   // element that NewY is less than
   P = Y;
   if (NewY < P->Elt)  {
      NewElt->NextElt = P;
      Y = NewElt;
      return;
   }
   while (1)  {
      if (P->NextElt != 0)  {
         if (NewY < P->NextElt->Elt)  {
            NewElt->NextElt = P->NextElt;
            P->NextElt = NewElt;
            return;
         }
         else P = P->NextElt;
      }
      else  {
         P->NextElt = NewElt;
         return;
      }
   }
}

void ProcessData()

{  

   for (NumY = 0; NumY < NumInputs; NumY++)
      // insert new Y in the proper place 
      // in list
      Insert(X[NumY]);
}

void PrintResults()

{  int I; struct ListElt *P;

   P = Y;
   for (I = 0; I < NumInputs; I++)  {
      printf("%d\n",P->Elt);
      P = P->NextElt;
   }
}

int main(int Argc, char ** Argv)

{  

   GetArgs(Argc,Argv);
   ProcessData();
   PrintResults();
}
 
