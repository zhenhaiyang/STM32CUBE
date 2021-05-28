/**
  ******************************************************************************
  * @file    sys.c
  * @author  zhy
  * @version 1.0
  * @date    2021-01-22
  * @brief   系统初始化相关，配置RCC时钟，中断分组
  ******************************************************************************
  * @version 1.1
  * @date    2021-04-14
  * @brief   改变位带的定义方法，提高程序的兼容性
  ******************************************************************************
  */
#include "sys.h"
#include "stm32f4xx.h"
#include "stdio.h"

/* 全局变量 */
BitBand PAin __attribute__((at((unsigned long)&(GPIOA->IDR))));
BitBand PBin __attribute__((at((unsigned long)&(GPIOB->IDR))));
BitBand PCin __attribute__((at((unsigned long)&(GPIOC->IDR))));
BitBand PDin __attribute__((at((unsigned long)&(GPIOD->IDR))));
BitBand PEin __attribute__((at((unsigned long)&(GPIOE->IDR))));
BitBand PFin __attribute__((at((unsigned long)&(GPIOF->IDR))));
BitBand PGin __attribute__((at((unsigned long)&(GPIOG->IDR))));
BitBand PHin __attribute__((at((unsigned long)&(GPIOH->IDR))));
BitBand PIin __attribute__((at((unsigned long)&(GPIOI->IDR))));

BitBand PAout __attribute__((at((unsigned long)&(GPIOA->ODR))));
BitBand PBout __attribute__((at((unsigned long)&(GPIOB->ODR))));
BitBand PCout __attribute__((at((unsigned long)&(GPIOC->ODR))));
BitBand PDout __attribute__((at((unsigned long)&(GPIOD->ODR))));
BitBand PEout __attribute__((at((unsigned long)&(GPIOE->ODR))));
BitBand PFout __attribute__((at((unsigned long)&(GPIOF->ODR))));
BitBand PGout __attribute__((at((unsigned long)&(GPIOG->ODR))));
BitBand PHout __attribute__((at((unsigned long)&(GPIOH->ODR))));
BitBand PIout __attribute__((at((unsigned long)&(GPIOI->ODR))));

/** 
 * @brief 重构函数 
 * @note 在printf中自动调用
 * @param {int} ch  发送的数据
 * @param {FILE} *f 此处用不到
 * @retval 当前发送值
 */
int fputc(int ch, FILE *f)
{
    while ((USART1->SR & USART_SR_TXE) == 0)
        ;                     //判断是否发送完成
    USART1->DR = (uint8_t)ch; //发送数据
    return ch;
}
