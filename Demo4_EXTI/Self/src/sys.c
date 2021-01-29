/**
  ******************************************************************************
  * @file    sys.c
  * @author  zhy
  * @version 1.0
  * @date    2021-01-22
  * @brief   系统初始化相关，配置RCC时钟，中断分组
  ******************************************************************************
  */
#include "sys.h"
#include "stm32f4xx.h"

/* 全局变量 */
BitBand PAin __attribute__((at(GPIOA_BASE + 16)));
BitBand PBin __attribute__((at(GPIOB_BASE + 16)));
BitBand PCin __attribute__((at(GPIOC_BASE + 16)));
BitBand PDin __attribute__((at(GPIOD_BASE + 16)));
BitBand PEin __attribute__((at(GPIOE_BASE + 16)));
BitBand PFin __attribute__((at(GPIOF_BASE + 16)));
BitBand PGin __attribute__((at(GPIOG_BASE + 16)));
BitBand PHin __attribute__((at(GPIOH_BASE + 16)));
BitBand PIin __attribute__((at(GPIOI_BASE + 16)));


BitBand PAout __attribute__((at(GPIOA_BASE + 20)));
BitBand PBout __attribute__((at(GPIOB_BASE + 20)));
BitBand PCout __attribute__((at(GPIOC_BASE + 20)));
BitBand PDout __attribute__((at(GPIOD_BASE + 20)));
BitBand PEout __attribute__((at(GPIOE_BASE + 20)));
BitBand PFout __attribute__((at(GPIOF_BASE + 20)));
BitBand PGout __attribute__((at(GPIOG_BASE + 20)));
BitBand PHout __attribute__((at(GPIOH_BASE + 20)));
BitBand PIout __attribute__((at(GPIOI_BASE + 20)));



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


