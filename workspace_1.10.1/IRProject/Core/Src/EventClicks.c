#include "main.h"
#include "fonts.h"
#include "ssd1306.h"
#include "stdio.h"
#include "EventClicks.h"

/*
 * Name  	| Index | CountIndex
 * ----------------------------------
 * MainMun  | 0	     | ( Index = 0 ~ 6 )
 * Led   	| 1 	 | ( index = 0 ~ 3 )
 * LEDs RGB | 2 	 | ( index = 0 ~ 3 )
 * */

int ClickButtons(int *index, int *MainMenu) {

	int GetIndexValue = *index;
	int GetMainMenuValue = *MainMenu;

	//Add in 30/10/2022
	if (GetMainMenuValue == 0) //Move To AnyPage
		*MainMenu = GetIndexValue + 1;//EventMainMeun(GetIndexValue, MainMenu);
	//Add in 30/10/2022
	else if (GetMainMenuValue == 1)
		EventMeunLed(GetIndexValue, MainMenu);
	//Add in 30/10/2022
	else if (GetMainMenuValue == 2)
		EventMeunLEDsRGP(GetIndexValue, MainMenu);

	// < here
	else if (GetMainMenuValue == 4)
		EventBuzzer(GetIndexValue, MainMenu);
	//Add Here New Method 🔼

	else
		EventBeSoon(GetIndexValue, MainMenu);


	return GetMainMenuValue; // Back Values
}

//

void EventMeunLed(int Myindex, int *MainMenu) {

	if (Myindex == 0) { HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13); }
	else if (Myindex == 1) { HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_14); }
	else if (Myindex == 2) { HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_15); }
	else if (Myindex == 3) { *MainMenu = 0; } // Back TO MainMeun

}

void EventMeunLEDsRGP(int Myindex,int* MainMenu)
{
	if (Myindex == 0) { HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1); }
	else if (Myindex == 1) { HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2); }
	else if (Myindex == 2) { HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_3); }
	else if (Myindex == 3) { *MainMenu = 0; } // Back TO MainMeun
}

void EventBuzzer(int Myindex,int* MainMenu)
{
	if(Myindex == 0)
	{
		DoRuningBuzzer = (DoRuningBuzzer == 1) ? 0 : 1 ;
	}
	else if(Myindex == 1)
	{
		*MainMenu = 0;
	}
}




//Soon Page
void EventBeSoon(int Myindex,int* MainMenu){
	//Anyway back to the main page
	*MainMenu = 0;
}













