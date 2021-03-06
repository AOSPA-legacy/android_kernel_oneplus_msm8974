/* Copyright (c) 2010-2012, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __ARCH_ARM_MACH_MSM_RPM_H
#define __ARCH_ARM_MACH_MSM_RPM_H

#include <linux/types.h>
#include <linux/list.h>
#include <linux/semaphore.h>

#include <mach/rpm-8660.h>
#include <mach/rpm-9615.h>
#include <mach/rpm-8960.h>
#include <mach/rpm-8930.h>
#include <mach/rpm-8064.h>

#define SEL_MASK_SIZE (5)

enum {
	MSM_RPM_PAGE_STATUS,
	MSM_RPM_PAGE_CTRL,
	MSM_RPM_PAGE_REQ,
	MSM_RPM_PAGE_ACK,
	MSM_RPM_PAGE_COUNT
};

enum {
	MSM_RPM_CTX_SET_0,
	MSM_RPM_CTX_SET_SLEEP,
	MSM_RPM_CTX_SET_COUNT,

	MSM_RPM_CTX_NOTIFICATION = 30,
	MSM_RPM_CTX_REJECTED = 31,
};

/* RPM control message RAM enums */
enum {
	MSM_RPM_CTRL_VERSION_MAJOR,
	MSM_RPM_CTRL_VERSION_MINOR,
	MSM_RPM_CTRL_VERSION_BUILD,

	MSM_RPM_CTRL_REQ_CTX_0,
	MSM_RPM_CTRL_REQ_SEL_0,
	MSM_RPM_CTRL_ACK_CTX_0,
	MSM_RPM_CTRL_ACK_SEL_0,

	MSM_RPM_CTRL_LAST,
};

enum {
	MSM_RPM_ID_NOTIFICATION_CONFIGURED_0 = 0,
	MSM_RPM_ID_NOTIFICATION_CONFIGURED_7 =
		MSM_RPM_ID_NOTIFICATION_CONFIGURED_0 + 7,

	MSM_RPM_ID_NOTIFICATION_REGISTERED_0,
	MSM_RPM_ID_NOTIFICATION_REGISTERED_7 =
		MSM_RPM_ID_NOTIFICATION_REGISTERED_0 + 7,

	MSM_RPM_ID_INVALIDATE_0,
	MSM_RPM_ID_INVALIDATE_7 =
		MSM_RPM_ID_INVALIDATE_0 + 7,

	MSM_RPM_ID_TRIGGER_TIMED_TO,
	MSM_RPM_ID_TRIGGER_TIMED_0,
	MSM_RPM_ID_TRIGGER_TIMED_SCLK_COUNT,

	MSM_RPM_ID_RPM_CTL,

	/* TRIGGER_CLEAR/SET deprecated in these 24 RESERVED bytes */
	MSM_RPM_ID_RESERVED_0,
	MSM_RPM_ID_RESERVED_5 =
		MSM_RPM_ID_RESERVED_0 + 5,

	MSM_RPM_ID_CXO_CLK,
	MSM_RPM_ID_PXO_CLK,
	MSM_RPM_ID_APPS_FABRIC_CLK,
	MSM_RPM_ID_SYSTEM_FABRIC_CLK,
	MSM_RPM_ID_MM_FABRIC_CLK,
	MSM_RPM_ID_DAYTONA_FABRIC_CLK,
	MSM_RPM_ID_SFPB_CLK,
	MSM_RPM_ID_CFPB_CLK,
	MSM_RPM_ID_MMFPB_CLK,
	MSM_RPM_ID_EBI1_CLK,

	MSM_RPM_ID_APPS_FABRIC_CFG_HALT_0,
	MSM_RPM_ID_APPS_FABRIC_HALT_0 =
		MSM_RPM_ID_APPS_FABRIC_CFG_HALT_0,
	MSM_RPM_ID_APPS_FABRIC_CFG_HALT_1,
	MSM_RPM_ID_APPS_FABRIC_CFG_CLKMOD_0,
	MSM_RPM_ID_APPS_FABRIC_CLOCK_MODE_0 =
		MSM_RPM_ID_APPS_FABRIC_CFG_CLKMOD_0,
	MSM_RPM_ID_APPS_FABRIC_CFG_CLKMOD_1,
	MSM_RPM_ID_APPS_FABRIC_CFG_CLKMOD_2,
	MSM_RPM_ID_APPS_FABRIC_CFG_IOCTL,
	MSM_RPM_ID_APPS_FABRIC_ARB_0,
	MSM_RPM_ID_APPS_FABRIC_ARB_11 =
		MSM_RPM_ID_APPS_FABRIC_ARB_0 + 11,

	MSM_RPM_ID_SYS_FABRIC_CFG_HALT_0,
	MSM_RPM_ID_SYSTEM_FABRIC_HALT_0 =
		MSM_RPM_ID_SYS_FABRIC_CFG_HALT_0,
	MSM_RPM_ID_SYS_FABRIC_CFG_HALT_1,
	MSM_RPM_ID_SYS_FABRIC_CFG_CLKMOD_0,
	MSM_RPM_ID_SYSTEM_FABRIC_CLOCK_MODE_0 =
		MSM_RPM_ID_SYS_FABRIC_CFG_CLKMOD_0,
	MSM_RPM_ID_SYS_FABRIC_CFG_CLKMOD_1,
	MSM_RPM_ID_SYS_FABRIC_CFG_CLKMOD_2,
	MSM_RPM_ID_SYS_FABRIC_CFG_IOCTL,
	MSM_RPM_ID_SYSTEM_FABRIC_ARB_0,
	MSM_RPM_ID_SYSTEM_FABRIC_ARB_29 =
		MSM_RPM_ID_SYSTEM_FABRIC_ARB_0 + 29,

	MSM_RPM_ID_MMSS_FABRIC_CFG_HALT_0,
	MSM_RPM_ID_MM_FABRIC_HALT_0 =
		MSM_RPM_ID_MMSS_FABRIC_CFG_HALT_0,
	MSM_RPM_ID_MMSS_FABRIC_CFG_HALT_1,
	MSM_RPM_ID_MMSS_FABRIC_CFG_CLKMOD_0,
	MSM_RPM_ID_MM_FABRIC_CLOCK_MODE_0 =
		MSM_RPM_ID_MMSS_FABRIC_CFG_CLKMOD_0,
	MSM_RPM_ID_MMSS_FABRIC_CFG_CLKMOD_1,
	MSM_RPM_ID_MMSS_FABRIC_CFG_CLKMOD_2,
	MSM_RPM_ID_MMSS_FABRIC_CFG_IOCTL,
	MSM_RPM_ID_MM_FABRIC_ARB_0,
	MSM_RPM_ID_MM_FABRIC_ARB_22 =
		MSM_RPM_ID_MM_FABRIC_ARB_0 + 22,

