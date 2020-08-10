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
#define LOG_TAG "aaa_sensor_buf_mgr"

#ifndef ENABLE_MY_LOG
    #define ENABLE_MY_LOG       (1)
#endif

#define ENABLE_AE_MVHDR_STAT       (1)

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <cutils/atomic.h>

#include <sys/stat.h>
#include <cutils/properties.h>
#include <string.h>
#include <aaa_types.h>
#include <aaa_error_code.h>
#include <mtkcam/utils/std/Log.h>
#include <camera_custom_nvram.h>
#include <awb_feature.h>
#include <awb_param.h>
#include <awb_tuning_custom.h>
#include <drv/tuning_mgr.h>
#include <isp_tuning.h>
#include <utils/threads.h>
#include <list>
#include <mtkcam/drv/IHalSensor.h>
#include <private/IopipeUtils.h>
#include "aaa_sensor_buf_mgr.h"
#include <sys/mman.h>
#include <mtkcam/drv/def/ICam_type.h>



using namespace std;
using namespace android;
using namespace NS3Av3;
using namespace NSIspTuning;
using namespace NSCam;
using namespace NSIoPipe;
using namespace NSCamIOPipe;

typedef list<BufInfo_T> BufInfoList_T;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  AAO buffer
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define AAO_OFFSET_ADDR (0)
#define AAO_YSIZE (0)
#define AAO_STRIDE_BUS_SIZE (3)

#define MAX_AAO_BUFFER_CNT (2)



typedef struct
{
    MUINT8                 m_u1NumBit; //8 bit:3, 10bit:2, 12bit:1, 14bit:0
    MUINT32                m_u4AAOBufSize;
    MUINT32                m_u4AAOXSize;
    MUINT32                m_u4AAOYSize;
    BufInfoList_T          m_rHwBufList;
    BufInfo_T              m_rAAOBufInfo[MAX_AAO_BUFFER_CNT];
} SAE_BUF_CTRL_T;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class AEBufMgr
{
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  Ctor/Dtor.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
private:
    //  Copy constructor is disallowed.
    AEBufMgr(AEBufMgr const&);
    //  Copy-assignment operator is disallowed.
    AEBufMgr& operator=(AEBufMgr const&);

public:
    AEBufMgr(ESensorDev_T const eSensorDev);
    ~AEBufMgr();

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  Operations.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public:
    static AEBufMgr& getInstance(MINT32 const i4SensorDev);
    MBOOL init(MINT32 const i4SensorIdx);
    MBOOL uninit();
    MBOOL debugPrint();
    MBOOL enqueueHwBuf(BufInfo_T& rBufInfo);
    MBOOL dequeueHwBuf(BufInfo_T& rBufInfo);
    MUINT32 getCurrHwBuf();
    MUINT32 getNextHwBuf();
    MBOOL allocateBuf(BufInfo_T &rBufInfo, MUINT32 u4BufSize);
    MBOOL freeBuf(BufInfo_T &rBufInfo);

    MBOOL updateDMABaseAddr(MUINT32 u4BaseAddr);
    MBOOL DMAInit();
    MBOOL DMAUninit();
    MBOOL AAStatEnable(MBOOL En);

    inline MBOOL sendCommandNormalPipe(MINT32 cmd, MINT32 arg1, MINT32 arg2, MINT32 arg3)
    {
        INormalPipe* pPipe = (INormalPipe*)INormalPipeUtils::get()->createDefaultNormalPipe(m_i4SensorIdx, "aao_buf_mgr");//iopipe2.0
        MBOOL fgRet = pPipe->sendCommand(cmd, arg1, arg2, arg3);
        pPipe->destroyInstance("aao_buf_mgr");
        return fgRet;
    }

    inline MBOOL setTGInfo(MINT32 const i4TGInfo)
    {
        CAM_LOGD("[%s()] i4TGInfo: %d \n", __FUNCTION__, i4TGInfo);

        switch (i4TGInfo)
        {
        case CAM_TG_1:
            m_eSensorTG = ESensorTG_1;
            break;
        case CAM_TG_2:
            m_eSensorTG = ESensorTG_2;
            break;
        default:
    	    CAM_LOGE("i4TGInfo = %d", i4TGInfo);
            return MFALSE;
        }

        return MTRUE;
    }


    inline MBOOL setSensorMode(MINT32 i4NewSensorMode)
    {
        CAM_LOGD("[%s()] m_eSensorDev: %d Sensor mode: %d \n", __FUNCTION__, m_eSensorDev, i4NewSensorMode);

        m_SensorMode = i4NewSensorMode;

        return MTRUE;
    }


	  inline MBOOL isDMAInit( MBOOL &isInited)
    {
    		isInited = m_u4IsDMAinited;
        return MTRUE;
    }

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  Data member
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
private:
    ESensorDev_T const     m_eSensorDev;
    ESensorTG_T            m_eSensorTG;
    MUINT32                m_u4AEStateSize;
    MUINT32                m_u4AEHistSize;
    MUINT32                m_u4AWBStateSize;
    MUINT32                m_u4AAOBufSize;
    MUINT32                m_u4AAOXSize;
    MUINT                  m_pixelMode;
	SAE_BUF_CTRL_T     m_PDBufCtrl;
	SAE_BUF_CTRL_T     m_MVHDRBufCtrl;
    volatile MINT32        m_Users;
    mutable android::Mutex m_Lock;
	MBOOL                  m_EnMVHDR;
	MBOOL                  m_EnPDAF;
	MBOOL                  m_u4IsDMAinited;
    MBOOL                  m_bDebugEnable;
    MINT32                 m_i4SensorIdx;
    INormalPipe*      m_pPipe;//iopipe2.0
    BufInfoList_T          m_rHwBufList;
    BufInfo_T              m_rAAOBufInfo[MAX_AAO_BUFFER_CNT];
    unsigned long *mpIspHwRegAddr;
    int mfd;
	MINT32                 m_i4CurrSensorId;
	MINT32      		   m_SensorMode;
	MBOOL                  m_FirstTimeCreateBuf;
};

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
template <ESensorDev_T const eSensorDev>
class AEBufMgrDev : public AEBufMgr
{
public:
    static
    AEBufMgr&
    getInstance()
    {
        static AEBufMgrDev<eSensorDev> singleton;
        return singleton;
    }

