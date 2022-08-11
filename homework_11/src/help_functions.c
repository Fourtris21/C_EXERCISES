#include "help_functions.h"
#include "structures.h"
#include "homework_11.h"
#include <stdio.h>
#include <stdlib.h>
int counter =1;
int* id = &counter;

void EnterEra(Era* era)
{
	int century;
    int year;
    int month;
    int day;
    int minutes;
    int seconds;
	printf("Century: ");
	scanf("%d", &century);
	SetEraCentury(era, century);
	printf("Year: ");
	scanf("%d", &year);
    SetEraYear(era, year);
	printf("Month: ");
	scanf("%d", &month);
    SetEraMonth(era, month);
	printf("Day: ");
	scanf("%d", &day);
    SetEraDay(era, day);
	printf("Minutes: ");
	scanf("%d", &minutes);
    SetEraMinutes(era, minutes);
	printf("Seconds: ");
	scanf("%d", &seconds);
    SetEraSeconds(era, seconds);
}
void PrintEra(Era* era)
{
	printf("Century: %d\n", GetEraCentury(era));
	printf("Year: %d\n", GetEraYera(era));
	printf("Month: %d\n", GetEraMonth(era));
	printf("Day: %d\n", GetEraDay(era));
	printf("Minutes: %d\n", GetEraMinutes(era));
	printf("Seconds: %d\n", GetEraSeconds(era));
}
void Razlika_Mejdu_Epohite(Era* era1, Era* era2)
{
	int seconds = abs(GetEraSeconds(era1)-GetEraSeconds(era2))%60;
	int minutes = (abs(GetEraSeconds(era1)-GetEraSeconds(era2))/60 + abs(GetEraMinutes(era1)-GetEraMinutes(era2))%60)%60;
	int	days = ((abs(GetEraSeconds(era1)-GetEraSeconds(era2))/60 + abs(GetEraMinutes(era1)-GetEraMinutes(era2))%60)/1440 + abs(GetEraDay(era1)-GetEraDay(era2))%30)%30;
	int months = (((abs(GetEraSeconds(era1)-GetEraSeconds(era2))/60 + abs(GetEraMinutes(era1)-GetEraMinutes(era2))%60)/1440 + abs(GetEraDay(era1)-GetEraDay(era2))%30)/30 + abs(GetEraMonth(era1)-GetEraMonth(era2))%12)%12;
	int years = ((((abs(GetEraSeconds(era1)-GetEraSeconds(era2))/60 + abs(GetEraMinutes(era1)-GetEraMinutes(era2))%60)/1440 + abs(GetEraDay(era1)-GetEraDay(era2))%30)/30 + abs(GetEraMonth(era1)-GetEraMonth(era2))%12)/12 + abs(GetEraYera(era1)-GetEraYera(era2))%100)%100;
	int centuries = ((((abs(GetEraSeconds(era1)-GetEraSeconds(era2))/60 + abs(GetEraMinutes(era1)-GetEraMinutes(era2))%60)/1440 + abs(GetEraDay(era1)-GetEraDay(era2))%30)/30 + abs(GetEraMonth(era1)-GetEraMonth(era2))%12)/12 + abs(GetEraYera(era1)-GetEraYera(era2))%100)/100 + abs(GetEraCentury(era1)-GetEraCentury(era2));
	printf("\n");
	printf("Razlikata na dvete epohi e: Centuries: %d\tYears: %d\tMonths: %d\tDays: %d\tMinutes: %d\tSeconds: %d\n", centuries,years,months ,days ,minutes ,seconds );
}
void MakePoint(Rect* rect)
{
	SetFirstPoint(rect, 0,0);
	SetSecondPoint(rect, 5,5);

	for (int i = 0; i < GetPointY(GetSecondPoint(rect)); i++)
	{
		for (int i = 0; i < GetPointX(GetSecondPoint(rect)); i++)
		{
			printf("-  ");
		}
		printf("\n");
	}
}
void Enter_Employee(Employee* emp)
{
	char f_name[10];
	char m_name[10];
	char l_name[10];
	char position[20];
	int internship = 0;
	double salary = 0.;

	printf("Employee %d\n", *id);
	SetId(emp, id);
	*id += 1;
	printf("First name: ");
	scanf("%s", f_name);
	SetFirstName(emp, f_name);
	printf("Middle name: ");
	scanf("%s", m_name);
	SetMiddleName(emp, m_name);
	printf("Last name: ");
	scanf("%s", l_name);
	SetLastName(emp, l_name);
	printf("Position: ");
	scanf("%s", position);
	SetPosition(emp, position);
	printf("Internship(in years): ");
	scanf("%d", &internship);
	SetInternship(emp, internship);
	printf("Salary: ");
	scanf("%lf", &salary);
	SetSalary(emp, salary);
}
void Info_Employee(Employee* emp)
{
	printf("Employee %d:\t", GetId(emp));
	printf("First name: %s\t",GetFirstName(emp));
	printf("Middle name: %s\t", GetMiddleName(emp));
	printf("Last name: %s\t", GetLastName(emp));
	printf("Position: %s\t", GetPosition(emp));
	printf("Internship(in years): %d\t", GetInternship(emp));
	printf("Salary: %.2lf\t", GetSalary(emp));
	printf("Boss: %s\n", GetBossName(emp));
}

