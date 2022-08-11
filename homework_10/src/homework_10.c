#include "homework_10.h"

void Zadacha_1()
{
    int num;
	printf("Enter num: ");
	scanf("%d", &num);
	int lastOneIndex = countBits(num)-1;
	printf("Starshi index sys stojnost 1: %d\n", lastOneIndex);
}
void Zadacha_2()
{
	int num;
	printf("Enter num: ");
	scanf("%d", &num);
	for (int i = 3; i < 8; i++)
	{
		int result = clearBit(num, i);
		num = result;
	}
	printf("%d", num);
}
void Zadacha_3()
{
	int index;
	int num;;
	printf("Enter num: ");
	scanf("%d", &num);
	printf("Enter index from where to clear bits: ");
	scanf("%d", &index);
	for (int i = index; i <= countBits(num); i++)
	{
		int result = clearBit(num, i);
		num = result;
	}
	printf("%d\n", num);
}
void Zadacha_4()
{
	/*int num;
	int result;
	printf("Enter num: ");
	scanf("%d", &num);

	for (int i = 0; i <= countBits(num); i++)
	{
		printf("%d * 2^%d\n",bitAt(num, i) , i);
		result += bitAt(num, i)*pow(2, i);
	}
	printf("%d\n", result);*/
    //задокументирана е, за да не се налага да използвам <math.h>
}
void Zadacha_5()
{
	int num;
	printf("Enter 32-bit num: ");
	scanf("%d", &num);
	for (int i = 0; i <= countBits(num); i++)
	{
		if(i % 3 == 0)
		{
			int result = setBit(num, i);
			num = result;
		}
	}
	printf("%d", num);
}
void Zadacha_6()
{
	int num;
	int num2;
	int counter = 0;
	printf("Enter first num: ");
	scanf("%d", &num);
	printf("Enter second num: ");
	scanf("%d", &num2);
	int len = 0;

	if(countBits(num) > countBits(num2))
	{
		len = countBits(num2);
		counter += countBits(num) - countBits(num2);
	}
	else
	{
		len = countBits(num);
		counter += countBits(num2) - countBits(num);
	}

	for (int i = 0; i <= len; i++)
	{
		if(bitAt(num, i) != bitAt(num2, i))
		{
			counter++;
		}
	}
	printf("Count of different positions: %d\n", counter);
}
void Zadacha_7()
{
	int num;
	printf("Enter num: ");
	scanf("%d", &num);
	for (int i = 0; i < sizeof(num)*3; i++)
	{
		if(i % 2 != 0)
		{
			int result = reverseBit(num, i);
			num = result;
		}
	}
	printf("%d", num);
}
void WelcomeFunction()
{
    void (*zadacha_pointer[10])() = {Zadacha_1 ,Zadacha_2, Zadacha_3, Zadacha_4, Zadacha_5, Zadacha_6, Zadacha_7};
    printf("Enter 1 to 7 to choose Zadacha: ");
	int option;
	scanf("%d", &option);
	switch (option)
	{
	case 1:
		zadacha_pointer[0]();
		break;
	case 2:
		zadacha_pointer[1]();
		break;
	case 3:
		zadacha_pointer[2]();
		break;
	case 4:
		zadacha_pointer[3]();
		break;
	case 5:
		zadacha_pointer[4]();
		break;
	case 6:
		zadacha_pointer[5]();
		break;
	case 7:
		zadacha_pointer[6]();
		break;
	default:
		break;
	}
}

