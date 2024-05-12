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

/* 使用STM32F10x的GPIO来控制LED的闪烁，主要使用到四个短小的函数完成功能-----------------------------------------------------------*/
void LED0_Init(void) {
  // 定义一个GPIO_InitTypeDef类型的结构体 C:\Users\22H2\Documents\Boards\Keil5\HM1\STM32F10x_FWLib\inc\stm32f10x_gpio.h
  GPIO_InitTypeDef GPIO_InitStructure;
  // 使能GPIOA的时钟，打开APB2总线时钟 C:\Users\22H2\Documents\Boards\Keil5\HM1\STM32F10x_FWLib\inc\stm32f10x_rcc.h
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  // 配置GPIOB的Pin8为推挽输出
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8; // Specifies the GPIO pins to be configured.
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // 推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; //  Specifies the speed for the selected pins.
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void LED0_ON(void) {
  GPIO_ResetBits(GPIOA, GPIO_Pin_8);
}

void LED0_OFF(void) {
  GPIO_SetBits(GPIOA, GPIO_Pin_8); // GPIOx: A,B,C,D,E,F,G; GPIO_Pin: Specifies the port bit to be written.
}

// __IO 作为一个宏（修饰），来告诉编译器后面这个变量是一个输入/输出变量
void Delay(__IO u32 nCount)
{
  unsigned long i;
  for (i = 0; i < nCount; i++)
    ; // 空循环（消耗时间）
}

int main(void) {
  LED0_Init();
  while(1) {
    LED0_ON();
    Delay(0x5FFFFF); 
    LED0_OFF();
    Delay(0x5FFFFF); 
  }
}

