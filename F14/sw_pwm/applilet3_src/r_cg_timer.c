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
* File Name    : r_cg_timer.c
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
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_TAU0_Create
* Description  : This function initializes the TAU0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Create(void)
{
    TAU0EN = 1U;    /* supplies input clock */
    TPS0 = _0001_TAU_CKM0_FCLK_1 | _0000_TAU_CKM1_FCLK_0 | _0000_TAU_CKM2_FCLK_1 | _0000_TAU_CKM3_FCLK_8;
    /* Stop all channels */
    TT0 = _0001_TAU_CH0_STOP_TRG_ON | _0002_TAU_CH1_STOP_TRG_ON | _0004_TAU_CH2_STOP_TRG_ON |
          _0008_TAU_CH3_STOP_TRG_ON | _0010_TAU_CH4_STOP_TRG_ON | _0020_TAU_CH5_STOP_TRG_ON |
          _0040_TAU_CH6_STOP_TRG_ON | _0080_TAU_CH7_STOP_TRG_ON | _0200_TAU_CH1_H8_STOP_TRG_ON |
          _0800_TAU_CH3_H8_STOP_TRG_ON;
    PWMDLY1 = _0000_TAU_PWM_DELAY_CLEAR;    /* clear PWM output delay */
    /* Mask channel 0 interrupt */
    TMMK00 = 1U;    /* disable INTTM00 interrupt */
    TMIF00 = 0U;    /* clear INTTM00 interrupt flag */
    /* Mask channel 1 interrupt */
    TMMK01 = 1U;    /* disable INTTM01 interrupt */
    TMIF01 = 0U;    /* clear INTTM01 interrupt flag */
    /* Mask channel 1 higher 8 bits interrupt */
    TMMK01H = 1U;    /* disable INTTM01H interrupt */
    TMIF01H = 0U;    /* clear INTTM01H interrupt flag */
    /* Mask channel 2 interrupt */
    TMMK02 = 1U;    /* disable INTTM02 interrupt */
    TMIF02 = 0U;    /* clear INTTM02 interrupt flag */
    /* Mask channel 3 interrupt */
    TMMK03 = 1U;    /* disable INTTM03 interrupt */
    TMIF03 = 0U;    /* clear INTTM03 interrupt flag */
    /* Mask channel 3 higher 8 bits interrupt */
    TMMK03H = 1U;    /* disable INTTM03H interrupt */
    TMIF03H = 0U;    /* clear INTTM03H interrupt flag */
    /* Mask channel 4 interrupt */
    TMMK04 = 1U;    /* disable INTTM04 interrupt */
    TMIF04 = 0U;    /* clear INTTM04 interrupt flag */
    /* Mask channel 5 interrupt */
    TMMK05 = 1U;    /* disable INTTM05 interrupt */
    TMIF05 = 0U;    /* clear INTTM05 interrupt flag */
    /* Mask channel 6 interrupt */
    TMMK06 = 1U;    /* disable INTTM06 interrupt */
    TMIF06 = 0U;    /* clear INTTM06 interrupt flag */
    /* Mask channel 7 interrupt */
    TMMK07 = 1U;    /* disable INTTM07 interrupt */
    TMIF07 = 0U;    /* clear INTTM07 interrupt flag */
    /* Channel 0 is used as master channel for PWM output function */
    TMR00 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_TRIGGER_SOFTWARE |
            _0001_TAU_MODE_PWM_MASTER;
    TDR00 = _9BFF_TAU_TDR00_VALUE;
    TO0 &= ~_0001_TAU_CH0_OUTPUT_VALUE_1;
    TOE0 &= ~_0001_TAU_CH0_OUTPUT_ENABLE;
    /* Channel 1 is used as slave channel for PWM output function */
    TMR01 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
            _0400_TAU_TRIGGER_MASTER_INT | _0009_TAU_MODE_PWM_SLAVE;
    TDR01 = _4E00_TAU_TDR01_VALUE;
    TOM0 |= _0002_TAU_CH1_OUTPUT_COMBIN;
    TOL0 &= ~_0002_TAU_CH1_OUTPUT_LEVEL_L;
    TO0 &= ~_0002_TAU_CH1_OUTPUT_VALUE_1;
    PWMDLY1 |= _0000_TO01_OUTPUT_DELAY_0;
    TOE0 |= _0002_TAU_CH1_OUTPUT_ENABLE;
    /* Channel 2 is used as slave channel for PWM output function */
    TMR02 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
            _0400_TAU_TRIGGER_MASTER_INT | _0009_TAU_MODE_PWM_SLAVE;
    TDR02 = _4E00_TAU_TDR02_VALUE;
    TOM0 |= _0004_TAU_CH2_OUTPUT_COMBIN;
    TOL0 &= ~_0004_TAU_CH2_OUTPUT_LEVEL_L;
    TO0 &= ~_0004_TAU_CH2_OUTPUT_VALUE_1;
    PWMDLY1 |= _0000_TO02_OUTPUT_DELAY_0;
    TOE0 |= _0004_TAU_CH2_OUTPUT_ENABLE;
    /* Channel 3 is used as slave channel for PWM output function */
    TMR03 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
            _0400_TAU_TRIGGER_MASTER_INT | _0009_TAU_MODE_PWM_SLAVE;
    TDR03 = _4E00_TAU_TDR03_VALUE;
    TOM0 |= _0008_TAU_CH3_OUTPUT_COMBIN;
    TOL0 &= ~_0008_TAU_CH3_OUTPUT_LEVEL_L;
    TO0 &= ~_0008_TAU_CH3_OUTPUT_VALUE_1;
    PWMDLY1 |= _0000_TO03_OUTPUT_DELAY_0;
    TOE0 |= _0008_TAU_CH3_OUTPUT_ENABLE;
    /* Channel 4 is used as slave channel for PWM output function */
    TMR04 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
            _0400_TAU_TRIGGER_MASTER_INT | _0009_TAU_MODE_PWM_SLAVE;
    TDR04 = _4E00_TAU_TDR04_VALUE;
    TOM0 |= _0010_TAU_CH4_OUTPUT_COMBIN;
    TOL0 &= ~_0010_TAU_CH4_OUTPUT_LEVEL_L;
    TO0 &= ~_0010_TAU_CH4_OUTPUT_VALUE_1;
    PWMDLY1 |= _0000_TO04_OUTPUT_DELAY_0;
    TOE0 |= _0010_TAU_CH4_OUTPUT_ENABLE;
    /* Channel 5 is used as slave channel for PWM output function */
    TMR05 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
            _0400_TAU_TRIGGER_MASTER_INT | _0009_TAU_MODE_PWM_SLAVE;
    TDR05 = _4E00_TAU_TDR05_VALUE;
    TOM0 |= _0020_TAU_CH5_OUTPUT_COMBIN;
    TOL0 &= ~_0020_TAU_CH5_OUTPUT_LEVEL_L;
    TO0 &= ~_0020_TAU_CH5_OUTPUT_VALUE_1;
    PWMDLY1 |= _0000_TO05_OUTPUT_DELAY_0;
    TOE0 |= _0020_TAU_CH5_OUTPUT_ENABLE;
    /* Channel 6 is used as slave channel for PWM output function */
    TMR06 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
            _0400_TAU_TRIGGER_MASTER_INT | _0009_TAU_MODE_PWM_SLAVE;
    TDR06 = _4E00_TAU_TDR06_VALUE;
    TOM0 |= _0040_TAU_CH6_OUTPUT_COMBIN;
    TOL0 &= ~_0040_TAU_CH6_OUTPUT_LEVEL_L;
    TO0 &= ~_0040_TAU_CH6_OUTPUT_VALUE_1;
    PWMDLY1 |= _0000_TO06_OUTPUT_DELAY_0;
    TOE0 |= _0040_TAU_CH6_OUTPUT_ENABLE;
    /* Channel 7 is used as slave channel for PWM output function */
    TMR07 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
            _0400_TAU_TRIGGER_MASTER_INT | _0009_TAU_MODE_PWM_SLAVE;
    TDR07 = _4E00_TAU_TDR07_VALUE;
    TOM0 |= _0080_TAU_CH7_OUTPUT_COMBIN;
    TOL0 &= ~_0080_TAU_CH7_OUTPUT_LEVEL_L;
    TO0 &= ~_0080_TAU_CH7_OUTPUT_VALUE_1;
    PWMDLY1 |= _0000_TO07_OUTPUT_DELAY_0;
    TOE0 |= _0080_TAU_CH7_OUTPUT_ENABLE;
    /* Set TO01 pin */
    P12 &= 0xBFU;
    PM12 &= 0xBFU;
    /* Set TO02 pin */
    P6 &= 0x7FU;
    PM6 &= 0x7FU;
    /* Set TO03 pin */
    PMC12 &= 0xDFU;
    P12 &= 0xDFU;
    PM12 &= 0xDFU;
    /* Set TO04 pin */
    P0 &= 0xFDU;
    PM0 &= 0xFDU;
    /* Set TO05 pin */
    P0 &= 0xFEU;
    PM0 &= 0xFEU;
    /* Set TO06 pin */
    P0 &= 0xFBU;
    PM0 &= 0xFBU;
    /* Set TO07 pin */
    P4 &= 0xEFU;
    PM4 &= 0xEFU;
}

