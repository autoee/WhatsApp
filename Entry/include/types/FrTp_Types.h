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
#ifndef FRTP_TYPES_H
#define FRTP_TYPES_H

/* ============================ [ INCLUDES  ] ====================================================== */
#include "Std_Types.h"
#ifdef __cplusplus
namespace autosar {
extern "C" {
#endif
/* ============================ [ MACROS    ] ====================================================== */
/* ============================ [ TYPES     ] ====================================================== */
/* This parameter defines the Rx Service Data Unit Identifier (Sdu Id) which uniquely identifies
 *  a data transfer (inter-module communication) between FrTp and PDUR.
 */
typedef struct
{
/* ImplementationType: PduIdType */
/* This unique identifier is used for change parameter request or receive cancellation from PduR
 *  to FrTp.
 */
	uint16 FrTpRxSduId ;
/* Reference to a PDU in the global PDU structure. */
/* /AUTOSAR/EcucDefs/EcuC/EcucPduCollection/Pdu */
	EcuC_PduType* FrTpRxSduRef ;
} FrTp_RxSduType ;

/* This parameter defines the Tx Service Data Unit Identifier (Sdu Id) which uniquely identifies
 *  a data transfer (inter-module communication) between FrTp and PDUR.
 */
typedef struct
{
/* ImplementationType: PduIdType */
/* This is a unique identifier for a to be transmitted message from the PduR to the FrTp. */
	uint16 FrTpTxSduId ;
/* Reference to a PDU in the global PDU structure. */
/* /AUTOSAR/EcucDefs/EcuC/EcucPduCollection/Pdu */
	EcuC_PduType* FrTpTxSduRef ;
} FrTp_TxSduType ;

/* This container contains the connection specific parameters to transfer N-PDUs via FlexRay TP. */
typedef struct
{
	FrTp_RxSduType* FrTpRxSdu ;
	FrTp_TxSduType* FrTpTxSdu ;
/* This parameter indicates wheather the connection requires a  bandwidth limitation or not. If
 *  FrTpBandwidthLimitation=True the sender shall send a StartFrame always on the first PDU of
 *  a PDU-Pool.
 */
	boolean FrTpBandwidthLimitation ;
/* This parameter defines the Local Address for the respective connection. When the local instance
 *  is the sender, this is the Source Address within the TP frame. When the local instance is the
 *  receiver, this is the Target Address within the TP frame.
 */
	uint16 FrTpLa ;
/* This parameter defines, whether this connection is an 1:1 ('false') or an 1:n ('true') connection.
 *  If data segmentation is required this parameter is used to check whether segmentation is possible
 *  or not. If the connection is 1:n segmentation is not possible and an error will occur.
 */
	boolean FrTpMultipleReceiverCon ;
/* This parameter defines the Remote Address for the respective connection. When the local instance
 *  is the sender, this is the Target Address within the TP frame. When the local instance is the
 *  receiver, this is the Source Address within the TP frame.
 */
	uint16 FrTpRa ;
/* FrTpConnectionControlReference: */
/* This parameter defines a reference to a connection control container. */
/* /AUTOSAR/EcucDefs/FrTp/FrTpMultipleConfig/FrTpConnectionControl */
	FrTp_ConnectionControlType* FrTpConCtrlRef ;
/* This parameter defines a reference to a RxPduPool. */
/* /AUTOSAR/EcucDefs/FrTp/FrTpMultipleConfig/FrTpRxPduPool */
	FrTp_RxPduPoolType* FrTpRxPduPoolRef ;
/* This parameter defines a reference to a TxPduPool. */
/* /AUTOSAR/EcucDefs/FrTp/FrTpMultipleConfig/FrTpTxPduPool */
	FrTp_TxPduPoolType* FrTpTxPduPoolRef ;
} FrTp_ConnectionType ;

/* This parameter defines the type of acknowledgement which is used for the specific channel. */
typedef enum
{
	FRTP_ACK_WITH_RT,
	FRTP_NO
} FrTp_AckTypeType ;

/* This container contains the configuration parameters to control a FlexRay TP connection. */
typedef struct
{
	FrTp_AckTypeType FrTpAckType ;
/* This parameter defines the maximum number of trying to send a frame when a TIMEOUT AR occurs. */
	uint8 FrTpMaxAr ;
/* This parameter defines the maximum number of trying to send a frame when a TIMEOUT AS occurs. */
	uint8 FrTpMaxAs ;
/* Limits the maximal buffer size the FrTp can choose in order to limit the amount of Tx buffer
 *  that will be requested at the sender side in a segmented transfer.
 */
	uint16 FrTpMaxBufferSize ;
/* This parameter defines the maximum number of FlowControl N-PDUs with FlowState "WAIT" */
	uint8 FrTpMaxFCWait ;
/* This parameter defines the maximum number of trying to send a frame when the FrIf returns an
 *  error.
 */
	uint8 FrTpMaxFrIf ;
/* This parameter is part of the ISO 10681-2 protocol's FlowControl parameter "Bandwidth Control
 *  (BC)". It limits the number of N-Pdus the sender is allowed to transmit within a FlexRay cycle.
 */
	uint8 FrTpMaxNbrOfNPduPerCycle ;
/* This parameter defines the maximum number of retries (if retry is configured). */
	uint8 FrTpMaxRn ;
/* This parameter is part of the ISO 10681-2 protocol's FlowControl parameter "Bandwidth Control
 *  (BC)". It represents the exponent to calculate the minimum number of "Separation Cycles" the
 *  sender has to wait for the next transmission of an FrTp N-Pdu.
 */
	uint8 FrTpSCexp ;
/* This parameter defines the time in seconds the FrTp requires to transmit a corresponding FlowControl
 *  Frame. According to ISO 10681-2 this parameter is a performance requirement.
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 FrTpTimeBr ;
/* This parameter defines the time in seconds of waiting for the next try to get a Tx or Rx buffer. */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 FrTpTimeBuffer ;
/* This parameter defines the time in seconds of waiting for the next try (if retry is activated)
 *  to send via FrIf_Transmit.
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 FrTpTimeFrIf ;
/* This parameter states the timeout in seconds between the PDU transmit request of the Transport
 *  Layer to the FlexRay Interface and the corresponding confirmation of the FlexRay Interface
 *  on the receiver side (for FC or AF).
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 FrTpTimeoutAr ;
/* This parameter specifies the timeout in seconds the FrIf shall confirm a transmitted Pdu to
 *  the FrTp.
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 FrTpTimeoutAs ;
/* This parameter defines the timeout in seconds for waiting for an FC or AF on the sender side
 *  in a 1:1 connection.
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 FrTpTimeoutBs ;
/* This parameter defines the timeout value in seconds a receiver is waiting for a CF or a LF. */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 FrTpTimeoutCr ;
} FrTp_ConnectionControlType ;

/* Container to hold the PDU parameters. */
typedef struct
{
/* ImplementationType: PduIdType */
/* This is a unique identifier for a received message which is forwarded from the FrIf to the FrTp. */
	uint16 FrTpRxPduId ;
/* Reference to a PDU in the global PDU structure. */
/* /AUTOSAR/EcucDefs/EcuC/EcucPduCollection/Pdu */
	EcuC_PduType* FrTpRxPduRef ;
} FrTp_RxPduType ;

/* This container contains all Pdus that are assigned to that Pdu Pool. */
typedef struct
{
/* ImplementationType: PduInfoType */
	FrTp_RxPduType* FrTpRxPdu ;
} FrTp_RxPduPoolType ;

/* Container to hold the PDU parameters. */
typedef struct
{
/* Handle Id to be used by the FrIf to confirm the transmission of the FrTpTxPdu to the FrIf module. */
	uint16 FrTpTxConfirmationPduId ;
/* Reference to a PDU in the global PDU structure. */
/* /AUTOSAR/EcucDefs/EcuC/EcucPduCollection/Pdu */
	EcuC_PduType* FrTpTxPduRef ;
} FrTp_TxPduType ;

/* This container contains all Pdus that are assigned to that Pdu Pool. */
typedef struct
{
/* ImplementationType: PduInfoType */
	FrTp_TxPduType* FrTpTxPdu ;
} FrTp_TxPduPoolType ;

/* This container contains the general configuration parameters of the FlexRay Transport Protocol
 *  module.
 */
typedef struct
{
/* True:  Acknowledge and Retry is enabled
 *                                         False: Acknowledge and Retry is disabled
 */
/* Preprocessor switch for enabling the Acknowledgement and retry mechanisms. */
	boolean FrTpAckRt ;
/* Preprocessor switch for defining the number of concurrent channels the module supports. Up to
 *  32 channels shall be definable here.
 */
	uint8 FrTpChanNum ;
/* parameters. 
 *                                         True: ChangeParameter API is enabled 
 *                                         False: ChangeParameter API is disabled.
 */
/* Preprocessor switch for enabling the API to change FrTp communication */
	boolean FrTpChangeParamApi ;
/* True:  Development Error Detection is enabled
 *                                         False: Development Error Detection is disabled
 */
/* Preprocessor switch for enabling development error detection. */
	boolean FrTpDevErrorDetect ;
/* True: Full duplex is enabled 
 *                                         False: Fullduplex is disabled (Half duplex is enabled)
 */
/* Preprocessor switch for enabling full duplex mechanisms for all channels. */
	boolean FrTpFullDuplexEnable ;
/* This parameter contains the calling period of the TPs Main Function. The parameter is specified
 *  in seconds.
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 FrTpMainFuncCycle ;
/* True:  Transmit Cancellation is enabled
 *                                         False: Transmit Cancellation is disabled
 */
/* Preprocessor switch for enabling Transmit Cancellation. */
	boolean FrTpTransmitCancellation ;
/* True:  Transmission with unknown message length is enabled
 *                                         False: Transmission with unknown message length is disabled
 */
/* Preprocessor switch to support data transfer with unknown message length. */
	boolean FrTpUnknownMsgLength ;
/* True:  Version Info API is enabled
 *                                         False: Version Info API is disabled
 */
/* Preprocessor switch for enabling the Version info API. */
	boolean FrTpVersionInfoApi ;
} FrTp_GeneralType ;

/* This container holds one or several multiple configuration sets. */
typedef struct
{
	FrTp_ConnectionType* FrTpConnection ;
	FrTp_ConnectionControlType* FrTpConnectionControl ;
	FrTp_RxPduPoolType* FrTpRxPduPool ;
	FrTp_TxPduPoolType* FrTpTxPduPool ;
} FrTp_MultipleConfigType ;

/* ============================ [ DATAS     ] ====================================================== */
/* ============================ [ DECLARES  ] ====================================================== */
/* ============================ [ LOCALS    ] ====================================================== */
/* ============================ [ FUNCTIONS ] ====================================================== */
#ifdef __cplusplus
}}  /* name space */
#endif
#endif /* FRTP_TYPES_H */

