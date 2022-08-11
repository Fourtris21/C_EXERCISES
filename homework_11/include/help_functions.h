#ifndef HELP_FUNCTIONS_H
#define HELP_FUNCTIONS_H

#include "structures.h"

void EnterEra(Era*);
void PrintEra(Era*);
void Razlika_Mejdu_Epohite(Era*, Era*);
void MakePoint(Rect*);
void Enter_Employee(Employee*);
void Info_Employee(Employee*);
//void Set_Boss(Employee*, Employee**);
int Sum(int, int);
int Difference(int, int);
int Multi(int, int);
int Division(int, int);
typedef int(*Ptr)(int, int);
int (*Calculate(char))(int, int);
Fraction* Add(Fraction*, Fraction*); 
Fraction* Mult(Fraction*, Fraction*);
Fraction* Divide(Fraction*, Fraction*);
Fraction* Subtract(Fraction*, Fraction*);

#endif