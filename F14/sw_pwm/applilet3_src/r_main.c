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
* File Name    : r_main.c
* Version      : Applilet3 for RL78/F14 V2.02.00.03 [07 Aug 2014]
* Device(s)    : R5F10PMG
* Tool-Chain   : IAR Systems iccrl78
* Description  : This file implements main function.
* Creation Date: 21.11.2014
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
/* Start user code for include. Do not edit comment generated here */

/***********************************************************************************************************************
Project setup:

TAU and TDR are configured for 400,641026 HZ - 2.496 msec PWM period 
-> counter running @ 16MHz, value at 39936 - 1 = 0x9BFF 

TRJ is configured for 10.2564,23 Hz, fPWM*256 - 9,75 usec trigger period
-> counter running @ 32MHz, value at 312 - 1 = 0x137

DTC runs is normal mode, writes 256 values to the output
The DTC triggers an interrupt using the TRJ vector.
Within the routine, the new data tables are configured 

TRJ is preload to zero so should underflow immediately after start to trigger the DTC
Then it is set immediately to the desired value

***********************************************************************************************************************/
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */


volatile uint8_t switchTable = 0;
volatile uint8_t pwmStep = 0;

void changeSwPwmTables(void);
void initStartTable(void);
void startTimers(void);

void setSwPwm(SW_PWM pwmNum, uint8_t level);

/* End user code. Do not edit comment generated here */

/* Set option bytes */
#pragma location = "OPTBYTE"
__root const uint8_t opbyte0 = 0xEFU;
#pragma location = "OPTBYTE"
__root const uint8_t opbyte1 = 0xFFU;
#pragma location = "OPTBYTE"
__root const uint8_t opbyte2 = 0xE8U;
#pragma location = "OPTBYTE"
__root const uint8_t opbyte3 = 0x86U;

/* Set security ID */
#pragma location = "SECUID"
__root const uint8_t secuid[10] = 
    {0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U};

void R_MAIN_UserInit(void);

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    R_MAIN_UserInit();
    /* Start user code. Do not edit comment generated here */
    
    uint8_t i = 0;
    
    // used by DTC within interrupt routine (timer int)
    P13_bit.no0 = 0U;
      
    // at the beginning, all at 50% 
    initStartTable();      
    
    // configure for 25% duty
    changeSwPwmTables();
    // switch table at the end of the PWM cycle
    switchTable = 1;
    
    R_DTCD0_Start();

    /* rearranged start APIs to make the offset small between the timer start points 
    R_TAU0_Channel0_Start();
    R_TAU1_Channel0_Start();
    R_TMR_RD0_Start();
    R_TMR_RD1_Start();
    R_TMR_RJ0_Start();
    */
    startTimers();    

    // do this just to see the first two cycles easier on the oscilloscope
    HALT();
       
#if 1
    
    // place burst toggle on pin just to visualize CPU / bus load
    while (1U)
    {
        P14_bit.no0 = ~P14_bit.no0;
    }
    
#endif

#if 0


    // increment pwm by one step on each push button press?
    // 0...255 then back to 0
    // NOTE: not tested yet
    while (1U)
    {
          P14_bit.no0 = ~P14_bit.no0;
          
          if(1 == pwmStep) {
            
            pwmStep = 0;
            
            setSwPwm(SW_PWM0, i);
            setSwPwm(SW_PWM1, i);
            setSwPwm(SW_PWM2, i);
            setSwPwm(SW_PWM3, i);
            setSwPwm(SW_PWM4, i);
            setSwPwm(SW_PWM5, i);
            setSwPwm(SW_PWM6, i);
            setSwPwm(SW_PWM7, i);
            setSwPwm(SW_PWM8, i);
            setSwPwm(SW_PWM9, i);
            setSwPwm(SW_PWM10, i);
            setSwPwm(SW_PWM11, i);
            setSwPwm(SW_PWM12, i);
            setSwPwm(SW_PWM13, i);
            setSwPwm(SW_PWM14, i);
            setSwPwm(SW_PWM15, i);
            setSwPwm(SW_PWM16, i);
            setSwPwm(SW_PWM17, i);
            setSwPwm(SW_PWM18, i);
            setSwPwm(SW_PWM19, i);
            setSwPwm(SW_PWM20, i);
            setSwPwm(SW_PWM21, i);
            setSwPwm(SW_PWM22, i);
            setSwPwm(SW_PWM23, i);
            setSwPwm(SW_PWM24, i);
            setSwPwm(SW_PWM25, i);
            setSwPwm(SW_PWM26, i);
            setSwPwm(SW_PWM27, i);  
            setSwPwm(SW_PWM28, i);
            setSwPwm(SW_PWM29, i);
            setSwPwm(SW_PWM30, i);
            setSwPwm(SW_PWM31, i);
          
            // change table at next period 
            switchTable = 1;
          
            i++;
            
          };
          
          P14_bit.no0 = ~P14_bit.no0;
          
          HALT(); // put CPU asleep
    }   
    
