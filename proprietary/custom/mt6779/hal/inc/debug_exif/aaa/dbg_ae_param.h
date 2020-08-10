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

/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/
#ifndef _DBG_AE_PARAM_H_
#define _DBG_AE_PARAM_H_

typedef enum
{
    AE_TAG_KIBOPLUS = 6,
    AE_TAG_SYLVIA = 7,
    AE_TAG_LAFITE = 8
} AE_TAG_VER;


// AE debug info
#define AE_DEBUG_TAG_VERSION (AE_TAG_LAFITE)
#define AE_DEBUG_TAG_SUBVERSION (13)
#define AE_DEBUG_TAG_VERSION_DP ((AE_DEBUG_TAG_SUBVERSION << 16) | AE_DEBUG_TAG_VERSION)
#define AE_DEBUG_TAG_SIZE 2048
#define DBG_AE_PARAM_REVISION 9232001

typedef struct
{
    MUINT32 u4Size;
    MUINT32 u4IsTrue;
    MUINT8 PlineInfo[10*AE_DEBUG_TAG_SIZE];
} AE_PLINE_DEBUG_INFO_T;


typedef struct
{
    AAA_DEBUG_TAG_T Tag[AE_DEBUG_TAG_SIZE];
} AE_DEBUG_INFO_T;

