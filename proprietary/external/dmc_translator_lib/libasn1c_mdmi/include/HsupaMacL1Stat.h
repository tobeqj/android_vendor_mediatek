/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _HsupaMacL1Stat_H_
#define _HsupaMacL1Stat_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "Tti.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* HsupaMacL1Stat */
typedef struct HsupaMacL1Stat {
    long     startingFrameNumber;
    Tti_t    tti;
    long     etfciTableIndex;
    long     numFrames;
    long     servingRgchUpCommandsCount;
    long     servingRgchDownCommandCount;
    long     servingRgchHoldCommandCount;
    long     nonServingRgchDownCommandCount;
    long     nonServingRgchHoldCommandCount;
    long     numReceivedAgch;
    long     numNewTx;
    long     numRetx;
    long     dtxCount;
    long     numReceivedNackAfterMaxRetx;
    long     mac_e_resetCount;
    long     numSuccessFirstRetx;
    long     maxPowerAllowed;
    long     numSentSi;
    long     numHappyTti;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} HsupaMacL1Stat_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_HsupaMacL1Stat;

#ifdef __cplusplus
}
#endif

#endif  /* _HsupaMacL1Stat_H_ */
#include <asn_internal.h>