	MSM_RPM_ID_PM8921_S1_0,
	MSM_RPM_ID_PM8921_S1_1,
	MSM_RPM_ID_PM8921_S2_0,
	MSM_RPM_ID_PM8921_S2_1,
	MSM_RPM_ID_PM8921_S3_0,
	MSM_RPM_ID_PM8921_S3_1,
	MSM_RPM_ID_PM8921_S4_0,
	MSM_RPM_ID_PM8921_S4_1,
	MSM_RPM_ID_PM8921_S5_0,
	MSM_RPM_ID_PM8921_S5_1,
	MSM_RPM_ID_PM8921_S6_0,
	MSM_RPM_ID_PM8921_S6_1,
	MSM_RPM_ID_PM8921_S7_0,
	MSM_RPM_ID_PM8921_S7_1,
	MSM_RPM_ID_PM8921_S8_0,
	MSM_RPM_ID_PM8921_S8_1,
	MSM_RPM_ID_PM8921_L1_0,
	MSM_RPM_ID_PM8921_L1_1,
	MSM_RPM_ID_PM8921_L2_0,
	MSM_RPM_ID_PM8921_L2_1,
	MSM_RPM_ID_PM8921_L3_0,
	MSM_RPM_ID_PM8921_L3_1,
	MSM_RPM_ID_PM8921_L4_0,
	MSM_RPM_ID_PM8921_L4_1,
	MSM_RPM_ID_PM8921_L5_0,
	MSM_RPM_ID_PM8921_L5_1,
	MSM_RPM_ID_PM8921_L6_0,
	MSM_RPM_ID_PM8921_L6_1,
	MSM_RPM_ID_PM8921_L7_0,
	MSM_RPM_ID_PM8921_L7_1,
	MSM_RPM_ID_PM8921_L8_0,
	MSM_RPM_ID_PM8921_L8_1,
	MSM_RPM_ID_PM8921_L9_0,
	MSM_RPM_ID_PM8921_L9_1,
	MSM_RPM_ID_PM8921_L10_0,
	MSM_RPM_ID_PM8921_L10_1,
	MSM_RPM_ID_PM8921_L11_0,
	MSM_RPM_ID_PM8921_L11_1,
	MSM_RPM_ID_PM8921_L12_0,
	MSM_RPM_ID_PM8921_L12_1,
	MSM_RPM_ID_PM8921_L13_0,
	MSM_RPM_ID_PM8921_L13_1,
	MSM_RPM_ID_PM8921_L14_0,
	MSM_RPM_ID_PM8921_L14_1,
	MSM_RPM_ID_PM8921_L15_0,
	MSM_RPM_ID_PM8921_L15_1,
	MSM_RPM_ID_PM8921_L16_0,
	MSM_RPM_ID_PM8921_L16_1,
	MSM_RPM_ID_PM8921_L17_0,
	MSM_RPM_ID_PM8921_L17_1,
	MSM_RPM_ID_PM8921_L18_0,
	MSM_RPM_ID_PM8921_L18_1,
	MSM_RPM_ID_PM8921_L19_0,
	MSM_RPM_ID_PM8921_L19_1,
	MSM_RPM_ID_PM8921_L20_0,
	MSM_RPM_ID_PM8921_L20_1,
	MSM_RPM_ID_PM8921_L21_0,
	MSM_RPM_ID_PM8921_L21_1,
	MSM_RPM_ID_PM8921_L22_0,
	MSM_RPM_ID_PM8921_L22_1,
	MSM_RPM_ID_PM8921_L23_0,
	MSM_RPM_ID_PM8921_L23_1,
	MSM_RPM_ID_PM8921_L24_0,
	MSM_RPM_ID_PM8921_L24_1,
	MSM_RPM_ID_PM8921_L25_0,
	MSM_RPM_ID_PM8921_L25_1,
	MSM_RPM_ID_PM8921_L26_0,
	MSM_RPM_ID_PM8921_L26_1,
	MSM_RPM_ID_PM8921_L27_0,
	MSM_RPM_ID_PM8921_L27_1,
	MSM_RPM_ID_PM8921_L28_0,
	MSM_RPM_ID_PM8921_L28_1,
	MSM_RPM_ID_PM8921_L29_0,
	MSM_RPM_ID_PM8921_L29_1,
	MSM_RPM_ID_PM8921_CLK1_0,
	MSM_RPM_ID_PM8921_CLK1_1,
	MSM_RPM_ID_PM8921_CLK2_0,
	MSM_RPM_ID_PM8921_CLK2_1,
	MSM_RPM_ID_PM8921_LVS1,
	MSM_RPM_ID_PM8921_LVS2,
	MSM_RPM_ID_PM8921_LVS3,
	MSM_RPM_ID_PM8921_LVS4,
	MSM_RPM_ID_PM8921_LVS5,
	MSM_RPM_ID_PM8921_LVS6,
	MSM_RPM_ID_PM8921_LVS7,
	MSM_RPM_ID_NCP_0,
	MSM_RPM_ID_NCP_1,
	MSM_RPM_ID_CXO_BUFFERS,
	MSM_RPM_ID_USB_OTG_SWITCH,
	MSM_RPM_ID_HDMI_SWITCH,
	MSM_RPM_ID_DDR_DMM_0,
	MSM_RPM_ID_DDR_DMM_1,
	MSM_RPM_ID_QDSS_CLK,

	/* 8660 specific ids */
	MSM_RPM_ID_TRIGGER_SET_FROM,
	MSM_RPM_ID_TRIGGER_SET_TO,
	MSM_RPM_ID_TRIGGER_SET_TRIGGER,

	MSM_RPM_ID_TRIGGER_CLEAR_FROM,
	MSM_RPM_ID_TRIGGER_CLEAR_TO,
	MSM_RPM_ID_TRIGGER_CLEAR_TRIGGER,
	MSM_RPM_ID_PLL_4,
	MSM_RPM_ID_SMI_CLK,
	MSM_RPM_ID_APPS_L2_CACHE_CTL,

	/* pmic 8901 */
	MSM_RPM_ID_SMPS0B_0,
	MSM_RPM_ID_SMPS0B_1,
	MSM_RPM_ID_SMPS1B_0,
	MSM_RPM_ID_SMPS1B_1,
	MSM_RPM_ID_SMPS2B_0,
	MSM_RPM_ID_SMPS2B_1,
	MSM_RPM_ID_SMPS3B_0,
	MSM_RPM_ID_SMPS3B_1,
	MSM_RPM_ID_SMPS4B_0,
	MSM_RPM_ID_SMPS4B_1,
	MSM_RPM_ID_LDO0B_0,
	MSM_RPM_ID_LDO0B_1,
	MSM_RPM_ID_LDO1B_0,
	MSM_RPM_ID_LDO1B_1,
	MSM_RPM_ID_LDO2B_0,
	MSM_RPM_ID_LDO2B_1,
	MSM_RPM_ID_LDO3B_0,
	MSM_RPM_ID_LDO3B_1,
	MSM_RPM_ID_LDO4B_0,
	MSM_RPM_ID_LDO4B_1,
	MSM_RPM_ID_LDO5B_0,
	MSM_RPM_ID_LDO5B_1,
	MSM_RPM_ID_LDO6B_0,
	MSM_RPM_ID_LDO6B_1,
	MSM_RPM_ID_LVS0B,
	MSM_RPM_ID_LVS1B,
	MSM_RPM_ID_LVS2B,
	MSM_RPM_ID_LVS3B,
	MSM_RPM_ID_MVS,

	/* pmic 8058 */
	MSM_RPM_ID_SMPS0_0,
	MSM_RPM_ID_SMPS0_1,
	MSM_RPM_ID_SMPS1_0,
	MSM_RPM_ID_SMPS1_1,
	MSM_RPM_ID_SMPS2_0,
	MSM_RPM_ID_SMPS2_1,
	MSM_RPM_ID_SMPS3_0,
	MSM_RPM_ID_SMPS3_1,
	MSM_RPM_ID_SMPS4_0,
	MSM_RPM_ID_SMPS4_1,
	MSM_RPM_ID_LDO0_0,
	MSM_RPM_ID_LDO0_1,
	MSM_RPM_ID_LDO1_0,
	MSM_RPM_ID_LDO1_1,
	MSM_RPM_ID_LDO2_0,
	MSM_RPM_ID_LDO2_1,
	MSM_RPM_ID_LDO3_0,
	MSM_RPM_ID_LDO3_1,
	MSM_RPM_ID_LDO4_0,
	MSM_RPM_ID_LDO4_1,
	MSM_RPM_ID_LDO5_0,
	MSM_RPM_ID_LDO5_1,
	MSM_RPM_ID_LDO6_0,
	MSM_RPM_ID_LDO6_1,
	MSM_RPM_ID_LDO7_0,
	MSM_RPM_ID_LDO7_1,
	MSM_RPM_ID_LDO8_0,
	MSM_RPM_ID_LDO8_1,
	MSM_RPM_ID_LDO9_0,
	MSM_RPM_ID_LDO9_1,
	MSM_RPM_ID_LDO10_0,
	MSM_RPM_ID_LDO10_1,
	MSM_RPM_ID_LDO11_0,
	MSM_RPM_ID_LDO11_1,
	MSM_RPM_ID_LDO12_0,
	MSM_RPM_ID_LDO12_1,
	MSM_RPM_ID_LDO13_0,
	MSM_RPM_ID_LDO13_1,
	MSM_RPM_ID_LDO14_0,
	MSM_RPM_ID_LDO14_1,
	MSM_RPM_ID_LDO15_0,
	MSM_RPM_ID_LDO15_1,
	MSM_RPM_ID_LDO16_0,
	MSM_RPM_ID_LDO16_1,
	MSM_RPM_ID_LDO17_0,
	MSM_RPM_ID_LDO17_1,
	MSM_RPM_ID_LDO18_0,
	MSM_RPM_ID_LDO18_1,
	MSM_RPM_ID_LDO19_0,
	MSM_RPM_ID_LDO19_1,
	MSM_RPM_ID_LDO20_0,
	MSM_RPM_ID_LDO20_1,
	MSM_RPM_ID_LDO21_0,
	MSM_RPM_ID_LDO21_1,
	MSM_RPM_ID_LDO22_0,
	MSM_RPM_ID_LDO22_1,
	MSM_RPM_ID_LDO23_0,
	MSM_RPM_ID_LDO23_1,
	MSM_RPM_ID_LDO24_0,
	MSM_RPM_ID_LDO24_1,
	MSM_RPM_ID_LDO25_0,
	MSM_RPM_ID_LDO25_1,
	MSM_RPM_ID_LVS0,
	MSM_RPM_ID_LVS1,

