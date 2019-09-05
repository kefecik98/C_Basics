/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw12.h"

#ifdef LINKEDLIST

// Do not modify the below program, we are using ifdef block for
// ease of grading. Please include this flag in your Makefile
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
			printf("%d",temp->value);
		}
		temp=temp->next;
	}
	printf("\n");

}
#endif


/********** Do Not modify the file above this line, you should modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int value)
{
	// allocate memory for the new Node*
	Node * p = malloc(sizeof(Node));
	// check memory allocation fails
	if (p == NULL)
	{
		printf("malloc failed in create node");
		return NULL;
	}
	// create a Node* with the value as 'value'(input argument).
	p -> value = value;
	p -> next = NULL;
	return p;
}
#endif

#ifdef TEST_LINKEDLISTCREATE
// 1. head: the head of the singly linkedlist.
// 2. length: the length of the singly linkedlist.

// This function creates and initializes a singly linkedlist with length as 'length'(input argument),
// The values of the nodes within the singly linkedlist will be the same as array indddices.
// For example, if the singly linkedlist length is 4, the value of the nodes will be 0 1 2 3
void LinkedListCreate(Node * * head, int length)
{
	// check if length is not negative
	if (length < 0)
	{
		printf("invalid length");
	}
	Node * p = CreateNode(0);
	* head = p;
	// create linked list of length as 'length'
	for (int i = 1; i < length; i++)
	{
		p->next = CreateNode(i);
		p=p->next;
	}
	// do not return anything
}
#endif



#ifdef TEST_JOSEPHUS

// 1. head: the head of the singly linkedlist.
// 2. k : this variable will be used for counting if count = k, the element will be out.
// 3. elemDivisible : this variable will be used for printing. When the number of
//    remaining nodes in linked list is divisible by elemDivisible then you should
//    print the remaining LinkedList with print functin provided to you.

// This function should solve the josephus problem using the singly linkedlist.

void Josephus(Node ** head, int k, int elemDivisible)
{
	// implement the algorithm here
	// remember to free the memory of the nodes
	// print the linked list using our function when number of nodes remaining is divisible by elemDivisible
	int size = 0;
	Node* c = *head;
	Node* p = *head;
	//Node* temp;
	while (c != NULL)
	{
		size++;
		c = c->next;
	}
	//int count = 0;
	//printf("size = %d\n", size);
	p = c;
	c = *head;
	int temp = size;
	for (int j = 0; j < temp - 1; j++)
	{
		for (int i = 0; i < k; i++)
  	{
			if(c->next == NULL)
				{
					p = c;
					c = *head;
				}
				else{
					p = c;
					c = c->next;
				}
			}
			if (c == *head)
			{
				*head = c->next;
				free(c);
				c = *head;
				size--;
			}else if (c->next == NULL){
				free(c);
				c = *head;
				size--;
				p->next = NULL;
			}else{
				p->next = c->next;
				free(c);
				c = p->next;
				size--;
			}
			if (size % elemDivisible == 0){
				LinkedListPrint(*head);
			}
	}


}

#endif
