/***************************************************************************************
 *	File Name				: debug.h
 *	CopyRight				: JockJo
 *	ModuleName			:	ElectronicDesign
 *
 *	CPU						: STM32F107VC/LQFP100
 *	RTOS					:
 *
 *	Create Data				:	2017-8-10
 *	Author/Corportation		: JockJo
 *
 *	Abstract Description	:	
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *	1    1.0      2017-8-10    JockJo   
 *
 ***************************************************************************************/


/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef __DEBUG_H
#define __DEBUG_H


/**************************************************************
*	Debug switch Section
**************************************************************/


/**************************************************************
*	Include File Section
**************************************************************/
#include "includes.h"

/**************************************************************
*	Macro Define Section
**************************************************************/
#ifndef uchar
#define uchar unsigned char
#endif //uchar

#ifndef uint
#define uint unsigned int
#endif //uint

#ifndef DEBUG_FUC
#define DEBUG_FUC		\
	 USART_SendData(USART1, 'A');
#endif		//DEBUG_FUC
/**************************************************************
*	Struct Define Section
**************************************************************/

/**************************************************************
*	Prototype Declare Section
**************************************************************/
void Debug_config(void);

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************Tpro************************/
#endif  //_DEBUG_H
