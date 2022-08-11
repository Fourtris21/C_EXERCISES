#include "homework_13.h"
#include "struct.h"
//struct Node* head = NULL;
void Zadacha_1()
{
	struct Node* head = NULL;
	struct Node* headEven = NULL;
	struct Node* headOdd = NULL;

	CreateList(&head);
	DivideToEvenOdd(&head, &headEven, &headOdd);
	printf("Even:\n");
	PrintList(&headEven);
	printf("\n");
	printf("Odd\n");
	PrintList(&headOdd);
}
void Zadacha_2()
{
    struct Node* head = NULL;
    CreateList(&head);
	int data;
	printf("Create node, enter value: ");
	scanf("%d", &data);
	struct Node* newNode = CreateSingleNode(data);
	int node;
	printf("Enter where to put the node(it will be placed in front of given number of node in the list! )");
	scanf("%d", &node);
	InsertNodeAtPosition(&head, newNode, node-1);
    PrintList(&head);
}
void Zadacha_3()
{
	struct Node* head = NULL;
    CreateList(&head);
	PrintList(&head);
	int node;
	printf("Enter number of node in the list to be deleted \n");
	scanf("%d", &node);
	DeleteAtPosition(&head, node-1);
	PrintList(&head);
}
void Zadacha_4()
{
	struct Node* head = NULL;
	struct Node* head2 = NULL;
	CreateList(&head);
	printf("Create second list: ");
	CreateList(&head2);
	printf("Split the two lists: ");
	Split(&head, &head2);
	PrintList(&head);
}
void Zadacha_5()
{
	struct Node* head = NULL;
	CreateStack(&head);
	PrintList(&head);
}
void Zadacha_6()
{
	struct Node* head = NULL;
	struct Node* head2 = NULL;
	CreateStack(&head);
	CreateStack(&head2);
	int* arr;
	arr = (int)malloc(30*sizeof(int));
	int size = SortTwoStacksInArray(&head, &head2, arr);
	 
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}
void Zadacha_7()
{
	struct CharNode* head = NULL;
	CreateCharStack(&head);
	char* word;
	word = (char*)malloc(20*sizeof(char));
	printf("Enter word: ");
	scanf("%s", word);
	CheckWord(&head, word);
	//PrintCharStack(&head);
}
void Zadacha_8()
{
	struct Node* head = NULL;
	struct Node* head2 = NULL;
	CreateStack(&head);
	CutNegative(&head, &head2);
	PrintList(&head2);
}
void Zadacha_9()
{
	struct CharNode* head = NULL;
	CreateCharStack(&head);
	CheckBalancedBrackets(&head);
}
void Zadacha_10()
{
	struct Node* head = NULL;
	int n;
	printf("Enter how many Fibonacci nums to display: ");
	scanf("%d", &n);
	PrintFibonacci(&head, n);
}
void Zadacha_11()
{
	struct Node* head = NULL;
	struct Node* head2 = NULL;
	int* arr;
	int n;
	printf("Enter how big is the num: ");
	scanf("%d", &n);
	arr = (int*)malloc(n*sizeof(int));
	printf("Enter the num with %d digits: ", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("This num written in stack: ");
	EnterNumInStack(&head, arr, n);
	printf("\nThis num written in queue: ");
	EnterNUmInQueue(&head2, arr, n);
}
void Zadacha_12()
{
	struct Node* head = NULL;
	int num;
	printf("Enter num: ");
	scanf("%d", &num);
	for (int i = 0; num > 0; i++)
	{
		Push(&head, num%2);
		num/=2;
	}
	PrintList(&head);
}

void WelcomeFunction()
{
    void (*zadacha_pointer[12])() = {Zadacha_1 ,Zadacha_2, Zadacha_3, Zadacha_4, Zadacha_5, Zadacha_6, Zadacha_7, Zadacha_8, Zadacha_9, Zadacha_10, Zadacha_11, Zadacha_12};
    printf("Enter 1 to 7 to choose Zadacha: ");
	int option;
	scanf("%d", &option);
	switch (option)
	{
	case 1:
		zadacha_pointer[0]();
		break;
	case 2:
		zadacha_pointer[1]();
		break;
	case 3:
		zadacha_pointer[2]();
		break;
	case 4:
		zadacha_pointer[3]();
		break;
	case 5:
		zadacha_pointer[4]();
		break;
	case 6:
		zadacha_pointer[5]();
		break;
	case 7:
		zadacha_pointer[6]();
		break;
    case 8:
		zadacha_pointer[7]();
		break;
    case 9:
		zadacha_pointer[8]();
		break;
    case 10:
		zadacha_pointer[9]();
		break;
    case 11:
		zadacha_pointer[10]();
		break;
    case 12:
		zadacha_pointer[11]();
		break;
	default:
		break;
	}
}