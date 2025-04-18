#ifndef _DIO_Interface_H_
#define _DIO_Interface_H_

void DIO_VidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin ,u8 Copy_u8Dir) ;


void DIO_VidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin ,u8 Copy_u8Value) ;


void DIO_VidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Dir)  ;


void DIO_VidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value)  ;


u8 DIO_U8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin)  ;


void DIO_VidTogglePinValue(u8 Copy_u8Port,u8 Copy_u8Pin)  ;


#endif