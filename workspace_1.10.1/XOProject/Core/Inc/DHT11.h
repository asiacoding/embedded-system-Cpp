#include "main.h"
#include "fonts.h"
#include "ssd1306.h"
#include "stdio.h"
#include "EventClicks.h"

#include "stm32f1xx_hal.h"

struct DHTSS1
{
	uint8_t TCI;
	uint8_t TCD;
	uint8_t TFD;
	uint8_t TFI;
};




void microDelay(uint16_t delay);
uint8_t DHT11_Start(void);
uint8_t DHT11_Read(void);
struct DHTSS1 Check_IN();

