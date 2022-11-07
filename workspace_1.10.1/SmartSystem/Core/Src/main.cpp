#include "ConfingSystem.h"
#include "main.h"
#include "fonts.h"
#include "ssd1306.h"
#include "LcdOledModule.h"
#include "stdio.h"
int main() {
	ConfingSystem ConfiObj;
	LcdOledModule LcdObj;
	ConfiObj.InitApp();
	while (1) {

		int i = 0;

		for (; i > 4000; i++) {

			char buffer[100];
			int age = i;
			// print "My age is " and age variable to buffer variable
			sprintf(buffer, "Count %d", age);
			ConfiObj.TogglePin(GPIOC, GPIO_PIN_14);
			LcdObj.SetText(buffer, &Font_7x10, 0, 0, SSD1306_COLOR_BLACK);
			HAL_Delay(1000);
		}

	}

}



