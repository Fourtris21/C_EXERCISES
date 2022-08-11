#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int num;
    Node* next;
    Node* prev;
};
typedef struct Node* NodePtr;

void CreateNode(NodePtr* headRef)
{
    if(*headRef != NULL)
    {
         printf("\nThere is first created node, now you have to Insert, Delete or Print elements\n");
        return;
    }
    int data;
    printf("Enter value of first Node: ");
    scanf("%d", &data);
    InsertFront(headRef, data);

}
void PrintList(NodePtr* headRef)
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
        while (current!= NULL)
        {
            printf("%d\t", current->num);
            current = current->next;
        }
    }
}
void InsertFront(NodePtr* headRef, int data)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(NodePtr));
    newNode->num = data;
    newNode->next = *headRef;
    *headRef = newNode;
}
void InsertBack(NodePtr* headRef, int data)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(NodePtr));
    NodePtr current = *headRef;
    newNode->num = data;
    newNode->next = NULL;
    newNode->prev = NULL;
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
        newNode->prev = current;
    }
}
void InsertAtPosition(NodePtr* headRef, int pos, int data)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(NodePtr));
    NodePtr current = *headRef;
    newNode->num = data;
    newNode->next = NULL;
    newNode->prev = NULL;
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
        newNode->prev =current;
        temp->prev = newNode;
    }
}
void DeleteFront(NodePtr* headRef)
{
    NodePtr temp;
    NodePtr current = *headRef;
    if(current == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    temp = current->next;
    printf("Deleted element is %d", current->num);
    *headRef = temp;
    temp->prev = NULL;
    free(current);
}
void DeleteBack(NodePtr* headRef)
{
    NodePtr current = *headRef;
    if(current == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    for (int i = 0; i < Lenght(*headRef)-2; i++)
    {
        current = current->next;
    }
    NodePtr temp = current->next;
    printf("Deleted element os %d", temp->num);
    temp->prev = NULL;
    current->next = NULL;
    free(temp);
}
void DeleteAtPosition(NodePtr* headRef, int pos)
{
    NodePtr current = *headRef;
    NodePtr temp;
    NodePtr temp2;
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
    printf("Deleted element is %d", temp->num);
    temp2 = temp->next;
    current->next = temp2;
    temp2->prev = current;
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