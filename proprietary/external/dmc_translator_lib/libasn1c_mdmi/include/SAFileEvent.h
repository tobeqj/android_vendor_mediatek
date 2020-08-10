/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _SAFileEvent_H_
#define _SAFileEvent_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SAFileEvent */
typedef struct SAFileEvent {
    OCTET_STRING_t   saFile;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} SAFileEvent_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SAFileEvent;

#ifdef __cplusplus
}
#endif

#endif  /* _SAFileEvent_H_ */
#include <asn_internal.h>