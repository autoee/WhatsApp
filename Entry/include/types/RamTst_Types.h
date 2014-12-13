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
#ifndef RAMTST_TYPES_H
#define RAMTST_TYPES_H

/* ============================ [ INCLUDES  ] ====================================================== */
#include "Std_Types.h"
#ifdef __cplusplus
namespace autosar {
extern "C" {
#endif
/* ============================ [ MACROS    ] ====================================================== */
/* ============================ [ TYPES     ] ====================================================== */
/* This container holds all of the available test algorithms for the specific microcontroller.
 *   Each test algorithm is selected ON or OFF before compiling so that only the desired test algorithms
 *  are in the compiled code.
 */
typedef struct
{
/* Preprocessor switch to select the Abraham Test ON or OFF */
	boolean RamTstAbrahamTestSelected ;
/* Preprocessor switch to select the Checkerboard Test ON or OFF */
	boolean RamTstCheckerboardTestSelected ;
/* Preprocessor switch to select the Galpat Test ON or OFF */
	boolean RamTstGalpatTestSelected ;
/* Preprocessor switch to select the March Test ON or OFF */
	boolean RamTstMarchTestSelected ;
/* Preprocessor switch to select the Transparent Galpat Test ON or OFF */
	boolean RamTstTranspGalpatTestSelected ;
/* Preprocessor switch to select the Walking Path Test ON or OFF */
	boolean RamTstWalkPathTestSelected ;
} RamTst_AlgorithmsType ;

/* Policy regading destruction or non-destruction of memory content. */
typedef enum
{
	RAMTST_TESTPOLICY_RAMTEST_DESTRUCTIVE,
	RAMTST_TESTPOLICY_RAMTEST_NON_DESTRUCTIVE
} RamTst_TestPolicyType ;

/* This container holds the description for one block of RAM.  For each RAM block to be tested
 *  by a given algorithm, there is one container which describes the block.  Multiple instances
 *  of this container are included in each container RamTst_AlgParams.
 */
typedef struct
{
/* ID of the RAM block */
	uint16 RamTstBlockId ;
/* Constraint: It must be larger than the RamTstStartAddress. */
/* End Address of the RAM block. */
	uint32 RamTstEndAddress ;
/* Pattern to be filled into each memory cell after destructive test of this block. */
	uint32 RamTstFillPattern ;
/* Constraint: It must be smaller than the RamTstEndAddress. */
/* Start Address of the RAM block. */
	uint32 RamTstStartAddress ;
	RamTst_TestPolicyType RamTstTestPolicy ;
} RamTst_BlockParamsType ;

/* This is the algorithm for which this RamTstAlgParams set is defined. Note that the same algorithm
 *  can be used in more than one RamTstAlgParams.
 */
typedef enum
{
	RAMTST_ABRAHAM_TEST,
	RAMTST_CHECKERBOARD_TEST,
	RAMTST_GALPAT_TEST,
	RAMTST_MARCH_TEST,
	RAMTST_TRANSP_GALPAT_TEST,
	RAMTST_WALK_PATH_TEST
} RamTst_AlgorithmType ;

/* This container holds parameters for configuring an algorithm.  For each algorithm selected in
 *  the RamTst_Algorithms container there can be one or more RamTstAlgParams containers. The multiplicity
 *  of the included container RamTstBlockParams depends on the number of separate blocks of RAM
 *  which are defined for the particular test configuration.
 */
typedef struct
{
	RamTst_BlockParamsType* RamTstBlockParams ;
/* This is the identifier by which this RamTstAlgParams set can be selected. */
	uint8 RamTstAlgParamsId ;
/* Constraint: Only the algorithms selected by RamTstCommon/ RamTstAlgorithms can be used. */
	RamTst_AlgorithmType RamTstAlgorithm ;
/* This is the absolute maximum value for the number of cells that NUMBER_OF_TESTED_CELLS and MAX_NUMBER_OF_TESTED_CELLS
 *  can be.
 */
	uint32 RamTstExtNumberOfTestedCells ;
/* This is the maximum value for the number of cells that can be tested in one cycle of a background
 *  test.
 */
	uint32 RamTstMaxNumberOfTestedCells ;
/* "RamTst_BlockParams"
 *                                                         calculationFormula = Count of RamTstBlockParams
 *  contained in this RamTstAlgParams.
 */
/* Number of RAM blocks configured using the container */
	uint16 RamTstNumberOfBlocks ;
/* This is the initial value for a RAM variable, which can be changed by the function "RamTst_ChangeNumberOfTestedCells"
 */
	uint32 RamTstNumberOfTestedCells ;
} RamTst_AlgParamsType ;

/* This function will be called from abackground test after finishing the RAM test without an error. */
/* TODO: 
 * typedef void (*RamTst_TestCompletedNotificationType)(void);
 */

/* This function will be called from a background test if an error occurs during the RAM test. */
/* TODO: 
 * typedef void (*RamTst_TestErrorNotificationType)(void);
 */

/* This container specifies configuration parameters which are set at pre-compile or link time. */
typedef struct
{
	RamTst_AlgParamsType* RamTstAlgParams ;
/* This is the identifier for the default "RamTstAlgParams" valid after the "RamTst_Init(..)" function.
 *  It is the initial value for a RAM variable which could be changed by the function "RamTst_SelectAlgParams".
 */
	uint8 RamTstDefaultAlgParamsId ;
/* Minimum number of tested cells for one cyle of a background test, as defined by implementer. */
	uint32 RamTstMinNumberOfTestedCells ;
/* calculationFormula = count of the container RamTst_AlgParams */
/* Number of configured parameter sets for the available test algorithms. */
	uint8 RamTstNumberOfAlgParamSets ;
	RamTst_TestCompletedNotificationType RamTstTestCompletedNotification ;
	RamTst_TestErrorNotificationType RamTstTestErrorNotification ;
} RamTst_ConfigParamsType ;

/* This container holds a list of all available functions in the RamTst module.  Each function
 *  is turned ON or OFF before compiling so that only the desired functions and test algorithms
 *  are in the compiled code.
 */
typedef struct
{
	RamTst_AlgorithmsType* RamTstAlgorithms ;
	RamTst_ConfigParamsType* RamTstConfigParams ;
/* Preprocessor switch to disable / enable the function "RamTst_Allow". */
	boolean RamTstAllowApi ;
/* Preprocessor switch to disable / enable the function "RamTst_ChangeNumberOfTestedCells". */
	boolean RamTstChangeNumOfTestedCellsApi ;
/* ON or OFF */
/* Preprocessor switch to select the development error tracer (DET) */
	boolean RamTstDevErrorDetect ;
/* Preprocessor switch to disable / enable the function "RamTst_GetAlgParams". */
	boolean RamTstGetAlgParamsApi ;
/* "RamTst_GetExecutionStatus" */
/* Preprocessor switch to disable / enable the function */
	boolean RamTstGetExecutionStatusApi ;
/* Preprocessor switch to disable / enable the function "RamTst_GetNumberOfTestedCells". */
	boolean RamTstGetNumberOfTestedCellsApi ;
/* "RamTst_GetTestAlgorithm" */
/* Preprocessor switch to disable / enable the function */
	boolean RamTstGetTestAlgorithmApi ;
/* "RamTst_GetTestResult" */
/* Preprocessor switch to disable / enable the function */
	boolean RamTstGetTestResultApi ;
/* "RamTst_GetTestResultPerBlock" */
/* Preprocessor switch to disable / enable the function */
	boolean RamTstGetTestResultPerBlockApi ;
/* "RamTst_GetVersionInfo" */
/* Preprocessor switch to disable / enable the function */
	boolean RamTstGetVersionInfoApi ;
/* Preprocessor switch to disable / enable the function "RamTst_Resume". */
	boolean RamTstResumeApi ;
/* "RamTst_RunFullTest" */
/* Preprocessor switch to disable / enable the function */
	boolean RamTstRunFullTestApi ;
/* "RamTst_RunPartialTest" */
/* Preprocessor switch to disable / enable the function */
	boolean RamTstRunPartialTestApi ;
/* Preprocessor switch to disable / enable the function "RamTst_SelectAlgParams". */
	boolean RamTstSelectAlgParamsApi ;
/* "RamTst_Stop" */
/* Preprocessor switch to disable / enable the function */
	boolean RamTstStopApi ;
/* Preprocessor switch to disable / enable the function "RamTst_Suspend". */
	boolean RamTstSuspendApi ;
} RamTst_CommonType ;

/* Container for the references to DemEventParameter elements which shall be invoked using the
 *  API Dem_ReportErrorStatus in case the corresponding error occurs. The EventId is taken from
 *  the referenced DemEventParameter's DemEventId value.
 */
typedef struct
{
/* Reference to the DemEventParameter which shall be issued when the error "RAM failure" has occurred.
 */
/* /AUTOSAR/EcucDefs/Dem/DemConfigSet/DemEventParameter */
	Dem_EventParameterType* RAMTST_E_RAM_FAILURE ;
} RamTst_DemEventParameterRefsType ;

/* Container holding all RamTst specific published information parameter. */
typedef struct
{
/* Size of RAM cells (in bits) which can be tested individually by the given implementation. */
	uint8 RamTstCellSize ;
} RamTst_PublishedInformationType ;

/* ============================ [ DATAS     ] ====================================================== */
/* ============================ [ DECLARES  ] ====================================================== */
/* ============================ [ LOCALS    ] ====================================================== */
/* ============================ [ FUNCTIONS ] ====================================================== */
#ifdef __cplusplus
}}  /* name space */
#endif
#endif /* RAMTST_TYPES_H */

