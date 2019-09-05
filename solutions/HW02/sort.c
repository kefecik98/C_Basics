// ***
// *** You MUST modify this file, only the ssort function
// ***

#include "sort.h"
#include <stdio.h>
#include <stdbool.h>

static bool checkOrder(int * arr, int size)
// a static function is visible only in this file
// This function returns true if the array elements are
// in the ascending order.
// false, otherwise
{
  int ind;
  for (ind = 0; ind < (size - 1); ind ++)
    {
      if (arr[ind] > arr[ind + 1])
	{
	  return false;
	}
    }
  return true;
}

#ifdef TEST_SORT
void ssort(int * arr, int size)
{
  // This function has two levels of for
  // The first level specifies which element in the array
  // The second level finds the smallest element among the unsorted
  // elements

  // After finding the smallest element among the unsorted elements,
  // swap it with the element of the index from the first level
  
  // call checkOrder to see whether this function correctly sorts the
  // elements

  int tempSmallestIndex=0,tempNumber=0,i=0,j=0;
  
  for (i = 0; i < size - 1; i++)
    {
      tempSmallestIndex = i;
      for (j = i + 1; j < size; j++)
	{
	  if (arr[tempSmallestIndex] > arr[j])
	    tempSmallestIndex = j;
	}
      if (tempSmallestIndex != i)
	{
	  tempNumber = arr[i];
	  arr[i] = arr[tempSmallestIndex];
	  arr[tempSmallestIndex] = tempNumber;
	}
    
    }
  
  if (checkOrder(arr, size) == false)
    {
      fprintf(stderr, "checkOrder returns false\n");
    }
}
#endif
