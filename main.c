/*
 * main.c
 *
 *  Created on: Mar 12, 2021
 *      Author: user
 */
#include "STD_TYPES.h"

#include "Keybad_Interface.h"

#include "DIO_Interface.h"


void  main (void )
{
	LCD_VidInt();
	Key_VidInit();
	DIO_VidSetPinDirection(3,0,1);
	s32 x=0,y=0,Ans;
	u8 input,n,flag=0,flag2=1,yflag=0,xflag=0,operation=0,xSignFlag=0,ySignFlag=0,errorFlag=0;
	s8 counter=-1;

	while (1)
	{
		input=Key_U8GetPressedKey();
		if(input!=100){
			counter++;
			if(input==15){
				if(xSignFlag==1){
					x=x*-1;
				}
				if(ySignFlag==1){
					y=y*-1;
				}
				if(((flag==1)&&(xflag==0)&&(counter>0))||((flag==1)&&(yflag==0))||(errorFlag==1)||((xflag==0)&&(counter!=0))){
					LCD_VidSetPosition(1,0);
					LCD_VidSendData('!');
					LCD_VidSendData('!');
					LCD_VidSendData('e');
					LCD_VidSendData('r');
					LCD_VidSendData('r');
					LCD_VidSendData('o');
					LCD_VidSendData('r');
					LCD_VidSendData('!');
					LCD_VidSendData('!');
					continue;
				}
				flag2=0;
				if(counter==0){
					xflag=1;
					LCD_VidSendData('A');
					LCD_VidSendData('n');
					LCD_VidSendData('s');
					continue;
				}
				switch(operation){
					case 13:
						Ans=x+y;	break;
					case 14:
						Ans=x-y;	break;
					case 7:
						Ans=x*y;	break;
					case 11:
						Ans=x/y;	break;
					case 0:
						Ans=x;	break;

				}
				LCD_VidSetPosition(1,0);
				LCD_VidSendData(0b00111101);
				LCD_VidSendNumber(Ans);
			}
			else if(input==3){
				LCD_VidInt();
				x=Ans;
				y=0;
				flag=0;
				counter=-1;
				flag2=1;
				yflag=0;
				xflag=0;
				xSignFlag=0;
				ySignFlag=0;
				operation=0;
				errorFlag=0;
			}
			else if((input==13)||(input==7)||(input==11)||(input==14)){
				if(((input==7)||(input==11))&&(flag==1)){
					errorFlag=1;
				}
				switch(input){
					case 13:
						LCD_VidSendData(0b00101011);
						if(counter==0){
							ySignFlag=1;
							continue;
						}
						else if((yflag==0)&&(flag==1)){
							continue;
						}								break;
					case 14:
						LCD_VidSendData(0b00101101);
						if(counter==0){
							xSignFlag=1;
							continue;
						}
						else if((yflag==0)&&(flag==1)){
							ySignFlag=1;
							continue;
						}								break;
					case 7:
						LCD_VidSendData(0b00101010);	break;
					case 11:
						LCD_VidSendData(0b00101111);	break;
				}
				DIO_VidTogglePinValue(3,0);
				operation=input;
				flag=1;
			}
			else{
				n=input;
				switch(input){
					case 12:
						n=0;	break;
					case 0:case 1:case 2:
						n=input+1;	break;
					case 8:case 9:case 10:
						n=input-1;	break;

				}
				LCD_VidSendNumber((s32)n);
				if(flag==0){
					xflag=1;
					if((counter==0)||(((xSignFlag==1)||(ySignFlag==1))&&counter==1)){
						x=0;
					}
					x=x*10+n;
				}
				else{
					yflag=1;
					y=y*10+n;
				}

			}
		}
	}

}
