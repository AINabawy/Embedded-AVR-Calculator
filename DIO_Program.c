#include"STD_Types.h"
#include"BIT_MATH.h"
#include"DIO_Register.h"

void DIO_VidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin ,u8 Copy_u8Dir){
	if( 1== Copy_u8Dir )
	{
		switch(Copy_u8Port)
		{
		case 0: SET_BIT(DDRA,Copy_u8Pin); break;
		case 1: SET_BIT(DDRB,Copy_u8Pin); break;
		case 2: SET_BIT(DDRC,Copy_u8Pin); break;
		case 3: SET_BIT(DDRD,Copy_u8Pin); break;
		}
	}
	else if (0==Copy_u8Dir)
	{
		switch(Copy_u8Port)
		{
		case 0: CLR_BIT(DDRA,Copy_u8Pin);    break;
		case 1: CLR_BIT(DDRB,Copy_u8Pin);    break;
		case 2: CLR_BIT(DDRC,Copy_u8Pin);    break;
		case 3: CLR_BIT(DDRD,Copy_u8Pin);    break;
		}

	}
	else
	{
		//DO NOTHING
	}

}

void DIO_VidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin ,u8 Copy_u8Value){
	if( 1== Copy_u8Value )
	{
		switch(Copy_u8Port)
		{
		case 0: SET_BIT(PORTA,Copy_u8Pin); break;
		case 1: SET_BIT(PORTB,Copy_u8Pin); break;
		case 2: SET_BIT(PORTC,Copy_u8Pin); break;
		case 3: SET_BIT(PORTD,Copy_u8Pin); break;
		}
	}
	else if (0==Copy_u8Value)
	{
		switch(Copy_u8Port)
		{
		case 0: CLR_BIT(PORTA,Copy_u8Pin);    break;
		case 1: CLR_BIT(PORTB,Copy_u8Pin);    break;
		case 2: CLR_BIT(PORTC,Copy_u8Pin);    break;
		case 3: CLR_BIT(PORTD,Copy_u8Pin);    break;
		}

	}
	else
	{
		//DO NOTHING
	}


}

void DIO_VidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Dir)
{
	switch(Copy_u8Port)
	{
	case 0: DDRA=Copy_u8Dir;     break;
	case 1: DDRB=Copy_u8Dir;     break;
	case 2: DDRC=Copy_u8Dir;     break;
	case 3: DDRD=Copy_u8Dir;     break;
	}
}	

void DIO_VidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
	case 0: PORTA=Copy_u8Value;     break;
	case 1: PORTB=Copy_u8Value;     break;
	case 2: PORTC=Copy_u8Value;     break;
	case 3: PORTD=Copy_u8Value;     break;
	}
}	

u8 DIO_U8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin)  
{
	u8 ret_value;
	switch(Copy_u8Port)
	{
	case 0: ret_value=GET_BIT(PINA,Copy_u8Pin); break;
	case 1: ret_value=GET_BIT(PINB,Copy_u8Pin); break;
	case 2: ret_value=GET_BIT(PINC,Copy_u8Pin); break;
	case 3: ret_value=GET_BIT(PIND,Copy_u8Pin); break;
	}
	return ret_value;

}


void DIO_VidTogglePinValue(u8 Copy_u8Port,u8 Copy_u8Pin)
{

	switch(Copy_u8Port)
	{
	case 0:TOG_BIT(PORTA,Copy_u8Pin); break;
	case 1:TOG_BIT(PORTB,Copy_u8Pin); break;
	case 2:TOG_BIT(PORTC,Copy_u8Pin); break;
	case 3:TOG_BIT(PORTD,Copy_u8Pin); break;
	}
}
