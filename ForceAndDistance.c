// vAdd.c
//
// Program to add two vectors using a GPU

#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 10000000

extern void gpu_dot_product(int *a, int *b, int *c, int size);

int main (int argc, char *argv[])
{
   int *a = (int *) malloc(ARRAY_SIZE * sizeof(int));
   int *b = (int *) malloc(ARRAY_SIZE * sizeof(int));
   int *c = (int *) malloc(ARRAY_SIZE * sizeof(int));
   int i;
   int dot = 0;
   
   for (i=0; i < ARRAY_SIZE; i++) {
      	  	a[i] = i+1;
	 	b[i] = i+1;
	      	c[i] = 0;
   } 

//   for (i=0; i < ARRAY_SIZE; i++)
//      c[i] = a[i] * b[i];
	  
   gpu_dot_product (a, b, c, ARRAY_SIZE);
 
   printf ("Array c:\n");
   for (i=0; i < ARRAY_SIZE; i++)
	{
		 dot += c[i];
     }

      printf ("%d ", dot);
  
   
   free (a);
   free (b);
   free (c);
   
   return 0;
}