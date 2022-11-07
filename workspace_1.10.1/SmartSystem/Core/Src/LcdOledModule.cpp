/*
 * LcdOledModule.cpp
 *
 *  Created on: Oct 31, 2022
 *      Author: Ahmed Ashraf
 */

#include "LcdOledModule.h"
#include "fonts.h"
#include "ssd1306.h"
#include "ssd1306.c"


void LcdOledModule::SetText(char* str, FontDef_t* Font, uint16_t X, uint16_t Y,
		 SSD1306_COLOR_t color) {
	//SSD1306_GotoXY (X, Y);
	//SSD1306_Puts (str, Font, color);
}

void LcdOledModule::Clear ()
{
	SSD1306_Clear();
}












