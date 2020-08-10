#
# Copyright (c) 2016 MediaTek Inc.
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files
# (the "Software"), to deal in the Software without restriction,
# including without limitation the rights to use, copy, modify, merge,
# publish, distribute, sublicense, and/or sell copies of the Software,
# and to permit persons to whom the Software is furnished to do so,
# subject to the following conditions:
#
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
# CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
# SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := msee_mpu_api
LOCAL_CFLAGS += -Werror -Wall -Wextra
LOCAL_CFLAGS += -DTBASE_API_LEVEL=5
LOCAL_C_INCLUDES += $(LOCAL_PATH)/public
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../common/drv/public
LOCAL_SRC_FILES += ../../../common/drv/emi_mpu_legacy.c
LOCAL_EXPORT_C_INCLUDE_DIRS += $(LOCAL_PATH)/public
LOCAL_EXPORT_C_INCLUDE_DIRS += $(LOCAL_PATH)/../../../common/drv/public

include vendor/mediatek/proprietary/trustzone/custom/build/tee_static_library.mk