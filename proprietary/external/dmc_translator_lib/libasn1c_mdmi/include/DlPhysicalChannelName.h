/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _DlPhysicalChannelName_H_
#define _DlPhysicalChannelName_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum DlPhysicalChannelName {
    DlPhysicalChannelName_pccpch_serving    = 0,
    DlPhysicalChannelName_pccpch_neighbor   = 1,
    DlPhysicalChannelName_sccpch0   = 2,
    DlPhysicalChannelName_sccpch1_on_fach   = 3,
    DlPhysicalChannelName_pich  = 4,
    DlPhysicalChannelName_aich  = 5,
    DlPhysicalChannelName_dpch  = 6,
    DlPhysicalChannelName_pdsch = 7
} e_DlPhysicalChannelName;

/* DlPhysicalChannelName */
typedef long     DlPhysicalChannelName_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DlPhysicalChannelName;
asn_struct_free_f DlPhysicalChannelName_free;
asn_struct_print_f DlPhysicalChannelName_print;
asn_constr_check_f DlPhysicalChannelName_constraint;
ber_type_decoder_f DlPhysicalChannelName_decode_ber;
der_type_encoder_f DlPhysicalChannelName_encode_der;
xer_type_decoder_f DlPhysicalChannelName_decode_xer;
xer_type_encoder_f DlPhysicalChannelName_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _DlPhysicalChannelName_H_ */
#include <asn_internal.h>