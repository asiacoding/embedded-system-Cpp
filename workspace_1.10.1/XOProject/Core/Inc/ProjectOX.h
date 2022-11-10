#include "stm32f1xx_hal.h"

/*
 char*MyGame;
 char*WinGame;

 char Play1 ;
 char Play2 ;

 char * WinGame ;

 char *MyGame ;
 * */

void GetList(int *Index, int *IndexMenu);

void AddTotal(char *str, int BagOrSmail);

void PrintLCD(uint16_t X, uint16_t Y, char *str, int IndexColor);

void PrintLCDByFont(uint16_t X, uint16_t Y, char *str, FontDef_t *Font,
		int IndexColor);

struct GameOver StatusGame();

struct GameOver Play(int index, int Player);

void DisplyGird(int IndexPlay);

int CheckIndexGrid(int index);