	/* 9615 specific */
	MSM_RPM_ID_PM8018_S1_0,
	MSM_RPM_ID_PM8018_S1_1,
	MSM_RPM_ID_PM8018_S2_0,
	MSM_RPM_ID_PM8018_S2_1,
	MSM_RPM_ID_PM8018_S3_0,
	MSM_RPM_ID_PM8018_S3_1,
	MSM_RPM_ID_PM8018_S4_0,
	MSM_RPM_ID_PM8018_S4_1,
	MSM_RPM_ID_PM8018_S5_0,
	MSM_RPM_ID_PM8018_S5_1,
	MSM_RPM_ID_PM8018_L1_0,
	MSM_RPM_ID_PM8018_L1_1,
	MSM_RPM_ID_PM8018_L2_0,
	MSM_RPM_ID_PM8018_L2_1,
	MSM_RPM_ID_PM8018_L3_0,
	MSM_RPM_ID_PM8018_L3_1,
	MSM_RPM_ID_PM8018_L4_0,
	MSM_RPM_ID_PM8018_L4_1,
	MSM_RPM_ID_PM8018_L5_0,
	MSM_RPM_ID_PM8018_L5_1,
	MSM_RPM_ID_PM8018_L6_0,
	MSM_RPM_ID_PM8018_L6_1,
	MSM_RPM_ID_PM8018_L7_0,
	MSM_RPM_ID_PM8018_L7_1,
	MSM_RPM_ID_PM8018_L8_0,
	MSM_RPM_ID_PM8018_L8_1,
	MSM_RPM_ID_PM8018_L9_0,
	MSM_RPM_ID_PM8018_L9_1,
	MSM_RPM_ID_PM8018_L10_0,
	MSM_RPM_ID_PM8018_L10_1,
	MSM_RPM_ID_PM8018_L11_0,
	MSM_RPM_ID_PM8018_L11_1,
	MSM_RPM_ID_PM8018_L12_0,
	MSM_RPM_ID_PM8018_L12_1,
	MSM_RPM_ID_PM8018_L13_0,
	MSM_RPM_ID_PM8018_L13_1,
	MSM_RPM_ID_PM8018_L14_0,
	MSM_RPM_ID_PM8018_L14_1,
	MSM_RPM_ID_PM8018_LVS1,

	/* 8930 specific */
	MSM_RPM_ID_PM8038_S1_0,
	MSM_RPM_ID_PM8038_S1_1,
	MSM_RPM_ID_PM8038_S2_0,
	MSM_RPM_ID_PM8038_S2_1,
	MSM_RPM_ID_PM8038_S3_0,
	MSM_RPM_ID_PM8038_S3_1,
	MSM_RPM_ID_PM8038_S4_0,
	MSM_RPM_ID_PM8038_S4_1,
	MSM_RPM_ID_PM8038_S5_0,
	MSM_RPM_ID_PM8038_S5_1,
	MSM_RPM_ID_PM8038_S6_0,
	MSM_RPM_ID_PM8038_S6_1,
	MSM_RPM_ID_PM8038_L1_0,
	MSM_RPM_ID_PM8038_L1_1,
	MSM_RPM_ID_PM8038_L2_0,
	MSM_RPM_ID_PM8038_L2_1,
	MSM_RPM_ID_PM8038_L3_0,
	MSM_RPM_ID_PM8038_L3_1,
	MSM_RPM_ID_PM8038_L4_0,
	MSM_RPM_ID_PM8038_L4_1,
	MSM_RPM_ID_PM8038_L5_0,
	MSM_RPM_ID_PM8038_L5_1,
	MSM_RPM_ID_PM8038_L6_0,
	MSM_RPM_ID_PM8038_L6_1,
	MSM_RPM_ID_PM8038_L7_0,
	MSM_RPM_ID_PM8038_L7_1,
	MSM_RPM_ID_PM8038_L8_0,
	MSM_RPM_ID_PM8038_L8_1,
	MSM_RPM_ID_PM8038_L9_0,
	MSM_RPM_ID_PM8038_L9_1,
	MSM_RPM_ID_PM8038_L10_0,
	MSM_RPM_ID_PM8038_L10_1,
	MSM_RPM_ID_PM8038_L11_0,
	MSM_RPM_ID_PM8038_L11_1,
	MSM_RPM_ID_PM8038_L12_0,
	MSM_RPM_ID_PM8038_L12_1,
	MSM_RPM_ID_PM8038_L13_0,
	MSM_RPM_ID_PM8038_L13_1,
	MSM_RPM_ID_PM8038_L14_0,
	MSM_RPM_ID_PM8038_L14_1,
	MSM_RPM_ID_PM8038_L15_0,
	MSM_RPM_ID_PM8038_L15_1,
	MSM_RPM_ID_PM8038_L16_0,
	MSM_RPM_ID_PM8038_L16_1,
	MSM_RPM_ID_PM8038_L17_0,
	MSM_RPM_ID_PM8038_L17_1,
	MSM_RPM_ID_PM8038_L18_0,
	MSM_RPM_ID_PM8038_L18_1,
	MSM_RPM_ID_PM8038_L19_0,
	MSM_RPM_ID_PM8038_L19_1,
	MSM_RPM_ID_PM8038_L20_0,
	MSM_RPM_ID_PM8038_L20_1,
	MSM_RPM_ID_PM8038_L21_0,
	MSM_RPM_ID_PM8038_L21_1,
	MSM_RPM_ID_PM8038_L22_0,
	MSM_RPM_ID_PM8038_L22_1,
	MSM_RPM_ID_PM8038_L23_0,
	MSM_RPM_ID_PM8038_L23_1,
	MSM_RPM_ID_PM8038_L24_0,
	MSM_RPM_ID_PM8038_L24_1,
	MSM_RPM_ID_PM8038_L25_0,
	MSM_RPM_ID_PM8038_L25_1,
	MSM_RPM_ID_PM8038_L26_0,
	MSM_RPM_ID_PM8038_L26_1,
	MSM_RPM_ID_PM8038_L27_0,
	MSM_RPM_ID_PM8038_L27_1,
	MSM_RPM_ID_PM8038_CLK1_0,
	MSM_RPM_ID_PM8038_CLK1_1,
	MSM_RPM_ID_PM8038_CLK2_0,
	MSM_RPM_ID_PM8038_CLK2_1,
	MSM_RPM_ID_PM8038_LVS1,
	MSM_RPM_ID_PM8038_LVS2,

