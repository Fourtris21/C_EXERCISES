#include <stdio.h>
#include <math.h>

int count = 0;
/*Да се напише рекурсивна функция
int numPrint(int n),
С помощта на която се отпечатват всички естествени числа до 100*/
void numPrint(int n);
/*Напишете програма на C за броене на цифрите на дадено число с
помощта на рекурсивна функция*/
int CountDigits(int n);
/*Да се напише функция, която намира и връща лицето на
правоъгълник*/
double AreaOfRectangle(double a, double b);
//Да се напише функция, която намира и отпечатва лицето на кръг
double AreaOfCircle(double r);
/*Функция, която по зададени граници на интервал [a,b] , намира и
извежда сумата от четните числа от този интервал*/
int SumOfEvenNums(int a, int b);
/*Да се напише функция с име isTriangle, която по дадени три цели
числа определя дали съществува триъгълник със страни тези числа*/
void IsTriangle(int a, int b, int c);
int main()
{
	//зад.1
	/*int n;
	scanf("%d", &n);
	numPrint(n);*/
	
	//зад.2
	/*int n;
	scanf("%d", &n);
	printf("%d", CountDigits(n));*/
	
	//зад.3
	/*double a, b;
	scanf("%lf", &a);
	scanf("%lf", &b);
	printf("%.2lf", AreaOfRectangle(a, b));*/

	//зад.4
	/*double r;
	scanf("%lf", &r);
	printf("%.2lf", AreaOfCircle(r));*/

	//зад.5
	/*int a, b, c;
	printf("Enter a: ");
	scanf("%d", &a);
	printf("Enter b: ");
	scanf("%d", &b);
	printf("Enter c: ");
	scanf("%d", &c);
	IsTriangle(a, b, c);*/

	//зад.6
	/*int a, b;
	printf("Enter a: ");
	scanf("%d", &a);
	printf("Enter b: ");
	scanf("%d", &b);
	printf("Sum: %d\n",SumOfEvenNums(a, b) );*/

	
	return (0);
}

int SumOfEvenNums(int a, int b)
{
	int sum = 0;
	for (int i = a; i <= b; i++)
	{
		if(i % 2 == 0)
		{
			sum += i;
		}
	}
	return sum;
}

void IsTriangle(int a, int b, int c)
{
	if((a+b) > c && (a+c) > b && (b+c) > a)
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
}

void numPrint(int n)
{
	if(n>0)
	{
		numPrint(n-1);
	}
	else
	{
		return;
	}
	printf("%d\t", n);
}

int CountDigits(int n)
{
	if(n== 0)
	{
		return 0;
	}
	count++;
	CountDigits(n/10);
	return count;
}

double AreaOfRectangle(double a, double b)
{
	return a*b;
}

double AreaOfCircle(double r)
{
	return r*r*M_PI;
}