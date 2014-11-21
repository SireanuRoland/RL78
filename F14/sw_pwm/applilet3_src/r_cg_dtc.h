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
* File Name    : r_cg_dtc.h
* Version      : Applilet3 for RL78/F14 V2.02.00.03 [07 Aug 2014]
* Device(s)    : R5F10PMG
* Tool-Chain   : IAR Systems iccrl78
* Description  : This file implements device driver for DTC module.
* Creation Date: 21.11.2014
***********************************************************************************************************************/

#ifndef DTC_H
#define DTC_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/* 
    Peripheral Enable Register 1 (PER1) 
*/
/* Control of D/A converter input clock (DTCEN) */
#define _00_DTC_CLOCK_STOP                  (0x00U) /* stop supply of input clock */
#define _08_DTC_CLOCK_SUPPLY                (0x08U) /* supply input clock */

/*
    DTC Control Register j (DTCCRj) (j = 0 to 23)
    High Speed DTC Control Register j (HDTCCRj) (j = 0 to 1)
*/
/* Data size selection (SZ) */
#define _00_DTC_DATA_SIZE_8BITS             (0x00U) /* 8 bits */
#define _40_DTC_DATA_SIZE_16BITS            (0x40U) /* 16 bits */
/* Repeat mode interrupt enable bit (RPTINT) */
#define _00_DTC_REPEAT_INT_DISABLE          (0x00U) /* disable interrupt generation */
#define _20_DTC_REPEAT_INT_ENABLE           (0x20U) /* enable interrupt generation */
/* Chain transfer enable bit (CHNE) */
#define _00_DTC_CHAIN_TRANSFER_DISABLE      (0x00U) /* disable chain transfers */
#define _10_DTC_CHAIN_TRANSFER_ENABLE       (0x10U) /* enable chain transfers */
/* Destination address control bit (DAMOD) */
#define _00_DTC_DEST_ADDR_FIXED             (0x00U) /* destination address fixed */
#define _08_DTC_DEST_ADDR_INCREMENTED       (0x08U) /* destination address incremented */
/* Source address control bit (SAMOD) */
#define _00_DTC_SOURCE_ADDR_FIXED           (0x00U) /* source address fixed */
#define _04_DTC_SOURCE_ADDR_INCREMENTED     (0x04U) /* source address incremented */
/* Repeat area select bit (RPTSEL) */
#define _00_DTC_REPEAT_AREA_DEST            (0x00U) /* transfer destination is the repeat area */
#define _02_DTC_REPEAT_AREA_SOURCE          (0x02U) /* transfer source is the repeat area */
/* Transfer mode select bit (MODE) */
#define _00_DTC_TRANSFER_MODE_NORMAL        (0x00U) /* normal mode */
#define _01_DTC_TRANSFER_MODE_REPEAT        (0x01U) /* repeat mode */

/*  
    DTC Activation Enable Register 0 (DTCEN0)
*/
/* DTC activation enable bit (DTCEN07 - DTCEN06) */
#define _00_DTC_INTP0_ACTIVATION_DISABLE    (0x00U) /* disable activation (INTP0) */
#define _40_DTC_INTP0_ACTIVATION_ENABLE     (0x40U) /* enable activation (INTP0) */
#define _00_DTC_INTP1_ACTIVATION_DISABLE    (0x00U) /* disable activation (INTP1) */
#define _20_DTC_INTP1_ACTIVATION_ENABLE     (0x20U) /* enable activation (INTP1) */
#define _00_DTC_INTP2_ACTIVATION_DISABLE    (0x00U) /* disable activation (INTP2) */
#define _10_DTC_INTP2_ACTIVATION_ENABLE     (0x10U) /* enable activation (INTP2) */
#define _00_DTC_INTP3_ACTIVATION_DISABLE    (0x00U) /* disable activation (INTP3) */
#define _08_DTC_INTP3_ACTIVATION_ENABLE     (0x08U) /* enable activation (INTP3) */
#define _00_DTC_INTP4_ACTIVATION_DISABLE    (0x00U) /* disable activation (INTP4) */
#define _04_DTC_INTP4_ACTIVATION_ENABLE     (0x04U) /* enable activation (INTP4) */
#define _00_DTC_INTP5_ACTIVATION_DISABLE    (0x00U) /* disable activation (INTP5) */
#define _02_DTC_INTP5_ACTIVATION_ENABLE     (0x02U) /* enable activation (INTP5) */
#define _00_DTC_INTP6_ACTIVATION_DISABLE    (0x00U) /* disable activation (INTP6) */
#define _01_DTC_INTP6_ACTIVATION_ENABLE     (0x01U) /* enable activation (INTP6) */

