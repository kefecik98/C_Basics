/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw15.h"

/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
#ifdef TEST_MAIN

int main(int argc, char **argv)
{
	// input argv[1] contains the name of the input file.
	// Check for the right number of input arguments.
  if (argc < 2){
    printf("need 2 arguments \n");
    return EXIT_FAILURE;
  }
  char * fileName = argv[1];
	//Initialize a linked list Node and use the file name from input arguments to create a linked list
  Node * headnode = NULL;
  LinkedListCreate(&headnode, fileName);
  //Remove all duplicates in the linked list created above.
  RemoveDuplicate(headnode);
	// release memory
  Node * c = headnode;
  Node * n;

  while(c != NULL){
    n = c->next;
    free(c);
    c = n;
  }

}

#endif
