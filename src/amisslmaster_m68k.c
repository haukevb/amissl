
/* This file was generated by idltool 53.18. Do not edit */


/***************************************************************************/

#ifdef __USE_INLINE__
#undef __USE_INLINE__
#endif

#ifdef __NOGLOBALIFACE__
#undef __NOGLOBALIFACE__
#endif

#ifndef PROTO_EXEC_H
#include <proto/exec.h>
#endif

#ifndef PROTO_AMISSLMASTER_H
#include <proto/amisslmaster.h>
#endif

#ifndef EXEC_EMULATION_H
#include <exec/emulation.h>
#endif

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

/***************************************************************************/

STATIC struct Library * stub_main_Open_PPC(uint32 *regarray)
{
	struct Library *Base = (struct Library *)regarray[REG68K_A6/4];
	struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *)((uint32)Base + Base->lib_PosSize);
	struct LibraryManagerInterface *Self = (struct LibraryManagerInterface *) ExtLib->ILibrary;

	return Self->Open(0);
}
STATIC CONST struct EmuTrap stub_main_Open = { TRAPINST, TRAPTYPE, (uint32 (*)(uint32 *))stub_main_Open_PPC };

// ---

STATIC APTR stub_main_Close_PPC(uint32 *regarray)
{
	struct Library *Base = (struct Library *)regarray[REG68K_A6/4];
	struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *)((uint32)Base + Base->lib_PosSize);
	struct LibraryManagerInterface *Self = (struct LibraryManagerInterface *) ExtLib->ILibrary;

	return Self->Close();
}
STATIC CONST struct EmuTrap stub_main_Close = { TRAPINST, TRAPTYPE, (uint32 (*)(uint32 *))stub_main_Close_PPC };

// ---

STATIC APTR stub_main_Expunge_PPC(uint32 *regarray UNUSED)
{
	return NULL;
}
STATIC CONST struct EmuTrap stub_main_Expunge = { TRAPINST, TRAPTYPE, (uint32 (*)(uint32 *))stub_main_Expunge_PPC };

// ---

STATIC uint32 stub_main_Reserved_PPC(uint32 *regarray UNUSED)
{
	return 0;
}
STATIC CONST struct EmuTrap stub_main_Reserved = { TRAPINST, TRAPTYPE, (uint32 (*)(uint32 *))stub_main_Reserved_PPC };

// ---

STATIC uint32 stub_main_Obtain_PPC(uint32 *regarray)
{
	struct Library *Base = (struct Library *)regarray[REG68K_A6/4];
	struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *)((uint32)Base + Base->lib_PosSize);
	struct AmiSSLMasterIFace *Self = (struct AmiSSLMasterIFace *)ExtLib->MainIFace;

	return Self->Obtain();
}
STATIC CONST struct EmuTrap stub_main_Obtain = { TRAPINST, TRAPTYPE, (uint32 (*)(uint32 *))stub_main_Obtain_PPC };

// ---

STATIC uint32 stub_main_Release_PPC(uint32 *regarray)
{
	struct Library *Base = (struct Library *)regarray[REG68K_A6/4];
	struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *)((uint32)Base + Base->lib_PosSize);
	struct AmiSSLMasterIFace *Self = (struct AmiSSLMasterIFace *)ExtLib->MainIFace;

	return Self->Release();
}
STATIC CONST struct EmuTrap stub_main_Release = { TRAPINST, TRAPTYPE, (uint32 (*)(uint32 *))stub_main_Release_PPC };

// ---

STATIC LONG stub_main_InitAmiSSLMaster_PPC(uint32 *regarray)
{
	struct Library *Base = (struct Library *)regarray[REG68K_A6/4];
	struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *)((uint32)Base + Base->lib_PosSize);
	struct AmiSSLMasterIFace *Self = (struct AmiSSLMasterIFace *)ExtLib->MainIFace;

	return Self->InitAmiSSLMaster(
		(LONG)regarray[REG68K_D0/4],
		(LONG)regarray[REG68K_D1/4]
	);
}
STATIC CONST struct EmuTrap stub_main_InitAmiSSLMaster = { TRAPINST, TRAPTYPE, (uint32 (*)(uint32 *))stub_main_InitAmiSSLMaster_PPC };

// ---

STATIC struct Library * stub_main_OpenAmiSSL_PPC(uint32 *regarray)
{
	struct Library *Base = (struct Library *)regarray[REG68K_A6/4];
	struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *)((uint32)Base + Base->lib_PosSize);
	struct AmiSSLMasterIFace *Self = (struct AmiSSLMasterIFace *)ExtLib->MainIFace;

	return Self->OpenAmiSSL();
}
STATIC CONST struct EmuTrap stub_main_OpenAmiSSL = { TRAPINST, TRAPTYPE, (uint32 (*)(uint32 *))stub_main_OpenAmiSSL_PPC };

// ---

STATIC void stub_main_CloseAmiSSL_PPC(uint32 *regarray)
{
	struct Library *Base = (struct Library *)regarray[REG68K_A6/4];
	struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *)((uint32)Base + Base->lib_PosSize);
	struct AmiSSLMasterIFace *Self = (struct AmiSSLMasterIFace *)ExtLib->MainIFace;

	Self->CloseAmiSSL();
}
STATIC CONST struct EmuTrap stub_main_CloseAmiSSL = { TRAPINST, TRAPTYPE, (uint32 (*)(uint32 *))stub_main_CloseAmiSSL_PPC };

// ---

STATIC struct Library * stub_main_OpenAmiSSLCipher_PPC(uint32 *regarray)
{
	struct Library *Base = (struct Library *)regarray[REG68K_A6/4];
	struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *)((uint32)Base + Base->lib_PosSize);
	struct AmiSSLMasterIFace *Self = (struct AmiSSLMasterIFace *)ExtLib->MainIFace;

	return Self->OpenAmiSSLCipher(
		(LONG)regarray[REG68K_D0/4]
	);
}
STATIC CONST struct EmuTrap stub_main_OpenAmiSSLCipher = { TRAPINST, TRAPTYPE, (uint32 (*)(uint32 *))stub_main_OpenAmiSSLCipher_PPC };

// ---

STATIC void stub_main_CloseAmiSSLCipher_PPC(uint32 *regarray)
{
	struct Library *Base = (struct Library *)regarray[REG68K_A6/4];
	struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *)((uint32)Base + Base->lib_PosSize);
	struct AmiSSLMasterIFace *Self = (struct AmiSSLMasterIFace *)ExtLib->MainIFace;

	Self->CloseAmiSSLCipher(
		(struct Library *)regarray[REG68K_A0/4]
	);
}
STATIC CONST struct EmuTrap stub_main_CloseAmiSSLCipher = { TRAPINST, TRAPTYPE, (uint32 (*)(uint32 *))stub_main_CloseAmiSSLCipher_PPC };

// ---

CONST CONST_APTR main_VecTable68K[] =
{
	&stub_main_Open,
	&stub_main_Close,
	&stub_main_Expunge,
	&stub_main_Reserved,
	&stub_main_Obtain,
	&stub_main_Release,
	&stub_main_InitAmiSSLMaster,
	&stub_main_OpenAmiSSL,
	&stub_main_CloseAmiSSL,
	&stub_main_OpenAmiSSLCipher,
	&stub_main_CloseAmiSSLCipher,
	(CONST_APTR)-1
};

/***************************************************************************/