/*  
    DTC Activation Enable Register 1 (DTCEN1)
*/
/* DTC activation enable bit (DTCEN10 - DTCEN17) */
#define _00_DTC_KEY_ACTIVATION_DISABLE      (0x00U) /* disable activation (KEY) */
#define _80_DTC_KEY_ACTIVATION_ENABLE       (0x80U) /* enable activation (KEY) */
#define _00_DTC_AD_ACTIVATION_DISABLE       (0x00U) /* disable activation (AD) */
#define _40_DTC_AD_ACTIVATION_ENABLE        (0x40U) /* enable activation (AD) */
#define _00_DTC_UART0R_ACTIVATION_DISABLE   (0x00U) /* disable activation (UART0 reception/CSI01/IIC01 transfer) */
#define _20_DTC_UART0R_ACTIVATION_ENABLE    (0x20U) /* enable activation (UART0 reception/CSI01/IIC01 transfer) */
#define _00_DTC_UART0T_ACTIVATION_DISABLE   (0x00U) /* disable activation (UART0 transmission/CSI00/IIC00 transfer) */
#define _10_DTC_UART0T_ACTIVATION_ENABLE    (0x10U) /* enable activation (UART0 transmission/CSI00/IIC00 transfer) */
#define _00_DTC_UART1R_ACTIVATION_DISABLE   (0x00U) /* disable activation (UART1 reception/CSI11/IIC11 transfer) */
#define _08_DTC_UART1R_ACTIVATION_ENABLE    (0x08U) /* enable activation (UART1 reception/CSI11/IIC11 transfer) */
#define _00_DTC_UART1T_ACTIVATION_DISABLE   (0x00U) /* disable activation (UART1 transmission/CSI10/IIC10 transfer) */
#define _04_DTC_UART1T_ACTIVATION_ENABLE    (0x04U) /* enable activation (UART1 transmission/CSI10/IIC10 transfer) */
#define _00_DTC_LIN0R_ACTIVATION_DISABLE    (0x00U) /* disable activation (LIN0 reception) */
#define _02_DTC_LIN0R_ACTIVATION_ENABLE     (0x02U) /* enable activation (LIN0 reception) */
#define _00_DTC_LIN0T_ACTIVATION_DISABLE    (0x00U) /* disable activation (LIN0 transmission) */
#define _01_DTC_LIN0T_ACTIVATION_ENABLE     (0x01U) /* enable activation (LIN0 transmission) */

