/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _RrProtocolError_H_
#define _RrProtocolError_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NULL.h>
#include <NativeInteger.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RrProtocolError_PR {
    RrProtocolError_PR_NOTHING, /* No components present */
    RrProtocolError_PR_noError,
    RrProtocolError_PR_hasError
} RrProtocolError_PR;
typedef enum hasError {
    hasError_invalidprotocoldiscriminator   = 0,
    hasError_invalidmessage = 1,
    hasError_invalidie  = 2,
    hasError_other  = 3
} e_hasError;

/* RrProtocolError */
typedef struct RrProtocolError {
    RrProtocolError_PR present;
    union RrProtocolError_u {
        NULL_t   noError;
        long     hasError;
    } choice;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} RrProtocolError_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RrProtocolError;

#ifdef __cplusplus
}
#endif

#endif  /* _RrProtocolError_H_ */
#include <asn_internal.h>