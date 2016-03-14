#include <sys/types.h>
#include <netinet/in.h>

#ifdef __amigaos4__
#undef __USE_INLINE__
#include <proto/bsdsocket.h>
#else
#define AMITCP_NEW_NAMES
#include <errno.h>
#include "multitcp.h"
#include <internal/amissl.h>
#endif

#include "libcmt.h"

int
getsockname(int sockfd, struct sockaddr *name, socklen_t *namelen)
{
#ifdef __amigaos4__
  GETISOCKET();
  if(ISocket) return ISocket->getsockname(sockfd, name, namelen);
  else return -1;
#else
	GETSTATE();

	if (state->SocketBase)
	{
		switch(state->TCPIPStackType)
		{
			case TCPIP_Miami:
			case TCPIP_AmiTCP:
			case TCPIP_MLink:
				return amitcp_GetSockName(sockfs, name, namelen);
				break;
			case TCPIP_IN225:
				return in225_getsockname(sockfs, name, namelen);
				break;
			case TCPIP_Termite:
        return termite_getsockname(sockfs, name, namelen);
				break;
		}
	}

	return(-1);
#endif
}
