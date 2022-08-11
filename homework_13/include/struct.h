#ifndef STRUCT_H
#define STRUCT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
typedef struct CharNode CNode;
void CreateCharStack(struct CharNode**);
void PrintCharStack(struct CharNode**);
void PushInCharStack(struct CharNode**, char);
char PopInCharStack(struct CharNode**);
void CreateList(struct Node**);
void CreateFirstNode(struct Node**);
struct Node* CreateSingleNode(int);
void PrintList(struct Node**);
void InsertFront(struct Node**, int);
void InsertNodeAtPosition(struct Node**, struct Node*, int);
void InsertBack(struct Node**, int);
void InsertAtPosition(struct Node**, int, int);
void DeleteFront(struct Node**);
void DeleteBack(struct Node**);
void DeleteAtPosition(struct Node**, int);
int Lenght(struct Node*);
void DivideToEvenOdd(struct Node**, struct Node**, struct Node**);
void Split(struct Node**, struct Node**);
void Push(struct Node**, int);
int Pop(struct Node**);
void CreateStack(struct Node**);
void CutNegative(struct Node**, struct Node**);
int* InsertionSort(int*, int);
int SortTwoStacksInArray(struct Node**, struct Node**, int*);
void CheckWord(struct CharNode**, char*);
void Enqueue(struct Node**, int);
void PrintFibonacci(struct Node**, int);
void EnterNumInStack(struct Node**, int*, int);
void EnterNUmInQueue(struct Node**, int*, int);
void CheckBalancedBrackets(struct CharNode**);

#endif

