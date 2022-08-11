#include <stdio.h>
#include<math.h>
/*Клиент вложил А лв с месечна лихва В%. Как ще се променя тази вноска, ако клиентът не
тегли
пари през този период:
a/за 5 години;
б/за N години;
в/докато вноската стане по-голяма от С лв.
Да се напише програма. Числата са на вход*/
void Depozit(void);
/*Започвайки тренировка спортист пробягал първия ден А км. Всеки следващ ден той
увеличавал дневната си норма с В% спрямо предишния ден. Какъв сумарен път ще пробяга
спортистът за :
а/10 дни;
б/N дни;
в/докато пробягания за ден път стане по-голям от Х км и на кой ден;
г/докато общо пробягания път стане по-голям от У км и за колко дни.
Да се напише програма. Числата са на вход*/
void Running(void);
/*Да се изведат първите N числа на една редица (геометрична прогресия), ако са дадени първият
член на редицата и частното между първите два елемента. Да се напише програма.
Числата са на вход*/
void GeometricProgression(void);
/*Да се изведат първите N числа на една редица (аритметична прогресия), ако са дадени
първият член на редицата и разликата между първите два елемента. Да се напише програма.
Числата са на вход*/
void ArithmeticProgression(void);
/*Дадени са a, b, N (b !=0, 1<=N<=100). Да се намери частното a/b и да се отпечата на екрана с
N цифри след десетичната запетая*/
void Rounding(void);
/*Да се намери сумата от тези елементи на редица, които са удвоени нечетни числа, ако:
а/редицата е с 41 елемента;
б/първо се въвежда броят на елементите на редицата;
в/редицата е последен елемент 0;
г/редицата е с елементи, чиято сума е по-голяма от 999*/
void Zadacha5(void);
/*По дадено N да се изчисли А(0)+А(1)+А(2)+...+А(N), ако А(0)=1,A(К+1)=2.A(К)+1 за К>=1*/
void Zadacha8(void);
/*По зададено естествено число N, да се намерят всички двойки естествени числа М и К, за
които
М2+К2=N*/
void Zadacha3(void);


int main()
{
	//зад.1
	// Depozit();
	
	//зад.2
	//Running();

	//зад.3
	//Zadacha3();

	//зад.4
	//Rounding();

	//зад.5
	//Zadacha5();

	//зад.6
	//ArithmeticProgression();

	//зад.7
	//GeometricProgression();
	
	//зад.8
	//Zadacha8();
	

	return (0);
}

void Depozit()
{
	double money = 0.;
	double lihva = 0.;
	int years = 0;
	double sum = 0.;
	printf("Vnoska: ");
	scanf("%lf", &money);

	printf("Lihva na mesec: ");
	scanf("%lf", &lihva);

	printf("Years: ");
	scanf("%d", &years);

	sum += ((lihva / 100) * money) * (years * 12);

	printf("Krajna suma za %d godini e %.2lf lv\n", years, sum);
}

void Running()
{
	double km1day = 0.;
	double progres = 0.;
	int days = 0;
	double granica = 0;

	printf("Kms for the first day: ");
	scanf("%lf", &km1day);
	double sumKm = km1day;
	printf("Progres: ");
	scanf("%lf", &progres);


	//докато пробягания за ден път стане по-голям от Х км и на кой ден
	/*printf("Granica(v km): ");
	scanf("%lf", &granica);
	while (granica >= 0)
	{
		sumKm = sumKm + ((progres/100)*sumKm);
		days++;
		granica -= sumKm;
	}
	printf("Day: %d\n", days+1);*/
	

	//какъв сумарен път ще пробяга спортистът за N дена
	/*printf("Days: ");
	scanf("%d", &days);
	double sum = 0.;
	while (days > 0)
	{
		sum += sumKm;
		sumKm = sumKm + ((progres/100)*sumKm);
		days--;
	}
	printf("Obsto kms: %lf", sum);*/

	//докато общо пробягания път стане по-голям от У км и за колко дни
	/*printf("Granica(v km): ");
	scanf("%lf", &granica);
	double sum = 0.;
	while (granica > 0)
	{
		sum += sumKm;
		sumKm = sumKm + ((progres/100)*sumKm);
		days++;
		granica -= sum;
	}
	printf("Days: %d\n", days);*/
}

void GeometricProgression()
{
	int n = 0;
	int firstElement = 0;
	int q = 1;
	int result= 0;

	printf("Enter n: ");
	scanf("%d", &n);
	printf("Enter first element: ");
	scanf("%d", &firstElement);
	printf("Enter chastno: ");
	scanf("%d", &q);

	for (int i = 1; i <= n; i++)
	{
		result = firstElement * pow(q, i-1);
		printf("%d\t", result);
	}

} 

void ArithmeticProgression()
{
	int n = 0;
	int firstElement = 0;
	int d = 0;
	int result= 0;

	printf("Enter n: ");
	scanf("%d", &n);
	printf("Enter first element: ");
	scanf("%d", &firstElement);
	printf("Enter razlika: ");
	scanf("%d", &d);

	for (int i = 1; i <= n; i++)
	{
		result = firstElement + ((i-1)*d);
		printf("%d\t", result);
	}
}

void Rounding()
{
	double a;
	double b;
	int n = 2;
	long double result = 0.;
	printf("Enter a: ");
	scanf("%lf", &a);
	do
	{
		printf("Enter b: ");
		scanf("%lf", &b);
	} while (b == 0);

	do
	{
		printf("Enter N: ");
		scanf("%d", &n);
	} while (n < 1 || n > 100);
	long double num = a/b;
	result = floor(pow(10, n)*num)/pow(10, n);
	printf("%.100Lf", result);
}

void Zadacha5()
{
	int n;
	printf("Enter n: ");
	scanf("%d", &n);
	int num;
	int sum = 0;
	//Да се намери сумата от тези елементи на редица, които са удвоени нечетни числа,
	//ако първо се въвежда броят на елементите на редицата

	/*while (n > 0)
	{
		scanf("%d", &num);
		if (num % 2 == 0)
		{
			if((num/2) % 2 == 1)
			{
				sum += num/2;
			}
		}
		n--;
	}
	printf("Sum: %d", sum);*/

	//Да се намери сумата от тези елементи на редица, които са удвоени нечетни числа, ако
	//редицата е с елементи, чиято сума е по-голяма от 999
	/*int bigSum = 0;
	while (n > 0)
	{
		n--;
		if (num % 2 == 0)
		{
			if((num/2) % 2 == 1)
			{
				sum += num/2;
			}
		}
		scanf("%d", &num);
		bigSum += num;
		if (n == 0)
		{
			if (bigSum < 999)
			{
				printf("Sorry, the sum is less than 999");
			}
			else
			{
				printf("Sum: %d", sum);
			}
		}
	}*/
}

void Zadacha8()
{
	int num;
	int sum = 1;
	printf("Enter num: ");
	scanf("%d", &num);
	int result = 1;
	for (int i = 0; i < num-1; i++)
	{
		result = (result*2)+1;
		sum += result;
	}
	printf("Sum: %d", sum);
}

void Zadacha3()
{
	int num;
	int m = 1;
	
	printf("Enter num: ");
	scanf("%d", &num);
	
	for (int i = 0; i < num/2; i++)
	{
		int k = (num/2)-m;
		if(((2*m)+ (2*k)) == num)
		{
			printf("m = %d k = %d\n", m, k);
		}
		m++;
	}
}