    AEBufMgrDev()
        : AEBufMgr(eSensorDev)
    {}

    virtual ~AEBufMgrDev() {}
};


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
IAEBufMgr::
init(MINT32 const i4SensorDev, MINT32 const i4SensorIdx)
{
    MBOOL ret_main, ret_sub, ret_main2, ret_sub2;
    ret_main = ret_sub = ret_main2 = ret_sub2 = MTRUE;

    if (i4SensorDev & ESensorDev_Main)
        ret_main = AEBufMgr::getInstance(ESensorDev_Main).init(i4SensorIdx);
    if (i4SensorDev & ESensorDev_Sub)
        ret_sub = AEBufMgr::getInstance(ESensorDev_Sub).init(i4SensorIdx);
    if (i4SensorDev & ESensorDev_MainSecond)
        ret_main2 = AEBufMgr::getInstance(ESensorDev_MainSecond).init(i4SensorIdx);
    if (i4SensorDev & ESensorDev_SubSecond)
        ret_sub2 = AEBufMgr::getInstance(ESensorDev_SubSecond).init(i4SensorIdx);
    return ret_main && ret_sub && ret_main2 &&ret_sub2;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
IAEBufMgr::
uninit(MINT32 const i4SensorDev)
{
    MBOOL ret_main, ret_sub, ret_main2, ret_sub2;
    ret_main = ret_sub = ret_main2 = ret_sub2 = MTRUE;

    if (i4SensorDev & ESensorDev_Main)
       ret_main = AEBufMgr::getInstance(ESensorDev_Main).uninit();
    if (i4SensorDev & ESensorDev_Sub)
       ret_sub = AEBufMgr::getInstance(ESensorDev_Sub).uninit();
    if (i4SensorDev & ESensorDev_MainSecond)
       ret_main2 = AEBufMgr::getInstance(ESensorDev_MainSecond).uninit();
    if (i4SensorDev & ESensorDev_SubSecond)
       ret_sub2 = AEBufMgr::getInstance(ESensorDev_SubSecond).uninit();

    return ret_main && ret_sub && ret_main2 && ret_sub2;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
IAEBufMgr::
DMAInit(MINT32 const i4SensorDev)
{
    MBOOL ret_main, ret_sub, ret_main2, ret_sub2;
    ret_main = ret_sub = ret_main2 = ret_sub2 = MTRUE;

    if (i4SensorDev & ESensorDev_Main)
        ret_main = AEBufMgr::getInstance(ESensorDev_Main).DMAInit();
    if (i4SensorDev & ESensorDev_Sub)
        ret_sub = AEBufMgr::getInstance(ESensorDev_Sub).DMAInit();
    if (i4SensorDev & ESensorDev_MainSecond)
        ret_main2 = AEBufMgr::getInstance(ESensorDev_MainSecond).DMAInit();
    if (i4SensorDev & ESensorDev_SubSecond)
       ret_sub2 = AEBufMgr::getInstance(ESensorDev_SubSecond).DMAInit();

    return ret_main && ret_sub && ret_main2 && ret_sub2;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
IAEBufMgr::
DMAUninit(MINT32 const i4SensorDev)
{
    MBOOL ret_main, ret_sub, ret_main2, ret_sub2;
    ret_main = ret_sub = ret_main2 = ret_sub2 = MTRUE;

    if (i4SensorDev & ESensorDev_Main)
        ret_main = AEBufMgr::getInstance(ESensorDev_Main).DMAUninit();
    if (i4SensorDev & ESensorDev_Sub)
        ret_sub = AEBufMgr::getInstance(ESensorDev_Sub).DMAUninit();
    if (i4SensorDev & ESensorDev_MainSecond)
        ret_main2 = AEBufMgr::getInstance(ESensorDev_MainSecond).DMAUninit();
    if (i4SensorDev & ESensorDev_SubSecond)
       ret_sub2 = AEBufMgr::getInstance(ESensorDev_SubSecond).DMAUninit();

    return ret_main && ret_sub && ret_main2 && ret_sub2;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
IAEBufMgr::
AAStatEnable(MINT32 const i4SensorDev, MBOOL En)
{
    MBOOL ret_main, ret_sub, ret_main2, ret_sub2;
    ret_main = ret_sub = ret_main2 = ret_sub2 = MTRUE;

    if (i4SensorDev & ESensorDev_Main)
        ret_main = AEBufMgr::getInstance(ESensorDev_Main).AAStatEnable(En);
    if (i4SensorDev & ESensorDev_Sub)
        ret_sub = AEBufMgr::getInstance(ESensorDev_Sub).AAStatEnable(En);
    if (i4SensorDev & ESensorDev_MainSecond)
        ret_main2 = AEBufMgr::getInstance(ESensorDev_MainSecond).AAStatEnable(En);
    if (i4SensorDev & ESensorDev_SubSecond)
        ret_sub2 = AEBufMgr::getInstance(ESensorDev_SubSecond).AAStatEnable(En);

    return ret_main && ret_sub && ret_main2 && ret_sub2;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
IAEBufMgr::
enqueueHwBuf(MINT32 const i4SensorDev, BufInfo_T& rBufInfo, MINT32 PDSel)
{
    (void)PDSel;
    if (i4SensorDev & ESensorDev_Main)
        return AEBufMgr::getInstance(ESensorDev_Main).enqueueHwBuf(rBufInfo);
    else if (i4SensorDev & ESensorDev_Sub)
        return AEBufMgr::getInstance(ESensorDev_Sub).enqueueHwBuf(rBufInfo);
    else if (i4SensorDev & ESensorDev_MainSecond)
        return AEBufMgr::getInstance(ESensorDev_MainSecond).enqueueHwBuf(rBufInfo);
    else if (i4SensorDev & ESensorDev_SubSecond)
        return AEBufMgr::getInstance(ESensorDev_SubSecond).enqueueHwBuf(rBufInfo);

    CAM_LOGE("Incorrect sensor device: i4SensorDev = %d", i4SensorDev);
    return MFALSE;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
IAEBufMgr::
dequeueHwBuf(MINT32 const i4SensorDev, BufInfo_T& rBufInfo, MINT32 i4PDSel, MUINT32 i4FrmNum)
{
    (void)i4PDSel;
    (void)i4FrmNum;
    if (i4SensorDev & ESensorDev_Main)
        return AEBufMgr::getInstance(ESensorDev_Main).dequeueHwBuf(rBufInfo);
    else if (i4SensorDev & ESensorDev_Sub)
        return AEBufMgr::getInstance(ESensorDev_Sub).dequeueHwBuf(rBufInfo);
    else if (i4SensorDev & ESensorDev_MainSecond)
        return AEBufMgr::getInstance(ESensorDev_MainSecond).dequeueHwBuf(rBufInfo);
    else if (i4SensorDev & ESensorDev_SubSecond)
        return AEBufMgr::getInstance(ESensorDev_SubSecond).dequeueHwBuf(rBufInfo);

    CAM_LOGE("Incorrect sensor device: i4SensorDev = %d", i4SensorDev);
    return MFALSE;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
IAEBufMgr::
updateDMABaseAddr(MINT32 const i4SensorDev, MINT32 PDSel)
{
    (void)PDSel;
    if (i4SensorDev & ESensorDev_Main)
        return AEBufMgr::getInstance(ESensorDev_Main).updateDMABaseAddr(AEBufMgr::getInstance(ESensorDev_Main).getNextHwBuf());
    else if (i4SensorDev & ESensorDev_Sub)
        return AEBufMgr::getInstance(ESensorDev_Sub).updateDMABaseAddr(AEBufMgr::getInstance(ESensorDev_Sub).getNextHwBuf());
    else if (i4SensorDev & ESensorDev_MainSecond)
        return AEBufMgr::getInstance(ESensorDev_MainSecond).updateDMABaseAddr(AEBufMgr::getInstance(ESensorDev_MainSecond).getNextHwBuf());
    else if (i4SensorDev & ESensorDev_SubSecond)
        return AEBufMgr::getInstance(ESensorDev_SubSecond).updateDMABaseAddr(AEBufMgr::getInstance(ESensorDev_SubSecond).getNextHwBuf());

    CAM_LOGE("Incorrect sensor device: i4SensorDev = %d", i4SensorDev);
    return MFALSE;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
IAEBufMgr::
setTGInfo(MINT32 const i4SensorDev, MINT32 const i4TGInfo)
{
    if (i4SensorDev & ESensorDev_Main)
        return AEBufMgr::getInstance(ESensorDev_Main).setTGInfo(i4TGInfo);
    else if (i4SensorDev & ESensorDev_Sub)
        return AEBufMgr::getInstance(ESensorDev_Sub).setTGInfo(i4TGInfo);
    else if (i4SensorDev & ESensorDev_MainSecond)
        return AEBufMgr::getInstance(ESensorDev_MainSecond).setTGInfo(i4TGInfo);
    else if (i4SensorDev & ESensorDev_SubSecond)
        return AEBufMgr::getInstance(ESensorDev_SubSecond).setTGInfo(i4TGInfo);

    CAM_LOGE("Incorrect sensor device: i4SensorDev = %d", i4SensorDev);
    return MFALSE;
}


MRESULT
IAEBufMgr::
setSensorMode(MINT32 const i4SensorDev, MINT32 i4NewSensorMode)
{
    MINT32 ret_main, ret_sub, ret_main2, ret_sub2;
    ret_main = ret_sub = ret_main2 = ret_sub2 = S_AE_OK;

    if (i4SensorDev & ESensorDev_Main)
        ret_main = AEBufMgr::getInstance(ESensorDev_Main).setSensorMode(i4NewSensorMode);
    if (i4SensorDev & ESensorDev_Sub)
        ret_sub = AEBufMgr::getInstance(ESensorDev_Sub).setSensorMode(i4NewSensorMode);
    if (i4SensorDev & ESensorDev_MainSecond)
        ret_main2 = AEBufMgr::getInstance(ESensorDev_MainSecond).setSensorMode(i4NewSensorMode);
    if (i4SensorDev & ESensorDev_SubSecond)
        ret_sub2 = AEBufMgr::getInstance(ESensorDev_SubSecond).setSensorMode(i4NewSensorMode);

    return (ret_main | ret_sub | ret_main2 | ret_sub2);
}


MRESULT
IAEBufMgr::
isDMAInit(MINT32 const i4SensorDev, MBOOL &isInited)
{
    MINT32 ret_main, ret_sub, ret_main2, ret_sub2;
    ret_main = ret_sub = ret_main2 = ret_sub2 = S_AE_OK;

    if (i4SensorDev & ESensorDev_Main)
        ret_main = AEBufMgr::getInstance(ESensorDev_Main).isDMAInit(isInited);
    if (i4SensorDev & ESensorDev_Sub)
        ret_sub = AEBufMgr::getInstance(ESensorDev_Sub).isDMAInit(isInited);
    if (i4SensorDev & ESensorDev_MainSecond)
        ret_main2 = AEBufMgr::getInstance(ESensorDev_MainSecond).isDMAInit(isInited);
    if (i4SensorDev & ESensorDev_SubSecond)
        ret_sub2 = AEBufMgr::getInstance(ESensorDev_SubSecond).isDMAInit(isInited);

    return (ret_main | ret_sub | ret_main2 | ret_sub2);
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
AEBufMgr&
AEBufMgr::
getInstance(MINT32 const i4SensorDev)
{
    switch (i4SensorDev)
    {
    case ESensorDev_Main: //  Main Sensor
        return  AEBufMgrDev<ESensorDev_Main>::getInstance();
    case ESensorDev_MainSecond: //  Main Second Sensor
        return  AEBufMgrDev<ESensorDev_MainSecond>::getInstance();
    case ESensorDev_Sub: //  Sub Sensor
        return  AEBufMgrDev<ESensorDev_Sub>::getInstance();
    case ESensorDev_SubSecond: //Sub Second Sensor
        return  AEBufMgrDev<ESensorDev_SubSecond>::getInstance();
    default:
        CAM_LOGE("i4SensorDev = %d", i4SensorDev);
        return  AEBufMgrDev<ESensorDev_Main>::getInstance();
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
AEBufMgr::
AEBufMgr(ESensorDev_T const eSensorDev)
    : m_eSensorDev(eSensorDev)
    , m_eSensorTG(ESensorTG_None)
    , m_u4AEStateSize(0)
    , m_u4AEHistSize(0)
    , m_u4AWBStateSize(0)
    , m_u4AAOBufSize(0)
    , m_u4AAOXSize(0)
    , m_pixelMode(0)
    , m_Users(0)
    , m_Lock()
    , m_EnMVHDR(0)
    , m_EnPDAF(0)
    , m_u4IsDMAinited(0)
    , m_bDebugEnable(MFALSE)
    , m_i4SensorIdx(0)
    , m_pPipe(MNULL)
    , m_rHwBufList()
    , mpIspHwRegAddr(NULL)
    , mfd(0)
    , m_i4CurrSensorId(0)
    , m_SensorMode(0)
    , m_FirstTimeCreateBuf(MFALSE)
{

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
AEBufMgr::
~AEBufMgr()
{

}

#define CAM_ISP_RANGE 0xA000
#define ISP_DEV_NAME     "/dev/camera-isp"

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
AEBufMgr::
init(MINT32 const i4SensorIdx)
{
#if ENABLE_AE_MVHDR_STAT
    char value[PROPERTY_VALUE_MAX] = {'\0'};
    property_get("vendor.debug.aao_buf_mgr.enable", value, "0");
    m_bDebugEnable = atoi(value);
    MINT32 cam_isp_addr = 0x15000000;

    // sensor index
    m_i4SensorIdx = i4SensorIdx;

	CAM_LOGD("[%s()] m_eSensorDev: %d, m_i4SensorIdx: %d, m_Users: %d \n", __FUNCTION__, m_eSensorDev, m_i4SensorIdx, m_Users);

	Mutex::Autolock lock(m_Lock);

	if (m_Users > 0)
	{
		CAM_LOGD("%d has created \n", m_Users);
		android_atomic_inc(&m_Users);
		return MTRUE;
	}

    // AAO statistics init
    AWB_STAT_PARAM_T rAWBStatParam;

    switch (m_eSensorDev)
    {
    case ESensorDev_Main: //  Main Sensor
        rAWBStatParam = getAWBStatParam<ESensorDev_Main>();
        break;
    case ESensorDev_MainSecond: //  Main Second Sensor
        rAWBStatParam = getAWBStatParam<ESensorDev_MainSecond>();
        break;
    case ESensorDev_Sub: //  Sub Sensor
        rAWBStatParam = getAWBStatParam<ESensorDev_Sub>();
        break;
    case ESensorDev_SubSecond: //Sub Second Sensor
        rAWBStatParam = getAWBStatParam<ESensorDev_SubSecond>();
        break;
    default:
        CAM_LOGE("m_eSensorDev = %d", m_eSensorDev);
        rAWBStatParam = getAWBStatParam<ESensorDev_Main>();
        break;
    }

    m_u4AAOBufSize = 0x280; //m_u4AEStateSize + m_u4AEHistSize + m_u4AWBStateSize;
    m_u4AAOXSize = m_u4AAOBufSize - 1;

    CAM_LOGD("m_u4AEStateSize = %d", m_u4AEStateSize);
    CAM_LOGD("m_u4AEHistSize = %d", m_u4AEHistSize);
    CAM_LOGD("m_u4AWBStateSize = %d", m_u4AWBStateSize);
    CAM_LOGD("m_u4AAOBufSize = %d", m_u4AAOBufSize);
    CAM_LOGD("m_u4AAOXSize = %d", m_u4AAOXSize);

    // Normal pipe
    //m_pPipe = (INormalPipe*)INormalPipeUtils::get()->createDefaultNormalPipe(m_i4SensorIdx,"aao_buf_mgr");

    // imem driver init
//    m_pIMemDrv->init();

    // AAO DMA buffer init

    // removes all elements from the list container
    m_rHwBufList.clear();

    // allocate and enqueue HW buffer
    for (MINT32 i = 0; i < MAX_AAO_BUFFER_CNT; i++) {
        m_rAAOBufInfo[i].useNoncache = 0;   // improve the performance
        allocateBuf(m_rAAOBufInfo[i], m_u4AAOBufSize);
        enqueueHwBuf(m_rAAOBufInfo[i]);
    }

    // Open isp driver
    mfd = open(ISP_DEV_NAME, O_RDWR);
    if (mfd < 0) {
        CAM_LOGE("error open kernel driver, %d, %s\n", errno, strerror(errno));
        return -1;
    }

    mpIspHwRegAddr = (unsigned long *) mmap(0, CAM_ISP_RANGE, (PROT_READ | PROT_WRITE), MAP_SHARED, mfd, cam_isp_addr);
    if (mpIspHwRegAddr == MAP_FAILED) {
        CAM_LOGE("mmap err(1), %d, %s \n", errno, strerror(errno));
        return -4;
    }
    CAM_LOGD("%s() m_eSensorDev(%d) ISPAddr:0x%lu\n", __FUNCTION__, m_eSensorDev, *mpIspHwRegAddr);

    //DMAInit();

    // Enable AA stat
    //AAStatEnable(MTRUE);
    debugPrint();

    android_atomic_inc(&m_Users);
#endif
    return MTRUE;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
AEBufMgr::
uninit()
{
#if ENABLE_AE_MVHDR_STAT
    IMEM_BUF_INFO buf_info;

	CAM_LOGD("[%s()] m_eSensorDev: %d, m_Users: %d \n", __FUNCTION__, m_eSensorDev, m_Users);

	Mutex::Autolock lock(m_Lock);

	// If no more users, return directly and do nothing.
	if (m_Users <= 0)
	{
		return MTRUE;
	}

	// More than one user, so decrease one User.
	android_atomic_dec(&m_Users);

	if (m_Users == 0) // There is no more User after decrease one User
	{
	    // Disable AA stat
        //AAStatEnable(MFALSE);

        // AAO DMA buffer uninit
        //DMAUninit();

        for (MINT32 i = 0; i < MAX_AAO_BUFFER_CNT; i++) {
            freeBuf(m_rAAOBufInfo[i]);
        }

       // imem driver ininit
//       m_pIMemDrv->uninit();

        if ( 0 != mpIspHwRegAddr ) {
            munmap(mpIspHwRegAddr, CAM_ISP_RANGE);
            mpIspHwRegAddr = NULL;
        }

        if(mfd >= 0)
        {
            close(mfd);
            mfd = -1;
        }
       // Normal pipe
       //m_pPipe->destroyInstance("aao_buf_mgr");
    }
	else	// There are still some users.
	{
		CAM_LOGD_IF(m_bDebugEnable,"Still %d users \n", m_Users);
	}
#endif
    return MTRUE;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
AEBufMgr::
debugPrint()
{
    BufInfoList_T::iterator it;

    for (it = m_rHwBufList.begin(); it != m_rHwBufList.end(); it++ ) {
        CAM_LOGD("m_rHwBufList.virtAddr:[0x%" PRIXPTR "]/phyAddr:[0x%" PRIXPTR "] \n",it->virtAddr,it->phyAddr);
    }

    return MTRUE;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
AEBufMgr::
enqueueHwBuf(BufInfo_T& rBufInfo)
{
 (void)rBufInfo;
#if 0//ENABLE_AE_MVHDR_STAT
    CAM_LOGD_IF(m_bDebugEnable,"%s() m_eSensorDev(%d)\n", __FUNCTION__, m_eSensorDev);
    CAM_LOGD_IF(m_bDebugEnable,"rBufInfo.virtAddr:[0x%x]/phyAddr:[0x%x] \n",rBufInfo.virtAddr,rBufInfo.phyAddr);

    // add element at the end
    m_rHwBufList.push_back(rBufInfo);
    m_pIMemDrv->cacheSyncbyRange(IMEM_CACHECTRL_ENUM_INVALID, &rBufInfo);
#endif
    return MTRUE;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
AEBufMgr::
dequeueHwBuf(BufInfo_T& rBufInfo)
{
#if ENABLE_AE_MVHDR_STAT
    CAM_LOGD_IF(m_bDebugEnable,"%s() m_eSensorDev(%d)\n", __FUNCTION__, m_eSensorDev);
    static MINT32 frameCnt = 0;

    char value[PROPERTY_VALUE_MAX] = {'\0'};
    property_get("vendor.aae.dump.enable", value, "0");
    MBOOL bEnable = atoi(value);


    if (m_rHwBufList.size()) {
        rBufInfo = m_rHwBufList.front();
        m_rHwBufList.pop_front();
    }

    if (bEnable) {
        char fileName[64];
        sprintf(fileName, "/sdcard/ae/ae%d.raw", frameCnt++);
        FILE *fp = fopen(fileName, "w");
        if (NULL == fp)
        {
            CAM_LOGE("fail to open file to save img: %s", fileName);
            MINT32 err = mkdir("/sdcard/ae", S_IRWXU | S_IRWXG | S_IRWXO);
            CAM_LOGD("err = %d", err);
            return MFALSE;
        }
        CAM_LOGD_IF(m_bDebugEnable,"%s\n", fileName);
        fwrite(reinterpret_cast<void *>(rBufInfo.virtAddr), 1, rBufInfo.size, fp);
        fclose(fp);
		// [Everest isp_reg review] temp use, need owner to review this code
        //isp_reg_t *pisp = (isp_reg_t *) mpIspHwRegAddr;
        camsv_reg_t *pisp = (camsv_reg_t *) mpIspHwRegAddr;
#if 0

        CAM_LOGD("%s() m_eSensorDev(%d) ISPAddr:0x%0x 0x%0x\n", __FUNCTION__, m_eSensorDev, mpIspHwRegAddr, pisp);

        CAM_LOGD("%s() CAMSV_CAMSV_CLK_EN (0x9020):0x%0x\n", __FUNCTION__, ISP_REG(pisp, CAMSV_CAMSV_CLK_EN));
        CAM_LOGD("%s() CAMSV_CAMSV_INT_EN(0x9008):0x%0x\n", __FUNCTION__, ISP_REG(pisp, CAMSV_CAMSV_INT_EN));
        CAM_LOGD("%s() CAMSV_TG_VF_CON(0x9414):0x%0x\n", __FUNCTION__, ISP_REG(pisp, CAMSV_TG_VF_CON));
        CAM_LOGD("%s() CAMSV_CAMSV_MODULE_EN(0x9000):0x%0x\n", __FUNCTION__, ISP_REG(pisp, CAMSV_CAMSV_MODULE_EN));
        CAM_LOGD("%s() CAMSV_CAMSV_PAK(0x903C):0x%0x\n", __FUNCTION__, ISP_REG(pisp, CAMSV_CAMSV_PAK));
        CAM_LOGD("%s() CAMSV_CAMSV_FMT_SEL(0x9004):0x%0x\n", __FUNCTION__, ISP_REG(pisp, CAMSV_CAMSV_FMT_SEL));
#endif
    }
    else {
        frameCnt = 0;
    }

    CAM_LOGD_IF(m_bDebugEnable,"rBufInfo.virtAddr:[0x%" PRIXPTR "]/phyAddr:[0x%" PRIXPTR "] \n",rBufInfo.virtAddr,rBufInfo.phyAddr);
#endif
    return MTRUE;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MUINT32
AEBufMgr::
getCurrHwBuf()
{
#if ENABLE_AE_MVHDR_STAT
    if (m_rHwBufList.size() > 0) {
        return m_rHwBufList.front().phyAddr;
    }
    else { // No free buffer
        CAM_LOGE("No free buffer\n");
        return 0;
    }
#else
    return 0;
#endif
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MUINT32
AEBufMgr::
getNextHwBuf()
{
#if ENABLE_AE_MVHDR_STAT
    BufInfoList_T::iterator it;

    if (m_rHwBufList.size() > 1) {
    	it = m_rHwBufList.begin();
        it++;
        return it->phyAddr;
    }
    else { // No free buffer
       CAM_LOGE("No free buffer\n");
       return 0;
    }
#else
    return 0;
#endif
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
AEBufMgr::
allocateBuf(BufInfo_T &rBufInfo, MUINT32 u4BufSize)
{
 (void)rBufInfo;
 (void)u4BufSize;
#if 0 //ENABLE_AE_MVHDR_STAT
    rBufInfo.size = u4BufSize;
    if (m_pIMemDrv->allocVirtBuf(&rBufInfo)) {
        CAM_LOGE("m_pIMemDrv->allocVirtBuf() error");
        return MFALSE;
    }

    if (m_pIMemDrv->mapPhyAddr(&rBufInfo)) {
        CAM_LOGE("m_pIMemDrv->mapPhyAddr() error");
        return MFALSE;
    }

    CAM_LOGD("%s() memID = 0x%x\n", __FUNCTION__, rBufInfo.memID);
#endif
    return MTRUE;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
AEBufMgr::
freeBuf(BufInfo_T &rBufInfo)
{
 (void)rBufInfo;
#if 0 //ENABLE_AE_MVHDR_STAT
    if (m_pIMemDrv->unmapPhyAddr(&rBufInfo)) {
        CAM_LOGE("m_pIMemDrv->unmapPhyAddr() error");
        return MFALSE;
    }

    if (m_pIMemDrv->freeVirtBuf(&rBufInfo)) {
        CAM_LOGE("m_pIMemDrv->freeVirtBuf() error");
        return MFALSE;
    }

    CAM_LOGD("%s() memID = 0x%x\n", __FUNCTION__, rBufInfo.memID);
#endif
    return MTRUE;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
AEBufMgr::
updateDMABaseAddr(MUINT32 u4BaseAddr)
{
#if ENABLE_AE_MVHDR_STAT
	// [Everest isp_reg review] temp use, need owner to review this code
    //isp_reg_t *pisp = (isp_reg_t *) mpIspHwRegAddr;
    camsv_reg_t *pisp = (camsv_reg_t *) mpIspHwRegAddr;

    CAM_LOGD("%s() m_eSensorDev(%d) u4BaseAddr=0x%x ISPAddr:0x%lu \n", __FUNCTION__, m_eSensorDev, u4BaseAddr, *mpIspHwRegAddr);

    if (!u4BaseAddr) {
        CAM_LOGE("u4BaseAddr is NULL\n");
        return E_ISPMGR_NULL_ADDRESS;
    }

    MINT32 handle;

// Temp mark, need owner to review this code
#if 0
    if (m_eSensorTG == ESensorTG_1) { // TG1
        ISP_REG(pisp, CAMSV_IMGO_SV_BASE_ADDR) = u4BaseAddr;
        ISP_REG(pisp, CAMSV_IMGO_SV_OFST_ADDR) = AAO_OFFSET_ADDR;
        ISP_REG(pisp, CAMSV_IMGO_SV_XSIZE) = m_u4AAOXSize;
        ISP_REG(pisp, CAMSV_IMGO_SV_YSIZE) = AAO_YSIZE;
        ISP_REG(pisp, CAMSV_IMGO_SV_STRIDE) = 0x1000;
    }
    else if (m_eSensorTG == ESensorTG_2) { // TG2
        // set module register
        ISP_REG(pisp, CAMSV_IMGO_SV_D_BASE_ADDR) = u4BaseAddr;
        ISP_REG(pisp, CAMSV_IMGO_SV_D_OFST_ADDR) = AAO_OFFSET_ADDR;
        ISP_REG(pisp, CAMSV_IMGO_SV_D_XSIZE) = m_u4AAOXSize;
        ISP_REG(pisp, CAMSV_IMGO_SV_D_YSIZE) = AAO_YSIZE;
        ISP_REG(pisp, CAMSV_IMGO_SV_D_STRIDE) = 0x1000;
    }
    else {
        CAM_LOGE("Incorrect TG info: m_eSensorTG = %d", m_eSensorTG);
    }
#endif
#endif
    return MTRUE;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
AEBufMgr::
DMAInit()
{
#if ENABLE_AE_MVHDR_STAT
    CAM_LOGD_IF(m_bDebugEnable,"%s() m_eSensorDev(%d)\n", __FUNCTION__, m_eSensorDev);

    updateDMABaseAddr(getNextHwBuf());

    if (m_eSensorTG == ESensorTG_1) { // TG1
        if (MFALSE==sendCommandNormalPipe(ENPipeCmd_SET_MODULE_EN, NSCam::NSIoPipe::NSCamIOPipe::EModule_CAMSV_IMGO, MTRUE, MNULL))
        {
            //Error Handling
            CAM_LOGE("EPIPECmd_SET_MODULE_En fail: EModule_AAO");
            return MFALSE;
        }
    }
    else {
        CAM_LOGD("%s() m_eSensorDev(%d) No TG:%d\n", __FUNCTION__, m_eSensorDev, m_eSensorTG);
    }

#endif
    return MTRUE;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
AEBufMgr::
DMAUninit()
{
    CAM_LOGD_IF(m_bDebugEnable,"%s() m_eSensorDev(%d)\n", __FUNCTION__, m_eSensorDev);

    if (m_eSensorTG == ESensorTG_1) { // TG1
        if (MFALSE==sendCommandNormalPipe(ENPipeCmd_SET_MODULE_EN, NSCam::NSIoPipe::NSCamIOPipe::EModule_CAMSV_IMGO, MFALSE, MNULL))
        {
            //Error Handling
            CAM_LOGE("EPIPECmd_SET_MODULE_En fail: EModule_AAO");
            return MFALSE;
        }
    }
    else {
        CAM_LOGD("%s() m_eSensorDev(%d) No TG:%d\n", __FUNCTION__, m_eSensorDev, m_eSensorTG);
    }

    return MTRUE;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
AEBufMgr::
AAStatEnable(MBOOL En)
{
    CAM_LOGD_IF(m_bDebugEnable,"m_eSensorDev(%d) AAStatEnable(%d)\n",m_eSensorDev, En);
    return MTRUE;
}
