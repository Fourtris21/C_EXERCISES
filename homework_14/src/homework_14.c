#include "homework_14.h"
#include "help_functions.h"
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void Zadacha_1()
{
	Node* head = NULL;
	Node* evenHead = NULL;
	Node* oddHead = NULL;

	int n, num;
	int counter1 = 0, counter2 = 0;
	printf("How many nums you want to enter: ");
	scanf("%d", &n);
	printf("Enter nums [1...101]\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		Enqueue(&head, num);
	}
	for (int i = 0; i < n; i++)
	{
		int num = Dequeue(&head);
		if(num % 2 == 0)
		{
			Enqueue(&evenHead ,num);
			counter1++;
		}
		else
		{
			Enqueue(&oddHead, num);
			counter2++;
		}
	}
	PrintQueue(&evenHead);
	PrintQueue(&oddHead);
}
void Zadacha_2()
{
	printf("Is prime? - %d\n",IsPrime(1));
	printf("NOD: %d\n", NOD(12,5));
	int arr[3] = {25, 5, 15};
	printf("NOD in array: %d\n", NodInArray(arr, 3));
}
void Zadacha_3()
{
    int size;
    printf("Enter size of matrix: ");
    scanf("%d", &size);
    GetStrangeMatrix(size);
}
void Zadacha_4()
{
    int n;
    printf("Enter size of matrix: ");
    scanf("%d", &n);
    GetSpiralMatrix(n);
}
void Zadacha_5()
{
	int arr[6] = {1,1,0,-1,-1};
	Proportion(arr, 5);
}
void Zadacha_6()
{
	int arr[5] = {1,3,5,7,9};
	printf("Max sum: %d\n", MaxSum(arr, 5));
	printf("Min sum: %d\n", MinSum(arr, 5));
}
void Zadacha_7()
{

}
void Zadacha_8()
{
	char* time;
	char* time2;
	time = (char*)malloc(11*sizeof(char));
	time2 =  malloc(11*sizeof(char));
	printf("Format: 00:00:00[AM/PM]\n");
	printf("Enter time: ");
	scanf("%s", time);
	//time2 = Time_24(time);
	strcpy(time2, Time_24(time));
	printf("%s", time2);
}
void Zadacha_9()
{
	int n, num;
	int* arr;
	printf("How many number rows you want to enter: ");
	scanf("%d", &n);
	printf("How many elements in each row you want: ");
	scanf("%d", &num);
	for (int i = 0; i < n; i++)
	{
		arr = (int*)malloc(num*sizeof(int));
		printf("Enter the array: ");
		for (int j = 0; j < num; j++)
		{
			scanf("%d", &arr[j]);
		}
		Check(arr, num);
		free(arr);
	}
}
void Zadacha_10()
{
	int size = 0;
	printf("How many digits there is in the card number: ");
	scanf("%d", &size);
	int* arr = (int)malloc(size*sizeof(int));
	printf("Enter the digits to check if the card is valid: ");
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	CheckCard(arr, size);
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