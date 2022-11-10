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
char * MapPlayerChar[] = { " ", " ", " ", " ", " ", " ", " ", " ", " "," " };
//Index 0 = X
//Index 1 = O

static int WinnerCountsA = 0; //X -< Count Of Win
static int WinnerCountsB = 0; //O -< ......
char strScr[25];
int Menu = 0;

//Main Method
void GetList(int *Index, int *IndexMenu)
{

	//Adress Page
	Menu = *IndexMenu;

	//See UI to SSD1603 LCD
	DisplyGird(*Index);

	// This job is very important, please do not change anything here
	SSD1306_UpdateScreen();
}


//A query is made here about the states of the place in the array. If it does not find any of the X or O, it is returned with zero otherwise 1
int CheckIndexGrid(int index)
{
	//Why is it because when you press the play button, this thing is repeated here and now it must be guessed about this matter
	return *MapPlayerChar [index] != ' ' ? 1 : 0;
}

struct GameOver Play(int index, int Player) {

	if(*MapPlayerChar [index] == ' ')
	{
	MapPlayerChar [index] =
			Player == 1 ? "X" :
					Player == 2 ? "O" : " ";
	}
	return StatusGame();//StatusGame();

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
	*MapPlayerChar[1 ] == 'X' && *MapPlayerChar[2 ] == 'X' && *MapPlayerChar[3 ] == 'X' ? 1 :      //123
    *MapPlayerChar[4 ] == 'X' && *MapPlayerChar[5 ] == 'X' && *MapPlayerChar[6 ] == 'X' ? 1 :  	//456
    *MapPlayerChar[7 ] == 'X' && *MapPlayerChar[8 ] == 'X' && *MapPlayerChar[9 ] == 'X' ? 1 :  	//789
    *MapPlayerChar[1 ] == 'X' && *MapPlayerChar[5 ] == 'X' && *MapPlayerChar[9 ] == 'X' ? 1 :  	//159
    *MapPlayerChar[3 ] == 'X' && *MapPlayerChar[5 ] == 'X' && *MapPlayerChar[7 ] == 'X' ? 1 :  	//357
    *MapPlayerChar[1 ] == 'X' && *MapPlayerChar[4 ] == 'X' && *MapPlayerChar[7 ] == 'X' ? 1 :  	//147
    *MapPlayerChar[2 ] == 'X' && *MapPlayerChar[5 ] == 'X' && *MapPlayerChar[8 ] == 'X' ? 1 :  	//258
    *MapPlayerChar[3 ] == 'X' && *MapPlayerChar[6 ] == 'X' && *MapPlayerChar[9 ] == 'X' ? 1 : 		//369
    		0;

	WIN2 =
    *MapPlayerChar[1 ] == 'O' && *MapPlayerChar[2 ] == 'O' && *MapPlayerChar[3 ] == 'O' ? 1 : 	//123
	*MapPlayerChar[4 ] == 'O' && *MapPlayerChar[5 ] == 'O' && *MapPlayerChar[6 ] == 'O' ? 1 : 	//456
	*MapPlayerChar[7 ] == 'O' && *MapPlayerChar[8 ] == 'O' && *MapPlayerChar[9 ] == 'O' ? 1 : 	//789
	*MapPlayerChar[1 ] == 'O' && *MapPlayerChar[5 ] == 'O' && *MapPlayerChar[9 ] == 'O' ? 1 : 	//159
	*MapPlayerChar[3 ] == 'O' && *MapPlayerChar[5 ] == 'O' && *MapPlayerChar[7 ] == 'O' ? 1 : 	//357
	*MapPlayerChar[1 ] == 'O' && *MapPlayerChar[4 ] == 'O' && *MapPlayerChar[7 ] == 'O' ? 1 : 	//147
	*MapPlayerChar[2 ] == 'O' && *MapPlayerChar[5 ] == 'O' && *MapPlayerChar[8 ] == 'O' ? 1 : 	//258
	*MapPlayerChar[3 ] == 'O' && *MapPlayerChar[6 ] == 'O' && *MapPlayerChar[9 ] == 'O' ? 1 :  //369
			0;

