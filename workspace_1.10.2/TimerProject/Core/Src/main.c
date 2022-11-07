/*


 - in SysTick Method  - SysTick_Handler			|
 * R 100 ms running 10 Loops in per second		|  	🤗
 * G 500 ms running 2 Loops in per second		|
 * B 1000 ms running 1 Loops in per second		|

 Notes Remove Method SysTick_Handler in Other File Name In Stm32 - F103c8t6 locFile: stm32f1xx_it.h ⭐⭐⭐⭐

 * */

#include "main.h"

int Read_Pins(GPIO_TypeDef *GPIOx, int Pin) {
	return GPIOx->IDR & (1 << Pin);
}
void WritePins(GPIO_TypeDef *GPIOx, int Pin) {
	GPIOx->ODR |= (1 << Pin);
}
void ClaerPins(GPIO_TypeDef *GPIOx, int Pin) {
	GPIOx->ODR &= ~(1 << Pin);
}
void Tagger_Pins(GPIO_TypeDef *GPIOx, int Pin) {
	if (Read_Pins(GPIOx, Pin) == 0)
		WritePins(GPIOx, Pin);
	else
		ClaerPins(GPIOx, Pin);
}
void sysTickDelay(int delay) {
	while (delay--) {
		while (!(SysTick->CTRL & (1 << 16))) {
		}; // Check Dely is Opne Or No ?
	}
}
void InitPins() {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3,
			GPIO_PIN_RESET);
	GPIO_InitStruct.Pin = GPIO_PIN_13;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

volatile uint32_t msTicks = 0;

void SysTick_Handler(void) {
	if (msTicks == 10) {
		msTicks = 0;
		Tagger_Pins(GPIOA, 3); //== 1S Led Red
	}
	Tagger_Pins(GPIOA, 1); //100 ms Led
	if (msTicks == 5) {
		Tagger_Pins(GPIOA, 2); //500 ms
	}
	msTicks += 1;
}

int main(void) {

	InitPins(); // cofing
	SysTick->CTRL = (1 << 0) | (1 << 2);
	SysTick->LOAD = 8000 - 1;
	SystemCoreClockUpdate();
	//SystemCoreClock  Generate interrupt each 100 ms = 10Loop in 1S
	SysTick_Config(SystemCoreClock / 100);

	while (1)
		;
}