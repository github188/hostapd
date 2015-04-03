/*
加解密模块库头文件
*/
#ifndef __ENCIPHERMENT_LIB_H
#define __ENCIPHERMENT_LIB_H

#define VM_MALLOC(size)		        malloc(size)

#define VM_ZALLOC(size)		        calloc(1, size)

#define VM_REALLOC(ptr, size)       realloc(ptr, size)

#define VM_FREE(ptr)						\
    do											\
    {											\
        if (ptr)								\
        {										\
            free(ptr);							\
            (ptr) = NULL;						\
        }										\
    }while(0)

#ifdef SHARED
int (*Create_RSA_generate_key_ex)(int bits, unsigned long  e);
int (*Create_RSA_public_encrypt)(char *modulus, unsigned long public_key, unsigned char *in, int inlen, unsigned char *out, int *outlen);
int (*Create_RSA_private_decrypt)(char *modulus, unsigned long public_key, char *private_key, unsigned char *in, int inlen, unsigned char *out, int *outlen);
int (*Create_hash_encrypt)(unsigned char *in, int inlen, unsigned char *out, int *outlen);
int (*Create_hash_decrypt)(unsigned char *in, int inlen, unsigned char *out, int *outlen);

#else

extern int Create_RSA_generate_key_ex(int bits, unsigned long  e);
extern int Create_RSA_public_encrypt(char *modulus, unsigned long public_key, unsigned char *in, int inlen, unsigned char *out, int *outlen);
extern int Create_RSA_private_decrypt(char *modulus, unsigned long public_key, char *private_key, unsigned char *in, int inlen, unsigned char *out, int *outlen);
extern int Create_hash_encrypt(unsigned char *in, int inlen, unsigned char *out, int *outlen);
extern int Create_hash_decrypt(unsigned char *in, int inlen, unsigned char *out, int *outlen);

#endif


#endif