	/* PM8917 specific */
	MSM_RPM_ID_PM8917_S1_0,
	MSM_RPM_ID_PM8917_S1_1,
	MSM_RPM_ID_PM8917_S2_0,
	MSM_RPM_ID_PM8917_S2_1,
	MSM_RPM_ID_PM8917_S3_0,
	MSM_RPM_ID_PM8917_S3_1,
	MSM_RPM_ID_PM8917_S4_0,
	MSM_RPM_ID_PM8917_S4_1,
	MSM_RPM_ID_PM8917_S5_0,
	MSM_RPM_ID_PM8917_S5_1,
	MSM_RPM_ID_PM8917_S6_0,
	MSM_RPM_ID_PM8917_S6_1,
	MSM_RPM_ID_PM8917_S7_0,
	MSM_RPM_ID_PM8917_S7_1,
	MSM_RPM_ID_PM8917_S8_0,
	MSM_RPM_ID_PM8917_S8_1,
	MSM_RPM_ID_PM8917_L1_0,
	MSM_RPM_ID_PM8917_L1_1,
	MSM_RPM_ID_PM8917_L2_0,
	MSM_RPM_ID_PM8917_L2_1,
	MSM_RPM_ID_PM8917_L3_0,
	MSM_RPM_ID_PM8917_L3_1,
	MSM_RPM_ID_PM8917_L4_0,
	MSM_RPM_ID_PM8917_L4_1,
	MSM_RPM_ID_PM8917_L5_0,
	MSM_RPM_ID_PM8917_L5_1,
	MSM_RPM_ID_PM8917_L6_0,
	MSM_RPM_ID_PM8917_L6_1,
	MSM_RPM_ID_PM8917_L7_0,
	MSM_RPM_ID_PM8917_L7_1,
	MSM_RPM_ID_PM8917_L8_0,
	MSM_RPM_ID_PM8917_L8_1,
	MSM_RPM_ID_PM8917_L9_0,
	MSM_RPM_ID_PM8917_L9_1,
	MSM_RPM_ID_PM8917_L10_0,
	MSM_RPM_ID_PM8917_L10_1,
	MSM_RPM_ID_PM8917_L11_0,
	MSM_RPM_ID_PM8917_L11_1,
	MSM_RPM_ID_PM8917_L12_0,
	MSM_RPM_ID_PM8917_L12_1,
	MSM_RPM_ID_PM8917_L14_0,
	MSM_RPM_ID_PM8917_L14_1,
	MSM_RPM_ID_PM8917_L15_0,
	MSM_RPM_ID_PM8917_L15_1,
	MSM_RPM_ID_PM8917_L16_0,
	MSM_RPM_ID_PM8917_L16_1,
	MSM_RPM_ID_PM8917_L17_0,
	MSM_RPM_ID_PM8917_L17_1,
	MSM_RPM_ID_PM8917_L18_0,
	MSM_RPM_ID_PM8917_L18_1,
	MSM_RPM_ID_PM8917_L21_0,
	MSM_RPM_ID_PM8917_L21_1,
	MSM_RPM_ID_PM8917_L22_0,
	MSM_RPM_ID_PM8917_L22_1,
	MSM_RPM_ID_PM8917_L23_0,
	MSM_RPM_ID_PM8917_L23_1,
	MSM_RPM_ID_PM8917_L24_0,
	MSM_RPM_ID_PM8917_L24_1,
	MSM_RPM_ID_PM8917_L25_0,
	MSM_RPM_ID_PM8917_L25_1,
	MSM_RPM_ID_PM8917_L26_0,
	MSM_RPM_ID_PM8917_L26_1,
	MSM_RPM_ID_PM8917_L27_0,
	MSM_RPM_ID_PM8917_L27_1,
	MSM_RPM_ID_PM8917_L28_0,
	MSM_RPM_ID_PM8917_L28_1,
	MSM_RPM_ID_PM8917_L29_0,
	MSM_RPM_ID_PM8917_L29_1,
	MSM_RPM_ID_PM8917_L30_0,
	MSM_RPM_ID_PM8917_L30_1,
	MSM_RPM_ID_PM8917_L31_0,
	MSM_RPM_ID_PM8917_L31_1,
	MSM_RPM_ID_PM8917_L32_0,
	MSM_RPM_ID_PM8917_L32_1,
	MSM_RPM_ID_PM8917_L33_0,
	MSM_RPM_ID_PM8917_L33_1,
	MSM_RPM_ID_PM8917_L34_0,
	MSM_RPM_ID_PM8917_L34_1,
	MSM_RPM_ID_PM8917_L35_0,
	MSM_RPM_ID_PM8917_L35_1,
	MSM_RPM_ID_PM8917_L36_0,
	MSM_RPM_ID_PM8917_L36_1,
	MSM_RPM_ID_PM8917_CLK1_0,
	MSM_RPM_ID_PM8917_CLK1_1,
	MSM_RPM_ID_PM8917_CLK2_0,
	MSM_RPM_ID_PM8917_CLK2_1,
	MSM_RPM_ID_PM8917_LVS1,
	MSM_RPM_ID_PM8917_LVS3,
	MSM_RPM_ID_PM8917_LVS4,
	MSM_RPM_ID_PM8917_LVS5,
	MSM_RPM_ID_PM8917_LVS6,
	MSM_RPM_ID_PM8917_LVS7,
	MSM_RPM_ID_VOLTAGE_CORNER,

	/* 8064 specific */
	MSM_RPM_ID_PM8821_S1_0,
	MSM_RPM_ID_PM8821_S1_1,
	MSM_RPM_ID_PM8821_S2_0,
	MSM_RPM_ID_PM8821_S2_1,
	MSM_RPM_ID_PM8821_L1_0,
	MSM_RPM_ID_PM8821_L1_1,
	MSM_RPM_ID_VDDMIN_GPIO,

	MSM_RPM_ID_LAST,
};

