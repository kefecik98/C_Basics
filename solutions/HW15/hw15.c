/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw15.h"

#ifdef LINKEDLIST
// Do not modify this function.
void LinkedListPrint(Node * head)
{

	Node *temp = head;

	while(temp!=NULL)
	{
		if(temp->next!=NULL)
		{
			printf("%d,",temp->value);
		}
		else
		{
			printf("%d\n",temp->value);
		}
		temp=temp->next;
	}
}
#endif


/********** Do Not modify the file above this line, you can modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int val)
{
	/*
	Create a new Node with `value` set to `val`. Set `next` to NULL.
	*/
	Node * p = malloc(sizeof(Node));
	// check memory allocation fails
	if (p == NULL)
	{
		printf("malloc failed in create node");
		return NULL;
	}
	// create a Node* with the value as 'value'(input argument).
	p -> value = val;
	p -> next = NULL;
	return p;
}
#endif

#ifdef TEST_LINKEDLISTCREATE

void LinkedListCreate(Node ** head, char* name)
{
	/*
	Create a linked list from the input file referenced by `name`.
	*/
	FILE * fptr = fopen(name, "rb");
	// check for fopen fail. If so, return EXIT_FAILURE
	if (fptr == NULL){
		printf("fopen null\n");
	}
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
	}
	// use fscanf to read the file for its contents.
	fseek(fptr, 0, SEEK_SET);
	int index = 0;
	while (fscanf(fptr, "%d", &arr[index]) == 1){
		index++;
	}
	if (count < 0)
	{
		printf("invalid length\n");
	}

	Node * p = CreateNode(arr[0]);
	* head = p;
	// create linked list of length as 'length'
	for (int i = 1; i < count; i++)
	{
		p->next = CreateNode(arr[i]);
		p=p->next;
	}
	p->next = NULL;

	free(arr);
	fclose(fptr);
}
#endif
#ifdef TEST_REMOVED
//This function will remove repetitions of a linked list value.

void RemoveDuplicate(Node *headRef)
{
	/*
	This function will remove repetitions from the linked list referenced by headRef.
	Each time we check for a new Node in the linked list, we will check if it is distinct from
	the Nodes already present in the list ( upto the previous Node).
	So for each occurrence after its first, we will be deleting that node.
	To delete a node: we will map the next Node of the previous Node to the Node after the current Node.
	Print the linked list after all repetitions have been removed. Use the function given to you for priniting.
	*/
	Node * p = headRef;
	Node * c = headRef;
	Node * pm1 = headRef;
	int dup = 0;
	p = p->next;
	while (p != NULL){
		c = headRef;
		while (c != p){
			if (c->value == p->value){

				if (p->next == NULL){
					free(p);
					p = NULL;
					pm1->next = NULL;
				}else{
					pm1->next = p->next;
					free(p);
					p = pm1->next;
				}

				dup = 1;
				break;

			}else {
				c = c->next;
			}
		}

		if (dup == 1){
			dup = 0;
		}else{
			p = p->next;
			pm1 = pm1->next;
		}
	}
	LinkedListPrint(headRef);
}
#endif
