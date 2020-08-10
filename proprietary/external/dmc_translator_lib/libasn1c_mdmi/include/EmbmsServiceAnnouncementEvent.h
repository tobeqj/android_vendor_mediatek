/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _EmbmsServiceAnnouncementEvent_H_
#define _EmbmsServiceAnnouncementEvent_H_


#include <asn_application.h>

/* Including external dependencies */
#include "ServiceAnnouncementEvent.h"

#ifdef __cplusplus
extern "C" {
#endif

/* EmbmsServiceAnnouncementEvent */
typedef ServiceAnnouncementEvent_t   EmbmsServiceAnnouncementEvent_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_EmbmsServiceAnnouncementEvent;
asn_struct_free_f EmbmsServiceAnnouncementEvent_free;
asn_struct_print_f EmbmsServiceAnnouncementEvent_print;
asn_constr_check_f EmbmsServiceAnnouncementEvent_constraint;
ber_type_decoder_f EmbmsServiceAnnouncementEvent_decode_ber;
der_type_encoder_f EmbmsServiceAnnouncementEvent_encode_der;
xer_type_decoder_f EmbmsServiceAnnouncementEvent_decode_xer;
xer_type_encoder_f EmbmsServiceAnnouncementEvent_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _EmbmsServiceAnnouncementEvent_H_ */
#include <asn_internal.h>