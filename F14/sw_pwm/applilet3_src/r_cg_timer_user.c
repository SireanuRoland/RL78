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
* File Name    : r_cg_timer_user.c
* Version      : Applilet3 for RL78/F14 V2.02.00.03 [07 Aug 2014]
* Device(s)    : R5F10PMG
* Tool-Chain   : IAR Systems iccrl78
* Description  : This file implements device driver for TAU module.
* Creation Date: 21.11.2014
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_timer.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */

volatile uint8_t currentTable = 0;
volatile uint8_t workTable = 1;

__near const uint16_t bufferReferences[2][SW_NUM_PORTS] = {

  { 
    (uint16_t) &Port9Table0,
    (uint16_t) &Port8Table0,
    (uint16_t) &Port7Table0,
    (uint16_t) &Port6Table0,
    (uint16_t) &Port5Table0 
  },
  {
    (uint16_t) &Port9Table1,
    (uint16_t) &Port8Table1,
    (uint16_t) &Port7Table1,
    (uint16_t) &Port6Table1,
    (uint16_t) &Port5Table1   
  }
};

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_tmr_rj0_interrupt
* Description  : This function is INTTRJ0 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma bank = 3
#pragma vector = INTTRJ0_vect
__interrupt static void r_tmr_rj0_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
  // just for debug, toggle a pin
  P13_bit.no0 = 1U;
  
  if (switchTable) {
  
    if (0 == currentTable) { 
      currentTable = 1;
      workTable = 0;
    }
    else { 
      currentTable = 0;
      workTable = 1;
    };
    
   switchTable = 0;   
  }
 
  // setup table 1 as next transfer chain
  dtc_controldata_0.dtsar = bufferReferences[currentTable][0];
  dtc_controldata_1.dtsar = bufferReferences[currentTable][1];
  dtc_controldata_2.dtsar = bufferReferences[currentTable][2];
  dtc_controldata_3.dtsar = bufferReferences[currentTable][3];
  dtc_controldata_4.dtsar = bufferReferences[currentTable][4];

  // can skip this since it is already at zero
  /*
  dtc_controldata_0.dtcct = 0;
  dtc_controldata_1.dtcct = 0;
  dtc_controldata_2.dtcct = 0;
  dtc_controldata_3.dtcct = 0;
  dtc_controldata_4.dtcct = 0;
  */
  
  // enable DTC again
  DTCEN4 |= _20_DTC_TMRJ0_ACTIVATION_ENABLE;
  
  // just for debug, toggle back
  P13_bit.no0 = 0U;
  
  /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
