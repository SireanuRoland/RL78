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
* File Name    : r_cg_dtc.c
* Version      : Applilet3 for RL78/F14 V2.02.00.03 [07 Aug 2014]
* Device(s)    : R5F10PMG
* Tool-Chain   : IAR Systems iccrl78
* Description  : This file implements device driver for DTC module.
* Creation Date: 19.11.2014
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_dtc.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#pragma location = 0xFFB00U
__no_init uint8_t dtc_vectortable[40];

#pragma location = 0xFFB40U
__no_init st_dtc_data dtc_controldata_0;

#pragma location = 0xFFB48U
__no_init st_dtc_data dtc_controldata_1;

#pragma location = 0xFFB50U
__no_init st_dtc_data dtc_controldata_2;

#pragma location = 0xFFB58U
__no_init st_dtc_data dtc_controldata_3;

#pragma location = 0xFFB60U
__no_init st_dtc_data dtc_controldata_4;


/***********************************************************************************************************************
* Function Name: R_DTC_Create
* Description  : This function initializes the DTC module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DTC_Create(void)
{
    /* Enable input clock supply */
    DTCEN = 1U;
    /* Disable all DTC channels operation */
    DTCEN0 = 0x00U;
    DTCEN1 = 0x00U;
    DTCEN2 = 0x00U;
    DTCEN3 = 0x00U;
    DTCEN4 = 0x00U;
    DTCEN5 = 0x00U;
    /* Set base address */
    DTCBAR = 0xFBU;
    /* Set DTCD0 */
    dtc_vectortable[34] = 0x40U;
    dtc_controldata_0.dtccr = _00_DTC_TRANSFER_MODE_NORMAL | _00_DTC_DATA_SIZE_8BITS | _04_DTC_SOURCE_ADDR_INCREMENTED |
                              _00_DTC_DEST_ADDR_FIXED | _10_DTC_CHAIN_TRANSFER_ENABLE;
    dtc_controldata_0.dtbls = _01_DTCD0_TRANSFER_BLOCKSIZE;
    dtc_controldata_0.dtcct = _00_DTCD0_TRANSFER_BYTE;
    dtc_controldata_0.dtrld = _00_DTCD0_TRANSFER_BYTE;
    dtc_controldata_0.dtsar = (uint16_t) &Port9Table0;
    dtc_controldata_0.dtdar = (uint16_t) PORT9_address;
    /* Set DTCD1 */
    dtc_controldata_1.dtccr = _00_DTC_TRANSFER_MODE_NORMAL | _00_DTC_DATA_SIZE_8BITS | _04_DTC_SOURCE_ADDR_INCREMENTED |
                              _00_DTC_DEST_ADDR_FIXED | _10_DTC_CHAIN_TRANSFER_ENABLE;
    dtc_controldata_1.dtbls = _01_DTCD1_TRANSFER_BLOCKSIZE;
    dtc_controldata_1.dtcct = _00_DTCD1_TRANSFER_BYTE;
    dtc_controldata_1.dtrld = 0x00U;
    dtc_controldata_1.dtsar = (uint16_t) &Port8Table0;
    dtc_controldata_1.dtdar = (uint16_t) PORT8_address;
    /* Set DTCD2 */
    dtc_controldata_2.dtccr = _00_DTC_TRANSFER_MODE_NORMAL | _00_DTC_DATA_SIZE_8BITS | _04_DTC_SOURCE_ADDR_INCREMENTED |
                              _00_DTC_DEST_ADDR_FIXED | _10_DTC_CHAIN_TRANSFER_ENABLE;
    dtc_controldata_2.dtbls = _01_DTCD2_TRANSFER_BLOCKSIZE;
    dtc_controldata_2.dtcct = _00_DTCD2_TRANSFER_BYTE;
    dtc_controldata_2.dtrld = 0x00U;
    dtc_controldata_2.dtsar = (uint16_t) &Port7Table0;
    dtc_controldata_2.dtdar = (uint16_t) PORT7_address;
    /* Set DTCD3 */
    dtc_controldata_3.dtccr = _00_DTC_TRANSFER_MODE_NORMAL | _00_DTC_DATA_SIZE_8BITS | _04_DTC_SOURCE_ADDR_INCREMENTED |
                              _00_DTC_DEST_ADDR_FIXED | _10_DTC_CHAIN_TRANSFER_ENABLE;
    dtc_controldata_3.dtbls = _01_DTCD3_TRANSFER_BLOCKSIZE;
    dtc_controldata_3.dtcct = _00_DTCD3_TRANSFER_BYTE;
    dtc_controldata_3.dtrld = 0x00U;
    dtc_controldata_3.dtsar = (uint16_t) &Port6Table0;
    dtc_controldata_3.dtdar = (uint16_t) PORT6_address;
    /* Set DTCD4 */
    dtc_controldata_4.dtccr = _00_DTC_TRANSFER_MODE_NORMAL | _00_DTC_DATA_SIZE_8BITS | _04_DTC_SOURCE_ADDR_INCREMENTED |
                              _00_DTC_DEST_ADDR_FIXED | _00_DTC_CHAIN_TRANSFER_DISABLE;
    dtc_controldata_4.dtbls = _01_DTCD4_TRANSFER_BLOCKSIZE;
    dtc_controldata_4.dtcct = _00_DTCD4_TRANSFER_BYTE;
    dtc_controldata_4.dtrld = 0x00U;
    dtc_controldata_4.dtsar = (uint16_t) &Port5Table0;
    dtc_controldata_4.dtdar = (uint16_t) PORT5_address;
}

