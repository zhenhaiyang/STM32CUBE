/**
  ******************************************************************************
  * @file    sys.h
  * @author  zhy
  * @version 1.0
  * @date    2021-01-22
  * @brief   系统初始化相关的头文件
  ******************************************************************************
  * @version 1.1
  * @date    2021-04-20
  * @brief   系统初始化相关的头文件
  *            更新了BitBand为volatile类型
  *            改变了BitBand中bit为pin
  ******************************************************************************
  * @version 1.2
  * @date    2021-05-19
  * @brief   系统初始化相关的头文件
  *             更新硬件宏定义的写法
  ******************************************************************************
  */

#ifndef _SYS_H
#define _SYS_H
#include <stdint.h>

/* 位带操作 */
typedef struct
{
    volatile unsigned int pin0 : 1;
    volatile unsigned int pin1 : 1;
    volatile unsigned int pin2 : 1;
    volatile unsigned int pin3 : 1;
    volatile unsigned int pin4 : 1;
    volatile unsigned int pin5 : 1;
    volatile unsigned int pin6 : 1;
    volatile unsigned int pin7 : 1;
    volatile unsigned int pin8 : 1;
    volatile unsigned int pin9 : 1;
    volatile unsigned int pin10 : 1;
    volatile unsigned int pin11 : 1;
    volatile unsigned int pin12 : 1;
    volatile unsigned int pin13 : 1;
    volatile unsigned int pin14 : 1;
    volatile unsigned int pin15 : 1;
    volatile unsigned int rsv : 16;

} BitBand __attribute__((bitband));

extern BitBand PAin;
extern BitBand PBin;
extern BitBand PCin;
extern BitBand PDin;
extern BitBand PEin;
extern BitBand PFin;
extern BitBand PGin;
extern BitBand PHin;
extern BitBand PIin;

extern BitBand PAout;
extern BitBand PBout;
extern BitBand PCout;
extern BitBand PDout;
extern BitBand PEout;
extern BitBand PFout;
extern BitBand PGout;
extern BitBand PHout;
extern BitBand PIout;

/* 硬件对应信息 */
#define set_led_0 PBout.pin1
#define set_led_1 PBout.pin0

#define get_key_wkup PAin.pin0
#define get_key_0 PHin.pin3
#define get_key_1 PHin.pin2
#define get_key_2 PCin.pin13

#endif
