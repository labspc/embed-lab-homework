/**
 ******************************************************************************
 * @file    Project/STM32F10x_StdPeriph_Template/main.c
 * @author  MCD Application Team
 * @version V3.6.0
 * @date    20-September-2021
 * @brief   Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2011 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

/* 使用STM32F10x的 按键KEY0 来控制LED的闪烁，在HM1的基础上继续完成功能-----------------------------------------------------------*/
void LED0_Init(void)
{
  // 定义一个GPIO_InitTypeDef类型的结构体 C:\Users\22H2\Documents\Boards\Keil5\HM1\STM32F10x_FWLib\inc\stm32f10x_gpio.h
  GPIO_InitTypeDef GPIO_InitStructure;
  // 使能GPIOA的时钟，打开APB2总线时钟 C:\Users\22H2\Documents\Boards\Keil5\HM1\STM32F10x_FWLib\inc\stm32f10x_rcc.h
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  // 配置GPIOB的Pin8为推挽输出
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;        // Specifies the GPIO pins to be configured.
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // 推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; //  Specifies the speed for the selected pins.
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void LED0_ON(void)
{
  GPIO_ResetBits(GPIOA, GPIO_Pin_8);
}

void LED0_OFF(void)
{
  GPIO_SetBits(GPIOA, GPIO_Pin_8); // GPIOx: A,B,C,D,E,F,G; GPIO_Pin: Specifies the port bit to be written.
}

// __IO 作为一个宏（修饰），来告诉编译器后面这个变量是一个输入/输出变量
void Delay(__IO u32 nCount)
{
  unsigned long i;
  for (i = 0; i < nCount; i++)
    ; // 空循环（消耗时间）
}

// 根据要求 KEY0 读取PC5
void KEY0_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;        // KEY0对应的引脚PC5
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // 输入上拉（上拉电阻）
  GPIO_Init(GPIOC, &GPIO_InitStructure);
}

int main(void)
{
  // 初始化LED0
  // 初始化按键KEY0
  LED0_Init();
  KEY0_Init();

  // 进入具有嵌入式特色的 while 无限循环
  while (1)
  {
    // Check the state of KEY0
    // Bit_RESET 作为一个宏定义，通常表示低电平（0）
    if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5) == Bit_RESET)
    { // If KEY0 is pressed
      LED0_ON();
    }
    else
    { // If KEY0 is released
      LED0_OFF();
    }
  }
}
