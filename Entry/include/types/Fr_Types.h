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
#ifndef FR_TYPES_H
#define FR_TYPES_H

/* ============================ [ INCLUDES  ] ====================================================== */
#include "Std_Types.h"
#ifdef __cplusplus
namespace autosar {
extern "C" {
#endif
/* ============================ [ MACROS    ] ====================================================== */
/* ============================ [ TYPES     ] ====================================================== */
/* Specifies the absolute timer configuration parameters of the Fr. */
typedef struct
{
/* Contains the index of an absolute timer contained in Fr on a certain FlexRay CC. */
	uint8 FrAbsTimerIdx ;
} Fr_AbsoluteTimerType ;

/* Container for the references to DemEventParameter elements which shall be invoked using the
 *  API Dem_ReportErrorStatus API in case the corresponding error occurs. The EventId is taken
 *  from the referenced DemEventParameter's DemEventId value. The standardized errors are provided
 *  in the container and can be extended by vendor specific error references.
 */
typedef struct
{
/* Reference to DEM event Id that is reported for FlexRay */
/* controller hardware test failure. If this parameter is not configured, no event reporting happens. */
/* /AUTOSAR/EcucDefs/Dem/DemConfigSet/DemEventParameter */
	Dem_EventParameterType* FrDemCtrlTestResultRef ;
} Fr_ControllerDemEventParameterRefsType ;

/* FIFO Frame Id range acceptance criteria. */
typedef struct
{
/* Last FrameId of this range that will be accepted by the FIFO. */
	uint16 FrRangeMax ;
/* First FrameId of this range that will be accepted by the FIFO. */
	uint16 FrRangeMin ;
} Fr_RangeType ;

/* FIFO channel admittance criteria. */
typedef enum
{
	FR_CHANNEL_A,
	FR_CHANNEL_AB,
	FR_CHANNEL_B
} Fr_ChannelsType ;

/* One First In First Out (FIFO) queued receive structure, defining the admittance criteria to
 *  the FIFO, and mandating the ability to admit messages into the FIFO based on Message Id filtering
 *  criteria.
 */
typedef struct
{
	Fr_RangeType* FrRange ;
/* Determines whether or not frames received in the dynamic segment that don't contain a message
 *  ID will be admitted into the FIFO.
 */
	boolean FrAdmitWithoutMessageId ;
/* FIFO cycle counter acceptance criteria. */
	uint8 FrBaseCycle ;
	Fr_ChannelsType FrChannels ;
/* Remark: Values 1,2,4,8,16,32,64 are valid only for FlexRay Protocol 2.1 Rev A compliance. */
/* FIFO cylce counter acceptance criteria. Valid values are  1,2,4,5,8,10,16,20,32,40,50,64. */
	uint8 FrCycleRepetition ;
/* Fifo Depth. */
	uint16 FrFifoDepth ;
/* FIFO message identifier acceptance criteria (Mask filter). */
	uint16 FrMsgIdMask ;
/* FIFO message identifier acceptance criteria (Match filter). */
	uint16 FrMsgIdMatch ;
} Fr_FifoType ;

/* Channels to which the node is connected. */
typedef enum
{
	FR_CHANNEL_A,
	FR_CHANNEL_AB,
	FR_CHANNEL_B
} Fr_PChannelsType ;

/* Number of samples per microtick. Remark: Allowed range N1SAMPLES, N2SAMPLES for FlexRay Protocol
 *  3.0 compliance.
 */
typedef enum
{
	FR_PSAMPLESPERMICROTICK_N1SAMPLES,
	FR_PSAMPLESPERMICROTICK_N2SAMPLES,
	FR_PSAMPLESPERMICROTICK_N4SAMPLES
} Fr_PSamplesPerMicrotickType ;

/* Channel used by the node to send a wakeup pattern. */
typedef enum
{
	FR_CHANNEL_A,
	FR_CHANNEL_B
} Fr_PWakeupChannelType ;

/* Duration of a microtick. */
typedef enum
{
	FR_PDMICROTICK_T100NS,
	FR_PDMICROTICK_T12_5NS,
	FR_PDMICROTICK_T25NS,
	FR_PDMICROTICK_T50NS
} Fr_PdMicrotickType ;

/* Configuration of the individual controller. */
typedef struct
{
	Fr_AbsoluteTimerType* FrAbsoluteTimer ;
	Fr_ControllerDemEventParameterRefsType* FrControllerDemEventParameterRefs ;
	Fr_FifoType* FrFifo ;
/* Determines index of CC within Fr. */
	uint8 FrCtrlIdx ;
/* Boolean flag that controls the transition to the POC:halt state due to a clock synchronization
 *  errors. If set to true, the CC is allowed to transition to POC:halt. If set to false, the CC
 *  will not transition to the POC:halt state but will enter or remain in the POC:normal passive
 *  state (self healing would still be possible)
 */
	boolean FrPAllowHaltDueToClock ;
/* Number of consecutive even/odd cycle pairs that must have valid clock correction terms before
 *  the CC will be allowed to transition from the POC:normal passive state to POC:normal active
 *  state. If set to zero, the CC is not allowed to transition from POC:normal passive to POC:normal
 *  active
 */
	uint8 FrPAllowPassiveToActive ;
/* Implementation Type: Fr_ChannelType */
	Fr_PChannelsType FrPChannels ;
/* Remark: Upper limit 10 for FlexRay Protocol 3.0 compliance. */
/* Local cluster drift damping factor used for rate correction [Microticks]. */
	uint8 FrPClusterDriftDamping ;
/* Remark: Lower limit 14 for FlexRay Protocol 2.1 Rev. A compliance. 
 *                                                 Upper limit 136 for FlexRay Protocol 3.0 compliance.
 */
/* Value used by the receiver to calculate the difference between primary time reference point
 *  and secondary time reference point [Microticks].
 */
	uint8 FrPDecodingCorrection ;
/* Remark: Lower limit 4 for FlexRay Protocol 3.0 compliance. 
 *                                                 Remark: Upper limit 200 for FlexRay Protocol
 *  2.1 Rev A compliance.
 */
/* Value used to compensate for reception delays on the indicated channel. This covers assumed
 *  propagation delay up to cPropagationDelayMax for microticks in the range of 0.0125us to 0.05us
 *  [Microticks].
 */
	uint8 FrPDelayCompensationA ;
/* Remark: Lower limit 4 for FlexRay Protocol 3.0 compliance. 
 *                                                 Remark: Upper limit 200 for FlexRay Protocol
 *  2.1 Rev A compliance.
 */
/* Value used to compensate for reception delays on the indicated channel. This covers assumed
 *  propagation delay up to cPropagationDelayMax for microticks in the range of 0.0125us to 0.05us
 *  [Microticks].
 */
	uint8 FrPDelayCompensationB ;
/* If FrPExternalSync is set to 'true' then FrPTwoKeySlotMode must also be set to 'true'. 
 *                                                 Remarks: Set to 'false' for FlexRay Protocol
 *  2.1 Rev. A compliance.
 */
/* Flag indicating whether the node is externally synchronized (operating as time gateway sink
 *  in an TT-E cluster) or locally synchronized.
 */
	boolean FrPExternalSync ;
/* Remarks: Set to 'false' for FlexRay Protocol 2.1 Rev. A compliance. */
/* Flag indicating whether a time gateway sink node will switch to local clock operation when synchronization
 *  with the time gateway source node is lost (FrPFallBackInternal = true) or will instead go to
 *  POC:ready (FrPFallBackInternal =false).
 */
	boolean FrPFallBackInternal ;
/* ID of the key slot, i.e., the slot used to transmit the startup frame, sync frame, or designated
 *  key slot frame. If this parameter is set to zero the node does not have a key slot.
 */
	uint16 FrPKeySlotId ;
/* Remarks: This parameter maps to FlexRay Protocol 2.1 Rev. A parameter pSingleSlotEnabled. */
/* Flag indicating whether or not the node shall enter key slot only mode following startup. */
	boolean FrPKeySlotOnlyEnabled ;
/* If FrPKeySlotUsedForStartup is set to true then FrPKeySlotUsedForSync must also be set to true.
 *  If FrPTwoKeySlotMode is set to true then both FrPKeySlotUsedForSync and FrPKeySlotUsedForStartup
 *  must also be set to true.
 */
/* Flag indicating whether the key slot is used to transmit a startup frame. */
	boolean FrPKeySlotUsedForStartup ;
/* If FrPKeySlotUsedForStartup is set to true then FrPKeySlotUsedForSync must also be set to true.
 *  If FrPTwoKeySlotMode is set to true then both FrPKeySlotUsedForSync and FrPKeySlotUsedForStartup
 *  must also be set to true.
 */
/* Flag indicating whether the key slot is used to transmit a sync frame. */
	boolean FrPKeySlotUsedForSync ;
/* Remark: Upper limit 7980 for FlexRay Protocol 2.1 Rev A compliance. */
/* Number of the last minislot in which a frame transmission can start in the dynamic segment. */
	uint16 FrPLatestTx ;
/* Integer number of macroticks between the static slot boundary and the following macrotick boundary
 *  of the secondary time reference point based on the nominal macrotick duration [Macroticks].
 */
	uint8 FrPMacroInitialOffsetA ;
/* Integer number of macroticks between the static slot boundary and the following macrotick boundary
 *  of the secondary time reference point based on the nominal macrotick duration [Macroticks].
 */
	uint8 FrPMacroInitialOffsetB ;
/* and the macrotick boundary immediately following the secondary 
 *                                                 time reference point. 
 *                                                 The parameter depends on FrPDelayCompensationA
 *  and therefore it has to be set independently for each channel [Microticks].
 */
/* Number of microticks between the secondary time reference point */
	uint8 FrPMicroInitialOffsetA ;
/* and the macrotick boundary immediately following the secondary time reference point. 
 *                                                 The parameter depends on FrPDelayCompensationB
 *  and therefore it has to be set independently for each channel [Microticks].
 */
/* Number of microticks between the secondary time reference point */
	uint8 FrPMicroInitialOffsetB ;
/* Remark: Lower limit 960 for FlexRay Protocol 3.0 compliance. Upper limit 640000 for FlexRay
 *  Protocol 2.1 Rev A compliance.
 */
/* Nominal number of microticks in the communication cycle of the local node. If nodes have different
 *  microtick durations this number will differ from node to node [Microticks].
 */
	uint32 FrPMicroPerCycle ;
/* in the CHI shall take place. If FrPNmVectorEarlyUpdate is set to false, the update shall take
 *  place after the NIT. If FrPNmVectorEarlyUpdate is set to true, the update shall take place
 *  after the end of the static segment.
 *                                                 Remarks: Set to 'false' for FlexRay Protocol
 *  2.1 Rev. A compliance.
 */
/* Flag indicating when the update of the Network Management Vector */
	boolean FrPNmVectorEarlyUpdate ;
/* Magnitude of the maximum permissible offset correction value [Microticks]. Remark: Upper limit
 *  15567 for FlexRay Protocol 2.1 Rev A compliance. Remark: Lower limit 15 for FlexRay Protocol
 *  3.0 compliance.
 */
	uint16 FrPOffsetCorrectionOut ;
/* Remark: This parameter maps to FlexRay Protocol 2.1 Rev. A parameter gOffsetCorrectionStart.
 *                                                 Remark: Lower limit 9 for FlexRay Protocol 2.1
 *  Rev A compliance.
 */
/* Start of the offset correction phase within the NIT, expressed as the number of macroticks from
 *  the start of cycle [Macroticks].
 */
	uint16 FrPOffsetCorrectionStart ;
/* Maximum payload length for dynamic frames [16 bit words]. */
	uint8 FrPPayloadLengthDynMax ;
/* Remarks: This parameter maps to FlexRay Protocol 2.1 Rev. A parameter pdMaxDrift. Lower limit
 *  3 for FlexRay Protocol 
 *                                                 3.0 compliance. Upper limit 1923 for FlexRay
 *  Protocol 2.1 Rev A compliance.
 */
/* Magnitude of the maximum permissible rate correction value and the maximum drift offset between
 *  two nodes operating with unsynchronized clocks for one communication cycle [Microticks].
 */
	uint16 FrPRateCorrectionOut ;
	Fr_PSamplesPerMicrotickType FrPSamplesPerMicrotick ;
/* Remark: Set to 0 for FlexRay Protocol 2.1 Rev A compliance. */
/* ID of the second key slot, in which a second startup frame shall be sent when operating as a
 *  coldstart node in a TT-L or TT-D cluster. If this parameter is set to zero the node does not
 *  have a second key slot.
 */
	uint16 FrPSecondKeySlotId ;
/* If pTwoKeySlotMode is set to true then both pKeySlotUsedForSync and pKeySlotUsedForStartup must
 *  also be set to true. If pExternalSync is set to true then pTwoKeySlotMode must also be set
 *  to true.
 *                                                 Remark: Set to false for FlexRay Protocol 2.1
 *  Rev A compliance.
 */
/* Flag indicating whether node operates as a coldstart node in a TT-E or TT-L cluster. */
	boolean FrPTwoKeySlotMode ;
/* FrPWakeupChannel must be selected from among the channels configured by FrPChannels. */
	Fr_PWakeupChannelType FrPWakeupChannel ;
/* Remark: Lower limit 2 for FlexRay Protocol 2.1 Rev A compliance. */
/* Number of repetitions of the wakeup symbol that are combined to form a wakeup pattern when the
 *  node enters the POC:wakeup send state.
 */
	uint8 FrPWakeupPattern ;
/* Remark: Upper limit 1875 for FlexRay Protocol 2.1 Rev A compliance. 
 *                                                 Remark: Lower limit 29 for FlexRay Protocol
 *  3.0 compliance.
 */
/* Expanded range of measured clock deviation allowed for startup frames during integration [Microticks].
 */
	uint16 FrPdAcceptedStartupRange ;
/* Remark: Lower limit 1926 for FlexRay Protocol 3.0 compliance. 
 *                                                 Upper limit 1283846 for FlexRay Protocol 2.1
 *  Rev. A compliance.
 */
/* Value for the startup listen timeout and wakeup listen timeout. Although this is a node local
 *  parameter, the real time equivalent of this value should be the same for all nodes in the cluster
 *  [Microticks].
 */
	uint32 FrPdListenTimeout ;
/* Remark: Allowed range T12_5NS, T25NS, T50NS for FlexRay Protocol 3.0 compliance. */
	Fr_PdMicrotickType FrPdMicrotick ;
} Fr_ControllerType ;

/* General configuration (parameters) of the FlexRay Driver module. */
typedef struct
{
/* Enables or disables buffer reconfiguration at runtime. */
	boolean FrBufferReconfig ;
/* Maxmimum number of iterations the FlexRay controller hardware test is performed during controller
 *  initialization.
 */
	uint8 FrCtrlTestCount ;
/* on or off.
 *                                         true: Development Error Detection and Notification enabled.
 *                                         false: Development Error Detection and Notification
 *  disabled.
 */
/* Switches the Development Error Detection and Notification */
	boolean FrDevErrorDetect ;
/* Specifies the InstanceId of this module instance. If only one instance is present it shall have
 *  the Id 0.
 */
	uint8 FrIndex ;
/* Determines the maximum number of communication controllers that the driver supports. */
	uint16 FrNumCtrlSupported ;
/* accepted if no slot status error occured. */
/* If stringent check is enabled (true), received frames are only */
	boolean FrRxStringentCheck ;
/* accepted the received payload length matches the configured payload length. */
/* If stringent check is enabled (true), received frames are only */
	boolean FrRxStringentLengthCheck ;
/* Enables/disables the existence of the Fr_GetVersionInfo API. */
	boolean FrVersionInfoApi ;
} Fr_GeneralType ;

/* Configuration of the individual controllers. */
typedef struct
{
	Fr_ControllerType* FrController ;
} Fr_MultipleConfigurationType ;

/* ============================ [ DATAS     ] ====================================================== */
/* ============================ [ DECLARES  ] ====================================================== */
/* ============================ [ LOCALS    ] ====================================================== */
/* ============================ [ FUNCTIONS ] ====================================================== */
#ifdef __cplusplus
}}  /* name space */
#endif
#endif /* FR_TYPES_H */

