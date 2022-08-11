#include <stdio.h>
#define SIZE 6
/*Прочетете масив от цели числа от клавиатурата.
Копирайте въведения масив във втори масив, като умножите стойността на
всеки елемент по 2. Принтирайте двата масива*/
void Zadacha1(void);
/*Напишете програма, която запълва масив от 20 елемента с произволно избрани
цели числа. За целта използвайте функцията rand().
Въведете едно цяло число от клавиатурата. Проверете дали въведеното число
от клавиатурата е намерено в масива. Принтирайте масива и отговора дали
числото е намерено в масива*/
void Zadacha2(void);
/*Напишете програма, която принтира уникалните елементи от масив с цели числа,
въведени от клавиатурата. За целта, някои от числата трябва да се повтарят*/
void Zadacha3(void);
/*Напишете програма, която да брои колко пъти се среща едно число в даден масив
от цели числа. Масивът трябва да бъде въведен от клавиатурата. Принтирайте
резултатите*/
void Zadacha4(void);
/*Дефинирайте едномерен масив int с 10 елемента =
{100,90,80,70,60,50,40,30,20,10}.
Дефинирайте пойнтер, който ще сочи към масива.
Достъпете 3 тия елемент от масива и му задайте стойност 5.
Достъпете 4 тия елемент и му задайте стойност 33.
Достъпете 5 тия елемент и го намалете със 7.
Достъпете 7 мия елемент и го увеличете с 10.
Достъпете 10 тия елемент и го умножете по 3.
Изпишете го по двата възможни начина и закоментирайте единия.
Принтирайте на екрана всички елементи на масива*/
void Zadacha5(void);

int main()
{
	//Zadacha1();
	//Zadacha2();
	//Zadacha3();
	//Zadacha4();
	//Zadacha5(); 
	
	return 0;
}

void Zadacha2()
{
	int arr[20];
	int num;
	for (int i = 0; i < 20; i++)
	{
		*(arr+i) = (rand()%100);
	}
	printf("Enter num to search: ");
	scanf("%d", &num);
	int i;
	for ( i = 0; i < 20; i++)
	{
		if(num == *(arr+i))
		{
			printf("YES\n");
			break;
		}
		if(i == 19)
		{
			printf("NO\n");
		}
			
	}
	for (int i = 0; i < 20; i++)
	{
		printf("%d, ", *(arr+i));
	}
}
void Zadacha3()
{
	int arr[] = {100,90,90,80,70,70,60,50,40,30,30,20,10};
	int arr2[14];
	int size = sizeof(arr) / sizeof(arr[0]);
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if(i == j && arr[i] != arr[size-1])
			{
				continue;
			}
			else
			{
				if(*(arr+i) == *(arr+j) && arr[i] != arr[size-1])
				{
					break;
				}
			}
				
			if(j == size - 1)
			{
				*(arr2+index) = *(arr+i);
				index++;
			}
		}
	}
	for (int i = 0; i < index; i++)
	{
		printf("%d, ",*(arr2 + i));
	}
}
void Zadacha4()
{
	int n;
	printf("Enter size of array: ");
	scanf("%d", &n);
		
	int num;
	printf("Enter num to search: ");
	scanf("%d", &num);

	int arr[n];
	printf("Enter array with %d elements: ", n);
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &*(arr+i));
		if(*(arr+i) == num)
		{
			counter++;
		}	
	}
	printf("%d was %d times in the array", num, counter);
}
void Zadacha5()
{
	int arr[] = {100,90,80,70,60,50,40,30,20,10};
	int size = sizeof(arr) / sizeof(arr[0]);
	int *ptr = arr;

	*(ptr + 2) = 5;
	//ptr[2] = 5;
	*(ptr + 3) = 33;
	//ptr[3] = 33;
	*(ptr + 4) -= 7;
	//ptr[4] -= 7;
	*(ptr + 6) += 10;
	//ptr[6] += 10;
	*(ptr + 9) *= 3;
	//ptr[9] *= 3;
	
	for (int i = 0; i < size; i++)
	{
		printf("%d, ", *(ptr + i));
	}
}
void Zadacha1()
{
	int arr[SIZE];
	
	printf("Enter %d elements in the array: ", SIZE);
	int i;
	for (i = 0; i < SIZE; i++)
	{
		scanf("%d", &*(arr + i) );
	}
	
	printf("The first array is: ");
	for ( i = 0; i < SIZE; i++)
	{
		printf("%d, ", *(arr + i) );
	}
	printf("\nThe second array is: ");
	for ( i = 0; i < SIZE; i++)
	{
		*(arr + i) *= 2;
		printf("%d, ", *(arr + i) );
	}
}