enum {
//BEGIN_OF_EXIF_TAG
AE_TAG_DEBUG_VERSION = 0,
AE_TAG_AE_MODE,
AE_TAG_PRV_INDEX,
AE_TAG_PRV_INDEXF,
AE_TAG_PRV_SHUTTER_TIME,
AE_TAG_PRV_SENSOR_GAIN,
AE_TAG_PRV_ISP_GAIN,
AE_TAG_PRV_ISO_REAL,
AE_TAG_PRV_FRAME_RATE,
AE_TAG_PRV_FLARE,
AE_TAG_PRV_FLARE_GAIN,
AE_TAG_AF_PLINE_EN,
AE_TAG_AF_ZSD_PLINE_EN,
AE_TAG_AF_SHUTTER_TIME,
AE_TAG_AF_SENSOR_GAIN,
AE_TAG_AF_ISP_GAIN,
AE_TAG_AF_ISO_REAL,
AE_TAG_AF_FRAME_RATE,
AE_TAG_AF_FLARE,
AE_TAG_AF_FLARE_GAIN,
AE_TAG_CAP_INDEX,
AE_TAG_CAP_SHUTTER_TIME,
AE_TAG_CAP_SENSOR_GAIN,
AE_TAG_CAP_ISP_GAIN,
AE_TAG_CAP_ISO_REAL,
AE_TAG_CAP_FRAME_RATE,
AE_TAG_CAP_FLARE,
AE_TAG_CAP_FLARE_GAIN,
AE_TAG_STROBE_PLINE_EN,
AE_TAG_STROBE_ZSD_PLINE_EN,
AE_TAG_FRAC_GAIN,
//Pline Info
AE_TAG_PRV_PLINE_ID,
AE_TAG_CAP_PLINE_ID,
AE_TAG_PRV_INDEXBASE,
AE_TAG_MIN_INDEX,
AE_TAG_MAX_INDEX,
AE_TAG_MIN_INDEXF,
AE_TAG_MAX_INDEXF,
AE_TAG_PRV_PLINE_MAX_BV,
AE_TAG_PRV_PLINE_MIN_BV,
AE_TAG_CAP_PLINE_MAX_BV,
AE_TAG_CAP_PLINE_MIN_BV,
AE_TAG_NVRAM_IDX,
AE_TAG_ZOOM_XOFFSET,
AE_TAG_ZOOM_XWIDTH,
AE_TAG_ZOOM_YOFFSET,
AE_TAG_ZOOM_YHEIGHT,

AE_TAG_EV_DIFF_FRAC,
AE_TAG_PRV_DELTA_INDEX,
AE_TAG_PRV_EV_RATIO,
AE_TAG_PERFRAME_EN,
AE_TAG_NOT_PERFRAME_EN,

AE_TAG_ZSD_EN,
AE_TAG_REALISO_EN,
AE_TAG_APERTURE,
AE_TAG_PRV_AETABLE_ID,
AE_TAG_CAP_AETABLE_ID,
AE_TAG_LV,
AE_TAG_REALBV,
AE_TAG_REALBVX1000,
AE_TAG_COMPBV,
AE_TAG_BV_OFFSET,
AE_TAG_AE_SCENE,
AE_TAG_EV_COM,
AE_TAG_EV_RATIO,
AE_TAG_FLICKER,
AE_TAG_FLICKER_AUTO,
AE_TAG_AEMETER,
AE_TAG_ISO_SETTING,

AE_TAG_MINI_GAIN,
AE_TAG_MAX_GAIN,
AE_TAG_1XGAIN_ISO,
AE_TAG_PRV_EXP_UINT,
AE_TAG_VIDEO_EXP_UINT,
AE_TAG_VIDEO_PRV_RATIO,
AE_TAG_CAP_EXP_UINT,
AE_TAG_CAP_PRV_RATIO,

AE_TAG_EN_FALRE_CAPTURE_THRES,
AE_TAG_EN_FLARE_VIDEO_THRES,
AE_TAG_EN_FLARE_STROBE_THRES,
AE_TAG_PRV_FLARE_OFFSET,
AE_TAG_CAP_FLARE_OFFSET,
AE_TAG_CAP_FLARE_THRES,
AE_TAG_VIDEO_FLARE_OFFSET,
AE_TAG_VIDEO_FLARE_THRES,
AE_TAG_STROBE_FLARE_OFFSET,
AE_TAG_STROBE_FLARE_THRES,
AE_TAG_CAP_MAX_FLARE_THRES,
AE_TAG_CAP_MIN_FLARE_THRES,
AE_TAG_VIDEO_MAX_FLARE_THRES,
AE_TAG_VIDEO_MIN_FLARE_THRES,
AE_TAG_FLARE_STD_THR_HIGH,
AE_TAG_FLARE_STD_THR_LOW,
AE_TAG_PRV_CAP_FLARE_DIFF,
AE_TAG_FLARE_MAX_STEP_GAP_FAST,
AE_TAG_FLARE_MAX_STEP_GAP_SLOW,
AE_TAG_FLARE_MAX_STEP_GAP_LIMIT_BV,
AE_TAG_FLARE_AE_STABLE_COUNT,
AE_TAG_SW_FLARE_STD,
AE_TAG_SW_FLARE_COUNT_R,
AE_TAG_SW_FLARE_COUNT_G,
AE_TAG_SW_FLARE_COUNT_B,
AE_TAG_SW_FLARE_PIXEL_VALUE,
AE_TAG_SW_FLARE_FAST_CONVERGE,
AE_TAG_SW_FLARE_DST_VALUE,
AE_TAG_SW_FLARE_APPLY_VALUE,
AE_TAG_PRV_FALRE_WEIGHT0_7,
AE_TAG_PRV_FALRE_WEIGHT8_15,
AE_TAG_VIDEO_FALRE_WEIGHT0_7,
AE_TAG_VIDEO_FALRE_WEIGHT8_15,

AE_TAG_HIST_INFO_FULL_BRIGHTEST,
AE_TAG_LSC_FAST_CONVERGE,

// HS
AE_TAG_HISTSTRETCH_HIT,
AE_TAG_HISTSTRETCH_EN,
AE_TAG_HISTSTRETCH_WEIGHTING,
AE_TAG_HISTSTRETCH_METERING,
AE_TAG_HS_NV_ENABLE,           //bEnableHistStretch
AE_TAG_HS_NV_WEIGHT,           //u4HistStretchWeight
AE_TAG_HS_NV_PCENT,            //u4Pcent
AE_TAG_HS_NV_THD,              //u4Thd;                       // 0~255
AE_TAG_HS_NV_FLATTHD,          //u4FlatThd;                   // 0~255
AE_TAG_HS_NV_BRIGHTPCENT,      //u4FlatBrightPcent;
AE_TAG_HS_NV_DARKPCENT,        // u4FlatDarkPcent;
AE_TAG_HS_NV_FLATX1,            //sFlatRatio
AE_TAG_HS_NV_FLATY1,
AE_TAG_HS_NV_FLATX2,
AE_TAG_HS_NV_FLATY2,
AE_TAG_HS_NV_ENABLEGREYTEXT,

AE_TAG_HS_EN_FLATSKY,
AE_TAG_HS_FLATSKYEVD,
AE_TAG_HS_FLATSKYTHD,
AE_TAG_HS_BVRATIO_X1,
AE_TAG_HS_BVRATIO_Y1,
AE_TAG_HS_BVRATIO_X2,
AE_TAG_HS_BVRATIO_Y2,
AE_TAG_HS_SCENE_SUM_R,
AE_TAG_HS_SCENE_SUM_G,
AE_TAG_HS_SCENE_SUM_B,

AE_TAG_HS_STS_Y,
AE_TAG_HS_STS_FLATHIGHY,
AE_TAG_HS_STS_FLATLOWY,
AE_TAG_HS_STS_FLATPROB,
AE_TAG_HS_STS_EVD,
AE_TAG_HS_STS_THD,
AE_TAG_HS_STS_TARGET,
AE_TAG_HS_STS_LIMITBY,
AE_TAG_HS_STS_COLORDIST,
AE_TAG_HS_STS_COLORPROB,
AE_TAG_HS_STS_FLATSKYDET,

// AOE
AE_TAG_ANTIOVER_HIT,
AE_TAG_ANTIOVER_EN,
AE_TAG_ANTIOVER_METERING,

AE_TAG_AOE_NV_ENABLE,   //bEnableAntiOverExposure;
AE_TAG_AOE_NV_WEIGHT,   //u4AntiOverExpWeight;
AE_TAG_AOE_NV_PCENT,    //u4Pcent;
AE_TAG_AOE_NV_THD,      //u4Thd;
AE_TAG_AOE_NV_COEPCENT, //
AE_TAG_AOE_NV_COETHD,   //
AE_TAG_AOE_NV_BV_COMP_RATIO,
AE_TAG_AOE_NV_COEP_ENABLE,
AE_TAG_AOE_NV_COEPY_X1,
AE_TAG_AOE_NV_COEPY_Y1,
AE_TAG_AOE_NV_COEPY_X2,
AE_TAG_AOE_NV_COEPY_Y2,

AE_TAG_AOE_NV_COEPDIFF_X1,
AE_TAG_AOE_NV_COEPDIFF_Y1,
AE_TAG_AOE_NV_COEPDIFF_X2,
AE_TAG_AOE_NV_COEPDIFF_Y2,

AE_TAG_AOE_EN_BV,
AE_TAG_AOE_BV_THD_X0,
AE_TAG_AOE_BV_THD_Y0,
AE_TAG_AOE_BV_THD_X1,
AE_TAG_AOE_BV_THD_Y1,
AE_TAG_AOE_BV_THD_X2,
AE_TAG_AOE_BV_THD_Y2,

AE_TAG_AOE_EN_OERATIO,
AE_TAG_AOE_EN_HISTOE,
AE_TAG_AOE_OE_LEVEL,
AE_TAG_AOE_OE_LOWBND,
AE_TAG_AOE_OE_HIGHBND,
AE_TAG_AOE_OE_BVRATIO_X0,
AE_TAG_AOE_OE_BVRATIO_X1,

AE_TAG_AOE_STS_Y,
AE_TAG_AOE_STS_WEIGHT,
AE_TAG_AOE_STS_THD,
AE_TAG_AOE_STS_OERATIO,
AE_TAG_AOE_STS_OE_BV_P,
AE_TAG_AOE_STS_OE_RATIO_P,
AE_TAG_AOE_STS_OE_P,
AE_TAG_AOE_STS_OE_DELTAY,
AE_TAG_AOE_STS_TARGET,
AE_TAG_AOE_STS_COEP_P,
AE_TAG_AOE_STS_COEP_ORIGY,
AE_TAG_AOE_STS_COEP_PROBY,
AE_TAG_AOE_STS_COEP_ORIGDIFF,
AE_TAG_AOE_STS_COEP_PROBDIFF,
AE_TAG_AOE_STS_COE_TARGET,
AE_TAG_AOE_STS_FINAL_TARGET,
AE_TAG_AOE_STS_LIMITBY,

// ABL
AE_TAG_BACKLIGH_HIT,
AE_TAG_BACKLIGH_EN,
AE_TAG_BACKLIGH_WEIGHTING,
AE_TAG_BACKLIGH_METERING,

AE_TAG_ABL_NV_ENABLE,       //bEnableBlackLight;
AE_TAG_ABL_NV_WEIGHT,       //u4BackLightWeight;
AE_TAG_ABL_NV_PCENT,        //u4Pcent;
AE_TAG_ABL_NV_THD,          //u4Thd;
AE_TAG_ABL_NV_CENTERBND,    //u4CenterHighBnd;
AE_TAG_ABL_NV_TARGETSTRENGTH,//u4TargetStrength;
AE_TAG_ABL_NV_FGBGRATIO_X1, //sFgBgEVRatio;
AE_TAG_ABL_NV_FGBGRATIO_Y1,
AE_TAG_ABL_NV_FGBGRATIO_X2,
AE_TAG_ABL_NV_FGBGRATIO_Y2,
AE_TAG_ABL_NV_BVRATIO_X1,   //sBVRatio;
AE_TAG_ABL_NV_BVRATIO_Y1,
AE_TAG_ABL_NV_BVRATIO_X2,
AE_TAG_ABL_NV_BVRATIO_Y2,

AE_TAG_ABL_EN_ABS_DIFF,
AE_TAG_ABL_ABS_DIFF_X1,
AE_TAG_ABL_ABS_DIFF_Y1,
AE_TAG_ABL_ABS_DIFF_X2,
AE_TAG_ABL_ABS_DIFF_Y2,
AE_TAG_ABL_ABS_DIFF_BVRATIO_X1,
AE_TAG_ABL_ABS_DIFF_BVRATIO_Y1,
AE_TAG_ABL_ABS_DIFF_BVRATIO_X2,
AE_TAG_ABL_ABS_DIFF_BVRATIO_Y2,

AE_TAG_ABL_STS_Y,
AE_TAG_ABL_STS_TARGET,
AE_TAG_ABL_STS_FGBGPROB,
AE_TAG_ABL_STS_FGBGORIG,
AE_TAG_ABL_STS_BVPROB,
AE_TAG_ABL_STS_BVORIG,
AE_TAG_ABL_STS_FINALPROB,
AE_TAG_ABL_STS_LIMITBY,

// NS
AE_TAG_NS_NV_ENABLE,
AE_TAG_NS_NV_PCENT,         //u4Pcent;
AE_TAG_NS_NV_THD,           //u4Thd;
AE_TAG_NS_NV_FLATTHD,       //u4FlatThd;

AE_TAG_NS_NV_BRIGHTTONE_PCENT,
AE_TAG_NS_NV_BRIGHTTONE_THD, //u4BrightToneThdMul

AE_TAG_NS_NV_LOWBNDPCENT,   //u4LowBndPcent;
AE_TAG_NS_NV_LOWBNDTHD,     //u4LowBndThd;
AE_TAG_NS_NV_LOWBNDTHDLIMIT,//u4LowBndThdLimit;
AE_TAG_NS_NV_BRIGHTPCENT,   //u4FlatBrightPcent;
AE_TAG_NS_NV_DARKPCENT,     //u4FlatDarkPcent;
AE_TAG_NS_NV_FALT_X1,       //sFlatRatio;
AE_TAG_NS_NV_FALT_Y1,
AE_TAG_NS_NV_FALT_X2,
AE_TAG_NS_NV_FALT_Y2,
AE_TAG_NS_NV_BV_X1,         //sBVRatio;
AE_TAG_NS_NV_BV_Y1,
AE_TAG_NS_NV_BV_X2,
AE_TAG_NS_NV_BV_Y2,
AE_TAG_NS_NV_SKYENABLE,
AE_TAG_NS_NV_SKYBV_X1,
AE_TAG_NS_NV_SKYBV_Y1,
AE_TAG_NS_NV_SKYBV_X2,
AE_TAG_NS_NV_SKYBV_Y2,

AE_TAG_NS_STS_Y,
AE_TAG_NS_STS_WEIGHT,
AE_TAG_NS_STS_HIGHBNDY,
AE_TAG_NS_STS_LOWBNDY,
AE_TAG_NS_STS_FLATHIGHY,
AE_TAG_NS_STS_FLATLOWY,
AE_TAG_NS_STS_FLATPROB,
AE_TAG_NS_STS_EVD,
AE_TAG_NS_STS_THD,
AE_TAG_NS_STS_TARGET,
AE_TAG_NS_STS_LOWBND_Y,
AE_TAG_NS_STS_LOWBNDTARGET,
AE_TAG_NS_STS_BRIGHTTONE_Y,
AE_TAG_NS_STS_BRIGHTTONE_THD,
AE_TAG_NS_STS_BRIGHTTONE_TARGET,
AE_TAG_NS_STS_BVORIG,
AE_TAG_NS_STS_BVPROB,
AE_TAG_NS_STS_CDF,
AE_TAG_NS_STS_CDFPROB,
AE_TAG_NS_STS_LIMITBY,

AE_TAG_METERV4P0_EN,
//MainTarget
AE_TAG_MAINTARGET_HIT,
AE_TAG_MT_ENABLE,
AE_TAG_MT_WEIGHT,
AE_TAG_MT_TARGETBV_X1,
AE_TAG_MT_TARGETBV_Y1,
AE_TAG_MT_TARGETBV_X2,
AE_TAG_MT_TARGETBV_Y2,
AE_TAG_MT_COLORWT_EN,
AE_TAG_MT_COLORWT_X1,
AE_TAG_MT_COLORWT_Y1,
AE_TAG_MT_COLORWT_X2,
AE_TAG_MT_COLORWT_Y2,
AE_TAG_MT_COLOSUP_R,
AE_TAG_MT_COLOSUP_G,
AE_TAG_MT_COLOSUP_B,
AE_TAG_MT_COLOSUP_X1,
AE_TAG_MT_COLOSUP_Y1,
AE_TAG_MT_COLOSUP_X2,
AE_TAG_MT_COLOSUP_Y2,
AE_TAG_MT_STS_Y,
AE_TAG_MT_STS_TARGET,
AE_TAG_MT_STS_PRETARGET,
AE_TAG_MT_STS_WEIGHT,

//HSv4p0
AE_TAG_HSV4P0_HIT,
AE_TAG_HSV4P0_ENABLE,
AE_TAG_HSV4P0_WEIGHT,
AE_TAG_HSV4P0_BVRATIO_0,
AE_TAG_HSV4P0_BVRATIO_1,
AE_TAG_HSV4P0_BVRATIO_2,
AE_TAG_HSV4P0_BVRATIO_3,
AE_TAG_HSV4P0_PCNT_0,
AE_TAG_HSV4P0_PCNT_1,
AE_TAG_HSV4P0_PCNT_2,
AE_TAG_HSV4P0_PCNT_3,
AE_TAG_HSV4P0_EVD_0,
AE_TAG_HSV4P0_EVD_1,
AE_TAG_HSV4P0_EVD_2,
AE_TAG_HSV4P0_EVD_3,
AE_TAG_HSV4P0_EVD_4,
AE_TAG_HSV4P0_BV0THD_0,
AE_TAG_HSV4P0_BV0THD_1,
AE_TAG_HSV4P0_BV0THD_2,
AE_TAG_HSV4P0_BV0THD_3,
AE_TAG_HSV4P0_BV0THD_4,
AE_TAG_HSV4P0_BV1THD_0,
AE_TAG_HSV4P0_BV1THD_1,
AE_TAG_HSV4P0_BV1THD_2,
AE_TAG_HSV4P0_BV1THD_3,
AE_TAG_HSV4P0_BV1THD_4,
AE_TAG_HSV4P0_BV2THD_0,
AE_TAG_HSV4P0_BV2THD_1,
AE_TAG_HSV4P0_BV2THD_2,
AE_TAG_HSV4P0_BV2THD_3,
AE_TAG_HSV4P0_BV2THD_4,
AE_TAG_HSV4P0_BV3THD_0,
AE_TAG_HSV4P0_BV3THD_1,
AE_TAG_HSV4P0_BV3THD_2,
AE_TAG_HSV4P0_BV3THD_3,
AE_TAG_HSV4P0_BV3THD_4,
AE_TAG_HSV4P0_DYNWT_EN,
AE_TAG_HSV4P0_DYNWT_X1,
AE_TAG_HSV4P0_DYNWT_Y1,
AE_TAG_HSV4P0_DYNWT_X2,
AE_TAG_HSV4P0_DYNWT_Y2,
AE_TAG_HSV4P0_STS_Y,
AE_TAG_HSV4P0_STS_EVD,
AE_TAG_HSV4P0_STS_THD,
AE_TAG_HSV4P0_STS_WEIGHT,
AE_TAG_HSV4P0_STS_TARGET,
AE_TAG_HSV4P0_STS_PRETARGET,
AE_TAG_HSV4P0_STS_GREENRATIO,
AE_TAG_HSV4P0_STS_GC_RATIO,

//////////////////////////
AE_TAG_EN_PRE_INDEX,
AE_TAG_EN_ROTATE_WEIGHT,
AE_TAG_EN_EV0_STROBE_TRIGGER,
AE_TAG_EN_LOCK_CAM_PRE_METERING_WIN,
AE_TAG_EN_LOCK_VDO_PRE_METERING_WIN,
AE_TAG_EN_LOCK_VDO_REC_METERING_WIN,
AE_TAG_EN_PREAF_LOCK_AE,

AE_TAG_METERING_STABLE_MAX,
AE_TAG_METERING_STABLE_MIN,
AE_TAG_X_BLOCK_NO,
AE_TAG_Y_BLOCK_NO,
AE_TAG_FACE_HIGH_BOUND,
AE_TAG_FACE_LOW_BOUND,
AE_TAG_FACE_NS_LOW_BOUND,
AE_TAG_METERING_HIGH_BOUND,
AE_TAG_METERING_LOW_BOUND,

AE_TAG_CWV,
AE_TAG_SE_CWV,
AE_TAG_AVG,
AE_TAG_SE_AVG,
AE_TAG_CENTRAL_Y,
AE_TAG_CWR,
AE_TAG_CWV_FINAL_TARGET,
AE_TAG_AE_TARGET,
AE_TAG_STROBE_TARGET,
AE_TAG_INIT_INDEX,
AE_TAG_MIN_CWV_RECMD,
AE_TAG_MAX_CWV_RECMD,

// face
AE_TAG_EN_FACE_AE,
AE_TAG_METERFACE_HIT,
AE_TAG_FACE_Y,
AE_TAG_FACE_WEIGHTING,

AE_TAG_FACE_Y_LOWBOUND,
AE_TAG_FACE_Y_HIGHBOUND,
AE_TAG_FACE_BVRATIO_LOWBOUND,
AE_TAG_FACE_BVRATIO_HIGHBOUND,
AE_TAG_FACE_TMPFDY_LOWBOUND,
AE_TAG_FACE_TMPFDY_HIGHBOUND,
AE_TAG_FACE_LOST_MAXCNT,
AE_TAG_FACE_EN_LOCSIZE,
AE_TAG_FACE_SIZE_X1,
AE_TAG_FACE_SIZE_Y1,
AE_TAG_FACE_SIZE_X2,
AE_TAG_FACE_SIZE_Y2,
AE_TAG_FACE_LOC_X1,
AE_TAG_FACE_LOC_Y1,
AE_TAG_FACE_LOC_X2,
AE_TAG_FACE_LOC_Y2,
AE_TAG_FACE_PROB,
AE_TAG_FACE_STS_LOC,
AE_TAG_FACE_STS_SIZE,
AE_TAG_FACE_STS_FINDCNT,
AE_TAG_FACE_STS_LOSTCNT,

AE_TAG_FACE_20_EN,
AE_TAG_FACE_20_FACE_Y,
AE_TAG_FACE_20_CWV,
AE_TAG_FACE_20_BV_L,
AE_TAG_FACE_20_BV_H,
AE_TAG_FACE_20_REAL_BV_X1000,
AE_TAG_FACE_20_METER_FD_TARGET,
AE_TAG_FACE_20_NORMAL_TARGET,
AE_TAG_FACE_20_FINAL_TARGET,
AE_TAG_FACE_20_FACE_TARGET,
AE_TAG_FACE_20_LCE_LINK,
AE_TAG_FACE_20_LCE_MAX_GAIN,
AE_TAG_FACE_20_IS_FRONT,
AE_TAG_FACE_20_IS_SIDE,
AE_TAG_FACE_20_IS_OT,
AE_TAG_FACE_20_CASE_NUMBER,
AE_TAG_FACE_20_FOUND_CNT,
AE_TAG_FACE_20_FAIL_CNT,
AE_TAG_FACE_20_STABLE_CNT,
AE_TAG_FACE_20_FACE_AE_STABLE,
AE_TAG_FACE_20_FACE_AE_STABLE_INDEX,
AE_TAG_FACE_20_FACE_AE_STABLE_CWV,
AE_TAG_FACE_20_FACE_AE_STABLE_CWR,
AE_TAG_FACE_20_FACE_AE_STABLE_INTHD,
AE_TAG_FACE_20_FACE_AE_STABLE_OUTTHD,
AE_TAG_FACE_20_FACE_AE_STABLE_XLOW,
AE_TAG_FACE_20_FACE_AE_STABLE_XHI,
AE_TAG_FACE_20_FACE_AE_STABLE_YLOW,
AE_TAG_FACE_20_FACE_AE_STABLE_YHI,
AE_TAG_FACE_20_AE_COMP,
AE_TAG_FACE_20_MULTI_FACE_NUM,
AE_TAG_FACE_20_MULTI_FACEY_0,
AE_TAG_FACE_20_MULTI_FACEY_1,
AE_TAG_FACE_20_MULTI_FACEY_2,
AE_TAG_FACE_20_MULTI_FACEY_3,
AE_TAG_FACE_20_MULTI_FACEY_4,
AE_TAG_FACE_20_MULTI_FACEY_5,
AE_TAG_FACE_20_MULTI_FACEY_6,
AE_TAG_FACE_20_MULTI_FACEY_7,
AE_TAG_FACE_20_MULTI_FACEY_8,
AE_TAG_FACE_20_MULTI_LMY_0,
AE_TAG_FACE_20_MULTI_LMY_1,
AE_TAG_FACE_20_MULTI_LMY_2,
AE_TAG_FACE_20_MULTI_LMY_3,
AE_TAG_FACE_20_MULTI_LMY_4,
AE_TAG_FACE_20_MULTI_LMY_5,
AE_TAG_FACE_20_MULTI_LMY_6,
AE_TAG_FACE_20_MULTI_LMY_7,
AE_TAG_FACE_20_MULTI_LMY_8,
AE_TAG_FACE_20_MULTI_FDY_0,
AE_TAG_FACE_20_MULTI_FDY_1,
AE_TAG_FACE_20_MULTI_FDY_2,
AE_TAG_FACE_20_MULTI_FDY_3,
AE_TAG_FACE_20_MULTI_FDY_4,
AE_TAG_FACE_20_MULTI_FDY_5,
AE_TAG_FACE_20_MULTI_FDY_6,
AE_TAG_FACE_20_MULTI_FDY_7,
AE_TAG_FACE_20_MULTI_FDY_8,
AE_TAG_FACE_20_MULTI_SORT_FDY_0,
AE_TAG_FACE_20_MULTI_SORT_FDY_1,
AE_TAG_FACE_20_MULTI_SORT_FDY_2,
AE_TAG_FACE_20_MULTI_SORT_FDY_3,
AE_TAG_FACE_20_MULTI_SORT_FDY_4,
AE_TAG_FACE_20_MULTI_SORT_FDY_5,
AE_TAG_FACE_20_MULTI_SORT_FDY_6,
AE_TAG_FACE_20_MULTI_SORT_FDY_7,
AE_TAG_FACE_20_MULTI_SORT_FDY_8,
AE_TAG_FACE_20_PARA_LOCK_MAX_CNT,
AE_TAG_FACE_20_PARA_TEMPORAL_SMOOTH,
AE_TAG_FACE_20_PARA_OT_LOCK_UPPER,
AE_TAG_FACE_20_PARA_OT_LOCK_LOWER,
AE_TAG_FACE_20_PARA_CONT_TRUST_CNT,
AE_TAG_FACE_20_PARA_LOC_SIZE_CHECK,
AE_TAG_FACE_20_PARA_IN_STALE_THD,
AE_TAG_FACE_20_PARA_OUT_B2T_STALE_THD,
AE_TAG_FACE_20_PARA_OUT_D2T_STALE_THD,
AE_TAG_FACE_20_PARA_IN_TO_OUT_THD_MAX_CNT,
AE_TAG_FACE_20_PARA_SIDE_FACE_LOCK,
AE_TAG_FACE_20_PARA_LIMIT_STABLE_THD_EN,
AE_TAG_FACE_20_PARA_LIMIT_STABLE_THD_NUM,
AE_TAG_FACE_20_PARA_RECONVERGE_WHEN_FACE_CHANGE,
AE_TAG_FACE_20_PARA_MOTION_LOCK_RATIO,
AE_TAG_FACE_20_PARA_IMPULSE_LOCK_CNT,
AE_TAG_FACE_20_PARA_IMPULSE_UPPER_THD,
AE_TAG_FACE_20_PARA_IMPULSE_LOWER_THD,
AE_TAG_FACE_20_PARA_ROP_TRUST_CNT,
AE_TAG_FACE_20_PARA_RECONVERGE_WHEN_SIZE_CHANGE_RAT,
AE_TAG_FACE_20_PARA_RECONVERGE_WHEN_POS_CHANGE_DIST,
AE_TAG_FACE_20_PARA_RECONVERGE_WHEN_FACE_AF_DONE,
AE_TAG_FACE_20_PARA_MULTI_WEIGHT_EN,
AE_TAG_FACE_20_PARA_MULTI_WEIGHT_PRIOR,
AE_TAG_FACE_20_PARA_MULTI_WEIGHT_0,
AE_TAG_FACE_20_PARA_MULTI_WEIGHT_1,
AE_TAG_FACE_20_PARA_MULTI_WEIGHT_2,
AE_TAG_FACE_20_PARA_MULTI_WEIGHT_3,
AE_TAG_FACE_20_PARA_MULTI_WEIGHT_4,
AE_TAG_FACE_20_PARA_MULTI_WEIGHT_5,
AE_TAG_FACE_20_PARA_MULTI_WEIGHT_6,
AE_TAG_FACE_20_PARA_MULTI_WEIGHT_7,
AE_TAG_FACE_20_PARA_MULTI_WEIGHT_8,
AE_TAG_FACE_20_PARA_LM_EXT_RATIO_W,
AE_TAG_FACE_20_PARA_LM_EXT_RATIO_H,
AE_TAG_FACE_20_PARA_LM_TRUST_ROP,
AE_TAG_FACE_20_PARA_LM_SMOOTH_XY,
AE_TAG_FACE_20_PARA_LM_SMOOTH_SIZE,
AE_TAG_FACE_20_PARA_LM_SMOOTH_OVERLAP,
AE_TAG_FACE_20_PARA_LM_SMOOTH_BUFLEN,
AE_TAG_FACE_20_PARA_LM_SMOOTH_LEVEL,
AE_TAG_FACE_20_PARA_LM_SMOOTH_MOMENTUM,
AE_TAG_FACE_20_PARA_LM_MIX_WEIGHT_PCENT,
AE_TAG_FACE_20_PARA_LM_CV_THD,
AE_TAG_FACE_20_PARA_LM_CV_BV,
AE_TAG_FACE_20_PARA_LM_ROP_THD,
AE_TAG_FACE_20_PARA_LM_ROP_BV,
AE_TAG_FACE_20_PARA_LM_BK_EN,
AE_TAG_FACE_20_PARA_LM_BK_CVthd,
AE_TAG_FACE_20_PARA_LM_BK_FYthd,
AE_TAG_FACE_20_PARA_LM_BK_Weight,
AE_TAG_FACE_20_PARA_LM_BK_BV,
AE_TAG_FACE_CNT,
AE_TAG_FACE0_XLOW,
AE_TAG_FACE0_XHI,
AE_TAG_FACE0_YLOW,
AE_TAG_FACE0_YHI,
AE_TAG_FACE0_WEIGHT,
AE_TAG_FACE0_FULLY,
AE_TAG_FACE0_CENTERY,
AE_TAG_FACE1_XLOW,
AE_TAG_FACE1_XHI,
AE_TAG_FACE1_YLOW,
AE_TAG_FACE1_YHI,
AE_TAG_FACE1_WEIGHT,
AE_TAG_FACE1_FULLY,
AE_TAG_FACE1_CENTERY,
AE_TAG_FACE2_XLOW,
AE_TAG_FACE2_XHI,
AE_TAG_FACE2_YLOW,
AE_TAG_FACE2_YHI,
AE_TAG_FACE2_WEIGHT,
AE_TAG_FACE2_FULLY,
AE_TAG_FACE2_CENTERY,
AE_TAG_FACE3_XLOW,
AE_TAG_FACE3_XHI,
AE_TAG_FACE3_YLOW,
AE_TAG_FACE3_YHI,
AE_TAG_FACE3_WEIGHT,
AE_TAG_FACE3_FULLY,
AE_TAG_FACE3_CENTERY,
AE_TAG_FACE4_XLOW,
AE_TAG_FACE4_XHI,
AE_TAG_FACE4_YLOW,
AE_TAG_FACE4_YHI,
AE_TAG_FACE4_WEIGHT,
AE_TAG_FACE4_FULLY,
AE_TAG_FACE4_CENTERY,
AE_TAG_FACE5_XLOW,
AE_TAG_FACE5_XHI,
AE_TAG_FACE5_YLOW,
AE_TAG_FACE5_YHI,
AE_TAG_FACE5_WEIGHT,
AE_TAG_FACE5_FULLY,
AE_TAG_FACE5_CENTERY,
AE_TAG_FACE6_XLOW,
AE_TAG_FACE6_XHI,
AE_TAG_FACE6_YLOW,
AE_TAG_FACE6_YHI,
AE_TAG_FACE6_WEIGHT,
AE_TAG_FACE6_FULLY,
AE_TAG_FACE6_CENTERY,
AE_TAG_FACE7_XLOW,
AE_TAG_FACE7_XHI,
AE_TAG_FACE7_YLOW,
AE_TAG_FACE7_YHI,
AE_TAG_FACE7_WEIGHT,
AE_TAG_FACE7_FULLY,
AE_TAG_FACE7_CENTERY,
AE_TAG_FACE8_XLOW,
AE_TAG_FACE8_XHI,
AE_TAG_FACE8_YLOW,
AE_TAG_FACE8_YHI,
AE_TAG_FACE8_WEIGHT,
AE_TAG_FACE8_FULLY,
AE_TAG_FACE8_CENTERY,
AE_TAG_FACE0_WEIGHT2K,
AE_TAG_FACE1_WEIGHT2K,
AE_TAG_FACE2_WEIGHT2K,
AE_TAG_FACE3_WEIGHT2K,
AE_TAG_FACE4_WEIGHT2K,
AE_TAG_FACE5_WEIGHT2K,
AE_TAG_FACE6_WEIGHT2K,
AE_TAG_FACE7_WEIGHT2K,
AE_TAG_FACE8_WEIGHT2K,
AE_TAG_FACE_20_SCALE0_XLOW,
AE_TAG_FACE_20_SCALE0_XHI,
AE_TAG_FACE_20_SCALE0_YLOW,
AE_TAG_FACE_20_SCALE0_YHI,
AE_TAG_FACE_20_SCALE1_XLOW,
AE_TAG_FACE_20_SCALE1_XHI,
AE_TAG_FACE_20_SCALE1_YLOW,
AE_TAG_FACE_20_SCALE1_YHI,
AE_TAG_FACE_20_SCALE2_XLOW,
AE_TAG_FACE_20_SCALE2_XHI,
AE_TAG_FACE_20_SCALE2_YLOW,
AE_TAG_FACE_20_SCALE2_YHI,
AE_TAG_FACE_20_SCALE3_XLOW,
AE_TAG_FACE_20_SCALE3_XHI,
AE_TAG_FACE_20_SCALE3_YLOW,
AE_TAG_FACE_20_SCALE3_YHI,
AE_TAG_FACE_20_SCALE4_XLOW,
AE_TAG_FACE_20_SCALE4_XHI,
AE_TAG_FACE_20_SCALE4_YLOW,
AE_TAG_FACE_20_SCALE4_YHI,
AE_TAG_FACE_20_SCALE5_XLOW,
AE_TAG_FACE_20_SCALE5_XHI,
AE_TAG_FACE_20_SCALE5_YLOW,
AE_TAG_FACE_20_SCALE5_YHI,
AE_TAG_FACE_20_SCALE6_XLOW,
AE_TAG_FACE_20_SCALE6_XHI,
AE_TAG_FACE_20_SCALE6_YLOW,
AE_TAG_FACE_20_SCALE6_YHI,
AE_TAG_FACE_20_SCALE7_XLOW,
AE_TAG_FACE_20_SCALE7_XHI,
AE_TAG_FACE_20_SCALE7_YLOW,
AE_TAG_FACE_20_SCALE7_YHI,
AE_TAG_FACE_20_SCALE8_XLOW,
AE_TAG_FACE_20_SCALE8_XHI,
AE_TAG_FACE_20_SCALE8_YLOW,
AE_TAG_FACE_20_SCALE8_YHI,
//face minimum boundary
AE_TAG_FACE_BEFEXT_XLOW,
AE_TAG_FACE_BEFEXT_XHI,
AE_TAG_FACE_BEFEXT_YLOW,
AE_TAG_FACE_BEFEXT_YHI,
//face landmark
AE_TAG_FACE_20_LANDMARK0_XLOW,
AE_TAG_FACE_20_LANDMARK0_XHI,
AE_TAG_FACE_20_LANDMARK0_YLOW,
AE_TAG_FACE_20_LANDMARK0_YHI,
AE_TAG_FACE_20_LANDMARK0_RIP,
AE_TAG_FACE_20_LANDMARK0_ROP,
AE_TAG_FACE_20_LANDMARK0_CV,
AE_TAG_FACE_20_LANDMARK0_ICS_LEFT,
AE_TAG_FACE_20_LANDMARK0_ICS_RIGHT,
AE_TAG_FACE_20_LANDMARK0_ICS_TOP,
AE_TAG_FACE_20_LANDMARK0_ICS_BOTTOM,
//face digital zoom
AE_TAG_FACE_20_DIGITAL_ZOOM_TGDOMAIN_XOFFSET,
AE_TAG_FACE_20_DIGITAL_ZOOM_TGDOMAIN_YOFFSET,
AE_TAG_FACE_20_DIGITAL_ZOOM_TGDOMAIN_WIDTH,
AE_TAG_FACE_20_DIGITAL_ZOOM_TGDOMAIN_HEIGHT,

//TGS
AE_TAG_INT_AE_EN,
AE_TAG_TG_ESC_OVEREXP_EN,
AE_TAG_TG_ESC_UNDEREXP_EN,

AE_TAG_TG_ACC_DELTA_EV_OVEREXP,
AE_TAG_TG_ACC_DELTA_EV_UNDEREXP,

//PSO
AE_TAG_PSO_LINEAR_CWV,
AE_TAG_PSO_TUNING_ACC_ENABLE,
AE_TAG_PSO_TUNING_ACC_ESC_RATIO,
AE_TAG_PSO_TUNING_CONV_DELTAEV_POSDOUND,
AE_TAG_PSO_TUNING_CONV_DELTAEV_NEGDOUND,

//temporal smooth option
AE_TAG_TEMP_SMOOTH_HS,
AE_TAG_TEMP_SMOOTH_ABL,
AE_TAG_TEMP_SMOOTH_AOE,
AE_TAG_TEMP_SMOOTH_NS,
AE_TAG_TEMP_SMOOTH_FACE,
AE_TAG_TEMP_SMOOTH_VIDEO,

AE_TAG_EN_METER_AE,
AE_TAG_METERING_EN,
AE_TAG_METERING_Y,
AE_TAG_METERING_Y_LOWBOUND,
AE_TAG_METERING_Y_HIGHBOUND,

AE_TAG_METERING_Y0,
AE_TAG_METERING_CNT,
AE_TAG_METERING0_XLOW,
AE_TAG_METERING0_XHI,
AE_TAG_METERING0_YLOW,
AE_TAG_METERING0_YHI,
AE_TAG_METERING0_WEIGHT,

AE_TAG_PRV_MAX_BLOCK_WIDTH,
AE_TAG_PRV_MAX_BLOCK_HEIGHT,
AE_TAG_STAT_XLOW,
AE_TAG_STAT_XHI,
AE_TAG_STAT_YLOW,
AE_TAG_STAT_YHI,

AE_TAG_STB_DEFAULT_IN_THD,
AE_TAG_STB_DEFAULT_OUT_THD,
AE_TAG_STB_EN_MODE_THD,
AE_TAG_STB_Video_IN_THD,
AE_TAG_STB_Video_OUT_THD,
AE_TAG_STB_Face_IN_THD,
AE_TAG_STB_Face_OUT_THD,
AE_TAG_STB_Touch_IN_THD,
AE_TAG_STB_Touch_OUT_THD,
AE_TAG_EN_TOUCH_SMOOTH,
AE_TAG_EN_TOUCH_PERFRAME,
AE_TAG_EN_TOUCH_WEIGHT,
AE_TAG_EN_BVACCRATIO,
AE_TAG_BVACC_DELTA_RATIO,
AE_TAG_BVACC_B2TEND,
AE_TAG_BVACC_B2TEND_RATIO,
AE_TAG_BVACC_B2TSTART_RATIO,

AE_TAG_CAM_MODE,
AE_TAG_OLD_AE_SMOOTH,
AE_TAG_SUB_PRE_INDEX_EN,
AE_TAG_VIDEO_DFS_EN,
AE_TAG_MAX_FPS,
AE_TAG_MIN_FPS,
AE_TAG_SENSOR_ID,
AE_TAG_AE_LOCKED,
AE_TAG_VIDEO_RECORD,
AE_TAG_AE_LIMITER,
AE_TAG_STROBE_ON,
AE_TAG_ROTATE_WEIGHTING,
AE_TAG_OBJECT_TRACKING,

// isp 6.0 flow
AE_TAG_FLOW_AE_STATE,
AE_TAG_FLOW_IS_LOCK,
AE_TAG_FLOW_IS_CALCULATE,
AE_TAG_FLOW_CYCLE_CNT,
AE_TAG_FLOW_MAGIC_NO,
AE_TAG_FLOW_DELAY_CNT,
AE_TAG_FLOW_IS_SLOW_MOTION,
AE_TAG_FLOW_IS_LIMIT,
AE_TAG_FLOW_MAIN_STATE,
AE_TAG_FLOW_SUB_STATE,
AE_TAG_FLOW_CURR_FRM_CNT,
AE_TAG_FLOW_REST_FRM_CNT,

// isp 6.0 metering
AE_TAG_ABL_STRENGTH_BYBV_EN,

AE_TAG_CS_GS_EN,
AE_TAG_CS_GS_GRTH,
AE_TAG_CS_GS_GBTH,
AE_TAG_CS_GS_GCNTRATIO_X1,
AE_TAG_CS_GS_GCNTRATIO_X2,
AE_TAG_CS_GS_GCNTRATIO_Y1,
AE_TAG_CS_GS_GCNTRATIO_Y2,
AE_TAG_CS_GS_STS_GREENCNT,
AE_TAG_CS_GS_STS_GREENRATIO,
AE_TAG_CS_GS_DETMIN,
AE_TAG_CS_GS_PROB,
AE_TAG_CS_GS_PROB_BV,
AE_TAG_CS_GS_PROB_GC,
AE_TAG_CS_GS_HS4P0_ORG_Y,
AE_TAG_CS_GS_SUP_Y,
AE_TAG_CS_GS_HS4P0_GS_Y,
AE_TAG_CS_GS_MT_ORG_Y,
AE_TAG_CS_GS_MT_GS_Y,

AE_TAG_FACE_SIZELOC_BYDR_EN,
AE_TAG_FACE_SIZELOC_DR,

AE_TAG_FBT_EN,
AE_TAG_FBT_SKP,
AE_TAG_FBT_OEP,
AE_TAG_FBT_XP_SYS,
AE_TAG_FBT_OE_SYS,
AE_TAG_FBT_DR,
AE_TAG_FBT_OETH,
AE_TAG_FBT_FDTH,
AE_TAG_FBT_FDMINTH,
AE_TAG_FBT_FDY,
AE_TAG_FBT_TARGET,

AE_TAG_PURE_AE_CWR,
AE_TAG_LINK_AE_CWR,
AE_TAG_PURE_AE_CWR_STABLE,
AE_TAG_PURE_AE_CWR_AF_STABLE,
AE_TAG_LINK_AE_CWR_STABLE,

AE_TAG_EN_LTM_LINK,
AE_TAG_LTM_OFFSET,
AE_TAG_AOE_STS_OE_ORIY,
AE_TAG_AOE_STS_OE_HBOUND,
AE_TAG_AOE_STS_OE_SEY,
AE_TAG_AOE_STS_DELTA_SEY,
AE_TAG_LTM_CT,
AE_TAG_LTM_FINAL_OFFSET,
AE_TAG_LTM_WEIGHT,
AE_TAG_LTM_FINAL_WEIGHT,

// isp 6.0 face
AE_TAG_FACE_ID0_ROP,
AE_TAG_FACE_ID1_ROP,
AE_TAG_FACE_ID2_ROP,
AE_TAG_FACE_ID3_ROP,
AE_TAG_FACE_ID4_ROP,
AE_TAG_FACE_ID5_ROP,
AE_TAG_FACE_ID6_ROP,
AE_TAG_FACE_ID7_ROP,
AE_TAG_FACE_ID8_ROP,

AE_TAG_FACE_MOTION_X0,
AE_TAG_FACE_MOTION_Y0,
AE_TAG_FACE_MOTION_X1,
AE_TAG_FACE_MOTION_Y1,
AE_TAG_FACE_MOTION_X2,
AE_TAG_FACE_MOTION_Y2,
AE_TAG_FACE_MOTION_X3,
AE_TAG_FACE_MOTION_Y3,
AE_TAG_FACE_MOTION_X4,
AE_TAG_FACE_MOTION_Y4,
AE_TAG_FACE_MOTION_X5,
AE_TAG_FACE_MOTION_Y5,
AE_TAG_FACE_MOTION_X6,
AE_TAG_FACE_MOTION_Y6,
AE_TAG_FACE_MOTION_X7,
AE_TAG_FACE_MOTION_Y7,
AE_TAG_FACE_MOTION_X8,
AE_TAG_FACE_MOTION_Y8,
AE_TAG_FACE_MOTION_X9,
AE_TAG_FACE_MOTION_Y9,

AE_TAG_FACE_LCE_LINK_EN,
AE_TAG_FACE_LOCK,
AE_TAG_FACE_LCETARGET,
AE_TAG_FACE_LCEHALFTARGET,

AE_TAG_FACE_20_MULTI_AVGFDY_0,
AE_TAG_FACE_20_MULTI_AVGFDY_1,
AE_TAG_FACE_20_MULTI_AVGFDY_2,
AE_TAG_FACE_20_MULTI_AVGFDY_3,
AE_TAG_FACE_20_MULTI_AVGFDY_4,
AE_TAG_FACE_20_MULTI_AVGFDY_5,
AE_TAG_FACE_20_MULTI_AVGFDY_6,
AE_TAG_FACE_20_MULTI_AVGFDY_7,
AE_TAG_FACE_20_MULTI_AVGFDY_8,

AE_TAG_FACE_SIZE_XLOW_0,
AE_TAG_FACE_SIZE_XHIGH_0,
AE_TAG_FACE_SIZE_YLOW_0,
AE_TAG_FACE_SIZE_YHIGH_0,
AE_TAG_FACE_SIZE_XLOW_1,
AE_TAG_FACE_SIZE_XHIGH_1,
AE_TAG_FACE_SIZE_YLOW_1,
AE_TAG_FACE_SIZE_YHIGH_1,
AE_TAG_FACE_SIZE_XLOW_2,
AE_TAG_FACE_SIZE_XHIGH_2,
AE_TAG_FACE_SIZE_YLOW_2,
AE_TAG_FACE_SIZE_YHIGH_2,
AE_TAG_FACE_SIZE_XLOW_3,
AE_TAG_FACE_SIZE_XHIGH_3,
AE_TAG_FACE_SIZE_YLOW_3,
AE_TAG_FACE_SIZE_YHIGH_3,
AE_TAG_FACE_SIZE_XLOW_4,
AE_TAG_FACE_SIZE_XHIGH_4,
AE_TAG_FACE_SIZE_YLOW_4,
AE_TAG_FACE_SIZE_YHIGH_4,

AE_TAG_FACE_LTM_0_XLOW,
AE_TAG_FACE_LTM_0_XHI,
AE_TAG_FACE_LTM_0_YLOW,
AE_TAG_FACE_LTM_0_YHI,
AE_TAG_FACE_LTM_BRIGHT_AVG_0,
AE_TAG_FACE_LTM_PROTECT_PERCENT,
AE_TAG_FACE_LTM_BRIGHT_AVG_PERCENT,

// isp 6.0 smooth
AE_TAG_SMOOTH_STATUS,
AE_TAG_PREV_DELTA_IDX,
AE_TAG_PREV2_DELTA_IDX,
AE_TAG_PREV3_DELTA_IDX,
AE_TAG_DELTA_INDEX_FULL,
AE_TAG_NON_LINEAR_CWV_RATIO,
AE_TAG_NON_LINEAR_AVG_RATIO,
AE_TAG_OVER_PROB,
AE_TAG_OVER_PL_PROB,
AE_TAG_PL_PROB,
AE_TAG_FDY,
AE_TAG_ONE_SHOT,
AE_TAG_STABLE_CASE,
AE_TAG_STABLE_CASE_C,

// Folivora effect
AE_TAG_FOLIVORA_ENABLE,
AE_TAG_FOLIVORA_IS_IN_EFFECT,
AE_TAG_FOLIVORA_IS_MOVING,
AE_TAG_FOLIVORA_IS_B_MOVING,
AE_TAG_FOLIVORA_IS_F_MOVING,
AE_TAG_FOLIVORA_IS_IN_TRACKING,
AE_TAG_FOLIVORA_HESITATE,
AE_TAG_FOLIVORA_B_TICKET,
AE_TAG_FOLIVORA_F_TICKET,
AE_TAG_FOLIVORA_C_TICKET,
AE_TAG_FOLIVORA_B_VALUE,
AE_TAG_FOLIVORA_C_VALUE,
AE_TAG_FOLIVORA_MOVING_QUANTITY,
AE_TAG_FOLIVORA_B_MOVING_TH,
AE_TAG_FOLIVORA_F_MOVING_TH,
AE_TAG_FOLIVORA_MOVING_QUANTITY_TH,
AE_TAG_FOLIVORA_DARK_TH,
AE_TAG_FOLIVORA_DARK_MIN_MOTION,
AE_TAG_FOLIVORA_TRACKING_TH,
AE_TAG_FOLIVORA_HESITATE_TH,

//Butterfly effect
AE_TAG_BF_ENABLE,
AE_TAG_BF_IN_EFFECT,
AE_TAG_BF_OVER,
AE_TAG_BF_ORG_STABLE,
AE_TAG_BF_STABLE,
AE_TAG_BF_PRE_DEV_STABLE,
AE_TAG_BF_PRE_DEV_INDEX,
AE_TAG_BF_B_V,
AE_TAG_BF_C_V,
AE_TAG_BF_B_TICKET,
AE_TAG_BF_C_TICKET,
AE_TAG_BF_RightAfterWT,
AE_TAG_BF_SYNC,
AE_TAG_BF_MAPPING,
AE_TAG_BF_TH,
AE_TAG_BF_SPEED,
AE_TAG_BF_CHANG_CNT,
AE_TAG_BF_UPBOUND,
AE_TAG_BF_LOWBOUND,


AE_TAG_INFO_0,         // AE tag info_0
AE_TAG_INFO_1,         // AE tag info_1
AE_TAG_INFO_2,         // AE tag info_2
AE_TAG_INFO_3,         // AE tag info_3
AE_TAG_INFO_4,         // AE tag info_3
AE_TAG_STABLE,

// 3hdr
AE_TAG_LE_SHUTTER_TIME,
AE_TAG_LE_SENSOR_GAIN,
AE_TAG_LE_ISP_GAIN, 
AE_TAG_ME_SHUTTER_TIME, 
AE_TAG_ME_SENSOR_GAIN, 
AE_TAG_ME_ISP_GAIN, 
AE_TAG_SE_SHUTTER_TIME, 
AE_TAG_SE_SENSOR_GAIN, 
AE_TAG_SE_ISP_GAIN, 
AE_TAG_3HDR_REAL_RATIO, 
AE_TAG_3HDR_PRE_RATIO, 
AE_TAG_3HDR_CUR_RATIO,
AE_TAG_3HDR_TARGET_RATIO,
AE_TAG_3HDR_LE_CNT,
AE_TAG_3HDR_SE_CNT,
AE_TAG_3HDR_BVX1000, 
AE_TAG_3HDR_CWV, 
AE_TAG_3HDR_FDY_AAO, 
AE_TAG_3HDR_FDY_SENSOR, 
AE_TAG_3HDR_TARGET, 
AE_TAG_3HDR_BVTARGET, 
AE_TAG_3HDR_HSTARGET, 
AE_TAG_3HDR_FACE_MULTI_WEIGHT_PRIOR,
AE_TAG_HDR_FACE_Y_LOWBOUND,
AE_TAG_HDR_FACE_Y_HIGHBOUND,
AE_TAG_HDR_FACE_BVRATIO_LOWBOUND,
AE_TAG_HDR_FACE_BVRATIO_HIGHBOUND,
AE_TAG_3HDR_BV4FDTARGET_0, 
AE_TAG_3HDR_BV4FDTARGET_1, 
AE_TAG_3HDR_BV4FDTARGET_2, 
AE_TAG_3HDR_BV4FDTARGET_3, 
AE_TAG_3HDR_FDTARGET_0, 
AE_TAG_3HDR_FDTARGET_1, 
AE_TAG_3HDR_FDTARGET_2, 
AE_TAG_3HDR_FDTARGET_3, 

AE_TAG_3HDR_MAX_RATIO, 
AE_TAG_3HDR_OE1_BIN_RATIO, 
AE_TAG_3HDR_OE2_BIN_RATIO, 

AE_TAG_3HDR_OE1_PCNT_0, 
AE_TAG_3HDR_OE1_PCNT_1, 
AE_TAG_3HDR_OE1_PCNT_2, 
AE_TAG_3HDR_OE1_PCNT_3, 
AE_TAG_3HDR_OE1_PCNT_4, 
AE_TAG_3HDR_OE1_RATIO_MOVE_0, 
AE_TAG_3HDR_OE1_RATIO_MOVE_1, 
AE_TAG_3HDR_OE1_RATIO_MOVE_2, 
AE_TAG_3HDR_OE1_RATIO_MOVE_3, 
AE_TAG_3HDR_OE1_RATIO_MOVE_4, 

AE_TAG_3HDR_OE2_PCNT_0, 
AE_TAG_3HDR_OE2_PCNT_1, 
AE_TAG_3HDR_OE2_PCNT_2, 
AE_TAG_3HDR_OE2_PCNT_3, 
AE_TAG_3HDR_OE2_PCNT_4, 
AE_TAG_3HDR_OE2_RATIO_MOVE_0, 
AE_TAG_3HDR_OE2_RATIO_MOVE_1, 
AE_TAG_3HDR_OE2_RATIO_MOVE_2, 
AE_TAG_3HDR_OE2_RATIO_MOVE_3, 
AE_TAG_3HDR_OE2_RATIO_MOVE_4, 

AE_TAG_3HDR_RATIO_STABLE, 
AE_TAG_3HDR_RATIO_STABLE_CNT, 

AE_TAG_3HDR_RATIO_IN_THD, 
AE_TAG_3HDR_RATIO_OUT_THD, 

AE_TAG_3HDR_3EXP_TRANS_METHOD,

AE_TAG_3HDR_YHIST_0,
AE_TAG_3HDR_YHIST_1,
AE_TAG_3HDR_YHIST_2,
AE_TAG_3HDR_YHIST_3,
AE_TAG_3HDR_YHIST_4,
AE_TAG_3HDR_YHIST_5,
AE_TAG_3HDR_YHIST_6,
AE_TAG_3HDR_YHIST_7,
AE_TAG_3HDR_YHIST_8,
AE_TAG_3HDR_YHIST_9,
AE_TAG_3HDR_YHIST_10,
AE_TAG_3HDR_YHIST_11,
AE_TAG_3HDR_YHIST_12,
AE_TAG_3HDR_YHIST_13,
AE_TAG_3HDR_YHIST_14,
AE_TAG_3HDR_YHIST_15,
AE_TAG_3HDR_YHIST_16,
AE_TAG_3HDR_YHIST_17,
AE_TAG_3HDR_YHIST_18,
AE_TAG_3HDR_YHIST_19,
AE_TAG_3HDR_YHIST_20,
AE_TAG_3HDR_YHIST_21,
AE_TAG_3HDR_YHIST_22,
AE_TAG_3HDR_YHIST_23,
AE_TAG_3HDR_YHIST_24,
AE_TAG_3HDR_YHIST_25,
AE_TAG_3HDR_YHIST_26,
AE_TAG_3HDR_YHIST_27,
AE_TAG_3HDR_YHIST_28,
AE_TAG_3HDR_YHIST_29,
AE_TAG_3HDR_YHIST_30,
AE_TAG_3HDR_YHIST_31,
AE_TAG_3HDR_YHIST_32,
AE_TAG_3HDR_YHIST_33,
AE_TAG_3HDR_YHIST_34,
AE_TAG_3HDR_YHIST_35,
AE_TAG_3HDR_YHIST_36,
AE_TAG_3HDR_YHIST_37,
AE_TAG_3HDR_YHIST_38,
AE_TAG_3HDR_YHIST_39,
AE_TAG_3HDR_YHIST_40,
AE_TAG_3HDR_YHIST_41,
AE_TAG_3HDR_YHIST_42,
AE_TAG_3HDR_YHIST_43,
AE_TAG_3HDR_YHIST_44,
AE_TAG_3HDR_YHIST_45,
AE_TAG_3HDR_YHIST_46,
AE_TAG_3HDR_YHIST_47,
AE_TAG_3HDR_YHIST_48,
AE_TAG_3HDR_YHIST_49,
AE_TAG_3HDR_YHIST_50,
AE_TAG_3HDR_YHIST_51,
AE_TAG_3HDR_YHIST_52,
AE_TAG_3HDR_YHIST_53,
AE_TAG_3HDR_YHIST_54,
AE_TAG_3HDR_YHIST_55,
AE_TAG_3HDR_YHIST_56,
AE_TAG_3HDR_YHIST_57,
AE_TAG_3HDR_YHIST_58,
AE_TAG_3HDR_YHIST_59,
AE_TAG_3HDR_YHIST_60,
AE_TAG_3HDR_YHIST_61,
AE_TAG_3HDR_YHIST_62,
AE_TAG_3HDR_YHIST_63,
AE_TAG_3HDR_YHIST_64,
AE_TAG_3HDR_YHIST_65,
AE_TAG_3HDR_YHIST_66,
AE_TAG_3HDR_YHIST_67,
AE_TAG_3HDR_YHIST_68,
AE_TAG_3HDR_YHIST_69,
AE_TAG_3HDR_YHIST_70,
AE_TAG_3HDR_YHIST_71,
AE_TAG_3HDR_YHIST_72,
AE_TAG_3HDR_YHIST_73,
AE_TAG_3HDR_YHIST_74,
AE_TAG_3HDR_YHIST_75,
AE_TAG_3HDR_YHIST_76,
AE_TAG_3HDR_YHIST_77,
AE_TAG_3HDR_YHIST_78,
AE_TAG_3HDR_YHIST_79,
AE_TAG_3HDR_YHIST_80,
AE_TAG_3HDR_YHIST_81,
AE_TAG_3HDR_YHIST_82,
AE_TAG_3HDR_YHIST_83,
AE_TAG_3HDR_YHIST_84,
AE_TAG_3HDR_YHIST_85,
AE_TAG_3HDR_YHIST_86,
AE_TAG_3HDR_YHIST_87,
AE_TAG_3HDR_YHIST_88,
AE_TAG_3HDR_YHIST_89,
AE_TAG_3HDR_YHIST_90,
AE_TAG_3HDR_YHIST_91,
AE_TAG_3HDR_YHIST_92,
AE_TAG_3HDR_YHIST_93,
AE_TAG_3HDR_YHIST_94,
AE_TAG_3HDR_YHIST_95,
AE_TAG_3HDR_YHIST_96,
AE_TAG_3HDR_YHIST_97,
AE_TAG_3HDR_YHIST_98,
AE_TAG_3HDR_YHIST_99,
AE_TAG_3HDR_YHIST_100,
AE_TAG_3HDR_YHIST_101,
AE_TAG_3HDR_YHIST_102,
AE_TAG_3HDR_YHIST_103,
AE_TAG_3HDR_YHIST_104,
AE_TAG_3HDR_YHIST_105,
AE_TAG_3HDR_YHIST_106,
AE_TAG_3HDR_YHIST_107,
AE_TAG_3HDR_YHIST_108,
AE_TAG_3HDR_YHIST_109,
AE_TAG_3HDR_YHIST_110,
AE_TAG_3HDR_YHIST_111,
AE_TAG_3HDR_YHIST_112,
AE_TAG_3HDR_YHIST_113,
AE_TAG_3HDR_YHIST_114,
AE_TAG_3HDR_YHIST_115,
AE_TAG_3HDR_YHIST_116,
AE_TAG_3HDR_YHIST_117,
AE_TAG_3HDR_YHIST_118,
AE_TAG_3HDR_YHIST_119,
AE_TAG_3HDR_YHIST_120,
AE_TAG_3HDR_YHIST_121,
AE_TAG_3HDR_YHIST_122,
AE_TAG_3HDR_YHIST_123,
AE_TAG_3HDR_YHIST_124,
AE_TAG_3HDR_YHIST_125,
AE_TAG_3HDR_YHIST_126,
AE_TAG_3HDR_YHIST_127,

AE_TAG_3HDR_RSV_0,
AE_TAG_3HDR_RSV_1,
AE_TAG_3HDR_RSV_2,
AE_TAG_3HDR_RSV_3,
AE_TAG_3HDR_RSV_4,
AE_TAG_3HDR_RSV_5,
AE_TAG_3HDR_RSV_6,
AE_TAG_3HDR_RSV_7,
AE_TAG_3HDR_RSV_8,
AE_TAG_3HDR_RSV_9,
AE_TAG_3HDR_RSV_10,
AE_TAG_3HDR_RSV_11,
AE_TAG_3HDR_RSV_12,
AE_TAG_3HDR_RSV_13,
AE_TAG_3HDR_RSV_14,
AE_TAG_3HDR_RSV_15,
AE_TAG_3HDR_RSV_16,
AE_TAG_3HDR_RSV_17,
AE_TAG_3HDR_RSV_18,
AE_TAG_3HDR_RSV_19,
AE_TAG_3HDR_RSV_20,
AE_TAG_3HDR_RSV_21,
AE_TAG_3HDR_RSV_22,
AE_TAG_3HDR_RSV_23,
AE_TAG_3HDR_RSV_24,
AE_TAG_3HDR_RSV_25,
AE_TAG_3HDR_RSV_26,
AE_TAG_3HDR_RSV_27,
AE_TAG_3HDR_RSV_28,
AE_TAG_3HDR_RSV_29,
AE_TAG_3HDR_RSV_30,
AE_TAG_3HDR_RSV_31,
AE_TAG_3HDR_RSV_32,
AE_TAG_3HDR_RSV_33,
AE_TAG_3HDR_RSV_34,
AE_TAG_3HDR_RSV_35,
AE_TAG_3HDR_RSV_36,
AE_TAG_3HDR_RSV_37,
AE_TAG_3HDR_RSV_38,
AE_TAG_3HDR_RSV_39,
AE_TAG_3HDR_RSV_40,
AE_TAG_3HDR_RSV_41,
AE_TAG_3HDR_RSV_42,
AE_TAG_3HDR_RSV_43,
AE_TAG_3HDR_RSV_44,
AE_TAG_3HDR_RSV_45,
AE_TAG_3HDR_RSV_46,
AE_TAG_3HDR_RSV_47,
AE_TAG_3HDR_RSV_48,
AE_TAG_3HDR_RSV_49,
AE_TAG_3HDR_RSV_50,
AE_TAG_3HDR_RSV_51,
AE_TAG_3HDR_RSV_52,
AE_TAG_3HDR_RSV_53,
AE_TAG_3HDR_RSV_54,
AE_TAG_3HDR_RSV_55,
AE_TAG_3HDR_RSV_56,
AE_TAG_3HDR_RSV_57,
AE_TAG_3HDR_RSV_58,
AE_TAG_3HDR_RSV_59,
AE_TAG_3HDR_RSV_60,
AE_TAG_3HDR_RSV_61,
AE_TAG_3HDR_RSV_62,
AE_TAG_3HDR_RSV_63,
//3hdr end

AE_TAG_MAX
//END_OF_EXIF_TAG
};

