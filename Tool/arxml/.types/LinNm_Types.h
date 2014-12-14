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
#ifndef LINNM_TYPES_H
#define LINNM_TYPES_H

/* ============================ [ INCLUDES  ] ====================================================== */
#include "Std_Types.h"
#ifdef __cplusplus
namespace autosar {
extern "C" {
#endif
/* ============================ [ MACROS    ] ====================================================== */
/* ============================ [ TYPES     ] ====================================================== */
/* This container contains the channel specific configuration parameter of the LinNm. */
typedef struct LinNm_ChannelConfigType_tag
{
/* This reference points to the unique channel defined by the ComMChannel and provides access to
 *  the unique channel index value in ComMChannelId.
 */
/* /AUTOSAR/EcucDefs/ComM/ComMConfigSet/ComMChannel */
	ComM_ChannelType* LinNmComMNetworkHandleRef ;
} LinNm_ChannelConfigType ;

/* This container contains the global configuration parameter of the LinNm. */
typedef struct LinNm_GlobalConfigType_tag
{
	LinNm_ChannelConfigType* LinNmChannelConfig ;
/* Pre-processor switch for enabling bus synchronization support of the LinNm. This feature is
 *  required for NM Coordinator nodes only.
 */
	boolean LinNmBusSynchronizationEnabled ;
/* Pre-processor switch for enabling the Communication Control support. */
	boolean LinNmComControlEnabled ;
/* Pre-processor switch for enabling the NM COM user data support */
	boolean LinNmComUserDataSupport ;
/* Enables/disables the coordinator synchronisation support. */
	boolean LinNmCoordinatorSyncSupport ;
/* Pre-processor switch for enabling development error detection support. */
	boolean LinNmDevErrorDetect ;
/* Pre-processor switch for enabling the Node Detection feature. */
	boolean LinNmNodeDetectionEnabled ;
/* Pre-processor switch for enabling transmission of the source node identifier in NM messages. */
	boolean LinNmNodeIdEnabled ;
/* Pre-processor switch for enabling support of the Passive Mode of the LinNm. */
	boolean LinNmPassiveModeEnabled ;
/* Pre-processor switch for enabling Remote Sleep Indication support. This feature is required
 *  for NM Coordinator nodes only.
 */
	boolean LinNmRemoteSleepIndicationEnabled ;
/* Pre-processor switch for enabling the Network Management state change notification. */
	boolean LinNmStateChangeIndEnabled ;
/* Pre-processor switch for enabling the Synchronize NM feature. */
	boolean LinNmSynchronizationPointEnabled ;
/* Pre-processor switch for enabling User Data support. */
	boolean LinNmUserDataEnabled ;
/* Pre-processor switch for enabling version info API support. */
	boolean LinNmVersionInfoApi ;
} LinNm_GlobalConfigType ;

/* ============================ [ DATAS     ] ====================================================== */
/* ============================ [ DECLARES  ] ====================================================== */
/* ============================ [ LOCALS    ] ====================================================== */
/* ============================ [ FUNCTIONS ] ====================================================== */
#ifdef __cplusplus
}}  /* name space */
#endif
#endif /* LINNM_TYPES_H */