	Status = *MapPlayerChar[1 ] == ' ' && *MapPlayerChar[2 ] != ' ' && *MapPlayerChar[3 ] != ' '
		  && *MapPlayerChar[6 ] == ' ' && *MapPlayerChar[5 ] != ' ' && *MapPlayerChar[4 ] != ' '
		  && *MapPlayerChar[7 ] == ' ' && *MapPlayerChar[8 ] != ' ' && *MapPlayerChar[9 ] != ' '  ?
				  1 : 0;

	//Add 1 Point to Player then Win 😏
	if(WIN1 == 1)  WinnerCountsA = WinnerCountsA+1;
	else if(WIN2 == 1)  WinnerCountsB = WinnerCountsB+1;

	//Set End Gmae
	GamesStatus.Stuts = (Status == 1) ? 2 : WIN2 == 1 || WIN1 == 1 ? 1 : 0;

	// Value = -1 Stuts == 1
	// Value = 1  First play won  'X'
	// Value = 2  Second play won 'O'
	// Value = 0  any other case
	GamesStatus.WinPlayer = (WIN1 == 1) ? 1 : (WIN2 == 1) ? 2 : Status == 1 ? -1 : 0;


	if(GamesStatus.WinPlayer != 0 ){
		MapPlayerChar[0]=" ";
		MapPlayerChar[1]=" ";
		MapPlayerChar[2]=" ";
		MapPlayerChar[3]=" ";
		MapPlayerChar[4]=" ";
		MapPlayerChar[5]=" ";
		MapPlayerChar[6]=" ";
		MapPlayerChar[7]=" ";
		MapPlayerChar[8]=" ";
		MapPlayerChar[9]=" ";
	}


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



uint16_t Left = (128/2)-(39/2);
int Top = 20;



	int X1 = Left + 5;  // X and Y in Rectangle
	int X2 = Left+12 + 5; //
	int X3 = Left+24 + 5; // W in Rectangle

	int Y1 = Top + 3; //
	int Y2 = Top+ 12 + 3; //
	int Y3 = Top + 24 + 3; // H in Rectangle





	//-------------------------------------
	PrintLCD(0, 0, (IndexPlay >= 10 || IndexPlay == 0) ? " <- new Game -> " : " Runing game    ",(IndexPlay >= 10 || IndexPlay == 0) ? 0:1);

	//
	//			   [Mune]
	//
	//          ------------
	//          |          |
	//    [0]   |          |  [0]
	//     X    | GamePlay |   O
	//          |          |
	//		    ------------


	sprintf(strScr ,WinnerCountsA==0? "-" : "%i",WinnerCountsA);
	PrintLCD( (X3/2-12) , 12+10,  strScr ,  1);
	PrintLCDByFont(X1-26-5,32,"X" ,&Font_16x26,1);

	sprintf(strScr ,WinnerCountsB==0? "-" : "%i",WinnerCountsB);
	PrintLCD(X3+12+12+6, 12+10,  strScr ,  1);
	PrintLCDByFont(X3+12+12,32,"O" ,&Font_16x26,1);





SSD1306_DrawRectangle(Left, //X
		Top, // Y
		24 + 12 + 5, // W
		24 + 12 + 3, // H
		1); //
	//------------------------------------
	PrintLCD(X1, Y1, MapPlayerChar[1], (IndexPlay == 1) ? 0 : 1);
	PrintLCD(X2, Y1, MapPlayerChar[2], (IndexPlay == 2) ? 0 : 1);
	PrintLCD(X3, Y1, MapPlayerChar[3], (IndexPlay == 3) ? 0 : 1);

	//-------------------------------------
	PrintLCD(X1, Y2, MapPlayerChar[4], (IndexPlay == 4) ? 0 : 1);
	PrintLCD(X2, Y2, MapPlayerChar[5], (IndexPlay == 5) ? 0 : 1);
	PrintLCD(X3, Y2, MapPlayerChar[6], (IndexPlay == 6) ? 0 : 1);

	//-------------------------------------
	PrintLCD(X1, Y3, MapPlayerChar[7], (IndexPlay == 7) ? 0 : 1);
	PrintLCD(X2, Y3, MapPlayerChar[8], (IndexPlay == 8) ? 0 : 1);
	PrintLCD(X3, Y3, MapPlayerChar[9], (IndexPlay == 9) ? 0 : 1);

}








