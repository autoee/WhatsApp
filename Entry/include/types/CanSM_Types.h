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
#ifndef CANSM_TYPES_H
#define CANSM_TYPES_H

/* ============================ [ INCLUDES  ] ====================================================== */
#include "Std_Types.h"
#ifdef __cplusplus
namespace autosar {
extern "C" {
#endif
/* ============================ [ MACROS    ] ====================================================== */
/* ============================ [ TYPES     ] ====================================================== */
/* This container contains the controller IDs assigned to a CAN network. */
typedef struct
{
/* Unique handle to identify one certain CAN controller. Reference to one of the CAN controllers
 *  managed by the CanIf module.
 */
/* /AUTOSAR/EcucDefs/CanIf/CanIfCtrlDrvCfg/CanIfCtrlCfg */
	CanIf_CtrlCfgType* CanSMControllerId ;
} CanSM_ControllerType ;

/* Container for the references to DemEventParameter elements which shall be invoked using the
 *  API Dem_ReportErrorStatus API in case the corresponding error occurs. The EventId is taken
 *  from the referenced DemEventParameter's DemEventId value. The standardized errors are provided
 *  in the container and can be extended by vendor specific error references.
 */
typedef struct
{
/* Reference to configured DEM event to report bus off errors for this CAN network. */
/* /AUTOSAR/EcucDefs/Dem/DemConfigSet/DemEventParameter */
	Dem_EventParameterType* CANSM_E_BUS_OFF ;
} CanSM_DemEventParameterRefsType ;

/* This container contains the CAN network specific parameters of each CAN network */
typedef struct
{
	CanSM_ControllerType* CanSMController ;
	CanSM_DemEventParameterRefsType* CanSMDemEventParameterRefs ;
/* This threshold defines the count of bus-offs until the bus-off recovery switches from level
 *  1 (short recovery time) to level 2 (long recovery time).
 */
	uint8 CanSMBorCounterL1ToL2 ;
/* This time parameter defines in seconds the duration of the bus-off recovery time in level 1
 *  (short recovery time).
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 CanSMBorTimeL1 ;
/* This time parameter defines in seconds the duration of the bus-off recovery time in level 2
 *  (long recovery time).
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 CanSMBorTimeL2 ;
/* This parameter defines in seconds the duration of the bus-off event check. This check assesses,
 *  if the recovery has been successful after the recovery reenables the transmit path. If a new
 *  bus-off occurs during this time period, the CanSM assesses this bus-off as sequential bus-off
 *  without successful recovery. Because a bus-off only can be detected, when PDUs are transmitted,
 *  the time has to be great enough to ensure that PDUs are transmitted again (e. g. time period
 *  of the fastest cyclic transmitted PDU of the COM module / ComTxModeTimePeriodFactor).
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 CanSMBorTimeTxEnsured ;
/* This parameter shall configure, if the CanSM polls the CanIf_GetTxConfirmationState API to decide
 *  the bus-off state to be recovered instead of using the CanSMBorTimeTxEnsured parameter for
 *  this decision.
 */
	boolean CanSMBorTxConfirmationPolling ;
/* Unique handle to identify one certain CAN network. Reference to one of the network handles configured
 *  for the ComM.
 */
/* /AUTOSAR/EcucDefs/ComM/ComMConfigSet/ComMChannel */
	ComM_ChannelType* CanSMComMNetworkHandleRef ;
/* ID of the CAN transceiver assigned to the configured network handle. Reference to one of the
 *  transceivers managed by the CanIf module.
 */
/* /AUTOSAR/EcucDefs/CanIf/CanIfTrcvDrvCfg/CanIfTrcvCfg */
	CanIf_TrcvCfgType* CanSMTransceiverId ;
} CanSM_ManagerNetworkType ;

/* This container contains the global parameters of the CanSM and sub containers, which are for
 *  the CAN network specific configuration.
 */
typedef struct
{
	CanSM_ManagerNetworkType* CanSMManagerNetwork ;
/* Specifies the maximal amount of mode request repetitions without a respective mode indication
 *  from the CanIf module until the CanSM module reports a development error to the DET and tries
 *  to go back to no communication.
 */
	uint8 CanSMModeRequestRepetitionMax ;
/* Specifies in which time duration the CanSM module shall repeat mode change requests by using
 *  the API of the CanIf module.
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 CanSMModeRequestRepetitionTime ;
} CanSM_ConfigurationType ;

/* Container for general pre-compile parameters of the CanSM module */
typedef struct
{
/* Enables and disables the development error detection and notification mechanism. */
	boolean CanSMDevErrorDetect ;
/* This parameter defines the cycle time of the function CanSM_MainFunction in seconds */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 CanSMMainFunctionTimePeriod ;
/* true: version information API activated
 *                                         false: version information API deactivated
 */
/* Activate/Deactivate the version information API (CanSM_GetVersionInfo). */
	boolean CanSMVersionInfoApi ;
/* If this parameter is set to true the Can_ChangeBaudrate API shall be supported. Otherwise the
 *  API is not supported.
 */
/* The support of the Can_ChangeBaudrate API is optional. */
	boolean CanSmChangeBaudrateApi ;
} CanSM_GeneralType ;

/* ============================ [ DATAS     ] ====================================================== */
/* ============================ [ DECLARES  ] ====================================================== */
/* ============================ [ LOCALS    ] ====================================================== */
/* ============================ [ FUNCTIONS ] ====================================================== */
#ifdef __cplusplus
}}  /* name space */
#endif
#endif /* CANSM_TYPES_H */

