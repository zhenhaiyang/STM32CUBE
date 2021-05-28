/**
  ******************************************************************************
  * @file    dma.c
  * @author  zhy
  * @version 1.0
  * @date    2021-05-27
  * @brief   dma的配置文件
  ******************************************************************************
  */

#include "dma.h"
#include "stm32f4xx_hal.h"

/** 
 * @brief DMA
 * @note 无
 * @param {uint32_t} memory 内存的地址
 * @param {uint32_t} length 发送数据的长度
 * @retval 无
 */
void DmaStart(uint32_t memory, uint32_t length)
{
    DMA2_Stream7->M0AR = memory;
    DMA2_Stream7->NDTR = length;
    DMA2_Stream7->CR |= DMA_SxCR_EN;
}

void DmaLinkUsart1Tx(void)
{
    DMA2_Stream7->PAR = (uint32_t) & (USART1->DR); //外设地址写入
    USART1->CR3 |= USART_CR3_DMAT;                 //使能外设DMA
}