enum {
	MSM_RPM_STATUS_ID_VERSION_MAJOR,
	MSM_RPM_STATUS_ID_VERSION_MINOR,
	MSM_RPM_STATUS_ID_VERSION_BUILD,
	MSM_RPM_STATUS_ID_SUPPORTED_RESOURCES_0,
	MSM_RPM_STATUS_ID_SUPPORTED_RESOURCES_1,
	MSM_RPM_STATUS_ID_SUPPORTED_RESOURCES_2,
	MSM_RPM_STATUS_ID_RESERVED_SUPPORTED_RESOURCES_0,
	MSM_RPM_STATUS_ID_SEQUENCE,
	MSM_RPM_STATUS_ID_RPM_CTL,
	MSM_RPM_STATUS_ID_CXO_CLK,
	MSM_RPM_STATUS_ID_PXO_CLK,
	MSM_RPM_STATUS_ID_APPS_FABRIC_CLK,
	MSM_RPM_STATUS_ID_SYSTEM_FABRIC_CLK,
	MSM_RPM_STATUS_ID_MM_FABRIC_CLK,
	MSM_RPM_STATUS_ID_DAYTONA_FABRIC_CLK,
	MSM_RPM_STATUS_ID_SFPB_CLK,
	MSM_RPM_STATUS_ID_CFPB_CLK,
	MSM_RPM_STATUS_ID_MMFPB_CLK,
	MSM_RPM_STATUS_ID_EBI1_CLK,
	MSM_RPM_STATUS_ID_APPS_FABRIC_CFG_HALT,
	MSM_RPM_STATUS_ID_APPS_FABRIC_HALT =
		MSM_RPM_STATUS_ID_APPS_FABRIC_CFG_HALT,
	MSM_RPM_STATUS_ID_APPS_FABRIC_CFG_CLKMOD,
	MSM_RPM_STATUS_ID_APPS_FABRIC_CLOCK_MODE =
		MSM_RPM_STATUS_ID_APPS_FABRIC_CFG_CLKMOD,
	MSM_RPM_STATUS_ID_APPS_FABRIC_CFG_IOCTL,
	MSM_RPM_STATUS_ID_APPS_FABRIC_ARB,
	MSM_RPM_STATUS_ID_SYS_FABRIC_CFG_HALT,
	MSM_RPM_STATUS_ID_SYSTEM_FABRIC_HALT =
		MSM_RPM_STATUS_ID_SYS_FABRIC_CFG_HALT,
	MSM_RPM_STATUS_ID_SYS_FABRIC_CFG_CLKMOD,
	MSM_RPM_STATUS_ID_SYSTEM_FABRIC_CLOCK_MODE =
		MSM_RPM_STATUS_ID_SYS_FABRIC_CFG_CLKMOD,
	MSM_RPM_STATUS_ID_SYS_FABRIC_CFG_IOCTL,
	MSM_RPM_STATUS_ID_SYSTEM_FABRIC_ARB,
	MSM_RPM_STATUS_ID_MMSS_FABRIC_CFG_HALT,
	MSM_RPM_STATUS_ID_MM_FABRIC_HALT =
		MSM_RPM_STATUS_ID_MMSS_FABRIC_CFG_HALT,
	MSM_RPM_STATUS_ID_MMSS_FABRIC_CFG_CLKMOD,
	MSM_RPM_STATUS_ID_MM_FABRIC_CLOCK_MODE =
		MSM_RPM_STATUS_ID_MMSS_FABRIC_CFG_CLKMOD,
	MSM_RPM_STATUS_ID_MMSS_FABRIC_CFG_IOCTL,
	MSM_RPM_STATUS_ID_MM_FABRIC_ARB,
	MSM_RPM_STATUS_ID_PM8921_S1_0,
	MSM_RPM_STATUS_ID_PM8921_S1_1,
	MSM_RPM_STATUS_ID_PM8921_S2_0,
	MSM_RPM_STATUS_ID_PM8921_S2_1,
	MSM_RPM_STATUS_ID_PM8921_S3_0,
	MSM_RPM_STATUS_ID_PM8921_S3_1,
	MSM_RPM_STATUS_ID_PM8921_S4_0,
	MSM_RPM_STATUS_ID_PM8921_S4_1,
	MSM_RPM_STATUS_ID_PM8921_S5_0,
	MSM_RPM_STATUS_ID_PM8921_S5_1,
	MSM_RPM_STATUS_ID_PM8921_S6_0,
	MSM_RPM_STATUS_ID_PM8921_S6_1,
	MSM_RPM_STATUS_ID_PM8921_S7_0,
	MSM_RPM_STATUS_ID_PM8921_S7_1,
	MSM_RPM_STATUS_ID_PM8921_S8_0,
	MSM_RPM_STATUS_ID_PM8921_S8_1,
	MSM_RPM_STATUS_ID_PM8921_L1_0,
	MSM_RPM_STATUS_ID_PM8921_L1_1,
	MSM_RPM_STATUS_ID_PM8921_L2_0,
	MSM_RPM_STATUS_ID_PM8921_L2_1,
	MSM_RPM_STATUS_ID_PM8921_L3_0,
	MSM_RPM_STATUS_ID_PM8921_L3_1,
	MSM_RPM_STATUS_ID_PM8921_L4_0,
	MSM_RPM_STATUS_ID_PM8921_L4_1,
	MSM_RPM_STATUS_ID_PM8921_L5_0,
	MSM_RPM_STATUS_ID_PM8921_L5_1,
	MSM_RPM_STATUS_ID_PM8921_L6_0,
	MSM_RPM_STATUS_ID_PM8921_L6_1,
	MSM_RPM_STATUS_ID_PM8921_L7_0,
	MSM_RPM_STATUS_ID_PM8921_L7_1,
	MSM_RPM_STATUS_ID_PM8921_L8_0,
	MSM_RPM_STATUS_ID_PM8921_L8_1,
	MSM_RPM_STATUS_ID_PM8921_L9_0,
	MSM_RPM_STATUS_ID_PM8921_L9_1,
	MSM_RPM_STATUS_ID_PM8921_L10_0,
	MSM_RPM_STATUS_ID_PM8921_L10_1,
	MSM_RPM_STATUS_ID_PM8921_L11_0,
	MSM_RPM_STATUS_ID_PM8921_L11_1,
	MSM_RPM_STATUS_ID_PM8921_L12_0,
	MSM_RPM_STATUS_ID_PM8921_L12_1,
	MSM_RPM_STATUS_ID_PM8921_L13_0,
	MSM_RPM_STATUS_ID_PM8921_L13_1,
	MSM_RPM_STATUS_ID_PM8921_L14_0,
	MSM_RPM_STATUS_ID_PM8921_L14_1,
	MSM_RPM_STATUS_ID_PM8921_L15_0,
	MSM_RPM_STATUS_ID_PM8921_L15_1,
	MSM_RPM_STATUS_ID_PM8921_L16_0,
	MSM_RPM_STATUS_ID_PM8921_L16_1,
	MSM_RPM_STATUS_ID_PM8921_L17_0,
	MSM_RPM_STATUS_ID_PM8921_L17_1,
	MSM_RPM_STATUS_ID_PM8921_L18_0,
	MSM_RPM_STATUS_ID_PM8921_L18_1,
	MSM_RPM_STATUS_ID_PM8921_L19_0,
	MSM_RPM_STATUS_ID_PM8921_L19_1,
	MSM_RPM_STATUS_ID_PM8921_L20_0,
	MSM_RPM_STATUS_ID_PM8921_L20_1,
	MSM_RPM_STATUS_ID_PM8921_L21_0,
	MSM_RPM_STATUS_ID_PM8921_L21_1,
	MSM_RPM_STATUS_ID_PM8921_L22_0,
	MSM_RPM_STATUS_ID_PM8921_L22_1,
	MSM_RPM_STATUS_ID_PM8921_L23_0,
	MSM_RPM_STATUS_ID_PM8921_L23_1,
	MSM_RPM_STATUS_ID_PM8921_L24_0,
	MSM_RPM_STATUS_ID_PM8921_L24_1,
	MSM_RPM_STATUS_ID_PM8921_L25_0,
	MSM_RPM_STATUS_ID_PM8921_L25_1,
	MSM_RPM_STATUS_ID_PM8921_L26_0,
	MSM_RPM_STATUS_ID_PM8921_L26_1,
	MSM_RPM_STATUS_ID_PM8921_L27_0,
	MSM_RPM_STATUS_ID_PM8921_L27_1,
	MSM_RPM_STATUS_ID_PM8921_L28_0,
	MSM_RPM_STATUS_ID_PM8921_L28_1,
	MSM_RPM_STATUS_ID_PM8921_L29_0,
	MSM_RPM_STATUS_ID_PM8921_L29_1,
	MSM_RPM_STATUS_ID_PM8921_CLK1_0,
	MSM_RPM_STATUS_ID_PM8921_CLK1_1,
	MSM_RPM_STATUS_ID_PM8921_CLK2_0,
	MSM_RPM_STATUS_ID_PM8921_CLK2_1,
	MSM_RPM_STATUS_ID_PM8921_LVS1,
	MSM_RPM_STATUS_ID_PM8921_LVS2,
	MSM_RPM_STATUS_ID_PM8921_LVS3,
	MSM_RPM_STATUS_ID_PM8921_LVS4,
	MSM_RPM_STATUS_ID_PM8921_LVS5,
	MSM_RPM_STATUS_ID_PM8921_LVS6,
	MSM_RPM_STATUS_ID_PM8921_LVS7,
	MSM_RPM_STATUS_ID_NCP_0,
	MSM_RPM_STATUS_ID_NCP_1,
	MSM_RPM_STATUS_ID_CXO_BUFFERS,
	MSM_RPM_STATUS_ID_USB_OTG_SWITCH,
	MSM_RPM_STATUS_ID_HDMI_SWITCH,
	MSM_RPM_STATUS_ID_DDR_DMM_0,
	MSM_RPM_STATUS_ID_DDR_DMM_1,
	MSM_RPM_STATUS_ID_EBI1_CH0_RANGE,
	MSM_RPM_STATUS_ID_EBI1_CH1_RANGE,
	MSM_RPM_STATUS_ID_QDSS_CLK,

	/* 8930 aliases to simplify device mapping */
	MSM_RPM_STATUS_ID_PM8038_NCP_0 = MSM_RPM_STATUS_ID_NCP_0,
	MSM_RPM_STATUS_ID_PM8038_NCP_1 = MSM_RPM_STATUS_ID_NCP_1,
	MSM_RPM_STATUS_ID_PM8038_CXO_BUFFERS
		= MSM_RPM_STATUS_ID_CXO_BUFFERS,
	MSM_RPM_STATUS_ID_PM8038_USB_OTG_SWITCH
		= MSM_RPM_STATUS_ID_USB_OTG_SWITCH,
	MSM_RPM_STATUS_ID_PM8038_HDMI_SWITCH
		= MSM_RPM_STATUS_ID_HDMI_SWITCH,
	MSM_RPM_STATUS_ID_PM8038_QDSS_CLK
		= MSM_RPM_STATUS_ID_QDSS_CLK,

	MSM_RPM_STATUS_ID_PM8917_NCP_0 = MSM_RPM_STATUS_ID_NCP_0,
		MSM_RPM_STATUS_ID_PM8917_NCP_1 = MSM_RPM_STATUS_ID_NCP_1,
	MSM_RPM_STATUS_ID_PM8917_CXO_BUFFERS
		= MSM_RPM_STATUS_ID_CXO_BUFFERS,
	MSM_RPM_STATUS_ID_PM8917_USB_OTG_SWITCH
		= MSM_RPM_STATUS_ID_USB_OTG_SWITCH,
	MSM_RPM_STATUS_ID_PM8917_HDMI_SWITCH
		= MSM_RPM_STATUS_ID_HDMI_SWITCH,
	MSM_RPM_STATUS_ID_PM8917_QDSS_CLK
		= MSM_RPM_STATUS_ID_QDSS_CLK,

