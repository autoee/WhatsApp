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
#ifndef DLT_TYPES_H
#define DLT_TYPES_H

/* ============================ [ INCLUDES  ] ====================================================== */
#include "Std_Types.h"
#ifdef __cplusplus
namespace autosar {
extern "C" {
#endif
/* ============================ [ MACROS    ] ====================================================== */
/* ============================ [ TYPES     ] ====================================================== */
/* Configuration parameters controlling network and diagnostic interfaces bandwidth. If DltImplementNVRamStorage
 *  is enabled this parameters are the initial values for the NVRam. If DltImplementNVRamStorage
 *  is not set, Link-Time or Post-Build configuration shall be uesd.
 */
typedef struct
{
/* Unit: kbit per second */
/* For communication over the Dlt Communication Module the maximum bandwidth shall be set. */
	uint32 DltBandwidthForComModule ;
/* Unit: kbit per second */
/* For communication over the DCM and as follows over the diagnostic interface the maximum bandwidth
 *  shall be set.
 */
	uint32 DltBandwidthForDiagChannel ;
/* Unit: second */
/* For implementing a traffic shaping, a time window for measuring shall be provided. */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 DltTimePeriodTrafficShaping ;
} Dlt_BandwidthType ;

/* Configuration parameters for setting message filtering properties in Dlt module. */
typedef struct
{
/* ImplementationType: Dlt_MessageLogLevelType */
/* The maximum log level a received message (from SW-C to Dlt) can have. This can also be modified
 *  at runtime and stored persistently in NVRAM. If DltImplementNVRamStorage is enabled this parameter
 *  is the initial value for the corospending NVRam entry. If DltImplementNVRamStorage is not set,
 *  Link-Time or Post-Build configuration shall be uesd. The value 0 means loging is disabled.
 */
	uint8 DltDefaultMaxLogLevel ;
/* Tells if trace messages shall be forwarded by Dlt. This functionality can also be modified at
 *  runtime and changed can stored persistently in NVRAM. If DltImplementNVRamStorage is enabled
 *  this parameter is the initial value for the corresponding NVRam entry. If DltImplementNVRamStorage
 *  is not set, Link-Time or Post-Build configuration shall be used.
 */
	boolean DltDefaultTraceStatus ;
/* ImplementationType: Dlt_MessageLogLevelType */
/* The maximum log level a received message (from SW-C to Dlt) can have. This is for setting DltDefaultMaxLogLevel
 *  to factory defaults. The value 0 means loging is disabled.
 */
	uint8 DltFactoryDefaultMaxLogLevel ;
/* If DltImplementNVRamStorage is enabled this parameter is the initial value for the corospending
 *  NVRam entry. If DltImplementNVRamStorage is not set, Link-Time or Post-Build configuration
 *  shall be uesd.
 */
/* This flag gives the Dlt the instruction to filter or not to filter incoming log or trace messages.
 *  If it is not set all incoming messages are forwarded to the communication channel. So also
 *  the caller of the DltSendXXXMessage can leave the field trace_info or log_info empty.
 */
	boolean DltFilterMessages ;
} Dlt_MessageFilteringType ;

/* Determines the endianes of the CPU (Most Significant Byte). */
typedef enum
{
	DLT_HEADERPAYLOADENDIANES_BIGENDIAN,
	DLT_HEADERPAYLOADENDIANES_LITTLEENDIAN
} Dlt_HeaderPayloadEndianesType ;

/* Configuration parameters for handling the specific protocol variants. */
typedef struct
{
/* This is the name of the ECU for use within the Dlt protocol. The meaning is described in the
 *  document. This name is transimitted within the Dlt protocol. There this are 4 characters. If
 *  you want to use an number representation type this as character.
 */
	char* DltEcuId ;
	Dlt_HeaderPayloadEndianesType DltHeaderPayloadEndianes ;
/* If DltImplementNVRamStorage is enabled this parameter is the initial value for the corospending
 *  NVRam entry. If DltImplementNVRamStorage is not set, Link-Time or Post-Build configuration
 *  shall be uesd.
 */
/* Corresponds to field WEID (With ECU ID). If set ECU ID shall be placed in the header, else not. */
	boolean DltHeaderUseEcuId ;
/* If DltImplementNVRamStorage is enabled this parameter is the initial value for the corospending
 *  NVRam entry. If DltImplementNVRamStorage is not set, Link-Time or Post-Build configuration
 *  shall be uesd.
 */
/* Corresponds to field UEH (Use Extended Header). If set the Extended Header shall be attached,
 *  else not.
 */
	boolean DltHeaderUseExtendedHeader ;
/* If DltImplementNVRamStorage is enabled this parameter is the initial value for the corospending
 *  NVRam entry. If DltImplementNVRamStorage is not set, Link-Time or Post-Build configuration
 *  shall be uesd.
 */
/* Corresponds to field WSID (with Session ID). If set the Session ID shall be placed in the header,
 *  else not.
 */
	boolean DltHeaderUseSessionID ;
/* If DltImplementNVRamStorage is enabled this parameter is the initial value for the corospending
 *  NVRam entry. If DltImplementNVRamStorage is not set, Link-Time or Post-Build configuration
 *  shall be uesd.
 */
/* Corresponds to field WTMS (With Timestamp). If set the timestamp shall be placed in the header,
 *  else not.
 */
	boolean DltHeaderUseTimestamp ;
/* The maximum length of a Dlt log or trace message. */
	uint16 DltMaxMessageLength ;
/* If DltImplementNVRamStorage is enabled this parameter is the initial value for the corospending
 *  NVRam entry. If DltImplementNVRamStorage is not set, Link-Time or Post-Build configuration
 *  shall be uesd.
 */
/* If this flag is set Dlt shall use the Verbose Mode for generating the header of the transport
 *  protocol. Also it shall store the information provided by registering Context ID and Application
 *  ID (description) at runtime if flag is set. If it is not set, the Non Verbose Mode shall be
 *  used.
 */
	boolean DltUseVerboseMode ;
} Dlt_ProtocolType ;

/* The Dlt generator shall enable VFB tracing for a given hook function when there is a #define
 *  in the Dlt-VFB configuration header file for the hook function name and tracing is globally
 *  enabled.
 */
/* TODO: 
 * typedef void (*Dlt_VfbTraceFunctionType)(void);
 */

/* Flags for adding removing functionality from code. */
typedef struct
{
/* Enables/Disables development error detection. */
	boolean DltDevErrorDetect ;
/* If set the functionality for Verbose Mode shall be available. */
	boolean DltImplementAppIdContextIdQuery ;
/* If set the extended functionality for the header shall be available. */
	boolean DltImplementExtendedHeader ;
/* This flag is for code generation of Dlt. If set the functionality for filtering messages shall
 *  be included in the code.
 */
	boolean DltImplementFilterMessages ;
/* If set the functionality for storing and loading information in and from NVRam shall be availible. */
	boolean DltImplementNVRamStorage ;
/* If the remote call from functions over the Dlt in SW-C shall be available. */
	boolean DltImplementSWCInjection ;
/* If set the timestamp functionality for the header shall be available. */
	boolean DltImplementTimestamp ;
/* If set the functionality for Verbose Mode shall be available. */
	boolean DltImplementVerboseMode ;
/* If set the the header files and the implementation of VFB-trace shall be generated. */
	boolean DltImplementVfbTrace ;
/* ImplementationType: Dlt_MessageLogLevelType */
/* The log level of the log messages generated by the VFB-Trace. */
	uint8 DltVfbTraceLogLevel ;
/* Reference to the hardware free running timer of the GPT module for time stamps (if no HWFRT
 *  is applied, calls to add timestamps are ignored).
 */
/* /AUTOSAR/EcucDefs/Gpt/GptChannelConfigSet/GptChannelConfiguration */
	Gpt_ChannelConfigurationType* DltGptChannel ;
} Dlt_GeneralType ;

/* Configuration parameters for reserving memory for some internal storing and buffer. */
typedef struct
{
/* Unit: byte */
/* Buffer size for the C-init buffer. This buffer is for storing messages from other BSW modules
 *  before Dlt is initialized.
 */
	uint32 DltInitBufferSize ;
/* Unit: byte */
/* The maximum count of register able Application Ids. There shall be a table to manage registered
 *  Application IDs, this is the number of lines to hold in this table.
 */
	uint32 DltMaxCountAppIds ;
/* Unit: byte */
/* The maximum count of registrable Context Ids. There shall be a table to manage registered Context
 *  IDs, this is the number of lines to hold in this table.
 */
	uint32 DltMaxCountContextIds ;
/* Unit: byte */
/* Each Context ID belongs to a specific Application ID. Dlt shall handle the correlation between
 *  them. The table of the registered Application IDs shall hold for every Application ID several
 *  references to the proper Context IDs. This is the maximum count for Context IDs per Application
 *  ID.
 */
	uint32 DltMaxCountContextIdsPerAppId ;
/* Unit: byte */
/* Buffer size for storing Dlt messages for waiting to transmit over the Network (send buffer). */
	uint32 DltMessageBufferSize ;
} Dlt_MemoryType ;

/* Container holding the sub-structure for multiple configuration support. */
typedef struct
{
	Dlt_BandwidthType* DltBandwidth ;
	Dlt_MessageFilteringType* DltMessageFiltering ;
	Dlt_ProtocolType* DltProtocol ;
/* Reference to the NvM Block which is used to store the Dlt parameters. */
/* /AUTOSAR/EcucDefs/NvM/NvMBlockDescriptor */
	NvM_BlockDescriptorType* DltNvRamBlockRef ;
} Dlt_MultipleConfigurationContainerType ;

/* All functions to trace from the VFB by the Dlt. */
typedef struct
{
/* Example: #define Dlt_Rte WriteHook i1 p1 a Start. Also the corresponding  function shall be
 *  generated. The exact argument description for the function is to take from the provieded BSWModudulDescription
 *  from the RTE module.
 */
	Dlt_VfbTraceFunctionType DltVfbTraceFunction ;
/* Foreign reference to the BSWModuleEntry describing the trace function implementation. */
	/*TODO:BSW-MODULE-ENTRY*/void* DltBswModuleEntryRef ;
} Dlt_VfbTraceType ;

/* ============================ [ DATAS     ] ====================================================== */
/* ============================ [ DECLARES  ] ====================================================== */
/* ============================ [ LOCALS    ] ====================================================== */
/* ============================ [ FUNCTIONS ] ====================================================== */
#ifdef __cplusplus
}}  /* name space */
#endif
#endif /* DLT_TYPES_H */

