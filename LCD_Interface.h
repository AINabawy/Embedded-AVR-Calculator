#ifndef _LCD_Interface_H_
#define _LCD_Interface_H_

void LCD_VidSendData(u8 Copy_u8Data) ;


void LCD_VidSendCommand(u8 Copy_u8Data) ;

void LCD_VidSendNumber(s32 Copy_S32Number) ;

void LCD_VidInt(void) ;

void LCD_WriteToCGRAM(u8 word[4][7]);

void LCD_SendString(u8 string[]);

#endif
