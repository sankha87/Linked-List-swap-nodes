//Add a node at the front:
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Node
{
	int data;
	struct Node *next;
};
Node* push(struct Node *head_ref, int new_data)
{
	struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = head_ref;
	head_ref = new_node;

	return head_ref;
}

void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
}

/* Function to swap nodes x and y in linked list by changing links */

Node* swapNodes(struct Node *head_ref, int x, int y)
{
	struct Node *currX = head_ref, *currY = head_ref, *prevX = NULL, *prevY = NULL;
	while (currX != NULL && currX->data != x)		// Search for x ( keep track of prevX and CurrX )
	{
		prevX = currX;
		currX = currX->next;
	}

	while (currY != NULL && currY->data != y)		// Search for y ( keep track of prevY and CurrY )
	{
		prevY = currY;
		currY = currY->next;
	}

	if (prevX != NULL)
		prevX->next = currY;
	else
		head_ref = currY;

	if (prevY != NULL)
		prevY->next = currX;
	else
		head_ref = currX;

	//swap next pointers
	struct Node *temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;

	return head_ref;
}

int main()
{
	struct Node *head = NULL;
	head = push(head, 7);
	head = push(head, 1);
	head = push(head, 6);
	head = push(head, 8);
	head = push(head, 9);
	printf("\n Created Linked list : \n");
	printList(head);
	head = swapNodes(head, 8, 1);
	printf("\n After swap, Linked list : \n");
	printList(head);
	_getch();
}