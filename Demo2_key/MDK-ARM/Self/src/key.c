/**
  ******************************************************************************
  * @file    key.c
  * @author  zhy
  * @version 1.0
  * @date    2021-05-18
  * @brief   按键处理程序
  ******************************************************************************
  */

#include "sys.h"
#include "key.h"

//{
/*-----------------------------------私有域:开始--------------------------------------*/

uint8_t edgeActive = 0;  //有效边沿
uint8_t levelActive = 0; //有效电平

/*-----------------------------------私有域:结束--------------------------------------*/
//}

void KeyScan(void)
{
    static uint8_t edge = 0;                                                             //触发边缘
    static uint8_t level = 0;                                                            //有效电平
    uint8_t key = get_key_0 | (get_key_1 << 1) | (get_key_2 << 2) | (get_key_wkup << 3); //用后四位作为处理
    key ^= 0x07;                                                                         //将常高的按键置反，取下降沿
    edgeActive = edge & key;                                                             //上一次为有效触发，且当前还是有效电平
    levelActive = level & key;                                                           //上一次为有效电平，且当前还是有效电平
    edge = key & (key ^ level);                                                          //键值发生变化，且当前位有效电平
    level = key;                                                                         //保留上一次有效电平
}

uint8_t KeyGetLevelActive(void)
{
    return levelActive;
}

uint8_t KeyGetEdgeActive(void)
{
    return edgeActive;
}

void KeyResetEdge(void)
{
    edgeActive = 0;
}
