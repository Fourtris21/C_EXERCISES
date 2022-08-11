#include "help_functions.h"

int Check_1(int num)
{
    int temp = num;
    int hours = 0;
    while (temp != 1)
    {
        if(num == 1)
        {
            hours = 1;
            break;
        }
        if(temp == 2)
        {
            temp--;
            hours++;
            break;
        }
        if(temp % 2 == 0)
        {
            temp/=2;
            hours++;
        }
        else
        {
            temp--;
            hours++;
        }
    }
    return hours;
}
int Check_2(int num)
{
    int temp = num+1;
    int hours = 1;
    while (temp != 1)
    {
        if(num == 1)
        {
            hours = 1;
            break;
        }
        if(temp == 2)
        {
            temp--;
            hours++;
            break;
        }
        if(temp % 2 == 0)
        {
            temp/=2;
            hours++;
        }
        else
        {
            temp--;
            hours++;
        }
    }
    return hours;
}