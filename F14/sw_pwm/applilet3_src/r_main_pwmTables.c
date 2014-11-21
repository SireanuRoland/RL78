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
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_port.h"
#include "r_cg_intc.h"
#include "r_cg_adc.h"
#include "r_cg_timer.h"
#include "r_cg_dtc.h"

#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/

uint8_t pwmLevels[NUM_SW_PWM];

__near const SW_PWM pwmNumLevelIndex[NUM_SW_PWM] = {

  SW_PWM0,
  SW_PWM1, 
  SW_PWM2,
  SW_PWM3, 
  SW_PWM4,
  SW_PWM5, 
  SW_PWM6, 
  SW_PWM7, 
  SW_PWM8, 
  SW_PWM9, 
  SW_PWM10, 
  SW_PWM11, 
  SW_PWM12, 
  SW_PWM13, 
  SW_PWM14, 
  SW_PWM15, 
  SW_PWM16, 
  SW_PWM17, 
  SW_PWM18, 
  SW_PWM19, 
  SW_PWM20, 
  SW_PWM21, 
  SW_PWM22, 
  SW_PWM23, 
  SW_PWM24, 
  SW_PWM25, 
  SW_PWM26, 
  SW_PWM27, 
  SW_PWM28,
  SW_PWM29, 
  SW_PWM30,
  SW_PWM31 

};

PORT9_SW_PWM Port9Table1[NUM_PWM_STEPS] = {
  
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask) 
  
};

PORT9_SW_PWM Port9Table0[NUM_PWM_STEPS] = {
  
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),
  (0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask),(0x0 & PORT9_Mask)  
  
};

PORT8_SW_PWM Port8Table1[NUM_PWM_STEPS] = {
  
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask)  
};

PORT8_SW_PWM Port8Table0[NUM_PWM_STEPS] = {
  
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),
  (0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask),(0x0 & PORT8_Mask)  
};

PORT7_SW_PWM Port7Table0[NUM_PWM_STEPS] = {
  
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask) 
};

PORT7_SW_PWM Port7Table1[NUM_PWM_STEPS] = {
  
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),
  (0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask),(0x0 & PORT7_Mask)  
};

PORT6_SW_PWM Port6Table0[NUM_PWM_STEPS] = {
  
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask)  
};

PORT6_SW_PWM Port6Table1[NUM_PWM_STEPS] = {
  
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),
  (0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask),(0x0 & PORT6_Mask)  
};

PORT5_SW_PWM Port5Table0[NUM_PWM_STEPS] = {
  
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask)  
};

PORT5_SW_PWM Port5Table1[NUM_PWM_STEPS] = {
  
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),
  (0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask),(0x0 & PORT5_Mask) 
};




