/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"
/* Macros --------------------------------------------------------------------*/
#define LED_PIN GPIO_Pin_8
#define LED_PORT GPIOA
#define LED_CLOCK RCC_APB2Periph_GPIOA

#define BASIC_TIM TIM2
#define BASIC_TIM_APBxClock_FUN RCC_APB1PeriphClockCmd
#define BASIC_TIM_CLK RCC_APB1Periph_TIM2

/* 定时器设置公式 -------------------------------------------------------------------
x=1ms，即timer=1000  T*TCLK=x*(PSC+1)*(ARR+1)  PSC=72T-1
T=1.17s  ARR=1000-1  PSC=72*100*1.17-1
在这之中省略了一个x，且其默认为1000ms，为什么？
*/

// 自定义延时(单位：s)
#define DELAY 1.17

#define TIM_ARR_VALUE 1000 - 1             // 设定自动重载寄存器的值
#define TIM_PSC_VALUE (72 * 100 * DELAY) - 1 // 设定预分频系数

/* LED0 初始化模板（可复用） -------------------------------------------------------------------*/
void LED_Init(void)
{
  // Define a structure of type GPIO_InitTypeDef.
  GPIO_InitTypeDef GPIO_InitStructure;

  // Enable the clock for GPIOA by opening the APB2 bus clock.
  RCC_APB2PeriphClockCmd(LED_CLOCK, ENABLE);

  // Configure Pin8 of GPIOB as push-pull output.
  GPIO_InitStructure.GPIO_Pin = LED_PIN;           // Specifies the GPIO pins to be configured.
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // Push-pull output.
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; // Specifies the speed for the selected pins.
  GPIO_Init(LED_PORT, &GPIO_InitStructure);
}
void LED0_ON(void)
{
  GPIO_ResetBits(LED_PORT, LED_PIN);
}
void LED0_OFF(void)
{
  GPIO_SetBits(LED_PORT, LED_PIN); // GPIOx: A,B,C,D,E,F,G; GPIO_Pin: Specifies the port bit to be written.
}

/* 使用轮询（Polling）的 TIM2 精准控制 LED 的闪烁（可复用）-----------------------------------------------------------*/
/**
 * @file main.c
 * @brief Configure TIM2
 * @return None
 */
void BASIC_TIM_Config(void)
{
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

  // 开启定时器时钟TCLK=72M,即内部时钟CK_INT=72M
  // 库函数中 APB1预分频的系数是2，即 PCLK1=36M，所以定时器时钟 TIMxCLK=36*2=72M
  BASIC_TIM_APBxClock_FUN(BASIC_TIM_CLK, ENABLE);

  // 自动重装载寄存器周的值(计数值)
  // 累计TIM_Period个频率后产生一个更新或者中断
  TIM_TimeBaseStructure.TIM_Period = TIM_ARR_VALUE;

  // 定时器的定时时间等于计数器的中断周期乘以中断的次数
  TIM_TimeBaseStructure.TIM_Prescaler = TIM_PSC_VALUE;

  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

  // 初始化定时器
  TIM_TimeBaseInit(BASIC_TIM, &TIM_TimeBaseStructure);

  // 清除计数器中断标志位
  TIM_ClearFlag(BASIC_TIM, TIM_FLAG_Update);

  // 使能计数器
  TIM_Cmd(BASIC_TIM, ENABLE);
  // 等待计数器更新
  while (TIM_GetFlagStatus(BASIC_TIM, TIM_FLAG_Update) == RESET);
}
int main(void)
{
  LED_Init();

  while (1)
  {
    LED0_ON();
    BASIC_TIM_Config();
    LED0_OFF();
    BASIC_TIM_Config();
  }
}