/***********************************************************************************************************************
* Function Name: R_DTCD0_Start
* Description  : This function enables DTCD0 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DTCD0_Start(void)
{
    DTCEN4 |= _20_DTC_TMRJ0_ACTIVATION_ENABLE;
}

/***********************************************************************************************************************
* Function Name: R_DTCD0_Stop
* Description  : This function disables DTCD0 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DTCD0_Stop(void)
{
    DTCEN4 &= (uint8_t)~_20_DTC_TMRJ0_ACTIVATION_ENABLE;
}

/* Start user code for adding. Do not edit comment generated here */

// in case the config gets overwritten by the tool
void BACKUP_R_DTC_Create(void)
{
    /* Enable input clock supply */
    DTCEN = 1U;
    /* Disable all DTC channels operation */
    DTCEN0 = 0x00U;
    DTCEN1 = 0x00U;
    DTCEN2 = 0x00U;
    DTCEN3 = 0x00U;
    DTCEN4 = 0x00U;
    DTCEN5 = 0x00U;
    /* Set base address */
    DTCBAR = 0xFBU;
    /* Set DTCD0 */
    dtc_vectortable[34] = 0x40U;
    dtc_controldata_0.dtccr = _00_DTC_TRANSFER_MODE_NORMAL | _00_DTC_DATA_SIZE_8BITS | _04_DTC_SOURCE_ADDR_INCREMENTED |
                              _00_DTC_DEST_ADDR_FIXED | _10_DTC_CHAIN_TRANSFER_ENABLE;
    dtc_controldata_0.dtbls = _01_DTCD0_TRANSFER_BLOCKSIZE;
    dtc_controldata_0.dtcct = _00_DTCD0_TRANSFER_BYTE;
    dtc_controldata_0.dtrld = _00_DTCD0_TRANSFER_BYTE;
    dtc_controldata_0.dtsar = (uint16_t) &Port9Table0;
    dtc_controldata_0.dtdar = (uint16_t) PORT9_address;
    /* Set DTCD1 */
    dtc_controldata_1.dtccr = _00_DTC_TRANSFER_MODE_NORMAL | _00_DTC_DATA_SIZE_8BITS | _04_DTC_SOURCE_ADDR_INCREMENTED |
                              _00_DTC_DEST_ADDR_FIXED | _10_DTC_CHAIN_TRANSFER_ENABLE;
    dtc_controldata_1.dtbls = _01_DTCD1_TRANSFER_BLOCKSIZE;
    dtc_controldata_1.dtcct = _00_DTCD1_TRANSFER_BYTE;
    dtc_controldata_1.dtrld = 0x00U;
    dtc_controldata_1.dtsar = (uint16_t) &Port8Table0;
    dtc_controldata_1.dtdar = (uint16_t) PORT8_address;
    /* Set DTCD2 */
    dtc_controldata_2.dtccr = _00_DTC_TRANSFER_MODE_NORMAL | _00_DTC_DATA_SIZE_8BITS | _04_DTC_SOURCE_ADDR_INCREMENTED |
                              _00_DTC_DEST_ADDR_FIXED | _10_DTC_CHAIN_TRANSFER_ENABLE;
    dtc_controldata_2.dtbls = _01_DTCD2_TRANSFER_BLOCKSIZE;
    dtc_controldata_2.dtcct = _00_DTCD2_TRANSFER_BYTE;
    dtc_controldata_2.dtrld = 0x00U;
    dtc_controldata_2.dtsar = (uint16_t) &Port7Table0;
    dtc_controldata_2.dtdar = (uint16_t) PORT7_address;
    /* Set DTCD3 */
    dtc_controldata_3.dtccr = _00_DTC_TRANSFER_MODE_NORMAL | _00_DTC_DATA_SIZE_8BITS | _04_DTC_SOURCE_ADDR_INCREMENTED |
                              _00_DTC_DEST_ADDR_FIXED | _10_DTC_CHAIN_TRANSFER_ENABLE;
    dtc_controldata_3.dtbls = _01_DTCD3_TRANSFER_BLOCKSIZE;
    dtc_controldata_3.dtcct = _00_DTCD3_TRANSFER_BYTE;
    dtc_controldata_3.dtrld = 0x00U;
    dtc_controldata_3.dtsar = (uint16_t) &Port6Table0;
    dtc_controldata_3.dtdar = (uint16_t) PORT6_address;
    /* Set DTCD4 */
    dtc_controldata_4.dtccr = _00_DTC_TRANSFER_MODE_NORMAL | _00_DTC_DATA_SIZE_8BITS | _04_DTC_SOURCE_ADDR_INCREMENTED |
                              _00_DTC_DEST_ADDR_FIXED | _00_DTC_CHAIN_TRANSFER_DISABLE;
    dtc_controldata_4.dtbls = _01_DTCD4_TRANSFER_BLOCKSIZE;
    dtc_controldata_4.dtcct = _00_DTCD4_TRANSFER_BYTE;
    dtc_controldata_4.dtrld = 0x00U;
    dtc_controldata_4.dtsar = (uint16_t) &Port5Table0;
    dtc_controldata_4.dtdar = (uint16_t) PORT5_address;
}
/* End user code. Do not edit comment generated here */
