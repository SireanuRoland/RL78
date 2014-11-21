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
* File Name    : r_cg_elc.h
* Version      : Applilet3 for RL78/F14 V2.02.00.03 [07 Aug 2014]
* Device(s)    : R5F10PMG
* Tool-Chain   : IAR Systems iccrl78
* Description  : This file implements device driver for ELC module.
* Creation Date: 20.11.2014
***********************************************************************************************************************/

#ifndef ELC_H
#define ELC_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/*
    Event Output Destination Selection Register n (ELSELRn)
*/
/* Event link selection (ELSELn3 - ELSELn0) */
#define _00_ELC_EVENT_LINK_OFF      (0x00U) /* prohibit event link */
#define _01_ELC_EVENT_LINK_AD       (0x01U) /* link destination AD */
#define _02_ELC_EVENT_LINK_TAU00    (0x02U) /* link destination TAU00 */
#define _03_ELC_EVENT_LINK_TAU01    (0x03U) /* link destination TAU01 */
#define _04_ELC_EVENT_LINK_RJ0      (0x04U) /* link destination Timer RJ0 */
#define _05_ELC_EVENT_LINK_RD0      (0x05U) /* link destination Timer RD0 */
#define _06_ELC_EVENT_LINK_RD1      (0x06U) /* link destination Timer RD1 */
#define _07_ELC_EVENT_LINK_DA0      (0x07U) /* link destination DA0 */
#define _08_ELC_EVENT_LINK_TAU02    (0x08U) /* link destination TAU02 */
#define _09_ELC_EVENT_LINK_TAU03    (0x09U) /* link destination TAU03 */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define ELC_DESTINATION_COUNT       (26U) 

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_ELC_Create(void);
void R_ELC_Stop(uint32_t event);

/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