/***********************************************************************************************************************
* Function Name: R_TAU0_Channel0_Start
* Description  : This function starts TAU0 channel 0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Channel0_Start(void)
{
    TOE0 |= _0002_TAU_CH1_OUTPUT_ENABLE | _0004_TAU_CH2_OUTPUT_ENABLE | _0008_TAU_CH3_OUTPUT_ENABLE |
            _0010_TAU_CH4_OUTPUT_ENABLE | _0020_TAU_CH5_OUTPUT_ENABLE | _0040_TAU_CH6_OUTPUT_ENABLE |
            _0080_TAU_CH7_OUTPUT_ENABLE;
    TS0 |= _0001_TAU_CH0_START_TRG_ON | _0002_TAU_CH1_START_TRG_ON | _0004_TAU_CH2_START_TRG_ON |
           _0008_TAU_CH3_START_TRG_ON | _0010_TAU_CH4_START_TRG_ON | _0020_TAU_CH5_START_TRG_ON |
           _0040_TAU_CH6_START_TRG_ON | _0080_TAU_CH7_START_TRG_ON;
}

/***********************************************************************************************************************
* Function Name: R_TAU0_Channel0_Stop
* Description  : This function stops TAU0 channel 0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Channel0_Stop(void)
{
    TT0 |= _0001_TAU_CH0_STOP_TRG_ON | _0002_TAU_CH1_STOP_TRG_ON | _0004_TAU_CH2_STOP_TRG_ON |
           _0008_TAU_CH3_STOP_TRG_ON | _0010_TAU_CH4_STOP_TRG_ON | _0020_TAU_CH5_STOP_TRG_ON |
           _0040_TAU_CH6_STOP_TRG_ON | _0080_TAU_CH7_STOP_TRG_ON;
    TOE0 &= ~_0002_TAU_CH1_OUTPUT_ENABLE & ~_0004_TAU_CH2_OUTPUT_ENABLE & ~_0008_TAU_CH3_OUTPUT_ENABLE & 
            ~_0010_TAU_CH4_OUTPUT_ENABLE & ~_0020_TAU_CH5_OUTPUT_ENABLE & ~_0040_TAU_CH6_OUTPUT_ENABLE & 
            ~_0080_TAU_CH7_OUTPUT_ENABLE;
}

/***********************************************************************************************************************
* Function Name: R_TAU1_Create
* Description  : This function initializes the TAU1 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU1_Create(void)
{
    TAU1EN = 1U;    /* supplies input clock */
    TPS1 = _0001_TAU_CKM0_FCLK_1 | _0000_TAU_CKM1_FCLK_0 | _0000_TAU_CKM2_FCLK_1 | _0000_TAU_CKM3_FCLK_8;
    /* Stop all channels */
    TT1 = _0001_TAU_CH0_STOP_TRG_ON | _0002_TAU_CH1_STOP_TRG_ON | _0004_TAU_CH2_STOP_TRG_ON |
          _0008_TAU_CH3_STOP_TRG_ON | _0010_TAU_CH4_STOP_TRG_ON | _0020_TAU_CH5_STOP_TRG_ON |
          _0040_TAU_CH6_STOP_TRG_ON | _0080_TAU_CH7_STOP_TRG_ON | _0200_TAU_CH1_H8_STOP_TRG_ON |
          _0800_TAU_CH3_H8_STOP_TRG_ON;
    PWMDLY2 = _0000_TAU_PWM_DELAY_CLEAR;    /* clear PWM output delay */
    /* Mask channel 0 interrupt */
    TMMK10 = 1U;    /* disable INTTM10 interrupt */
    TMIF10 = 0U;    /* clear INTTM10 interrupt flag */
    /* Mask channel 1 interrupt */
    TMMK11 = 1U;    /* disable INTTM11 interrupt */
    TMIF11 = 0U;    /* clear INTTM11 interrupt flag */
    /* Mask channel 1 higher 8 bits interrupt */
    TMMK11H = 1U;    /* disable INTTM11H interrupt */
    TMIF11H = 0U;    /* clear INTTM11H interrupt flag */
    /* Mask channel 2 interrupt */
    TMMK12 = 1U;    /* disable INTTM12 interrupt */
    TMIF12 = 0U;    /* clear INTTM12 interrupt flag */
    /* Mask channel 3 interrupt */
    TMMK13 = 1U;    /* disable INTTM13 interrupt */
    TMIF13 = 0U;    /* clear INTTM13 interrupt flag */
    /* Mask channel 3 higher 8 bits interrupt */
    TMMK13H = 1U;    /* disable INTTM13H interrupt */
    TMIF13H = 0U;    /* clear INTTM13H interrupt flag */
    /* Mask channel 4 interrupt */
    TMMK14 = 1U;    /* disable INTTM14 interrupt */
    TMIF14 = 0U;    /* clear INTTM14 interrupt flag */
    /* Mask channel 5 interrupt */
    TMMK15 = 1U;    /* disable INTTM15 interrupt */
    TMIF15 = 0U;    /* clear INTTM15 interrupt flag */
    /* Mask channel 6 interrupt */
    TMMK16 = 1U;    /* disable INTTM16 interrupt */
    TMIF16 = 0U;    /* clear INTTM16 interrupt flag */
    /* Mask channel 7 interrupt */
    TMMK17 = 1U;    /* disable INTTM17 interrupt */
    TMIF17 = 0U;    /* clear INTTM17 interrupt flag */
    /* Channel 0 is used as master channel for PWM output function */
    TMR10 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_TRIGGER_SOFTWARE |
            _0001_TAU_MODE_PWM_MASTER;
    TDR10 = _9BFF_TAU_TDR10_VALUE;
    TO1 &= ~_0001_TAU_CH0_OUTPUT_VALUE_1;
    TOE1 &= ~_0001_TAU_CH0_OUTPUT_ENABLE;
    /* Channel 1 is used as slave channel for PWM output function */
    TMR11 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
            _0400_TAU_TRIGGER_MASTER_INT | _0009_TAU_MODE_PWM_SLAVE;
    TDR11 = _4E00_TAU_TDR11_VALUE;
    TOM1 |= _0002_TAU_CH1_OUTPUT_COMBIN;
    TOL1 &= ~_0002_TAU_CH1_OUTPUT_LEVEL_L;
    TO1 &= ~_0002_TAU_CH1_OUTPUT_VALUE_1;
    PWMDLY2 |= _0000_TO11_OUTPUT_DELAY_0;
    TOE1 |= _0002_TAU_CH1_OUTPUT_ENABLE;
    /* Channel 2 is used as slave channel for PWM output function */
    TMR12 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
            _0400_TAU_TRIGGER_MASTER_INT | _0009_TAU_MODE_PWM_SLAVE;
    TDR12 = _4E00_TAU_TDR12_VALUE;
    TOM1 |= _0004_TAU_CH2_OUTPUT_COMBIN;
    TOL1 &= ~_0004_TAU_CH2_OUTPUT_LEVEL_L;
    TO1 &= ~_0004_TAU_CH2_OUTPUT_VALUE_1;
    PWMDLY2 |= _0000_TO12_OUTPUT_DELAY_0;
    TOE1 |= _0004_TAU_CH2_OUTPUT_ENABLE;
    /* Channel 3 is used as slave channel for PWM output function */
    TMR13 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
            _0400_TAU_TRIGGER_MASTER_INT | _0009_TAU_MODE_PWM_SLAVE;
    TDR13 = _4E00_TAU_TDR13_VALUE;
    TOM1 |= _0008_TAU_CH3_OUTPUT_COMBIN;
    TOL1 &= ~_0008_TAU_CH3_OUTPUT_LEVEL_L;
    TO1 &= ~_0008_TAU_CH3_OUTPUT_VALUE_1;
    PWMDLY2 |= _0000_TO13_OUTPUT_DELAY_0;
    TOE1 |= _0008_TAU_CH3_OUTPUT_ENABLE;
    /* Channel 4 is used as slave channel for PWM output function */
    TMR14 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
            _0400_TAU_TRIGGER_MASTER_INT | _0009_TAU_MODE_PWM_SLAVE;
    TDR14 = _4E00_TAU_TDR14_VALUE;
    TOM1 |= _0010_TAU_CH4_OUTPUT_COMBIN;
    TOL1 &= ~_0010_TAU_CH4_OUTPUT_LEVEL_L;
    TO1 &= ~_0010_TAU_CH4_OUTPUT_VALUE_1;
    PWMDLY2 |= _0000_TO14_OUTPUT_DELAY_0;
    TOE1 |= _0010_TAU_CH4_OUTPUT_ENABLE;
    /* Channel 5 is used as slave channel for PWM output function */
    TMR15 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
            _0400_TAU_TRIGGER_MASTER_INT | _0009_TAU_MODE_PWM_SLAVE;
    TDR15 = _4E00_TAU_TDR15_VALUE;
    TOM1 |= _0020_TAU_CH5_OUTPUT_COMBIN;
    TOL1 &= ~_0020_TAU_CH5_OUTPUT_LEVEL_L;
    TO1 &= ~_0020_TAU_CH5_OUTPUT_VALUE_1;
    PWMDLY2 |= _0000_TO15_OUTPUT_DELAY_0;
    TOE1 |= _0020_TAU_CH5_OUTPUT_ENABLE;
    /* Channel 6 is used as slave channel for PWM output function */
    TMR16 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
            _0400_TAU_TRIGGER_MASTER_INT | _0009_TAU_MODE_PWM_SLAVE;
    TDR16 = _4E00_TAU_TDR16_VALUE;
    TOM1 |= _0040_TAU_CH6_OUTPUT_COMBIN;
    TOL1 &= ~_0040_TAU_CH6_OUTPUT_LEVEL_L;
    TO1 &= ~_0040_TAU_CH6_OUTPUT_VALUE_1;
    PWMDLY2 |= _0000_TO16_OUTPUT_DELAY_0;
    TOE1 |= _0040_TAU_CH6_OUTPUT_ENABLE;
    /* Channel 7 is used as slave channel for PWM output function */
    TMR17 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
            _0400_TAU_TRIGGER_MASTER_INT | _0009_TAU_MODE_PWM_SLAVE;
    TDR17 = _4E00_TAU_TDR17_VALUE;
    TOM1 |= _0080_TAU_CH7_OUTPUT_COMBIN;
    TOL1 &= ~_0080_TAU_CH7_OUTPUT_LEVEL_L;
    TO1 &= ~_0080_TAU_CH7_OUTPUT_VALUE_1;
    PWMDLY2 |= _0000_TO17_OUTPUT_DELAY_0;
    TOE1 |= _0080_TAU_CH7_OUTPUT_ENABLE;
    /* Set TO11 pin */
    P5 &= 0xEFU;
    PM5 &= 0xEFU;
    /* Set TO12 pin */
    P4 &= 0xBFU;
    PM4 &= 0xBFU;
    /* Set TO13 pin */
    P5 &= 0xDFU;
    PM5 &= 0xDFU;
    /* Set TO14 pin */
    P6 &= 0xEFU;
    PM6 &= 0xEFU;
    /* Set TO15 pin */
    P5 &= 0xBFU;
    PM5 &= 0xBFU;
    /* Set TO16 pin */
    P6 &= 0xDFU;
    PM6 &= 0xDFU;
    /* Set TO17 pin */
    P5 &= 0x7FU;
    PM5 &= 0x7FU;
}

