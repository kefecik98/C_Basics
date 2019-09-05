/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw14.h"


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
//source: the head of the singly linkedlist.
//len: the length of the array.
//arr: the array with the contents of the input file.

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
// source is the head of the list to be split.
// head1 is the head of the upper sub-list.
// head2 is the head of the lower sub-list.

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

#ifdef TEST_MERGE
// upper is the upper sub-list to be merged
// lower is the lower sub-list to be merged
Node* Merge(Node* upper, Node* lower)
{
	// Check for the base cases. (When either sub-list is NULL)
  if (upper == NULL){
    return lower;
  }else if (lower == NULL){
    return upper;
  }
  Node * p;
	// Pick the larger between upper and lower, and recur appropriately.
  if (upper->value <= lower->value){
    p = upper;
    p->next = Merge(upper->next, lower);
  }else{
    p = lower;
    p->next = Merge(upper, lower->next);
  }
	// return the merged array
  return p;
}
#endif

#ifdef TEST_SORT
// source is the head of the list to for which MergeSort is to be performed.
void MergeSort(Node** source)
{
	// Declare a node, to hold the current head of the source list.
  Node * c = * source;
	// Declare nodes, to hold the two the heads of the two sub-lists.
  Node * h1;
  Node * h2;
	// Check for the base case -- length 0 or 1
		// if so, return;
  int size = 0;
  while (c != NULL)
  {
  	size++;
  	c = c->next;
  }
  if (size < 2){
	   return;
  }
  c = *source;
	// Use SpiltList() to partition the list into sub lists.
		// This will partiton the source list, into two lists (As done in the previous homework)
  SplitList(c, &h1, &h2);
	// Recursively sort the sub-lists by calling MergeSort() on the upper and lower sub-lists.
		// MergeSort() is a recursive function, and MergeSort() needs to be called
		// on both sub-lists (obtained after partitioning)
  MergeSort(&h1);
  MergeSort(&h2);
	// Merge the two sorted lists together, using the Merge()
  *source = Merge(h1, h2);

}
#endif
