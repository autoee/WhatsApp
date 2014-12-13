/**
 * WhatsApp - the open source AUTOSAR platform https://github.com/parai
 *
 * Copyright (C) 2014  WhatsApp <parai@foxmail.com>
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * Version: AUTOSAR 4.2.0
 * Generated by arxml.py
 */
#ifndef ETHIF_TYPES_H
#define ETHIF_TYPES_H

/* ============================ [ INCLUDES  ] ====================================================== */
#include "Std_Types.h"
#ifdef __cplusplus
namespace autosar {
extern "C" {
#endif
/* ============================ [ MACROS    ] ====================================================== */
/* ============================ [ TYPES     ] ====================================================== */
/* Maps a particular connection in the Ethernet Interface to the physical Ethernet Controller. */
typedef struct
{
/* Reference to the controller in Ethernet Driver on which this connection will be transmitted
 *  / received. Connections are specified in the Socket Adapter [9].
 */
/* /AUTOSAR/EcucDefs/Eth/EthConfigSet/EthCtrlConfig */
	Eth_CtrlConfigType* EthIfEthCtrlRef ;
/* /AUTOSAR/EcucDefs/SoAd/SoAdSocketConnection */
	SoAd_SocketConnectionType* EthIfSoAdConnectionRef ;
} EthIf_Connection2EthCtrlMappingType ;

/* Configuration of Ethernet frame owner */
typedef struct
{
/* Selects the Ethernet frame type. */
	uint16 EthIfFrameType ;
/* Selects the owner of an Ethernet frame type. The owner is a zero based index into the callback
 *  function configuration 'EthIfRxIndicationConfig'. I.e. an Ethernet frame of type IPv4 (0x800)
 *  at index 0 will call the first callback function configured in 'EthIfRxIndicationConfig'.
 */
	uint8 EthIfOwner ;
} EthIf_FrameOwnerConfigType ;

/* Specifies receive indication callback function. */
/* TODO: 
 * typedef void (*EthIf_RxIndicationFunctionType)(void);
 */

/* Configuration of receive callback functions. */
typedef struct
{
	EthIf_RxIndicationFunctionType EthIfRxIndicationFunction ;
} EthIf_RxIndicationConfigType ;

/* Specifies link state change callback function */
/* TODO: 
 * typedef void (*EthIf_TrcvLinkStateChgFunctionType)(void);
 */

/* Specifies link state change callback function */
typedef struct
{
	EthIf_TrcvLinkStateChgFunctionType EthIfTrcvLinkStateChgFunction ;
} EthIf_TrcvLinkStateChgConfigType ;

/* Specifies transmit indication callback function */
/* TODO: 
 * typedef void (*EthIf_TxConfirmationFunctionType)(void);
 */

/* Configuration of transmit indication callback functions. */
typedef struct
{
	EthIf_TxConfirmationFunctionType EthIfTxConfirmationFunction ;
} EthIf_TxConfirmationConfigType ;

/* Collecting container for all parameters with post-build configuration classes. */
typedef struct
{
	EthIf_Connection2EthCtrlMappingType* EthIfConnection2EthCtrlMapping ;
	EthIf_FrameOwnerConfigType* EthIfFrameOwnerConfig ;
	EthIf_RxIndicationConfigType* EthIfRxIndicationConfig ;
	EthIf_TrcvLinkStateChgConfigType* EthIfTrcvLinkStateChgConfig ;
	EthIf_TxConfirmationConfigType* EthIfTxConfirmationConfig ;
} EthIf_ConfigSetType ;

/* This container contains the general configuration parameters of the Ethernet Interface. */
typedef struct
{
/* Enables / Disables development error detection. */
	boolean EthIfDevErrorDetect ;
/* Enables / Disables receive interrupt. */
	boolean EthIfEnableRxInterrupt ;
/* Enables / Disables the transmit interrupt. */
	boolean EthIfEnableTxInterrupt ;
/* Specifies the period of main function EthIf_MainFunctionRx and EthIf_MainFunctionTx in seconds.
 *  Ethernet Interface does not require this information but the BSW scheduler.
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 EthIfMainFunctionPeriod ;
/* Limits the total number of transceivers. */
	uint8 EthIfMaxTrcvsTotal ;
/* Limits the total number of transmit buffers. */
	uint8 EthIfMaxTxBufsTotal ;
/* Defines header files for callback functions which shall be included in case of CDDs. Range of
 *  characters is 1.. 32.
 */
	char* EthIfPublicCddHeaderFile ;
/* period of main function EthIf_MainFunctionTx. */
/* Specifies the frequency of transceiver link state change checks in each */
	uint8 EthIfTrcvLinkStateChgMainReload ;
/* Enables / Disables version info API */
	boolean EthIfVersionInfoApi ;
/* Enables / Disables version info API macro implementation. */
	boolean EthIfVersionInfoApiMacro ;
} EthIf_GeneralType ;

/* ============================ [ DATAS     ] ====================================================== */
/* ============================ [ DECLARES  ] ====================================================== */
/* ============================ [ LOCALS    ] ====================================================== */
/* ============================ [ FUNCTIONS ] ====================================================== */
#ifdef __cplusplus
}}  /* name space */
#endif
#endif /* ETHIF_TYPES_H */

