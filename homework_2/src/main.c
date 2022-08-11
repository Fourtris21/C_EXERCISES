#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void PrintPattern3(void);
void PrintPattern2(void);
void PrintPattern1(void);
/*Напишете програма, която изчислява броя на секундите в една
година*/
void SecondsInYear(void);
/*Да се напише програма, която чете едно цяло шестцифрено число и
намира лицето на правоъгълника със страна a, равна на сумата от не-
четните цифри и страна b, равна на сумата от четните цифри*/
void Area(void);
/*Направете бягаща светлина, като приемете, че всеки бит от
дадена променлива, е свързан с лампа (или светодиод). Когато битът е
нула, лампата не свети, когато е единица свети.
Примерно, ако генерирате последователност:
1, 2, 3, 4, се получава следното:
1 *....................
2 .*...................
4 ..*..................
8 ...*................. ...
За да генерирате закъснение, използвайте следната функция от C runtime:
#include <unistd.h>
unsigned int sleep(unsigned int seconds);*/
void GasiLampite(void);
int intToBin(int k);
/*Да се напише програма, която чете едно цяло шестцифрено число,
отделя от него цифрите на позиции 1,3,5 и 6 и с тези цифри образува ново
число от четири цифри. Ако разглеждаме това ново число като
година,програмата трябва да изведе дали тази година е високосна или не*/
void LeapYear(void);

int main()
{
	//зад.1
	//LeapYear();

	//зад.2
	//Area();

	//зад.5
	//GasiLampite();

	//зад.6
	//SecondsInYear();

	//зад.7
	//PrintPattern1();
	//PrintPattern2();
	//PrintPattern3();
	
	return (0);
}

void PrintPattern3()
{
	int num;
	char ch = '#';
	char sp = ' ';
	printf("Enter number: ");
	scanf("%d", &num);
	for (int i = num; i > 0 ; i-=2)
	{
		for (int k = 0; k < i/2; k++)
		{
			printf("%c", sp);
		}
		
		for (int l = num; l >= i ; l--)
		{
			printf("%c", ch);
		}
		printf("\n");
	}
	for (int i = num-2; i > 0 ; i-=2)
	{
		for (int k = num; k > i; k-= 2)
		{
			printf("%c", sp);
		}
		for (int l = i; l > 0 ; l--)
		{
			printf("%c", ch);
		}
		printf("\n");
	}
}

void PrintPattern2()
{
	int num;
	char ch = '#';
	char sp = ' ';
	printf("Enter number: ");
	scanf("%d", &num);
	for (int i = num; i > 0 ; i-=2)
	{
		for (int k = 0; k < i/2; k++)
		{
			printf("%c", sp);
		}

		for (int l = num; l >= i ; l--)
		{
			printf("%c", ch);
		}
		printf("\n");
	}
}

void PrintPattern1()
{
	int num;
	char ch = '#';
	char sp = ' ';
	printf("Enter number: ");
	scanf("%d", &num);
	for (int i = num; i > 0 ; i-=2)
	{
		for (int k = num; k > i; k-= 2)
		{
			printf("%c", sp);
		}

		for (int l = i; l > 0 ; l--)
		{
			printf("%c", ch);
		}
		printf("\n");
	}
}

void SecondsInYear()
{
	unsigned int seconds = 365 * 24 * 60 * 60;
	printf("Seconds in 1 year: %d", seconds);
}

void Area()
{
	int num;
	int oddSum = 0;
	int evenSum = 0;
	printf("Enter number with 6 digits: ");
	scanf("%d", &num);
	for (int i = 0; i < 6; i++)
	{
		int tempNum = num % 10;

		if((tempNum)%2 == 0)
		{
			evenSum += tempNum;
		}
		else
		{
			oddSum += tempNum;
		}
		num /= 10;
	}

	printf("Area: %d\n", evenSum* oddSum);
}

void GasiLampite()
{
	char symbols[100];
	printf("Enter something: ");
	scanf("%s", &symbols);
	int lenght = strlen(symbols);
	for (int i = 0; i < lenght; i++)
	{
		int k = (int)(symbols[i]);
		k = intToBin(k);
		char str[100];
		sprintf(str, "%u", k);
		
		for (int l = 0; l < strlen(str); l++)
		{ 
			if(str[l] == '0')
			{
				printf(".");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
		sleep(1);
	}
}

int intToBin(int k)
{
    if (k == 0) return 0;
    if (k == 1) return 1;
    return (k % 2) + 10 * intToBin(k / 2);
}

void LeapYear()
{
	char num[7];
	char year[5];
	int yearInt;
	int index = 0;
	printf("Enter number with 6 digits: ");
	scanf("%s", &num);
	for (int i = 0; i < 6; i+=2)
	{
		if(i >= 4)
		{
			year[3] = num[5];
		}
		year[index++] = num[i];
	}
	puts(year);

	yearInt = atoi(year);
	if ((yearInt % 4 == 0 && yearInt % 100 != 0) || yearInt % 400 == 0)
	{
		printf("The year is leap\n");
	}
	else
	{
		printf("The year is not leap\n");	
	}
	
}