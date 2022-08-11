#include <stdio.h>
/*Напишете програма, която събира две матрици (4х4) и записва
резултата в трета такава със същия размер. Събирането на матриците става като
намерим сумата на съответстващите елементи в тях. Данните за изходните матрици
трябва да бъдат въведени от потребителя. Разпечатайте трите матрици в конзолата*/
void Zadacha1(void);
/*Напишете програма, която проверява дали дадена матрица е
identity matrix - матрица с размер (N x N), където само елементите в главния
диагонал са единици, а всички останали елементи са нули*/
void Zadacha2(void);
/*Напишете програма, която печата броя на уникалните редове в бинарна
матрица, съставена само от единици и нули*/
void Zadacha3(void);

int main()
{
	
	//Zadacha1();
	//Zadacha2();
	//Zadacha3();
	

	return (0);
}
void Zadacha1()
{
	int row = 4;
	int col = 4;
	int a[4][4];
	int b[4][4];
	int c[4][4];

	printf("Enter the first 4x4 matrix:\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("a[%d][%d] = ", i,j);
			scanf("%d", &a[i][j]);
		}
	}
	printf("Enter the second 4x4 matrix:\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("b[%d][%d] = ", i,j);
			scanf("%d", &b[i][j]);
		}
	}
	printf("The sum of first and second matrix: \n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}
}
void Zadacha2()
{
	int n;
	int counter = 0;
	int counter2 = 0;
	int stepen = 1;

	printf("Enter N in NxN matrix: ");
	scanf("%d", &n);

	int temp = n;
	int a[n][n];

	printf("Enter the matrix:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("a[%d][%d] = ", i,j);
			scanf("%d", &a[i][j]);

			if(i == j && a[i][j] == 1)
			{
				counter++;
			}
			else if(i != j && a[i][j] == 0)
			{
				counter2++;
			}
		}
	}

	for (int i = n-1; i >= 0; i--)
	{
		for (int j = n-1; j >= 0; j--)
		{
			if(i == j && a[i][j] == 1)
			{
				counter++;
			}
		}
	}

	while(temp-1 > 0)
	{
		stepen *= 2;
		temp--;
	}
	if(counter == 2*n && counter2 == stepen)
	{
		printf("identity matrix\n");
	}
	else
	{
		printf("Pech:(\n");
	}
}
void Zadacha3()
{
	int matrix[5][5]= 
	{
		{0,1,0,1,0},
		{1,1,1,1,1},
		{0,0,0,0,0},
		{0,1,0,1,0},
		{0,1,0,0,1}
	};
	int counter = 0;
	int uniqueCounter = 0;
	int uniqueRow = 0;
	for (int i = 0; i < 5; i++)
	{
		int* arr = matrix[i];
		for (int j = 0; j < 5; j++)
		{
			int* arr2 = matrix[j];
			for (int k = 0; k < 5; k++)
			{
				if(i == j)
				{
					break;
				}
				else
				{
					if(*(arr+k) == *(arr2+k))
					{
						  counter++;
					}
				}
				if(k == 4 && counter != 5)
				{
					uniqueCounter++;
				}
			}
			counter = 0;
			
		}
		if(uniqueCounter == 4)
		{
			uniqueRow++;
		}
		uniqueCounter = 0;
	}
	
	printf("%d\n", uniqueRow);
}