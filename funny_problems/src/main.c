#include <stdio.h>
#include <stdlib.h>

int* readArray(int n);
void read2DArray(int** a, int n, int m);
void printArray(int *arr, int n);
int* maxElements(int** a, int n, int m);
void swap(int* a, int* b);
void bubbleSort(int *arr, int n);
void Problem_1(void);
void Problem_2(void);
void Problem_3(void);
int main()
{
/*Problem_1: Напишете програма, която въвежда масив от цели числа от
клавиатурата. Сортирайте го във възходящ ред. След това от
клавиатурата въведете цяло число и го поставете на правилната му
позиция в масива, така че да не се нарушава реда. Принтирайте
масива*/

	//Problem_1();

/*Problem_2: Напишете програма, която да завърти даден масив от цели числа с N позиции
наляво. Масива и числото N трябва да бъдат въведени от клавиатурата.
Принтирайте оригиналния и резултатния масиви*/

	//Problem_2();

/*Problem_3: Функция, връщаща максималните елементи за всеки ред от двунерен масив*/
	//Problem_3();
	
	return (0);
}
int* readArray(int n)
{
	printf("Enter array with %d elements:\n", n);
	int* arr = malloc(n*sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr+i);
	}
	return arr;
}
void read2DArray(int** a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
}
void printArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", *(arr+i));
	}
}
int* maxElements(int** a, int n, int m)
{
	int* arr = malloc(m*sizeof(int));
	for (int i = 0; i < n; i++)
	{
		int* row = a[i];
		int max = a[i][0];
		for (int j = 0; j < m; j++)
		{
			if(*(row + j)> max)
			{
				max = *(row+j);
			}
			if(j == m-1)
			{
				*(arr+i) = max;
			}
		}
	}
	return arr;
}
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void bubbleSort(int *arr, int n)
{
	int counter = 0;
	while (counter < n-1)
	{
		for (int i = 0; i < n-1; i++)
		{
			if (*(arr+i+1) < *(arr+i))
			{
				swap((arr+i+1), (arr+i));
			}
		}
		counter++;
	}
}
void Problem_1()
{
	printf("Enter size of array: ");
	int n;
	scanf("%d", &n);
	int* myArr = readArray(n);
	bubbleSort(myArr, n);
	printArray(myArr, n);
	printf("Enter num to put in the array: ");
	int num;
	scanf("%d", &num);
	
	int* copyMyArray = malloc((n+1)* sizeof(int));
	
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (num < *(myArr+i))
		{
			*(copyMyArray+k) = num;
			k++;
			while (i != n+1)
			{
				*(copyMyArray+k) = *(myArr+i);
				k++;
				i++;
			}
			break;
		}
		else
		{
			if(i == n-1 && num >= *(myArr+i))
			{
				*(copyMyArray+k) = *(myArr+i);
				k++;
				*(copyMyArray+k) = num;
				break;
			}
			else
			{
				*(copyMyArray+k) = *(myArr+i);
				k++;
			}
		}
	}
	
	printArray(copyMyArray, n+1);
}
void Problem_2()
{
	printf("Enter size of array: ");
	int n;
	scanf("%d", &n);
	int* myArr = readArray(n);
	printArray(myArr, n);
	printf("Enter how many elemens you want to move back: ");
	int num;
	scanf("%d", &num);
	
	int* copyMyArray = malloc(n* sizeof(int));
	int k = 0;
	for (int i = num; i < n; i++)
	{
		*(copyMyArray+k) = *(myArr+i);
		k++;
	}
	for (int i = 0; i < num; i++)
	{
		*(copyMyArray+k) = *(myArr+i);
		k++;
	}
	printArray(copyMyArray, n);
}
void Problem_3()
{
	int N = 3, M = 4;
	int** arr = (int**)malloc(sizeof(int*)*N);
	for (int i = 0; i < M; i++)
	{
		*(arr+i) = (int*)malloc(sizeof(int)*M);
	}
	read2DArray(arr,  N,  M);
	
	int* maxElement = malloc(N*sizeof(int));
	maxElement = maxElements(arr, N, M);
	for (int i = 0; i < N; i++)
	{
		printf("%d\t",*(maxElement+i) );
	}
}