	/* 8660 Specific */
	MSM_RPM_STATUS_ID_PLL_4,
	MSM_RPM_STATUS_ID_SMI_CLK,
	MSM_RPM_STATUS_ID_APPS_L2_CACHE_CTL,
	MSM_RPM_STATUS_ID_SMPS0B_0,
	MSM_RPM_STATUS_ID_SMPS0B_1,
	MSM_RPM_STATUS_ID_SMPS1B_0,
	MSM_RPM_STATUS_ID_SMPS1B_1,
	MSM_RPM_STATUS_ID_SMPS2B_0,
	MSM_RPM_STATUS_ID_SMPS2B_1,
	MSM_RPM_STATUS_ID_SMPS3B_0,
	MSM_RPM_STATUS_ID_SMPS3B_1,
	MSM_RPM_STATUS_ID_SMPS4B_0,
	MSM_RPM_STATUS_ID_SMPS4B_1,
	MSM_RPM_STATUS_ID_LDO0B_0,
	MSM_RPM_STATUS_ID_LDO0B_1,
	MSM_RPM_STATUS_ID_LDO1B_0,
	MSM_RPM_STATUS_ID_LDO1B_1,
	MSM_RPM_STATUS_ID_LDO2B_0,
	MSM_RPM_STATUS_ID_LDO2B_1,
	MSM_RPM_STATUS_ID_LDO3B_0,
	MSM_RPM_STATUS_ID_LDO3B_1,
	MSM_RPM_STATUS_ID_LDO4B_0,
	MSM_RPM_STATUS_ID_LDO4B_1,
	MSM_RPM_STATUS_ID_LDO5B_0,
	MSM_RPM_STATUS_ID_LDO5B_1,
	MSM_RPM_STATUS_ID_LDO6B_0,
	MSM_RPM_STATUS_ID_LDO6B_1,
	MSM_RPM_STATUS_ID_LVS0B,
	MSM_RPM_STATUS_ID_LVS1B,
	MSM_RPM_STATUS_ID_LVS2B,
	MSM_RPM_STATUS_ID_LVS3B,
	MSM_RPM_STATUS_ID_MVS,
	MSM_RPM_STATUS_ID_SMPS0_0,
	MSM_RPM_STATUS_ID_SMPS0_1,
	MSM_RPM_STATUS_ID_SMPS1_0,
	MSM_RPM_STATUS_ID_SMPS1_1,
	MSM_RPM_STATUS_ID_SMPS2_0,
	MSM_RPM_STATUS_ID_SMPS2_1,
	MSM_RPM_STATUS_ID_SMPS3_0,
	MSM_RPM_STATUS_ID_SMPS3_1,
	MSM_RPM_STATUS_ID_SMPS4_0,
	MSM_RPM_STATUS_ID_SMPS4_1,
	MSM_RPM_STATUS_ID_LDO0_0,
	MSM_RPM_STATUS_ID_LDO0_1,
	MSM_RPM_STATUS_ID_LDO1_0,
	MSM_RPM_STATUS_ID_LDO1_1,
	MSM_RPM_STATUS_ID_LDO2_0,
	MSM_RPM_STATUS_ID_LDO2_1,
	MSM_RPM_STATUS_ID_LDO3_0,
	MSM_RPM_STATUS_ID_LDO3_1,
	MSM_RPM_STATUS_ID_LDO4_0,
	MSM_RPM_STATUS_ID_LDO4_1,
	MSM_RPM_STATUS_ID_LDO5_0,
	MSM_RPM_STATUS_ID_LDO5_1,
	MSM_RPM_STATUS_ID_LDO6_0,
	MSM_RPM_STATUS_ID_LDO6_1,
	MSM_RPM_STATUS_ID_LDO7_0,
	MSM_RPM_STATUS_ID_LDO7_1,
	MSM_RPM_STATUS_ID_LDO8_0,
	MSM_RPM_STATUS_ID_LDO8_1,
	MSM_RPM_STATUS_ID_LDO9_0,
	MSM_RPM_STATUS_ID_LDO9_1,
	MSM_RPM_STATUS_ID_LDO10_0,
	MSM_RPM_STATUS_ID_LDO10_1,
	MSM_RPM_STATUS_ID_LDO11_0,
	MSM_RPM_STATUS_ID_LDO11_1,
	MSM_RPM_STATUS_ID_LDO12_0,
	MSM_RPM_STATUS_ID_LDO12_1,
	MSM_RPM_STATUS_ID_LDO13_0,
	MSM_RPM_STATUS_ID_LDO13_1,
	MSM_RPM_STATUS_ID_LDO14_0,
	MSM_RPM_STATUS_ID_LDO14_1,
	MSM_RPM_STATUS_ID_LDO15_0,
	MSM_RPM_STATUS_ID_LDO15_1,
	MSM_RPM_STATUS_ID_LDO16_0,
	MSM_RPM_STATUS_ID_LDO16_1,
	MSM_RPM_STATUS_ID_LDO17_0,
	MSM_RPM_STATUS_ID_LDO17_1,
	MSM_RPM_STATUS_ID_LDO18_0,
	MSM_RPM_STATUS_ID_LDO18_1,
	MSM_RPM_STATUS_ID_LDO19_0,
	MSM_RPM_STATUS_ID_LDO19_1,
	MSM_RPM_STATUS_ID_LDO20_0,
	MSM_RPM_STATUS_ID_LDO20_1,
	MSM_RPM_STATUS_ID_LDO21_0,
	MSM_RPM_STATUS_ID_LDO21_1,
	MSM_RPM_STATUS_ID_LDO22_0,
	MSM_RPM_STATUS_ID_LDO22_1,
	MSM_RPM_STATUS_ID_LDO23_0,
	MSM_RPM_STATUS_ID_LDO23_1,
	MSM_RPM_STATUS_ID_LDO24_0,
	MSM_RPM_STATUS_ID_LDO24_1,
	MSM_RPM_STATUS_ID_LDO25_0,
	MSM_RPM_STATUS_ID_LDO25_1,
	MSM_RPM_STATUS_ID_LVS0,
	MSM_RPM_STATUS_ID_LVS1,

	/* 9615 Specific */
	MSM_RPM_STATUS_ID_PM8018_S1_0,
	MSM_RPM_STATUS_ID_PM8018_S1_1,
	MSM_RPM_STATUS_ID_PM8018_S2_0,
	MSM_RPM_STATUS_ID_PM8018_S2_1,
	MSM_RPM_STATUS_ID_PM8018_S3_0,
	MSM_RPM_STATUS_ID_PM8018_S3_1,
	MSM_RPM_STATUS_ID_PM8018_S4_0,
	MSM_RPM_STATUS_ID_PM8018_S4_1,
	MSM_RPM_STATUS_ID_PM8018_S5_0,
	MSM_RPM_STATUS_ID_PM8018_S5_1,
	MSM_RPM_STATUS_ID_PM8018_L1_0,
	MSM_RPM_STATUS_ID_PM8018_L1_1,
	MSM_RPM_STATUS_ID_PM8018_L2_0,
	MSM_RPM_STATUS_ID_PM8018_L2_1,
	MSM_RPM_STATUS_ID_PM8018_L3_0,
	MSM_RPM_STATUS_ID_PM8018_L3_1,
	MSM_RPM_STATUS_ID_PM8018_L4_0,
	MSM_RPM_STATUS_ID_PM8018_L4_1,
	MSM_RPM_STATUS_ID_PM8018_L5_0,
	MSM_RPM_STATUS_ID_PM8018_L5_1,
	MSM_RPM_STATUS_ID_PM8018_L6_0,
	MSM_RPM_STATUS_ID_PM8018_L6_1,
	MSM_RPM_STATUS_ID_PM8018_L7_0,
	MSM_RPM_STATUS_ID_PM8018_L7_1,
	MSM_RPM_STATUS_ID_PM8018_L8_0,
	MSM_RPM_STATUS_ID_PM8018_L8_1,
	MSM_RPM_STATUS_ID_PM8018_L9_0,
	MSM_RPM_STATUS_ID_PM8018_L9_1,
	MSM_RPM_STATUS_ID_PM8018_L10_0,
	MSM_RPM_STATUS_ID_PM8018_L10_1,
	MSM_RPM_STATUS_ID_PM8018_L11_0,
	MSM_RPM_STATUS_ID_PM8018_L11_1,
	MSM_RPM_STATUS_ID_PM8018_L12_0,
	MSM_RPM_STATUS_ID_PM8018_L12_1,
	MSM_RPM_STATUS_ID_PM8018_L13_0,
	MSM_RPM_STATUS_ID_PM8018_L13_1,
	MSM_RPM_STATUS_ID_PM8018_L14_0,
	MSM_RPM_STATUS_ID_PM8018_L14_1,
	MSM_RPM_STATUS_ID_PM8018_LVS1,