int Sum(int a, int b)
{
	return a+b;
}
int Difference(int a, int b)
{
	return a-b;
}
int Multi(int a, int b)
{
	return a*b;
}
int Division(int a, int b)
{
	return a/b;
}

Ptr Calculate(char code)
{
	if(code == '+')
	{
		return &Sum;
	}
	else if(code == '-')
	{
		return &Difference;
	}
	else if(code == '*')
	{
		return &Multi;
	}
	else if(code == '/')
	{
		return &Division;
	}
}
typedef Fraction* FractionPtr;
FractionPtr Add(FractionPtr frc, FractionPtr frc2)
{
	FractionPtr newFraction;
	newFraction = (FractionPtr)malloc(1*sizeof(FractionPtr));
	int n = (GetDenominator(frc)*GetNumerator(frc2))+(GetDenominator(frc2)*GetNumerator(frc));
	int d = GetDenominator(frc)*GetDenominator(frc2);
	SetNumerator(newFraction, n);
	SetDenominator(newFraction, d);
	return newFraction;
}
FractionPtr Mult(FractionPtr frc, FractionPtr frc2)
{
	FractionPtr newFraction;
	newFraction = (FractionPtr)malloc(1*sizeof(FractionPtr));
	int n = GetNumerator(frc)*GetNumerator(frc2);
	int d = GetDenominator(frc)*GetDenominator(frc2);
	SetNumerator(newFraction, n);
	SetDenominator(newFraction, d);
	return newFraction;
}
FractionPtr Divide(FractionPtr frc, FractionPtr frc2)
{
	FractionPtr newFraction ;
	newFraction = (FractionPtr)malloc(1*sizeof(FractionPtr));
	int n = GetNumerator(frc)* GetDenominator(frc2);
	int d = GetNumerator(frc2)*GetDenominator(frc);
	SetNumerator(newFraction, n);
	SetDenominator(newFraction, d);
	return newFraction;
}
FractionPtr Subtract(FractionPtr frc, FractionPtr frc2)
{
	FractionPtr newFraction;
	newFraction = (FractionPtr)malloc(1*sizeof(FractionPtr));
	int n = (GetDenominator(frc)*GetNumerator(frc2))-(GetDenominator(frc2)*GetNumerator(frc));
	int d = GetDenominator(frc)*GetDenominator(frc2);
	SetNumerator(newFraction, n);
	SetDenominator(newFraction, d);
	return newFraction;
}

