#include <clib/alib_protos.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/locale.h>
#if defined(__amigaos4__)
#include <proto/timezone.h>
#endif

#include "libcmt.h"

#ifdef __amigaos4__
struct Library *LocaleBase = NULL;
struct LocaleIFace *ILocale = NULL;
#elif !defined(__MORPHOS__)
struct LocaleBase *LocaleBase = NULL;
#else
struct Library *LocaleBase = NULL;
#endif

// global variables throughout libcmt
struct MinList __filelist; /* list of open files (fflush() needs also access) */
struct SignalSemaphore __filelist_cs;
struct SignalSemaphore __mem_cs;
void *__mem_pool = NULL;
ULONG __clock_base = 0;
LONG __gmt_offset = 0;

#if defined(__amigaos4__)
static int timezone_get_offset(void)
{
  struct Library *TimezoneBase;
  struct TimezoneIFace *ITimezone = NULL;

  if ((TimezoneBase = OpenLibrary("timezone.library", 52)))
  {
    if ((ITimezone = (struct TimezoneIFace *)GetInterface(TimezoneBase,"main",1,NULL)))
    {
      GetTimezoneAttrs(NULL,TZA_UTCOffset,&__gmt_offset,TAG_DONE);
      SHOWVALUE(DBF_STARTUP, __gmt_offset);
      DropInterface((struct Interface *)ITimezone);
    }
    CloseLibrary(TimezoneBase);
  }

  return (ITimezone != NULL);
}
#else
#define timezone_get_offset() 0
#endif

void __init_libcmt(void)
{
  ENTER();

  // initialize memory stuff
  SHOWPOINTER(DBF_STARTUP, &__mem_cs);
  SHOWPOINTER(DBF_STARTUP, &__mem_pool);

  InitSemaphore(&__mem_cs);

#if defined(__amigaos4__)
  __mem_pool = AllocSysObjectTags(ASOT_MEMPOOL, ASOPOOL_MFlags, MEMF_PRIVATE, ASOPOOL_Puddle, 8192, ASOPOOL_Threshold, 4096, ASOPOOL_Name, "AmiSSL", TAG_DONE);
#else
  __mem_pool = CreatePool(MEMF_ANY, 8192, 4096);
#endif

  // initialize file i/o stuff
  SHOWPOINTER(DBF_STARTUP, &__filelist);
  SHOWPOINTER(DBF_STARTUP, &__filelist_cs);
  NewList((struct List *)&__filelist);
  InitSemaphore(&__filelist_cs);

  // initialize clock/locale stuff
  SHOWPOINTER(DBF_STARTUP, &__clock_base);
  SHOWPOINTER(DBF_STARTUP, &__gmt_offset);

#if defined(__amigaos4__)
  if((DOSBase = OpenLibrary("dos.library", 50)) &&
     (LocaleBase = OpenLibrary("locale.library", 50)) &&
     (IDOS = (struct DOSIFace *)GetInterface(DOSBase,"main",1,NULL)) &&
     (ILocale = (struct LocaleIFace *)GetInterface(LocaleBase,"main",1,NULL)))
#elif defined(__amigaos3__)
  if(((DOSBase = (struct DosLibrary *)OpenLibrary("dos.library", 37)) &&
      (LocaleBase = (struct LocaleBase *)OpenLibrary("locale.library", 38))))
#elif defined(__MORPHOS__)
  if(((DOSBase = (struct DosLibrary *)OpenLibrary("dos.library", 37)) &&
      (LocaleBase = (struct Library *)OpenLibrary("locale.library", 38))))
#endif
  {
    struct Locale *locale;
    struct DateStamp ds;

    if (!timezone_get_offset())
    {
      if ((locale = OpenLocale(NULL)) != NULL)
      {
        __gmt_offset = locale->loc_GMTOffset;
        SHOWVALUE(DBF_STARTUP, __gmt_offset);
        CloseLocale(locale);
      }
      else
        E(DBF_STARTUP, "ERROR on OpenLocale()");
    }
    DateStamp(&ds);

    __clock_base = ((ULONG)ds.ds_Tick + TICKS_PER_SECOND * 60 * ((ULONG)ds.ds_Minute + 24 * 60 * (ULONG)ds.ds_Days))
                   * CLOCKS_PER_SEC / TICKS_PER_SECOND;
  }
  else
    E(DBF_STARTUP, "ERROR on OpenLibrary()");

  LEAVE();
}

void __free_libcmt(void)
{
  ENTER();

  // close helper libs
  SHOWPOINTER(DBF_STARTUP, &__clock_base);
  SHOWPOINTER(DBF_STARTUP, &__gmt_offset);

#if defined(__amigaos4__)
  DropInterface((struct Interface *)ILocale);
  ILocale = NULL;
  DropInterface((struct Interface *)IDOS);
  IDOS = NULL;
#endif
  CloseLibrary((struct Library *)LocaleBase);
  LocaleBase = NULL;
  CloseLibrary((struct Library *)DOSBase);
  DOSBase = NULL;

  SHOWPOINTER(DBF_STARTUP, &__mem_pool);
  // free memory related stuff
#ifdef __amigaos4__
  if(__mem_pool)
    FreeSysObject(ASOT_MEMPOOL, __mem_pool);
#else
  if(__mem_pool)
    DeletePool(__mem_pool);
#endif

  LEAVE();
}
