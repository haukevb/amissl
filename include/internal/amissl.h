#ifndef INTERNAL_AMISSL_H
#define INTERNAL_AMISSL_H

#include <exec/types.h>
#include <dos.h>

typedef struct {
	unsigned long pid;
	int errno;
	char *getenv_var;
	APTR stack;
	APTR a4;
} AMISSL_STATE;

AMISSL_STATE *GetAmiSSLState(void);
void SetAmiSSLerrno(int errno);
int GetAmiSSLerrno(void);

#define SETUPSTATE() AMISSL_STATE *state =�GetAmiSSLState()
#define SETUPSTATEDS() AMISSL_STATE *state =�GetAmiSSLState(); putreg(REG_A4,(long)state->a4)

#endif /* !INTERNAL_AMISSL_H */