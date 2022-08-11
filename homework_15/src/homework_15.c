#include "homework_15.h"
#include "help_functions.h"
#include "struct.h"

void Zadacha_1(void)
{
    int number_sweets = 0;
    printf("Enter how many sweets you want: ");
    scanf("%d", &number_sweets);
    (Check_1(number_sweets) > Check_2(number_sweets))? printf("%d", Check_2(number_sweets)) : printf("%d", Check_1(number_sweets));
}
void Zadacha_2(void)
{
	Node* head = NULL;
	Node* tail = NULL;
	Node* head2 = NULL;
	Node* tail2 = NULL;
	Node* tempHead = NULL;
	Node* tempTail = NULL;
	Enqueue(&head, &tail, 1);
	Enqueue(&head, &tail, 3);
	Enqueue(&head, &tail, 5);
	
	Enqueue(&head2, &tail2, 1);
	Enqueue(&head2, &tail2, 2);
	Enqueue(&head2, &tail2, 6);
	while (head != NULL || head2 != NULL)
	{
		if(GetFirstElement(&head) < GetFirstElement(&head2))
		{
			int data = Dequeue(&head);
			Enqueue(&tempHead, &tempTail, data);
		}
		else
		{
			int data = Dequeue(&head2);
			Enqueue(&tempHead, &tempTail, data);
		}
	}
	PrintQueue(&tempHead);
}
void Zadacha_3(void)
{

}
void Zadacha_4(void)
{
	Node* head = NULL;
	int num;
	int n;
	printf("Enter num of elements: ");
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		printf("Enter element: ");
		scanf("%d", &n);
		InsertBack(&head, n);
	}
	Node* curr_head = head;
	for (int i = 0; i < num; i++)
	{
		Node* temp_head = head;
		int curr_element = curr_head->data;
		int* arr = (int*)malloc(sizeof(int)*num);
		int counter = 0;
		while (temp_head != NULL)
		{
			if(temp_head->data == curr_element)
			{
				arr[counter] = 
				counter++

			}
		}
		
		
		
		
		
	}
	

}
void Zadacha_5(void)
{

}
void Zadacha_6(void)
{

}
void Zadacha_7(void)
{

}
void Zadacha_8(void)
{

}
void Zadacha_9(void)
{

}
void Zadacha_10(void)
{

}


void WelcomeFunction()
{
    void (*zadacha_pointer[10])() = {Zadacha_1 ,Zadacha_2, Zadacha_3, Zadacha_4, Zadacha_5, Zadacha_6, Zadacha_7, Zadacha_8, Zadacha_9, Zadacha_10};
    printf("Enter 1 to 10 to choose Zadacha: ");
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
	default:
		break;
	}
}