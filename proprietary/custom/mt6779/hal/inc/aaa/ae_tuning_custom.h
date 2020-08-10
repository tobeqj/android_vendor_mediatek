/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

#ifndef _AE_TUNING_CUSTOM_H
#define _AE_TUNING_CUSTOM_H

#include <isp_tuning.h>
#include "aaa/ae_param.h"
#include "camera_custom_ae_tuning.h"
#include "kd_imgsensor.h"

#define AE_CYCLE_NUM (3)

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//         P U B L I C    F U N C T I O N    D E C L A R A T I O N              //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
template <ESensorDev_T eSensorDev>
MBOOL isAEEnabled();

template <ESensorDev_T eSensorDev>
AE_PARAM_TEMP_T const& getAEParam();

template <ESensorDev_T eSensorDev>
AE_PARAM_TEMP_T const& getHDRAEParam();

template <ESensorDev_T eSensorDev>
AE_PARAM_TEMP_T const& getAUTOHDRAEParam();

template <ESensorDev_T eSensorDev>
AE_PARAM_TEMP_T const& getVTAEParam();

template <ESensorDev_T eSensorDev, CAM_SCENARIO_T eCamScenario>
AE_PARAM_TEMP_T const& getAEParamData();

template <ESensorDev_T eSensorDev>
const MINT32* getAEActiveCycle();

template <ESensorDev_T eSensorDev>
MINT32 getAECycleNum();

// New Custom AE params
template <MINT32 i4SensorDevID, MINT32 i4ModuleID, MINT32 i4LensID>
AE_CUST_PARAM_T const& getCustomAEPreParam();

template <MINT32 i4SensorDevID, MINT32 i4ModuleID, MINT32 i4LensID>
AE_CUST_PARAM_T const& getCustomAEVdoParam();

template <MINT32 i4SensorDevID, MINT32 i4ModuleID, MINT32 i4LensID>
AE_CUST_PARAM_T const& getCustomAECapParam();

template <MINT32 i4SensorDevID, MINT32 i4ModuleID, MINT32 i4LensID, CAM_SCENARIO_T eCamScenario>
AE_CUST_PARAM_T const& getCustomAEParamData();

AE_CUST_PARAM_T const& getAEModuleParamData(CAM_SCENARIO_T eCamScenario, MINT32 i4SensorDevID, MINT32 i4ModuleID, MINT32 i4LensID);

#endif
