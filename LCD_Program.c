#include"STD_Types.h"
#include"DIO_Interface.h"
#include"avr/delay.h"


void LCD_VidSendData(u8 Copy_u8Data)
{
DIO_VidSetPinValue(0,0,1); //RS=1 to send data 	

DIO_VidSetPinValue(0,1,0);	//RW=0 to write data
	
DIO_VidSetPortValue(2,Copy_u8Data);	

DIO_VidSetPinValue(0,2,1);// enable bit2
_delay_ms(1);	
	
DIO_VidSetPinValue(0,2,0);
_delay_ms(1);		
}	

void LCD_VidSendCommand(u8 Copy_u8Command)
{
DIO_VidSetPinValue(0,0,0); //RS=0 to send Command 	

DIO_VidSetPinValue(0,1,0);	//RW=0 to write Command
	
DIO_VidSetPortValue(2,Copy_u8Command);	

// enable bit2

DIO_VidSetPinValue(0,2,1);
_delay_ms(1);	
	
DIO_VidSetPinValue(0,2,0);
_delay_ms(1);		
}

void LCD_VidSendNumber(s32 Copy_S32Number)
{
if(Copy_S32Number<0){
	LCD_VidSendData(0b00101101);
	Copy_S32Number=Copy_S32Number*-1;
}
u8 counter=0;
u32 value=0,temp;
	if(Copy_S32Number==0){
		LCD_VidSendData(48);
	}
	while(Copy_S32Number)
	{
		value=(value*10)+(Copy_S32Number%10);
		Copy_S32Number=Copy_S32Number/10;
		if(value==0){
			counter++;
		}
	}
	while(value)
	{
		temp=value%10;
		value=value/10;
		LCD_VidSendData(temp+48);
    }
	for(u8 i=0;i<counter;i++){
			LCD_VidSendData(48);
	}

}   

void LCD_VidSetPosition(u8 Copy_Row,u8 Copy_Col )
{
  if(0==Copy_Row)	
  {
	LCD_VidSendCommand(128+Copy_Col);
  }	
   else if(1==Copy_Row)	
  {
	LCD_VidSendCommand(128+Copy_Col+64);
  }	
  else
  {
	//DO NOTHING
  }	

}

void LCD_VidInt(void)
{
DIO_VidSetPortDirection(2,0b11111111);
DIO_VidSetPinDirection(0,0,1);
DIO_VidSetPinDirection(0,1,1);
DIO_VidSetPinDirection(0,2,1);

_delay_ms(40);
LCD_VidSendCommand(0b00111000);

_delay_ms(1);
LCD_VidSendCommand(0b00001111);

_delay_ms(1);
LCD_VidSendCommand(0b00000001);

_delay_ms(2);
LCD_VidSendCommand(0b00000001);//0b00000011 for Arabic and 0b00000001 for english
}

void LCD_WriteToCGRAM(u8 word[][7]){
	u8 step=1;
	for(int i=0;i<=(sizeof(word))/7;i++){
		LCD_VidSendCommand(64+step*i);
		for(int j=0;j<7;j++){
			LCD_VidSendData(word[i][j]);
		}
		LCD_VidSendCommand(128+step*i);
		LCD_VidSendData(0+step*i);
	}

}

void LCD_SendString(u8 string[]){
	u8 i=0;
	while(string[i]!='\n'){
		LCD_VidSendData(string[i]);
		i++;
	}
}