/***********************************************************************************************************************
* Function Name: R_TAU1_Channel0_Start
* Description  : This function starts TAU1 channel 0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU1_Channel0_Start(void)
{
    TOE1 |= _0002_TAU_CH1_OUTPUT_ENABLE | _0004_TAU_CH2_OUTPUT_ENABLE | _0008_TAU_CH3_OUTPUT_ENABLE |
            _0010_TAU_CH4_OUTPUT_ENABLE | _0020_TAU_CH5_OUTPUT_ENABLE | _0040_TAU_CH6_OUTPUT_ENABLE |
            _0080_TAU_CH7_OUTPUT_ENABLE;
    TS1 |= _0001_TAU_CH0_START_TRG_ON | _0002_TAU_CH1_START_TRG_ON | _0004_TAU_CH2_START_TRG_ON |
           _0008_TAU_CH3_START_TRG_ON | _0010_TAU_CH4_START_TRG_ON | _0020_TAU_CH5_START_TRG_ON |
           _0040_TAU_CH6_START_TRG_ON | _0080_TAU_CH7_START_TRG_ON;
}

/***********************************************************************************************************************
* Function Name: R_TAU1_Channel0_Stop
* Description  : This function stops TAU1 channel 0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU1_Channel0_Stop(void)
{
    TT1 |= _0001_TAU_CH0_STOP_TRG_ON | _0002_TAU_CH1_STOP_TRG_ON | _0004_TAU_CH2_STOP_TRG_ON |
           _0008_TAU_CH3_STOP_TRG_ON | _0010_TAU_CH4_STOP_TRG_ON | _0020_TAU_CH5_STOP_TRG_ON |
           _0040_TAU_CH6_STOP_TRG_ON | _0080_TAU_CH7_STOP_TRG_ON;
    TOE1 &= ~_0002_TAU_CH1_OUTPUT_ENABLE & ~_0004_TAU_CH2_OUTPUT_ENABLE & ~_0008_TAU_CH3_OUTPUT_ENABLE & 
            ~_0010_TAU_CH4_OUTPUT_ENABLE & ~_0020_TAU_CH5_OUTPUT_ENABLE & ~_0040_TAU_CH6_OUTPUT_ENABLE & 
            ~_0080_TAU_CH7_OUTPUT_ENABLE;
}

/***********************************************************************************************************************
* Function Name: R_TMR_RJ0_Create
* Description  : This function initializes the TMRJ0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_RJ0_Create(void)
{
    TRJ0EN = 1U;    /* enable input clock supply */
    TRJCR0 &= (uint8_t)~_01_TMRJ_COUNT_START;    /* disable TMRJ0 operation */
    TRJMK0 = 1U;    /* disable INTTRJ0 interrupt */
    TRJIF0 = 0U;    /* clear INTTRJ0 interrupt flag */
    /* Set INTTRJ0 level 1 priority */
    TRJPR10 = 0U;
    TRJPR00 = 1U;
    TRJMR0 = _00_TMRJ_MODE_TIMER | _00_TMRJ_COUNT_SOURCE_FCLK;
    TRJIOC0 = _00_TMRJ_TRJIOC_INITIAL_VALUE;
    TRJ0 = _0137_TMRJ_TRJ0_VALUE;
}

