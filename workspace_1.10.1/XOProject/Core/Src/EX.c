#include "EX.h"
#include "stdio.h"
#include "stm32f1xx_hal.h"
#include <stdio.h>
#include <string.h>


int GetLenChar(char str[])
{
	int Length = 0;
	for (Length = 0; str[Length] != '\0'; ++Length);
	return Length;
}

int GetLenInt(int arr[])
{
	int index = 0;
	while( arr[index] != -1 ){
		index+=1;
	}
	return index;
}
