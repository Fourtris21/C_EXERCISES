#include "structures.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct Era
{
	int century;
	int year;
	int month;
	int day;
	int minutes;
	int seconds;
};
typedef struct Era* EraPtr;
void SetEraCentury(EraPtr era, int century)
{
	era->century = century;
}
int GetEraCentury(EraPtr era)
{
	return era->century;
}
void SetEraYear(EraPtr era, int year)
{
    era->year = year;
}
int GetEraYera(EraPtr era)
{
    return era->year;
}
void SetEraMonth(EraPtr era, int month)
{
    era->month = month;
}
int GetEraMonth(EraPtr era)
{
    return era->month;
}
void SetEraDay(EraPtr era, int day)
{
    era->day = day;
}
int GetEraDay(EraPtr era)
{
    return era->day;
}
void SetEraMinutes(EraPtr era, int minutes)
{
    era->minutes = minutes;
}
int GetEraMinutes(EraPtr era)
{
    return era->minutes;
}
void SetEraSeconds(EraPtr era, int seconds)
{
    era->seconds = seconds;
}
int GetEraSeconds(EraPtr era)
{
    return era->seconds;
}

struct Point
{
	int x;
	int y;
};
typedef struct Point* PointPtr;
void SetPointX(PointPtr point, int x)
{
    point->x = x;
}
int GetPointX(PointPtr point)
{
    return point->x;
}
void SetPointY(PointPtr point, int y)
{
    point->y = y;
}
int GetPointY(PointPtr point)
{
    return point->y;
}
struct Rect
{
	PointPtr firstPoint;
	PointPtr secondPoint;
};
typedef struct Rect* RectPtr;
void SetFirstPoint(RectPtr rect, int x, int y)
{
	(rect->firstPoint) = (PointPtr) malloc(1*sizeof(struct Point*));
	SetPointX(rect->firstPoint, x);
	SetPointY(rect->firstPoint, y);
}
PointPtr GetFirstPoint(RectPtr rect)
{
	PointPtr point = rect->firstPoint;
	return point;
}
void SetSecondPoint(RectPtr rect, int x, int y)
{
	(rect->secondPoint) = (PointPtr) malloc(1*sizeof(struct Point*));
	SetPointX(rect->secondPoint, x);
	SetPointY(rect->secondPoint, y);
}
PointPtr GetSecondPoint(RectPtr rect)	
{
	PointPtr point = rect->secondPoint;
	return point;
}
struct Employee
{
	int id;
	char firstName[10];
	char middleName[10];
	char lastName[10];
	char position[20];
	int internship;
	double salary;
	struct Employee* boss;
};
typedef struct Employee* EmployeePointer;
void SetId(EmployeePointer emp, int* id)
{
	emp->id = *id;
}
void SetFirstName(EmployeePointer emp, char* f_name)
{
	strcpy(emp->firstName, f_name);
}
void SetMiddleName(EmployeePointer emp, char* m_name)
{
	strcpy(emp->middleName, m_name);
}
void SetLastName(EmployeePointer emp, char* l_name)
{
	strcpy(emp->lastName, l_name);
}
void SetPosition(EmployeePointer emp, char* position)
{
	strcpy(emp->position, position);
}
void SetInternship(EmployeePointer emp, int internship)
{
	emp->internship = internship;
}
void SetSalary(EmployeePointer emp, double salary)
{
	emp->salary = salary;
}
void Set_Boss(EmployeePointer emp, EmployeePointer *boss)
{
	int option;
	printf("Enter boss(1 or 2) for %s %s %s: ", (GetFirstName(emp)), (GetMiddleName(emp)), (GetLastName(emp)));
	scanf("%d", &option);
	switch (option)
	{
	case 1:
		emp->boss = boss[0]; 
		break;
	case 2:
		emp->boss = boss[1]; 
		break;
	default:
		break;
	}
}
int GetId(EmployeePointer emp)
{
	return emp->id;
}
char* GetFirstName(EmployeePointer emp)
{
	char* name = malloc(10);
	name = emp->firstName;
	return name;
}
char* GetMiddleName(EmployeePointer emp)
{
	char* name = malloc(10);
	name = emp->middleName;
	return name;
}
char* GetLastName(EmployeePointer emp)
{
	char* name = malloc(10);
	name = emp->lastName;
	return name;
}
char* GetPosition(EmployeePointer emp)
{
	char* position = malloc(20);
	position = emp->position;
	return position;
}
int GetInternship(EmployeePointer emp)
{
	return emp->internship;
}
double GetSalary(EmployeePointer emp)
{
	return emp->salary;
}
char* GetBossName(EmployeePointer emp)
{
	return emp->boss->firstName;
}


struct Node
{
	int num;
	Node *node;
};
typedef Node* NodePtr;
void SetNum(NodePtr node, int num)
{
	node->num = num;
}
void SetNextNum(NodePtr node, int num)
{
	node->node = num;
}
int GetNum(NodePtr node)
{
	return node->num;
}
int GetNextNum(NodePtr node)
{
	return node->node;
}

struct Watermelon
{
	int diameter;
	double width;
};
typedef Watermelon* WatermelonPtr;
void SetDiameter(WatermelonPtr watP, int diameter)
{
	watP->diameter = diameter;
}
void SetWidth(WatermelonPtr watP, double width)
{
	watP->width = width;
}
int GetDiameter(WatermelonPtr watP)
{
	return watP->diameter;
}
double GetWidth(WatermelonPtr watP)
{
	return watP->width;
}

struct Fraction
{
	int n;
	int d;
};
typedef Fraction* FractionPtr;
void SetNumerator(FractionPtr frc, int n)
{
	frc->n = n;
}
void SetDenominator(FractionPtr frc, int d)
{
	frc->d = d;
}
int GetNumerator(FractionPtr frc)
{
	return frc->n;
}
int GetDenominator(FractionPtr frc)
{
	return frc->d;
}
FractionPtr CreateFraction(int n, int d)
{
	FractionPtr fraction;
	fraction = (FractionPtr)malloc(1*sizeof(FractionPtr));
	SetNumerator(fraction, n);
	SetDenominator(fraction, d);
	return fraction;
}
FractionPtr CreateFractionByInput()
{
	int n, d;
	printf("Enter numerator: ");
	scanf("%d", &n);
	printf("Enter denominator: ");
	scanf("%d", &d);
	FractionPtr fraction = CreateFraction(n,d);
	return fraction;
}
void PrintFraction(FractionPtr frc)
{
	printf("%d/%d\n", GetNumerator(frc), GetDenominator(frc));
}
