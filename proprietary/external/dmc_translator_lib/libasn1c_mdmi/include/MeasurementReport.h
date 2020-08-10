/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _MeasurementReport_H_
#define _MeasurementReport_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RatType.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MeasurementReport */
typedef struct MeasurementReport {
    RatType_t    ratType;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} MeasurementReport_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MeasurementReport;

#ifdef __cplusplus
}
#endif

#endif  /* _MeasurementReport_H_ */
#include <asn_internal.h>