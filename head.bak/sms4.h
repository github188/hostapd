#ifndef __SMS4__

#define __SMS4__


#ifdef __cplusplus
extern "C"
{
#endif


#define SMS4_ENCRYPT   1
#define SMS4_DECRYPT   0
#define SMS4_BLOCK_SIZE 16
#define WORD_SIZE	4

typedef struct sms4_ctx
{
	u32 *key;
	u32 *input;
	u32 input_len;
	u32 *output;
	u32 *iv;
	u32 rk[32];
	u32 enc;
}SMS4_CTX;

int sms4_cbc_encrypt(const u8 *in, u8 *out,
		     const u32 length, const u8 *key,
		     u8 *ivec);

int sms4_ofb_encrypt(const u8 *in, u8 *out,
			const u32 length, const u8 *key,
			u8 *ivec);

#define sms4_ofb_decrypt(_in, _out, _len, _key, _iv)	sms4_ofb_encrypt(_in, _out, _len, _key, _iv)

int sms4_block_encrypt(const u8 *in, u8 *out,
		     const u32 length, const u8 *key);
int sms4_block_decrypt(const u8 *in, u8 *out,
		     const u32 length, const u8 *key);

void sms4_test(void);

#ifdef __cplusplus
}
#endif
#endif /* __SMS4__ */
