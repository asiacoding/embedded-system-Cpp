#include "fonts.h"
#include "ssd1306.h"
#include "stdio.h"
#include "stm32f1xx_hal.h"

int GetLenInt(int arr[]);
int GetLenChar(char str[]);

struct GameOver {
	// value == 1 One of the players won
	// value == 2 The game is over without anyone winning
	// value == 0 The game is still on
	int Stuts;

	// Value = -1 Stuts==1
	// Value = 1  First play won  'X'
	// Value = 2  Second play won 'O'
	// Value = 0  any other case
	int WinPlayer;
};



/*
 How to Ues
 int values[100] = { 1,2 ... };
 foreach(int *v, values)
 {
 int index = (*v); // Get Index in Array
 }
 */

#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)

/*
 How to ues
 int values[100] = { 1,2 ... };
 int IndexValue=10;
 int NewValue=10;
 addarr(&values,IndexValue,NewValue);
 */
#define addarr(itemarry,Index,Value) \
	*itemarry[Index] = Value







