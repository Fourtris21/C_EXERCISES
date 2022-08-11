#include "homework_9.h"
#define LEN 50

void Zadacha_1()
{
	char niz[] = "nesto si tam";
	char* string = niz;
	int index = 0;
	int len = 0;
	
	while (*(string + index) != '\0')
	{
		len++;
		index++;
	}
	printf("%d", len);
}
void Zadacha_2()
{
	char niz1[20] = "Kazwam se ";
	char niz2[10] = "Anna";
	int index = 0;
	int len1 = strlen(niz1);
	int len2 = strlen(niz2);
	for (int i = len1; i < len1 + len2+1; i++)
	{
		niz1[i] = niz2[index];
		index++;
	}
	printf("%s", niz1);
}
void Zadacha_3()
{
	char niz1[] = "Obicham pointeri";
	char niz2[] = "Ne obicham pointeri";
	if(strlen(niz1) == strlen(niz2))
	{
		for (int i = 0; i < strlen(niz1); i++)
		{
			if(niz1[i] == niz2[i])
			{
				continue;
			}
			else
			{
				printf("Ne sa ednakvi!!");
				break;
			}	
		}
		printf("Ednakwi nizowe!");
	}
	else
	{
		printf("Ne sa ednakvi!");
	}
}
void Zadacha_4()
{
	char arr[] = "nina";
	char copy[LEN];
	strcpy(copy, arr);
	if(strcmp(copy, Strrev(arr)) == 0)
	{
		printf("Palindrome\n");
	}
	else
	{
		printf("Not palindrome\n");
	}
}
void Zadacha_5()
{
	char symb;
	int counter = 0;
	int bestCounter = 0;
	int index = 0,iPosition = 0, searchedIndex;
	char str[] = "asssssssddfdffghggssssssssggggggghhag";
	printf("%s\n", Sort(str, strlen(str)));

	for (int i = 0; i < strlen(str); i+= iPosition)
	{
		symb = *(str+i);
		iPosition = 0;
		while (symb == *(str+index))
		{
			counter++;
			index++;
			iPosition++;
		}
		if(bestCounter < counter)
		{
			bestCounter = counter;
			searchedIndex = index-1;
		}
		counter = 0;
	}
	
	printf("%d\n", bestCounter);
	printf("%c\n", str[searchedIndex]);
}
void Zadacha_6()
{
	char symb;
	int index = 0;
	int index2 = 0;
	int iPosition = 0;
	char str[] = "asssssssddfdffghggssssshkgjyljgssssggggggghhag";
	char str2[LEN];
	printf("%s\n", Sort(str, strlen(str)));

	for (int i = 0; i < strlen(str); i+=iPosition)
	{
		symb = *(str+i);
		iPosition = 0;
		while (symb == *(str+index))
		{
			index++;
			iPosition++;
		}
		*(str2 + index2) = *(str+(index-1));
		index2++;
	}
	
	printf("%s\n", str2);
}
void Zadacha_7()
{
	char str[] = "      asshhag  ";
	int len = strlen(str);
	CutSpaceFrontBack(str, len);
}
void Zadacha_8()
{
	char str[] = "  jef r  er e   ";
	int len = strlen(str);
	printf("After cutting spaces front and back: ");
	CutSpaceFrontBack(str, len);
	printf("\n");
	printf("After cutting spaces inside the string: ");
	CutSpaces(str, len);
}
void Zadacha_9()
{
	char str[] = "wsdrpointersafjskpointers,nke sjdpointerspointersguyfiyt";
	char searchedString[] = "pointers";
	int searchedStringLen = strlen(searchedString);
	int counter = 0;
	int index = 0;
	int count = 0;
	char* ptr;
	for (int i = 0; i < strlen(str); i++)
	{
	 	ptr = &str[i];
		for (int j = 0; j < searchedStringLen; j++)
		{
			if(*(ptr+j) == *(searchedString+index))
			{
				counter++;
				index++;
			}
			else
			{
				break;
			}
		}
		if(counter == searchedStringLen)
		{
			count++;
		}
		counter = 0;
		index = 0;
	}
	printf("%d\n", count);
}
void Zadacha_10()
{
	char str[] = "wsdrpointersafjskpointers,nke sjdpointerspointerguyfiyt";
	char newStr[LEN];
	char cutString[] = "pointers";
	int cutStringLen = strlen(cutString);
	int counter = 0;
	int index = 0;
	int newStrIndex = 0;
	char* ptr;

	for (int i = 0; i < strlen(str); i++)
	{
	 	ptr = &str[i];
		 int j = 0;
		for (j = 0; j < cutStringLen; j++)
		{
			if(*(ptr+j) == *(cutString+index))
			{
				counter++;
				index++;
			}
			else
			{
				break;
			}
		}
		if(counter == cutStringLen)
		{
			i+=cutStringLen-1;
		}
		else
		{
			for (int k = 0; k <= j; k++)
			{
				
				*(newStr+newStrIndex) = *(ptr+k);
				newStrIndex++;
			}
			i+=j;
		}
		counter = 0;
		index = 0;
	}
	printf("%s\n", newStr);
}
void WelcomeFunction()
{
    void (*zadacha_pointer[10])() = {Zadacha_1, Zadacha_2, Zadacha_3, Zadacha_4, Zadacha_5, Zadacha_6, Zadacha_7, Zadacha_8, Zadacha_9, Zadacha_10};

	printf("Enter 1 to 10 to choose Zadacha: ");
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
	case 8:
		zadacha_pointer[7]();
		break;
	case 9:
		zadacha_pointer[8]();
		break;
	case 10:
		zadacha_pointer[9]();
		break;
	default:
		break;
	}
}