	/* 8930 specific */
	MSM_RPM_STATUS_ID_PM8038_S1_0,
	MSM_RPM_STATUS_ID_PM8038_S1_1,
	MSM_RPM_STATUS_ID_PM8038_S2_0,
	MSM_RPM_STATUS_ID_PM8038_S2_1,
	MSM_RPM_STATUS_ID_PM8038_S3_0,
	MSM_RPM_STATUS_ID_PM8038_S3_1,
	MSM_RPM_STATUS_ID_PM8038_S4_0,
	MSM_RPM_STATUS_ID_PM8038_S4_1,
	MSM_RPM_STATUS_ID_PM8038_S5_0,
	MSM_RPM_STATUS_ID_PM8038_S5_1,
	MSM_RPM_STATUS_ID_PM8038_S6_0,
	MSM_RPM_STATUS_ID_PM8038_S6_1,
	MSM_RPM_STATUS_ID_PM8038_L1_0,
	MSM_RPM_STATUS_ID_PM8038_L1_1,
	MSM_RPM_STATUS_ID_PM8038_L2_0,
	MSM_RPM_STATUS_ID_PM8038_L2_1,
	MSM_RPM_STATUS_ID_PM8038_L3_0,
	MSM_RPM_STATUS_ID_PM8038_L3_1,
	MSM_RPM_STATUS_ID_PM8038_L4_0,
	MSM_RPM_STATUS_ID_PM8038_L4_1,
	MSM_RPM_STATUS_ID_PM8038_L5_0,
	MSM_RPM_STATUS_ID_PM8038_L5_1,
	MSM_RPM_STATUS_ID_PM8038_L6_0,
	MSM_RPM_STATUS_ID_PM8038_L6_1,
	MSM_RPM_STATUS_ID_PM8038_L7_0,
	MSM_RPM_STATUS_ID_PM8038_L7_1,
	MSM_RPM_STATUS_ID_PM8038_L8_0,
	MSM_RPM_STATUS_ID_PM8038_L8_1,
	MSM_RPM_STATUS_ID_PM8038_L9_0,
	MSM_RPM_STATUS_ID_PM8038_L9_1,
	MSM_RPM_STATUS_ID_PM8038_L10_0,
	MSM_RPM_STATUS_ID_PM8038_L10_1,
	MSM_RPM_STATUS_ID_PM8038_L11_0,
	MSM_RPM_STATUS_ID_PM8038_L11_1,
	MSM_RPM_STATUS_ID_PM8038_L12_0,
	MSM_RPM_STATUS_ID_PM8038_L12_1,
	MSM_RPM_STATUS_ID_PM8038_L13_0,
	MSM_RPM_STATUS_ID_PM8038_L13_1,
	MSM_RPM_STATUS_ID_PM8038_L14_0,
	MSM_RPM_STATUS_ID_PM8038_L14_1,
	MSM_RPM_STATUS_ID_PM8038_L15_0,
	MSM_RPM_STATUS_ID_PM8038_L15_1,
	MSM_RPM_STATUS_ID_PM8038_L16_0,
	MSM_RPM_STATUS_ID_PM8038_L16_1,
	MSM_RPM_STATUS_ID_PM8038_L17_0,
	MSM_RPM_STATUS_ID_PM8038_L17_1,
	MSM_RPM_STATUS_ID_PM8038_L18_0,
	MSM_RPM_STATUS_ID_PM8038_L18_1,
	MSM_RPM_STATUS_ID_PM8038_L19_0,
	MSM_RPM_STATUS_ID_PM8038_L19_1,
	MSM_RPM_STATUS_ID_PM8038_L20_0,
	MSM_RPM_STATUS_ID_PM8038_L20_1,
	MSM_RPM_STATUS_ID_PM8038_L21_0,
	MSM_RPM_STATUS_ID_PM8038_L21_1,
	MSM_RPM_STATUS_ID_PM8038_L22_0,
	MSM_RPM_STATUS_ID_PM8038_L22_1,
	MSM_RPM_STATUS_ID_PM8038_L23_0,
	MSM_RPM_STATUS_ID_PM8038_L23_1,
	MSM_RPM_STATUS_ID_PM8038_L24_0,
	MSM_RPM_STATUS_ID_PM8038_L24_1,
	MSM_RPM_STATUS_ID_PM8038_L25_0,
	MSM_RPM_STATUS_ID_PM8038_L25_1,
	MSM_RPM_STATUS_ID_PM8038_L26_0,
	MSM_RPM_STATUS_ID_PM8038_L26_1,
	MSM_RPM_STATUS_ID_PM8038_L27_0,
	MSM_RPM_STATUS_ID_PM8038_L27_1,
	MSM_RPM_STATUS_ID_PM8038_CLK1_0,
	MSM_RPM_STATUS_ID_PM8038_CLK1_1,
	MSM_RPM_STATUS_ID_PM8038_CLK2_0,
	MSM_RPM_STATUS_ID_PM8038_CLK2_1,
	MSM_RPM_STATUS_ID_PM8038_LVS1,
	MSM_RPM_STATUS_ID_PM8038_LVS2,

	/* PMIC 8917 */
	MSM_RPM_STATUS_ID_PM8917_S1_0,
	MSM_RPM_STATUS_ID_PM8917_S1_1,
	MSM_RPM_STATUS_ID_PM8917_S2_0,
	MSM_RPM_STATUS_ID_PM8917_S2_1,
	MSM_RPM_STATUS_ID_PM8917_S3_0,
	MSM_RPM_STATUS_ID_PM8917_S3_1,
	MSM_RPM_STATUS_ID_PM8917_S4_0,
	MSM_RPM_STATUS_ID_PM8917_S4_1,
	MSM_RPM_STATUS_ID_PM8917_S5_0,
	MSM_RPM_STATUS_ID_PM8917_S5_1,
	MSM_RPM_STATUS_ID_PM8917_S6_0,
	MSM_RPM_STATUS_ID_PM8917_S6_1,
	MSM_RPM_STATUS_ID_PM8917_S7_0,
	MSM_RPM_STATUS_ID_PM8917_S7_1,
	MSM_RPM_STATUS_ID_PM8917_S8_0,
	MSM_RPM_STATUS_ID_PM8917_S8_1,
	MSM_RPM_STATUS_ID_PM8917_L1_0,
	MSM_RPM_STATUS_ID_PM8917_L1_1,
	MSM_RPM_STATUS_ID_PM8917_L2_0,
	MSM_RPM_STATUS_ID_PM8917_L2_1,
	MSM_RPM_STATUS_ID_PM8917_L3_0,
	MSM_RPM_STATUS_ID_PM8917_L3_1,
	MSM_RPM_STATUS_ID_PM8917_L4_0,
	MSM_RPM_STATUS_ID_PM8917_L4_1,
	MSM_RPM_STATUS_ID_PM8917_L5_0,
	MSM_RPM_STATUS_ID_PM8917_L5_1,
	MSM_RPM_STATUS_ID_PM8917_L6_0,
	MSM_RPM_STATUS_ID_PM8917_L6_1,
	MSM_RPM_STATUS_ID_PM8917_L7_0,
	MSM_RPM_STATUS_ID_PM8917_L7_1,
	MSM_RPM_STATUS_ID_PM8917_L8_0,
	MSM_RPM_STATUS_ID_PM8917_L8_1,
	MSM_RPM_STATUS_ID_PM8917_L9_0,
	MSM_RPM_STATUS_ID_PM8917_L9_1,
	MSM_RPM_STATUS_ID_PM8917_L10_0,
	MSM_RPM_STATUS_ID_PM8917_L10_1,
	MSM_RPM_STATUS_ID_PM8917_L11_0,
	MSM_RPM_STATUS_ID_PM8917_L11_1,
	MSM_RPM_STATUS_ID_PM8917_L12_0,
	MSM_RPM_STATUS_ID_PM8917_L12_1,
	MSM_RPM_STATUS_ID_PM8917_L14_0,
	MSM_RPM_STATUS_ID_PM8917_L14_1,
	MSM_RPM_STATUS_ID_PM8917_L15_0,
	MSM_RPM_STATUS_ID_PM8917_L15_1,
	MSM_RPM_STATUS_ID_PM8917_L16_0,
	MSM_RPM_STATUS_ID_PM8917_L16_1,
	MSM_RPM_STATUS_ID_PM8917_L17_0,
	MSM_RPM_STATUS_ID_PM8917_L17_1,
	MSM_RPM_STATUS_ID_PM8917_L18_0,
	MSM_RPM_STATUS_ID_PM8917_L18_1,
	MSM_RPM_STATUS_ID_PM8917_L21_0,
	MSM_RPM_STATUS_ID_PM8917_L21_1,
	MSM_RPM_STATUS_ID_PM8917_L22_0,
	MSM_RPM_STATUS_ID_PM8917_L22_1,
	MSM_RPM_STATUS_ID_PM8917_L23_0,
	MSM_RPM_STATUS_ID_PM8917_L23_1,
	MSM_RPM_STATUS_ID_PM8917_L24_0,
	MSM_RPM_STATUS_ID_PM8917_L24_1,
	MSM_RPM_STATUS_ID_PM8917_L25_0,
	MSM_RPM_STATUS_ID_PM8917_L25_1,
	MSM_RPM_STATUS_ID_PM8917_L26_0,
	MSM_RPM_STATUS_ID_PM8917_L26_1,
	MSM_RPM_STATUS_ID_PM8917_L27_0,
	MSM_RPM_STATUS_ID_PM8917_L27_1,
	MSM_RPM_STATUS_ID_PM8917_L28_0,
	MSM_RPM_STATUS_ID_PM8917_L28_1,
	MSM_RPM_STATUS_ID_PM8917_L29_0,
	MSM_RPM_STATUS_ID_PM8917_L29_1,
	MSM_RPM_STATUS_ID_PM8917_L30_0,
	MSM_RPM_STATUS_ID_PM8917_L30_1,
	MSM_RPM_STATUS_ID_PM8917_L31_0,
	MSM_RPM_STATUS_ID_PM8917_L31_1,
	MSM_RPM_STATUS_ID_PM8917_L32_0,
	MSM_RPM_STATUS_ID_PM8917_L32_1,
	MSM_RPM_STATUS_ID_PM8917_L33_0,
	MSM_RPM_STATUS_ID_PM8917_L33_1,
	MSM_RPM_STATUS_ID_PM8917_L34_0,
	MSM_RPM_STATUS_ID_PM8917_L34_1,
	MSM_RPM_STATUS_ID_PM8917_L35_0,
	MSM_RPM_STATUS_ID_PM8917_L35_1,
	MSM_RPM_STATUS_ID_PM8917_L36_0,
	MSM_RPM_STATUS_ID_PM8917_L36_1,
	MSM_RPM_STATUS_ID_PM8917_CLK1_0,
	MSM_RPM_STATUS_ID_PM8917_CLK1_1,
	MSM_RPM_STATUS_ID_PM8917_CLK2_0,
	MSM_RPM_STATUS_ID_PM8917_CLK2_1,
	MSM_RPM_STATUS_ID_PM8917_LVS1,
	MSM_RPM_STATUS_ID_PM8917_LVS3,
	MSM_RPM_STATUS_ID_PM8917_LVS4,
	MSM_RPM_STATUS_ID_PM8917_LVS5,
	MSM_RPM_STATUS_ID_PM8917_LVS6,
	MSM_RPM_STATUS_ID_PM8917_LVS7,
	MSM_RPM_STATUS_ID_VOLTAGE_CORNER,
	MSM_RPM_STATUS_ID_PM8917_VOLTAGE_CORNER
		= MSM_RPM_STATUS_ID_VOLTAGE_CORNER,
	MSM_RPM_STATUS_ID_PM8038_VOLTAGE_CORNER
		= MSM_RPM_STATUS_ID_VOLTAGE_CORNER,