#endif
    
    /* End user code. Do not edit comment generated here */
}


/***********************************************************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_MAIN_UserInit(void)
{
    /* Start user code. Do not edit comment generated here */
    EI();
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */

void startTimers(void) {
  
  volatile uint8_t trdsr_dummy;
  
  P13_bit.no0 = 1U;
  
  trdsr_dummy = TRDSR1; /* read TRDSR1 before write 0 */
  TRDSR1 = 0x00U; /* clear TRD1 each interrupt request */
  
  trdsr_dummy = TRDSR0; /* read TRDSR0 before write 0 */
  TRDSR0 = 0x00U; /* clear TRD0 each interrupt request */
  TRDSTR |= _04_TMRD_TRD0_COUNT_CONTINUES | _08_TMRD_TRD1_COUNT_CONTINUES;
  
  TOE0 |= _0002_TAU_CH1_OUTPUT_ENABLE | _0004_TAU_CH2_OUTPUT_ENABLE | _0008_TAU_CH3_OUTPUT_ENABLE |
    _0010_TAU_CH4_OUTPUT_ENABLE | _0020_TAU_CH5_OUTPUT_ENABLE | _0040_TAU_CH6_OUTPUT_ENABLE |
      _0080_TAU_CH7_OUTPUT_ENABLE;
  
  TOE1 |= _0002_TAU_CH1_OUTPUT_ENABLE | _0004_TAU_CH2_OUTPUT_ENABLE | _0008_TAU_CH3_OUTPUT_ENABLE |
    _0010_TAU_CH4_OUTPUT_ENABLE | _0020_TAU_CH5_OUTPUT_ENABLE | _0040_TAU_CH6_OUTPUT_ENABLE |
      _0080_TAU_CH7_OUTPUT_ENABLE;        

  TRJIF0 = 0U;    /* clear INTTRJ0 interrupt flag */
  TRJMK0 = 0U;    /* enable INTTRJ0 interrupt */
  TRJ0 = 0U;    // force the TRJ to generate a trigger immediately when started
  
  // start timer 0
  TS0 |= _0001_TAU_CH0_START_TRG_ON | _0002_TAU_CH1_START_TRG_ON | _0004_TAU_CH2_START_TRG_ON |
    _0008_TAU_CH3_START_TRG_ON | _0010_TAU_CH4_START_TRG_ON | _0020_TAU_CH5_START_TRG_ON |
      _0040_TAU_CH6_START_TRG_ON | _0080_TAU_CH7_START_TRG_ON;    
  
  // start timer 1
  TS1 |= _0001_TAU_CH0_START_TRG_ON | _0002_TAU_CH1_START_TRG_ON | _0004_TAU_CH2_START_TRG_ON |
    _0008_TAU_CH3_START_TRG_ON | _0010_TAU_CH4_START_TRG_ON | _0020_TAU_CH5_START_TRG_ON |
      _0040_TAU_CH6_START_TRG_ON | _0080_TAU_CH7_START_TRG_ON;  
  
  /* start TMRD0 counter */
  /* start TMRD1 counter */
  TRDSTR |= (_01_TMRD_TRD0_COUNT_START | _02_TMRD_TRD1_COUNT_START);               
  
  TRJCR0 |= _01_TMRJ_COUNT_START;    /* enable TMRJ operation */  
  TRJ0 = _0137_TMRJ_TRJ0_VALUE; // set it back to the desired period 
  
  P13_bit.no0 = 0U;
}

