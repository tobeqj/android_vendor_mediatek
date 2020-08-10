/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2017. All rights reserved.
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

// Flash AWB tuning parameter
{
    9,  //foreground percentage
    95, //background percentage
     2, //FgPercentage_Th1
     5, //FgPercentage_Th2
    10, //FgPercentage_Th3
    15, //FgPercentage_Th4
   250, //FgPercentage_Th1_Val
   250, //FgPercentage_Th2_Val
   250, //FgPercentage_Th3_Val
   250, //FgPercentage_Th4_Val
    10, //location_map_th1
    20, //location_map_th2
    40, //location_map_th3
    50, //location_map_th4
   100, //location_map_val1
   100, //location_map_val2
   100, //location_map_val3
   100, //location_map_val4
     0, //SelfTuningFbBgWeightTbl
    100, //FgBgTbl_Y0
    100, //FgBgTbl_Y1
    100, //FgBgTbl_Y2
    100, //FgBgTbl_Y3
    100, //FgBgTbl_Y4
    100, //FgBgTbl_Y5
      5, //YPrimeWeightTh[0]
      9, //YPrimeWeightTh[1]
		 11, //YPrimeWeightTh[2]
		 13, //YPrimeWeightTh[3]
		 15, //YPrimeWeightTh[4]
			1, //YPrimeWeight[0]
			3, //YPrimeWeight[1]
			5, //YPrimeWeight[2]
			7, //YPrimeWeight[3]
	// FlashPreferenceGain
	{
		512,	// FlashPreferenceGain.i4R
		512,	// FlashPreferenceGain.i4G
		512	  // FlashPreferenceGain.i4B
	},
},

// Flash AWB calibration
{{

    {1117, 512,1024},
    {1120, 512,1054},  
    {1097, 512,1047},  
    {1075, 512,1008}, 
    {1093, 512,1011}, 
    {1082, 512, 992},  
    {1097, 512, 960}, 
    {1099, 512, 957}, 
    {1091, 512, 978}, 
    {1096, 512, 935},

/*
    {1063, 512, 987},   
    {1109, 512, 998},   
    {1088, 512,1004},   
    {1084, 512, 970},  
    {1097, 512, 960},   
    {1084, 512, 953},   
    {1095, 512, 932},   
    {1078, 512, 936},   
    {1083, 512, 900},   
    {1076, 512, 912},
*/
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0},
   {   0,   0,   0}
}}


