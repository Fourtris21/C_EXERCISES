#include "homework_11.h"
#include "structures.h"
#include "help_functions.h"
#include <stdlib.h>

void Zadacha_1()
{
   	struct Era* era;
    struct Era* era2;
	era = (struct Era*)malloc(sizeof(struct Era*));
    era2 = (struct Era*)malloc(sizeof(struct Era*));
	printf("Enter first era:\n");
	EnterEra(era);
	printf("Enter second era:\n");
	EnterEra(era2);
	Razlika_Mejdu_Epohite(era, era2);
	//PrintEra(era);
    //PrintEra(era2);
}
void Zadacha_2()
{
    struct Rect *screen;
	screen = (struct Rect*)malloc(sizeof(struct Rect*));
	MakePoint(screen);
}
void Zadacha_3()
{
	Employee *arr_boss[10];
	Employee *arr_employee[10];
	for (int i = 0; i < 10; i++)
	{
		arr_boss[i] = (Employee*)malloc(1*sizeof(struct Employee*));
		arr_employee[i] = (Employee*)malloc(1*sizeof(struct Employee*));
	}
	
    //Bosses in the firm:
	//Boss 1
	SetFirstName(arr_boss[0], "Petar");
	SetMiddleName(arr_boss[0], "Ivanov");
	SetLastName(arr_boss[0], "Petrov");
	SetPosition(arr_boss[0], "Big boss");
	SetInternship(arr_boss[0], 20);
	SetSalary(arr_boss[0], 2300);
	//Boss 2
	SetFirstName(arr_boss[1], "Ivan");
	SetMiddleName(arr_boss[1], "Ivanov");
	SetLastName(arr_boss[1], "Donev");
	SetPosition(arr_boss[1], "Big boss");
	SetInternship(arr_boss[1], 22);
	SetSalary(arr_boss[1], 3000);

	for (int i = 0; i < 2; i++)
	{
		Enter_Employee(arr_employee[i]);
	}
	printf("\nBosses in the firm:\n");
	puts(GetFirstName(arr_boss[0]));
	puts(GetMiddleName(arr_boss[0]));
	puts(GetLastName(arr_boss[0]));
	//puts(GetFirstName(arr_boss[1]) ,GetMiddleName(arr_boss[1]) ,GetLastName(arr_boss[1]));
	for (int i = 0; i < 2; i++)
	{
		Set_Boss(arr_employee[i], arr_boss);
	}
	
	for (int i = 0; i < 2; i++)
	{
		Info_Employee(arr_employee[i]);
	}
}
void Zadacha_4()
{
    Ptr ptr;
	ptr = Calculate('+');
	printf("%d\n", ptr(2,4));
}
void Zadacha_5()
{
    
}
void Zadacha_6()
{
    Node* node_arr[11];
	for (int i = 0; i < 10; i++)
	{
		node_arr[i] = (Node*)malloc(1*sizeof(struct Node*));
		SetNum(node_arr[i], 1);
		SetNextNum(node_arr[i], 2);
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d", GetNum(node_arr[i]));
		printf("\t");
		printf("%d", GetNextNum(node_arr[i]));
		printf("\n");
	}
}
void Zadacha_7()
{
    Watermelon* melon[5];
	Watermelon* pumpkin[5];
	int melonDiameter = 0;
	int pumpkinDiameter = 0;
	double melonWidth = 0.;
	double pumpkinWidth = 0.;

	for (int i = 0; i < 5; i++)
	{
		melon[i] = (Watermelon*)malloc(1*sizeof(struct Watermelon*));
		pumpkin[i] = (Watermelon*)malloc(1*sizeof(struct Watermelon*));
		SetDiameter(melon[i], (rand()%(140-15+1))+15);
		printf("%d\t", GetDiameter(melon[i]));
		SetWidth(melon[i], ((double)rand()*(3.5-0.5))/(double)RAND_MAX + 0.5);
		printf("%lf\n", GetWidth(melon[i]));
		SetDiameter(pumpkin[i], (rand()%(95-35+1))+35);
		printf("%d\t", GetDiameter(pumpkin[i]));
		SetWidth(pumpkin[i], ((double)rand()*(0.9-0.3))/(double)RAND_MAX + 0.3);
		printf("%lf\n", GetWidth(pumpkin[i]));
	}

	for (int i = 0; i < 5; i++)
	{
		melonDiameter += GetDiameter(melon[i]);
		pumpkinDiameter += GetDiameter(pumpkin[i]);
		melonWidth = GetWidth(melon[i]);
		pumpkinWidth = GetWidth(pumpkin[i]);
	}

	double radiusMelon = ((melonDiameter/5)/2)-(melonWidth/5);
	double radiusPumpkin = ((pumpkinDiameter/5)/2)-(pumpkinWidth/5);
	double melonVolume = (4/3)*3.14*radiusMelon*radiusMelon*radiusMelon;
	double pumpkinVolume = (4/3)*3.14*radiusPumpkin*radiusPumpkin*radiusPumpkin;

	if(melonVolume > pumpkinVolume)
	{
		printf("Po-dobre e da si kupq 5 dini s diametar %d santimetra i kora s debelina %.2lf sm wmesto 5 dini s diametar %d sm i debelina na korata %.2lf sm.\n",melonDiameter/5, melonWidth/5, pumpkinDiameter/5, pumpkinWidth/5);
	}
	else
	{
		printf("Po-dobre e da si kupq 5 dini s diametar %d santimetra i kora s debelina %.2lf sm wmesto 5 dini s diametar %d sm i debelina na korata %.2lf sm.\n",pumpkinDiameter/5,pumpkinWidth/5, melonDiameter/5, melonWidth/5);
	}
}
void Zadacha_8()
{
    Fraction* newFraction = CreateFraction(2,4);
	Fraction* newFraction2 = CreateFraction(3,5);
	PrintFraction(newFraction2);
	Fraction* newFraction3 = CreateFractionByInput();
	PrintFraction(newFraction3);
	Fraction* newFraction4 = Divide(newFraction, newFraction2);
	PrintFraction(newFraction4);
}
void WelcomeFunction()
{
    void (*zadacha_pointer[10])() = {Zadacha_1 ,Zadacha_2, Zadacha_3, Zadacha_4, Zadacha_5, Zadacha_6, Zadacha_7, Zadacha_8};
    printf("Enter 1 to 9 to choose Zadacha: ");
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
	default:
		break;
	}
}