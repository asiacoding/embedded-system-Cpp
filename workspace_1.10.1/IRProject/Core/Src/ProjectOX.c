/*
 About Codes )
 int winner[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};
 int len = GetLenInt(winner); //Get Last Index
 winner[(len == 0) ? 0 : len - 1] = Player;
 Box1) |
 ________________________________
 | 1, ,1 | arr Index -> | 1,0,1 |
 | 1,2,2 |              | 1,2,2 |
 | 2, ,  | <- UI        | 2,0,0 |
 |-------|--------------|-------|


 */

#include "fonts.h"
#include "ssd1306.h"
#include "stdio.h"
#include "ProjectOX.h"
#include "EX.h"

//Base Method add here only

void PrintLCDByFont(uint16_t X, uint16_t Y, char *str, FontDef_t *Font,
		int IndexColor) {
	SSD1306_GotoXY(X, Y);
	SSD1306_Puts(str, Font,
			IndexColor == 0 ? SSD1306_COLOR_BLACK : SSD1306_COLOR_WHITE);
}
void PrintLCD(uint16_t X, uint16_t Y, char *str, int IndexColor) {
	SSD1306_GotoXY(X, Y);
	SSD1306_Puts(str, &Font_7x10,
			IndexColor == 0 ? SSD1306_COLOR_BLACK : SSD1306_COLOR_WHITE);
}
void AddTotal(char *str, int BagOrSmail) {
	if (BagOrSmail == 0) {
		PrintLCDByFont(20, 0, str, &Font_7x10, 1);
	} else {
		PrintLCDByFont(20, 0, str, &Font_11x18, 1);
	}
}


// Add X or O Value Only
char * MapPlayerChar[8] = { " ", " ", " ", " ", " ", " ", " ", " ", " ", };

//Main Method
void GetList(int *Index, int *IndexMenu)
{
	DisplyGird(*Index);

	// This job is very important, please do not change anything here
	SSD1306_UpdateScreen();
}

int Play(int index, int Player) {
	MapPlayerChar [index] =
			Player == 1 ? "X" :
					Player == 2 ? "O" : " ";

	return 0;//StatusGame();
}



// 10 = End Gamse
// 1 = Win
// 0 = Runing play
struct GameOver StatusGame() {
/*

	  ---------------
	  Summary
	  ---------------
   	  Here the cells inside the game are calculated and sent if any of the two players won or not

	  ---------------
	  how to Work !!
	  ---------------




*/
	struct GameOver GamesStatus;

	int WIN1 = 0,
		WIN2 = 0,
		Status = 0;

	WIN1 =
	MapPlayerChar[1 - 1] == 'X' && MapPlayerChar[2 - 1] == 'X' && MapPlayerChar[3 - 1] == 'X' ? 1 :      //123
    MapPlayerChar[4 - 1] == 'X' && MapPlayerChar[5 - 1] == 'X' && MapPlayerChar[6 - 1] == 'X' ? 1 :  	//456
    MapPlayerChar[7 - 1] == 'X' && MapPlayerChar[8 - 1] == 'X' && MapPlayerChar[9 - 1] == 'X' ? 1 :  	//789
    MapPlayerChar[1 - 1] == 'X' && MapPlayerChar[5 - 1] == 'X' && MapPlayerChar[9 - 1] == 'X' ? 1 :  	//159
    MapPlayerChar[3 - 1] == 'X' && MapPlayerChar[5 - 1] == 'X' && MapPlayerChar[7 - 1] == 'X' ? 1 :  	//357
    MapPlayerChar[1 - 1] == 'X' && MapPlayerChar[4 - 1] == 'X' && MapPlayerChar[7 - 1] == 'X' ? 1 :  	//147
    MapPlayerChar[2 - 1] == 'X' && MapPlayerChar[5 - 1] == 'X' && MapPlayerChar[8 - 1] == 'X' ? 1 :  	//258
    MapPlayerChar[3 - 1] == 'X' && MapPlayerChar[6 - 1] == 'X' && MapPlayerChar[9 - 1] == 'X' ? 1 : 		//369
    		0;

