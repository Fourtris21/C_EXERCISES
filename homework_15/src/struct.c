#include "struct.h"


typedef struct node* NodePtr;

void Enqueue(NodePtr* head, NodePtr* tail, int num)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(struct node));
    NodePtr curr_node = *head;
    newNode->data = num;
    newNode->next = NULL;
    if(*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
       (*tail)->next = newNode;
        *tail = newNode;
    }
}
int Dequeue(NodePtr* head)
{
    NodePtr temp;
    NodePtr curr_node = *head;
    if(curr_node == NULL)
    {
        printf("Empty\n");
        return;
    }
    temp = curr_node->next;
    *head = temp;
    return curr_node->data;
}
int GetFirstElement(NodePtr *head)
{
    if(*head != NULL)
    {
        return (*head)->data;
    }
    return __INT_MAX__;
}
void PrintQueue(NodePtr* head)
{
    if(*head == NULL)
    {
        printf("Empty\n");
    }
    NodePtr curr_node = *head;
    while (curr_node != NULL)
    {
        printf("%d\t", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("\n");
}
void InsertBack(NodePtr *headRef, int num)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(struct Node*));
    NodePtr current = *headRef;
    newNode->data = num;
    newNode->next = NULL;
    if(current == NULL)
    {
        current = newNode;
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}
void DeleteAtPosition(NodePtr *headRef, int pos)
{
    NodePtr temp;
    NodePtr temp2;
    NodePtr current = *headRef;
    if(current == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    for (int i = 0; i < pos-1; i++)
    {
        current = current->next;
        if(current == NULL)
        {
            printf("\nPosition not found\n");
            return;
        }
    }
    temp = current->next;
    temp2 = temp->next;
    current->next = temp2;
    printf("\nDeleted element is %d\n", temp->data);
    free(temp);
}