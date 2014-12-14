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
#ifndef FIM_TYPES_H
#define FIM_TYPES_H

/* ============================ [ INCLUDES  ] ====================================================== */
#include "Std_Types.h"
#ifdef __cplusplus
namespace autosar {
extern "C" {
#endif
/* ============================ [ MACROS    ] ====================================================== */
/* ============================ [ TYPES     ] ====================================================== */
/* The summarized EventId definition record consists of a summarized event ID and a specific EventId. */
typedef struct FiM_EventSummaryType_tag
{
/* /AUTOSAR/EcucDefs/Dem/DemConfigSet/DemEventParameter */
	Dem_EventParameterType* FiMInputSumEventRef ;
/* /AUTOSAR/EcucDefs/FiM/FiMConfigSet/FiMSummaryEventId */
	FiM_SummaryEventIdType* FiMOutputSumEventRef ;
} FiM_EventSummaryType ;

/* This container includes symbolic names of all FIDs. */
typedef struct FiM_FIDType_tag
{
/* Implementation Type: FiM_FunctionIdType. */
/* The configuration parameter is used as an ID which represents a functionality. FiMFunctionId
 *  is the unique identifier assigned during FIM configuration.
 */
	uint16 FiMFunctionId ;
} FiM_FIDType ;

typedef struct FiM_InhRefChoiceType_tag
{
} FiM_InhRefChoiceType ;

/* The configuration parameter is used for an existing DEM event and summarized events as well. */
typedef struct FiM_InhEventIdType_tag
{
	FiM_InhRefChoiceType* FiMInhRefChoice ;
} FiM_InhEventIdType ;

/* The configuration parameter is used to specify the inhibition mask for an event - FID relation. */
typedef enum
{
	FIM_LAST_FAILED,
	FIM_NOT_TESTED,
	FIM_TESTED,
	FIM_TESTED_AND_FAILED
} FiM_InhInhibitionMaskType ;

/* This container includes all configuration parameters concerning the relationship between event
 *  and FID.
 */
typedef struct FiM_InhibitionConfigurationType_tag
{
	FiM_InhEventIdType* FiMInhEventId ;
	FiM_InhInhibitionMaskType FiMInhInhibitionMask ;
/* /AUTOSAR/EcucDefs/FiM/FiMConfigSet/FiMFID */
	FiM_FIDType* FiMInhFunctionIdRef ;
} FiM_InhibitionConfigurationType ;

/* This container defines the name of a summarized event. */
typedef struct FiM_SummaryEventIdType_tag
{
/* The summarized EventId definition record defines the existence of a summarized event with a
 *  specific name. This summarized event can be referenced in the EventSummary (as FimSummaryEventId)
 *  and Inhibition configuration (as FimInhEventId).
 */
	uint16 FiMEventSumId ;
} FiM_SummaryEventIdType ;

/* This container contains the configuration parameters and sub containers of the FiM module supporting
 *  multiple configuration sets.
 */
typedef struct FiM_ConfigSetType_tag
{
/* This record means that a particular FID that has to be disabled in case of summarized event
 *  (defined above) is to be disabled in any of the specific events. A possible solution could
 *  be assigning events as summarized events along with a list of specific events. During the configuration
 *  process the summarized event substitutes the referenced single events. 
 * 
 *                                         However, it is not outlined how this requirement is
 *  solved - whether by configuration process or by implementation within the FiM. The FiM configuration
 *  tool could also build up a suitable data structure for summarized events and deal with it in
 *  the FiM implementation.
 */
	FiM_EventSummaryType* FiMEventSummary ;
	FiM_FIDType* FiMFID ;
	FiM_InhibitionConfigurationType* FiMInhibitionConfiguration ;
	FiM_SummaryEventIdType* FiMSummaryEventId ;
} FiM_ConfigSetType ;

typedef struct FiM_GeneralType_tag
{
/* Enable or disable calibration of inhibit relations The scope of the parameter is to meet the
 *  requirement (FIM008) to have the option to calibrate inhibit data on the one hand side and
 *  also to provide the option to protect inhibit data for consistency reasons.
 */
	boolean FiMDataFixed ;
/* This configuration parameter is used to switch on or to switch off the detection of development
 *  errors during development.
 */
	boolean FiMDevErrorDetect ;
/* TRUE: the DEM informs FIM about changes of event status, 
 *                                         FALSE: the FIM polls event status from the DEM module
 *  either cyclically or on demand.
 */
/* This configuration parameter specifies the way FIM obtains status of EventIds. */
	boolean FiMEventUpdateTriggeredByDem ;
/* This configuration parameter specifies the total maximum number of links between EventIds and
 *  FIDs.
 */
	uint16 FiMMaxEventFidLinks ;
/* This configuration parameter specifies the maximum number of EventIds that can be linked to
 *  a single FID.
 */
	uint16 FiMMaxEventsPerFid ;
/* This configuration parameter specifies the maximum number of FIDs that can be linked to a single
 *  event.
 */
	uint16 FiMMaxFidsPerEvent ;
/* This configuration parameter specifies the maximum number of summarized events that can be configured.
 */
	uint16 FiMMaxSummaryEvents ;
/* This configuration parameter specifies the total maximum number of links between EventIds and
 *  summarized events.
 */
	uint16 FiMMaxSummaryLinks ;
/* This configuration parameter specifies the total maximum number of links between EventIds and
 *  FIDs plus the number of links between EventIds and summarized events.
 */
	uint16 FiMMaxTotalLinks ;
/* The AUTOSAR configuration standard is to use SI units, so this parameter is defined as float
 *  value in seconds. DEM configuration tools must convert this float value to the appropriate
 *  value format for the use in the software implementation of DEM.
 * 
 *                                         min:
 *                                         A negative value is not allowed.
 * 
 *                                         max:
 *                                         FID must be set after a maximal time of 100ms after
 *  DEM status is set.
 * 
 *                                         upperMultiplicity:
 *                                         Exactly one TaskTime must be specified per configuration.
 * 
 *                                         lowerMultiplicity:
 *                                         Exactly one TaskTime must be specified per configuration.
 */
/* Allow to configure the time for the periodic cyclic task. Please note: This configuration value
 *  shall be equal to the value in the Basic Software Scheduler configuration of the RTE module.
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 FiMTaskTime ;
/* This configuration parameter is used to switch on or to switch off the API to get the version
 *  information.
 */
	boolean FiMVersionInfoApi ;
} FiM_GeneralType ;

/* ============================ [ DATAS     ] ====================================================== */
/* ============================ [ DECLARES  ] ====================================================== */
/* ============================ [ LOCALS    ] ====================================================== */
/* ============================ [ FUNCTIONS ] ====================================================== */
#ifdef __cplusplus
}}  /* name space */
#endif
#endif /* FIM_TYPES_H */