	/* 8064 specific */
	MSM_RPM_STATUS_ID_PM8821_S1_0,
	MSM_RPM_STATUS_ID_PM8821_S1_1,
	MSM_RPM_STATUS_ID_PM8821_S2_0,
	MSM_RPM_STATUS_ID_PM8821_S2_1,
	MSM_RPM_STATUS_ID_PM8821_L1_0,
	MSM_RPM_STATUS_ID_PM8821_L1_1,
	MSM_RPM_STATUS_ID_VDDMIN_GPIO,

	MSM_RPM_STATUS_ID_LAST,
};

static inline uint32_t msm_rpm_get_ctx_mask(unsigned int ctx)
{
	return 1UL << ctx;
}

static inline unsigned int msm_rpm_get_sel_mask_reg(unsigned int sel)
{
	return sel / 32;
}

static inline uint32_t msm_rpm_get_sel_mask(unsigned int sel)
{
	return 1UL << (sel % 32);
}

struct msm_rpm_iv_pair {
	uint32_t id;
	uint32_t value;
};

struct msm_rpm_notification {
	struct list_head list;  /* reserved for RPM use */
	struct semaphore sem;
	uint32_t sel_masks[SEL_MASK_SIZE];  /* reserved for RPM use */
};

struct msm_rpm_map_data {
	uint32_t id;
	uint32_t sel;
	uint32_t count;
};

#define MSM_RPM_MAP(t, i, s, c) \
	[MSM_RPM_ID_##i] = \
	{\
		.id = MSM_RPM_##t##_ID_##i, \
		.sel = MSM_RPM_##t##_SEL_##s, \
		.count = c, \
	}

#define MSM_RPM_MAP_PMIC(_target, _pmic, _id, _select, _count) \
	[MSM_RPM_ID_##_id] = \
	{\
		.id = MSM_RPM_##_target##_ID_PM##_pmic##_##_id, \
		.sel = MSM_RPM_##_target##_SEL_##_select, \
		.count = _count, \
	}

#define MSM_RPM_STATUS_ID_VALID BIT(31)

#define MSM_RPM_STATUS_ID_MAP(t, i) \
	[MSM_RPM_STATUS_ID_## i] = (MSM_RPM_##t##_STATUS_ID_##i \
					| MSM_RPM_STATUS_ID_VALID)

#define MSM_RPM_CTRL_MAP(t, i) \
	[MSM_RPM_CTRL_##i] = MSM_RPM_##t##_CTRL_##i


struct msm_rpm_platform_data {
	void __iomem *reg_base_addrs[MSM_RPM_PAGE_COUNT];
	unsigned int irq_ack;
	unsigned int irq_err;
	unsigned int irq_wakeup;
	void *ipc_rpm_reg;
	unsigned int ipc_rpm_val;
	struct msm_rpm_map_data target_id[MSM_RPM_ID_LAST];
	unsigned int target_status[MSM_RPM_STATUS_ID_LAST];
	unsigned int target_ctrl_id[MSM_RPM_CTRL_LAST];
	unsigned int sel_invalidate, sel_notification, sel_last;
	unsigned int ver[3];
};

extern struct msm_rpm_platform_data msm8660_rpm_data;
extern struct msm_rpm_platform_data msm8960_rpm_data;
extern struct msm_rpm_platform_data msm9615_rpm_data;
extern struct msm_rpm_platform_data msm8930_rpm_data;
extern struct msm_rpm_platform_data msm8930_rpm_data_pm8917;
extern struct msm_rpm_platform_data apq8064_rpm_data;

#if defined(CONFIG_MSM_RPM)

int msm_rpm_local_request_is_outstanding(void);
int msm_rpm_get_status(struct msm_rpm_iv_pair *status, int count);
int msm_rpm_set(int ctx, struct msm_rpm_iv_pair *req, int count);
int msm_rpm_set_noirq(int ctx, struct msm_rpm_iv_pair *req, int count);

static inline int msm_rpm_set_nosleep(
	int ctx, struct msm_rpm_iv_pair *req, int count)
{
	unsigned long flags;
	int rc;

	local_irq_save(flags);
	rc = msm_rpm_set_noirq(ctx, req, count);
	local_irq_restore(flags);

	return rc;
}

int msm_rpm_clear(int ctx, struct msm_rpm_iv_pair *req, int count);
int msm_rpm_clear_noirq(int ctx, struct msm_rpm_iv_pair *req, int count);

static inline int msm_rpm_clear_nosleep(
	int ctx, struct msm_rpm_iv_pair *req, int count)
{
	unsigned long flags;
	int rc;

	local_irq_save(flags);
	rc = msm_rpm_clear_noirq(ctx, req, count);
	local_irq_restore(flags);

	return rc;
}

int msm_rpm_register_notification(struct msm_rpm_notification *n,
	struct msm_rpm_iv_pair *req, int count);
int msm_rpm_unregister_notification(struct msm_rpm_notification *n);
int msm_rpm_init(struct msm_rpm_platform_data *data);

#else

static inline int msm_rpm_local_request_is_outstanding(void)
{
	return -ENODEV;
}

static inline int msm_rpm_get_status(struct msm_rpm_iv_pair *status, int count)
{
	return -ENODEV;
}

static inline int msm_rpm_set(int ctx, struct msm_rpm_iv_pair *req, int count)
{
	return -ENODEV;
}

static inline int msm_rpm_set_noirq(int ctx, struct msm_rpm_iv_pair *req,
					int count)
{
	return -ENODEV;
}

static inline int msm_rpm_set_nosleep(
	int ctx, struct msm_rpm_iv_pair *req, int count)
{
	return -ENODEV;
}

static inline int msm_rpm_clear(int ctx, struct msm_rpm_iv_pair *req,
				int count)
{
	return -ENODEV;
}

static inline int msm_rpm_clear_noirq(int ctx, struct msm_rpm_iv_pair *req,
					int count)
{
	return -ENODEV;
}

static inline int msm_rpm_clear_nosleep(
	int ctx, struct msm_rpm_iv_pair *req, int count)
{
	return -ENODEV;
}

static inline int msm_rpm_register_notification(struct msm_rpm_notification *n,
	struct msm_rpm_iv_pair *req, int count)
{
	return -ENODEV;
}

static inline int msm_rpm_unregister_notification(
					struct msm_rpm_notification *n)
{
	return -ENODEV;
}

static inline int msm_rpm_init(struct msm_rpm_platform_data *data)
{
	return -ENODEV;
}

#endif /* CONFIG_RPM */

#endif /* __ARCH_ARM_MACH_MSM_RPM_H */
