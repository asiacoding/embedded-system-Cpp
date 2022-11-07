#include "fonts.h"
#include "ssd1306.h"
#include "stdio.h"
#include "DrowingLCD.h"
#include "DHT11.h"

//Base Method add here only
void PrintLCDByFont(uint16_t X, uint16_t Y, char *str, FontDef_t *Font,
		int IndexColor) {
	SSD1306_GotoXY(X, Y);
	SSD1306_Puts(str, Font,
			(IndexColor == 0) ? SSD1306_COLOR_BLACK : SSD1306_COLOR_WHITE);
}
void PrintLCD(uint16_t X, uint16_t Y, char *str, int IndexColor) {
	SSD1306_GotoXY(X, Y);
	SSD1306_Puts(str, &Font_7x10,
			(IndexColor == 0) ? SSD1306_COLOR_BLACK : SSD1306_COLOR_WHITE);
}

void AddTotal(char *str, int BagOrSmail) {
	if (BagOrSmail == 0) {
		PrintLCDByFont(20, 0, str, &Font_7x10, 1);
	} else {
		PrintLCDByFont(20, 0, str, &Font_11x18, 1);
	}
}

//Main Method
void GetList(int *Index, int *IndexMenu) {

	int MyValueIndex = *Index;
	int MyValueMainMenu = *IndexMenu;

	char *NameSol[10] =
	{
			"LEDs                         ",// = 1
			"LEDs RGB                     ",// = 2
			"temperature sensors          ",// = 3
			"Buzzer                       ",// = 4
			"Motor                        ",// = 5
			"About                        ",// = 6
			"ShutDown                     " // = 7
	};

	if (MyValueMainMenu == 0) {
		AddTotal("Menu                       ", 1);
		GetListMainMenus(MyValueIndex, NameSol);

	} else if (MyValueMainMenu == 1) {
		AddTotal(NameSol[MyValueMainMenu - 1], 0);
		GetListLed(MyValueIndex);

	} else if (MyValueMainMenu == 2) {
		AddTotal(NameSol[MyValueMainMenu - 1], 0);
		GetListLed_RGB(MyValueIndex);

	} else if (MyValueMainMenu == 3) {
		PrintLCDByFont(0, 0, NameSol[MyValueMainMenu - 1], &Font_7x10, 1);
		GetListTemperatureSensor(MyValueIndex);

	} else if (MyValueMainMenu == 4) {
		PrintLCDByFont(
				0,
				0,
				NameSol[MyValueMainMenu - 1],
				&Font_7x10,
				1);
		GetListBuzzerSensor(MyValueIndex);

	} else if (MyValueMainMenu == 6) {
		//AddTotal(NameSol[MyValueMainMenu - 1],0);
		GetListAbout(MyValueIndex);
	}

	//Add Here New UI here ..

	else {
		AddTotal(NameSol[MyValueMainMenu - 1], 1);
		GetListSoonModel(); // [🌟]
	}

	//See Any Text [🌟]
	SSD1306_UpdateScreen();
}
void GetListMainMenus(int IndexMenu, char *str[]) {

	char *OldValue = str[IndexMenu - 1];  // Find the value before the current
	char *Value = str[IndexMenu];         // Find the current value
	char *NextValue = str[IndexMenu + 1]; // Find the following value

	if ((IndexMenu - 1) > -1) {
		PrintLCD(0, 24, OldValue, 1);
	} else {
		PrintLCD(0, 24, "                    ", 1);
	}
	PrintLCD(0, 36, Value, 0);
	if ((IndexMenu + 1) < 7) {
		PrintLCD(0, 48, NextValue, 1);
	} else {
		PrintLCD(0, 48, "                    ", 1);
	}

}

//Method Groups
void GetListLed(int IndexMenu) {
	PrintLCD(0, 12,
			(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == 0) ?
					"Led 1 = off                " :
					"Led 1 = on                 ",
			(IndexMenu <= 0 || IndexMenu >= 4) ? 0 : 1);
	PrintLCD(0, 24,
			(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_14) == 0) ?
					"Led 2 = off                " :
					"Led 2 = on                 ", (IndexMenu == 1) ? 0 : 1);
	PrintLCD(0, 36,
			(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15) == 0) ?
					"Led 3 = off                " :
					"Led 3 = on                 ", (IndexMenu == 2) ? 0 : 1);
	PrintLCD(0, 48, "Back", (IndexMenu == 3) ? 0 : 1);
}

