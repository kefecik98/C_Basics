/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw14.h"


#ifdef LINKEDLIST
// Do not modify this function, we are using this within ifdef block for
// ease of grading.
void LinkedListPrint(Node * * source)
{

	Node *temp = * source;

	while(temp!=NULL)
	{
		if(temp->next!=NULL)
		{
			printf("%d,",temp->value);
		}
		else
		{
			printf("%d",temp->value);
		}
		temp=temp->next;
	}
	printf("\n");
}
#endif

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
	FILE * fptr = fopen(filename, "rb");
	// check for fopen fail. If so, return EXIT_FAILURE
	if (fptr == NULL){
		printf("fopen null\n");
		return EXIT_FAILURE;
	}
	// count the number of integers in the file.
	int count = 0;
	int temp;
	while(fscanf(fptr, "%d", &temp) == 1){
    count++;
	}
	// allocate memory to store the numbers
	int *arr = malloc(sizeof(int)*count);
	// check for malloc fail, if so, return EXIT_FAILURE
	if (arr == NULL){
		printf("array malloc failed\n");
		return EXIT_FAILURE;
	}
	// use fscanf to read the file for its contents.
	fseek(fptr, 0, SEEK_SET);
	int index = 0;
	while (fscanf(fptr, "%d", &arr[index]) == 1){
		index++;
	}
	// create head node, which corresponds to the head of the linked-list.
	Node * headnode = NULL;
	// You must now use the appropriate function to construct the remaining list.
	LinkedListCreate(&headnode, count, arr);
	// call MergerSort() function for final output.
		// This will call a recursive function.
		// The input list will be divided into two sub-lists recursively,
		// Then the contents of the sub-lists are compared and merged back to form the
		// sorted output list.
	MergeSort(&headnode);
	// use the provided function to print the final list.
	LinkedListPrint(&headnode);
	// Tip: Check for memory errors.
	Node *tmp;
	while(count > 0){
		tmp = headnode->next;
		free(headnode);
		headnode = tmp;
		count--;
	}
	free(arr);
	fclose(fptr);

	return EXIT_SUCCESS;
}

#endif