	WIN2 =
    MapPlayerChar[1 - 1] == 'O' && MapPlayerChar[2 - 1] == 'O' && MapPlayerChar[3 - 1] == 'O' ? 1 : 	//123
	MapPlayerChar[4 - 1] == 'O' && MapPlayerChar[5 - 1] == 'O' && MapPlayerChar[6 - 1] == 'O' ? 1 : 	//456
	MapPlayerChar[7 - 1] == 'O' && MapPlayerChar[8 - 1] == 'O' && MapPlayerChar[9 - 1] == 'O' ? 1 : 	//789
	MapPlayerChar[1 - 1] == 'O' && MapPlayerChar[5 - 1] == 'O' && MapPlayerChar[9 - 1] == 'O' ? 1 : 	//159
	MapPlayerChar[3 - 1] == 'O' && MapPlayerChar[5 - 1] == 'O' && MapPlayerChar[7 - 1] == 'O' ? 1 : 	//357
	MapPlayerChar[1 - 1] == 'O' && MapPlayerChar[4 - 1] == 'O' && MapPlayerChar[7 - 1] == 'O' ? 1 : 	//147
	MapPlayerChar[2 - 1] == 'O' && MapPlayerChar[5 - 1] == 'O' && MapPlayerChar[8 - 1] == 'O' ? 1 : 	//258
	MapPlayerChar[3 - 1] == 'O' && MapPlayerChar[6 - 1] == 'O' && MapPlayerChar[9 - 1] == 'O' ? 1 :  //369
			0;

	Status = 0;// MapPlayerChar[1 - 1] == ' ' && MapPlayerChar[2 - 1] != ' ' && MapPlayerChar[3 - 1] != ' '
		  //&& MapPlayerChar[6 - 1] == ' ' && MapPlayerChar[5 - 1] != ' ' && MapPlayerChar[4 - 1] != ' '
		  //&& MapPlayerChar[7 - 1] == ' ' && MapPlayerChar[8 - 1] != ' ' && MapPlayerChar[9 - 1] != ' '  ?
//				  1 : 0;

	//Set End Gmae
	GamesStatus.Stuts = (Status == 1) ? 2 : WIN2 == 1 || WIN1 == 1 ? 1 : 0;

	// Value = -1 Stuts == 1
	// Value = 1  First play won  'X'
	// Value = 2  Second play won 'O'
	// Value = 0  any other case
	GamesStatus.WinPlayer = (WIN1 == 1) ? 1 : (WIN2 == 1) ? 2 : Status == 1 ? -1 : 0;

	return GamesStatus;
}

void DisplyGird(int IndexPlay) {
/*
	  ---------------
	  Summary
	  ---------------
	  Here the length of the text and graphics inside the screen is calculated and the information is sent to it
	  ---------------
	  how to Work !!
	  ---------------
	  An example of this is done depending on if the number 1 is sent in the variable [IndexPlay]

	  PrintLCD(X1, Y1, MapPlayerChar [0] , (IndexPlay ==  ( ( 1 ) ) <-----       ) ? 0 : 1)

	  If the condition is met,
	  	  the color is reversed, and this is how the required element is distinguished
*/




	SSD1306_DrawRectangle(0, //X
			0, // Y
			24 + 12 + 5, // W
			24 + 12 + 3, // H
			1); //


	int X1 = 0 + 5;  // X and Y in Rectangle
	int X2 = 12 + 5; //
	int X3 = 24 + 5; // W in Rectangle

	int Y1 = 0 + 3; //
	int Y2 = 12 + 3; //
	int Y3 = 24 + 3; // H in Rectangle



	//------------------------------------
	PrintLCD(X1, Y1, MapPlayerChar[0], (IndexPlay == 0) ? 0 : 1);
	PrintLCD(X2, Y1, MapPlayerChar[1], (IndexPlay == 1) ? 0 : 1);
	PrintLCD(X3, Y1, MapPlayerChar[2], (IndexPlay == 2) ? 0 : 1);

	//-------------------------------------
	PrintLCD(X1, Y2, MapPlayerChar[3], (IndexPlay == 3) ? 0 : 1);
	PrintLCD(X2, Y2, MapPlayerChar[4], (IndexPlay == 4) ? 0 : 1);
	PrintLCD(X3, Y2, MapPlayerChar[5], (IndexPlay == 5) ? 0 : 1);

	//-------------------------------------
	PrintLCD(X1, Y3, MapPlayerChar[6], (IndexPlay == 6) ? 0 : 1);
	PrintLCD(X2, Y3, MapPlayerChar[7], (IndexPlay == 7) ? 0 : 1);
	PrintLCD(X3, Y3, MapPlayerChar[8], (IndexPlay == 8) ? 0 : 1);

	//-------------------------------------
//	PrintLCD(24 + 12 + 5 + 5, 0, (IndexPlay == 10) ? "  New Game  " : "            ", (IndexPlay == 10) ? 0 : 1);
}








