#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
struct Node* head = NULL;
int main()
{
	CreateNode(&head);
	PrintList(&head);
	InsertBack(&head, 3);
	InsertBack(&head, 4);
	InsertFront(&head, 5);
	PrintList(&head);
	DeleteFront(&head);
	PrintList(&head);
	InsertAtPosition(&head, 2, 66);
	PrintList(&head);
	DeleteAtPosition(&head, 2);
	PrintList(&head);
	DeleteBack(&head);
	PrintList(&head);
	CreateNode(&head);
	return (0);
}
