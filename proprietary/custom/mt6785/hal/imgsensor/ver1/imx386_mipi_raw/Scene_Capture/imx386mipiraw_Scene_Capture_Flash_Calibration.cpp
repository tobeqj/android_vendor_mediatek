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
#include "camera_custom_nvram.h"
#include "imx386mipiraw_Scene_Capture.h"

const FLASH_CALIBRATION_NVRAM_T imx386mipiraw_Flash_Calibration_0000 = {
    .engTab = {
        .exp = 10000,
        .afe_gain = 1024,
        .isp_gain = 1024,
        .distance = 0,
        .yTab = {
           0, 300, 628, 948,1259,1560,1854,2139,2417,2685,2949,3207,3455,3698,3937,4169,4395,4843,5258,5645,6014,6359,6681,6978,7268,7527,7768,7991,8186,8354,8519,
         258, 582, 912,1231,1543,1841,2134,2419,2696,2962,3227,3486,3731,3975,4214,4446,4667,5115,5526,5914,6283,6623,6947,7251,7524,7785,8016,8240,8424,8602,  -1,
         532, 859,1190,1508,1820,2117,2410,2693,2968,3237,3498,3754,4001,4242,4479,4708,4932,5375,5785,6169,6539,6876,7189,7490,7758,8012,8248,8463,8656,8822,  -1,
         795,1122,1450,1772,2080,2377,2669,2950,3226,3491,3753,4010,4253,4495,4730,4956,5180,5621,6029,6413,6774,7113,7427,7718,7994,8242,8477,8692,8878,  -1,  -1,
        1053,1376,1707,2028,2336,2632,2924,3203,3478,3742,4004,4258,4502,4742,4978,5204,5425,5864,6269,6650,7010,7347,7660,7950,8218,8468,8700,8910,9095,  -1,  -1,
        1299,1621,1954,2270,2581,2877,3167,3446,3720,3984,4245,4498,4740,4980,5214,5442,5661,6098,6501,6878,7233,7567,7881,8170,8443,8687,8914,9150,  -1,  -1,  -1,
        1539,1864,2196,2511,2821,3117,3405,3686,3958,4221,4481,4732,4976,5213,5449,5671,5891,6332,6730,7107,7462,7796,8102,8388,8664,8906,9136,9338,  -1,  -1,  -1,
        1768,2097,2425,2744,3050,3347,3635,3913,4188,4449,4707,4959,5201,5439,5670,5894,6114,6549,6949,7324,7688,8012,8316,8599,8881,9114,9333,  -1,  -1,  -1,  -1,
        1991,2320,2649,2967,3274,3568,3858,4138,4409,4671,4928,5181,5422,5657,5887,6110,6327,6763,7161,7535,7886,8214,8522,8807,9072,9320,9547,  -1,  -1,  -1,  -1,
        2208,2536,2867,3182,3491,3785,4073,4351,4622,4884,5142,5391,5631,5867,6097,6319,6535,6969,7366,7744,8089,8421,8720,9009,9270,9507,  -1,  -1,  -1,  -1,  -1,
        2421,2749,3079,3395,3703,3997,4286,4564,4832,5094,5352,5600,5839,6074,6302,6526,6741,7174,7571,7938,8294,8616,8919,9196,9464,9700,  -1,  -1,  -1,  -1,  -1,
        2625,2954,3284,3602,3908,4201,4489,4766,5037,5298,5552,5800,6038,6273,6501,6722,6939,7371,7767,8138,8481,8804,9105,9384,9649,  -1,  -1,  -1,  -1,  -1,  -1,
        2826,3155,3484,3801,4108,4401,4688,4964,5235,5496,5748,5996,6234,6466,6694,6913,7129,7560,7952,8317,8664,8989,9290,9573,9827,  -1,  -1,  -1,  -1,  -1,  -1,
        3017,3345,3674,3992,4298,4593,4877,5154,5422,5681,5936,6183,6419,6652,6881,7099,7312,7741,8134,8500,8843,9167,9465,9742,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        3209,3539,3866,4182,4490,4781,5067,5341,5611,5869,6122,6372,6606,6837,7065,7285,7493,7926,8315,8679,9026,9342,9639,9911,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        3388,3718,4045,4362,4669,4961,5252,5526,5789,6047,6301,6544,6779,7009,7237,7452,7662,8100,8481,8858,9201,9521,9808,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        3570,3897,4225,4539,4848,5137,5421,5697,5961,6219,6471,6715,6954,7180,7406,7623,7832,8265,8663,9014,9357,9687,9963,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        3914,4248,4577,4896,5201,5492,5782,6056,6321,6576,6830,7073,7310,7540,7768,7981,8195,8600,8985,9344,9674,9999,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        4242,4572,4903,5217,5525,5815,6103,6373,6638,6894,7147,7390,7624,7859,8077,8292,8502,8910,9291,9643,9973,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        4548,4877,5206,5523,5826,6118,6399,6672,6938,7190,7440,7684,7920,8144,8377,8581,8789,9191,9570,9922,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        4838,5162,5494,5806,6106,6397,6679,6947,7214,7466,7717,7959,8191,8411,8632,8844,9058,9453,9837,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        5098,5426,5761,6070,6371,6665,6938,7207,7474,7721,7971,8207,8435,8662,8878,9091,9298,9703,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        5343,5684,5998,6311,6622,6896,7175,7441,7702,7952,8199,8439,8664,8888,9104,9314,9516,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        5572,5893,6221,6526,6829,7116,7391,7674,7928,8169,8409,8648,8870,9092,9306,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        5768,6089,6413,6718,7020,7306,7578,7841,8106,8357,8597,8827,9068,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        5972,6285,6610,6917,7205,7489,7782,8046,8285,8530,8772,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        6145,6460,6784,7085,7375,7657,7944,8189,8445,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        6320,6615,6935,7233,7541,7800,8082,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        6447,6750,7083,7396,7671,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        6607,6895,7197,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        6693,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        },
    },
    .flashWBGain = {
    {   0, 512,   0},  //duty=-1, dutyLt=-1
    {1185, 512,1092},  //duty=0, dutyLt=-1
    {1191, 512,1098},  //duty=1, dutyLt=-1
    {1183, 512,1089},  //duty=2, dutyLt=-1
    {1180, 512,1085},  //duty=3, dutyLt=-1
    {1177, 512,1080},  //duty=4, dutyLt=-1
    {1175, 512,1074},  //duty=5, dutyLt=-1
    {1175, 512,1057},  //duty=6, dutyLt=-1
    {1183, 512,1081},  //duty=7, dutyLt=-1
    {1180, 512,1077},  //duty=8, dutyLt=-1
    {1180, 512,1071},  //duty=9, dutyLt=-1
    {1177, 512,1068},  //duty=10, dutyLt=-1
    {1177, 512,1064},  //duty=11, dutyLt=-1
    {1175, 512,1060},  //duty=12, dutyLt=-1
    {1175, 512,1057},  //duty=13, dutyLt=-1
    {1174, 512,1054},  //duty=14, dutyLt=-1
    {1172, 512,1051},  //duty=15, dutyLt=-1
    {1173, 512,1046},  //duty=16, dutyLt=-1
    {1171, 512,1040},  //duty=17, dutyLt=-1
    {1171, 512,1034},  //duty=18, dutyLt=-1
    {1170, 512,1029},  //duty=19, dutyLt=-1
    {1170, 512,1024},  //duty=20, dutyLt=-1
    {1170, 512,1019},  //duty=21, dutyLt=-1
    {1169, 512,1015},  //duty=22, dutyLt=-1
    {1170, 512,1010},  //duty=23, dutyLt=-1
    {1170, 512,1005},  //duty=24, dutyLt=-1
    {1170, 512,1000},  //duty=25, dutyLt=-1
    {1170, 512, 995},  //duty=26, dutyLt=-1
    {1171, 512, 990},  //duty=27, dutyLt=-1
    {1171, 512, 984},  //duty=28, dutyLt=-1
    {1172, 512, 980},  //duty=29, dutyLt=-1
    { 533, 512,3303},  //duty=-1, dutyLt=0
    { 778, 512,1562},  //duty=0, dutyLt=0
    { 886, 512,1345},  //duty=1, dutyLt=0
    { 946, 512,1262},  //duty=2, dutyLt=0
    { 983, 512,1218},  //duty=3, dutyLt=0
    {1009, 512,1188},  //duty=4, dutyLt=0
    {1028, 512,1156},  //duty=5, dutyLt=0
    {1047, 512,1164},  //duty=6, dutyLt=0
    {1057, 512,1152},  //duty=7, dutyLt=0
    {1067, 512,1141},  //duty=8, dutyLt=0
    {1074, 512,1131},  //duty=9, dutyLt=0
    {1080, 512,1123},  //duty=10, dutyLt=0
    {1084, 512,1115},  //duty=11, dutyLt=0
    {1089, 512,1109},  //duty=12, dutyLt=0
    {1092, 512,1102},  //duty=13, dutyLt=0
    {1097, 512,1097},  //duty=14, dutyLt=0
    {1099, 512,1092},  //duty=15, dutyLt=0
    {1105, 512,1083},  //duty=16, dutyLt=0
    {1108, 512,1075},  //duty=17, dutyLt=0
    {1112, 512,1067},  //duty=18, dutyLt=0
    {1114, 512,1060},  //duty=19, dutyLt=0
    {1117, 512,1053},  //duty=20, dutyLt=0
    {1119, 512,1047},  //duty=21, dutyLt=0
    {1120, 512,1042},  //duty=22, dutyLt=0
    {1124, 512,1035},  //duty=23, dutyLt=0
    {1125, 512,1029},  //duty=24, dutyLt=0
    {1127, 512,1023},  //duty=25, dutyLt=0
    {1129, 512,1018},  //duty=26, dutyLt=0
    {1130, 512,1011},  //duty=27, dutyLt=0
    {1131, 512,1006},  //duty=28, dutyLt=0
    { 512, 512, 512},  //duty=29, dutyLt=0
    { 532, 512,3283},  //duty=-1, dutyLt=1
    { 683, 512,1852},  //duty=0, dutyLt=1
    { 776, 512,1532},  //duty=1, dutyLt=1
    { 838, 512,1404},  //duty=2, dutyLt=1
    { 881, 512,1330},  //duty=3, dutyLt=1
    { 913, 512,1276},  //duty=4, dutyLt=1
    { 940, 512,1262},  //duty=5, dutyLt=1
    { 960, 512,1236},  //duty=6, dutyLt=1
    { 977, 512,1216},  //duty=7, dutyLt=1
    { 990, 512,1200},  //duty=8, dutyLt=1
    {1001, 512,1186},  //duty=9, dutyLt=1
    {1011, 512,1173},  //duty=10, dutyLt=1
    {1019, 512,1162},  //duty=11, dutyLt=1
    {1026, 512,1153},  //duty=12, dutyLt=1
    {1033, 512,1144},  //duty=13, dutyLt=1
    {1038, 512,1137},  //duty=14, dutyLt=1
    {1043, 512,1130},  //duty=15, dutyLt=1
    {1053, 512,1117},  //duty=16, dutyLt=1
    {1060, 512,1106},  //duty=17, dutyLt=1
    {1066, 512,1097},  //duty=18, dutyLt=1
    {1071, 512,1088},  //duty=19, dutyLt=1
    {1075, 512,1079},  //duty=20, dutyLt=1
    {1079, 512,1072},  //duty=21, dutyLt=1
    {1082, 512,1065},  //duty=22, dutyLt=1
    {1087, 512,1057},  //duty=23, dutyLt=1
    {1089, 512,1051},  //duty=24, dutyLt=1
    {1091, 512,1044},  //duty=25, dutyLt=1
    {1094, 512,1038},  //duty=26, dutyLt=1
    {1096, 512,1031},  //duty=27, dutyLt=1
    {1098, 512,1025},  //duty=28, dutyLt=1
    { 512, 512, 512},  //duty=29, dutyLt=1
    { 532, 512,3382},  //duty=-1, dutyLt=2
    { 642, 512,2036},  //duty=0, dutyLt=2
    { 721, 512,1680},  //duty=1, dutyLt=2
    { 777, 512,1520},  //duty=2, dutyLt=2
    { 819, 512,1422},  //duty=3, dutyLt=2
    { 853, 512,1385},  //duty=4, dutyLt=2
    { 880, 512,1336},  //duty=5, dutyLt=2
    { 901, 512,1301},  //duty=6, dutyLt=2
    { 920, 512,1274},  //duty=7, dutyLt=2
    { 935, 512,1253},  //duty=8, dutyLt=2
    { 948, 512,1233},  //duty=9, dutyLt=2
    { 960, 512,1219},  //duty=10, dutyLt=2
    { 969, 512,1205},  //duty=11, dutyLt=2
    { 978, 512,1193},  //duty=12, dutyLt=2
    { 986, 512,1182},  //duty=13, dutyLt=2
    { 994, 512,1173},  //duty=14, dutyLt=2
    {1000, 512,1165},  //duty=15, dutyLt=2
    {1011, 512,1149},  //duty=16, dutyLt=2
    {1020, 512,1135},  //duty=17, dutyLt=2
    {1028, 512,1124},  //duty=18, dutyLt=2
    {1035, 512,1113},  //duty=19, dutyLt=2
    {1041, 512,1103},  //duty=20, dutyLt=2
    {1045, 512,1094},  //duty=21, dutyLt=2
    {1049, 512,1087},  //duty=22, dutyLt=2
    {1055, 512,1078},  //duty=23, dutyLt=2
    {1058, 512,1070},  //duty=24, dutyLt=2
    {1061, 512,1063},  //duty=25, dutyLt=2
    {1065, 512,1056},  //duty=26, dutyLt=2
    {1067, 512,1050},  //duty=27, dutyLt=2
    { 512, 512, 512},  //duty=28, dutyLt=2
    { 512, 512, 512},  //duty=29, dutyLt=2
    { 532, 512,3324},  //duty=-1, dutyLt=3
    { 619, 512,2172},  //duty=0, dutyLt=3
    { 686, 512,1800},  //duty=1, dutyLt=3
    { 737, 512,1615},  //duty=2, dutyLt=3
    { 779, 512,1531},  //duty=3, dutyLt=3
    { 810, 512,1460},  //duty=4, dutyLt=3
    { 836, 512,1401},  //duty=5, dutyLt=3
    { 858, 512,1361},  //duty=6, dutyLt=3
    { 877, 512,1329},  //duty=7, dutyLt=3
    { 893, 512,1303},  //duty=8, dutyLt=3
    { 907, 512,1281},  //duty=9, dutyLt=3
    { 919, 512,1262},  //duty=10, dutyLt=3
    { 930, 512,1245},  //duty=11, dutyLt=3
    { 940, 512,1230},  //duty=12, dutyLt=3
    { 949, 512,1218},  //duty=13, dutyLt=3
    { 957, 512,1207},  //duty=14, dutyLt=3
    { 964, 512,1196},  //duty=15, dutyLt=3
    { 977, 512,1177},  //duty=16, dutyLt=3
    { 988, 512,1162},  //duty=17, dutyLt=3
    { 996, 512,1149},  //duty=18, dutyLt=3
    {1004, 512,1137},  //duty=19, dutyLt=3
    {1011, 512,1126},  //duty=20, dutyLt=3
    {1017, 512,1116},  //duty=21, dutyLt=3
    {1022, 512,1108},  //duty=22, dutyLt=3
    {1027, 512,1098},  //duty=23, dutyLt=3
    {1031, 512,1090},  //duty=24, dutyLt=3
    {1035, 512,1082},  //duty=25, dutyLt=3
    {1038, 512,1075},  //duty=26, dutyLt=3
    {1041, 512,1067},  //duty=27, dutyLt=3
    { 512, 512, 512},  //duty=28, dutyLt=3
    { 512, 512, 512},  //duty=29, dutyLt=3
    { 532, 512,3317},  //duty=-1, dutyLt=4
    { 605, 512,2282},  //duty=0, dutyLt=4
    { 664, 512,1897},  //duty=1, dutyLt=4
    { 710, 512,1690},  //duty=2, dutyLt=4
    { 747, 512,1597},  //duty=3, dutyLt=4
    { 778, 512,1524},  //duty=4, dutyLt=4
    { 803, 512,1461},  //duty=5, dutyLt=4
    { 824, 512,1414},  //duty=6, dutyLt=4
    { 843, 512,1378},  //duty=7, dutyLt=4
    { 860, 512,1347},  //duty=8, dutyLt=4
    { 874, 512,1322},  //duty=9, dutyLt=4
    { 887, 512,1301},  //duty=10, dutyLt=4
    { 898, 512,1280},  //duty=11, dutyLt=4
    { 909, 512,1264},  //duty=12, dutyLt=4
    { 918, 512,1251},  //duty=13, dutyLt=4
    { 926, 512,1239},  //duty=14, dutyLt=4
    { 934, 512,1227},  //duty=15, dutyLt=4
    { 948, 512,1206},  //duty=16, dutyLt=4
    { 960, 512,1188},  //duty=17, dutyLt=4
    { 969, 512,1173},  //duty=18, dutyLt=4
    { 978, 512,1160},  //duty=19, dutyLt=4
    { 985, 512,1147},  //duty=20, dutyLt=4
    { 992, 512,1137},  //duty=21, dutyLt=4
    { 997, 512,1128},  //duty=22, dutyLt=4
    {1003, 512,1117},  //duty=23, dutyLt=4
    {1008, 512,1109},  //duty=24, dutyLt=4
    {1012, 512,1100},  //duty=25, dutyLt=4
    {1015, 512,1092},  //duty=26, dutyLt=4
    { 512, 512, 512},  //duty=27, dutyLt=4
    { 512, 512, 512},  //duty=28, dutyLt=4
    { 512, 512, 512},  //duty=29, dutyLt=4
    { 532, 512,3303},  //duty=-1, dutyLt=5
    { 595, 512,2364},  //duty=0, dutyLt=5
    { 647, 512,1973},  //duty=1, dutyLt=5
    { 689, 512,1808},  //duty=2, dutyLt=5
    { 723, 512,1668},  //duty=3, dutyLt=5
    { 752, 512,1577},  //duty=4, dutyLt=5
    { 776, 512,1515},  //duty=5, dutyLt=5
    { 798, 512,1465},  //duty=6, dutyLt=5
    { 816, 512,1423},  //duty=7, dutyLt=5
    { 832, 512,1389},  //duty=8, dutyLt=5
    { 847, 512,1360},  //duty=9, dutyLt=5
    { 860, 512,1336},  //duty=10, dutyLt=5
    { 871, 512,1316},  //duty=11, dutyLt=5
    { 882, 512,1298},  //duty=12, dutyLt=5
    { 892, 512,1283},  //duty=13, dutyLt=5
    { 901, 512,1268},  //duty=14, dutyLt=5
    { 909, 512,1256},  //duty=15, dutyLt=5
    { 924, 512,1233},  //duty=16, dutyLt=5
    { 935, 512,1213},  //duty=17, dutyLt=5
    { 946, 512,1196},  //duty=18, dutyLt=5
    { 955, 512,1181},  //duty=19, dutyLt=5
    { 962, 512,1168},  //duty=20, dutyLt=5
    { 969, 512,1157},  //duty=21, dutyLt=5
    { 975, 512,1146},  //duty=22, dutyLt=5
    { 982, 512,1136},  //duty=23, dutyLt=5
    { 986, 512,1126},  //duty=24, dutyLt=5
    { 991, 512,1117},  //duty=25, dutyLt=5
    { 995, 512,1108},  //duty=26, dutyLt=5
    { 512, 512, 512},  //duty=27, dutyLt=5
    { 512, 512, 512},  //duty=28, dutyLt=5
    { 512, 512, 512},  //duty=29, dutyLt=5
    { 532, 512,3283},  //duty=-1, dutyLt=6
    { 587, 512,2426},  //duty=0, dutyLt=6
    { 634, 512,2091},  //duty=1, dutyLt=6
    { 673, 512,1861},  //duty=2, dutyLt=6
    { 705, 512,1739},  //duty=3, dutyLt=6
    { 732, 512,1630},  //duty=4, dutyLt=6
    { 756, 512,1558},  //duty=5, dutyLt=6
    { 776, 512,1506},  //duty=6, dutyLt=6
    { 794, 512,1463},  //duty=7, dutyLt=6
    { 810, 512,1427},  //duty=8, dutyLt=6
    { 825, 512,1397},  //duty=9, dutyLt=6
    { 838, 512,1370},  //duty=10, dutyLt=6
    { 849, 512,1349},  //duty=11, dutyLt=6
    { 860, 512,1329},  //duty=12, dutyLt=6
    { 870, 512,1311},  //duty=13, dutyLt=6
    { 879, 512,1297},  //duty=14, dutyLt=6
    { 887, 512,1282},  //duty=15, dutyLt=6
    { 902, 512,1257},  //duty=16, dutyLt=6
    { 915, 512,1235},  //duty=17, dutyLt=6
    { 925, 512,1218},  //duty=18, dutyLt=6
    { 935, 512,1202},  //duty=19, dutyLt=6
    { 943, 512,1188},  //duty=20, dutyLt=6
    { 950, 512,1176},  //duty=21, dutyLt=6
    { 956, 512,1164},  //duty=22, dutyLt=6
    { 963, 512,1153},  //duty=23, dutyLt=6
    { 968, 512,1143},  //duty=24, dutyLt=6
    { 972, 512,1133},  //duty=25, dutyLt=6
    { 512, 512, 512},  //duty=26, dutyLt=6
    { 512, 512, 512},  //duty=27, dutyLt=6
    { 512, 512, 512},  //duty=28, dutyLt=6
    { 512, 512, 512},  //duty=29, dutyLt=6
    { 532, 512,3262},  //duty=-1, dutyLt=7
    { 582, 512,2472},  //duty=0, dutyLt=7
    { 625, 512,2150},  //duty=1, dutyLt=7
    { 660, 512,1921},  //duty=2, dutyLt=7
    { 690, 512,1781},  //duty=3, dutyLt=7
    { 716, 512,1688},  //duty=4, dutyLt=7
    { 739, 512,1606},  //duty=5, dutyLt=7
    { 759, 512,1547},  //duty=6, dutyLt=7
    { 776, 512,1500},  //duty=7, dutyLt=7
    { 792, 512,1462},  //duty=8, dutyLt=7
    { 806, 512,1430},  //duty=9, dutyLt=7
    { 819, 512,1403},  //duty=10, dutyLt=7
    { 831, 512,1379},  //duty=11, dutyLt=7
    { 841, 512,1357},  //duty=12, dutyLt=7
    { 851, 512,1340},  //duty=13, dutyLt=7
    { 860, 512,1323},  //duty=14, dutyLt=7
    { 869, 512,1307},  //duty=15, dutyLt=7
    { 884, 512,1280},  //duty=16, dutyLt=7
    { 896, 512,1258},  //duty=17, dutyLt=7
    { 907, 512,1239},  //duty=18, dutyLt=7
    { 917, 512,1221},  //duty=19, dutyLt=7
    { 925, 512,1207},  //duty=20, dutyLt=7
    { 933, 512,1193},  //duty=21, dutyLt=7
    { 939, 512,1181},  //duty=22, dutyLt=7
    { 946, 512,1169},  //duty=23, dutyLt=7
    { 951, 512,1159},  //duty=24, dutyLt=7
    { 956, 512,1149},  //duty=25, dutyLt=7
    { 512, 512, 512},  //duty=26, dutyLt=7
    { 512, 512, 512},  //duty=27, dutyLt=7
    { 512, 512, 512},  //duty=28, dutyLt=7
    { 512, 512, 512},  //duty=29, dutyLt=7
    { 532, 512,3245},  //duty=-1, dutyLt=8
    { 577, 512,2573},  //duty=0, dutyLt=8
    { 617, 512,2184},  //duty=1, dutyLt=8
    { 650, 512,1983},  //duty=2, dutyLt=8
    { 679, 512,1821},  //duty=3, dutyLt=8
    { 703, 512,1724},  //duty=4, dutyLt=8
    { 724, 512,1650},  //duty=5, dutyLt=8
    { 744, 512,1589},  //duty=6, dutyLt=8
    { 761, 512,1538},  //duty=7, dutyLt=8
    { 776, 512,1497},  //duty=8, dutyLt=8
    { 790, 512,1463},  //duty=9, dutyLt=8
    { 803, 512,1432},  //duty=10, dutyLt=8
    { 815, 512,1406},  //duty=11, dutyLt=8
    { 825, 512,1385},  //duty=12, dutyLt=8
    { 835, 512,1366},  //duty=13, dutyLt=8
    { 844, 512,1347},  //duty=14, dutyLt=8
    { 852, 512,1332},  //duty=15, dutyLt=8
    { 868, 512,1302},  //duty=16, dutyLt=8
    { 880, 512,1279},  //duty=17, dutyLt=8
    { 891, 512,1258},  //duty=18, dutyLt=8
    { 901, 512,1240},  //duty=19, dutyLt=8
    { 910, 512,1224},  //duty=20, dutyLt=8
    { 917, 512,1211},  //duty=21, dutyLt=8
    { 924, 512,1198},  //duty=22, dutyLt=8
    { 931, 512,1185},  //duty=23, dutyLt=8
    { 936, 512,1174},  //duty=24, dutyLt=8
    { 512, 512, 512},  //duty=25, dutyLt=8
    { 512, 512, 512},  //duty=26, dutyLt=8
    { 512, 512, 512},  //duty=27, dutyLt=8
    { 512, 512, 512},  //duty=28, dutyLt=8
    { 512, 512, 512},  //duty=29, dutyLt=8
    { 533, 512,3223},  //duty=-1, dutyLt=9
    { 574, 512,2607},  //duty=0, dutyLt=9
    { 610, 512,2240},  //duty=1, dutyLt=9
    { 642, 512,2020},  //duty=2, dutyLt=9
    { 668, 512,1877},  //duty=3, dutyLt=9
    { 692, 512,1760},  //duty=4, dutyLt=9
    { 713, 512,1682},  //duty=5, dutyLt=9
    { 731, 512,1621},  //duty=6, dutyLt=9
    { 748, 512,1570},  //duty=7, dutyLt=9
    { 763, 512,1528},  //duty=8, dutyLt=9
    { 776, 512,1491},  //duty=9, dutyLt=9
    { 789, 512,1460},  //duty=10, dutyLt=9
    { 800, 512,1434},  //duty=11, dutyLt=9
    { 811, 512,1411},  //duty=12, dutyLt=9
    { 820, 512,1390},  //duty=13, dutyLt=9
    { 829, 512,1371},  //duty=14, dutyLt=9
    { 837, 512,1354},  //duty=15, dutyLt=9
    { 853, 512,1323},  //duty=16, dutyLt=9
    { 865, 512,1298},  //duty=17, dutyLt=9
    { 877, 512,1277},  //duty=18, dutyLt=9
    { 887, 512,1258},  //duty=19, dutyLt=9
    { 895, 512,1241},  //duty=20, dutyLt=9
    { 903, 512,1227},  //duty=21, dutyLt=9
    { 910, 512,1213},  //duty=22, dutyLt=9
    { 917, 512,1200},  //duty=23, dutyLt=9
    { 922, 512,1188},  //duty=24, dutyLt=9
    { 512, 512, 512},  //duty=25, dutyLt=9
    { 512, 512, 512},  //duty=26, dutyLt=9
    { 512, 512, 512},  //duty=27, dutyLt=9
    { 512, 512, 512},  //duty=28, dutyLt=9
    { 512, 512, 512},  //duty=29, dutyLt=9
    { 533, 512,3283},  //duty=-1, dutyLt=10
    { 571, 512,2649},  //duty=0, dutyLt=10
    { 605, 512,2273},  //duty=1, dutyLt=10
    { 634, 512,2060},  //duty=2, dutyLt=10
    { 660, 512,1909},  //duty=3, dutyLt=10
    { 682, 512,1806},  //duty=4, dutyLt=10
    { 702, 512,1719},  //duty=5, dutyLt=10
    { 720, 512,1651},  //duty=6, dutyLt=10
    { 736, 512,1598},  //duty=7, dutyLt=10
    { 751, 512,1555},  //duty=8, dutyLt=10
    { 764, 512,1518},  //duty=9, dutyLt=10
    { 776, 512,1487},  //duty=10, dutyLt=10
    { 787, 512,1459},  //duty=11, dutyLt=10
    { 798, 512,1435},  //duty=12, dutyLt=10
    { 808, 512,1413},  //duty=13, dutyLt=10
    { 817, 512,1393},  //duty=14, dutyLt=10
    { 825, 512,1375},  //duty=15, dutyLt=10
    { 840, 512,1343},  //duty=16, dutyLt=10
    { 853, 512,1317},  //duty=17, dutyLt=10
    { 864, 512,1294},  //duty=18, dutyLt=10
    { 874, 512,1275},  //duty=19, dutyLt=10
    { 883, 512,1258},  //duty=20, dutyLt=10
    { 891, 512,1243},  //duty=21, dutyLt=10
    { 897, 512,1228},  //duty=22, dutyLt=10
    { 904, 512,1214},  //duty=23, dutyLt=10
    { 512, 512, 512},  //duty=24, dutyLt=10
    { 512, 512, 512},  //duty=25, dutyLt=10
    { 512, 512, 512},  //duty=26, dutyLt=10
    { 512, 512, 512},  //duty=27, dutyLt=10
    { 512, 512, 512},  //duty=28, dutyLt=10
    { 512, 512, 512},  //duty=29, dutyLt=10
    { 533, 512,3299},  //duty=-1, dutyLt=11
    { 569, 512,2660},  //duty=0, dutyLt=11
    { 601, 512,2310},  //duty=1, dutyLt=11
    { 628, 512,2098},  //duty=2, dutyLt=11
    { 653, 512,1941},  //duty=3, dutyLt=11
    { 674, 512,1832},  //duty=4, dutyLt=11
    { 693, 512,1753},  //duty=5, dutyLt=11
    { 711, 512,1687},  //duty=6, dutyLt=11
    { 726, 512,1631},  //duty=7, dutyLt=11
    { 741, 512,1586},  //duty=8, dutyLt=11
    { 754, 512,1545},  //duty=9, dutyLt=11
    { 765, 512,1511},  //duty=10, dutyLt=11
    { 777, 512,1482},  //duty=11, dutyLt=11
    { 787, 512,1458},  //duty=12, dutyLt=11
    { 796, 512,1435},  //duty=13, dutyLt=11
    { 805, 512,1414},  //duty=14, dutyLt=11
    { 813, 512,1395},  //duty=15, dutyLt=11
    { 828, 512,1362},  //duty=16, dutyLt=11
    { 841, 512,1334},  //duty=17, dutyLt=11
    { 852, 512,1311},  //duty=18, dutyLt=11
    { 862, 512,1290},  //duty=19, dutyLt=11
    { 871, 512,1273},  //duty=20, dutyLt=11
    { 879, 512,1257},  //duty=21, dutyLt=11
    { 886, 512,1243},  //duty=22, dutyLt=11
    { 893, 512,1228},  //duty=23, dutyLt=11
    { 512, 512, 512},  //duty=24, dutyLt=11
    { 512, 512, 512},  //duty=25, dutyLt=11
    { 512, 512, 512},  //duty=26, dutyLt=11
    { 512, 512, 512},  //duty=27, dutyLt=11
    { 512, 512, 512},  //duty=28, dutyLt=11
    { 512, 512, 512},  //duty=29, dutyLt=11
    { 533, 512,3283},  //duty=-1, dutyLt=12
    { 566, 512,2679},  //duty=0, dutyLt=12
    { 597, 512,2352},  //duty=1, dutyLt=12
    { 623, 512,2127},  //duty=2, dutyLt=12
    { 647, 512,1978},  //duty=3, dutyLt=12
    { 667, 512,1867},  //duty=4, dutyLt=12
    { 686, 512,1777},  //duty=5, dutyLt=12
    { 702, 512,1711},  //duty=6, dutyLt=12
    { 718, 512,1654},  //duty=7, dutyLt=12
    { 732, 512,1608},  //duty=8, dutyLt=12
    { 744, 512,1567},  //duty=9, dutyLt=12
    { 756, 512,1533},  //duty=10, dutyLt=12
    { 767, 512,1506},  //duty=11, dutyLt=12
    { 777, 512,1479},  //duty=12, dutyLt=12
    { 786, 512,1455},  //duty=13, dutyLt=12
    { 795, 512,1433},  //duty=14, dutyLt=12
    { 803, 512,1414},  //duty=15, dutyLt=12
    { 818, 512,1379},  //duty=16, dutyLt=12
    { 831, 512,1351},  //duty=17, dutyLt=12
    { 842, 512,1327},  //duty=18, dutyLt=12
    { 852, 512,1306},  //duty=19, dutyLt=12
    { 861, 512,1287},  //duty=20, dutyLt=12
    { 869, 512,1271},  //duty=21, dutyLt=12
    { 876, 512,1256},  //duty=22, dutyLt=12
    { 512, 512, 512},  //duty=23, dutyLt=12
    { 512, 512, 512},  //duty=24, dutyLt=12
    { 512, 512, 512},  //duty=25, dutyLt=12
    { 512, 512, 512},  //duty=26, dutyLt=12
    { 512, 512, 512},  //duty=27, dutyLt=12
    { 512, 512, 512},  //duty=28, dutyLt=12
    { 512, 512, 512},  //duty=29, dutyLt=12
    { 533, 512,3250},  //duty=-1, dutyLt=13
    { 565, 512,2716},  //duty=0, dutyLt=13
    { 594, 512,2366},  //duty=1, dutyLt=13
    { 619, 512,2166},  //duty=2, dutyLt=13
    { 641, 512,2003},  //duty=3, dutyLt=13
    { 661, 512,1894},  //duty=4, dutyLt=13
    { 679, 512,1809},  //duty=5, dutyLt=13
    { 695, 512,1738},  //duty=6, dutyLt=13
    { 710, 512,1680},  //duty=7, dutyLt=13
    { 723, 512,1633},  //duty=8, dutyLt=13
    { 736, 512,1592},  //duty=9, dutyLt=13
    { 748, 512,1557},  //duty=10, dutyLt=13
    { 758, 512,1526},  //duty=11, dutyLt=13
    { 768, 512,1499},  //duty=12, dutyLt=13
    { 777, 512,1475},  //duty=13, dutyLt=13
    { 785, 512,1453},  //duty=14, dutyLt=13
    { 794, 512,1433},  //duty=15, dutyLt=13
    { 809, 512,1397},  //duty=16, dutyLt=13
    { 821, 512,1368},  //duty=17, dutyLt=13
    { 832, 512,1342},  //duty=18, dutyLt=13
    { 842, 512,1321},  //duty=19, dutyLt=13
    { 851, 512,1301},  //duty=20, dutyLt=13
    { 859, 512,1284},  //duty=21, dutyLt=13
    { 866, 512,1269},  //duty=22, dutyLt=13
    { 512, 512, 512},  //duty=23, dutyLt=13
    { 512, 512, 512},  //duty=24, dutyLt=13
    { 512, 512, 512},  //duty=25, dutyLt=13
    { 512, 512, 512},  //duty=26, dutyLt=13
    { 512, 512, 512},  //duty=27, dutyLt=13
    { 512, 512, 512},  //duty=28, dutyLt=13
    { 512, 512, 512},  //duty=29, dutyLt=13
    { 533, 512,3271},  //duty=-1, dutyLt=14
    { 563, 512,2705},  //duty=0, dutyLt=14
    { 591, 512,2406},  //duty=1, dutyLt=14
    { 615, 512,2178},  //duty=2, dutyLt=14
    { 636, 512,2038},  //duty=3, dutyLt=14
    { 656, 512,1918},  //duty=4, dutyLt=14
    { 673, 512,1833},  //duty=5, dutyLt=14
    { 689, 512,1763},  //duty=6, dutyLt=14
    { 703, 512,1705},  //duty=7, dutyLt=14
    { 716, 512,1656},  //duty=8, dutyLt=14
    { 729, 512,1613},  //duty=9, dutyLt=14
    { 740, 512,1576},  //duty=10, dutyLt=14
    { 750, 512,1546},  //duty=11, dutyLt=14
    { 760, 512,1518},  //duty=12, dutyLt=14
    { 769, 512,1492},  //duty=13, dutyLt=14
    { 777, 512,1470},  //duty=14, dutyLt=14
    { 785, 512,1449},  //duty=15, dutyLt=14
    { 800, 512,1413},  //duty=16, dutyLt=14
    { 812, 512,1383},  //duty=17, dutyLt=14
    { 824, 512,1358},  //duty=18, dutyLt=14
    { 833, 512,1335},  //duty=19, dutyLt=14
    { 842, 512,1315},  //duty=20, dutyLt=14
    { 850, 512,1298},  //duty=21, dutyLt=14
    { 512, 512, 512},  //duty=22, dutyLt=14
    { 512, 512, 512},  //duty=23, dutyLt=14
    { 512, 512, 512},  //duty=24, dutyLt=14
    { 512, 512, 512},  //duty=25, dutyLt=14
    { 512, 512, 512},  //duty=26, dutyLt=14
    { 512, 512, 512},  //duty=27, dutyLt=14
    { 512, 512, 512},  //duty=28, dutyLt=14
    { 512, 512, 512},  //duty=29, dutyLt=14
    { 534, 512,3235},  //duty=-1, dutyLt=15
    { 562, 512,2740},  //duty=0, dutyLt=15
    { 588, 512,2417},  //duty=1, dutyLt=15
    { 612, 512,2210},  //duty=2, dutyLt=15
    { 632, 512,2053},  //duty=3, dutyLt=15
    { 651, 512,1946},  //duty=4, dutyLt=15
    { 668, 512,1856},  //duty=5, dutyLt=15
    { 683, 512,1784},  //duty=6, dutyLt=15
    { 697, 512,1724},  //duty=7, dutyLt=15
    { 710, 512,1675},  //duty=8, dutyLt=15
    { 722, 512,1632},  //duty=9, dutyLt=15
    { 733, 512,1597},  //duty=10, dutyLt=15
    { 743, 512,1565},  //duty=11, dutyLt=15
    { 753, 512,1536},  //duty=12, dutyLt=15
    { 762, 512,1511},  //duty=13, dutyLt=15
    { 770, 512,1487},  //duty=14, dutyLt=15
    { 778, 512,1466},  //duty=15, dutyLt=15
    { 792, 512,1428},  //duty=16, dutyLt=15
    { 805, 512,1398},  //duty=17, dutyLt=15
    { 816, 512,1371},  //duty=18, dutyLt=15
    { 826, 512,1348},  //duty=19, dutyLt=15
    { 835, 512,1328},  //duty=20, dutyLt=15
    { 842, 512,1310},  //duty=21, dutyLt=15
    { 512, 512, 512},  //duty=22, dutyLt=15
    { 512, 512, 512},  //duty=23, dutyLt=15
    { 512, 512, 512},  //duty=24, dutyLt=15
    { 512, 512, 512},  //duty=25, dutyLt=15
    { 512, 512, 512},  //duty=26, dutyLt=15
    { 512, 512, 512},  //duty=27, dutyLt=15
    { 512, 512, 512},  //duty=28, dutyLt=15
    { 512, 512, 512},  //duty=29, dutyLt=15
    { 534, 512,3231},  //duty=-1, dutyLt=16
    { 560, 512,2750},  //duty=0, dutyLt=16
    { 584, 512,2461},  //duty=1, dutyLt=16
    { 606, 512,2242},  //duty=2, dutyLt=16
    { 625, 512,2099},  //duty=3, dutyLt=16
    { 643, 512,1990},  //duty=4, dutyLt=16
    { 659, 512,1896},  //duty=5, dutyLt=16
    { 673, 512,1824},  //duty=6, dutyLt=16
    { 687, 512,1764},  //duty=7, dutyLt=16
    { 699, 512,1712},  //duty=8, dutyLt=16
    { 711, 512,1668},  //duty=9, dutyLt=16
    { 721, 512,1631},  //duty=10, dutyLt=16
    { 731, 512,1599},  //duty=11, dutyLt=16
    { 740, 512,1569},  //duty=12, dutyLt=16
    { 749, 512,1541},  //duty=13, dutyLt=16
    { 757, 512,1517},  //duty=14, dutyLt=16
    { 764, 512,1495},  //duty=15, dutyLt=16
    { 778, 512,1457},  //duty=16, dutyLt=16
    { 791, 512,1425},  //duty=17, dutyLt=16
    { 802, 512,1397},  //duty=18, dutyLt=16
    { 811, 512,1372},  //duty=19, dutyLt=16
    { 820, 512,1352},  //duty=20, dutyLt=16
    { 512, 512, 512},  //duty=21, dutyLt=16
    { 512, 512, 512},  //duty=22, dutyLt=16
    { 512, 512, 512},  //duty=23, dutyLt=16
    { 512, 512, 512},  //duty=24, dutyLt=16
    { 512, 512, 512},  //duty=25, dutyLt=16
    { 512, 512, 512},  //duty=26, dutyLt=16
    { 512, 512, 512},  //duty=27, dutyLt=16
    { 512, 512, 512},  //duty=28, dutyLt=16
    { 512, 512, 512},  //duty=29, dutyLt=16
    { 534, 512,3221},  //duty=-1, dutyLt=17
    { 559, 512,2766},  //duty=0, dutyLt=17
    { 581, 512,2491},  //duty=1, dutyLt=17
    { 602, 512,2277},  //duty=2, dutyLt=17
    { 620, 512,2139},  //duty=3, dutyLt=17
    { 636, 512,2026},  //duty=4, dutyLt=17
    { 651, 512,1933},  //duty=5, dutyLt=17
    { 665, 512,1858},  //duty=6, dutyLt=17
    { 678, 512,1799},  //duty=7, dutyLt=17
    { 690, 512,1746},  //duty=8, dutyLt=17
    { 701, 512,1701},  //duty=9, dutyLt=17
    { 711, 512,1663},  //duty=10, dutyLt=17
    { 721, 512,1629},  //duty=11, dutyLt=17
    { 729, 512,1599},  //duty=12, dutyLt=17
    { 738, 512,1570},  //duty=13, dutyLt=17
    { 746, 512,1545},  //duty=14, dutyLt=17
    { 753, 512,1522},  //duty=15, dutyLt=17
    { 767, 512,1483},  //duty=16, dutyLt=17
    { 779, 512,1449},  //duty=17, dutyLt=17
    { 789, 512,1420},  //duty=18, dutyLt=17
    { 799, 512,1395},  //duty=19, dutyLt=17
    { 512, 512, 512},  //duty=20, dutyLt=17
    { 512, 512, 512},  //duty=21, dutyLt=17
    { 512, 512, 512},  //duty=22, dutyLt=17
    { 512, 512, 512},  //duty=23, dutyLt=17
    { 512, 512, 512},  //duty=24, dutyLt=17
    { 512, 512, 512},  //duty=25, dutyLt=17
    { 512, 512, 512},  //duty=26, dutyLt=17
    { 512, 512, 512},  //duty=27, dutyLt=17
    { 512, 512, 512},  //duty=28, dutyLt=17
    { 512, 512, 512},  //duty=29, dutyLt=17
    { 535, 512,3204},  //duty=-1, dutyLt=18
    { 558, 512,2780},  //duty=0, dutyLt=18
    { 579, 512,2514},  //duty=1, dutyLt=18
    { 598, 512,2306},  //duty=2, dutyLt=18
    { 615, 512,2171},  //duty=3, dutyLt=18
    { 631, 512,2057},  //duty=4, dutyLt=18
    { 646, 512,1964},  //duty=5, dutyLt=18
    { 659, 512,1890},  //duty=6, dutyLt=18
    { 671, 512,1828},  //duty=7, dutyLt=18
    { 682, 512,1774},  //duty=8, dutyLt=18
    { 693, 512,1730},  //duty=9, dutyLt=18
    { 703, 512,1691},  //duty=10, dutyLt=18
    { 712, 512,1657},  //duty=11, dutyLt=18
    { 721, 512,1625},  //duty=12, dutyLt=18
    { 729, 512,1596},  //duty=13, dutyLt=18
    { 737, 512,1570},  //duty=14, dutyLt=18
    { 744, 512,1546},  //duty=15, dutyLt=18
    { 757, 512,1505},  //duty=16, dutyLt=18
    { 769, 512,1471},  //duty=17, dutyLt=18
    { 779, 512,1441},  //duty=18, dutyLt=18
    { 512, 512, 512},  //duty=19, dutyLt=18
    { 512, 512, 512},  //duty=20, dutyLt=18
    { 512, 512, 512},  //duty=21, dutyLt=18
    { 512, 512, 512},  //duty=22, dutyLt=18
    { 512, 512, 512},  //duty=23, dutyLt=18
    { 512, 512, 512},  //duty=24, dutyLt=18
    { 512, 512, 512},  //duty=25, dutyLt=18
    { 512, 512, 512},  //duty=26, dutyLt=18
    { 512, 512, 512},  //duty=27, dutyLt=18
    { 512, 512, 512},  //duty=28, dutyLt=18
    { 512, 512, 512},  //duty=29, dutyLt=18
    { 535, 512,3193},  //duty=-1, dutyLt=19
    { 557, 512,2790},  //duty=0, dutyLt=19
    { 577, 512,2532},  //duty=1, dutyLt=19
    { 595, 512,2333},  //duty=2, dutyLt=19
    { 612, 512,2195},  //duty=3, dutyLt=19
    { 627, 512,2087},  //duty=4, dutyLt=19
    { 641, 512,1992},  //duty=5, dutyLt=19
    { 653, 512,1917},  //duty=6, dutyLt=19
    { 665, 512,1854},  //duty=7, dutyLt=19
    { 676, 512,1802},  //duty=8, dutyLt=19
    { 686, 512,1755},  //duty=9, dutyLt=19
    { 696, 512,1717},  //duty=10, dutyLt=19
    { 705, 512,1681},  //duty=11, dutyLt=19
    { 713, 512,1647},  //duty=12, dutyLt=19
    { 721, 512,1619},  //duty=13, dutyLt=19
    { 729, 512,1592},  //duty=14, dutyLt=19
    { 736, 512,1569},  //duty=15, dutyLt=19
    { 749, 512,1526},  //duty=16, dutyLt=19
    { 760, 512,1492},  //duty=17, dutyLt=19
    { 512, 512, 512},  //duty=18, dutyLt=19
    { 512, 512, 512},  //duty=19, dutyLt=19
    { 512, 512, 512},  //duty=20, dutyLt=19
    { 512, 512, 512},  //duty=21, dutyLt=19
    { 512, 512, 512},  //duty=22, dutyLt=19
    { 512, 512, 512},  //duty=23, dutyLt=19
    { 512, 512, 512},  //duty=24, dutyLt=19
    { 512, 512, 512},  //duty=25, dutyLt=19
    { 512, 512, 512},  //duty=26, dutyLt=19
    { 512, 512, 512},  //duty=27, dutyLt=19
    { 512, 512, 512},  //duty=28, dutyLt=19
    { 512, 512, 512},  //duty=29, dutyLt=19
    { 536, 512,3181},  //duty=-1, dutyLt=20
    { 557, 512,2800},  //duty=0, dutyLt=20
    { 576, 512,2547},  //duty=1, dutyLt=20
    { 593, 512,2353},  //duty=2, dutyLt=20
    { 609, 512,2216},  //duty=3, dutyLt=20
    { 623, 512,2111},  //duty=4, dutyLt=20
    { 637, 512,2018},  //duty=5, dutyLt=20
    { 649, 512,1942},  //duty=6, dutyLt=20
    { 660, 512,1879},  //duty=7, dutyLt=20
    { 671, 512,1824},  //duty=8, dutyLt=20
    { 681, 512,1779},  //duty=9, dutyLt=20
    { 690, 512,1739},  //duty=10, dutyLt=20
    { 699, 512,1701},  //duty=11, dutyLt=20
    { 707, 512,1668},  //duty=12, dutyLt=20
    { 715, 512,1639},  //duty=13, dutyLt=20
    { 722, 512,1612},  //duty=14, dutyLt=20
    { 729, 512,1587},  //duty=15, dutyLt=20
    { 741, 512,1545},  //duty=16, dutyLt=20
    { 512, 512, 512},  //duty=17, dutyLt=20
    { 512, 512, 512},  //duty=18, dutyLt=20
    { 512, 512, 512},  //duty=19, dutyLt=20
    { 512, 512, 512},  //duty=20, dutyLt=20
    { 512, 512, 512},  //duty=21, dutyLt=20
    { 512, 512, 512},  //duty=22, dutyLt=20
    { 512, 512, 512},  //duty=23, dutyLt=20
    { 512, 512, 512},  //duty=24, dutyLt=20
    { 512, 512, 512},  //duty=25, dutyLt=20
    { 512, 512, 512},  //duty=26, dutyLt=20
    { 512, 512, 512},  //duty=27, dutyLt=20
    { 512, 512, 512},  //duty=28, dutyLt=20
    { 512, 512, 512},  //duty=29, dutyLt=20
    { 537, 512,3166},  //duty=-1, dutyLt=21
    { 556, 512,2804},  //duty=0, dutyLt=21
    { 575, 512,2556},  //duty=1, dutyLt=21
    { 591, 512,2372},  //duty=2, dutyLt=21
    { 606, 512,2236},  //duty=3, dutyLt=21
    { 620, 512,2127},  //duty=4, dutyLt=21
    { 633, 512,2038},  //duty=5, dutyLt=21
    { 645, 512,1963},  //duty=6, dutyLt=21
    { 656, 512,1899},  //duty=7, dutyLt=21
    { 666, 512,1845},  //duty=8, dutyLt=21
    { 676, 512,1800},  //duty=9, dutyLt=21
    { 685, 512,1757},  //duty=10, dutyLt=21
    { 694, 512,1720},  //duty=11, dutyLt=21
    { 702, 512,1687},  //duty=12, dutyLt=21
    { 709, 512,1656},  //duty=13, dutyLt=21
    { 717, 512,1629},  //duty=14, dutyLt=21
    { 723, 512,1604},  //duty=15, dutyLt=21
    { 512, 512, 512},  //duty=16, dutyLt=21
    { 512, 512, 512},  //duty=17, dutyLt=21
    { 512, 512, 512},  //duty=18, dutyLt=21
    { 512, 512, 512},  //duty=19, dutyLt=21
    { 512, 512, 512},  //duty=20, dutyLt=21
    { 512, 512, 512},  //duty=21, dutyLt=21
    { 512, 512, 512},  //duty=22, dutyLt=21
    { 512, 512, 512},  //duty=23, dutyLt=21
    { 512, 512, 512},  //duty=24, dutyLt=21
    { 512, 512, 512},  //duty=25, dutyLt=21
    { 512, 512, 512},  //duty=26, dutyLt=21
    { 512, 512, 512},  //duty=27, dutyLt=21
    { 512, 512, 512},  //duty=28, dutyLt=21
    { 512, 512, 512},  //duty=29, dutyLt=21
    { 537, 512,3151},  //duty=-1, dutyLt=22
    { 556, 512,2805},  //duty=0, dutyLt=22
    { 574, 512,2565},  //duty=1, dutyLt=22
    { 590, 512,2389},  //duty=2, dutyLt=22
    { 605, 512,2247},  //duty=3, dutyLt=22
    { 618, 512,2141},  //duty=4, dutyLt=22
    { 630, 512,2053},  //duty=5, dutyLt=22
    { 642, 512,1981},  //duty=6, dutyLt=22
    { 652, 512,1918},  //duty=7, dutyLt=22
    { 663, 512,1862},  //duty=8, dutyLt=22
    { 672, 512,1815},  //duty=9, dutyLt=22
    { 681, 512,1773},  //duty=10, dutyLt=22
    { 689, 512,1737},  //duty=11, dutyLt=22
    { 697, 512,1702},  //duty=12, dutyLt=22
    { 705, 512,1672},  //duty=13, dutyLt=22
    { 512, 512, 512},  //duty=14, dutyLt=22
    { 512, 512, 512},  //duty=15, dutyLt=22
    { 512, 512, 512},  //duty=16, dutyLt=22
    { 512, 512, 512},  //duty=17, dutyLt=22
    { 512, 512, 512},  //duty=18, dutyLt=22
    { 512, 512, 512},  //duty=19, dutyLt=22
    { 512, 512, 512},  //duty=20, dutyLt=22
    { 512, 512, 512},  //duty=21, dutyLt=22
    { 512, 512, 512},  //duty=22, dutyLt=22
    { 512, 512, 512},  //duty=23, dutyLt=22
    { 512, 512, 512},  //duty=24, dutyLt=22
    { 512, 512, 512},  //duty=25, dutyLt=22
    { 512, 512, 512},  //duty=26, dutyLt=22
    { 512, 512, 512},  //duty=27, dutyLt=22
    { 512, 512, 512},  //duty=28, dutyLt=22
    { 512, 512, 512},  //duty=29, dutyLt=22
    { 538, 512,3133},  //duty=-1, dutyLt=23
    { 556, 512,2812},  //duty=0, dutyLt=23
    { 573, 512,2572},  //duty=1, dutyLt=23
    { 589, 512,2399},  //duty=2, dutyLt=23
    { 603, 512,2265},  //duty=3, dutyLt=23
    { 616, 512,2156},  //duty=4, dutyLt=23
    { 628, 512,2065},  //duty=5, dutyLt=23
    { 640, 512,1991},  //duty=6, dutyLt=23
    { 650, 512,1929},  //duty=7, dutyLt=23
    { 660, 512,1877},  //duty=8, dutyLt=23
    { 669, 512,1830},  //duty=9, dutyLt=23
    { 678, 512,1788},  //duty=10, dutyLt=23
    { 686, 512,1752},  //duty=11, dutyLt=23
    { 512, 512, 512},  //duty=12, dutyLt=23
    { 512, 512, 512},  //duty=13, dutyLt=23
    { 512, 512, 512},  //duty=14, dutyLt=23
    { 512, 512, 512},  //duty=15, dutyLt=23
    { 512, 512, 512},  //duty=16, dutyLt=23
    { 512, 512, 512},  //duty=17, dutyLt=23
    { 512, 512, 512},  //duty=18, dutyLt=23
    { 512, 512, 512},  //duty=19, dutyLt=23
    { 512, 512, 512},  //duty=20, dutyLt=23
    { 512, 512, 512},  //duty=21, dutyLt=23
    { 512, 512, 512},  //duty=22, dutyLt=23
    { 512, 512, 512},  //duty=23, dutyLt=23
    { 512, 512, 512},  //duty=24, dutyLt=23
    { 512, 512, 512},  //duty=25, dutyLt=23
    { 512, 512, 512},  //duty=26, dutyLt=23
    { 512, 512, 512},  //duty=27, dutyLt=23
    { 512, 512, 512},  //duty=28, dutyLt=23
    { 512, 512, 512},  //duty=29, dutyLt=23
    { 539, 512,3121},  //duty=-1, dutyLt=24
    { 556, 512,2811},  //duty=0, dutyLt=24
    { 573, 512,2580},  //duty=1, dutyLt=24
    { 588, 512,2408},  //duty=2, dutyLt=24
    { 602, 512,2275},  //duty=3, dutyLt=24
    { 615, 512,2170},  //duty=4, dutyLt=24
    { 626, 512,2082},  //duty=5, dutyLt=24
    { 637, 512,2008},  //duty=6, dutyLt=24
    { 648, 512,1945},  //duty=7, dutyLt=24
    { 657, 512,1891},  //duty=8, dutyLt=24
    { 666, 512,1843},  //duty=9, dutyLt=24
    { 512, 512, 512},  //duty=10, dutyLt=24
    { 512, 512, 512},  //duty=11, dutyLt=24
    { 512, 512, 512},  //duty=12, dutyLt=24
    { 512, 512, 512},  //duty=13, dutyLt=24
    { 512, 512, 512},  //duty=14, dutyLt=24
    { 512, 512, 512},  //duty=15, dutyLt=24
    { 512, 512, 512},  //duty=16, dutyLt=24
    { 512, 512, 512},  //duty=17, dutyLt=24
    { 512, 512, 512},  //duty=18, dutyLt=24
    { 512, 512, 512},  //duty=19, dutyLt=24
    { 512, 512, 512},  //duty=20, dutyLt=24
    { 512, 512, 512},  //duty=21, dutyLt=24
    { 512, 512, 512},  //duty=22, dutyLt=24
    { 512, 512, 512},  //duty=23, dutyLt=24
    { 512, 512, 512},  //duty=24, dutyLt=24
    { 512, 512, 512},  //duty=25, dutyLt=24
    { 512, 512, 512},  //duty=26, dutyLt=24
    { 512, 512, 512},  //duty=27, dutyLt=24
    { 512, 512, 512},  //duty=28, dutyLt=24
    { 512, 512, 512},  //duty=29, dutyLt=24
    { 539, 512,3119},  //duty=-1, dutyLt=25
    { 557, 512,2806},  //duty=0, dutyLt=25
    { 573, 512,2584},  //duty=1, dutyLt=25
    { 587, 512,2416},  //duty=2, dutyLt=25
    { 601, 512,2282},  //duty=3, dutyLt=25
    { 613, 512,2177},  //duty=4, dutyLt=25
    { 625, 512,2092},  //duty=5, dutyLt=25
    { 636, 512,2017},  //duty=6, dutyLt=25
    { 646, 512,1955},  //duty=7, dutyLt=25
    { 512, 512, 512},  //duty=8, dutyLt=25
    { 512, 512, 512},  //duty=9, dutyLt=25
    { 512, 512, 512},  //duty=10, dutyLt=25
    { 512, 512, 512},  //duty=11, dutyLt=25
    { 512, 512, 512},  //duty=12, dutyLt=25
    { 512, 512, 512},  //duty=13, dutyLt=25
    { 512, 512, 512},  //duty=14, dutyLt=25
    { 512, 512, 512},  //duty=15, dutyLt=25
    { 512, 512, 512},  //duty=16, dutyLt=25
    { 512, 512, 512},  //duty=17, dutyLt=25
    { 512, 512, 512},  //duty=18, dutyLt=25
    { 512, 512, 512},  //duty=19, dutyLt=25
    { 512, 512, 512},  //duty=20, dutyLt=25
    { 512, 512, 512},  //duty=21, dutyLt=25
    { 512, 512, 512},  //duty=22, dutyLt=25
    { 512, 512, 512},  //duty=23, dutyLt=25
    { 512, 512, 512},  //duty=24, dutyLt=25
    { 512, 512, 512},  //duty=25, dutyLt=25
    { 512, 512, 512},  //duty=26, dutyLt=25
    { 512, 512, 512},  //duty=27, dutyLt=25
    { 512, 512, 512},  //duty=28, dutyLt=25
    { 512, 512, 512},  //duty=29, dutyLt=25
    { 540, 512,3101},  //duty=-1, dutyLt=26
    { 557, 512,2803},  //duty=0, dutyLt=26
    { 573, 512,2586},  //duty=1, dutyLt=26
    { 587, 512,2420},  //duty=2, dutyLt=26
    { 600, 512,2292},  //duty=3, dutyLt=26
    { 613, 512,2186},  //duty=4, dutyLt=26
    { 624, 512,2099},  //duty=5, dutyLt=26
    { 512, 512, 512},  //duty=6, dutyLt=26
    { 512, 512, 512},  //duty=7, dutyLt=26
    { 512, 512, 512},  //duty=8, dutyLt=26
    { 512, 512, 512},  //duty=9, dutyLt=26
    { 512, 512, 512},  //duty=10, dutyLt=26
    { 512, 512, 512},  //duty=11, dutyLt=26
    { 512, 512, 512},  //duty=12, dutyLt=26
    { 512, 512, 512},  //duty=13, dutyLt=26
    { 512, 512, 512},  //duty=14, dutyLt=26
    { 512, 512, 512},  //duty=15, dutyLt=26
    { 512, 512, 512},  //duty=16, dutyLt=26
    { 512, 512, 512},  //duty=17, dutyLt=26
    { 512, 512, 512},  //duty=18, dutyLt=26
    { 512, 512, 512},  //duty=19, dutyLt=26
    { 512, 512, 512},  //duty=20, dutyLt=26
    { 512, 512, 512},  //duty=21, dutyLt=26
    { 512, 512, 512},  //duty=22, dutyLt=26
    { 512, 512, 512},  //duty=23, dutyLt=26
    { 512, 512, 512},  //duty=24, dutyLt=26
    { 512, 512, 512},  //duty=25, dutyLt=26
    { 512, 512, 512},  //duty=26, dutyLt=26
    { 512, 512, 512},  //duty=27, dutyLt=26
    { 512, 512, 512},  //duty=28, dutyLt=26
    { 512, 512, 512},  //duty=29, dutyLt=26
    { 541, 512,3086},  //duty=-1, dutyLt=27
    { 558, 512,2800},  //duty=0, dutyLt=27
    { 573, 512,2585},  //duty=1, dutyLt=27
    { 587, 512,2427},  //duty=2, dutyLt=27
    { 600, 512,2296},  //duty=3, dutyLt=27
    { 512, 512, 512},  //duty=4, dutyLt=27
    { 512, 512, 512},  //duty=5, dutyLt=27
    { 512, 512, 512},  //duty=6, dutyLt=27
    { 512, 512, 512},  //duty=7, dutyLt=27
    { 512, 512, 512},  //duty=8, dutyLt=27
    { 512, 512, 512},  //duty=9, dutyLt=27
    { 512, 512, 512},  //duty=10, dutyLt=27
    { 512, 512, 512},  //duty=11, dutyLt=27
    { 512, 512, 512},  //duty=12, dutyLt=27
    { 512, 512, 512},  //duty=13, dutyLt=27
    { 512, 512, 512},  //duty=14, dutyLt=27
    { 512, 512, 512},  //duty=15, dutyLt=27
    { 512, 512, 512},  //duty=16, dutyLt=27
    { 512, 512, 512},  //duty=17, dutyLt=27
    { 512, 512, 512},  //duty=18, dutyLt=27
    { 512, 512, 512},  //duty=19, dutyLt=27
    { 512, 512, 512},  //duty=20, dutyLt=27
    { 512, 512, 512},  //duty=21, dutyLt=27
    { 512, 512, 512},  //duty=22, dutyLt=27
    { 512, 512, 512},  //duty=23, dutyLt=27
    { 512, 512, 512},  //duty=24, dutyLt=27
    { 512, 512, 512},  //duty=25, dutyLt=27
    { 512, 512, 512},  //duty=26, dutyLt=27
    { 512, 512, 512},  //duty=27, dutyLt=27
    { 512, 512, 512},  //duty=28, dutyLt=27
    { 512, 512, 512},  //duty=29, dutyLt=27
    { 542, 512,3081},  //duty=-1, dutyLt=28
    { 558, 512,2792},  //duty=0, dutyLt=28
    { 573, 512,2585},  //duty=1, dutyLt=28
    { 512, 512, 512},  //duty=2, dutyLt=28
    { 512, 512, 512},  //duty=3, dutyLt=28
    { 512, 512, 512},  //duty=4, dutyLt=28
    { 512, 512, 512},  //duty=5, dutyLt=28
    { 512, 512, 512},  //duty=6, dutyLt=28
    { 512, 512, 512},  //duty=7, dutyLt=28
    { 512, 512, 512},  //duty=8, dutyLt=28
    { 512, 512, 512},  //duty=9, dutyLt=28
    { 512, 512, 512},  //duty=10, dutyLt=28
    { 512, 512, 512},  //duty=11, dutyLt=28
    { 512, 512, 512},  //duty=12, dutyLt=28
    { 512, 512, 512},  //duty=13, dutyLt=28
    { 512, 512, 512},  //duty=14, dutyLt=28
    { 512, 512, 512},  //duty=15, dutyLt=28
    { 512, 512, 512},  //duty=16, dutyLt=28
    { 512, 512, 512},  //duty=17, dutyLt=28
    { 512, 512, 512},  //duty=18, dutyLt=28
    { 512, 512, 512},  //duty=19, dutyLt=28
    { 512, 512, 512},  //duty=20, dutyLt=28
    { 512, 512, 512},  //duty=21, dutyLt=28
    { 512, 512, 512},  //duty=22, dutyLt=28
    { 512, 512, 512},  //duty=23, dutyLt=28
    { 512, 512, 512},  //duty=24, dutyLt=28
    { 512, 512, 512},  //duty=25, dutyLt=28
    { 512, 512, 512},  //duty=26, dutyLt=28
    { 512, 512, 512},  //duty=27, dutyLt=28
    { 512, 512, 512},  //duty=28, dutyLt=28
    { 512, 512, 512},  //duty=29, dutyLt=28
    { 543, 512,3057},  //duty=-1, dutyLt=29
    { 512, 512, 512},  //duty=0, dutyLt=29
    { 512, 512, 512},  //duty=1, dutyLt=29
    { 512, 512, 512},  //duty=2, dutyLt=29
    { 512, 512, 512},  //duty=3, dutyLt=29
    { 512, 512, 512},  //duty=4, dutyLt=29
    { 512, 512, 512},  //duty=5, dutyLt=29
    { 512, 512, 512},  //duty=6, dutyLt=29
    { 512, 512, 512},  //duty=7, dutyLt=29
    { 512, 512, 512},  //duty=8, dutyLt=29
    { 512, 512, 512},  //duty=9, dutyLt=29
    { 512, 512, 512},  //duty=10, dutyLt=29
    { 512, 512, 512},  //duty=11, dutyLt=29
    { 512, 512, 512},  //duty=12, dutyLt=29
    { 512, 512, 512},  //duty=13, dutyLt=29
    { 512, 512, 512},  //duty=14, dutyLt=29
    { 512, 512, 512},  //duty=15, dutyLt=29
    { 512, 512, 512},  //duty=16, dutyLt=29
    { 512, 512, 512},  //duty=17, dutyLt=29
    { 512, 512, 512},  //duty=18, dutyLt=29
    { 512, 512, 512},  //duty=19, dutyLt=29
    { 512, 512, 512},  //duty=20, dutyLt=29
    { 512, 512, 512},  //duty=21, dutyLt=29
    { 512, 512, 512},  //duty=22, dutyLt=29
    { 512, 512, 512},  //duty=23, dutyLt=29
    { 512, 512, 512},  //duty=24, dutyLt=29
    { 512, 512, 512},  //duty=25, dutyLt=29
    { 512, 512, 512},  //duty=26, dutyLt=29
    { 512, 512, 512},  //duty=27, dutyLt=29
    { 512, 512, 512},  //duty=28, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    { 512, 512, 512},  //duty=29, dutyLt=29
    },
};