#include "struct.h"
#include <stdlib.h>

struct Node
{
    int num;
    struct Node* next;
};
typedef struct Node* NodePtr;

void CreateNode(NodePtr *headRef)
{
    if(*headRef != NULL)
    {
        printf("\nThere is first created node, now you have to Insert, Delete or Print elements\n");
        return;
    } 
    int data;
    printf("\nEnter value of first node: ");
    scanf("%d", &data);
    InsertFront(headRef, data);
}
void PrintList(NodePtr *headRef)
{
    NodePtr current = *headRef;
    if(current == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    else
    {
        printf("\nThe list elements are:\n");
        while (current != NULL)
        {
            printf("%d\t", current->num);
            current = current->next;
        }
    }
}
void InsertFront(NodePtr *headRef, int data)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(struct Node*));
    newNode->num = data;
    newNode->next = *headRef;
    *headRef = newNode;
}
void InsertBack(NodePtr *headRef, int data)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(struct Node*));
    NodePtr current = *headRef;
    newNode->num = data;
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
void InsertAtPosition(NodePtr *headRef, int pos, int data)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(struct Node*));
    NodePtr current = *headRef;
    newNode->num = data;
    newNode->next = NULL;
    if(current == NULL)
    {
        current = newNode;
    }
    else
    {
        for (int i = 0; i < pos-1; i++)
        {
            current = current->next;
            if(current == NULL)
            {
                printf("\nPosition not found\n");
                return;
            }
        }
        NodePtr temp = current->next;
        current->next = newNode;
        newNode->next = temp;
    }
}
void DeleteFront(NodePtr *headRef)
{
    NodePtr temp;
    NodePtr current = *headRef;
    if(current == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    temp = current->next;
    printf("\nDeleted element is %d\n", current->num);
    
    *(headRef) = temp;
    free(current);
}
void DeleteBack(NodePtr *headRef)
{
    NodePtr temp;
    NodePtr current = *headRef;
    if(current == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    for (int i = 0; i < Lenght(*(headRef))-2; i++)
    {
        current = current->next;
    }
    temp = current->next;
    current->next = NULL;
    printf("\nDeleted element id %d\n", temp->num);
    free(temp);
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
    printf("\nDeleted element is %d\n", temp->num);
    free(temp);
}
int Lenght(NodePtr head)
{
    int count = 0;
    NodePtr temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}