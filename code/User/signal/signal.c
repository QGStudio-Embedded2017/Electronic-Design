/***************************************************************************************
 *	FileName					: signal.c
 *	CopyRight					: JockJo
 *	ModuleName				: signal	
 *
 *	CPU							:	STM32F107VC/LQFP64
 *	RTOS						:
 *
 *	Create Data					: 2017-8-11	
 *	Author/Corportation			:	JockJo
 *
 *	Abstract Description		:	signal
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *	1		1.0     2017-8-11    JockJo
 *
 ***************************************************************************************/


/**************************************************************
*	Debug switch Section
**************************************************************/


/**************************************************************
*	Include File Section
**************************************************************/
#include "includes.h"
#include "signal.h"
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

/***TIM3 Init********/
static void TIM3_GPIO_Config(void);
static void TIM3_Mode_Config(void);

/**************************************************************
*	Global Variable Declare Section
**************************************************************/
//三个LED灯高电平PWM设置
u16 LED1_PWM = 5000;		//50%
u16 LED2_PWM = 3000;		//30%
u16 LED3_PWM = 7000;		//70%

//定时器的计数周期、预分频定义
//计算公式 定时周期 = 1/(72MHz*(PRESCALER+1))*(PERIOD+1)
//此处10ms一个周期，10KHz
u16 TIM3_Period = 10000;
u16 TIM3_Prescaler = 71;

/**************************************************************
*	File Static Variable Define Section
**************************************************************/


/**************************************************************
*	Function Define Section
**************************************************************/

void Signal_Control_Init(void)
{
	TIM3_GPIO_Config();
	TIM3_Mode_Config();
	
}


/**
 *  @name	     Signal_PWM_Set
 *	@description   LED发送信号
 *	@param			none
 *	@return		  none
 *  @notice
 */
void Signal_PWM_Set(LED_Type LED, u16 PWM_Number)
{
		TIM_Cmd(TIM3,DISABLE);
		if(LED == LED1)
		{
				LED1_PWM = PWM_Number;
		}
		else if(LED == LED2)
		{
				LED2_PWM = PWM_Number;
		}
		else if(LED == LED3)
		{
				LED3_PWM = PWM_Number;
		}
		TIM_Cmd(TIM3,ENABLE);
}

/**
 *  @name	     Signal_Hz_Set
 *	@description   LED发送频率设置
 *	@param			none
 *	@return		  none
 *  @notice     计算公式 定时周期 = 1/(72MHz*(PRESCALER+1))*(PERIOD+1)
 *			        默认10ms一个周期，10KHz
 *
 */
void Signal_HZ_Set(u16 period, u16 prescaler)
{
		TIM_Cmd(TIM3,DISABLE);		
		TIM3_Period = period;
		TIM3_Prescaler = prescaler;
		TIM_Cmd(TIM3,ENABLE);
}


/**
 *  @name	     TIM3_GPIO_Config
 *	@description   init PA6\PB0\PB1
 *	@param			none
 *	@return		  none
 *  @notice
 */
static void TIM3_GPIO_Config(void)
{
	/*定义一个GPIO_InitTypeDef类型的结构体*/
	GPIO_InitTypeDef GPIO_InitStructure;

  /*设置TIM1CLK为72MHZ*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); 
	
	/*开启GPIOB的时钟使能*/
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA, ENABLE);

	/*部分映射,将TIM3_CHN3映射到PB0,TIM3_CHN4映射到PB1*/
	//GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3,ENABLE);
	
  /*选择要控制的GPIOB引脚，TIM3_CHN3对应PB0,TIM3_CHN4对应PB1*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;
	
	/*设置引脚模式为复用推挽输出*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	
	/*设置引脚速率为50MHz*/
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	
	/*调用库函数,初始化GPIOB*/
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	/*选择要控制的GPIOB引脚，TIM3_CHN1对应PA6*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	
	/*调用库函数,初始化GPIOB*/
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/*使能引脚初始化为1*/
	//GPIO_SetBits(GPIOB, GPIO_Pin_0|GPIO_Pin_1);
	//GPIO_SetBits(GPIOA, GPIO_Pin_6);
}


/**
 *  @name	     TIM3_Mode_Config
 *	@description   
 *	@param			none
 *	@return		  none
 *  @notice
 */
static void TIM3_Mode_Config(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	/*PWM信号电平跳变值*/
 	u16 CCR1_Val = LED1_PWM;        
 	u16 CCR3_Val = LED2_PWM;
	u16 CCR4_Val = LED3_PWM;
	
/* ----------------------------------------------------------------------- 
    TIM3 Channel1 duty cycle = (TIM3_CCR1/ TIM3_ARR+1)* 100% 
		TIM3 Channel3 duty cycle = (TIM3_CCR3/ TIM3_ARR+1)* 100% 
    TIM3 Channel4 duty cycle = (TIM3_CCR4/ TIM3_ARR+1)* 100%
  ----------------------------------------------------------------------- */
	

	/*Time base configuration*/
	TIM_TimeBaseStructure.TIM_Period = TIM3_Period;						//1000次为一个定时周期
	TIM_TimeBaseStructure.TIM_Prescaler = TIM3_Prescaler;			//预分频系数，不预分频，1MHZ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;	//时钟分配系数，不分频
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//向上计数
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	
	/*PWM1 Mode configuration:Channel1*/
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;		//设置为PWM模式1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;			
  TIM_OCInitStructure.TIM_Pulse = CCR1_Val;	   //设置跳变值
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //小于CCR1_Val为高电平
  TIM_OC1Init(TIM3, &TIM_OCInitStructure);	 //使能通道1
  TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	/*PWM1 Mode configuration:Channel3*/
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;		//设置为PWM模式1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;			
  TIM_OCInitStructure.TIM_Pulse = CCR3_Val;	   //设置跳变值
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //小于CCR3_Val为高电平
  TIM_OC3Init(TIM3, &TIM_OCInitStructure);	 //使能通道3
  TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	/*PWM1 Mode configuration:Channel4*/
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;			
  TIM_OCInitStructure.TIM_Pulse = CCR4_Val;	   //设置跳变值
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //小于CCR4_Val时为高电平
  TIM_OC4Init(TIM3, &TIM_OCInitStructure);	 //使能通道4
  TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);	
	TIM_ARRPreloadConfig(TIM3, ENABLE);			//使能TIM3重载寄存器ARR
	
	//开启中断
	TIM_ClearFlag(TIM3, TIM_FLAG_Update);
  TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
		
	/*TIM3 enable counter*/
	TIM_Cmd(TIM3,ENABLE);
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
