/*
 * Copyright (c) 2017, ARM Limited and Contributors. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of ARM nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __PLATFORM_DEBUG_H__
#define __PLATFORM_DEBUG_H__

#define MCU_ALL_PWR_ON_CTRL	(MCUCFG_BASE + 0xB58)

#define readl(addr)		mmio_read_32((addr))
#define writel(addr, val)	mmio_write_32((addr), (val))
#define sync_writel(addr, val)	do { mmio_write_32((addr), (val)); dsbsy(); } while (0)

#define MCU_BIU_BASE				MCUCFG_BASE
#define MISC1_CFG_BASE				(0xb00)
#define DFD_INTERNAL_CTL			(MCU_BIU_BASE+MISC1_CFG_BASE+0x00)
#define DFD_INTERNAL_PWR_ON			(MCU_BIU_BASE+MISC1_CFG_BASE+0x08)
#define DFD_CHAIN_LENGTH0			(MCU_BIU_BASE+MISC1_CFG_BASE+0x0c)
#define DFD_INTERNAL_SHIFT_CLK_RATIO		(MCU_BIU_BASE+MISC1_CFG_BASE+0x10)
#define DFD_INTERNAL_TEST_SO_0			(MCU_BIU_BASE+MISC1_CFG_BASE+0x28)
#define DFD_INTERNAL_NUM_OF_TEST_SO_GROUP	(MCU_BIU_BASE+MISC1_CFG_BASE+0x30)
#define DFD_V30_CTL				(MCU_BIU_BASE+MISC1_CFG_BASE+0x100)
#define DFD_V30_BASE_ADDR			(MCU_BIU_BASE+MISC1_CFG_BASE+0x104)

extern void clear_all_on_mux(void);
extern int dfd_smc_dispatcher(unsigned long arg0, unsigned long arg1, unsigned long arg2);
#endif