void GetListLed_RGB(int IndexMenu) {

	//int Y = IndexMenu*12+12;
//IndexMenu*12+12

	//SSD1306_DrawFilledCircle(110,12-3,5,(IndexMenu==0)?SSD1306_COLOR_WHITE:SSD1306_COLOR_BLACK);
	//SSD1306_DrawFilledCircle(110,24-3,5,(IndexMenu==1)?SSD1306_COLOR_WHITE:SSD1306_COLOR_BLACK);
	//SSD1306_DrawFilledCircle(110,36-3,5,(IndexMenu==2)?SSD1306_COLOR_WHITE:SSD1306_COLOR_BLACK);
	//SSD1306_DrawFilledCircle(110,48-3,5,(IndexMenu==3)?SSD1306_COLOR_WHITE:SSD1306_COLOR_BLACK);

	PrintLCD(0, 12,
			(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0) ?
					"Red: off                   " :
					"Red: on                    ",
			(IndexMenu <= 0 || IndexMenu >= 4) ? 0 : 1);
	PrintLCD(0, 24,
			(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_14) == 0) ?
					"Green: off                 " :
					"Green: on                  ", (IndexMenu == 1) ? 0 : 1);
	PrintLCD(0, 36,
			(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15) == 0) ?
					"Blue: off                  " :
					"Blue: on                   ", (IndexMenu == 2) ? 0 : 1);
	PrintLCD(0, 48, "Back", (IndexMenu == 3) ? 0 : 1);
}

void GetListTemperatureSensor(int IndexMenu) {
	//IndexMenu = 1;
	//Check_IN

	if (DHT11_Start()) {
		struct DHTSS1 Ret;
		Ret = Check_IN();
		char strCopy[15];
		//PB9
		sprintf(strCopy, "%d.%d C      ", Ret.TCI, Ret.TCD);
		PrintLCD(0, 12, strCopy, 1);
		sprintf(strCopy, "%d.%d F      ", Ret.TFI, Ret.TFD);
		PrintLCD(0, 24, strCopy, 1);
		PrintLCD(0, 36, "Back", 0);
	}

}
//PB9
void GetListBuzzerSensor(int IndexMenu) {
	PrintLCD(0, 12, "Test					", (IndexMenu == 1) ? 0 : 1);
	PrintLCD(0, 24, "Back					", (IndexMenu == 2) ? 0 : 1);
}

void GetListAbout(int IndexMenu) {
	//SSD1306_DrawRectangle(uint16_t x,
	//uint16_t y,
	//uint16_t w,
	//uint16_t h,
	//SSD1306_COLOR_t c)

	//SSD1306_COLOR_t Value = SSD1306_COLOR_WHITE;

	/*
	 * 	for (int i = 0; i <= 20; i++) {
	 Value = (Value == SSD1306_COLOR_WHITE) ?
	 SSD1306_COLOR_BLACK : SSD1306_COLOR_WHITE;
	 SSD1306_DrawRectangle(i + 20, i + 20, i - 20, i - 20, Value);

	 }
	 * */

	//HAL_Delay(2);
	///Value = SSD1306_COLOR_BLACK;
	//for (int i = 0; i <= 5; i++) {
	//Value = (Value == SSD1306_COLOR_WHITE) ?
	//		SSD1306_COLOR_BLACK : SSD1306_COLOR_WHITE;
	//	SSD1306_DrawRectangle(i + 20, i + 20, i - 20, i - 20, Value);
	//	int I =10*i;
	//	int Y =10*i;
	//SSD1306_DrawCircle(I,Y,5,SSD1306_COLOR_WHITE);//int16_t x0, int16_t y0, int16_t r
	//SSD1306_DrawFilledCircle(I,Y,3,SSD1306_COLOR_WHITE);
//	}
}
void GetListSoonModel() {
	PrintLCD(0, 36, "Will open soon                 ", 1);
	PrintLCD(0, 48, "Back", 0);
}
