/***************************************************************************************
 *	FileName					:	mian.c
 *	CopyRight					:	JockJo
 *	ModuleName				:	ElectronicDesign
 *
 *	CPU							:	STM32F107VC/LQFP100
 *	RTOS						:
 *
 *	Create Data					: 2017-8-10
 *	Author/Corportation			: JockJo
 *
 *	Abstract Description		:	
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *	1    1.0      2017-8-10    JockJo       
 *
 ***************************************************************************************/


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
//debug
#define BUG_DETECT_PRINT(a,has_bug,no_bug) { if(a) \
printf("%s",has_bug); \
else \
printf("%s",no_bug);}


/**************************************************************
*	Struct Define Section
**************************************************************/


/**************************************************************
*	Prototype Declare Section
**************************************************************/


/**************************************************************
*	Global Variable Declare Section
**************************************************************/


/**************************************************************
*	File Static Variable Define Section
**************************************************************/


/**************************************************************
*	Function Define Section
**************************************************************/

/**
 *  @name
 *	@description
 *	@param			
 *	@return		
 *  @notice
 */
 int main()
 {
	  Debug_config();
		Signal_Control_Init();
		while(1)
		{
				;
		}
 }
 

 
 #ifdef  DEBUG
/*******************************************************************************
* Function Name  : assert_failed
* Description    : Reports the name of the source file and the source line number
*                  where the assert_param error has occurred.
* Input          : - file: pointer to the source file name
*                  - line: assert_param error line source number
* Output         : None
* Return         : None
*******************************************************************************/
void assert_failed(u8* file, u32 line)
{
          /* User can add his own implementation to report the file name and line number,
             ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
        
          while (1)
          {}
}
#endif
