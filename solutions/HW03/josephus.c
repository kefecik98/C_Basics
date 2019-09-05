// ***
// *** You MUST modify this file
// ***

#include "josephus.h"
#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_JOSEPHUS
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails,
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements
  int pass;
  pass = k * n;
  int counter = 0;

  for (int i = 0; i <= pass; i++)
    {
      if (arr[i % n] == 1)
      {
          pass += 1;
          continue;
      }
      if (((counter % k) == 0) && (i != 0))
      {
          counter = 0;
          printf("%d\n", (i - 1) % n);
          arr[i % n] = 1;
      }
      counter++;

    }

  // print the last one




  // release the memory of the array
  free (arr);
}
#endif
