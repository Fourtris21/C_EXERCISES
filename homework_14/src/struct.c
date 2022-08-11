#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

struct node
{
   int data;
   struct node* next;
};
typedef struct node* NodePtr;

void Enqueue(NodePtr* head, int num)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(struct node));
    NodePtr curr_node = *head;
    newNode->data = num;
    newNode->next = NULL;
    if(*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        while (curr_node->next != NULL)
        {
            curr_node = curr_node->next;
        }
        curr_node->next = newNode;
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
    free(curr_node);
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