/*  
    DTC Activation Enable Register 2 (DTCEN2)
*/
/* DTC activation enable bit (DTCEN20 - DTCEN27) */
#define _00_DTC_CANR_ACTIVATION_DISABLE     (0x00U) /* disable activation (CAN reception) */
#define _80_DTC_CANR_ACTIVATION_ENABLE      (0x80U) /* enable activation (CAN reception) */
#define _00_DTC_TAU00_ACTIVATION_DISABLE    (0x00U) /* disable activation (TAU00) */
#define _20_DTC_TAU00_ACTIVATION_ENABLE     (0x20U) /* enable activation (TAU00) */
#define _00_DTC_TAU01_ACTIVATION_DISABLE    (0x00U) /* disable activation (TAU01) */
#define _10_DTC_TAU01_ACTIVATION_ENABLE     (0x10U) /* enable activation (TAU01) */
#define _00_DTC_TAU02_ACTIVATION_DISABLE    (0x00U) /* disable activation (TAU02) */
#define _08_DTC_TAU02_ACTIVATION_ENABLE     (0x08U) /* enable activation (TAU02) */
#define _00_DTC_TAU03_ACTIVATION_DISABLE    (0x00U) /* disable activation (TAU03) */
#define _04_DTC_TAU03_ACTIVATION_ENABLE     (0x04U) /* enable activation (TAU03) */
#define _00_DTC_TAU04_ACTIVATION_DISABLE    (0x00U) /* disable activation (TAU04) */
#define _02_DTC_TAU04_ACTIVATION_ENABLE     (0x02U) /* enable activation (TAU04) */
#define _00_DTC_TAU05_ACTIVATION_DISABLE    (0x00U) /* disable activation (TAU05) */
#define _01_DTC_TAU05_ACTIVATION_ENABLE     (0x01U) /* enable activation (TAU05) */
/*  
    DTC Activation Enable Register 3 (DTCEN3)
*/
/* DTC activation enable bit (DTCEN30 - DTCEN37) */
#define _00_DTC_TAU06_ACTIVATION_DISABLE    (0x00U) /* disable activation (TAU06) */
#define _80_DTC_TAU06_ACTIVATION_ENABLE     (0x80U) /* enable activation (TAU06) */
#define _00_DTC_TAU07_ACTIVATION_DISABLE    (0x00U) /* disable activation (TAU07) */
#define _40_DTC_TAU07_ACTIVATION_ENABLE     (0x40U) /* enable activation (TAU07) */
#define _00_DTC_TMRDA0_ACTIVATION_DISABLE   (0x00U) /* disable activation (Timer RD compare match A0) */
#define _20_DTC_TMRDA0_ACTIVATION_ENABLE    (0x20U) /* enable activation (Timer RD compare match A0) */
#define _00_DTC_TMRDB0_ACTIVATION_DISABLE   (0x00U) /* disable activation (Timer RD compare match B0) */
#define _10_DTC_TMRDB0_ACTIVATION_ENABLE    (0x10U) /* enable activation (Timer RD compare match B0) */
#define _00_DTC_TMRDC0_ACTIVATION_DISABLE   (0x00U) /* disable activation (Timer RD compare match C0) */
#define _08_DTC_TMRDC0_ACTIVATION_ENABLE    (0x08U) /* enable activation (Timer RD compare match C0) */
#define _00_DTC_TMRDD0_ACTIVATION_DISABLE   (0x00U) /* disable activation (Timer RD compare match D0) */
#define _04_DTC_TMRDD0_ACTIVATION_ENABLE    (0x04U) /* enable activation (Timer RD compare match D0) */
#define _00_DTC_TMRDA1_ACTIVATION_DISABLE   (0x00U) /* disable activation (Timer RD compare match A1) */
#define _02_DTC_TMRDA1_ACTIVATION_ENABLE    (0x02U) /* enable activation (Timer RD compare match A1) */
#define _00_DTC_TMRDB1_ACTIVATION_DISABLE   (0x00U) /* disable activation (Timer RD compare match B1) */
#define _01_DTC_TMRDB1_ACTIVATION_ENABLE    (0x01U) /* enable activation (Timer RD compare match B1) */

/*  
    DTC Activation Enable Register 4 (DTCEN4)
*/
/* DTC activation enable bit (DTCEN40 - DTCEN47) */
#define _00_DTC_TMRDC1_ACTIVATION_DISABLE   (0x00U) /* disable activation (Timer RD compare match C1) */
#define _80_DTC_TMRDC1_ACTIVATION_ENABLE    (0x80U) /* enable activation (Timer RD compare match C1) */
#define _00_DTC_TMRDD1_ACTIVATION_DISABLE   (0x00U) /* disable activation (Timer RD compare match D1) */
#define _40_DTC_TMRDD1_ACTIVATION_ENABLE    (0x40U) /* enable activation (Timer RD compare match D1) */
#define _00_DTC_TMRJ0_ACTIVATION_DISABLE    (0x00U) /* disable activation (Timer RJ0 underflow) */
#define _20_DTC_TMRJ0_ACTIVATION_ENABLE     (0x20U) /* enable activation (Timer RJ0 underflow) */
#define _00_DTC_CMP0_ACTIVATION_DISABLE     (0x00U) /* disable activation (Comparator detection 0) */
#define _10_DTC_CMP0_ACTIVATION_ENABLE      (0x10U) /* enable activation (Comparator detection 0) */
#define _00_DTC_TAU10_ACTIVATION_DISABLE    (0x00U) /* disable activation (TAU10) */
#define _08_DTC_TAU10_ACTIVATION_ENABLE     (0x08U) /* enable activation (TAU10) */
#define _00_DTC_TAU11_ACTIVATION_DISABLE    (0x00U) /* disable activation (TAU11) */
#define _04_DTC_TAU11_ACTIVATION_ENABLE     (0x04U) /* enable activation (TAU11) */
#define _00_DTC_TAU12_ACTIVATION_DISABLE    (0x00U) /* disable activation (TAU12) */
#define _02_DTC_TAU12_ACTIVATION_ENABLE     (0x02U) /* enable activation (TAU12) */
#define _00_DTC_TAU13_ACTIVATION_DISABLE    (0x00U) /* disable activation (TAU13) */
#define _01_DTC_TAU13_ACTIVATION_ENABLE     (0x01U) /* enable activation (TAU13) */

