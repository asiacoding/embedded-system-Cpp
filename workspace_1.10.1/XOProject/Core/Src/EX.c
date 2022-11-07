#include "EX.h"
#include "stdio.h"
#include "stm32f1xx_hal.h"



int GetLenInt(int *arr)
{
	int Length = 0;

	while (arr[Length] != 0) {
		Length += 1;
	};
	return Length;
}
