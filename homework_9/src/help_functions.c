#include "help_functions.h"
#define LEN 50

void CutSpaceFrontBack(char* str, int len)
{
	char str2[LEN];
	int index = 0;
	int index2 = 0;
	int lastIndex = len-1;
	
	while (str[index] == ' ')
	{
		index++;
	}
	while (str[lastIndex] == ' ')
	{
		lastIndex--;
	}
	for (int i = index; i <=lastIndex; i++)
	{
		*(str2 + index2) = *(str + i);
		index2++;
	}
	str = str2;
	printf("%s", str);
}
void CutSpaces(char* str, int len)
{
	char str2[LEN];
	int index = 0;

	for (int i = 0; i < len; i++)
	{
		if(*(str+i) != ' ')
		{
			*(str2 + index) = *(str+i);
			index++;
		}
		else
		{
			continue;
		}
	}
	str = str2;
	printf("%s", str);
}
char* Strrev(char* arr)
{
	char* end;
	char* copy = arr;
	end = arr+strlen(arr)-1;
	while (end > copy)
	{
		char temp;
		temp = *copy;		
		*copy++ = *end;
		*end-- = temp;		
	}	
	return arr;
}
char* Sort(char* str, int len)
{
	char key;
	int j;
	for (int i = 1; i < len; i++)
	{
		key = str[i];
		j = i-1;
		while (j >= 0 && str[j] >key)
		{
			str[j+1] = str[j];
			j--;
		}
		str[j+1] = key;
	}
	return str;
}