#define AE_DEBUG_DATA_VERSION (AE_TAG_LAFITE)
#define AE_DEBUG_DATA_SUBVERSION (0)
#define AE_DEBUG_DATA_VERSION_DP ((AE_DEBUG_TAG_SUBVERSION << 16) | AE_DEBUG_TAG_VERSION)

#define AE_BLOCK_NO (5)
#define AE_V4P0_BLOCK_NO (15)
#define AE_SW_HISTOGRAM_BIN (256)
typedef struct
{
    MUINT32 u4AETableVer;
    MUINT32 u4AETableSize;
    /*
    MUINT32 u4AAO_AWBValueWinSize8;
    MUINT32 u4AAO_AWBValueSepSize8;
    MUINT32 u4AAO_AWBSumWinSize8;
    MUINT32 u4AAO_AWBSumSepSize8;
    MUINT32 u4AAO_AEYWinSize8;
    MUINT32 u4AAO_AEYSepSize8;
    MUINT32 u4AAO_AEYWinSizeSE8;
    MUINT32 u4AAO_AEYSepSizeSE8;
    MUINT32 u4AAO_AEOverWinSize8;
    MUINT32 u4AAO_AEOverSepSize8;

    MUINT32 u4HIST_LEWinSize8;
    MUINT32 u4HIST_LESepSize8;
    MUINT32 u4HIST_SEWinSize8;
    MUINT32 u4HIST_SESepSize8;
    MUINT32 u4AAO_LineSize8;

    MUINT32 u4AWB_Rounding;
    MUINT32 u4AWB_ShiftBits;
    MUINT32 u4Y_Rounding;
    MUINT32 u4Y_ShiftBits;
    //AE Block
    MUINT32 u4AEOverExpRatio;    //Global OE Ratio
    MUINT32 u4AEOverExpRatioR;   //Global R OE Ratio
    MUINT32 u4AEOverExpRatioG;   //Global G OE Ratio
    MUINT32 u4AEOverExpRatioB;   //Global B OE Ratio
    MUINT32 pu4AEOverExpBlockCnt[AE_V4P0_BLOCK_NO][AE_V4P0_BLOCK_NO];
    MUINT32 pu4AEOverExpBlockCntR[AE_V4P0_BLOCK_NO][AE_V4P0_BLOCK_NO];
    MUINT32 pu4AEOverExpBlockCntG[AE_V4P0_BLOCK_NO][AE_V4P0_BLOCK_NO];
    MUINT32 pu4AEOverExpBlockCntB[AE_V4P0_BLOCK_NO][AE_V4P0_BLOCK_NO];
    */

    MUINT32 pu4AEBlock[AE_BLOCK_NO][AE_BLOCK_NO]; // AE block value in Algorithm level
    MUINT32 pu4AEBlockSE[AE_BLOCK_NO][AE_BLOCK_NO]; // AE SE block value in Algorithm level  
    MUINT32 pu4AEv4p0Block[AE_V4P0_BLOCK_NO][AE_V4P0_BLOCK_NO]; // AE v4p0 block value in Algorithm level
    MUINT32 pu4AEv4p0BlockSE[AE_V4P0_BLOCK_NO][AE_V4P0_BLOCK_NO]; // AE SE v4p0 block value in Algorithm level
    MUINT32 pu4AEBlockR[AE_V4P0_BLOCK_NO][AE_V4P0_BLOCK_NO];
    MUINT32 pu4AEBlockG[AE_V4P0_BLOCK_NO][AE_V4P0_BLOCK_NO];
    MUINT32 pu4AEBlockB[AE_V4P0_BLOCK_NO][AE_V4P0_BLOCK_NO];

    /*
    MUINT32 u4AEOverExpSE;
    MUINT32 u4AEOverExpCntSE;
    MUINT32 u4AETotalCntSE;
    */

    // Linear Block
    MUINT32 pu4AELieanrSortedY[AE_V4P0_BLOCK_NO * AE_V4P0_BLOCK_NO];
    MUINT32 pu4AELieanrSortedSEY[AE_V4P0_BLOCK_NO * AE_V4P0_BLOCK_NO];

    // FolivoraFMatrix
    MUINT32 m_u4FolivoraFMatrix[AE_V4P0_BLOCK_NO][AE_V4P0_BLOCK_NO];

    //AE Hist
    MUINT32 pu4CentralYHist[AE_SW_HISTOGRAM_BIN];
    MUINT32 pu4FullYHist[AE_SW_HISTOGRAM_BIN];
    MUINT32 pu4FullRGBHist[AE_SW_HISTOGRAM_BIN];
    /*
    MUINT32 pu4FullRHist[AE_SW_HISTOGRAM_BIN];
    MUINT32 pu4FullGHist[AE_SW_HISTOGRAM_BIN];
    MUINT32 pu4FullBHist[AE_SW_HISTOGRAM_BIN];
    */

    MUINT32 pu4CentralYHistSE[AE_SW_HISTOGRAM_BIN];
    MUINT32 pu4FullYHistSE[AE_SW_HISTOGRAM_BIN];
    MUINT32 pu4FullRGBHistSE[AE_SW_HISTOGRAM_BIN];
    /*
    MUINT32 pu4FullRHistSE[AE_SW_HISTOGRAM_BIN];
    MUINT32 pu4FullGHistSE[AE_SW_HISTOGRAM_BIN];
    MUINT32 pu4FullBHistSE[AE_SW_HISTOGRAM_BIN];
    */
} AE_DEBUG_DATA_T;

#endif // _DBG_AE_PARAM_H_
