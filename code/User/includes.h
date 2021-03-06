/***************************************************************************************
 *	File Name				: includes.h
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
#ifndef __INCLUDES_H
#define __INCLUDES_H


/**************************************************************
*	Debug switch Section
**************************************************************/


/**************************************************************
*	Include File Section
**************************************************************/
#include "stm32f10x.h"
#include "debug.h"
#include "signal.h"


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

/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************Tpro************************/
#endif  //_INCLUDES_H