void initStartTable(void) {
  
  uint8_t * portDataBuffer;
  uint8_t data;
  uint8_t pwmBit;
  uint16_t i,j;
  SW_PWM pwmNum;
  
  for (j=0; j<NUM_SW_PWM; j++) {
    
    pwmNum = pwmNumLevelIndex[j];
    
    // initialize the current table 
    // do this only for the initial state
    portDataBuffer = (uint8_t *) bufferReferences[currentTable][((pwmNum & 0x00F0) >> 4)];
    pwmBit = pwmNum & 0x000F;
    
    // set to 50%
    for(i=0; i<127; i++) {
      
      data = *portDataBuffer;
      data |= (1u << pwmBit);     
      *portDataBuffer++ = data;
    };
    
    for( ; i<NUM_PWM_STEPS; i++) {
      
      data = *portDataBuffer;
      data &= (~(1u << pwmBit));
      *portDataBuffer++ = data;
    };
    
    // store pwm level 50%
    pwmLevels[j] = 127;
  
  };

};


void changeSwPwmTables (void) {
  
  setSwPwm(SW_PWM0, 64);
  setSwPwm(SW_PWM1, 64);
  setSwPwm(SW_PWM2, 64);
  setSwPwm(SW_PWM3, 64);
  setSwPwm(SW_PWM4, 64);
  setSwPwm(SW_PWM5, 64);
  setSwPwm(SW_PWM6, 64);
  setSwPwm(SW_PWM7, 64);
  setSwPwm(SW_PWM8, 64);
  setSwPwm(SW_PWM9, 64);
  setSwPwm(SW_PWM10, 64);
  setSwPwm(SW_PWM11, 64);
  setSwPwm(SW_PWM12, 64);
  setSwPwm(SW_PWM13, 64);
  setSwPwm(SW_PWM14, 64);
  setSwPwm(SW_PWM15, 64);
  setSwPwm(SW_PWM16, 64);
  setSwPwm(SW_PWM17, 64);
  setSwPwm(SW_PWM18, 64);
  setSwPwm(SW_PWM19, 64);
  setSwPwm(SW_PWM20, 64);
  setSwPwm(SW_PWM21, 64);
  setSwPwm(SW_PWM22, 64);
  setSwPwm(SW_PWM23, 64);
  setSwPwm(SW_PWM24, 64);
  setSwPwm(SW_PWM25, 64);
  setSwPwm(SW_PWM26, 64);
  setSwPwm(SW_PWM27, 64);  
  setSwPwm(SW_PWM28, 64);
  setSwPwm(SW_PWM29, 64);
  setSwPwm(SW_PWM30, 64);
  setSwPwm(SW_PWM31, 64);
       
}


void setSwPwm(const SW_PWM pwmNum, const uint8_t level) {
  
  uint8_t * portDataBuffer;
  uint8_t data;
  uint8_t pwmBit;
  uint16_t i;
  
  // always modify the working table in background
  portDataBuffer = (uint8_t *) bufferReferences[workTable][((pwmNum & 0x00F0) >> 4)];
  pwmBit = pwmNum & 0x000F;
    
  for(i=0; i<level; i++) {
    
    data = *portDataBuffer;
    data |= (1u << pwmBit);  
    *portDataBuffer++ = data;
  };
  
  for( ; i<NUM_PWM_STEPS; i++) {
    
    data = *portDataBuffer;
    data &= (~(1u << pwmBit));
    *portDataBuffer++ = data;
  };
  
  // store pwm level
  for (i=0;i<NUM_SW_PWM;i++) {
    
    if(pwmNum == pwmNumLevelIndex[i]) break;
  }   
  
  pwmLevels[i] = level;
  
};                

/* End user code. Do not edit comment generated here */
