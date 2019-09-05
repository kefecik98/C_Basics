/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw13.h"

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


/********** Do Not modify the file above this line, you can modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int val)
//val: value of the element of the node to be created
{
	// Define a new variable of type Node
	// Initialize "next", and "value" appropriately
	// allocate memory for the new Node*
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
	//return the newNode
}
#endif

#ifdef TEST_LINKEDLISTCREATE
//head: the head of the singly linkedlist.
//len: the length of the array.
//arr: the array with the contents of the input file.

//This function will create and initialize the singly linkedlist with length=len,

void LinkedListCreate(Node * * source, int len, int* arr)
{
	// This function is similar to the one in HW12.
	// Tip: use CreateNode(arr[index])
	if (len < 0)
	{
		printf("invalid length");
	}
	Node * p = CreateNode(arr[0]);
	* source = p;
	// create linked list of length as 'length'
	for (int i = 1; i < len; i++)
	{
		p->next = CreateNode(arr[i]);
		p=p->next;
	}
	p->next = NULL;
}
#endif


#ifdef TEST_SPLIT
// source is the Node corresponding to the head of the list
// head1 is the list corresponding upper half of the list. (After Partition)
// head2 is the list corresponding lower half of the list. (After Partition)
void SplitList(Node* source, Node** head1, Node** head2)
{
	// Find the mid point of the list.
	Node* c = source;
	int size = 0;
	while (c != NULL)
	{
		size++;
		c = c->next;
	}
		//in case of an even number of nodes, mid point will be floor(<num_elements>/2)
			//Example: 1,2,3,4
				// The list should split into 1,2 and 3,4
  int listBreak;
	if (size % 2 == 0){
		listBreak = (size/2) - 1;
	}else{
		listBreak = (size/2);
	}
		//in case of an odd number of nodes, mid point will be <num_elements>/2
			//Example: 1,2,3,4,5
				// The list should split into 1,2,3 and 4,5
	c = source;
	size = 0;
	while (size < listBreak){
		c = c->next;
		size++;
	}
	*head1 = source;
	*head2 = c->next;
	c->next = NULL;
    	// Tip: head1 will point to the source node.
	// Tip: head2 will point to the mid-point of the list.
	// Tip: Ensure you break the link between the sub-lists.
}
#endif


#ifdef TEST_DIV
void Divide(Node** source)
{
	// Declare a node, to hold the current head of source list.
	Node* c = *source;
	// Declare nodes, to hold the two the heads of the two sub-lists.
	Node* h1;
	Node* h2;
	// Check for the base case -- length 0 or 1
		// if so, return;
	int size = 0;
	while (c != NULL)
	{
		size++;
		c = c->next;
	}

	if (size < 2){
		free(*source);
		return;
	}
	c = *source;
	// Use SpiltList(...) to partition the list into sub lists.
	SplitList(c, &h1, &h2);
	// Use LinkedListPrint(...); to print the upper sub-list.
	LinkedListPrint(&h1);
	// Use LinkedListPrint(...); to print the lower sub-list
	LinkedListPrint(&h2);
		// DO NOT USE YOUR OWN PRINT FUNCTION.

	 // Recursively Divide(...) both sub-lists, to find their respective mid-points
	 Divide(&h1);
	 Divide(&h2);

	 // till only one or no elements are left in the sub-lists.
}
#endif
