/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _Hypothesis_H_
#define _Hypothesis_H_


#include <asn_application.h>

/* Including external dependencies */
#include "SystemFrameNumber.h"
#include "SubFrameNumber.h"
#include <NativeInteger.h>
#include "ServingCellIndex.h"
#include "CecAggregationLevel.h"
#include "DciFormat.h"
#include "RntiType.h"
#include "DciFormatStatus.h"
#include "SearchSpaceType.h"
#include "StartCceIndex.h"
#include "TailBitingDecoderStateMatch.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Hypothesis */
typedef struct Hypothesis {
    SystemFrameNumber_t  sysFrameNumber;
    SubFrameNumber_t     subFrameNumber;
    long     servingCellId;
    ServingCellIndex_t   servingCellIndex;
    CecAggregationLevel_t    cecAggregationLevel;
    DciFormat_t  dciFormat;
    RntiType_t   decodeStatus;
    long     payloadSize;
    DciFormatStatus_t    dciFormatStatus;
    SearchSpaceType_t    searchSpaceType;
    StartCceIndex_t  startCceIndex;
    TailBitingDecoderStateMatch_t    tailMatch;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} Hypothesis_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Hypothesis;

#ifdef __cplusplus
}
#endif

#endif  /* _Hypothesis_H_ */
#include <asn_internal.h>