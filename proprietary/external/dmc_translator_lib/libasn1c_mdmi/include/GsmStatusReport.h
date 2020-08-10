/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _GsmStatusReport_H_
#define _GsmStatusReport_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>
#include "TimeStamp.h"
#include <NativeInteger.h>
#include "Lai.h"
#include "CallManagementState.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* GsmStatusReport */
typedef struct GsmStatusReport {
    OCTET_STRING_t   data;
    TimeStamp_t  time;
    long     mobileStationModel;
    OCTET_STRING_t   mobileStationClassmark2;
    OCTET_STRING_t   mobileStationClassmark3;
    OCTET_STRING_t   imei;
    OCTET_STRING_t   imsi;
    Lai_t    lai;
    long     cellId;
    CallManagementState_t    callManagementState;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} GsmStatusReport_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GsmStatusReport;

#ifdef __cplusplus
}
#endif

#endif  /* _GsmStatusReport_H_ */
#include <asn_internal.h>