/* Note: This structure can only grow, it can't be changed since
 * it is shared between amisslmaster.library and amissl.library,
 * which might be different versions!
 */
struct AmiSSLInitStruct
{
  struct Library *BlowFishBase;
  struct Library *CASTBase;
  struct Library *DESBase;
  struct Library *IDEABase;
  struct Library *MD2Base;
  struct Library *MD4Base;
  struct Library *MD5Base;
  struct Library *MDC2Base;
  struct Library *RC2Base;
  struct Library *RC4Base;
  struct Library *RC5Base;
  struct Library *RIPEMDBase;
  struct Library *SHABase;
  struct Library *RSABase;
  struct Library *DHBase;
  struct Library *DSABase;
};
