#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int x, int y);
int* readArray(int n);
void printArray(int *arr, int n);
void swap(int* a, int* b);
void bubbleSort(int *arr, int n);
void SelectionSort(int* arr, int n);
void QuickSort(int* arr, int x, int y);
void InsertionSort(int* arr, int n);
int BinarySearch(int *array, int x, int low, int high);
int FnPlus(int a, int b);
int FnMinus(int a, int b);
int FnMulty(int a, int b);
int FnDivision(int a, int b);
int (* FnCalculator)(int, int) = NULL;
void Zadacha_2(void);

int main()
{
	//за довършване: зад 3 и 4

	//Selection Sort
	/*printf("Enter size of array: ");
	int n;
	scanf("%d", &n);
	int* arr;
	arr = readArray(n);
	SelectionSort(arr, n);*/
	
	//Insertion Sort
	/*printf("Enter size of array: ");
	int n;
	scanf("%d", &n);
	int* arr;
	arr = readArray(n);
	InsertionSort(arr, n);*/
	
	//Quick Sort
	/*printf("Enter size of array: ");
	int n;
	scanf("%d", &n);
	int* arr;
	arr = readArray(n);
	QuickSort(arr, 0, n-1);
	printArray(arr, n);*/

	//Binary Search
	/*printf("Enter size of array: ");
	int n;
	scanf("%d", &n);
	int* arr;
	arr = readArray(n);
	int x = 4;
	int result = BinarySearch(arr, x, 0, n - 1);
	if (result == -1)
	{
		printf("Not found");
	}
	else
	{
		printf("Element is found at index %d", result);
	}*/

	//зад.2
	//Zadacha_2();
	

	return (0);
}
void SelectionSort(int* arr, int n)
{
	int min;
	for (int i = 0; i < n-1; i++)
	{
		min = i;
		for (int l = i+1; l < n; l++)
		{
			if(*(arr+min)> *(arr+l))
			{
				min = l;
			}
		}
		int temp = *(arr+min);
		*(arr+min) = *(arr+i);
		*(arr+i) = temp;
	}
	printArray(arr, n);
}
void InsertionSort(int* arr, int n)
{
	int key, j;
	for (int i = 1; i < n; i++)
	{
		key = arr[i];
		j = i-1;
		while (j >= 0 && arr[j]> key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
	printArray(arr, n);
}
void QuickSort(int* arr , int x, int y) 
{
	if (x < y) 
	{
		int pi = partition(arr, x, y);
		QuickSort(arr, x, pi - 1);
		QuickSort(arr, pi + 1, y);
	}
	
}
int BinarySearch(int *array, int x, int low, int high) 
{
	while (low <= high) 
	{
		int mid = low + (high - low) / 2;
		if (array[mid] == x)
		{
			return mid;
		}
		if (array[mid] < x)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}
int FnPlus(int a, int b)
{
	return a+b;
}
int FnMinus(int a, int b)
{
	return a-b;
}
int FnMulty(int a, int b)
{
	return a*b;
}
int FnDivision(int a, int b)
{
	return a/b;
}
void Zadacha_2()
{
	int a = 4;
	int b = 5;
	printf("Enter +, -, *, / : ");
	char ch;
	scanf("%c", &ch);

	switch (ch)
	{
		case '+':
		FnCalculator = FnPlus(a, b);
		printf("%d", (*FnCalculator));
		break;
		case '-':
		FnCalculator = FnMinus(a, b);
		printf("%d", (*FnCalculator));
		break;
		case '*':
		FnCalculator = FnMulty(a, b);
		printf("%d", (*FnCalculator));
		break;
		case '/':
		FnCalculator = FnDivision(a, b);
		printf("%d", (*FnCalculator));
		break;
	default:
		break;
	}
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
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void printArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", *(arr+i));
	}
	
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
int partition(int arr[], int x, int y)
 {
	int pivot = arr[y];
	int i = (x - 1);
	for (int j = x; j < y; j++) 
	{
		if (arr[j] <= pivot) 
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[y]);
	return (i + 1);
}