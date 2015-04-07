#ifndef __WAPI_SHA256_H__
#define __WAPI_SHA256_H__

#ifdef __cplusplus
extern "C"
{
#endif

#define SHA256_DIGEST_SIZE      32
#define SHA256_HMAC_BLOCK_SIZE  64

//#define SHA_NAME( x )  cout<<#x<<endl;

struct sha256_ctx {
		u32 Nl,Nh;
		u32 num,md_len;
        u32 state[8];
		u8  padding[8];
        u8 buf[SHA256_HMAC_BLOCK_SIZE];
};

void wapi_hmac_sha256(const u8 *key, size_t key_len, const u8 *data,
		 size_t data_len, u8 *mac, size_t length);

void KD_hmac_sha256(const u8 *key, size_t key_len, const u8 *text,
		 size_t text_len, u8 *output, size_t length );

//test
void sha256_test(void);

#ifdef __cplusplus
}
#endif
#endif /* __SHA256__ */