/***********************************************************************************************************************
* Function Name: R_TMR_RJ0_Start
* Description  : This function starts TMRJ0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_RJ0_Start(void)
{
    TRJIF0 = 0U;    /* clear INTTRJ0 interrupt flag */
    TRJMK0 = 0U;    /* enable INTTRJ0 interrupt */
    TRJCR0 |= _01_TMRJ_COUNT_START;    /* enable TMRJ operation */
}

/***********************************************************************************************************************
* Function Name: R_TMR_RJ0_Stop
* Description  : This function stops TMRJ0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_RJ0_Stop(void)
{
    TRJCR0 &= (uint8_t)~_01_TMRJ_COUNT_START;    /* disable TMRJ operation */
    TRJMK0 = 1U;    /* disable INTTRJ0 interrupt */
    TRJIF0 = 0U;    /* clear INTTRJ0 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_TMR_RD0_Create
* Description  : This function initializes the TMRD0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_RD0_Create(void)
{
    TRD0EN = 1U;    /* enable input clock supply */ 
    TRDSTR |= _04_TMRD_TRD0_COUNT_CONTINUES;
    TRDSTR &= (uint8_t)~_01_TMRD_TRD0_COUNT_START;  /* disable TMRD0 operation */
    PWMDLY0 = _0000_TMRD_PWM_DELAY_CLEAR;    /* clear PWM output delay */
    TRDMK0 = 1U;    /* disable TMRD0 interrupt */
    TRDIF0 = 0U;    /* clear TMRD0 interrupt flag */
    TRDMR |= _00_TMRD_TRDGRC0_GENERAL | _00_TMRD_TRDGRD0_GENERAL;
    TRDPMR |= _01_TMRD_TRDIOB0_PWM_MODE | _02_TMRD_TRDIOC0_PWM_MODE | _04_TMRD_TRDIOD0_PWM_MODE;
    TRDDF0 = _00_TMRD_TRDIOD_FORCEDCUTOFF_DISABLE | _00_TMRD_TRDIOC_FORCEDCUTOFF_DISABLE |
             _00_TMRD_TRDIOB_FORCEDCUTOFF_DISABLE;
    PWMDLY0 |= _0000_TMRD_TRDIOB0_OUTPUT_DELAY_0 | _0000_TMRD_TRDIOC0_OUTPUT_DELAY_0 |
               _0000_TMRD_TRDIOD0_OUTPUT_DELAY_0;
    TRDOER1 &= _F0_TMRD_CHANNEL0_OUTPUT_DEFAULT;
    TRDOER1 |= _01_TMRD_TRDIOA0_OUTPUT_DISABLE | _00_TMRD_TRDIOB0_OUTPUT_ENABLE | _00_TMRD_TRDIOC0_OUTPUT_ENABLE |
               _00_TMRD_TRDIOD0_OUTPUT_ENABLE;
    TRDOCR |= _00_TMRD_TRDIOB0_INITIAL_OUTPUT_L | _00_TMRD_TRDIOC0_INITIAL_OUTPUT_L | _00_TMRD_TRDIOD0_INITIAL_OUTPUT_L;
    TRDCR0 |= _01_TMRD_INTERNAL_CLOCK_F2 | _20_TMRD_COUNTER_CLEAR_TRDGRA;
    TRDIER0 = _00_TMRD_IMIA_DISABLE | _00_TMRD_IMIB_DISABLE | _00_TMRD_IMIC_DISABLE | _00_TMRD_IMID_DISABLE;
    TRDPOCR0 = _01_TMRD_TRDIOB_OUTPUT_ACTIVE_H | _02_TMRD_TRDIOC_OUTPUT_ACTIVE_H | _00_TMRD_TRDIOD_OUTPUT_ACTIVE_L;
    TRDGRA0 = _9BFF_TMRD_TRDGRA0_VALUE;
    TRDGRB0 = _4DFF_TMRD_TRDGRB0_VALUE;
    TRDGRC0 = _4DFF_TMRD_TRDGRC0_VALUE;
    TRDGRD0 = _4DFF_TMRD_TRDGRD0_VALUE;
    /* Set TRDIOB0 pin */
    POM1 &= 0xFDU;
    PM1 &= 0xFDU;
    P1 &= 0xFDU;
    /* Set TRDIOC0 pin */
    POM1 &= 0xEFU;
    PM1 &= 0xEFU;
    P1 &= 0xEFU;
    /* Set TRDIOD0 pin */
    POM1 &= 0xFBU;
    PM1 &= 0xFBU;
    P1 &= 0xFBU;
}

