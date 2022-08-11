#include <stdio.h>
/*Напишете C програма за броене на честотата на цифрите в дадено число.
Input any number: 116540
Frequency of 0 = 1
Frequency of 1 = 2
Frequency of 2 = 0
Frequency of 3 = 0
Frequency of 4 = 1
Frequency of 5 = 1
Frequency of 6 = 1
Frequency of 7 = 0
Frequency of 8 = 0
Frequency of 9 = 0*/
void Zadacha1(void);
/*Да се състави програма на C, която при въвеждане на естествено число от интервала
[10 - 30000] извежда цифрите му в морзовата азбука.
Цифрите на числото се извеждат отдясно-наляво
Входни данни: х - естествено число.
Цифрите в морзовата абука се изписват както следва:
0: "----- ";
1: ".... "
2: "...- "
3: "..-- "
4: "..--- "
5: ".---- "
6: "-... "
7: "--.. "
8: "---.. "
9: "----. "
За целта използвайте цикъл и оператор switch*/
void Zadacha2(void);
/*Задача Домашно
Да се състави програма на C, чрез която се въвеждат естествени числа от интервала
[1..50].
Програмата да преустановява работата си при въвеждане на 2 последователни числа,
които са равни.
Програмата да извежда
броя на въведените числа и тяхната средна стойност.
Пример:
1,2,3,4,5,5
Изход:
брой 6, средна стойност 3.33333*/
void Zadacha4(void);

int main()
{
	//Zadacha1();

	//Zadacha2();
	
	//Zadacha4();

	

	//задача 3 в процес
	/*char colors[4][6] = {"trefa", "karo","kupa","pika"};
	int num;
	printf("Enter num: ");
	scanf("%d", &num);
	int num2 = (52-num)+1;
	int num3 = num2%4;
	int num4 = num3;
	
	for (int i = nu; i < 13; i++)
	{
		
		for (int j = num3; j < 4; j++)
		{
			printf("%s\t", colors[j]);
		}
		num3 = 0;
		
	}*/

	return (0);
}

void Zadacha1()
{
	int counter0 = 0;
	int counter1 = 0;
	int counter2 = 0;
	int counter3 = 0;
	int counter4 = 0;
	int counter5 = 0;
	int counter6 = 0;
	int counter7 = 0;
	int counter8 = 0;
	int counter9 = 0;

	int num;
	int tempNum;
	printf("Enter num: ");
	scanf("%d", &num);

	while (num != 0)
	{
		tempNum = num%10;
		switch (tempNum)
		{
		case 0:
			counter0++;
			break;
		case 1:
			counter1++;
			break;
		case 2:
			counter2++;
			break;
		case 3:
			counter3++;
			break;
		case 4:
			counter4++;
			break;
		case 5:
			counter5++;
			break;
		case 6:
			counter6++;
			break;
		case 7:
			counter7++;
			break;
		case 8:
			counter8++;
			break;
		case 9:
			counter9++;
			break;
		
		default:
			break;
		}
		num/=10;
	}
	printf("Frequency of 0 = %d\n", counter0);
	printf("Frequency of 1 = %d\n", counter1);
	printf("Frequency of 2 = %d\n", counter2);
	printf("Frequency of 3 = %d\n", counter3);
	printf("Frequency of 4 = %d\n", counter4);
	printf("Frequency of 5 = %d\n", counter5);
	printf("Frequency of 6 = %d\n", counter6);
	printf("Frequency of 7 = %d\n", counter7);
	printf("Frequency of 8 = %d\n", counter8);
	printf("Frequency of 9 = %d\n", counter9);

}

void Zadacha2()
{
	char arr0[] = "----- ";
	char arr1[] = ".... ";
	char arr2[] = "...- ";
	char arr3[] = "..-- ";
	char arr4[] = "..--- ";
	char arr5[] = ".---- ";
	char arr6[] = "-... ";
	char arr7[] = "--.. ";
	char arr8[] = "---.. ";
	char arr9[] = "----. ";
	
	int num;
	int tempNum;
	printf("Enter num: ");
	scanf("%d", &num);
	//int lenght = CheckNumLenght(num);
	while (num != 0)
	{
		tempNum = num%10;
		switch (tempNum)
		{
			case 0:
		printf("%s", arr0);
			break;
			case 1:
		printf("%s", arr1);
			break;
			case 2:
		printf("%s",arr2);
			break;
			case 3:
		printf("%s",arr3);
			break;
			case 4:
		printf("%s",arr4);
			break;
			case 5:
		printf("%s", arr5);
			break;
			case 6:
		printf("%s", arr6);
			break;
			case 7:
		printf("%s", arr7);
			break;
			case 8:
		printf("%s", arr8);
			break;
			case 9:
		printf("%s", arr9);
			break;
			
		default:
			break;
		}
		num/=10;
	}
}

void Zadacha4()
{
	int n;
	int num;
	int prevNum;
	int counter = 1;

	printf("Enter nums: ");
	scanf("%d", &num);
	prevNum = num;
	double sum = num;

	do
	{
		prevNum = num;
		printf("Enter nums: ");
		scanf("%d", &num);
		sum += num;
		counter ++;
	} while (num != prevNum);
	
	printf("Mid sum: %lf\n", sum/counter);
	printf("Counter: %d\n", counter);
}