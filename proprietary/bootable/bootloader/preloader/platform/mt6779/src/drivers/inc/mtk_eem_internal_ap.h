/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * MediaTek Inc. (C) 2016. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */

#ifndef _MTK_EEM_INTERNAL_AP_H_
#define _MTK_EEM_INTERNAL_AP_H_
#include "mtk_eem.h"
struct eem_det;
//ruct eem_ctrl;

struct eem_det_ops {
	/* interface to EEM */
	void (*switch_bank)(struct eem_det *det, enum eem_phase phase);
	int (*init01)(struct eem_det *det);
	void (*set_phase)(struct eem_det *det, enum eem_phase phase);
#if EEM_CHECK_VOLT
	int (*get_volt)(struct eem_det *det);
	int (*volt_2_eem)(struct eem_det *det, int volt);
#endif
};

struct eem_det {
	const char *name;
	struct eem_det_ops *ops;
	int status;			/* TODO: enable/disable */
	int features;		/* enum eem_features */
	/* enum eem_ctrl_id ctrl_id; */
	unsigned int realptpid;

	/* constant */
	unsigned int DETWINDOW;
	unsigned int VMAX;
	unsigned int VMIN;
	unsigned int DTHI;
	unsigned int DTLO;
	unsigned int VBOOT;
	unsigned int DETMAX;
	unsigned int AGECONFIG;
	unsigned int AGEM;
	unsigned int DCCONFIG;

	/* Generated by EEM init01. Used in EEM init02 */
	unsigned int DCVOFFSETIN;
	unsigned int AGEVOFFSETIN;
	unsigned int EEMCTL0;

#if EEM_CHECK_VOLT
	/* for PMIC */
	unsigned int eem_v_base;
	unsigned int eem_step;
	unsigned int pmic_base;
	unsigned int pmic_step;
	unsigned int real_vboot;
#endif

	/* for debug */
	unsigned int eem_eemEn[NR_EEM_PHASE];
};



/**************************************************
 *extern variables and operations defined at mtk_eem_platform.c
 ***************************************************
 */
//extern struct eem_det_ops cpu_det_ops;

/*********************************************
 *extern operations defined at mtk_eem.c
 *********************************************
 */
#if 0
extern void base_ops_switch_bank(struct eem_det *det, enum eem_phase phase);
extern int base_ops_init01(struct eem_det *det);
extern void base_ops_set_phase(struct eem_det *det, enum eem_phase phase);
extern int base_ops_get_volt(struct eem_det *det);
#endif
#endif