/*  
    DTC Activation Enable Register 5 (DTCEN5)
*/
/* DTC activation enable bit (DTCEN50 - DTCEN57) */
#define _00_DTC_LIN1R_ACTIVATION_DISABLE    (0x00U) /* disable activation (LIN1 reception) */
#define _80_DTC_LIN1R_ACTIVATION_ENABLE     (0x80U) /* enable activation (LIN1 reception) */
#define _00_DTC_LIN1T_ACTIVATION_DISABLE    (0x00U) /* disable activation (LIN1 transmission) */
#define _40_DTC_LIN1T_ACTIVATION_ENABLE     (0x40U) /* enable activation (LIN1 transmission) */
#define _00_DTC_TAU14_ACTIVATION_DISABLE    (0x00U) /* disable activation (TAU14) */
#define _20_DTC_TAU14_ACTIVATION_ENABLE     (0x20U) /* enable activation (TAU14) */
#define _00_DTC_TAU15_ACTIVATION_DISABLE    (0x00U) /* disable activation (TAU15) */
#define _10_DTC_TAU15_ACTIVATION_ENABLE     (0x10U) /* enable activation (TAU15) */
#define _00_DTC_TAU16_ACTIVATION_DISABLE    (0x00U) /* disable activation (TAU16) */
#define _08_DTC_TAU16_ACTIVATION_ENABLE     (0x08U) /* enable activation (TAU16) */
#define _00_DTC_TAU17_ACTIVATION_DISABLE    (0x00U) /* disable activation (TAU17) */
#define _04_DTC_TAU17_ACTIVATION_ENABLE     (0x04U) /* enable activation (TAU17) */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _0000_DTCD0_SRC_ADDRESS             (0x0000U)
#define _0000_DTCD0_DEST_ADDRESS            (0x0000U)
#define _00_DTCD0_TRANSFER_BYTE             (0x00U)
#define _01_DTCD0_TRANSFER_BLOCKSIZE        (0x01U)
#define _0000_DTCD1_SRC_ADDRESS             (0x0000U)
#define _0000_DTCD1_DEST_ADDRESS            (0x0000U)
#define _00_DTCD1_TRANSFER_BYTE             (0x00U)
#define _01_DTCD1_TRANSFER_BLOCKSIZE        (0x01U)
#define _0000_DTCD2_SRC_ADDRESS             (0x0000U)
#define _0000_DTCD2_DEST_ADDRESS            (0x0000U)
#define _00_DTCD2_TRANSFER_BYTE             (0x00U)
#define _01_DTCD2_TRANSFER_BLOCKSIZE        (0x01U)
#define _0000_DTCD3_SRC_ADDRESS             (0x0000U)
#define _0000_DTCD3_DEST_ADDRESS            (0x0000U)
#define _00_DTCD3_TRANSFER_BYTE             (0x00U)
#define _01_DTCD3_TRANSFER_BLOCKSIZE        (0x01U)
#define _0000_DTCD4_SRC_ADDRESS             (0x0000U)
#define _0000_DTCD4_DEST_ADDRESS            (0x0000U)
#define _00_DTCD4_TRANSFER_BYTE             (0x00U)
#define _01_DTCD4_TRANSFER_BLOCKSIZE        (0x01U)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
typedef struct
{
    uint8_t  dtccr;
    uint8_t  dtbls;
    uint8_t  dtcct;
    uint8_t  dtrld;
    uint16_t dtsar;
    uint16_t dtdar;
}st_dtc_data;


/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_DTC_Create(void);
void R_DTCD0_Start(void);
void R_DTCD0_Stop(void);

/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
