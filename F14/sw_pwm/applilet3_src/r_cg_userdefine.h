/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIESREGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2012, 2014 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_userdefine.h
* Version      : Applilet3 for RL78/F14 V2.02.00.03 [07 Aug 2014]
* Device(s)    : R5F10PMG
* Tool-Chain   : IAR Systems iccrl78
* Description  : This file includes user definition.
* Creation Date: 21.11.2014
***********************************************************************************************************************/

#ifndef _USER_DEF_H
#define _USER_DEF_H

/***********************************************************************************************************************
User definitions
***********************************************************************************************************************/

/* Start user code for function. Do not edit comment generated here */
#include "r_cg_dtc.h"

extern __no_init st_dtc_data dtc_controldata_0;
extern __no_init st_dtc_data dtc_controldata_1;
extern __no_init st_dtc_data dtc_controldata_2;
extern __no_init st_dtc_data dtc_controldata_3;
extern __no_init st_dtc_data dtc_controldata_4;


#define PORT9_address   0xFFF09
#define PORT8_address   0xFFF08
#define PORT7_address   0xFFF07
#define PORT6_address   0xFFF06
#define PORT5_address   0xFFF05

#define PORT9_Mask      0xFF // complete port
#define PORT8_Mask      0xFE // bit 0 not available
#define PORT7_Mask      0xFF // complete port
#define PORT6_Mask      0xB0 // bit 7-5-4 not available
#define PORT5_Mask      0xF0 // bit 7-6-5-4 not available

#define NUM_PWM_STEPS   256

typedef enum PORT_t {
  
    SW_PORT_9 = ((24 << 8) | (0 << 4)),
    SW_PORT_8 = ((17 << 8) | (1 << 4)),
    SW_PORT_7 = ((9 << 8)  | (2 << 4)),
    SW_PORT_6 = ((4 << 8)  | (3 << 4)),
    SW_PORT_5 = ((0 << 8)  | (4 << 4))
    
} PORT_t;

#define SW_NUM_PORTS 5

typedef enum SW_PWM_t {
      
  SW_PWM0 = (0 | SW_PORT_5),
  SW_PWM1 = (1 | SW_PORT_5),
  SW_PWM2 = (2 | SW_PORT_5),
  SW_PWM3 = (3 | SW_PORT_5),
  
  SW_PWM4 = (0 | SW_PORT_6),
  SW_PWM5 = (1 | SW_PORT_6),
  SW_PWM6 = (2 | SW_PORT_6),
  SW_PWM7 = (3 | SW_PORT_6),
  SW_PWM8 = (6 | SW_PORT_6),

  SW_PWM9 =  (0 | SW_PORT_7),
  SW_PWM10 = (1 | SW_PORT_7),
  SW_PWM11 = (2 | SW_PORT_7),
  SW_PWM12 = (3 | SW_PORT_7),
  SW_PWM13 = (4 | SW_PORT_7),
  SW_PWM14 = (5 | SW_PORT_7),
  SW_PWM15 = (6 | SW_PORT_7),
  SW_PWM16 = (7 | SW_PORT_7),

  SW_PWM17 = (1 | SW_PORT_8),
  SW_PWM18 = (2 | SW_PORT_8),
  SW_PWM19 = (3 | SW_PORT_8),
  SW_PWM20 = (4 | SW_PORT_8),
  SW_PWM21 = (5 | SW_PORT_8),
  SW_PWM22 = (6 | SW_PORT_8),
  SW_PWM23 = (7 | SW_PORT_8),

  SW_PWM24 = (0 | SW_PORT_9),
  SW_PWM25 = (1 | SW_PORT_9),
  SW_PWM26 = (2 | SW_PORT_9),
  SW_PWM27 = (3 | SW_PORT_9),
  SW_PWM28 = (4 | SW_PORT_9),
  SW_PWM29 = (5 | SW_PORT_9),
  SW_PWM30 = (6 | SW_PORT_9),
  SW_PWM31 = (7 | SW_PORT_9),
    
} SW_PWM;



#define NUM_SW_PWM 32



typedef struct
{
    unsigned char SW_PWM0:1;
    unsigned char SW_PWM1:1;
    unsigned char SW_PWM2:1;
    unsigned char SW_PWM3:1;
    const unsigned char reserved4:1;
    const unsigned char reserved5:1;
    const unsigned char reserved6:1;
    const unsigned char reserved7:1;

} PORT5_SW_PWM;

typedef struct
{
    unsigned char SW_PWM4:1;
    unsigned char SW_PWM5:1;
    unsigned char SW_PWM6:1;
    unsigned char SW_PWM7:1;
    const unsigned char reserved8:1;
    const unsigned char reserved9:1;
    unsigned char SW_PWM8:1;
    const unsigned char reserved10:1;

} PORT6_SW_PWM;

typedef struct
{
    unsigned char SW_PWM9:1;
    unsigned char SW_PWM10:1;
    unsigned char SW_PWM11:1;
    unsigned char SW_PWM12:1;
    unsigned char SW_PWM13:1;
    unsigned char SW_PWM14:1;
    unsigned char SW_PWM15:1;
    unsigned char SW_PWM16:1;

} PORT7_SW_PWM;

typedef struct
{
    const unsigned char reserved11:1;
    unsigned char SW_PWM17:1;
    unsigned char SW_PWM18:1;
    unsigned char SW_PWM19:1;
    unsigned char SW_PWM20:1;
    unsigned char SW_PWM21:1;
    unsigned char SW_PWM22:1;
    unsigned char SW_PWM23:1;

} PORT8_SW_PWM;

typedef struct
{
    unsigned char SW_PWM24:1;
    unsigned char SW_PWM25:1;
    unsigned char SW_PWM26:1;
    unsigned char SW_PWM27:1;
    unsigned char SW_PWM28:1;
    unsigned char SW_PWM29:1;
    unsigned char SW_PWM30:1;
    unsigned char SW_PWM31:1;

} PORT9_SW_PWM;


extern PORT9_SW_PWM Port9Table1[NUM_PWM_STEPS];
extern PORT9_SW_PWM Port9Table0[NUM_PWM_STEPS];
extern PORT8_SW_PWM Port8Table1[NUM_PWM_STEPS];
extern PORT8_SW_PWM Port8Table0[NUM_PWM_STEPS];
extern PORT7_SW_PWM Port7Table1[NUM_PWM_STEPS];
extern PORT7_SW_PWM Port7Table0[NUM_PWM_STEPS];
extern PORT6_SW_PWM Port6Table1[NUM_PWM_STEPS];
extern PORT6_SW_PWM Port6Table0[NUM_PWM_STEPS];
extern PORT5_SW_PWM Port5Table1[NUM_PWM_STEPS];
extern PORT5_SW_PWM Port5Table0[NUM_PWM_STEPS];

// command to switch table
extern volatile uint8_t switchTable;

extern volatile uint8_t workTable;
extern volatile uint8_t currentTable;

/* __near is important to get the constants mirrored in RAM address space */
extern __near const uint16_t bufferReferences[2][SW_NUM_PORTS];

extern uint8_t pwmLevels[NUM_SW_PWM];
extern __near const SW_PWM pwmNumLevelIndex[NUM_SW_PWM];

extern volatile uint8_t pwmStep;

/* End user code. Do not edit comment generated here */
#endif
