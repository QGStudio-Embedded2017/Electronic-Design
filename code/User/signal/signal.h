/***************************************************************************************
 *	File Name				: signal.h
 *	CopyRight				: JockJo
 *	ModuleName			:	signal
 *
 *	CPU						: STM32F107VC/LQFP100
 *	RTOS					:
 *
 *	Create Data				:	2017-8-11
 *	Author/Corportation		: JockJo
 *
 *	Abstract Description	:	
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *	1    1.0      2017-8-11    JockJo   
 *
 ***************************************************************************************/


/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef __SIGNAL_H
#define __SIGNAL_H


/**************************************************************
*	Debug switch Section
**************************************************************/


/**************************************************************
*	Include File Section
**************************************************************/
#include "stm32f10x.h"

/**************************************************************
*	Macro Define Section
**************************************************************/
#ifndef uchar
#define uchar unsigned char
#endif //uchar

#ifndef uint
#define uint unsigned int
#endif //uint

/**************************************************************
*	Struct Define Section
**************************************************************/
#ifndef LEDTYPE
#define LEDTYPE
typedef enum{
	LED1, LED2, LED3
}LED_Type;
#endif	//LEDTYPE

/**************************************************************
*	Prototype Declare Section
**************************************************************/
void Signal_Control_Init(void);
void Signal_HZ_Set(u16 period, u16 prescaler);
void Signal_PWM_Set(LED_Type LED, u16 PWM_Number);

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************Tpro************************/
#endif  //_SIGNAL_H
