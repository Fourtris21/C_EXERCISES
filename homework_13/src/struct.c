#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int num;
    struct Node* next;
};
typedef struct Node* NodePtr;
struct CharNode
{
    char value;
    struct CharValue* next;
};
typedef struct CharNode* CharNodePtr;
void CreateCharStack(CharNodePtr* head)
{
    if(*head != NULL)
    {
        printf("\nThere is created stack\n");
        PrintCharStack(head);
        return;
    }
    char data = NULL;
    int size = 0;
    printf("How many elements you want to enter at first: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("\nEnter char value of node: ");
        scanf(" %c", &data);
        PushInCharStack(head, data);
    }
}
void PrintCharStack(CharNodePtr* head)
{
    CharNodePtr current = *head;
    if(*head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    else
    {
        printf("\nThe list elements are:\n");
        while (current != NULL)
        {
            printf("%c \t", current->value);
            current = current->next;
        }
    }
}
void PushInCharStack(CharNodePtr* head, char value)
{
    CharNodePtr newNode = (CharNodePtr)malloc(sizeof(struct CharNode));
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}
char PopInCharStack(CharNodePtr* head)
{
    CharNodePtr temp;
    CharNodePtr current = *head;
    if(current == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    temp = current->next;
    printf("\nDeleted element is %c\n", current->value);
    
    *(head) = temp;
    return current->value;
    free(current);
}
void CreateList(NodePtr* headRef)
{
    if(*headRef != NULL)
    {
        printf("\nThere is created list\n");
        PrintList(headRef);
        return;
    }
    int data = 0;
    int size = 0;
    CreateFirstNode(headRef);
    printf("How many elements you want to enter at first: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("\nEnter value of node: ");
        scanf("%d", &data);
        InsertBack(headRef, data);
    }
}
void CreateFirstNode(NodePtr *headRef)
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
NodePtr CreateSingleNode(int data)
{
    NodePtr newNoed = (NodePtr)malloc(sizeof(struct Node));
    newNoed->num = data;
    newNoed->next = NULL;
}
void PrintList(NodePtr *headRef)
{
    NodePtr current = *headRef;
    if(*headRef == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    else
    {
        printf("\nThe list elements are:\n");
        do
        {
            printf("%d\t", current->num);
            current = current->next;
        }
        while (current != NULL);
    }
}
void InsertFront(NodePtr *headRef, int data)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(struct Node));
    newNode->num = data;
    newNode->next = *headRef;
    *headRef = newNode;
}
void InsertBack(NodePtr *headRef, int data)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(struct Node));
    NodePtr current = *headRef;
    newNode->num = data;
    newNode->next = NULL;
    if(*headRef == NULL)
    {
        *headRef = newNode;
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
void InsertNodeAtPosition(NodePtr *headRef, NodePtr node, int pos)
{
    NodePtr current = *headRef;
    if(current == NULL)
    {
        current = node;
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
        current->next = node;
        node->next = temp;
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
void DivideToEvenOdd(NodePtr *head, NodePtr *headEven, NodePtr *headOdd)
{
    NodePtr current = *head;
    if(current == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    while (current != NULL)
    {
        if(current->num % 2 == 0)
        {
            InsertBack(headEven, current->num);
        }
        else
        {
            InsertBack(headOdd, current->num);
        }
        current = current->next;
    }
}
void Split(NodePtr* head, NodePtr* head2)
{
    NodePtr current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = *head2;
}
void Push(NodePtr* headRef, int data)
{
    InsertFront(headRef, data);
}
int Pop(NodePtr* headRef)
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
    return current->num;
    free(current);
}
void CreateStack(NodePtr* headRef)
{
    if(*headRef != NULL)
    {
        printf("\nThere is created stack\n");
        PrintList(headRef);
        return;
    }
    int data = 0;
    int size = 0;
    printf("How many elements you want to enter at first: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("\nEnter value of node: ");
        scanf("%d", &data);
        Push(headRef, data);
    }
}
void CutNegative(NodePtr* head, NodePtr* head2)
{
    NodePtr current = *head;
    while (current != NULL)
    {
       if(current->num < 0)
       {
            Pop(&current);
       }
       else
       {
            int value = Pop(&current);
            Push(head2, value);
       }
       current = current->next;
    }
}
int* InsertionSort(int* arr, int n)
{
	int key, j;
	for (int i = 1; i < n; i++)
	{
		key = arr[i];
		j = i-1;
		while (j >= 0 && arr[j]> key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
	return arr;
}
int SortTwoStacksInArray(NodePtr *head, NodePtr *head2, int* arr)
{
    int pos = 0;
    NodePtr current = *head;
    NodePtr current2 = *head2;
    while (current != NULL)
    {
        int num = Pop(&current);
        arr[pos] = num;
        pos++;
    }
    while (current2 != NULL)
    {
        int num = Pop(&current2);
        arr[pos] = num;
        pos++;
    }
    arr = InsertionSort(arr, pos);
    return pos;
}
void CheckWord(CharNodePtr* head, char* word)
{
    CharNodePtr current = *head;
    int sizeOfWord = strlen(word);
    int tempCounter = 0;
    while (current != NULL)
    {
        if(tempCounter == sizeOfWord)
        {
            printf("The word is in the stack\n");
            return;
        }
        if(word[tempCounter] == current->value)
        {
            tempCounter++;
            current = current->next;
        }
        else
        {
            tempCounter = 0;
            current = current->next;
        }
    }
    if(tempCounter != sizeOfWord)
    {
        printf("The word is not in the stack");
    }
}
void Enqueue(NodePtr* head, int value)
{
    InsertBack(head, value);
} 
void PrintFibonacci(NodePtr* head, int n)
{
    if(n == 1)
    {
        Enqueue(head, 1);
        return;
    }
    else
    {
        Enqueue(head, 1);
        Enqueue(head, 1);
        NodePtr current = *head;
        NodePtr prev = current;
        NodePtr prev2 = prev->next;
        for (int i = 0; i < n-2; i++)
        {
            int value = prev->num + prev2->num;
            Enqueue(head, value);
            prev = prev->next;
            prev2 = prev2->next;
        }
    }
    PrintList(head);
}
void EnterNumInStack(NodePtr* head, int* arr, int size)
{
    for (int i = size-1; i >= 0; i--)
    {
        Push(head, arr[i]);
    }
    PrintList(head);
}
void EnterNUmInQueue(NodePtr* head, int* arr, int size)
{
    for (int i = size-1; i >= 0; i--)
    {
        Enqueue(head, arr[i]);
    }
    PrintList(head);
}
void CheckBalancedBrackets(CharNodePtr* head)
{
    CharNodePtr current = *head;
    CharNodePtr temp = NULL;
    CharNodePtr temp2 = NULL;
    CharNodePtr temp3 = NULL;
    int counter = 0;
    while (current != NULL)
    {
        if(current->value == '[' || current->value == '{' || current->value == '(')
        {
            counter ++;
            char value = current->value;
            PushInCharStack(&temp, value);

        }
        if(current->value == ']' || current->value == '}' || current->value == ')')
        {
            counter--;
            char value = current->value;
            PushInCharStack(&temp2, value);
        }
        current = current->next;
    }
    while (temp2 != NULL)
    {
        char value = PopInCharStack(&temp2);
        PushInCharStack(&temp3, value);
    }
    
    while (temp != NULL || temp3 != NULL)
    {
        char value = PopInCharStack(&temp);
        char value2 = PopInCharStack(&temp3);
        if(value == '[' && value2 == ']')
        {
            if(temp != NULL && temp3 != NULL)
            {
                temp = temp->next;
                temp3 = temp3->next;
            }
        }
        else if(value == '{' && value2 == '}')
        {
            if(temp != NULL && temp3 != NULL)
            {
                temp = temp->next;
                temp3 = temp3->next;
            }
        }
        else if(value == '(' && value2 == ')')
        {
            if(temp != NULL && temp3 != NULL)
            {
                temp = temp->next;
                temp3 = temp3->next;
            }
        }
        else
        {
            printf("Not balanced !");
            return;
        }
    }
    if(counter == 0)
    {
        printf("Balanced!\n");
    }
    else
    {
        printf("Not balanced!\n");
    }
}

