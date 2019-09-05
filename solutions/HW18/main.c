// Edit this file as required
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw18.h"


#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
	// check for input error
  if (argc < 2){
    printf("need one argument\n");
    return EXIT_FAILURE;
  }
	// open the file
	// input file is in argv[1]
  char* fileName = argv[1];
  FILE * fptr = fopen(fileName, "r");
	// n is the element in the file
	// dim is the second element in the file
  char ch;
  int n, dim;
  ch = fgetc(fptr);
  n = atoi(&ch);
  ch = fgetc(fptr);
  dim = atoi(&ch);
	// the rest of the data in the file are the datapoints.
  ListNode * head;
	// call LinkedListCreate
  LinkedListCreate(&head, n, dim, fptr);
	// call FindMin
  FindMin(head);
}
#endif
