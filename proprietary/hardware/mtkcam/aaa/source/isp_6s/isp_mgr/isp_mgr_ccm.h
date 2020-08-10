/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
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
 *     TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/
#ifndef _ISP_MGR_CCM_H_
#define _ISP_MGR_CCM_H_

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// CCM
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define INIT_CCM_ADDR(reg)\
    INIT_REG_INFO_ADDR_P1_MULTI(ECCM_R1, reg, CCM_R1_CCM_);\
    INIT_REG_INFO_ADDR_P1_MULTI(ECCM_R2, reg, CCM_R2_CCM_);\
    INIT_REG_INFO_ADDR_P1_MULTI(ECCM_R3, reg, CCM_R3_CCM_);\
    INIT_REG_INFO_ADDR_P2_MULTI(ECCM_D1, reg, CCM_D1A_CCM_);\
    INIT_REG_INFO_ADDR_P2_MULTI(ECCM_D2, reg, CCM_D2A_CCM_);\
    INIT_REG_INFO_ADDR_P2_MULTI(ECCM_D3, reg, CCM_D3A_CCM_);\

typedef class ISP_MGR_CCM : public ISP_MGR_BASE_T
{
    typedef ISP_MGR_CCM    MyType;
public:
    enum
    {
        ECCM_R1,
        ECCM_R2,
        ECCM_R3,
        ECCM_D1,
        ECCM_D2,
        ECCM_D3,
        ESubModule_NUM
    };
private:
    MBOOL m_bEnable[ESubModule_NUM];
    MBOOL m_bCCTEnable;
    MINT32 m_MdpCCM_D3[3*3];
    float m_MdpCCM_D3_Y2R[3*3];
    MUINT32 m_u4ISO;
    enum
    {
        ERegInfo_CNV_1,
        ERegInfo_CNV_2,
        ERegInfo_CNV_3,
        ERegInfo_CNV_4,
        ERegInfo_CNV_5,
        ERegInfo_CNV_6,
        ERegInfo_CTRL,
        ERegInfo_CFC_CTRL1,
        ERegInfo_CFC_CTRL2,
        ERegInfo_NUM
    };

    RegInfo_T m_rIspRegInfo[ESubModule_NUM][ERegInfo_NUM];

protected:
    ISP_MGR_CCM(ESensorDev_T const eSensorDev)
        : ISP_MGR_BASE_T(m_rIspRegInfo, ERegInfo_NUM, eSensorDev, ESubModule_NUM)
        , m_u4ISO(0)
        , m_bCCTEnable(MTRUE)
    {
        for(int i=0; i<ESubModule_NUM; i++){
            m_bEnable[i] = MFALSE;
            ::memset(m_rIspRegInfo[i], 0, sizeof(RegInfo_T)*ERegInfo_NUM);
        }
        INIT_CCM_ADDR(CNV_1);
        INIT_CCM_ADDR(CNV_2);
        INIT_CCM_ADDR(CNV_3);
        INIT_CCM_ADDR(CNV_4);
        INIT_CCM_ADDR(CNV_5);
        INIT_CCM_ADDR(CNV_6);
        INIT_CCM_ADDR(CTRL);
        INIT_CCM_ADDR(CFC_CTRL1);
        INIT_CCM_ADDR(CFC_CTRL2);
        for(int i=0; i<ESubModule_NUM; i++){
            m_rIspRegInfo[i][ERegInfo_CFC_CTRL2].val = 0x1CE729CE;
            reinterpret_cast<REG_CCM_R1_CCM_CTRL*>(REG_INFO_VALUE_PTR_MULTI(i, CTRL))->Bits.CCM_CFC_EN = 1;
            reinterpret_cast<REG_CCM_R1_CCM_CFC_CTRL1*>(REG_INFO_VALUE_PTR_MULTI(i, CFC_CTRL1))->Bits.CCM_H = 4063;
            reinterpret_cast<REG_CCM_R1_CCM_CFC_CTRL1*>(REG_INFO_VALUE_PTR_MULTI(i, CFC_CTRL1))->Bits.CCM_L = 32;
        }
    }

    virtual ~ISP_MGR_CCM() {}

public:
    static MyType&  getInstance(ESensorDev_T const eSensorDev);

public:

    template <class ISP_xxx_T>
    MyType& put(MUINT8 SubModuleIndex, ISP_xxx_T const& rParam);

    template <class ISP_xxx_T>
    MyType& get(MUINT8 SubModuleIndex, ISP_xxx_T & rParam);

    MVOID
    getDefaultValue(MUINT8 SubModuleIndex, ISP_NVRAM_CCM_T & rParam)
    {

        switch (SubModuleIndex)
        {
            case ECCM_R1:
            case ECCM_D1:
            case ECCM_D2:
            case ECCM_D3:
            default:
                rParam.cnv_1.bits.CCM_CNV_00 = 512;
                rParam.cnv_1.bits.CCM_CNV_01 = 0;
                rParam.cnv_2.bits.CCM_CNV_02 = 0;
                rParam.cnv_3.bits.CCM_CNV_10 = 0;
                rParam.cnv_3.bits.CCM_CNV_11 = 512;
                rParam.cnv_4.bits.CCM_CNV_12 = 0;
                rParam.cnv_5.bits.CCM_CNV_20 = 0;
                rParam.cnv_5.bits.CCM_CNV_21 = 0;
                rParam.cnv_6.bits.CCM_CNV_22 = 512;
        }
    }

    MBOOL
    isEnable(MUINT8 SubModuleIndex)
    {
        return m_bEnable[SubModuleIndex];
    }

    MBOOL
    isCCTEnable()
    {
        return m_bCCTEnable;
    }

    MVOID
    setEnable(MUINT8 SubModuleIndex, MBOOL bEnable)
    {
        m_bEnable[SubModuleIndex] = bEnable;
    }

    MVOID
    setCCTEnable(MBOOL bEnable)
    {
        m_bCCTEnable = bEnable;
    }

    MBOOL apply_P1(MUINT8 SubModuleIndex, const RAWIspCamInfo& rRawIspCamInfo, TuningMgr& rTuning, MINT32 i4SubsampleIdex=0);

    MBOOL apply_P2(MUINT8 SubModuleIndex, const RAWIspCamInfo& rRawIspCamInfo, dip_a_reg_t* pReg);

} ISP_MGR_CCM_T;

template <ESensorDev_T const eSensorDev>
class ISP_MGR_CCM_DEV : public ISP_MGR_CCM_T
{
public:
    static
    ISP_MGR_CCM_T&
    getInstance()
    {
        static ISP_MGR_CCM_DEV<eSensorDev> singleton;
        return singleton;
    }
    virtual MVOID destroyInstance() {}

    ISP_MGR_CCM_DEV()
        : ISP_MGR_CCM_T(eSensorDev)
    {}

    virtual ~ISP_MGR_CCM_DEV() {}

};
#endif