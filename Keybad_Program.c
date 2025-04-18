#include"STD_Types.h"
#include"DIO_Interface.h"
#include"avr/delay.h"

//inialize the pins for keybad
void Key_VidInit(void)
{
	DIO_VidSetPortDirection(1,0b00001111);
	DIO_VidSetPortValue(1,0b11111111);
}

u8 Key_U8GetPressedKey(void)
{
	u8 col,row,res=100;
	for(col=0;col<4;col++)
	{
		DIO_VidSetPinValue(1,col,0);
		for(row=0;row<4;row++)
		{
			if(DIO_U8GetPinValue(1,row+4)==0)
			{
				res=(row*4)+col ;
				// make the function call only one time as iam pushing
				while(DIO_U8GetPinValue(1,row+4)==0)
				{
				}
				//to eliminate the bouncing after removing your hand
				_delay_ms(2);
			}
		}
		DIO_VidSetPinValue(1,col,1);
	}

	return res;

}

/* program in the main

void main(void)
{
Key_VidInit();
LCD_VidInt() ;

u8 x;
Key_U8GetPressedKey();
if(x!=100) assume any number
{
	LCD_VidSendNumber(x);
}
}
 */




