#ifndef STRUCT_H
#define STRUCT_H

typedef struct Node Node;
void CreateNode(struct Node**);
void PrintList(struct Node**);
void InsertFront(struct Node**, int);
void InsertBack(struct Node**, int);
void InsertAtPosition(struct Node**, int, int);
void DeleteFront(struct Node**);
void DeleteBack(struct Node**);
void DeleteAtPosition(struct Node**, int);
int Lenght(struct Node*);
#endif