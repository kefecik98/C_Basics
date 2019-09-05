//edit this file as required
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw18.h"

//Do Not Change this function
void PrintAnswer(ListNode* head, ListNode* min1, ListNode* min2)
{
	ListNode* temp = head;
	int i;
	while(temp!=NULL)
	{
		i = 0;
		while(i < head -> treenode->dimension)
		{
			if(i == 0)
				printf("(%d, ", temp->treenode->data[i]);
			else if(i == head -> treenode->dimension-1)
				printf("%d)\n", temp->treenode->data[i]);
			else
				printf("%d, ", temp->treenode->data[i]);
			i+=1;

		}
		temp = temp->next;
	}

	i = 0;
	while(i < head -> treenode->dimension)
	{
		if(i == 0)
			printf("(%d, ", min1->treenode->data[i]);
		else if(i == head -> treenode->dimension-1)
			printf("%d) <-> ", min1->treenode->data[i]);
		else
			printf("%d, ", min1->treenode->data[i]);
		i+=1;
	}

	i = 0;
	while(i < head -> treenode->dimension)
	{
		if(i == 0)
			printf("(%d, ", min2->treenode->data[i]);
		else if(i == head -> treenode->dimension-1)
			printf("%d)\n", min2->treenode->data[i]);
		else
			printf("%d, ", min2->treenode->data[i]);
		i+=1;
	}
}

/*
YOU CAN EDIT BELOW THIS COMMENT
*/

#ifdef TEST_MIN
void FindMin(ListNode* head)
{
	// find pair of ListNodes with least distance between them.
	// call print Function
	ListNode* min1;
	ListNode* min2;
	int minDist;
	ListNode* c = head;
	int size = 0;
	while (c != NULL)
	{
		size++;
		c = c->next;
	}
	c = head;
	ListNode * p = head;
	for(int i = 0; i < size; i++){
		p = head;
		for(int j = 0; j < size; j++){
			if((FindDist(p->treenode, c->treenode) < minDist) && (FindDist(p->treenode, c->treenode) != 0)){
				minDist = FindDist(p->treenode, c->treenode);
				if(p->treenode->data[0] < c->treenode->data[0]){
					min1 = p;
					min2 = c;
				}else{
					min1 = c;
					min2 = p;
				}
			}
			p = p->next;
		}
		c = c->next;
	}
	PrintAnswer(head, min1, min2);
	/*
	ENSURE the 2nd parameter of the print function (min1) is smaller than
	the 3rd parameter (min2).
	Look at README, and expected output for more details.
	*/

}
#endif


#ifdef TEST_DIST
int FindDist(TreeNode* x, TreeNode* y)
{
	//find the eucledian distance between
	// x->data and y->data
	// DO NOT FIND SQUARE ROOT (we are working with int)
	// return the distance'
	int dist = 0;
	for(int i = 0; i < x->dimension; i++){
		dist += (x->data[i] - y->data[i])*(x->data[i] - y->data[i]);
	}
	return dist;
}
#endif


#ifdef TEST_CREATENODE
ListNode* CreateNode(int n, int dim, int* arr)
{
	// check for malloc error
	ListNode * node = malloc(sizeof(ListNode));
	if (node == NULL){
		printf("node malloc in createNode failed\n");
		return NULL;
	}
	// initialize dim
	node->treenode->dimension = dim;
	// both left and right childern will be NULL
	node->treenode->left = NULL;
	node->treenode->right = NULL;
	// allocate memory for data
	node->treenode->data = malloc(sizeof(int)*dim);
	if (node->treenode->data == NULL){
		printf("treenode data malloc in createNode failed\n");
		return NULL;
	}
	for(int i = 0; i < dim; i++){
		node->treenode->data[i] = arr[i];
	}
	node->next = NULL;
	// return a ListNode
	return node;
}
#endif


#ifdef TEST_LINKEDLISTCREATE
void LinkedListCreate(ListNode ** head, int n, int dim, FILE* fptr)
{
	// create temp node using CreateNode
	int * arr = malloc(sizeof(int)*dim);
	char ch;
	for(int j = 0; j < n; j++){

		// read from file into an array, pass array to CreateNode
		for(int i = 0; i < dim; i++){
			ch = fgetc(fptr);
			arr[i] = atoi(&ch);
		}
		ListNode * temp1 = CreateNode(n, dim, arr);
		if (j == 0){
			*head = temp1;
		}
		temp1 = temp1->next;
		// assign temp to that node

		// use a loop to create nodes for the remaining elements of the list.
	}
	free(arr);
}
#endif
