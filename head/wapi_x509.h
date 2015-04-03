
#ifndef __WAPI_X509V3_H__
#define __WAPI_X509V3_H__

#define WAPI_X509_DEBUG

#define X509_SRC_TYPE_FILE    1
#define X509_SRC_TYPE_STREAM  2

#define X509_KEY_HEX_LEN 48

#define FORMAT_UNDEF    0
#define FORMAT_ASN1     1
#define FORMAT_TEXT     2
#define FORMAT_PEM      3
#define FORMAT_NETSCAPE 4
#define FORMAT_PKCS12   5
#define FORMAT_SMIME    6
#define FORMAT_ENGINE   7
#define FORMAT_IISSGC	8	/* XXX this stupid macro helps us to avoid
				 * adding yet another param to load_*key() */

typedef struct pw_cb_data
{
	const void *password;
	const char *prompt_info;
} PW_CB_DATA;

#define WAPI_PRINTF printf

/*#define WAPI_PRINTF_CODE( data , len, type ) \
	do{											 \
		int __i;										 \
		char *format[] ={"%.2c ","%.2x ","%.2d "};			\
		for( __i = 0; __i < (len) ; __i++ )					 \
			{									 \
				WAPI_PRINTF(format[(type)], (unsigned char)(data)[__i] );		  \
				if(__i % 16 == 7)WAPI_PRINTF("  ");	   \
				else if(__i % 16 == 15)WAPI_PRINTF("\n"); \
			}									     \
			WAPI_PRINTF("\n");					\
		}										     \
	while(0)*/

#ifdef WAPI_X509_DEBUG
#define WAPI_PRINTF_CODE_CHAR( data , len )  WAPI_PRINTF_CODE( (data) ,(len),0 )
#define WAPI_PRINTF_CODE_HEX( data , len )  WAPI_PRINTF_CODE( (data) ,(len),1 )
#define WAPI_PRINTF_CODE_DEC( data , len )  WAPI_PRINTF_CODE( (data) ,(len),2 )
#else
#define WAPI_PRINTF_CODE_CHAR( data , len )  
#define WAPI_PRINTF_CODE_HEX( data , len )  
#define WAPI_PRINTF_CODE_DEC( data , len )
#endif

void wapi_sha256(const unsigned char *in, u_int32_t n, unsigned char *out);
int wapi_x509v3_check_same_issuer(const u_int8_t *Ax509, u_int32_t Alen, const u_int8_t *Bx509, u_int32_t Blen);
int wapi_x509v3_get_certificate_from_file( char *filename, u_int8_t *out, u_int32_t *out_len);
int wapi_x509v3_get_identity ( u_int8_t *in, u_int32_t in_len ,u_int8_t *out, u_int32_t *out_len);
int wapi_x509v3_get_pubkey ( u_int8_t *in, u_int32_t in_len ,u_int8_t *out, u_int32_t *out_len);
int wapi_x509v3_get_prikey (char *file, u_int8_t *out, u_int32_t *out_len );
int wapi_ecdsa192_verify_signature( u_int8_t *text, u_int32_t text_len, u_int8_t *key, u_int32_t ken_len, u_int8_t *sign, u_int32_t sign_len);
int wapi_ecdsa192_build_signature(u_int8_t *text, u_int32_t text_len, u_int8_t *key, u_int32_t ken_len, u_int8_t *sign, u_int32_t *sign_len);
int wapi_ecdh_gen_pubkey( u_int8_t *prikey, u_int8_t *pubkey );
int wapi_ecdh_compute_key( u_int8_t *prikey,  u_int8_t *pubkey, u_int8_t *out );

void x509_test(void);

#endif /* __WAPI_X509V3_H__ */