/***********************************************************************************************************************
* Function Name: R_TMR_RD0_Start
* Description  : This function starts TMRD0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_RD0_Start(void)
{
    volatile uint8_t trdsr_dummy;

   
    trdsr_dummy = TRDSR0; /* read TRDSR0 before write 0 */
    TRDSR0 = 0x00U; /* clear TRD0 each interrupt request */
    TRDSTR |= _04_TMRD_TRD0_COUNT_CONTINUES;
    TRDSTR |= _01_TMRD_TRD0_COUNT_START;    /* start TMRD0 counter */
}

/***********************************************************************************************************************
* Function Name: R_TMR_RD0_Stop
* Description  : This function stops TMRD0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_RD0_Stop(void)
{
    volatile uint8_t trdsr_dummy;
    
    TRDSTR |= _04_TMRD_TRD0_COUNT_CONTINUES;
    TRDSTR &= (uint8_t)~_01_TMRD_TRD0_COUNT_START;  /* stop TMRD0 counter */
    trdsr_dummy = TRDSR0; /* read TRDSR0 before write 0 */
    TRDSR0 = 0x00U; /* clear TRD0 each interrupt request */
}

/***********************************************************************************************************************
* Function Name: R_TMR_RD1_Create
* Description  : This function initializes the TMRD1 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_RD1_Create(void)
{
    TRD0EN = 1U;    /* enable input clock supply */ 
    TRDSTR |= _08_TMRD_TRD1_COUNT_CONTINUES;
    TRDSTR &= (uint8_t)~_02_TMRD_TRD1_COUNT_START;  /* disable TMRD1 operation */
    PWMDLY0 = _0000_TMRD_PWM_DELAY_CLEAR;    /* clear PWM output delay */
    TRDMK1 = 1U;    /* disable TMRD1 interrupt */
    TRDIF1 = 0U;    /* clear TMRD1 interrupt flag */
    TRDMR |= _00_TMRD_TRDGRC1_GENERAL | _00_TMRD_TRDGRD1_GENERAL;
    TRDPMR |= _10_TMRD_TRDIOB1_PWM_MODE | _20_TMRD_TRDIOC1_PWM_MODE | _40_TMRD_TRDIOD1_PWM_MODE;
    TRDDF1 = _00_TMRD_TRDIOD_FORCEDCUTOFF_DISABLE | _00_TMRD_TRDIOC_FORCEDCUTOFF_DISABLE |
             _00_TMRD_TRDIOB_FORCEDCUTOFF_DISABLE;
    PWMDLY0 |= _0000_TMRD_TRDIOB1_OUTPUT_DELAY_0 | _0000_TMRD_TRDIOC1_OUTPUT_DELAY_0 |
               _0000_TMRD_TRDIOD1_OUTPUT_DELAY_0;
    TRDOER1 &= _0F_TMRD_CHANNEL1_OUTPUT_DEFAULT;
    TRDOER1 |= _10_TMRD_TRDIOA1_OUTPUT_DISABLE | _00_TMRD_TRDIOB1_OUTPUT_ENABLE | _00_TMRD_TRDIOC1_OUTPUT_ENABLE |
               _00_TMRD_TRDIOD1_OUTPUT_ENABLE;
    TRDOCR |= _00_TMRD_TRDIOB1_INITIAL_OUTPUT_L | _00_TMRD_TRDIOC1_INITIAL_OUTPUT_L | _00_TMRD_TRDIOD1_INITIAL_OUTPUT_L;
    TRDCR1 |= _01_TMRD_INTERNAL_CLOCK_F2 | _20_TMRD_COUNTER_CLEAR_TRDGRA;
    TRDIER1 = _00_TMRD_IMIA_DISABLE | _00_TMRD_IMIB_DISABLE | _00_TMRD_IMIC_DISABLE | _00_TMRD_IMID_DISABLE;
    TRDPOCR1 = _01_TMRD_TRDIOB_OUTPUT_ACTIVE_H | _02_TMRD_TRDIOC_OUTPUT_ACTIVE_H | _04_TMRD_TRDIOD_OUTPUT_ACTIVE_H;
    TRDGRA1 = _9BFF_TMRD_TRDGRA1_VALUE;
    TRDGRB1 = _4DFF_TMRD_TRDGRB1_VALUE;
    TRDGRC1 = _4DFF_TMRD_TRDGRC1_VALUE;
    TRDGRD1 = _4DFF_TMRD_TRDGRD1_VALUE;
    /* Set TRDIOB1 pin */
    POM1 &= 0x7FU;
    PM1 &= 0x7FU;
    P1 &= 0x7FU;
    /* Set TRDIOC1 pin */
    POM1 &= 0xBFU;
    PM1 &= 0xBFU;
    P1 &= 0xBFU;
    /* Set TRDIOD1 pin */
    PM3 &= 0xFEU;
    P3 &= 0xFEU;
}

/***********************************************************************************************************************
* Function Name: R_TMR_RD1_Start
* Description  : This function starts TMRD1 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_RD1_Start(void)
{
    volatile uint8_t trdsr_dummy;

   
    trdsr_dummy = TRDSR1; /* read TRDSR1 before write 0 */
    TRDSR1 = 0x00U; /* clear TRD1 each interrupt request */
    TRDSTR |= _08_TMRD_TRD1_COUNT_CONTINUES;
    TRDSTR |= _02_TMRD_TRD1_COUNT_START;    /* start TMRD1 counter */
}

/***********************************************************************************************************************
* Function Name: R_TMR_RD1_Stop
* Description  : This function stops TMRD1 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_RD1_Stop(void)
{
    volatile uint8_t trdsr_dummy;
    
    TRDSTR |= _08_TMRD_TRD1_COUNT_CONTINUES;
    TRDSTR &= (uint8_t)~_02_TMRD_TRD1_COUNT_START;  /* stop TMRD1 counter */
    trdsr_dummy = TRDSR1; /* read TRDSR1 before write 0 */
    TRDSR1 = 0x00U; /* clear TRD1 each interrupt request */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
