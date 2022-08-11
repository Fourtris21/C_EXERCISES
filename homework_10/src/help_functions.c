#include "help_functions.h"

int bitAt(int num, int index)
{
	return (num >> index)&1;
}
int clearBit(int num, int index)
{
	return (num)&(~(1<<index));
}
int setBit(int num, int index)
{
	return num | (1<<index);
}
int reverseBit(int num, int index)
{
	return num ^(1<< index);
}
int setEvenToNull(int num)
{
	for (int i = 0; i < 8; i += 2)
	{
		int result = clearBit(num, i);
		num = result;
	}
	return num;
}
int countBits(int n)
{
	int count = 0;
	while(n)
	{
		count++;
		n >>= 1;
	}
	return count;
}
