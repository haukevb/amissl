#ifndef LIBRARIES_AMISSLMASTER_H
#define LIBRARIES_AMISSLMASTER_H

#define CIPHER_AES			0x11
#define CIPHER_BlowFish		0x01
#define CIPHER_CAST			0x02
#define CIPHER_DES			0x03
#define CIPHER_DH			0x04
#define CIPHER_DSA			0x05
#define CIPHER_IDEA			0x06
#define CIPHER_MD2			0x07
#define CIPHER_MD4			0x08
#define CIPHER_MD5			0x09
#define CIPHER_MDC2			0x0a
#define CIPHER_RC2			0x0b
#define CIPHER_RC4			0x0c
#define CIPHER_RC5			0x0d
#define CIPHER_RIPEMD		0x0e
#define CIPHER_RSA			0x0f
#define CIPHER_SHA			0x10

#define AMISSL_V2			0x01	/* OBSOLETE NAME */
#define AMISSL_V096g		0x01
#define AMISSL_V097a		0x02

#define AMISSL_CURRENT_VERSION	AMISSL_V097a

#endif /* LIBRARIES_AMISSLMASTER_H */
