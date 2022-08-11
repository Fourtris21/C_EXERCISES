#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void GetSpiralMatrix(int size)
{
	int  i, j;
	int matrix[size][size];
	int count = size * size;
	char direction = 'd';
	int down = size-1;
	int right = size-1;
	int left = 1;
	int up = 0;
	int row = 0;
	int col = 0;

	matrix[0][0]= 1;
	for ( i = 2; i <= count; i++)
	{
		if(direction == 'd')
		{
			row++;
			matrix[row][col] = i;
			if(row == down)
			{
				direction = 'r';
				down--;
			}
		}
		else if(direction == 'r')
		{
			col++;
			matrix[row][col] = i;
			if(col == right)
			{
				direction = 'u';
				right--;
			}
		}
		else if(direction == 'u')
		{
			row--;
			matrix[row][col] = i;
			if(row == up)
			{
				direction = 'l';
				up++;
			}
		}
		else if(direction == 'l')
		{
			col--;
			matrix[row][col] = i;
			if(col == left)
			{
				direction = 'd';
				left ++;
			}
		}
	}
	for ( i = 0; i < size; i++)
	{
		for ( j = 0; j < size; j++)
		{
			printf("%d  ", matrix[i][j]);
		}
		printf("\n");
	}
}
void GetStrangeMatrix(int size)
{
	int i, j;
	int row = 0;
	int col = 0;
	int counter = 0;
	int counter2 = 1;
	int bottom = size-1;
	int up = 0;
	int matrix[size][size];
	int n = (size*size)-size;

	for ( i = 1; i <= n/2; i++)
	{
		if(row == col)
		{
			matrix[row][col] = 0;
			if(row == size && col == size)
			{
				break;
			}
		}
		row++;
		matrix[row][col] = i;
		if(row == bottom)
		{
			counter ++;
			col++;
			row = size - (size -counter);
		}
	}
	for ( i = (n/2)+1; i <= n; i++)
	{
		row--;
		matrix[row][col] = i;
		
		if(row == up)
		{
			col--;
			counter2 ++;
			row = size-counter2;
		}
	}
	for ( i = 0; i < size; i++)
	{
		for ( j = 0; j < size; j++)
		{
			printf("%d  ", matrix[i][j]);
				
		}
		printf("\n");
	}
}
int IsPrime(int num)
{
	int counter = 0;
	for (int i = 2; i <= num/2; i++)
	{
		if(num % i == 0)
		{
			counter++;
		}
	}
	if(counter == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int NOD(int num, int num2)
{
	while(num != num2)
	{
		if(num > num2)
		{
			num = num-num2;
		}
		else
		{
			num2 = num2-num;
		}
	}
	return num;
}
int NodInArray(int* arr, int len)
{
	int nod = arr[0];
	for (int i = 0; i < len-1; i++)
	{
		if(NOD(arr[i], arr[i+1]) < nod)
		{
			nod = NOD(arr[i], arr[i+1]);
		}
	}
	return nod;	
}
void Proportion(int* arr, int len)
{
	int null = 0;
	int negative = 0;
	int positive = 0;
	for (int i = 0; i < len; i++)
	{
		if(arr[i] > 0)
		{
			positive++;
		}
		else if(arr[i] < 0)
		{
			negative++;
		}
		else
		{
			null++;
		}
	}
	float posPer = (positive*100)/len;
	float negPer = (negative*100)/len;
	float nullPer = (null*100)/len;
	printf("%f\n", posPer);
	printf("%f\n", negPer);
	printf("%f\n", nullPer);
}
int* InsertionSort(int* arr, int n)
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
	return arr;
}
int MinSum(int* arr, int len)
{
	arr = InsertionSort(arr, len);
	int sum = 0;
	for (int i = 0; i < len-1; i++)
	{
		sum += arr[i];
	}
	return sum;
}
int MaxSum(int* arr, int len)
{
	arr = InsertionSort(arr, len);
	int sum = 0;
	for (int i = 1; i < len; i++)
	{
		sum += arr[i];
	}
	return sum;
}
int* RedoubleAtEvenPosition(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if(i % 2 == 1)
		{
			arr[i]*=2;
		}
	}
	return arr;
}
int* ReverseArray(int* arr, int len)
{
	for (int i = 0; i < len/2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[len-1-i];
		arr[len-1-i] = temp;
	}
	return arr;
}
void PrintArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d", arr[i]);
	}
}

void CheckCard(int* arr, int size)
{
	char type[12];
	if(*(arr+0) == 4)
	{
		strcpy(type, "VISA");
	}
	else
	{
		strcpy(type, "Master card");
	}
	if(size != 16)
	{
		printf("Invalid card number\n");
		return;
	}
	ReverseArray(arr, size);
	RedoubleAtEvenPosition(arr, size);
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if(arr[i] > 9)
		{
			while (arr[i] != 0)
			{
				int digit = arr[i]%10;
				sum += digit;
				arr[i]/=10;
			}
		}
		else
		{
			sum += arr[i];
		}
	}
	if(sum % 10 == 0)
	{
		printf("Valid card");
		printf("%s", type);
	}
	else
	{
		printf("Invalid card");
	}
}
void Check(int* arr, int size)
{
	bool flag = true;
	for (int i = 1; i < size-1; i++)
	{
		if((arr[i]>arr[i-1] && arr[i]>arr[i+1]) || (arr[i]< arr[i-1] && arr[i]< arr[i+1]))
		{
			continue;
		}
		else
		{
			flag = false;
			break;
		}
	}
	if (flag == true)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
}
char* Time_24(char* time)
{
	int num;
	char newStr[3];
	char newStr2[3];
	if(time[8] == 'P' && time[9] == 'M')
	{
		newStr[0] = time[0];
		newStr[1] = time[1];
		num = atoi(newStr);
		num += 12;
		sprintf(newStr2, "%d", num);
	}
	return newStr2;
}

