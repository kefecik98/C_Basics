/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw13.h"

/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
#ifdef TEST_MAIN

int main(int argc, char **argv)
{
	// if argc is less than 2 then, return EXIT_FAILURE
	// input file is specified through the Makefile.
	if (argc < 2){
		printf("not enough arguments\n");
		return EXIT_FAILURE;
	}
	char * filename = argv[1];
	// open file to read
	FILE * ptr = fopen(filename, "rf");
	// check for fopen fail. If so, return EXIT_FAILURE
	if (ptr == NULL){
		printf("fptr is null\n");
		return EXIT_FAILURE;
	}
	// count the number of integers in the file.
	int count = 0;
	int temp;
	while(fscanf(ptr, "%d", &temp) == 1){
    count++;
	}
	// allocate memory to store the numbers
	int *arr = malloc(sizeof(int)*count);
	// check for malloc fail, if so, return EXIT_FAILURE
	if (arr == NULL){
		printf("array malloc failed\n");
		return EXIT_FAILURE;
	}
	// use fscanf to read the file, and store its contents into an array.
	fseek(ptr, 0, SEEK_SET);
	int index = 0;
	while (fscanf(ptr, "%d", &arr[index]) == 1){
		index++;
	}
	// create head node to store the head of the linked list.
	Node * headnode = NULL;
	// call the appropriate function to create the rest of the linked list, with the values of the array.
	LinkedListCreate(&headnode, count, arr);
	// Divide is a function to break the lists into smaller sublists.
		// You are supposed to find the mid-point of the list, and then break the list into two lists.
		// Then the sub-lists are broken down further into smaller sub-lists.
		// Refer to the example in the README
	Divide(&headnode);
	// Tip: check for memory errors.
	free(arr);
	fclose(ptr);
	return EXIT_SUCCESS;
}

#endif
