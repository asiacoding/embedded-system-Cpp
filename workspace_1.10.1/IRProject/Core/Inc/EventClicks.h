#include "stm32f1xx_hal.h"

/*
 * Name  	| Index | CountIndex
 * ----------------------------------
 * MainMun  | 0	     | ( Index = 0 ~ 1 )
 * Led   	| 1 	 | ( index = 0 ~ 3 )
 * LEDs RGB | 2 	 | ( index = 0 ~ 3 )
 * */

static int DoRuningBuzzer = 0;

int ClickButtons(int* index,int* MainMenu);
void EventMeunLed(int Myindex,int* MainMenu);
void EventMeunLEDsRGP(int Myindex,int* MainMenu);
void EventBuzzer(int Myindex,int* MainMenu);
void EventBeSoon(int Myindex,int* MainMenu);

