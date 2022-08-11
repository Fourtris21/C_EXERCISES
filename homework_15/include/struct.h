#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    Node* next;
};
typedef struct node Node;
void Enqueue(Node**,Node**, int);
int Dequeue(Node**);
int GetFirstElement(Node**);
void PrintQueue(Node**);
void DeleteAtPosition(NodePtr *headRef, int pos);
void InsertBack(struct Node**, int);

#endif